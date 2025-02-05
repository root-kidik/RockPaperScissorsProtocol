#pragma once

#include <array>
#include <tuple>

#include <RockPaperScissorsProtocol/entity/Card.hpp>
#include <RockPaperScissorsProtocol/entity/client/ClientCommand.hpp>

namespace rps::protocol::entity::client
{

struct CardForcedNominatedRequest final : ClientCommand<ClientCommandType::CardForcedNominated>
{
    Card card;

    auto as_tuple()
    {
        return std::tie(card);
    }
};

} // namespace rps::protocol::entity::client
