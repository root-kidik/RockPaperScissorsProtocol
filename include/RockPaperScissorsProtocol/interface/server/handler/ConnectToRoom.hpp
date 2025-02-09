#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/ConnectToRoom.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/CommandHandler.hpp>

namespace rps::protocol::interface::server::handler
{

using ConnectToRoom = CommandHandler<entity::server::request::ConnectToRoom, entity::server::response::Status>;

} // namespace rps::protocol::interface::server::handler
