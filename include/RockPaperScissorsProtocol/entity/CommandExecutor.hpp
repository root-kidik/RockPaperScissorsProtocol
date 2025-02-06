#pragma once

#include <cassert>
#include <memory>
#include <string>
#include <unordered_map>
#include <sstream>

#include <RockPaperScissorsProtocol/entity/CommandRepresentation.hpp>
#include <RockPaperScissorsProtocol/interface/CommandHandlerBase.hpp>
#include <RockPaperScissorsProtocol/interface/Connection.hpp>

namespace rps::protocol::entity
{

template <typename CommandType>
class CommandExecutor
{
public:
    void execute_command(std::string&& raw_data, const std::shared_ptr<interface::Connection>& connection)
    {
        std::istringstream iss{std::move(raw_data)};

        entity::CommandRepresentation command_type;
        iss >> command_type;

        if (command_type < static_cast<entity::CommandRepresentation>(CommandType::Begin) + 1 ||
            command_type > static_cast<entity::CommandRepresentation>(CommandType::End) - 1)
            return;

        std::string data;
        std::getline(iss, data);

        if (!data.empty() && std::isspace(data.front()))
            data.erase(0, 1);

        auto it = m_commands.find(static_cast<CommandType>(command_type));

        assert(it != m_commands.end() && "Not setted command to execute this command_type");

        it->second->execute(std::move(data), connection);
    }

    template <typename CommandHandler, typename... Args>
    void register_command(Args&&... args)
    {
        assert(m_commands.find(CommandHandler::RequestType::kType) == m_commands.end() &&
               "Already setted command to execute this command_type");

        m_commands.emplace(CommandHandler::RequestType::kType,
                           std::make_unique<CommandHandler>(std::forward<Args>(args)...));
    }

private:
    std::unordered_map<CommandType, std::unique_ptr<interface::CommandHandlerBase>> m_commands;
};

} // namespace rps::protocol::entity
