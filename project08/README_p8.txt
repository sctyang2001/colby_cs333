Scottie Yang Miaoyi
CS333 - Project 8
May 9, 2021
------------------------------------------------------------
TO VISIT Scottie's CS333 Project Base Camp https://wiki.colby.edu/x/cApHIQ
------------------------------------------------------------

<<< DIRECTORY LAYOUT >>>
project08/
|__/C/
|  |__/benford
|  |__|__/benford_parallel.c
|  |__|__/benford_sequential.c
|  |__|__/longer_nonBenford.bin
|  |__|__/longer.bin
|  |__|__/medium.bin
|  |__|__/my_timing.c
|  |__|__/my_timing.h
|  |__|__/super_short.bin
|  |__/imageMul
|  |__|__/colorize
|  |__|__/IMG_4203
|  |__|__/my_timing.c
|  |__|__/my_timing.h
|  |__|__/ppmIO.c
|  |__|__/ppmIO.h
|__/Other/
|  |__/IMG_4203.ppm
|  |__/ppmIO.py

<<< RUNNING SYSTEM >>>
OS - MacOS Monterey 12.1（21C52)
Compiler - XCode.app/c++/4.2.1, Apple clang version 13.0.0 (clang-1300.0.29.30)

<< Part I >>
NOTE: For all operations please locate into ./project08/C/ using the "cd" command;
< Task 01>
ROOT: project08/
|__/C/
|  |__/benford
|  |__|__/..
GOAL:  The program confirms that data from a (relatively wide) log-normal distribution follows Benford's Law.
TO COMPILE $ gcc -o par my_timing.c benford_parallel.c -lm -lpthread
TO RUN (with command line argument) $ ./par
OUTPUT (integrated):
part a:
  trial 1: 0.001399 seconds
  trial 2: 0.001572 seconds
  trial 3: 0.001709 seconds
  trial 4: 0.001562 seconds
  trial 5: 0.001344 seconds 
  Avearge (middle 3): 0.001513 seconds

  part b:
  trial 1: 0.001288 seconds
  trial 2: 0.001531 seconds
  trial 3: 0.001470 seconds
  trial 4: 0.002239 seconds
  trial 5: 0.001372 seconds
  Avearge (middle 3): 0.001457 seconds

  part c:
  trial 1: 0.001322 seconds
  trial 2: 0.001632 seconds
  trial 3: 0.001789 seconds
  trial 4: 0.001494 seconds
  trial 5: 0.001572 seconds
  Avearge (middle 3): 0.001566 seconds

  part d:
  trial 1: 0.001703 seconds
  trial 2: 0.001609 seconds
  trial 3: 0.001490 seconds
  trial 4: 0.001597 seconds
  trial 5: 0.001647 seconds
  Avearge (middle 3): 0.001616 seconds

  part e:
  trial 1: 0.001267 seconds
  trial 2: 0.001350 seconds
  trial 3: 0.001401 seconds
  trial 4: 0.001182 seconds
  trial 5: 0.001228 seconds
  Avearge (middle 3): 0.001281 seconds

  part f:
  trial 1: 0.001501 seconds
  trial 2: 0.001199 seconds
  trial 3: 0.001327 seconds
  trial 4: 0.001318 seconds
  trial 5: 0.001369 seconds
  Avearge (middle 3): 0.001338 seconds

ANSWER to questions:
- What conclusions can you draw?
  The last two conditions where we didn't use mutex ran the faster compared
  to other 4 conditions. This makes sense as for the other 4 conditions,
  mutex have to be locked and unlocked whenever it is overwritten and that takes time.
  Part c and d took longer than other conditions because mutex had to be locked and unlocked
  twice (when updating local and global count) for every count. 
- What can you say about the roles of mutex locks for this problem?
  Mutex locks so that other thread cannot access the same resources at the same time.
  For this problem, mutex locks the counts array before its overwritten and unlocks after
  its overwritten so that no two threads can access to it at the same time.
- In what conditions would you want to use a mutex?
  When you have a resource that don't want two different threads to access at the same 
  time.

< Task 02>
ROOT: project08/
|__/C/
|  |__/imageMul (EXTENSION)
|  |__|__/..
NOTE: This program contains two command-line arguments input to run. (EXTENSION: created three different color filters.)
GOAL: The program reads an image and applies a pixel-wise operator to it. Use parallelism to reduce the computation time.
TO COMPILE $ gcc -o colorize -I. colorize.c ppmIO.c -lm my_timing.c
TO RUN (with command line argument) $ ./colorize <image filename> <filter(bw/bold/neg)> (example: $ ./colorize IMG_4203.ppm bw)
OUTPUT (integrated):
  Serial:
  trial 1: 0.047768 seconds
  trial 2: 0.053045 seconds
  trial 3: 0.053951 seconds
  Average: 0.051588 seconds

  1 thread:
  trial 1: 0.046420 seconds
  trial 2: 0.044510 seconds
  trial 3: 0.044595 seconds
  Average: 0.045175 seconds

  2 threads:
  trial 1: 0.029545 seconds
  trial 2: 0.033429 seconds
  trial 3: 0.030901 seconds
  Average: 0.031291 seconds

  4 threads:
  trial 1: 0.027940 seconds
  trial 2: 0.029141 seconds
  trial 3: 0.027864 seconds
  Average: 0.028315 seconds

ANSWER to questions:
- Compare computation times for the serial and parallel versions.
  According to my results, serial version took more time than parallel versions.
- Compare how computation time depends upon the number of threads.
  As seen from the results above, as the number of threads increase, the computation
  time decreases but the time does not decrease at the same ratio as the increase
  in thread. 

<< Part II >>
NOTE: For this part regarding the details shown below, please refer to websites below for tutorials.
Part II (JavaScript) TO VISIT https://wiki.colby.edu/x/74ihIQ
NOTE: For all operations please locate into ./project08/Other using the "cd" command.
ROOT: project08/
|__/Other
|  |__/IMG_4203.ppm
|  |__/ppmIO.py
GOAL: This program is a simple ppmIO file for filter.
TO TEST (with command line argument) $ python3 ppmIO.py IMG_4203.ppm
OUTPUT (integrated):
  1 thread:
  trial 1: 0.016811 seconds
  trial 2: 0.018459 seconds
  trial 3: 0.019802 seconds
  trial 4: 0.017674 seconds
  trial 5: 0.018822 seconds
  Average: 0.018739 seconds

  2 thread:
  trial 1: 0.018569 seconds
  trial 2: 0.018973 seconds
  trial 3: 0.018470 seconds
  trial 4: 0.019028 seconds
  trial 5: 0.017697 seconds
  Average: 0.017980 seconds

  4 threads:
  trial 1: 0.016092 seconds
  trial 2: 0.016093 seconds
  trial 3: 0.016598 seconds
  trial 4: 0.016318 seconds
  trial 5: 0.015421 seconds
  Average: 0.016010 seconds

  8 threads:
  trial 1: 0.016716 seconds
  trial 2: 0.016369 seconds
  trial 3: 0.015486 seconds
  trial 4: 0.015566 seconds
  trial 5: 0.016248 seconds
  Average: 0.016004 seconds

ANSWER to questions:
- Compare how computation time depends upon the number of threads.
  As seen from the results above, as the number of threads increase, the computation
  time decreases but the time does not decrease at the same ratio as the increase
  in thread. 

NOTE: For this part regarding the details above-shown, please refer to websites below for tutorials.
Part II (JavaScript) TO VISIT https://wiki.colby.edu/x/74ihIQ
TO VISIT Scottie's CS333 Project Base Camp https://wiki.colby.edu/x/cApHIQ