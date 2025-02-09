#pragma once

#include <array>
#include <tuple>

#include <RockPaperScissorsProtocol/entity/Card.hpp>
#include <RockPaperScissorsProtocol/entity/client/ClientMessage.hpp>

namespace rps::protocol::entity::client::request
{

struct GameStarted final : ClientMessage<ClientMessageType::GameStarted>
{
    std::array<Card, kMaxCardsPerPlayer> cards;

    auto as_tuple()
    {
        return std::tie(cards);
    }
};

} // namespace rps::protocol::entity::client::request
