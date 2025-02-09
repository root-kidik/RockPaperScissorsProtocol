#pragma once

#include <optional>
#include <string>

#include <RockPaperScissorsProtocol/entity/server/ServerMessage.hpp>

namespace rps::protocol::entity::server::response
{

struct Status final : ServerMessage<ServerMessageType::Status>
{
    bool is_ok;

    auto as_tuple()
    {
        return std::tie(is_ok);
    }
};

} // namespace rps::protocol::entity::server::response
