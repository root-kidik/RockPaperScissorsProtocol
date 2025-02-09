#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/StartGame.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/ResponseHandler.hpp>

namespace rps::protocol::interface::server::handler::response
{

using StartGame = ResponseHandler<entity::server::response::Status<entity::server::request::StartGame>>;

} // namespace rps::protocol::interface::server::handler::response
