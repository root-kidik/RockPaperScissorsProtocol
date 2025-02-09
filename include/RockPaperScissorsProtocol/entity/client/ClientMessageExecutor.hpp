#pragma once

#include <RockPaperScissorsProtocol/entity/MessageExecutor.hpp>
#include <RockPaperScissorsProtocol/entity/client/ClientMessageType.hpp>

namespace rps::protocol::entity::client
{

using ClientMessageExecutor = MessageExecutor<ClientMessageType>;

} // namespace rps::protocol::entity::client
