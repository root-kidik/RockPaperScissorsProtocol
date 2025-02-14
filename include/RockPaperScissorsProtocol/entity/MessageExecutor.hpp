#pragma once

#include <cassert>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>

#ifndef NDEBUG
#include <iostream>
#endif

#include <RockPaperScissorsProtocol/entity/MessageRepresentation.hpp>
#include <RockPaperScissorsProtocol/interface/Connection.hpp>
#include <RockPaperScissorsProtocol/interface/MessageHandlerBase.hpp>
#include <RockPaperScissorsProtocol/entity/MessageSender.hpp>
#include <RockPaperScissorsProtocol/util/Util.hpp>

namespace rps::protocol::entity
{

template <typename RequestMessageType, typename ResponseMessageType>
class MessageExecutor
{
public:
    MessageExecutor(entity::MessageSender& message_sender) : m_message_sender{message_sender}
    {

    }

    void execute_message(std::string&& raw_data, const std::shared_ptr<interface::Connection>& connection)
    {
        std::istringstream iss{std::move(raw_data)};

        entity::MessageIdx message_idx;
        iss >> message_idx;

        entity::MessageRepresentation message_type;
        iss >> message_type;

        std::string data;
        std::getline(std::move(iss), data);

        if (data.empty())
            return;

        if (!std::isspace(data.front()))
            return;

        data.erase(0, 1);

#ifndef NDEBUG
        std::cout << data << '\n';
#endif

        if (util::is_valid_value_for_enum<RequestMessageType>(message_type))
        {
            auto it = m_request_handlers.find(static_cast<RequestMessageType>(message_type));

            assert(it != m_request_handlers.end() && "Not setted request handler to handle this message_type");

            it->second->execute(std::move(data), connection);
        }
        else if (util::is_valid_value_for_enum<ResponseMessageType>(message_type))
            m_message_sender.handle_response(message_idx, std::move(data), connection);
    }

    template <typename RequestHandler, typename... Args>
    void register_request_handler(Args&&... args)
    {
        assert(m_request_handlers.find(RequestHandler::Request::kType) == m_request_handlers.end() &&
               "Already setted request handler to handle this message_type");

        auto handler = std::make_unique<RequestHandler>(std::forward<Args>(args)...);
        handler->m_message_sender = m_message_sender;
        
        m_request_handlers.emplace(RequestHandler::Request::kType,
                                   std::move(handler));
    }

private:
    std::unordered_map<RequestMessageType, std::unique_ptr<interface::MessageHandlerBase>> m_request_handlers;
    entity::MessageSender&                                                                 m_message_sender;
};

} // namespace rps::protocol::entity
