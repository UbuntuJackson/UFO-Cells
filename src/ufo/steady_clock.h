#ifndef STEADYCLOCK_HPP
#define STEADYCLOCK_HPP

#include <chrono>
#include <sstream>
#include <thread>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <utility>
#include <tuple>
#include <iostream>

//---------------------------------------------------------------------//
// This file is a wonderful contribution by Allie (2024). You can find //
// her as bruhmoent on github.                                         //
//---------------------------------------------------------------------//

enum TimeUnit
{
    HOURS,
    MINUTES,
    SECONDS,
    MILLISECONDS,
    MICROSECONDS,
    NANOSECONDS
};

class SteadyClock
{
public:
    void Start()
    {
        start = std::chrono::steady_clock::now();
    }

    template <typename... Args>
    std::string FormatDuration(const Args&... units)
    {
        static_assert((std::is_same<Args, TimeUnit>::value && ...), "All arguments must be of TimeUnit type");

        if (HasDuplicates(units...)) {
            throw std::invalid_argument("Duplicate time units are not allowed");
        }

        auto sorted_units = SortUnits(units...);

        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::chrono::steady_clock::duration duration = end - start;

        std::cout << "original time: " << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << std::endl;

        std::ostringstream result;
        ProcessUnits(duration, result, sorted_units);

        return result.str();
    }
    
    //for testing purposes.
    template <typename... Args>
    std::string FormatDurationTest(int _duration, const Args&... units)
    {
        static_assert((std::is_same<Args, TimeUnit>::value && ...), "All arguments must be of TimeUnit type");

        if (HasDuplicates(units...)) {
            throw std::invalid_argument("Duplicate time units are not allowed");
        }

        auto sorted_units = SortUnits(units...);

        std::chrono::steady_clock::duration duration = std::chrono::milliseconds(_duration);

        std::cout << "original time: " << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << std::endl;

        std::ostringstream result;
        ProcessUnits(duration, result, sorted_units);

        return result.str();
    }

private:
    std::chrono::steady_clock::time_point start;

    template <typename... Args>
    auto SortUnits(const Args&... units)
    {
        constexpr std::size_t size = sizeof...(Args);
        TimeUnit unit_array[size] = { units... };
        std::size_t indices[size];

        for (std::size_t i = 0; i < size; ++i) {
            indices[i] = i;
        }

        std::sort(indices, indices + size, [&unit_array](std::size_t i, std::size_t j) {
            return unit_array[i] < unit_array[j];
            });

        return SortUnitsHelper(unit_array, indices, std::index_sequence_for<Args...>());
    }

    template <std::size_t... Indices, std::size_t Size>
    auto SortUnitsHelper(const TimeUnit(&unit_array)[Size], const std::size_t(&indices)[Size], std::index_sequence<Indices...>)
    {
        return std::make_tuple(unit_array[indices[Indices]]...);
    }

    template <typename... Args>
    bool HasDuplicates(const Args&... units)
    {
        return ((std::unordered_set<TimeUnit>{ units... }.size()) != sizeof...(units));
    }

    template <typename... Args>
    void ProcessUnits(std::chrono::steady_clock::duration& _duration, std::ostringstream& result, const std::tuple<Args...>& units)
    {
        ProcessUnitsHelper(_duration, result, units, std::index_sequence_for<Args...>());
    }

    template <typename... Args, std::size_t... Indices>
    void ProcessUnitsHelper(std::chrono::steady_clock::duration& _duration, std::ostringstream& result, const std::tuple<Args...>& units, std::index_sequence<Indices...>)
    {
        (ProcessUnit(_duration, result, std::get<Indices>(units)), ...);
    }

    template <typename Arg>
    void ProcessUnit(std::chrono::steady_clock::duration& _duration, std::ostringstream& result, Arg unit)
    {
        const auto [convertedValue, remainder] = Convert(_duration, unit);
        result << convertedValue << ' ' << ToString(unit) << ' ';

        _duration = remainder;
    }

    std::pair<long long, std::chrono::steady_clock::duration> Convert(const std::chrono::steady_clock::duration& duration, TimeUnit unit)
    {
        long long value = 0;

        switch (unit)
        {
        case HOURS:
            value = std::chrono::duration_cast<std::chrono::hours>(duration).count();
            return {value, duration - std::chrono::hours(value)};
        case MINUTES:
            value = std::chrono::duration_cast<std::chrono::minutes>(duration).count();
            return {value, duration - std::chrono::minutes(value)};
    
        case SECONDS:
            value = std::chrono::duration_cast<std::chrono::seconds>(duration).count();
            return { value, duration - std::chrono::seconds(value) };
        case MILLISECONDS:
            value = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
            return { value, duration - std::chrono::milliseconds(value) };
        case MICROSECONDS:
            value = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
            return { value, duration - std::chrono::microseconds(value) };
        case NANOSECONDS:
            value = duration.count();
            return { value, std::chrono::steady_clock::duration(0) };
        default:
            return { -1, std::chrono::steady_clock::duration(0) };
        }
    }

    const char* ToString(TimeUnit unit)
    {
        switch (unit)
        {
        case HOURS:
            return "hours";
        case MINUTES:
            return "minutes";
        case SECONDS:
            return "seconds";
        case MILLISECONDS:
            return "milliseconds";
        case MICROSECONDS:
            return "microseconds";
        case NANOSECONDS:
            return "nanoseconds";
        default:
            return "invalid";
        }
    }
};

#endif // STEADYCLOCK_HPP
