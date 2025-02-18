#pragma once

#include <RockPaperScissorsProtocol/entity/client/request/RoundInfo.hpp>
#include <RockPaperScissorsProtocol/entity/client/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/RequestHandler.hpp>

namespace rps::protocol::interface::client::handler::request
{

using RoundInfo = RequestHandler<entity::client::request::RoundInfo,
                                 entity::client::response::Status<entity::client::request::RoundInfo>>;

} // namespace rps::protocol::interface::client::handler::request
