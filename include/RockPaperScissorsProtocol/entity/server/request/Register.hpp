#pragma once

#include <optional>
#include <string>

#include <RockPaperScissorsProtocol/entity/server/ServerMessage.hpp>

namespace rps::protocol::entity::server::request
{

struct Register final : ServerMessage<ServerMessageType::Register>
{
    std::string user_nickname;

    auto as_tuple()
    {
        return std::tie(user_nickname);
    }
};

} // namespace rps::protocol::entity::server::request
