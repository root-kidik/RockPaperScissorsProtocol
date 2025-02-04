#pragma once

#include <optional>
#include <string>

#include <RockPaperScissorsProtocol/entity/client/ClientCommand.hpp>

namespace rps::protocol::entity::client
{

struct GameStartedRequest final : ClientCommand<ClientCommandType::GameStarted>
{
    std::string room_name;

    auto as_tuple()
    {
        return std::tie(room_name);
    }
};

} // namespace rps::protocol::entity::client
