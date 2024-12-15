#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265358979323846

typedef struct {
  double x1, x2, x3, x4;
  double y1, y2, y3, y4;
  double z1, z2, z3, z4;
} SpaceCoord;

typedef struct {
  double x, y, z;
} Coord;

typedef struct {
  int index;
  char type[10];
  Coord *coord;
} Shape;

typedef struct {
  char command[10];
  char side;
  double args[4];
  int shapeI;
} Command;

void translateCoords(Shape *shape, double A, double B, double C, int iteration);
void rotateCoords(Shape *shape, char side, double DEG, int iteration);
void reflectCoords(Shape *shape, char side, int iteration);
void scaleCoords(Shape *shape, double A, double B, double C, int iteration);

void parseCommand(Command *cmds, Shape *shape, int T);

void checkCameraSight(Shape *shape, SpaceCoord *spCoord);

int main() {
  SpaceCoord spCoord;
  scanf("%lf %lf %lf", &spCoord.x1, &spCoord.y1, &spCoord.z1);
  scanf("%lf %lf %lf", &spCoord.x2, &spCoord.y2, &spCoord.z2);
  scanf("%lf %lf %lf", &spCoord.x3, &spCoord.y3, &spCoord.z3);
  scanf("%lf %lf %lf", &spCoord.x4, &spCoord.y4, &spCoord.z4);

  int M;

  Shape shapes[M];

  scanf("%d", &M);

  int shapesIndex = 0;

  for (int i = 0; i < M; i++) {

    shapes[i].coord = (Coord *)malloc(sizeof(Coord) * 9);
    shapes[i].index = shapesIndex;

    shapesIndex++;
    scanf("%s", shapes[i].type);

    int iteration = 0;
    if (strcmp(shapes[i].type, "CUBE") == 0)
      iteration = 8;
    else if (strcmp(shapes[i].type, "PRISM") == 0)
      iteration = 6;
    else
      iteration = 5;

    for (int j = 0; j < iteration; j++) {
      scanf("%lf %lf %lf", &(shapes[i]).coord[j].x, &(shapes[i]).coord[j].y,
            &(shapes[i]).coord[j].z);
    }
  }

  int T;
  scanf("%d", &T);

  Command cmds[T];

  for (int i = 0; i < T; i++) {
    char command[10];
    int I, S, A, B, C;
    scanf("%s %d %d %d %d %d", command, &I, &S, &A, &B, &C);
  }

  /* parseCommand(cmds, shapes, T); */

  // free memory;
  for (int i = 0; i < M; i++) {
    printf("\n%d %s\n", shapes[i].index, shapes[i].type);
    free(shapes[i].coord);
  }
}

void parseCommand(Command *cmds, Shape *shapes, int T) {}

void translateCoords(Shape *shape, double A, double B, double C,
                     int iteration) {

  for (int i = 0; i < iteration; i++) {
    shape->coord[i].x += A;
    shape->coord[i].y += B;
    shape->coord[i].z += C;
  }
}
void rotateCoords(Shape *shape, char side, double DEG, int iteration) {
  int RAD = DEG * (PI) / 180;

  double x_Factor[3], y_Factor[3], z_Factor[3];
  if (side == 'X') {
    x_Factor[0] = 1;
    x_Factor[1] = 0;
    x_Factor[2] = 0;
    y_Factor[0] = 0;
    y_Factor[1] = cos(RAD);
    y_Factor[2] = -sin(RAD);
    z_Factor[0] = 0;
    z_Factor[1] = sin(RAD);
    z_Factor[2] = cos(RAD);
  } else if (side == 'Y') {
    x_Factor[0] = cos(RAD);
    x_Factor[1] = 0;
    x_Factor[2] = -sin(RAD);
    y_Factor[0] = 1;
    y_Factor[1] = cos(RAD);
    y_Factor[2] = 0;
    z_Factor[0] = sin(RAD);
    z_Factor[1] = 1;
    z_Factor[2] = cos(RAD);
  } else {
    x_Factor[0] = cos(RAD);
    x_Factor[1] = -sin(RAD);
    x_Factor[2] = 0;
    y_Factor[0] = sin(RAD);
    y_Factor[1] = cos(RAD);
    y_Factor[2] = 0;
    z_Factor[0] = 0;
    z_Factor[1] = 0;
    z_Factor[2] = 1;
  }

  for (int i = 0; i < iteration; i++) {
    shape->coord[i].x = shape->coord[i].x * x_Factor[0] +
                        shape->coord[i].x * x_Factor[1] +
                        shape->coord[i].x * x_Factor[2];
    shape->coord[i].y = shape->coord[i].y * y_Factor[0] +
                        shape->coord[i].y * y_Factor[1] +
                        shape->coord[i].y * y_Factor[2];
    shape->coord[i].z = shape->coord[i].z * z_Factor[0] +
                        shape->coord[i].z * z_Factor[1] +
                        shape->coord[i].z * z_Factor[2];
  }
}
void reflectCoords(Shape *shape, char side, int iteration) {
  double x_Factor[3], y_Factor[3], z_Factor[3];
  if (side == 'X') {
    x_Factor[0] = 1;
    x_Factor[1] = 0;
    x_Factor[2] = 0;
    y_Factor[0] = 0;
    y_Factor[1] = -1;
    y_Factor[2] = 0;
    z_Factor[0] = 0;
    z_Factor[1] = 0;
    z_Factor[2] = 1;
  } else if (side == 'Y') {
    x_Factor[0] = -1;
    x_Factor[1] = 0;
    x_Factor[2] = 0;
    y_Factor[0] = 0;
    y_Factor[1] = 1;
    y_Factor[2] = 0;
    z_Factor[0] = 0;
    z_Factor[1] = 0;
    z_Factor[2] = 1;
  } else {
    x_Factor[0] = 1;
    x_Factor[1] = 0;
    x_Factor[2] = 0;
    y_Factor[0] = 0;
    y_Factor[1] = 1;
    y_Factor[2] = 0;
    z_Factor[0] = 0;
    z_Factor[1] = 0;
    z_Factor[2] = -1;
  }

  for (int i = 0; i < iteration; i++) {
    shape->coord[i].x = shape->coord[i].x * x_Factor[0] +
                        shape->coord[i].x * x_Factor[1] +
                        shape->coord[i].x * x_Factor[2];
    shape->coord[i].y = shape->coord[i].y * y_Factor[0] +
                        shape->coord[i].y * y_Factor[1] +
                        shape->coord[i].y * y_Factor[2];
    shape->coord[i].z = shape->coord[i].z * z_Factor[0] +
                        shape->coord[i].z * z_Factor[1] +
                        shape->coord[i].z * z_Factor[2];
  }
}
void scaleCoords(Shape *shape, double A, double B, double C, int iteration) {
  for (int i = 0; i < iteration; i++) {
    shape->coord[i].x = shape->coord[i].x *= A;
    shape->coord[i].y = shape->coord[i].y *= B;
    shape->coord[i].z = shape->coord[i].z *= C;
  }
}
