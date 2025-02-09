#pragma once

#include <RockPaperScissorsProtocol/entity/MessageExecutor.hpp>
#include <RockPaperScissorsProtocol/entity/client/ClientMessageType.hpp>
#include <RockPaperScissorsProtocol/entity/server/ServerMessageType.hpp>

namespace rps::protocol::entity::client
{

using ClientMessageExecutor = MessageExecutor<ClientMessageType, server::ServerMessageType>;

} // namespace rps::protocol::entity::client
