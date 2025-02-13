#pragma once

#include <string>

#include <RockPaperScissorsProtocol/entity/Card.hpp>
#include <RockPaperScissorsProtocol/entity/server/ServerMessage.hpp>

namespace rps::protocol::entity::server::request
{

struct NominateCard final : ServerMessage<ServerMessageType::NominateCard>
{
    std::string room_name;
    std::string user_uuid;
    Card        card;

    auto as_tuple()
    {
        return std::tie(room_name, user_uuid, card);
    }
};

} // namespace rps::protocol::entity::server::request
