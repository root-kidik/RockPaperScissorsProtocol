#pragma once

#include <RockPaperScissorsProtocol/entity/Message.hpp>
#include <RockPaperScissorsProtocol/entity/client/ClientMessageType.hpp>

namespace rps::protocol::entity::client
{

template <ClientMessageType Type>
struct ClientMessage : Message<ClientMessageType, Type>
{
};

} // namespace rps::protocol::entity::client
