#pragma once

#include <memory>
#include <string>

#include <RockPaperScissorsProtocol/interface/MessageHandlerBase.hpp>
#include <RockPaperScissorsProtocol/util/Util.hpp>

namespace rps::protocol::interface
{

template <typename RequestType, typename ResponseType>
class MessageHandler : public MessageHandlerBase
{
public:
    using Request  = RequestType;
    using Response = ResponseType;

    void execute(std::string&& data, const std::shared_ptr<Connection>& connection) override final
    {
        connection->send(util::serialize_message(handle(util::deserialize<Request>(std::move(data)), connection)));
    }

    virtual Response handle(Request&& request, const std::shared_ptr<Connection>& connection) = 0;
};

} // namespace rps::protocol::interface
