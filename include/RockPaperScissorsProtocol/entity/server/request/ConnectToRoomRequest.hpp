#pragma once

#include <optional>
#include <string>

#include <RockPaperScissorsProtocol/entity/server/ServerCommand.hpp>

namespace rps::protocol::entity
{

struct ConnectToRoomRequest final : ServerCommand<ServerCommandType::ConnectToRoom>
{
    std::string user_uuid;
    std::string room_name;

    auto as_tuple()
    {
        return std::tie(user_uuid, room_name);
    }
};

} // namespace rps::protocol::entity
