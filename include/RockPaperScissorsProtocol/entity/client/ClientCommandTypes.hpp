#pragma once

#include <cstdint>

namespace rps::protocol::entity
{

enum class ClientCommandTypes : std::uint32_t
{
    Begin,
    NewPlayerAdded,
    End,
};

} // namespace rps::protocol::entity
