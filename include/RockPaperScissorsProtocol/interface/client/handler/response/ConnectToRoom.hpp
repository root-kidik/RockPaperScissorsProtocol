#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/ConnectToRoom.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/ResponseHandler.hpp>

namespace rps::protocol::interface::client::handler::response
{

using ConnectToRoom = ResponseHandler<entity::server::response::Status<entity::server::request::ConnectToRoom>>;

} // namespace rps::protocol::interface::client::handler::response
