#pragma once

#include <cassert>
#include <memory>
#include <string>
#include <unordered_map>

#include <RockPaperScissorsProtocol/entity/client/ClientCommandType.hpp>
#include <RockPaperScissorsProtocol/entity/server/ServerCommandType.hpp>
#include <RockPaperScissorsProtocol/interface/CommandHandler.hpp>
#include <RockPaperScissorsProtocol/interface/Connection.hpp>

namespace rps::protocol::entity
{

template <typename CommandType>
class CommandExecutor
{
public:
    void execute_command(CommandType command_type, const std::string& data, const std::shared_ptr<interface::Connection>& connection)
    {
        auto it = m_commands.find(command_type);

        assert(it != m_commands.end() && "Not setted command to execute this command_type");

        it->second.execute(data, connection);
    }

    void register_command(CommandType command_type, interface::CommandHandler& command)
    {
        assert(m_commands.find(command_type) == m_commands.end() &&
               "Already setted command to execute this command_type");

        m_commands.emplace(command_type, command);
    }

private:
    std::unordered_map<CommandType, interface::CommandHandler&> m_commands;
};

using ServerCommandExecutor = CommandExecutor<ServerCommandType>;
using ClientCommandExecutor = CommandExecutor<ClientCommandType>;

} // namespace rps::protocol::entity
