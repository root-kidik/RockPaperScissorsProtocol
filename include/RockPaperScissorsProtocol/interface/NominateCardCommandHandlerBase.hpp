#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/NominateCardRequest.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/StatusResponse.hpp>
#include <RockPaperScissorsProtocol/interface/CommandHandler.hpp>

namespace rps::protocol::interface
{

using NominateCardCommandHandlerBase = CommandHandler<entity::server::NominateCardRequest, entity::server::StatusResponse>;

} // namespace rps::protocol::interface
