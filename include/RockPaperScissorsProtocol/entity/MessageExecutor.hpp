#pragma once

#include <cassert>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>

#include <RockPaperScissorsProtocol/entity/MessageRepresentation.hpp>
#include <RockPaperScissorsProtocol/interface/Connection.hpp>
#include <RockPaperScissorsProtocol/interface/RequestHandlerBase.hpp>

namespace rps::protocol::entity
{

template <typename MessageType>
class MessageExecutor
{
public:
    void execute_message(std::string&& raw_data, const std::shared_ptr<interface::Connection>& connection)
    {
        std::istringstream iss{std::move(raw_data)};

        entity::MessageRepresentation message_type;
        iss >> message_type;

        if (message_type < static_cast<entity::MessageRepresentation>(MessageType::Begin) + 1 ||
            message_type > static_cast<entity::MessageRepresentation>(MessageType::End) - 1)
            return;

        std::string data;
        std::getline(iss, data);

        if (!data.empty() && std::isspace(data.front()))
            data.erase(0, 1);

        auto it = m_commands.find(static_cast<MessageType>(message_type));

        assert(it != m_commands.end() && "Not setted command to execute this message_type");

        it->second->execute(std::move(data), connection);
    }

    template <typename RequestHandler, typename... Args>
    void register_command(Args&&... args)
    {
        assert(m_commands.find(RequestHandler::Request::kType) == m_commands.end() &&
               "Already setted command to execute this message_type");

        m_commands.emplace(RequestHandler::Request::kType, std::make_unique<RequestHandler>(std::forward<Args>(args)...));
    }

private:
    std::unordered_map<MessageType, std::unique_ptr<interface::RequestHandlerBase>> m_commands;
};

} // namespace rps::protocol::entity
