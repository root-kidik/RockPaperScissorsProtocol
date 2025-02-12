#pragma once

#include <chrono>
#include <cstdint>

namespace rps::protocol::entity
{

inline constexpr std::uint8_t         kMaxCardsPerPlayer{6};
inline constexpr std::uint8_t         kMaxCardsPerRoom{36};
inline constexpr std::uint8_t         kMaxPlayersPerRoom{4};
inline constexpr std::chrono::seconds kTurnTime{10};

using CardRepresentation = std::uint32_t;

enum class Card : CardRepresentation
{
    Begin, // just for min value
    Rock,
    Paper,
    Scissors,
    Backface,
    End // just for max value
};

} // namespace rps::protocol::entity
