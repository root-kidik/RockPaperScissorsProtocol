#pragma once

#include <memory>
#include <string>

#include <RockPaperScissorsProtocol/interface/Connection.hpp>

namespace rps::protocol::interface
{

class CommandHandler
{
public:
    virtual ~CommandHandler() = default;

    virtual void execute(const std::string& data, const std::shared_ptr<Connection>& connection) = 0;
};

} // namespace rps::protocol::interface
