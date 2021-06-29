#include <iostream>
#include <thread>
#include <fmt/format.h>

#include "chronometer.hpp"

int main(int argc, char** argv) {
  (void)argc;
  (void)argv;

  Dissoni::Chronometer timer;

  for (const auto& duration : {1, 2 ,3, 4, 5}) {
    std::cout << fmt::format("Waiting for {0} seconds ...", duration) << std::endl;

    timer.reset();
    std::this_thread::sleep_for(Dissoni::Chronometer::seconds(duration));
  
    std::cout << timer.get<Dissoni::Chronometer::nanoseconds>() << " nanoseconds"<< std::endl;
    std::cout << timer.get<Dissoni::Chronometer::microseconds>() << " microseconds"<< std::endl;
    std::cout << timer.get<Dissoni::Chronometer::milliseconds>() << " milliseconds"<< std::endl;
    std::cout << timer.get<Dissoni::Chronometer::seconds>() << " seconds"<< std::endl;
    std::cout << std::endl;
  }

  return EXIT_SUCCESS;
}
