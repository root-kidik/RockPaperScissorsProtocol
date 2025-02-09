#pragma once

#include <RockPaperScissorsProtocol/entity/client/request/RoundInfo.hpp>
#include <RockPaperScissorsProtocol/entity/client/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/ResponseHandler.hpp>

namespace rps::protocol::interface::server::handler::response
{

using RoundInfo = ResponseHandler<entity::client::response::Status<entity::client::request::RoundInfo>>;

} // namespace rps::protocol::interface::server::handler::response
