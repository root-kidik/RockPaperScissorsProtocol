#pragma once

#include <RockPaperScissorsProtocol/entity/CommandExecutor.hpp>
#include <RockPaperScissorsProtocol/entity/server/ServerMessageType.hpp>

namespace rps::protocol::entity::server
{

using ServerCommandExecutor = CommandExecutor<ServerMessageType>;

} // namespace rps::protocol::entity::server
