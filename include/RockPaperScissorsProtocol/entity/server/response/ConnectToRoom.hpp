#pragma once

#include <string>
#include <array>

#include <RockPaperScissorsProtocol/entity/server/ServerMessage.hpp>
#include <RockPaperScissorsProtocol/entity/Card.hpp>

namespace rps::protocol::entity::server::response
{

struct ConnectToRoom final : ServerMessage<ServerMessageType::ConnectToRoom>
{
    std::array<std::string, kMaxPlayersPerRoom - 1> existed_players;

    auto as_tuple()
    {
        return std::tie(existed_players);
    }
};

} // namespace rps::protocol::entity::server::response
