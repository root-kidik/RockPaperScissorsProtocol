#pragma once

#include <tuple>

#include <RockPaperScissorsProtocol/entity/Card.hpp>
#include <RockPaperScissorsProtocol/entity/client/ClientCommand.hpp>

namespace rps::protocol::entity::client
{

struct CardRaisedRequest final : ClientCommand<ClientCommandType::CardRaised>
{
    Card card;

    auto as_tuple()
    {
        return std::tie(card);
    }
};

} // namespace rps::protocol::entity::client
