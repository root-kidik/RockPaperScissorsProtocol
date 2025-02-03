#pragma once

#include <cstdint>

namespace rps::protocol::entity
{

enum class ClientCommandType : std::uint32_t
{
    Begin = 10000,
    NewPlayerAdded,
    End,
};

} // namespace rps::protocol::entity
