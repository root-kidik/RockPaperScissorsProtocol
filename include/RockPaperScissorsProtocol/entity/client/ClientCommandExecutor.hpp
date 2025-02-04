#pragma once

#include <RockPaperScissorsProtocol/entity/CommandExecutor.hpp>
#include <RockPaperScissorsProtocol/entity/client/ClientCommandType.hpp>

namespace rps::protocol::entity::client
{

using ClientCommandExecutor = CommandExecutor<ClientCommandType>;

} // namespace rps::protocol::entity::client
