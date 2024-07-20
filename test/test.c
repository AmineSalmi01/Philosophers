#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

// void *read_data() {
//     printf("Data reading\n");

//     sleep(1);
//     printf("data read complete.\n");
//     return (NULL);
// }

// void *processData() {
//     printf("process data\n");

//     sleep(1);
//     printf("data process complete.\n");
//     return (NULL);
// }

// void* writeData(void* arg) {
//     printf("Writing data...\n");
//     // Simulate writing data
//     sleep(1);
//     printf("Data write complete.\n");
//     return NULL;
// }

// int main()
// {
//     pthread_t t1, t2, t3;

//     pthread_create(&t1, NULL, &read_data, NULL);
//     pthread_create(&t2, NULL, &processData, NULL);
//     pthread_create(&t3, NULL, &writeData, NULL);
//     pthread_join(t1, NULL);
//     pthread_join(t2, NULL);
//     pthread_join(t3, NULL);
//     return (0);
// }

// void *rout(void *arg)
// {
//     int val = *(int *)arg;
//     printf("the rescive arg is -> %d\n", val);
//     return NULL;
// }

// int main()
// {
//     pthread_t t;
//     int arg = 452;
//     pthread_create(&t, NULL, &rout, &arg);
//     pthread_join(t, NULL);
//     return 0;
// }

// void *func_test(void *arg)
// {
//     int *res = malloc(sizeof(int));
//     *res = 42;
//     pthread_exit(res);
// }

// int main()
// {
//     pthread_t thread;
//     int *thread_res;

//     pthread_create(&thread, NULL, func_test, NULL);
//     pthread_join(thread, (void **)&thread_res);
//     printf("Thread result: %d\n", *thread_res);
// }

static int glob = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_function(void *arg)
{
    int loops = *((int *)arg);
    int loc;

    for (int i = 0; i < loops; i++)
    {
        pthread_mutex_lock(&mutex);
        loc = glob;
        loc++;
        glob = loc;
        pthread_mutex_unlock(&mutex);
    }
    return (NULL);
}

void *thread_read(void *arg)
{
    int loops = *((int *)arg);

    for (int i = 0; i < loops; i++)
    {
        pthread_mutex_lock(&mutex);
        printf("%d\n", glob);
        pthread_mutex_unlock(&mutex);
    }
    return (NULL);
}

int main(int ac, char **av)
{
    pthread_t t1, t2;
    int loops = (ac > 1) ? atoi(av[1]) : 10000;
    pthread_create(&t1, NULL, thread_function, &loops);
    pthread_create(&t2, NULL, thread_read, &loops);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}