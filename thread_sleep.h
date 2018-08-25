#ifndef __STD_THREAD_UTILS_SLEEP_H__
#define __STD_THREAD_UTILS_SLEEP_H__

#include <stdint.h>
#include <chrono>
#include <thread>

namespace thread_utils
{
    /*
     * Sleeps the current thread for the given amount of time in milliseconds
     * @param milliseconds
     */
    inline void sleep_for(int64_t milliseconds)
    {
        std::this_thread::sleep_for(milliseconds);
    }
    /*
     * Sleeps the current thread until the given monotonic time in milliseconds
     * @param timestamp_ms
     */
    inline void sleep_until(int64_t timestamp_ms)
    {
        int64_t now = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()).time_since_epoch().count();
        std::this_thread::sleep_for(timestamp_ms - now);
    }
}

#endif
