#pragma once

#include <cstdint>

namespace rps::protocol::entity
{

enum class ServerCommandTypes : std::uint32_t
{
    Begin,
    Register,
    CreateRoom,
    ConnectToRoom,
    End,
};

} // namespace rps::protocol::entity
