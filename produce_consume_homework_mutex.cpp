#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <pthread.h>
#include <time.h>

pthread_mutex_t mutex;
int buffer[10] = {0};
int consume_list[10000] = {0};
int produce_pointer = 0;
int consume_pointer = 0;
int total_consume = 0;

void *producer(void *param)
{
    srand(time(NULL));
    while (1)
    {
        pthread_mutex_lock(&mutex);
        if (buffer[produce_pointer] == 0)
        {
            int now_produce = rand() % 100 + 1;
            buffer[produce_pointer] = now_produce;
            produce_pointer++;
            produce_pointer = produce_pointer % 10;
        }
        pthread_mutex_unlock(&mutex);
        Sleep(10);
    }
}

void *consumer(void *param)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);
        if (buffer[consume_pointer] != 0)
        {
            consume_list[total_consume] = buffer[consume_pointer];
            buffer[consume_pointer] = 0;
            total_consume++;
            consume_pointer++;
            consume_pointer = consume_pointer % 10;
        }
        pthread_mutex_unlock(&mutex);
        Sleep(10);
    }
}

void *display(void *param)
{
    while (1)
    {
        printf("buffer:\n");
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", buffer[i]);
        }
        printf("\n");

        printf("total consume:\n");
        for (int i = 0; i < total_consume; i++)
        {
            printf("%d ", consume_list[i]);
        }
        printf("\n\n\n");
        Sleep(1000);
    }
}

int main(int argc, char *argv[])
{
    pthread_mutex_init(&mutex, NULL);

    pthread_t produce, consume1, consume2, show;
    pthread_create(&produce, NULL, &producer, NULL);
    pthread_create(&consume1, NULL, &consumer, NULL);
    pthread_create(&consume2, NULL, &consumer, NULL);
    pthread_create(&show, NULL, &display, NULL);

    pthread_join(produce, NULL);
    pthread_join(consume1, NULL);
    pthread_join(consume2, NULL);
    pthread_join(show, NULL);

    pthread_mutex_destroy(&mutex);
}