#ifndef _RUNTIME_MEASUREMENT_H_
#define _RUNTIME_MEASUREMENT_H_

#include <stdint.h>
#include <sys/times.h>
#include <utility>
#include <unistd.h>
#include <functional>

class RuntimeMeasurement
{
    struct tms                              mStartTimes;
    struct tms                              mCurrentTimes;
    std::function<void (int64_t, int64_t)>  mResultCallback;
public:
    struct Result
    {
        int64_t user_time_clktck;
        int64_t system_time_clktck;
        int64_t clocks_per_sec;

        double userTimeToSec() const { return (user_time_clktck / static_cast<double>(clocks_per_sec)); }
        double systemTimeToSec() const { return (system_time_clktck / static_cast<double>(clocks_per_sec)); }
    };

    static int64_t CLOCK_TICKS_PER_SEC() { return sysconf(_SC_CLK_TCK); }

    Result measure()
    {
        times(&mCurrentTimes);
        return {  (mCurrentTimes.tms_utime - mStartTimes.tms_utime)
                , (mCurrentTimes.tms_stime - mStartTimes.tms_stime)
                , sysconf(_SC_CLK_TCK) };
    }
    
    RuntimeMeasurement(const std::function<void (int64_t, int64_t)>& result_callback = nullptr) : mResultCallback(result_callback)
    {
        times(&mStartTimes);
    }
    
    ~RuntimeMeasurement()
    {
        if( mResultCallback )
        {
            auto measurement = measure();
            mResultCallback(measurement.user_time_clktck, measurement.system_time_clktck);
        }
    }
};

#endif
