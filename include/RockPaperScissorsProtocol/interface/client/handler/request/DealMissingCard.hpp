#pragma once

#include <RockPaperScissorsProtocol/entity/client/request/DealMissingCard.hpp>
#include <RockPaperScissorsProtocol/entity/client/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/RequestHandler.hpp>

namespace rps::protocol::interface::client::handler::request
{

using DealMissingCard = RequestHandler<entity::client::request::DealMissingCard,
                                       entity::client::response::Status<entity::client::request::DealMissingCard>>;

} // namespace rps::protocol::interface::client::handler::request
