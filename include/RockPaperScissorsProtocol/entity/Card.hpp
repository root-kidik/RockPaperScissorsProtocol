#pragma once

#include <cstdint>

namespace rps::protocol::entity
{

inline constexpr std::uint32_t kMaxCardsPerPlayer{6};
inline constexpr std::uint32_t kMaxCardsPerRoom{36};

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
