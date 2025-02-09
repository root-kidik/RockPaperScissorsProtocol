#pragma once

#include <RockPaperScissorsProtocol/entity/client/request/DealMissingCard.hpp>
#include <RockPaperScissorsProtocol/entity/client/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/ResponseHandler.hpp>

namespace rps::protocol::interface::server::handler::response
{

using DealMissingCard = ResponseHandler<entity::client::response::Status<entity::client::request::DealMissingCard>>;

} // namespace rps::protocol::interface::server::handler::response
