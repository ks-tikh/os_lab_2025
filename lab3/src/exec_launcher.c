#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s seed arraysize\n", argv[0]);
        return 1;
    }

    pid_t pid = fork();
    
    if (pid == -1) {
        // Ошибка создания процесса
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Дочерний процесс - используем системный вызов exec
        
        printf("Child process: launching sequential_min_max with seed=%s, array_size=%s\n", 
               argv[1], argv[2]);
        
        // Вариант 1: execv с массивом аргументов
        char *args[] = {"./sequential_min_max", argv[1], argv[2], NULL};
        execv(args[0], args);
        
        // Если execv вернул управление - значит ошибка
        perror("execv failed");
        return 1;
    } else {
        // Родительский процесс
        printf("Parent process: waiting for child to finish...\n");
        
        int status;
        waitpid(pid, &status, 0);
        
        if (WIFEXITED(status)) {
            printf("Parent: child process exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Parent: child process terminated abnormally\n");
        }
    }
    
    return 0;
}
