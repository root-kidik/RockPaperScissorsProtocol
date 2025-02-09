#pragma once

#include <RockPaperScissorsProtocol/entity/client/request/NewPlayerAdded.hpp>
#include <RockPaperScissorsProtocol/entity/client/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/ResponseHandler.hpp>

namespace rps::protocol::interface::server::handler::response
{

using NewPlayerAdded = ResponseHandler<entity::client::response::Status<entity::client::request::NewPlayerAdded>>;

} // namespace rps::protocol::interface::server::handler::response
