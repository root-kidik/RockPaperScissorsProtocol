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

    RequestHandler(entity::MessageSender& message_sender) : m_message_sender{message_sender}
    {

    }

    void execute(std::string&& data, const std::shared_ptr<Connection>& connection) override final
    {
        m_message_sender.send(handle(util::deserialize<Request>(std::move(data)), connection));
    }

    virtual Response handle(Request&& request, const std::shared_ptr<Connection>& connection) = 0;

private:
    entity::MessageSender& m_message_sender;
};

} // namespace rps::protocol::interface
