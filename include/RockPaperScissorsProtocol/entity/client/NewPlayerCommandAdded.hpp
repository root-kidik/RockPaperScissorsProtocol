#pragma once

#include <optional>
#include <string>

#include <RockPaperScissorsProtocol/entity/client/ClientCommand.hpp>

namespace rps::protocol::entity
{

struct NewPlayerAdded : ClientCommand<ClientCommandType::NewPlayerAdded>
{
    std::string user_nickname;

    auto as_tuple()
    {
        return std::tie(user_nickname);
    }
};

} // namespace rps::protocol::entity
