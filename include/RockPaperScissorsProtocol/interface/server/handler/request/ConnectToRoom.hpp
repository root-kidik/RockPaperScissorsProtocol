#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/ConnectToRoom.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/ConnectToRoom.hpp>
#include <RockPaperScissorsProtocol/interface/RequestHandler.hpp>

namespace rps::protocol::interface::server::handler::request
{

using ConnectToRoom = RequestHandler<entity::server::request::ConnectToRoom, entity::server::response::ConnectToRoom>;

} // namespace rps::protocol::interface::server::handler::request
