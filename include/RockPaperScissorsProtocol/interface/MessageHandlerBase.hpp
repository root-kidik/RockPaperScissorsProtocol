#pragma once

#include <memory>
#include <string>

#include <RockPaperScissorsProtocol/interface/Connection.hpp>

namespace rps::protocol::interface
{

class MessageHandlerBase
{
public:
    virtual ~MessageHandlerBase() = default;

    virtual void execute(std::string&& data, const std::shared_ptr<Connection>& connection) = 0;
};

} // namespace rps::protocol::interface
