#pragma once

#include <RockPaperScissorsProtocol/entity/Message.hpp>
#include <RockPaperScissorsProtocol/entity/server/ServerMessageType.hpp>

namespace rps::protocol::entity::server
{

template <ServerMessageType Type>
struct ServerMessage : Message<ServerMessageType, Type>
{
};

} // namespace rps::protocol::entity::server
