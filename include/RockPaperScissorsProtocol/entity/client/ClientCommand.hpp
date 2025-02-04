#pragma once

#include <RockPaperScissorsProtocol/entity/Command.hpp>
#include <RockPaperScissorsProtocol/entity/client/ClientCommandType.hpp>

namespace rps::protocol::entity::client
{

template <ClientCommandType Type>
struct ClientCommand : Command<ClientCommandType, Type>
{
};

} // namespace rps::protocol::entity::client
