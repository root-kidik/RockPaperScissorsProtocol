#pragma once

#include <optional>
#include <string>

#include <RockPaperScissorsProtocol/entity/client/ClientMessage.hpp>

namespace rps::protocol::entity::client::request
{

struct NewPlayerAdded final : ClientMessage<ClientMessageType::NewPlayerAdded>
{
    std::string user_nickname;

    auto as_tuple()
    {
        return std::tie(user_nickname);
    }
};

} // namespace rps::protocol::entity::client::request
