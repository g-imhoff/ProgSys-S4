#include "../header/base.h"
#include "../header/error_chk.h"
#include "../header/script.h"

void ps1(void) {
    int tube[2]; 
    error_chk(pipe(tube));

    pid_t status_fork = fork();
    error_chk(status_fork);

    if (status_fork == 0) {
        close(tube[0]);
        int status_dup2 = dup2(tube[1], fileno(stdout));
        error_chk(status_dup2);
        close(tube[1]);

        int status_execlp = execlp("ps", "ps", "eaux", NULL); 
        error_chk(status_execlp);
    } else {
        close(tube[1]);

        char buffer[BUFFER_SIZE];
        ssize_t bytes_read;

        int write_file = open("./toto.txt", O_CREAT | O_WRONLY, 0644);
        error_chk(write_file);

        while ((bytes_read = read(tube[0], buffer, BUFFER_SIZE)) > 0) {
            write(write_file, buffer, bytes_read);
        }

        int wait_status = waitpid(status_fork, NULL, 0);
        error_chk(wait_status);
    }
}

void script(const char* username) {
    printf("Hello, %s\n", username);

    ps1();
}