#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/Register.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/Register.hpp>
#include <RockPaperScissorsProtocol/interface/CommandHandler.hpp>

namespace rps::protocol::interface::server::handler
{

using Register = CommandHandler<entity::server::request::Register, entity::server::response::Register>;

} // namespace rps::protocol::interface::server::handler
