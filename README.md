Philosophers Project

Overview

This project is an implementation of the "Dining Philosophers" problem, a classic problem in computer science and concurrent programming. The problem describes a scenario where n philosophers are seated around a circular table with n chopsticks in the center, and each philosopher has to eat from a bowl of rice. The problem is to ensure that no philosopher is starving and that no deadlocks or livelocks occur.

Project Requirements

The program should simulate the behavior of n philosophers and chopsticks.
The philosophers should alternate between eating and thinking.
The chopsticks should be shared among the philosophers, and no philosopher should be able to grab both chopsticks at the same time.
The program should handle deadlocks and livelocks properly.

Technical Requirements
The program should be written in the C programming language.
The program should use the pthread library to implement threads.
The program should use the semaphore data structure to synchronize the philosophers and chopsticks.

Compilation
To compile the program, run the following command in the terminal:
```bash
make
```
Execution
To run the program, execute the following command in the terminal:
```bash
./philosophers NUM_PHILOSOPHERS TIME_TO_DIE TIME_TO_EAT TIME_TO_SLEEP NUM_TIMES_EACH_PHILOSOPHER_MUST_EAT
```
Where:

NUM_PHILOSOPHERS is the number of philosophers.
TIME_TO_DIE is the time in seconds after which a philosopher will stop eating and thinking.
TIME_TO_EAT is the maximum time in seconds that a philosopher will spend eating.
TIME_TO_SLEEP is the maximum time in seconds that a philosopher will spend thinking.
NUM_TIMES_EACH_PHILOSOPHER_MUST_EAT is the number of times each philosopher must eat before stopping.

Cleaning
To remove the compiled files, run the following command in the terminal:
```bash
make clean
```
Author

Brahim Maaqoul
