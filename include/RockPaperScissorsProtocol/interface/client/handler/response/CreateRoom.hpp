#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/CreateRoom.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/ResponseHandler.hpp>

namespace rps::protocol::interface::client::handler::response
{

using CreateRoom = ResponseHandler<entity::server::response::Status<entity::server::request::CreateRoom>>;

} // namespace rps::protocol::interface::client::handler::response
