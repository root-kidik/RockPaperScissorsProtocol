#pragma once

#include <RockPaperScissorsProtocol/entity/client/request/CardRaised.hpp>
#include <RockPaperScissorsProtocol/entity/client/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/ResponseHandler.hpp>

namespace rps::protocol::interface::server::handler::response
{

using CardRaised = ResponseHandler<entity::client::response::Status<entity::client::request::CardRaised>>;

} // namespace rps::protocol::interface::server::handler::response
