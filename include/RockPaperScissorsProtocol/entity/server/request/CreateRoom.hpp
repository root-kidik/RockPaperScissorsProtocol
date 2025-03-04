#pragma once

#include <string>

#include <RockPaperScissorsProtocol/entity/server/ServerMessage.hpp>

namespace rps::protocol::entity::server::request
{

struct CreateRoom final : ServerMessage<ServerMessageType::CreateRoom>
{
    std::string room_name;
    std::string user_uuid;

    auto as_tuple()
    {
        return std::tie(room_name, user_uuid);
    }
};

} // namespace rps::protocol::entity::server::request
