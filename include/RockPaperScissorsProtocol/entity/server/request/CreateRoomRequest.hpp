#pragma once

#include <optional>
#include <string>

#include <RockPaperScissorsProtocol/entity/server/ServerCommand.hpp>

namespace rps::protocol::entity::server
{

struct CreateRoomRequest final : ServerCommand<ServerCommandType::CreateRoom>
{
    std::string room_name;
    std::string user_uuid;

    auto as_tuple()
    {
        return std::tie(room_name, user_uuid);
    }
};

} // namespace rps::protocol::entity::server
