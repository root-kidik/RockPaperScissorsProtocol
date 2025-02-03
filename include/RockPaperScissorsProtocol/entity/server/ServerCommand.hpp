#pragma once

#include <RockPaperScissorsProtocol/entity/Command.hpp>
#include <RockPaperScissorsProtocol/entity/server/ServerCommandType.hpp>

namespace rps::protocol::entity
{

template <ServerCommandType Type>
struct ServerCommand : Command<ServerCommandType, Type>
{
};

} // namespace rps::protocol::entity
