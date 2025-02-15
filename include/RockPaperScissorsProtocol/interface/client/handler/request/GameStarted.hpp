#pragma once

#include <RockPaperScissorsProtocol/entity/client/request/GameStarted.hpp>
#include <RockPaperScissorsProtocol/entity/client/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/RequestHandler.hpp>

namespace rps::protocol::interface::client::handler::request
{

using GameStarted = RequestHandler<entity::client::request::GameStarted,
                                   entity::client::response::Status<entity::client::request::GameStarted>>;

} // namespace rps::protocol::interface::client::handler::request
