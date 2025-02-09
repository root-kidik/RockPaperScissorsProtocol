#pragma once

#include <RockPaperScissorsProtocol/entity/server/response/Register.hpp>
#include <RockPaperScissorsProtocol/interface/ResponseHandler.hpp>

namespace rps::protocol::interface::client::handler::response
{

using Register = ResponseHandler<entity::server::response::Register>;

} // namespace rps::protocol::interface::client::handler::response
