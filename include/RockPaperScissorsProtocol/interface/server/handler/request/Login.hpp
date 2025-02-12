#pragma once

#include <RockPaperScissorsProtocol/entity/server/request/Login.hpp>
#include <RockPaperScissorsProtocol/entity/server/response/Login.hpp>
#include <RockPaperScissorsProtocol/interface/RequestHandler.hpp>

namespace rps::protocol::interface::server::handler::request
{

using Login = RequestHandler<entity::server::request::Login, entity::server::response::Login>;

} // namespace rps::protocol::interface::server::handler::request
