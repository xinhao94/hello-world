#include <stdio.h>
#include <math.h>

struct _point{
  int x;
  int y;
};
typedef struct _point point;

void printPoint(point obj){
  printf("(%d,%d)\n", obj.x, obj.y);
}

void editPoint(point* p_obj, int a, int b){
  p_obj->x = a;
  p_obj->y = b;
}

double distance(point obj1, point obj2){
  return sqrt(pow((obj1.x-obj2.x),2) + pow((obj1.y-obj2.y),2));
}

double slope(point obj1, point obj2){
  return (obj2.y-obj1.y)/(obj2.x-obj1.x);
}

point* closestPoint(point* s, int n, point p){
  if(n == 0){
    return NULL;
  }
  double bestDistance = distance(s[0], p);
  point* bestChoice = &s[0];
  for(int i=1; i<n; i++){
    if(distance(s[i], p)<bestDistance){
      bestDistance = distance(s[i], p);
      bestChoice = &s[i];
    }
    else{
      continue;
    }
  }
  return bestChoice;
}

int main(void) {
  point target;
  editPoint(&target, 1, -1);
  point pointSet[7];
  pointSet[0].x = 2; pointSet[0].y = 7;
  pointSet[1].x = 10; pointSet[1].y = 5;
  pointSet[2].x = 8; pointSet[2].y = -2;
  pointSet[3].x = 7; pointSet[3].y = -6;
  pointSet[4].x = -3; pointSet[4].y = -5;
  pointSet[5].x = -8; pointSet[5].y = 0;
  pointSet[6].x = -5; pointSet[6].y = 6;
  printPoint(target);
  for(int i=0; i<=6; i++){
    printPoint(pointSet[i]);
  }
  point* result = closestPoint(pointSet, 7, target);
  printPoint(*result);
  return EXIT_SUCCESS;
}
