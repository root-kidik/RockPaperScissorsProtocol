#pragma once

#include <cassert>
#include <sstream>
#include <string>
#include <tuple>

#include <RockPaperScissorsProtocol/entity/MessageRepresentation.hpp>

namespace rps::protocol::util
{

/*
Boost.pfr - I miss you
*/

template <typename Enum, typename = std::enable_if_t<std::is_enum_v<Enum>>>
std::ostream& operator<<(std::ostream& os, Enum& e)
{
    assert(static_cast<std::underlying_type_t<Enum>>(e) > static_cast<std::underlying_type_t<Enum>>(Enum::Begin) &&
           static_cast<std::underlying_type_t<Enum>>(e) < static_cast<std::underlying_type_t<Enum>>(Enum::End));

    return os << static_cast<std::underlying_type_t<Enum>>(e);
}

template <typename Enum, typename = std::enable_if_t<std::is_enum_v<Enum>>>
std::istream& operator>>(std::istream& is, Enum& e)
{
    std::underlying_type_t<Enum> value;
    is >> value;

    assert(value > static_cast<std::underlying_type_t<Enum>>(Enum::Begin) &&
           value < static_cast<std::underlying_type_t<Enum>>(Enum::End));

    e = static_cast<Enum>(value);
    return is;
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
    ((oss << std::get<Is>(t) << (Is + 1 < sizeof...(Is) ? " " : "")), ...);
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
    ((iss >> std::get<Is>(t)), ...);
}

template <typename T>
T deserialize(std::string&& str)
{
    T    obj;
    auto tuple = obj.as_tuple();
    deserialize_tuple(std::move(tuple), std::move(str), std::make_index_sequence<std::tuple_size<decltype(tuple)>::value>{});
    return obj;
}

template <typename Message>
std::string serialize_message(Message&& command)
{
    return std::to_string(static_cast<entity::MessageRepresentation>(Message::kType)) + ' ' + serialize(std::move(command));
}

template <typename Enum, typename = std::enable_if_t<std::is_enum_v<Enum>>>
bool is_enum_has_valid_value(Enum e)
{
    return static_cast<std::underlying_type_t<Enum>>(e) > static_cast<std::underlying_type_t<Enum>>(Enum::Begin) &&
           static_cast<std::underlying_type_t<Enum>>(e) < static_cast<std::underlying_type_t<Enum>>(Enum::End);
}

template <typename Enum, typename = std::enable_if_t<std::is_enum_v<Enum>>>
bool is_valid_value_for_enum(std::underlying_type_t<Enum> value)
{
    return is_enum_has_valid_value(static_cast<Enum>(value));
}

} // namespace rps::protocol::util
