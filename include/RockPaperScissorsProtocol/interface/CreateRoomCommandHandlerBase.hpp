#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/CreateRoomRequest.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/StatusResponse.hpp>
#include <RockPaperScissorsProtocol/interface/CommandHandler.hpp>

namespace rps::protocol::interface
{

using CreateRoomCommandHandlerBase = CommandHandler<entity::server::CreateRoomRequest, entity::server::StatusResponse>;

} // namespace rps::protocol::interface
