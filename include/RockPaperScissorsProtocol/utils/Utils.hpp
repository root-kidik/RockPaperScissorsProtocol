#pragma once

#include <sstream>
#include <string>
#include <tuple>

namespace rps::protocol::utils
{

template <typename Tuple, std::size_t... Is>
std::string serialize_tuple(const Tuple& t, std::index_sequence<Is...>)
{
    std::ostringstream oss;
    ((oss << std::get<Is>(t) << (Is + 1 < sizeof...(Is) ? " " : "")), ...);
    return oss.str();
}

template <typename T>
std::string serialize(T& obj)
{
    auto tuple = obj.as_tuple();
    return serialize_tuple(tuple, std::make_index_sequence<std::tuple_size<decltype(tuple)>::value>{});
}

template <typename Tuple, std::size_t... Is>
void deserialize_tuple(Tuple& t, const std::string& str, std::index_sequence<Is...>)
{
    std::istringstream iss{str};
    ((iss >> std::get<Is>(t)), ...);
}

template <typename T>
T deserialize(const std::string& str)
{
    T    obj;
    auto tuple = obj.as_tuple();
    deserialize_tuple(tuple, str, std::make_index_sequence<std::tuple_size<decltype(tuple)>::value>{});
    return obj;
}

} // namespace rps::protocol::utils
