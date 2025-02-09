#pragma once

#include <memory>

#include <RockPaperScissorsProtocol/entity/MessageRepresentation.hpp>
#include <RockPaperScissorsProtocol/interface/Connection.hpp>
#include <RockPaperScissorsProtocol/util/Util.hpp>

namespace rps::protocol::entity
{

// TODO: after full complete server-side, inherit from RequestHandler, add partial specialization for void, and get answer
class MessageSender
{
public:
    template <typename Request>
    void send(Request&& command, const std::shared_ptr<interface::Connection>& connection)
    {
        connection->send(util::serialize_message(std::move(command)));
    }
};

} // namespace rps::protocol::entity
