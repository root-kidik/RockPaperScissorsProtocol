#pragma once

#include <RockPaperScissorsProtocol/entity/MessageRepresentation.hpp>

namespace rps::protocol::entity::server
{

enum class ServerMessageType : MessageRepresentation
{
    Begin, // just for min value
    Status,
    Register,
    Login,
    CreateRoom,
    ConnectToRoom,
    StartGame,
    NominateCard,
    End // just for max value
};

} // namespace rps::protocol::entity::server
