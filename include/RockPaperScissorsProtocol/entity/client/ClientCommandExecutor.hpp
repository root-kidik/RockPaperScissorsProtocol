#pragma once

#include <RockPaperScissorsProtocol/entity/CommandExecutor.hpp>
#include <RockPaperScissorsProtocol/entity/client/ClientMessageType.hpp>

namespace rps::protocol::entity::client
{

using ClientCommandExecutor = CommandExecutor<ClientMessageType>;

} // namespace rps::protocol::entity::client
