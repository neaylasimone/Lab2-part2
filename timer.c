/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

static volatile sig_atomic_t ticks = 0; /* number of SIGALRM received (seconds) */
static time_t start_time;

void alarm_handler(int signum)
{
  (void)signum;
  ticks++;           /* count every second */
}

void int_handler(int signum)
{
  (void)signum;
  time_t end = time(NULL);
  double elapsed = difftime(end, start_time);

  printf("\nTotal alarms (seconds counted): %d\n", (int)ticks);
  printf("Total execution time (seconds): %.0f\n", elapsed);
  /* exit after reporting */
  exit(0);
}

int main(int argc, char *argv[])
{
  start_time = time(NULL);

  /* set up handlers */
  signal(SIGALRM, alarm_handler);
  signal(SIGINT,  int_handler); /* CTRL-C */

  /* request a SIGALRM every second */
  alarm(1);

  for (;;) {
    pause();          /* sleep until *some* signal arrives */
    alarm(1);         /* schedule the next second */
  }

  return 0;
}
