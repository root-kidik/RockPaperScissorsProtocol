#pragma once

#include <string>

namespace rps::protocol::interface
{

class Connection
{
public:
    virtual ~Connection() = default;

    virtual bool is_connected() const          = 0;
    virtual void send(const std::string& data) = 0;
};

} // namespace rps::protocol::interface
