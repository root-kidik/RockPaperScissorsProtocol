#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/Register.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/ResponseHandler.hpp>

namespace rps::protocol::interface::client::handler::response
{

using Register = ResponseHandler<entity::server::response::Status<entity::server::request::Register>>;

} // namespace rps::protocol::interface::client::handler::response
