#pragma once

#include <RockPaperScissorsProtocol/entity/client/request/CardRaised.hpp>
#include <RockPaperScissorsProtocol/entity/client/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/RequestHandler.hpp>

namespace rps::protocol::interface::client::handler::request
{

using CardRaised = RequestHandler<entity::client::request::CardRaised,
                                  entity::client::response::Status<entity::client::request::CardRaised>>;

} // namespace rps::protocol::interface::client::handler::request
