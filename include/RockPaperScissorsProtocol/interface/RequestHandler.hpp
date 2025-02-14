#pragma once

#include <memory>
#include <string>

#include <RockPaperScissorsProtocol/entity/MessageSender.hpp>
#include <RockPaperScissorsProtocol/interface/MessageHandlerBase.hpp>
#include <RockPaperScissorsProtocol/util/Util.hpp>

namespace rps::protocol::interface
{

template <typename RequestType, typename ResponseType>
class RequestHandler : public MessageHandlerBase
{
public:
    using Request  = RequestType;
    using Response = ResponseType;

    void execute(std::string&& data, const std::shared_ptr<Connection>& connection) override final
    {
        assert(m_message_sender.has_value() && "Message sender must be setted");
        m_message_sender.value().send(handle(util::deserialize<Request>(std::move(data)), connection), connection);
    }

    virtual Response handle(Request&& request, const std::shared_ptr<Connection>& connection) = 0;
};

} // namespace rps::protocol::interface
