#pragma once

#include <iostream>
#include <iterator>

namespace logger
{
    template <typename... Args>
    auto log(const Args... args) noexcept -> void
    {
        ((std::cout << args << '\t'), ...) << '\n';
    }

    template<typename T>
    auto log_list(const T& input) -> void
    {
        for (const auto el : input)
        {
            std::cout << el << '\t';
        }

        std::cout << '\n';
    }

    template<size_t N = 0, typename T>
    auto log_c_list(const T (&input)[N]) -> void
    {
        for (size_t i = 0; i < N; ++i)
        {
            std::cout << input[i] << '\t';
        }

        std::cout << '\n';
    }

    template<typename T>
    auto log_reversed_list(const T& input) -> void
    {
        for (auto it = std::end(input) - 1; it >= std::begin(input); --it)
        {
            std::cout << *it << '\t';
        }

        std::cout << '\n';
    }


    template<size_t N = 0, typename T>
    auto log_reversed_c_list(const T (&input)[N]) -> void
    {
        for (int32_t i = N - 1; i >= 0; --i)
        {
            std::cout << input[i] << '\t';
        }

        std::cout << '\n';
    }

    template<typename Pair>
    auto log_pair(const Pair& pair) -> void
    {
        std::cout << pair.first << '\t' << pair.second << '\n';
    }

    template<typename Map>
    auto log_map(const Map& map) -> void
    {
        for (const auto pair : map)
        {
            std::cout << pair.first << '\t' << pair.second << '\n';
        }
    }
}
