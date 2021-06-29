#ifndef _H_CHRONOMETER_
#define _H_CHRONOMETER_

#include <chrono>

namespace Dissoni
{
  class Chronometer {
  public:
    using clock = std::chrono::steady_clock;
    using nanoseconds = std::chrono::nanoseconds;
    using microseconds = std::chrono::microseconds;
    using milliseconds = std::chrono::milliseconds;
    using seconds = std::chrono::seconds;

    Chronometer() : origin(clock::now()) {};

    Chronometer(const Chronometer &) = delete;
    Chronometer(Chronometer &&) = delete;
    Chronometer &operator=(const Chronometer &) = delete;
    Chronometer &operator=(Chronometer &&) = delete;

    void reset() noexcept {
      this->origin = clock::now();
    };

    template <typename T>
    uint64_t get() const {
      return std::chrono::duration_cast<T>(clock::now() - this->origin).count();
    }

  private:
    clock::time_point origin;
  };
}

#endif // _H_CHRONOMETER