#pragma once

#include <tuple>

#include <RockPaperScissorsProtocol/entity/Card.hpp>
#include <RockPaperScissorsProtocol/entity/client/ClientMessage.hpp>

namespace rps::protocol::entity::client::request
{

struct RoundInfo final : ClientMessage<ClientMessageType::GameResult>
{
    bool is_winned;

    auto as_tuple()
    {
        return std::tie(is_winned);
    }
};

} // namespace rps::protocol::entity::client::request
