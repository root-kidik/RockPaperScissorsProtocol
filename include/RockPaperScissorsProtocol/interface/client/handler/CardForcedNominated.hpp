#pragma once

#include <RockPaperScissorsProtocol/entity/client/request/CardForcedNominatedRequest.hpp>
#include <RockPaperScissorsProtocol/entity/client/response/StatusResponse.hpp>
#include <RockPaperScissorsProtocol/interface/CommandHandler.hpp>

namespace rps::protocol::interface::client::handler
{

using CardForcedNominated = CommandHandler<entity::client::CardForcedNominatedRequest, entity::client::StatusResponse>;

} // namespace rps::protocol::interface::client::handler
