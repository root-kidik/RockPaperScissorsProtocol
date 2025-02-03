#pragma once

#include <type_traits>

namespace rps::protocol::entity
{

template <typename T, T Type, typename = std::enable_if_t<std::is_enum_v<T>>>
struct Command
{
    static constexpr T kType = Type;
};

} // namespace rps::protocol::entity
