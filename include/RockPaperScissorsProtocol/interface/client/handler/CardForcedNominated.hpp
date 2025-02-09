#pragma once

#include <RockPaperScissorsProtocol/entity/client/request/CardForcedNominated.hpp>
#include <RockPaperScissorsProtocol/entity/client/response/StatusResponse.hpp>
#include <RockPaperScissorsProtocol/interface/CommandHandler.hpp>

namespace rps::protocol::interface::client::handler
{

using CardForcedNominated = CommandHandler<entity::client::CardForcedNominated, entity::client::StatusResponse>;

} // namespace rps::protocol::interface::client::handler
