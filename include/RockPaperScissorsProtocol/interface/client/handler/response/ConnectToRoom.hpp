#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/ConnectToRoom.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/ConnectToRoom.hpp>
#include <RockPaperScissorsProtocol/interface/ResponseHandler.hpp>

namespace rps::protocol::interface::client::handler::response
{

using ConnectToRoom = ResponseHandler<entity::server::response::ConnectToRoom>;

} // namespace rps::protocol::interface::client::handler::response
