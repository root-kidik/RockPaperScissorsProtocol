#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/CreateRoom.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/RequestHandler.hpp>

namespace rps::protocol::interface::server::handler::request
{

using CreateRoom = RequestHandler<entity::server::request::CreateRoom,
                                  entity::server::response::Status<entity::server::request::CreateRoom>>;

} // namespace rps::protocol::interface::server::handler::request
