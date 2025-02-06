#pragma once

#include <RockPaperScissorsProtocol/entity/CommandRepresentation.hpp>

namespace rps::protocol::entity::server
{

enum class ServerCommandType : CommandRepresentation
{
    Begin, // just for min value
    Status,
    Register,
    CreateRoom,
    ConnectToRoom,
    StartGame,
    NominateCard,
    End // just for max value
};

} // namespace rps::protocol::entity::server
