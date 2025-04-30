#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

FILE *fp;
sem_t s1, s2;

void* t1(void* p) {
    int sum = 0;
    for (int i = 1; i <= 100; ++i) {
        sem_wait(&s1);
        sum += i;
        fprintf(fp, "Thread 1 : %d\n", sum);
        sem_post(&s2);
    }
    return NULL;
}

void* t2(void* p) {
    int sum = 0;
    for (int i = 1; i <= 100; ++i) {
        sem_wait(&s2);
        sum += i;
        fprintf(fp, "Thread 2 : %d\n", sum);
        sem_post(&s1);
    }
    return NULL;
}

int main() {
    fp = fopen("result.txt", "w");
    sem_init(&s1, 0, 1);
    sem_init(&s2, 0, 0);
    pthread_t a, b;
    pthread_create(&a, 0, t1, 0);
    pthread_create(&b, 0, t2, 0);
    pthread_join(a, 0);
    pthread_join(b, 0);
    fclose(fp);
    return 0;
}
