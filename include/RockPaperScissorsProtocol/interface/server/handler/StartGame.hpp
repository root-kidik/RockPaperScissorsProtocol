#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/StartGameRequest.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/StatusResponse.hpp>
#include <RockPaperScissorsProtocol/interface/CommandHandler.hpp>

namespace rps::protocol::interface::server::handler
{

using StartGame = CommandHandler<entity::server::StartGameRequest, entity::server::StatusResponse>;

} // namespace rps::protocol::interface::server::handler
