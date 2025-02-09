#pragma once

#include <RockPaperScissorsProtocol/entity/client/request/CardForcedNominated.hpp>
#include <RockPaperScissorsProtocol/entity/client/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/ResponseHandler.hpp>

namespace rps::protocol::interface::server::handler::response
{

using CardForcedNominated = ResponseHandler<entity::client::response::Status<entity::client::request::CardForcedNominated>>;

} // namespace rps::protocol::interface::server::handler::response
