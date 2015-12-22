#include <stdio.h>
#include <stdlib.h>

int
main() {
  int fds[2];
  char buf[128];
  int n, pid;
  pipe(fds);
  if ((pid = fork()) > 0) {
    write(fds[1], "pipe test", 9);
    pid = wait();
    printf("child is done\n");
  } else {
    n = read(fds[0], buf, sizeof(buf));
    printf("%s\n", buf);
    exit(0);
  }
}
