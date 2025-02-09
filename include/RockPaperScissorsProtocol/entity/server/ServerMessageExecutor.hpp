#pragma once

#include <RockPaperScissorsProtocol/entity/MessageExecutor.hpp>
#include <RockPaperScissorsProtocol/entity/client/ClientMessageType.hpp>
#include <RockPaperScissorsProtocol/entity/server/ServerMessageType.hpp>

namespace rps::protocol::entity::server
{

using ServerMessageExecutor = MessageExecutor<ServerMessageType, client::ClientMessageType>;

} // namespace rps::protocol::entity::server
