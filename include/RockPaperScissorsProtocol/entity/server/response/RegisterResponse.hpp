#pragma once

#include <optional>
#include <string>

#include <RockPaperScissorsProtocol/entity/server/ServerCommand.hpp>

namespace rps::protocol::entity
{

struct RegisterResponse final : ServerCommand<ServerCommandType::Register>
{
    std::string user_uuid;

    auto as_tuple()
    {
        return std::tie(user_uuid);
    }
};

} // namespace rps::protocol::entity
