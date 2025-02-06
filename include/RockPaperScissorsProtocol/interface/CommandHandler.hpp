#pragma once

#include <memory>
#include <string>

#include <RockPaperScissorsProtocol/entity/CommandRepresentation.hpp>
#include <RockPaperScissorsProtocol/interface/CommandHandlerBase.hpp>
#include <RockPaperScissorsProtocol/util/Util.hpp>

namespace rps::protocol::interface
{

template <typename Request, typename Response>
class CommandHandler : public CommandHandlerBase
{
public:
    using RequestType = Request;

    void execute(std::string&& data, const std::shared_ptr<Connection>& connection) override final
    {
        connection->send(std::to_string(static_cast<entity::CommandRepresentation>(Response::kType)) + ' ' +
                         util::serialize(handle(util::deserialize<Request>(std::move(data)), connection)));
    }

    virtual Response handle(Request&& request, const std::shared_ptr<Connection>& connection) = 0;
};

} // namespace rps::protocol::interface
