#pragma once

#include <optional>
#include <string>

#include <RockPaperScissorsProtocol/entity/server/ServerCommand.hpp>

namespace rps::protocol::entity
{

struct CreateRoomCommand : ServerCommand<ServerCommandType::CreateRoom>
{
    std::string room_name;
    std::string user_uuid;

    auto as_tuple()
    {
        return std::make_tuple(std::ref(room_name), std::ref(user_uuid));
    }
};

} // namespace rps::protocol::entity
