#define _GNU_SOURCE

#include <unistd.h>
#include <stdio.h>

int main() {
  setresgid(getegid(), getegid(), getegid()); // Be nice.

  if (chdir("/home/jail/jaildir") == -1) {
    fprintf(stderr, "Unable to chdir().\n");
    return 1;
  }
  
  char* args[] = {"/bin/rbash", 0};
  char* envs[] = {"PATH=/nopathforyou", 0};

  if (execve(args[0], args, envs) == -1) {
    fprintf(stderr, "Unable to execve().\n");
    return 2;
  }
}
