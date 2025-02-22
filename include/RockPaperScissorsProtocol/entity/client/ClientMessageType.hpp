#pragma once

#include <RockPaperScissorsProtocol/entity/MessageRepresentation.hpp>

namespace rps::protocol::entity::client
{

enum class ClientMessageType : MessageRepresentation
{
    Begin = 10'000, // just for min value
    Status,
    NewPlayerAdded,
    GameStarted,
    CardForcedNominated,
    CardRaised,
    RoundInfo,
    DealMissingCard,
    GameResult,
    End // just for max value
};

} // namespace rps::protocol::entity::client
