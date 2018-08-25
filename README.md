# cpp11_chrono_utils
Utility functions wrapping std::chrono and std::this_thread functionality
* Getter functions for monotonic time and platform specific system time
* Runtime measuring based on monotonic time
* Wrapper for thread_sleep_for, thread_sleep_until using in64_t as argument instead std::chrono
