# cpp11_chrono_utils
Utility wrapper functions of std::chrono's and std::this_thread's functionality
* Getter functions for monotonic time and platform specific system time
* Runtime measuring based on monotonic time
* Wrapper for thread_sleep_for, thread_sleep_until that are accepting int64_t as argument instead std::chrono
