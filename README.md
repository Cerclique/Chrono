# Chronometer

## Introduction

Single header file containing chronometer tool to help compute execution time in a program.

## Installation && Usage

- Clone the repository.
- Build using `make`.
- Run the executable `ChronoSample`.

The sample declare a `Chronometer` object, sleep for 5 seconds and print execution time in different time precision.

## API

### Constructor

Since no argument are needed, only the default constructor is available.

At creation, the origin time point is set to current time.

```c++
Chronometer timer;
```

### Reset the timer

Resetting timer set the origin time point to current time.

```c++
timer.reset();
```

### Get elapsed time

Different time unit are available :
- `Chronometer::nanoseconds`
- `Chronometer::microseconds`
- `Chronometer::milliseconds`
- `Chronometer::seconds`

Thus, to get time from last timer reset :

```c++
uint64_t elapsedMilliconds = timer.get<Chronometer::milliseconds>(); /**Get time in milliseconds **/
auto elapsedSeconds = timer.get<Chronometer::seconds>(); /** Get time in seconds **/
```
