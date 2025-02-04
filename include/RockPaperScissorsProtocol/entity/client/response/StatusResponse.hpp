#pragma once

#include <optional>
#include <string>

#include <RockPaperScissorsProtocol/entity/client/ClientCommand.hpp>

namespace rps::protocol::entity::client
{

struct StatusResponse final : ClientCommand<ClientCommandType::Status>
{
    bool is_ok;

    auto as_tuple()
    {
        return std::tie(is_ok);
    }
};

} // namespace rps::protocol::entity::client
