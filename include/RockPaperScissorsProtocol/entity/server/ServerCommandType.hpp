#pragma once

#include <cstdint>

namespace rps::protocol::entity
{

enum class ServerCommandType : std::uint32_t
{
    Begin,
    Register,
    CreateRoom,
    ConnectToRoom,
    End,
};

} // namespace rps::protocol::entity
