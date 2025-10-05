/* signal1.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

/* Global flag set by handler */
volatile sig_atomic_t got_alarm = 0;

void handler(int signum)
{ /* signal handler */
  (void)signum; /* unused */
  printf("Hello World!\n");
  got_alarm = 1; /* let main continue */
}

int main(int argc, char *argv[])
{
  /* register handler to handle SIGALRM */
  signal(SIGALRM, handler);
  /* schedule a SIGALRM for 5 seconds */
  alarm(5);

  /* busy wait for signal to be delivered (kept to match starter style) */
  while (!got_alarm) { /* spin */ }

  /* after handler has run */
  printf("Turing was right!\n");
  return 0;
}
