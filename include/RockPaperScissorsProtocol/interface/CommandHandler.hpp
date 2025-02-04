#pragma once

#include <memory>
#include <string>

#include <RockPaperScissorsProtocol/entity/CommandRepresentation.hpp>
#include <RockPaperScissorsProtocol/interface/CommandHandlerBase.hpp>
#include <RockPaperScissorsProtocol/utils/Utils.hpp>

namespace rps::protocol::interface
{

template <typename Request, typename Response>
class CommandHandler : public CommandHandlerBase
{
public:
    void execute(std::string&& data, const std::shared_ptr<Connection>& connection) override final
    {
        connection->send(std::to_string(static_cast<entity::CommandRepresentation>(Response::kType)) + ' ' +
                         utils::serialize(handle(utils::deserialize<Request>(std::move(data)), connection)));
    }

    virtual Response handle(Request&& request, const std::shared_ptr<Connection>& connection) = 0;
};

} // namespace rps::protocol::interface
