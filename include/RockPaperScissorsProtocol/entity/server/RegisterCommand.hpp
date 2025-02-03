#pragma once

#include <optional>
#include <string>

#include <RockPaperScissorsProtocol/entity/server/ServerCommand.hpp>

namespace rps::protocol::entity
{

struct RegisterCommand : ServerCommand<ServerCommandType::Register>
{
    std::string user_nickname;

    auto as_tuple()
    {
        return std::make_tuple(user_nickname);
    }
};

} // namespace rps::protocol::entity
