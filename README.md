*This project has been created as part of the 42 curriculum by aluis.*

## Description

The **Philosophers** project is an introduction to concurrent programming and the challenges of synchronization.
It simulates the classic **Dining Philosophers problem**, originally formulated by Edsger Dijkstra.

The goal is to manage a set of philosophers sitting around a table, each alternating between **eating**, **sleeping**, and **thinking**.
To eat, a philosopher needs two forks (one on each side). The challenge is to avoid **deadlocks**, **data races**, and **starvation**, using threads and mutexes (or processes and semaphores for the "bonus" part).

This project teaches:
- Thread creation and management (`pthread`).
- Mutexes for protecting shared resources.
- Avoiding race conditions and deadlocks.
- Time management with `gettimeofday` or similar.

## Instructions

### Compilation
- The project is compiled with a `Makefile` that includes the rules: `make`, `make clean`, `make fclean`, `make re`.
- The mandatory part produces `philo` (using threads and mutexes).


Example:
```bash
cd philo
make
```

### Execution

The program takes the following arguments:

```text
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

number_of_philosophers: number of philosophers (and forks).

time_to_die (ms): if a philosopher doesn't start eating within this time after their last meal, they die.

time_to_eat (ms): time a philosopher takes to eat (holds two forks).

time_to_sleep (ms): time a philosopher spends sleeping after eating.

number_of_times_each_philosopher_must_eat (optional): if specified, simulation stops when all philosophers have eaten at least this many time

Example:

```bash
./philo 5 800 200 200
```

### Output format

Each state change is printed with a timestamp (in ms) and the philosopher's number:

```text
timestamp_in_ms X has taken a fork

timestamp_in_ms X is eating

timestamp_in_ms X is sleeping

timestamp_in_ms X is thinking

timestamp_in_ms X died
```

## Resources

### Classic references

```link
https://www.youtube.com/watch?v=mvZKu0DfFLQ&list=PLO4ds-J6a6ZwvKXvx4YUP2xbUgQ3r4b8M
```
```link
https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2
```
```link
https://www.youtube.com/watch?v=IKG1P4rgm54&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=2
```
```link
https://www.youtube.com/watch?v=xoXzp4B8aQk&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=5
```

## AI usage description

During this project, AI (ChatGPT/GitHub Copilot) was used for the following tasks:

```text
* Generating initial structure of the Makefile.

* Explaining the difference between usleep and precise timing with gettimeofday.

* Helping write this README.md following the 42 requirements.
```

No AI was used to generate the core logic of the simulation; all algorithmic decisions regarding deadlock avoidance (e.g., odd-even fork picking order) were made manually.

## Skalidraw showcase

```link
https://excalidraw.com/#json=H9kvHSQ2TGNgUeaIlhQ5I,Hlwjaf8ikbrzdadMpuXmIw
```
