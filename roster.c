#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <assert.h>

struct student_tag{
  char * name;
  char ** classes;
  int numClasses;
};
typedef struct student_tag student_t;

struct roster_tag{
  student_t ** students;
  int numStudents;
};
typedef struct roster_tag roster_t;

struct classes_tag{
  char ** classNames;
  int numClasses;
};
typedef struct classes_tag classes_t;

void stripNewline(char * str){
  char * p = strchr(str, '\n');
  if(p != NULL){
    *p = '\0';
  }
}

int readAnInteger(FILE * f){
  char * p = NULL;
  size_t sz = 0;
  getline(&p, &sz, f);
  int answer = atoi(p);
  return answer;
}

student_t * readAStudent(FILE * f){
  student_t * s = malloc(sizeof(*s));
  size_t sz = 0;
  s->name = NULL;
  getline(&s->name, &sz, f);
  stripNewline(s->name);
  s->numClasses = readAnInteger(f);
  s->classes = malloc(s->numClasses * sizeof(*s->classes));
  for(int i=0; i<s->numClasses; i++){
      s->classes[i] = NULL;
      getline(&s->classes[i], &sz, f);
      stripNewline(s->classes[i]);
  }
  return s;
}

roster_t * readInput(const char * fname){
  FILE * f = fopen(fname, "r");
  if(f == NULL){
    return NULL;
  }
  roster_t * answer = malloc(sizeof(*answer));
  answer->numStudents = readAnInteger(f);
  answer->students = malloc(answer->numStudents * sizeof(*answer->students));
  if(answer->students == NULL){
    free(answer);
    return NULL;
  }
  for(int i=0; i<answer->numStudents; i++){
    answer->students[i] = readAStudent(f);
  }
  int result = fclose(f);
  assert(result == 0);
  return answer;
}

void printRoster(roster_t * the_roster){
    printf("\nTotal number of students is %d\n", the_roster->numStudents);
    printf("Their names are as follows:\n");
    for(int i=0; i<the_roster->numStudents; i++){
        printf("%d. %s\n", i+1, the_roster->students[i]->name);
    }
}

int contains(char ** array, const char * str, int n){
    for(int i=0; i<n; i++){
        if(strcmp(array[i], str) == 0){
            return 1;
        }
        else{
            continue;
        }
    }
    return 0;
}

void addClassToList(classes_t * class_list, char * name){
    class_list->numClasses ++;
    class_list->classNames = realloc(class_list->classNames, class_list->numClasses*sizeof(*class_list->classNames));
    class_list->classNames[class_list->numClasses-1] = name;
}

classes_t * getClassList(roster_t * the_roster){
    classes_t * ans = malloc(sizeof(*ans));
    assert(ans != NULL);
    ans->numClasses = 0;
    ans->classNames = NULL;
    for(int i=0; i<the_roster->numStudents; i++){
        student_t * curr_student = the_roster->students[i];
        for(int j=0; j<curr_student->numClasses; j++){
            if(contains(ans->classNames, curr_student->classes[j], ans->numClasses) == 0){
                addClassToList(ans, curr_student->classes[j]);
            }
            else{
                continue;
            }
        }
    }
    return ans;
}

void printClasses(classes_t * class_list){
    printf("\nTotal number of classes is %d\n", class_list->numClasses);
    printf("The names of all classes are as follows:\n");
    for(int i=0; i<class_list->numClasses; i++){
        printf("%d. %s\n", i+1, class_list->classNames[i]);
    }
}

char * makeRosterFileName(const char * class_name){
    const char * suffix = ".roster.txt";
    unsigned int length = strlen(class_name)+strlen(suffix)+1;
    char * answer = malloc(length * sizeof(*answer));
    snprintf(answer, length, "%s%s", class_name, suffix);
    return answer;
}

void writeOneFile(const char * class_name, roster_t * r){
  char * filename = makeRosterFileName(class_name);
  FILE * output_file = fopen(filename, "w");
  if(output_file == NULL){
    perror("fopen");
    fprintf(stderr, "Trying to open %s\n", filename);
    printf("Attempt to creat \"%s\" was failed\n", filename);
    abort();
  }
  else{
    printf("Roster file \"%s\" was created\n", filename);
  }
  free(filename);
  for(int i=0; i<r->numStudents; i++){
    student_t * s = r->students[i];
    if(contains(s->classes, class_name, s->numClasses) == 1){
      fprintf(output_file, "%s\n", s->name);
    }
    else{
      continue;
    }
  }
  int result = fclose(output_file);
  assert(result == 0);
}

void writeAllFiles(classes_t * unique_class_list, roster_t * the_roster){
  printf("\n");
  for(int i=0; i<unique_class_list->numClasses; i++){
    writeOneFile(unique_class_list->classNames[i], the_roster);
  }
}

void freeClasses(classes_t * c){
  for(int i=0; i<c->numClasses; i++){
    free(c->classNames[i]);
  }
  free(c->classNames);
}

void freeRoster(roster_t * r){
  for(int i=0; i<r->numStudents; i++){
    free(r->students[i]);
  }
  free(r->students);
}

int main(int argc, char ** argv){
  if(argc != 2){
    fprintf(stderr, "Please enter the file name as second argument\n");
    return EXIT_FAILURE;
  }
  printf("\nResults are generated based on information in \"%s\"\n", argv[1]);
  roster_t * the_roster = readInput(argv[1]);
  if(the_roster == NULL){
    fprintf(stderr, "The designated file could not be read\n");
    return EXIT_FAILURE;
  }
  printRoster(the_roster);
  classes_t * unique_class_list = getClassList(the_roster);
  printClasses(unique_class_list);
  writeAllFiles(unique_class_list, the_roster);
  freeClasses(unique_class_list);
  freeRoster(the_roster);
  return EXIT_SUCCESS;
}





/* 
input.txt
4
Orpheus
3
Mus304
Lit322
Bio419
Hercules
2
Gym399
Lit322
Perseus
3
Lit322
Phys511
Bio419
Bellerophon
2
Gym399
Bio419
*/
