#pragma once

#include <RockPaperScissorsProtocol/entity/Command.hpp>
#include <RockPaperScissorsProtocol/entity/client/ClientCommandTypes.hpp>

namespace rps::protocol::entity
{

template <ClientCommandTypes Type>
struct ClientCommand : Command<ClientCommandTypes, Type>
{
};

} // namespace rps::protocol::entity
