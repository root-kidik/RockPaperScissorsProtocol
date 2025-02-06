#pragma once

#include <sstream>
#include <string>
#include <tuple>

#include <RockPaperScissorsProtocol/entity/CommandRepresentation.hpp>

namespace rps::protocol::util
{

/*
Boost.pfr - I miss you
*/

template <typename Enum, typename = std::enable_if_t<std::is_enum_v<Enum>>>
std::ostream& operator<<(std::ostream& os, Enum e)
{
    return os << static_cast<std::underlying_type_t<Enum>>(e);
}

template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const std::array<T, N>& arr)
{
    for (std::size_t i = 0; i < N; ++i)
    {
        os << arr[i];
        if (i < N - 1)
            os << ' ';
    }

    return os;
}

template <typename T, std::size_t N>
std::istream& operator>>(std::istream& is, std::array<T, N>& arr)
{
    for (std::size_t i = 0; i < N; ++i)
        is >> arr[i];

    return is;
}

template <typename Tuple, std::size_t... Is>
std::string serialize_tuple(Tuple&& t, std::index_sequence<Is...>)
{
    std::ostringstream oss;
    ((oss << std::get<Is>(std::move(t)) << (Is + 1 < sizeof...(Is) ? " " : "")), ...);
    return oss.str();
}

template <typename T>
std::string serialize(T&& obj)
{
    auto tuple = obj.as_tuple();
    return serialize_tuple(std::move(tuple), std::make_index_sequence<std::tuple_size<decltype(tuple)>::value>{});
}

template <typename Tuple, std::size_t... Is>
void deserialize_tuple(Tuple&& t, std::string&& str, std::index_sequence<Is...>)
{
    std::istringstream iss{std::move(str)};
    ((iss >> std::get<Is>(std::move(t))), ...);
}

template <typename T>
T deserialize(std::string&& str)
{
    T    obj;
    auto tuple = obj.as_tuple();
    deserialize_tuple(std::move(tuple), std::move(str), std::make_index_sequence<std::tuple_size<decltype(tuple)>::value>{});
    return obj;
}

template <typename Request>
std::string serialize_request(Request&& request)
{
    return std::to_string(static_cast<entity::CommandRepresentation>(Request::kType)) + ' ' + serialize(std::move(request));
}

} // namespace rps::protocol::util
