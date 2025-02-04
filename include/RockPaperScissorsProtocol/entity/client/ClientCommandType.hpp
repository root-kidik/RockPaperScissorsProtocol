#pragma once

#include <RockPaperScissorsProtocol/entity/CommandRepresentation.hpp>

namespace rps::protocol::entity
{

enum class ClientCommandType : CommandRepresentation
{
    Begin = 10000, // just for min value
    NewPlayerAdded,
    End // just for max value
};

} // namespace rps::protocol::entity
