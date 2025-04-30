#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    pid_t pid1 = fork();
    if (pid1 == 0) {
        int fd = open("count.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if (fd == -1) exit(EXIT_FAILURE);
        close(fd);
        exit(EXIT_SUCCESS);
    }

    waitpid(pid1, NULL, 0);

    pid_t pid2 = fork();
    if (pid2 == 0) {
        FILE *fp = fopen("count.txt", "w");
        if (!fp) exit(EXIT_FAILURE);
        for (int i = 1; i <= 100; ++i) fprintf(fp, "%d\n", i);
        fclose(fp);
        exit(EXIT_SUCCESS);
    }

    waitpid(pid2, NULL, 0);
    printf("Anakku sudah pintar berhitung\n");
    return 0;
}
