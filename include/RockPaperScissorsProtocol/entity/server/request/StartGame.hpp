#pragma once

#include <string>

#include <RockPaperScissorsProtocol/entity/server/ServerMessage.hpp>

namespace rps::protocol::entity::server::request
{

struct StartGame final : ServerMessage<ServerMessageType::StartGame>
{
    std::string user_uuid;
    std::string room_name;

    auto as_tuple()
    {
        return std::tie(user_uuid, room_name);
    }
};

} // namespace rps::protocol::entity::server::request
