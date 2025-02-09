#pragma once

#include <RockPaperScissorsProtocol/entity/client/request/GameStarted.hpp>
#include <RockPaperScissorsProtocol/entity/client/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/ResponseHandler.hpp>

namespace rps::protocol::interface::server::handler::response
{

using GameStarted = ResponseHandler<entity::client::response::Status<entity::client::request::GameStarted>>;

} // namespace rps::protocol::interface::server::handler::response
