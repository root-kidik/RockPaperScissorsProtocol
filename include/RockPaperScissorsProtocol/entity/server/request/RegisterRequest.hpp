#pragma once

#include <optional>
#include <string>

#include <RockPaperScissorsProtocol/entity/server/ServerCommand.hpp>

namespace rps::protocol::entity
{

struct RegisterRequest final : ServerCommand<ServerCommandType::Register>
{
    std::string user_nickname;

    auto as_tuple()
    {
        return std::tie(user_nickname);
    }
};

} // namespace rps::protocol::entity
