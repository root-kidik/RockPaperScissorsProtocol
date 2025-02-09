#pragma once

#include <array>
#include <tuple>

#include <RockPaperScissorsProtocol/entity/Card.hpp>
#include <RockPaperScissorsProtocol/entity/client/ClientMessage.hpp>

namespace rps::protocol::entity::client::request
{

struct CardForcedNominated final : ClientMessage<ClientMessageType::CardForcedNominated>
{
    Card card;

    auto as_tuple()
    {
        return std::tie(card);
    }
};

} // namespace rps::protocol::entity::client::request
