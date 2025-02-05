#pragma once

#include <array>

#include <RockPaperScissorsProtocol/entity/Card.hpp>
#include <RockPaperScissorsProtocol/entity/client/ClientCommand.hpp>

namespace rps::protocol::entity::client
{

struct GameStartedRequest final : ClientCommand<ClientCommandType::GameStarted>
{
    std::array<Card, kMaxCardsPerPlayer> cards;

    auto as_tuple()
    {
        return std::tie(cards);
    }
};

} // namespace rps::protocol::entity::client
