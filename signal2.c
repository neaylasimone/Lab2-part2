/* signal2.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t got_alarm = 0;

void handler(int signum)
{
  (void)signum;
  printf("Hello World!\n");
  got_alarm = 1;
}

int main(int argc, char *argv[])
{
  /* register handler once */
  signal(SIGALRM, handler);

  /* forever: wait 5s -> handler prints, then main prints */
  for (;;) {
    got_alarm = 0;
    alarm(5);                 /* schedule SIGALRM in 5 seconds */
    while (!got_alarm) { }    /* busy wait to match starter style */
    printf("Turing was right!\n");
    /* loop repeats */
  }

  return 0;
}
