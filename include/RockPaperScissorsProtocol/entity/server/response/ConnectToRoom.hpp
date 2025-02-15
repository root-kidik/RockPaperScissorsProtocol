#pragma once

#include <array>
#include <string>

#include <RockPaperScissorsProtocol/entity/Card.hpp>
#include <RockPaperScissorsProtocol/entity/server/ServerMessage.hpp>

namespace rps::protocol::entity::server::response
{

struct ConnectToRoom final : ServerMessage<ServerMessageType::ConnectToRoom>
{
    bool                                            is_ok;
    std::array<std::string, kMaxPlayersPerRoom - 1> existed_players;

    auto as_tuple()
    {
        return std::tie(is_ok, existed_players);
    }
};

} // namespace rps::protocol::entity::server::response
