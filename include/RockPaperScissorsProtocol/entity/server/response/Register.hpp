#pragma once

#include <string>

#include <RockPaperScissorsProtocol/entity/server/ServerMessage.hpp>

namespace rps::protocol::entity::server::response
{

struct Register final : ServerMessage<ServerMessageType::Register>
{
    std::string user_uuid;

    auto as_tuple()
    {
        return std::tie(user_uuid);
    }
};

} // namespace rps::protocol::entity::server::response
