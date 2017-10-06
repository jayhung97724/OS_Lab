#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  FILE* cptr;
  seteuid(0);
  printf("My real user id      = %d\n", getuid());
  printf("My effective user id = %d\n", geteuid());
  cptr = fopen("datafile", "a");

  if(cptr == NULL) {
    printf("can't open file!\n");
    return 0;
  }

  fprintf(cptr, "My real id      = %d\n", getuid());
  fprintf(cptr, "My effective id = %d\n", geteuid());
  fclose(cptr);

  return 0;
}

