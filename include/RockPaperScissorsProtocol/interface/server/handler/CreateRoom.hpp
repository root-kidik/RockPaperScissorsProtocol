#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/CreateRoom.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/CommandHandler.hpp>

namespace rps::protocol::interface::server::handler
{

using CreateRoom = CommandHandler<entity::server::request::CreateRoom, entity::server::response::Status>;

} // namespace rps::protocol::interface::server::handler
