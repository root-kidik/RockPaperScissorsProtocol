#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/Register.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/Register.hpp>
#include <RockPaperScissorsProtocol/interface/MessageHandler.hpp>

namespace rps::protocol::interface::server::handler
{

using Register = MessageHandler<entity::server::request::Register, entity::server::response::Register>;

} // namespace rps::protocol::interface::server::handler
