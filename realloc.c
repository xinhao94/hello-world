#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

int compareStrings(const void *s1vp, const void *s2vp){
  char * const * s1ptr = s1vp;
  char * const * s2ptr = s2vp;
  return strcmp(*s1ptr, *s2ptr);
}

void sort(char **lines, size_t n){
  qsort(lines, n, sizeof(*lines), compareStrings);
}

int main(void){
  char **lines = NULL;
  char *curr = NULL;
  size_t linecap;
  size_t i = 0;
  //EOF = control + D
  while(getline(&curr, &linecap, stdin) >= 0){
    lines = realloc(lines, (i+1)*sizeof(*lines));
    lines[i] = curr;
    curr = NULL;
    i ++;
  }
  free(curr);
  sort(lines, i);
  for (size_t j=0; j<i; j++){
    printf("%s", lines[j]);
    free(lines[j]);
  }
  free(lines);
  return EXIT_SUCCESS;
}
