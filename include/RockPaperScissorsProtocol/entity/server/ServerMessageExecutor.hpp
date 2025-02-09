#pragma once

#include <RockPaperScissorsProtocol/entity/MessageExecutor.hpp>
#include <RockPaperScissorsProtocol/entity/server/ServerMessageType.hpp>

namespace rps::protocol::entity::server
{

using ServerMessageExecutor = MessageExecutor<ServerMessageType>;

} // namespace rps::protocol::entity::server
