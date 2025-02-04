#pragma once

#include <sstream>
#include <string>
#include <tuple>

namespace rps::protocol::utils
{

/*
Boost.pfr - I miss you
*/

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

} // namespace rps::protocol::utils
