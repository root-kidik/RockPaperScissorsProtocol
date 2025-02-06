#pragma once

#include <RockPaperScissorsProtocol/entity/CommandRepresentation.hpp>

namespace rps::protocol::entity::client
{

enum class ClientCommandType : CommandRepresentation
{
    Begin = 10'000, // just for min value
    Status,
    NewPlayerAdded,
    GameStarted,
    CardForcedNominated,
    CardRaised,
    RoundInfo,
    DealMissingCard,
    End // just for max value
};

} // namespace rps::protocol::entity::client
