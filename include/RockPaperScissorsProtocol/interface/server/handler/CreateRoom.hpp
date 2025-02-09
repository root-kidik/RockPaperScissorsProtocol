#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/CreateRoom.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/MessageHandler.hpp>

namespace rps::protocol::interface::server::handler
{

using CreateRoom = MessageHandler<entity::server::request::CreateRoom,
                                  entity::server::response::Status<entity::server::request::CreateRoom>>;

} // namespace rps::protocol::interface::server::handler
