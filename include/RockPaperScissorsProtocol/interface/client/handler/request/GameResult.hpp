#pragma once

#include <RockPaperScissorsProtocol/entity/client/request/GameResult.hpp>
#include <RockPaperScissorsProtocol/entity/client/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/RequestHandler.hpp>

namespace rps::protocol::interface::client::handler::request
{

using GameResult = RequestHandler<entity::client::request::GameResult,
                                  entity::client::response::Status<entity::client::request::GameResult>>;

} // namespace rps::protocol::interface::client::handler::request
