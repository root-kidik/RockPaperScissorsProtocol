#pragma once

#include <RockPaperScissorsProtocol/entity/Command.hpp>
#include <RockPaperScissorsProtocol/entity/server/ServerCommandTypes.hpp>

namespace rps::protocol::entity
{

template <ServerCommandTypes Type>
struct ServerCommand : Command<ServerCommandTypes, Type>
{
};

} // namespace rps::protocol::entity
