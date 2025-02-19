#pragma once

#include <array>
#include <tuple>

#include <RockPaperScissorsProtocol/entity/Card.hpp>
#include <RockPaperScissorsProtocol/entity/client/ClientMessage.hpp>

namespace rps::protocol::entity::client::request
{

struct RoundInfo final : ClientMessage<ClientMessageType::RoundInfo>
{
    bool                                 is_winned;
    std::array<Card, kMaxPlayersPerRoom> raised_cards;

    auto as_tuple()
    {
        return std::tie(is_winned, raised_cards);
    }
};

} // namespace rps::protocol::entity::client::request
