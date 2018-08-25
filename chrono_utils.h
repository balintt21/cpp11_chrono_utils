#ifndef __STD_CHRONO_UTILS_H__
#define __STD_CHRONO_UTILS_H__

#include <stdint.h>
#include <chrono>

namespace chrono_utils
{
    /**
     * Returns the monotonic time in milliseconds
     */
    inline int64_t monotonic_time_ms()
    {
        return std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()).time_since_epoch().count();
    }
    /**
     * Returns the system time in milliseconds
     */
    inline int64_t system_time_ms()
    {
        return std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()).time_since_epoch().count();
    }
    /**
     * Returns the system time in windows time format
     */
    inline int64_t windows_time_ms()
    {
        static constexpr int64_t WIN_UNIX_DELTA = 0xA9730B66800LL;
        return (system_time_ms() + WIN_UNIX_DELTA);
    }
    /**
     * Returns the system time in mac time format
     */
    inline int64_t mac_time_ms()
    {
        static constexpr int64_t MAC_UNIX_DELTA = 0x1E4F3397400LL;
        return (system_time_ms() + MAC_UNIX_DELTA);
    }

    /**
     * Returns a time point for the current time. See timediff_ms, timediff_s
     * @return A time point is returned
     */
    inline std::chrono::time_point<std::chrono::steady_clock> timediff_start()
    {
        return std::chrono::steady_clock::now();
    }
    /**
     * Returns the difference between the current time point and the given in milliseconds
     * @param start - Time point returned by a previous call to timediff_start()
     * @return Difference between the current time and given @p start in milliseconds
     */
    inline int64_t timediff_ms(const std::chrono::time_point<std::chrono::steady_clock>& start)
    {
        return std::chrono::duration_cast<std::chrono::milliseconds,int64_t> (std::chrono::steady_clock::now() - start).count();
    }
    /**
     * Returns the difference between the current time point and the given in seconds as double
     * @param start - Time point returned by a previous call to timediff_start()
     * @return Difference between the current time and given @p start as a double in seconds
     */
    inline double timediff_s(const std::chrono::time_point<std::chrono::steady_clock>& start)
    {
        return std::chrono::duration<double>(std::chrono::steady_clock::now() - start).count();
    }
}

#endif
