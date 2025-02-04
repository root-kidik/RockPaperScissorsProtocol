#pragma once

#include <RockPaperScissorsProtocol/entity/CommandSender.hpp>
#include <RockPaperScissorsProtocol/entity/client/request/GameStartedRequest.hpp>
#include <RockPaperScissorsProtocol/entity/client/response/StatusResponse.hpp>

namespace rps::protocol::entity
{

using GameStartedCommandSender = CommandSender<client::GameStartedRequest, client::StatusResponse>;

} // namespace rps::protocol::entity
