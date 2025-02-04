#pragma once

#include <RockPaperScissorsProtocol/entity/CommandRepresentation.hpp>
#include <RockPaperScissorsProtocol/interface/Connection.hpp>
#include <RockPaperScissorsProtocol/utils/Utils.hpp>

namespace rps::protocol::entity
{

// TODO: after full complete server-side, inherit from CommandHandler, add partial specialization for void, and get answer
template <typename Request, typename Response>
class CommandSender
{
public:
    void send(Request&& command, const std::shared_ptr<interface::Connection>& connection)
    {
        connection->send(std::to_string(static_cast<CommandRepresentation>(Request::kType)) + ' ' +
                         utils::serialize(std::move(command)));
    }
};

} // namespace rps::protocol::entity
