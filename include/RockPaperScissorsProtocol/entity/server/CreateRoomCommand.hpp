#pragma once

#include <optional>
#include <string>

#include <RockPaperScissorsProtocol/entity/server/ServerCommand.hpp>

namespace rps::protocol::entity
{

struct CreateRoomCommand : ServerCommand<ServerCommandType::CreateRoom>
{
    std::string user_uuid;
    std::string room_name;

    auto as_tuple()
    {
        return std::make_tuple(std::ref(user_uuid), std::ref(room_name));
    }
};

} // namespace rps::protocol::entity
