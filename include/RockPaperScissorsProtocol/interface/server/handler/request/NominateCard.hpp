#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/NominateCard.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/RequestHandler.hpp>

namespace rps::protocol::interface::server::handler::request
{

using NominateCard = RequestHandler<entity::server::request::NominateCard,
                                    entity::server::response::Status<entity::server::request::NominateCard>>;

} // namespace rps::protocol::interface::server::handler::request
