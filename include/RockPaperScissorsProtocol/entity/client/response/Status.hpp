#pragma once

#include <RockPaperScissorsProtocol/entity/client/ClientMessage.hpp>

namespace rps::protocol::entity::client::response
{

template <typename Response>
struct Status final : ClientMessage<Response::kType>
{
    bool is_ok;

    auto as_tuple()
    {
        return std::tie(is_ok);
    }
};

} // namespace rps::protocol::entity::client::response
