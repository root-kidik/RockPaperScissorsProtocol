#pragma once

#include <memory>
#include <string>

#include <RockPaperScissorsProtocol/interface/MessageHandlerBase.hpp>
#include <RockPaperScissorsProtocol/util/Util.hpp>

namespace rps::protocol::interface
{

template <typename ResponseType>
class ResponseHandler : public MessageHandlerBase
{
public:
    using Response = ResponseType;

    void execute(std::string&& data, const std::shared_ptr<Connection>& connection) override final
    {
        handle(util::deserialize<Response>(std::move(data)));
    }

    virtual void handle(Response&& response) = 0;
};

} // namespace rps::protocol::interface
