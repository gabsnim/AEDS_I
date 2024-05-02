/*
Aluno: Gabriel Xavier Borges
Matricula: 805347
*/

#include <math.h>
#include <stdio.h>

void method_01(void) {
  int x = 0;
  int y = 0;
  printf("digite x = ");
  scanf("%d", &x);
  if (x <= 0) {
    printf("tente com X > 0");
  } else {
    x = x * x;
    y = x * 3;
    printf("%d\n", y);
  }
}

void method_02(void) {
  int x;
  double m, p, a = 0.0;
  printf("digite x = ");
  scanf("%d", &x);
  if (x <= 0) {
    printf("tente com X > 0");
  } else {
    m = (double)x / 2.0;
    p = m * 4.0;
    a = m * m;
    printf("perimetro = %lf\narea = %lf\n", p, a);
  }
}

void method_03(void) {
  int l1, l2, a = 0;
  printf("digite os lados do retangulo\n");
  scanf("%d"
        "%d",
        &l1, &l2);
  a = (l1 * l2) * 6;
  printf("area 6x maior = %d\n", a);
}

void method_04(void) {
  int l1, l2 = 0;
  double a, p = 0.0;
  printf("digite os lados do retangulo\n");
  scanf("%d"
        "%d",
        &l1, &l2);
  if (l1 <= 0 || l2 <= 0) {
    printf("tente com lados > 0");
  } else {
    double a1 = ((double)l1 / 4);
    double a2 = ((double)l2 / 4);
    // a = ((double)l1 / 4) * ((double)l2 / 4);
    a = a1 * a2;
    p = (a1 * 2) + (a2 * 2);
    printf("area = %lf\n perimetro = %lf", a, p);
  }
}

void method_05(void) {
  double b, h, a = 0.0;
  printf("digite a base e a altura do triangulo\n");
  scanf("%lf"
        "%lf",
        &b, &h);
  if (b <= 0 || h <= 0) {
    printf("tente com valores > 0");
  } else {
    h = h * 2;
    a = (b * h) / 2;
    printf("area = %lf\n", a);
  }
}

void method_06(void) {
  double x, h, a, p = 0.0;
  printf("digite o lado\n");
  scanf("%lf", &x);

  if (x <= 0) {
    printf("tente com um valor > 0");
  } else {
    x = x * 3;
    h = x * sqrt(3) / 2;
    a = pow(x, 2) * sqrt(3) / 4;
    p = x * 3;
    printf("altura  = %lf\n area = %lf\n perimetro = %lf\n", h, a, p);
  }
}

void method_07(void) {
  double x, v = 0.0;
  printf("digite o valor do lado\n");
  scanf("%lf", &x);
  if (x <= 0) {
    printf("tente com um valor > 0");
  } else {
    x = x * 5;
    v = pow(x, 3);
    printf("o volume e: %lf\n", v);
  }
}

void method_08(void) {
  double c, h, l, v = 0.0;
  printf("digite o valor do comprimento, altura e largura\n");
  scanf("%lf"
        "%lf"
        "%lf",
        &c, &h, &l);
  if (c <= 0 || h <= 0 || l <= 0) {
    printf("tente com valores maiores que 0");
  } else {
    c = c / 8;
    h = h / 8;
    l = l / 8;
    v = c * h * l;
    printf("volume = %lf", v);
  }
}

void method_09(void) {
  double r, a = 0.0;
  printf("digite o valor do raio do circulo\n");
  scanf("%lf", &r);

  if (r <= 0) {
    printf("tente com raio > 0");
  } else {
    a = (M_PI * pow(r, 2)) / 2;
    a = a / 6;
    printf("%lf", a);
  }
}

void method_10(void) {
  double r, v = 0.0;
  printf("digite o valor do raio da esfera\n");
  scanf("%lf", &r);

  if (r <= 0) {
    printf("tente com raio > 0");
  } else {
    r = r * 0.75;
    v = (4.0 / 3.0) * M_PI * pow(r, 3);
    printf("o volume e: %lf", v);
  }
}

void method_11e(void) {
  double a, r = 0.0;
  printf("digite o valor da area: ");
  scanf("%lf", &a);

  if (a <= 0) {
    printf("tente com area > 0");
  } else {
    r = sqrt(a / M_PI);
    r = r / 7;
    printf("%.2lf\n", r);
  }
}
void method_12e(void) {
  double v, r, s = 0.0;
  printf("digite o valor do volume: ");
  scanf("%lf", &v);

  if (v <= 0) {
    printf("tente com volume > 0");
  } else {
    r = cbrt(v * 3 / (4 * M_PI));
    r = r * (5.0 / 8.0);
    s = 4.0 * M_PI * pow(r, 2);
    printf("raio de 5/8 = %.2lf\n", r);
    printf("area da superficie da esfera = %.2lf\n", s);
  }
}

int main(int argc, char *argv[]) {

  int opcao = 0;

  printf("%s\n", "Estudo dirigido 01");
  printf("%s\n", "Autor: Gabriel Xavier Borges");
  printf("\n");

  do {

    printf("\n%s\n", "Opcoes:");
    printf("\n%s", "0 - Terminar");
    printf("\n%s", "1 - Method_01");
    printf("\n");
    printf("\n%s", "2 - Method_02");
    printf("\n");
    printf("\n%s", "3 - Method_03");
    printf("\n");
    printf("\n%s", "4 - Method_04");
    printf("\n");
    printf("\n%s", "5 - Method_05");
    printf("\n");
    printf("\n%s", "6 - Method_06");
    printf("\n");
    printf("\n%s", "7 - Method_07");
    printf("\n");
    printf("\n%s", "8 - Method_08");
    printf("\n");
    printf("\n%s", "9 - Method_09");
    printf("\n");
    printf("\n%s", "10 - Method_10");
    printf("\n");
    printf("\n%s", "11 - Method_11e");
    printf("\n");
    printf("\n%s", "12 - Method_12e");
    printf("\n");

    printf("\n%s", "Opcao = ");
    scanf("%d", &opcao);
    getchar();

    printf("\n%s%d", "Opcao = ", opcao);
    printf("\n");

    switch (opcao) {
    case 0:
      break;
    case 1:
      method_01();
      break;
    case 2:
      method_02();
      break;
    case 3:
      method_03();
      break;
    case 4:
      method_04();
      break;
    case 5:
      method_05();
      break;
    case 6:
      method_06();
      break;
    case 7:
      method_07();
      break;
    case 8:
      method_08();
      break;
    case 9:
      method_09();
      break;
    case 10:
      method_10();
      break;
    case 11:
      method_11e();
      break;
    case 12:
      method_12e();
      break;
    default:
      printf("\nERRO: Opcao invalida.\n");
      break;
    }
  } while (opcao != 0);

  printf("\n\nApertar ENTER para terminar.");
  getchar();
  return (0);
}