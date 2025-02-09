#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/RegisterRequest.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/RegisterResponse.hpp>
#include <RockPaperScissorsProtocol/interface/CommandHandler.hpp>

namespace rps::protocol::interface::server::handler
{

using Register = CommandHandler<entity::server::RegisterRequest, entity::server::RegisterResponse>;

} // namespace rps::protocol::interface::server::handler
