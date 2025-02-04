#pragma once

#include <RockPaperScissorsProtocol/entity/CommandSender.hpp>
#include <RockPaperScissorsProtocol/entity/client/request/NewPlayerAddedRequest.hpp>
#include <RockPaperScissorsProtocol/entity/client/response/StatusResponse.hpp>

namespace rps::protocol::entity
{

using NewPlayerAddedCommandSender = CommandSender<client::NewPlayerAddedRequest, client::StatusResponse>;

} // namespace rps::protocol::entity
