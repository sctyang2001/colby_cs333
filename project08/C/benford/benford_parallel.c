/**
* benford_parallel.c: The program confirms that data from a 
* (relatively wide) log-normal distribution follows Benford's Law.
*
* Scottie YANG Miaoyi
* May 9, 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <math.h>
#include "my_timing.h"
#include <pthread.h>

// Global variables
int global_counts[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// create a global variable that is an array of ints with 10*NUMTHREADS entries
#define NUMTHREADS 8
// int global_counts[10][NUMTHREADS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
// int global_counts[80] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int N = 0;
double *data;
pthread_mutex_t lock;
// pthread_mutex_t lock[10];

// thread information struct
typedef struct
{
    int id;
    int start;
    int end;
} threadData;

// Load data from a binary file that has an int and then
// a sequence of doubles. The value of the int should indicate
// the number of doubles in the sequence.
// Load the data into global variables N and data.
int loadData(char *filename)
{
    FILE *fp;

    if (filename != NULL && strlen(filename))
        fp = fopen(filename, "r");
    else
        return -1;

    if (!fp)
        return -1;

    fread(&N, sizeof(int), 1, fp);
    data = (double *)malloc(sizeof(double) * N);
    fread(data, sizeof(double), N, fp);
    fclose(fp);
    // Uncomment this to verify the right data are being read in.
    // For super_short.bin, it should print out
    // data[0] = 97.137926
    // data[1] = 24.639612
    // data[2] = 55.692572
    //   int i;
    //   for (i = 0; i < N; i++) {
    //         printf( "data[%d] = %f\n", i, data[i] );
    //   }
    return 1; // success
}

// Return the leading Digit of n.
int leadingDigit(double n)
{
    // This is not a particularly efficient approach.
    if (fabs(n) == 1.0)
        return 1;
    else if (fabs(n) == 0.0)
        return 0;
    else if (fabs(n) < 1.0)
    {
        // multiply it by 10 until you get a number that is at least 1.
        // Then chop off the fractional part. All that remains is the first digit.
        double tmp = fabs(n);
        while (tmp < 1.0)
        {
            tmp *= 10.0;
        }
        return (int)floor(tmp);
    }
    else
    {
        // Divide it by 10 until you get a number smaller than 10.
        // That number will be the first digit of the original number.
        long long unsigned in = (long long unsigned)floor(fabs(n));
        while (in > 9)
        {
            in /= 10;
        }
        return in;
    }
} // end leadingDigit

// thread function to count frequencies of leading digits
// part a
// void *thread_function(void *thread_data)
// {
//     threadData *ti = (threadData *)thread_data;
//     for (int i = ti->start; i < ti->end; i++)
//     {
//         int ld = leadingDigit(data[i]);
//         pthread_mutex_lock(&lock);

//         global_counts[ld]++;
//         pthread_mutex_unlock(&lock);
//     }
//     pthread_exit(NULL);
// }

// part b
// void *thread_function(void *thread_data)
// {
//     threadData *ti = (threadData *)thread_data;
//     for (int i = ti->start; i < ti->end; i++)
//     {
//         int ld = leadingDigit(data[i]);
//         pthread_mutex_lock(&lock[ld]);

//         global_counts[ld]++;
//         pthread_mutex_unlock(&lock[ld]);
//     }
//     pthread_exit(NULL);
// }

// part c
// void *thread_function(void *thread_data)
// {
//     threadData *ti = (threadData *)thread_data;
//     int local_counts[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//     for (int i = ti->start; i < ti->end; i++)
//     {
//         int ld = leadingDigit(data[i]);
//         pthread_mutex_lock(&lock);

//         local_counts[ld]++;
//         pthread_mutex_unlock(&lock);
//     }
//     for (int i = 0; i < 10; i++)
//     {
//         pthread_mutex_lock(&lock);
//         global_counts[i] += local_counts[i];
//         pthread_mutex_unlock(&lock);
//     }
//     pthread_exit(NULL);
// }

// part d
// void *thread_function(void *thread_data)
// {
//     threadData *ti = (threadData *)thread_data;
//     int local_counts[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//     for (int i = ti->start; i < ti->end; i++)
//     {
//         int ld = leadingDigit(data[i]);
//         pthread_mutex_lock(&lock[ld]);

//         local_counts[ld]++;
//         pthread_mutex_unlock(&lock[ld]);
//     }
//     for (int i = 0; i < 10; i++)
//     {
//         pthread_mutex_lock(&lock[i]);
//         global_counts[i] += local_counts[i];
//         pthread_mutex_unlock(&lock[i]);
//     }
//     pthread_exit(NULL);
//  }

// part e
// void *thread_function(void *thread_data)
// {
//     threadData *ti = (threadData *)thread_data;
//     for (int i = ti->start; i < ti->end; i++)
//     {
//         int ld = leadingDigit(data[i]);
//         global_counts[ld][ti->id]++;
//     }
//     pthread_exit(NULL);
// }

// part f
// void *thread_function(void *thread_data)
// {
//     threadData *ti = (threadData *)thread_data;
//     for (int i = ti->start; i < ti->end; i++)
//     {
//         int ld = leadingDigit(data[i]);
//         global_counts[ld * 8 + ti->id]++;
//     }
//     pthread_exit(NULL);
// }

// Main function
int main(int argc, char *argv[])
{
    // timing variables
    double start_time, end_time;

    // Load data
    if (loadData(argv[1]) != 1)
    {
        printf("Error: Could not load data.\n");
        return -1;
    }

    // Initialize the lock
    // pthread_mutex_init(&lock, NULL);

    // Create the threads
    // pthread_t threads[8];
    // threadData thread_info[8];
    // int num_threads = 8;
    // int num_per_thread = N / num_threads;

    pthread_t threads[NUMTHREADS];
    threadData thread_info[NUMTHREADS];
    int num_threads = NUMTHREADS;
    int num_per_thread = N / num_threads;

    // start timing
    start_time = get_time_sec();

    for (int i = 0; i < num_threads; i++)
    {
        thread_info[i].id = i;
        thread_info[i].start = i * num_per_thread;
        thread_info[i].end = (i + 1) * num_per_thread;
        pthread_create(&threads[i], NULL, thread_function, &thread_info[i]);
    }

    // Wait for the threads to finish
    for (int i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // end timing
    end_time = get_time_sec();

    // Print the results
    printf("\n");
    // for (int i = 0; i < 10; i++)
    // {
    //     printf("There are %d %d's\n", global_counts[i], i);
    // }
    for (int i = 0; i < 10; i++)
    {
        int sum = 0;
        for (int j = 0; j < NUMTHREADS; j++)
        {
            // sum += global_counts[i * 8 + j];
            sum += global_counts[i][j];
        }
        printf("There are %d %d's\n", sum, i);
    }

    // Print the timing
    printf("\n");
    printf("Time: %f\n", end_time - start_time);

    // Clean up
    // pthread_mutex_destroy(&lock);
    free(data);
    return 0;
}