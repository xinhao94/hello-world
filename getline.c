#include <stdio.h>

int main(void){
  size_t sz = 0;
  ssize_t len = 0;
  char * line = NULL;
  FILE * f = fopen("./test.txt", "r");
  while((len = getline(&line, &sz, f)) >= 0){
    printf("%s", line);
  }
  free(line);
  fclose(f);
  return EXIT_SUCCESS;
}
