#include <iostream>
#include <thread>

#include "chronometer.hpp"

int main(int argc, char** argv) {
  (void)argc;
  (void)argv;

  Chronometer timer;

  std::this_thread::sleep_for(Chronometer::seconds(5));
  
  std::cout << timer.get<Chronometer::nanoseconds>() << " nanoseconds"<< std::endl;
  std::cout << timer.get<Chronometer::microseconds>() << " microseconds"<< std::endl;
  std::cout << timer.get<Chronometer::milliseconds>() << " milliseconds"<< std::endl;
  std::cout << timer.get<Chronometer::seconds>() << " seconds"<< std::endl;

  return 0;
}
