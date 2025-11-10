#include <assert.h>
#include <signal.h>
#include <unistd.h>
#include <print>

sig_atomic_t quit = 0;

void handler(int signal)
{
    static const char msg[] = "hallo handler!\n";
    write(STDOUT_FILENO, msg, sizeof(msg));
    quit = 1;

    // !!!std::println("{}", msg); // <-- !!!
}

int main()
{
    std::println("PID={}", getpid());

    struct sigaction termaction = {0};
    termaction.sa_handler = handler;

    int rv = sigaction(SIGTERM, &termaction, nullptr);
    if (rv == -1) {
        perror("sigaction");
        return 1;
    }
    rv = sigaction(SIGINT, &termaction, nullptr);
    if (rv == -1) {
        perror("sigaction");
        return 1;
    }

    while (!quit) {
        char c;
        ssize_t nread = read(STDIN_FILENO, &c, 1);
        if (nread == -1) {
            perror("read");
            if (errno == EINTR)
                continue;
            return 1;
        }
        assert(nread == 1);
    }

    std::println("shutdown");

    return 0;
}
