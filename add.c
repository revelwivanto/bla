#include <stdio.h>
#include <pthread.h>

FILE *fp;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void* run(void* arg) {
    int id = *(int*)arg, sum = 0;
    for (int i = 1; i <= 100; ++i) {
        sum += i;
        pthread_mutex_lock(&m);
        fprintf(fp, "Thread %d : %d\n", id, sum);
        pthread_mutex_unlock(&m);
    }
    return NULL;
}

int main() {
    int id1 = 1, id2 = 2;
    fp = fopen("result.txt", "w");
    pthread_t t1, t2;
    pthread_create(&t1, NULL, run, &id1);
    pthread_create(&t2, NULL, run, &id2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    fclose(fp);
    return 0;
}
