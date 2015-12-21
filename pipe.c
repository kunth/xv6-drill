#include <stdio.h>

int
main() {
  int fds[2];
  char buf[128];
  int n;
  pipe(fds);
  write(fds[1], "hello", 5);
  n = read(fds[0], buf, sizeof(buf));
  printf("%s\n", buf);
  return 0;
}
