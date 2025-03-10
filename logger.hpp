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
    auto log_list(const T& input)
    {
        for (auto it = std::begin(input); it < std::end(input); ++it)
        {
            std::cout << *it << '\t';
        }

        std::cout << '\n';
    }

    template<size_t N = 0, typename T>
    auto log_c_list(const T (&input)[N])
    {
        for (size_t i = 0; i < N; ++i)
        {
            std::cout << input[i] << '\t';
        }

        std::cout << '\n';
    }

    template<typename T>
    auto log_reversed_list(const T& input)
    {
        for (auto it = std::end(input) - 1; it >= std::begin(input); --it)
        {
            std::cout << *it << '\t';
        }

        std::cout << '\n';
    }


    template<size_t N = 0, typename T>
    auto log_reversed_c_list(const T (&input)[N])
    {
        for (int32_t i = N - 1; i >= 0; --i)
        {
            std::cout << input[i] << '\t';
        }

        std::cout << '\n';
    }
}
