#pragma once

#include <optional>
#include <string>

#include <RockPaperScissorsProtocol/entity/client/ClientMessage.hpp>

namespace rps::protocol::entity::client::response
{

struct Status final : ClientMessage<ClientMessageType::Status>
{
    bool is_ok;

    auto as_tuple()
    {
        return std::tie(is_ok);
    }
};

} // namespace rps::protocol::entity::client::response
