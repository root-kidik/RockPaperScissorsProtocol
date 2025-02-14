#pragma once

#include <functional>
#include <memory>
#include <queue>

#include <RockPaperScissorsProtocol/entity/MessageRepresentation.hpp>
#include <RockPaperScissorsProtocol/interface/Connection.hpp>
#include <RockPaperScissorsProtocol/util/Util.hpp>

namespace rps::protocol::entity
{

class MessageSender
{
public:
    template <typename Request, typename Response>
    void send(Request&&                                     message,
              const std::shared_ptr<interface::Connection>& connection,
              std::function<void(Response&&)>               callback = nullptr)
    {
        connection->send(std::to_string(m_sended_message_count++) + ' ' + util::serialize_message(std::move(message)));

        if (!callback)
            return;

        Callback cb;
        cb.message_idx = message.idx;
        cb.callback    = [](std::string&& data) { callback(util::deserialize<Response>(std::move(data))); };

        m_callbacks.emplace(connection.get(), std::move(cb));
    }

    void handle_response(entity::MessageIdx message_idx, std::string&& data, const std::shared_ptr<interface::Connection>& connection)
    {
        auto it = m_callbacks.find(connection.get());
        if (it == m_callbacks.end())
            return;

        auto& cq = it->second;

        while (!cq.empty() && cq.front().message_idx < message_idx)
            cq.pop();

        if (cq.empty())
            return;

        auto& cb = cq.front();

        if (cb.message_idx != message_idx)
            return;

        assert(cb.callback && "Callback must be not nullptr");
        cb.callback(std::move(data));

        cq.pop();
    }

private:
    // Terrible type erasure
    struct Callback
    {
        MessageIdx                         message_idx;
        std::function<void(std::string&&)> callback;
    };

    std::unordered_map<interface::Connection*, std::queue<Callback>> m_callbacks; // TODO(@rtkid): replace queue -> ring_buffer

    MessageIdx m_sended_message_count{};
};

} // namespace rps::protocol::entity
