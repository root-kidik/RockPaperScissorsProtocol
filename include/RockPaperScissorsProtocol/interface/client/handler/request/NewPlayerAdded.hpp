#pragma once

#include <RockPaperScissorsProtocol/entity/client/request/NewPlayerAdded.hpp>
#include <RockPaperScissorsProtocol/entity/client/response/Status.hpp>
#include <RockPaperScissorsProtocol/interface/RequestHandler.hpp>

namespace rps::protocol::interface::client::handler::request
{

using NewPlayerAdded = RequestHandler<entity::client::request::NewPlayerAdded,
                                      entity::client::response::Status<entity::client::request::NewPlayerAdded>>;

} // namespace rps::protocol::interface::client::handler::request
