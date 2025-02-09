#pragma once

#include <array>
#include <tuple>

#include <RockPaperScissorsProtocol/entity/Card.hpp>
#include <RockPaperScissorsProtocol/entity/client/ClientCommand.hpp>

namespace rps::protocol::entity::client::request
{

struct GameStarted final : ClientCommand<ClientCommandType::GameStarted>
{
    std::array<Card, kMaxCardsPerPlayer> cards;

    auto as_tuple()
    {
        return std::tie(cards);
    }
};

} // namespace rps::protocol::entity::client::request
