#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#define LINE_SIZE 5

int main(void){
  //Open and read a file
  FILE * f = fopen("./test.txt", "r");
  if(f == NULL){
    printf("Error code = %d, reason = %s\n", errno, strerror(errno));
    return EXIT_FAILURE;
  }
  long total = 0;
  char line[LINE_SIZE];
  int c;
  int letters = 0;
  while((c=fgetc(f)) != EOF){
    printf("%c", c);
    if(isalpha(c)){
      letters ++;
    }
  }
  printf("This file has %d letters.\n", letters);
  fclose(f);
  // The strchr() function returns a pointer to the first 
  //occurrence of c that is converted to a character in string. 
  //The function returns NULL if the specified character is not found.
  FILE * g = fopen("./test.txt", "r");
  while(fgets(line, LINE_SIZE, g) != NULL){
    if(strchr(line, '\n') == NULL){
      printf("Line is too long!\n");
      return EXIT_FAILURE;
    }
    else{
        total += atoi(line);
    }
  }
  printf("The total is %ld.\n", total);
  fclose(g);
  //Write sth into the file
  FILE * h = fopen("./a.txt", "w");
  if(h == NULL){
    printf("Error code = %d, reason = %s\n", errno, strerror(errno));
    return EXIT_FAILURE;
  }
  int start = 1;
  int end = 7;
  for(int i=start; i<=end; i++){
      //printf("Code executed %d times.\n", i);
      fprintf(h, "%d\n", i*i);
  }
  printf("File \"a.txt\" has been created.\n");
  if(fclose(h) != 0){
      printf("Error code = %d, reason = %s\n", errno, strerror(errno));
      return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
