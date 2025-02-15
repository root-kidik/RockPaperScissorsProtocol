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
#include <RockPaperScissorsProtocol/util/Util.hpp>

namespace rps::protocol::entity
{

template <typename RequestMessageType, typename ResponseMessageType>
class MessageExecutor
{
public:
    void process_data(std::string&& raw_data, const std::shared_ptr<interface::Connection>& connection)
    {
        m_buffer += std::move(raw_data);

        while (true)
        {
            auto end_pos = m_buffer.find('\n');
            if (end_pos == std::string::npos)
                break;

            auto message = m_buffer.substr(0, end_pos);
            m_buffer.erase(0, end_pos + 1);

            execute_message(std::move(message), connection);
        }
    }

    template <typename RequestHandler, typename... Args>
    void register_request_handler(Args&&... args)
    {
        assert(m_request_handlers.find(RequestHandler::Request::kType) == m_request_handlers.end() &&
               "Already setted request handler to handle this message_type");

        m_request_handlers.emplace(RequestHandler::Request::kType,
                                   std::make_unique<RequestHandler>(std::forward<Args>(args)...));
    }

    template <typename ResponseHandler, typename... Args>
    void register_response_handler(Args&&... args)
    {
        assert(m_response_handlers.find(ResponseHandler::Response::kType) == m_response_handlers.end() &&
               "Already setted response handler to handle this message_type");

        m_response_handlers.emplace(ResponseHandler::Response::kType,
                                    std::make_unique<ResponseHandler>(std::forward<Args>(args)...));
    }

private:
    void execute_message(std::string&& raw_data, const std::shared_ptr<interface::Connection>& connection)
    {
#ifndef NDEBUG
        std::cout << "receive: " << raw_data;
#endif

        std::istringstream iss{std::move(raw_data)};

        entity::MessageRepresentation message_type;
        iss >> message_type;

        std::string data;
        std::getline(std::move(iss), data);

        if (data.empty())
            return;

        if (!std::isspace(data.front()))
            return;

        data.erase(0, 1);

        if (util::is_valid_value_for_enum<RequestMessageType>(message_type))
        {
            auto it = m_request_handlers.find(static_cast<RequestMessageType>(message_type));

            assert(it != m_request_handlers.end() && "Not setted request handler to handle this message_type");

            it->second->execute(std::move(data), connection);
        }
        else if (util::is_valid_value_for_enum<ResponseMessageType>(message_type))
        {
            auto it = m_response_handlers.find(static_cast<ResponseMessageType>(message_type));

            if (it == m_response_handlers.end())
            {
#ifndef NDEBUG
                std::cout << "Not setted response handler to handle this message_type\n";
#endif
                return;
            }

            it->second->execute(std::move(data), connection);
        }
    }

    std::string m_buffer;

    std::unordered_map<RequestMessageType, std::unique_ptr<interface::MessageHandlerBase>>  m_request_handlers;
    std::unordered_map<ResponseMessageType, std::unique_ptr<interface::MessageHandlerBase>> m_response_handlers;
};

} // namespace rps::protocol::entity
