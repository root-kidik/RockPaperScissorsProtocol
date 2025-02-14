#pragma once

#include <memory>
#include <string>
#include <optional>

#include <RockPaperScissorsProtocol/interface/Connection.hpp>

namespace rps::protocol
{
namespace interface
{
class RequestHandler;
}

namespace entity
{
class MessageExecutor;
}
}

namespace rps::protocol::interface
{

class MessageHandlerBase
{
public:
    virtual ~MessageHandlerBase() = default;

    virtual void execute(std::string&& data, const std::shared_ptr<Connection>& connection) = 0;

private:
    // Internal mechanism (Skip passing sender inside ctor)
    friend entity::MessageExecutor; 
    friend interface::RequestHandler;
    std::optional<entity::MessageExecutor&> m_message_sender;
};

} // namespace rps::protocol::interface
