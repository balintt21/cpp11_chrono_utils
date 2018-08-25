# cpp11_chrono_utils
Utility wrapper functions of std::chrono's and std::this_thread's functionality
* Getter functions for monotonic time and platform specific system time
* Runtime measuring based on monotonic time
* Wrapper for thread_sleep_for, thread_sleep_until that are accepting int64_t as argument instead std::chrono

## Example

    #include <stdio.h>
    #include "chrono_utils.h"
    #include "thread_sleep.h"


    int main(int argc, char** argv)
    {
        puts("Test start");
        printf("System time: \t%ld ms\nWindows time: \t%ld ms\nMacintosh time: %ld ms\nMonotonic time: %ld ms\n\n"
            , chrono_utils::system_time_ms()
            , chrono_utils::windows_time_ms()
            , chrono_utils::mac_time_ms()
            , chrono_utils::monotonic_time_ms());

        auto t0 = chrono_utils::timediff_start();
        thread_utils::sleep_for(2560);
        printf("sleeped for %.4f sec\n", chrono_utils::timediff_s(t0));

        auto t1 = chrono_utils::timediff_start();
        int64_t now = chrono_utils::monotonic_time_ms();
        int64_t deadline = now + 1560;
        thread_utils::sleep_until(deadline);
        printf("sleeped from %ld until %ld, duration: %ld sec\n", now, deadline, chrono_utils::timediff_ms(t1));

        printf("total time spent: %.4f sec\n", chrono_utils::timediff_s(t0));
        puts("Done.");

        return 0;
    }
   
  

