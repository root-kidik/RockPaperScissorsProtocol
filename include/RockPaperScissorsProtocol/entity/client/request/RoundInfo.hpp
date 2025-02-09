#pragma once

#include <optional>
#include <string>

#include <RockPaperScissorsProtocol/entity/client/ClientMessage.hpp>

namespace rps::protocol::entity::client::request
{

struct RoundInfo final : ClientMessage<ClientMessageType::RoundInfo>
{
    bool is_winned;

    auto as_tuple()
    {
        return std::tie(is_winned);
    }
};

} // namespace rps::protocol::entity::client::request
