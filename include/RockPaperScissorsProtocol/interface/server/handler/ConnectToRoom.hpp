#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/ConnectToRoomRequest.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/StatusResponse.hpp>
#include <RockPaperScissorsProtocol/interface/CommandHandler.hpp>

namespace rps::protocol::interface::server::handler
{

using ConnectToRoom = CommandHandler<entity::server::ConnectToRoomRequest, entity::server::StatusResponse>;

} // namespace rps::protocol::interface::server::handler
