# Chronometer

## Introduction

Single header file containing chronometer tool to help compute execution time in a program.

## Installation && Usage

- Clone the repository.
- Build using `make`.
- Run the executable `ChronoSample`.

The sample declare a `Chronometer` object, sleep from 1 to 5 seconds and print execution time in different time precision for each run.

## API

### Constructor

Since no argument are needed, only the default constructor is available.

At creation, the origin time point is set to current time.

```c++
Dissoni::Chronometer timer;
```

### Reset the timer

Resetting timer set the origin time point to current time.

```c++
timer.reset();
```

### Get elapsed time

Different time unit are available :
- `Dissoni::Chronometer::nanoseconds`
- `Dissoni::Chronometer::microseconds`
- `Dissoni::Chronometer::milliseconds`
- `Dissoni::Chronometer::seconds`

Thus, to get time from last timer reset :

```c++
const uint64_t elapsedMilliseconds = timer.get<Dissoni::Chronometer::milliseconds>(); /**Get time in milliseconds **/
const auto elapsedSeconds = timer.get<Dissoni::Chronometer::seconds>(); /** Get time in seconds **/
```
