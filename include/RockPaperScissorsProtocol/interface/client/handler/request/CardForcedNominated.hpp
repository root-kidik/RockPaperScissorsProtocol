#pragma once

#include <RockPaperScissorsProtocol/entity/client/request/CardForcedNominated.hpp>
#include <RockPaperScissorsProtocol/entity/client/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/RequestHandler.hpp>

namespace rps::protocol::interface::client::handler::request
{

using CardForcedNominated = RequestHandler<entity::client::request::CardForcedNominated,
                                           entity::client::response::Status<entity::client::request::CardForcedNominated>>;

} // namespace rps::protocol::interface::client::handler::request
