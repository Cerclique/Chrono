#include <chrono>

class Chronometer {
public:
  typedef std::chrono::steady_clock clock;
  typedef std::chrono::nanoseconds nanoseconds;
  typedef std::chrono::microseconds microseconds;
  typedef std::chrono::milliseconds milliseconds;
  typedef std::chrono::seconds seconds;

  Chronometer() : origin(clock::now()) {};

  Chronometer(const Chronometer&) = delete;
  Chronometer(Chronometer&&) = delete;
  Chronometer& operator=(const Chronometer&) = delete;
  Chronometer& operator=(Chronometer&&) = delete;

  void reset() noexcept {
    this->origin = clock::now();
  };

  template<class T>
  uint64_t get() const {
    return std::chrono::duration_cast<T>(clock::now() - this->origin).count();
  }

private:
  clock::time_point origin;
};
