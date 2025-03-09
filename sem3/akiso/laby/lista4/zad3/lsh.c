#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

//this is my implementation of a simple shell in C
//it can handle multiple commands separated by pipes
//it can handle background processes
//it can handle cd command
//it can handle exit command

#define MAX_LINE 1024
#define MAX_ARGS 128

void handle_background_processes() {
    while (waitpid(-1, NULL, WNOHANG) > 0);
}

void execute_command(char **args, int input_fd, int output_fd, int background) {
    pid_t pid = fork();
    if (pid == 0) {
        // Proces dziecka
        if (input_fd != STDIN_FILENO) {
            dup2(input_fd, STDIN_FILENO);
            close(input_fd);
        }
        if (output_fd != STDOUT_FILENO) {
            dup2(output_fd, STDOUT_FILENO);
            close(output_fd);
        }

        if (execvp(args[0], args) == -1) {
            perror("lsh");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("lsh");
    } else {
        if (!background) {
            waitpid(pid, NULL, 0);
        } else {
            printf("Proces uruchomiony w tle, PID: %d\n", pid);
        }
    }
}

void execute_pipeline(char *commands[], int num_commands, int background) {
    int pipe_fd[2], input_fd = STDIN_FILENO;

    for (int i = 0; i < num_commands; i++) {
        char *args[MAX_ARGS];
        int arg_count = 0;

        // Parsowanie aktualnego polecenia
        char *token = strtok(commands[i], " \t\r\n");
        while (token != NULL) {
            args[arg_count++] = token;
            token = strtok(NULL, " \t\r\n");
        }
        args[arg_count] = NULL;

        // Jeśli to nie ostatnie polecenie, tworzymy pipe
        int output_fd = STDOUT_FILENO;
        if (i < num_commands - 1) {
            pipe(pipe_fd);
            output_fd = pipe_fd[1];
        }

        // Uruchomienie polecenia
        execute_command(args, input_fd, output_fd, background);

        // Zamykamy deskryptory w procesie rodzica
        if (input_fd != STDIN_FILENO) {
            close(input_fd);
        }
        if (output_fd != STDOUT_FILENO) {
            close(output_fd);
        }

        // Ustawienie wejścia dla następnego polecenia
        if (i < num_commands - 1) {
            input_fd = pipe_fd[0];
        }
    }
}

void parse_and_execute(char *line) {
    char *commands[MAX_ARGS];
    int num_commands = 0, background = 0;

    // Sprawdzenie, czy proces ma być uruchomiony w tle
    char *ampersand = strchr(line, '&');
    if (ampersand) {
        background = 1;
        *ampersand = '\0'; // Usuwamy '&' z linii
    }

    // Podział linii na polecenia oddzielone |
    char *token = strtok(line, "|");
    while (token != NULL) {
        commands[num_commands++] = token;
        token = strtok(NULL, "|");
    }

    // Wykonanie poleceń w potoku
    if (num_commands > 1) {
        execute_pipeline(commands, num_commands, background);
    } else {
        // Jeśli brak potoku, wykonaj jedno polecenie
        char *args[MAX_ARGS];
        int arg_count = 0;

        token = strtok(commands[0], " \t\r\n");
        while (token != NULL) {
            args[arg_count++] = token;
            token = strtok(NULL, " \t\r\n");
        }
        args[arg_count] = NULL;

        execute_command(args, STDIN_FILENO, STDOUT_FILENO, background);
    }
}

void cd_command(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "lsh: oczekiwano argumentu dla \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("lsh");
        }
    }
}

void lsh_loop() {
    char line[MAX_LINE];

    while (1) {
        // Wyświetlenie promptu
        printf("lsh> ");
        fflush(stdout);

        // Odczytanie linii wejściowej
        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("\n");
            break;
        }

        // Usunięcie końcowego znaku nowej linii
        line[strcspn(line, "\n")] = '\0';

        // Obsługa wbudowanych komend
        if (strcmp(line, "exit") == 0) {
            break;
        } else if (strncmp(line, "cd", 2) == 0) {
            char *args[MAX_ARGS];
            int arg_count = 0;
            char *token = strtok(line, " \t\r\n");
            while (token != NULL) {
                args[arg_count++] = token;
                token = strtok(NULL, " \t\r\n");
            }
            args[arg_count] = NULL;
            cd_command(args);
        } else {
            // Wykonanie polecenia lub potoku
            parse_and_execute(line);
        }

        // Obsługa zakończonych procesów w tle
        handle_background_processes();
    }
}

int main() {
    // Obsługa sygnałów, aby unikać zombie procesów
    signal(SIGCHLD, handle_background_processes);

    // Pętla powłoki
    lsh_loop();

    return 0;
}
