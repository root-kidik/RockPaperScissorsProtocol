#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/NominateCard.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/MessageHandler.hpp>

namespace rps::protocol::interface::server::handler
{

using NominateCard = MessageHandler<entity::server::request::NominateCard, entity::server::response::Status>;

} // namespace rps::protocol::interface::server::handler
