#pragma once

#include <cassert>
#include <memory>
#include <string>
#include <unordered_map>

#include <RockPaperScissorsProtocol/interface/CommandHandlerBase.hpp>
#include <RockPaperScissorsProtocol/interface/Connection.hpp>

namespace rps::protocol::entity
{

template <typename CommandType>
class CommandExecutor
{
public:
    void execute_command(CommandType command_type, std::string&& data, const std::shared_ptr<interface::Connection>& connection)
    {
        auto it = m_commands.find(command_type);

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
