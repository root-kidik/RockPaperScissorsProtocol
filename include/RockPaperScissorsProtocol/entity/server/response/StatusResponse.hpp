#pragma once

#include <optional>
#include <string>

#include <RockPaperScissorsProtocol/entity/server/ServerCommand.hpp>

namespace rps::protocol::entity
{

struct StatusResponse : ServerCommand<ServerCommandType::Status>
{
    bool is_ok;

    auto as_tuple()
    {
        return std::tie(is_ok);
    }
};

} // namespace rps::protocol::entity
