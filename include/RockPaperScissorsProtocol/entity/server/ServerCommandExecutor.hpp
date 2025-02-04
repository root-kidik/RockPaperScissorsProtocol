#pragma once

#include <RockPaperScissorsProtocol/entity/CommandExecutor.hpp>
#include <RockPaperScissorsProtocol/entity/server/ServerCommandType.hpp>

namespace rps::protocol::entity::server
{

using ServerCommandExecutor = CommandExecutor<ServerCommandType>;

} // namespace rps::protocol::entity::server
