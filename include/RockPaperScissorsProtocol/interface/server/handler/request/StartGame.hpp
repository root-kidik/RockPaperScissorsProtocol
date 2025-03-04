#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/StartGame.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/RequestHandler.hpp>

namespace rps::protocol::interface::server::handler::request
{

using StartGame = RequestHandler<entity::server::request::StartGame,
                                 entity::server::response::Status<entity::server::request::StartGame>>;

} // namespace rps::protocol::interface::server::handler::request
