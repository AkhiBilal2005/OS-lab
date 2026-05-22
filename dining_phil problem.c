#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_PHIL 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

int state[NUM_PHIL];
int phil_ids[NUM_PHIL];

sem_t mutex;
sem_t S[NUM_PHIL];

void test(int i)
{
    if (state[i] == HUNGRY &&
        state[(i + 4) % NUM_PHIL] != EATING &&
        state[(i + 1) % NUM_PHIL] != EATING)
    {
        state[i] = EATING;

        sleep(1);

        printf("Phil %d takes forks %d and %d and starts eating\n",
               i + 1,
               (i + 4) % NUM_PHIL + 1,
               i + 1);

        sem_post(&S[i]);
    }
}

void take_fork(int i)
{
    sem_wait(&mutex);

    state[i] = HUNGRY;

    printf("Phil %d is hungry\n", i + 1);

    test(i);

    sem_post(&mutex);

    sem_wait(&S[i]);

    sleep(1);
}

void put_fork(int i)
{
    sem_wait(&mutex);

    state[i] = THINKING;

    printf("Phil %d puts down fork %d and %d and starts thinking\n",
           i + 1,
           (i + 4) % NUM_PHIL + 1,
           i + 1);

    test((i + 4) % NUM_PHIL);
    test((i + 1) % NUM_PHIL);

    sem_post(&mutex);
}

void *phil(void *num)
{
    int i = *(int *)num;

    while (1)
    {
        printf("Phil %d is thinking\n", i + 1);

        sleep(1);

        take_fork(i);

        sleep(2);

        put_fork(i);
    }

    return NULL;
}

int main()
{
    int i;

    pthread_t thread_id[NUM_PHIL];

    sem_init(&mutex, 0, 1);

    for (i = 0; i < NUM_PHIL; i++)
    {
        sem_init(&S[i], 0, 0);
        phil_ids[i] = i;
    }

    for (i = 0; i < NUM_PHIL; i++)
    {
        pthread_create(&thread_id[i], NULL, phil, &phil_ids[i]);

        printf("Phil %d is seated at the table\n", i + 1);
    }

    for (i = 0; i < NUM_PHIL; i++)
    {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}
