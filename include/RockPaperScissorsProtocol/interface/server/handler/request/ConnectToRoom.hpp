#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/ConnectToRoom.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/RequestHandler.hpp>

namespace rps::protocol::interface::server::handler::request
{

using ConnectToRoom = RequestHandler<entity::server::request::ConnectToRoom,
                                     entity::server::response::Status<entity::server::request::ConnectToRoom>>;

} // namespace rps::protocol::interface::server::handler::request::::
