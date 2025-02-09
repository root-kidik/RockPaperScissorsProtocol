#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/ConnectToRoom.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/MessageHandler.hpp>

namespace rps::protocol::interface::server::handler
{

using ConnectToRoom = MessageHandler<entity::server::request::ConnectToRoom, entity::server::response::Status>;

} // namespace rps::protocol::interface::server::handler
