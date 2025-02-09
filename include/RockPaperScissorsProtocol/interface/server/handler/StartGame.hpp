#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/StartGame.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/MessageHandler.hpp>

namespace rps::protocol::interface::server::handler
{

using StartGame = MessageHandler<entity::server::request::StartGame, entity::server::response::Status>;

} // namespace rps::protocol::interface::server::handler
