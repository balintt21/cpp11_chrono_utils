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
        int64_t user_time_ns;
        int64_t system_time_ns;
    };
    
    Result measure()
    {
        times(&mCurrentTimes);
        return { (mCurrentTimes.tms_utime - mStartTimes.tms_utime), (mCurrentTimes.tms_stime - mStartTimes.tms_stime) };
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
            mResultCallback(measurement.user_time_ns, measurement.system_time_ns);
        }
    }
};

#endif
