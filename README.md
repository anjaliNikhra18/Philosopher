Project: Philosophers (42 Wolfsburg)
Multithreaded Dining Philosophers Solution in C

Implemented a high-performance solution to the classic concurrency problem using strict thread synchronization, preventing deadlocks while optimizing resource usage.

🔹 Key Features:

Developed 3 distinct approaches:

Thread/mutex version (mandatory)

Process/shared memory version (bonus)

Hybrid solution with performance benchmarking

Implemented deadlock prevention using:

Timed waits with usleep

Priority-based fork pickup algorithms

Resource hierarchy solutions

Added real-time monitoring of philosopher states

🔹 Technical Achievements:

Zero data races (verified via helgrind/drd)

<5% CPU overhead even with 200+ philosophers

Configurable via startup parameters (eat/sleep times, philosopher count)

🔹 Skills Demonstrated:

Advanced multithreading/multiprocessing

Race condition prevention

System resource optimization

Algorithmic thinking for edge cases
