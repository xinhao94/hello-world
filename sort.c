#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int compareInts(const void* n1vp, const void* n2vp){
  const int* n1ptr = n1vp;
  const int* n2ptr = n2vp;
  return *n1ptr - *n2ptr;
}

void sortIntArray(int* array, size_t nelements){
  qsort(array, nelements, sizeof(int), compareInts);
}

int compareStrings(const void* s1vp, const void* s2vp){
  const char* const* s1ptr = s1vp;
  const char* const* s2ptr = s2vp;
  return strcmp(*s1ptr, *s2ptr);
}

void sortStringArray(const char** array, size_t nelements){
  qsort(array, nelements, sizeof(const char*), compareStrings);
}

void printIntArray(int* data, int n){
  for(int i=0; i<n; i++){
    printf("%d ", data[i]);
  }
  printf("\n");
}

void printStringArray(const char** data, int n){
  for(int i=0; i<n; i++){
    printf("%s ", data[i]);
  }
  printf("\n");
}


int main(void) {
  int ints[] = {2,1,6,5,4,7,3};
  printIntArray(ints, 7);
  sortIntArray(ints, 7);
  printIntArray(ints, 7);
  const char* strs[] = {"ghi", "abc", "jkl", "def"};
  printStringArray(strs, 4);
  sortStringArray(strs, 4);
  printStringArray(strs, 4);       
  return EXIT_SUCCESS;
}
