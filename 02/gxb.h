#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char* chars;

int G_readint(char *text) {
  int x = 0;
  printf("%s", text);
  scanf("%d", &x);
  getchar();
  return (x);
}

double G_readdouble(char *text) {
  double x = 0;
  printf("%s", text);
  scanf("%lf", &x);
  getchar();
  return (x);
}

float G_readfloat(char *text) {
  float x = 0;
  printf("%s", text);
  scanf("%f", &x);
  getchar();
  return (x);
}

char G_readchar(char *text) {
  char x = '0';
  printf("%s", text);
  scanf("%c", &x);
  getchar();
  return (x);
}

char* G_readstring(char *text)
{
  char *x = (char*) malloc(100 * sizeof(char));
  printf("%s", text);
  scanf("%s", x);
  getchar();
  return (x);
}


// char* G_readln(char *text)
// {
//   //substituir /n por /0
// }

bool G_isPar(int x) {
  if (x % 2 == 0) {
    return true;
  }
  return false;
}

bool G_fIntervalo(int x, int a, int b) {
  if (x >= a && x <= b) {
    return true;
  }
  return false;
}

bool G_aIntervalo(int x, int a, int b) {
  if (x > a && x < b) {
    return true;
  }
  return false;
}

bool G_isMaiuscula (char x)
{
  if(x >= 'A' && x <= 'Z')
  {
    return true;
  }
  return false;
}

bool G_isMinuscula (char x)
{
  if(x >= 'a' && x <= 'z')
  {
    return true;
  }
  return false;
}

bool G_isDigit (char x)
{
  if(x >= '0' && x <= '9')
  {
    return true;
  }
  return false;
}

bool G_isSpecial (char x)
{
  if(G_isDigit(x) != 1 && G_isMaiuscula(x) != 1 && G_isMinuscula(x) != 1) // ou = 0 
  {
    return true;
  }
  return false;
}