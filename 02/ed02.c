/*
Aluno: Gabriel Xavier Borges
Matricula: 805347

*/

#include "gxb.h"

void method_01(void) {
  int x = 0;
  printf("digite o numero: ");
  scanf("%d", &x);
  if (G_isPar(x) == 1) {
    printf("O numero %d e par\n", x);
  } else {
    printf("O numero %d e impar\n", x);
  }
}

void method_02(void) {
  int x = 0;
  printf("digite o numero: ");
  scanf("%d", &x);
  if (G_isPar(x) == 1 && x > 25) {
    printf("O numero %d e par e maior que 25\n", x);
  } else if (G_isPar(x) != 1 && x < -25) {
    printf("O numero %d e impar e menor que -25\n", x);
  } else {
    printf("O numero nao atende os requisitos\n");
  }
}

void method_03(void) {
  int x, n = 0;
  printf("digite o numero de vezes para testar: ");
  scanf("%d", &n);
  while (n > 0) {
    x = G_readint("Digite x: \n");
    if (G_aIntervalo(x, 35, 65) == 1) {
      printf("O numero %d pertence ao intervalo aberto 35:65\n", x);
    } else {
      printf("O numero %d NAO pertence ao intervalo aberto 35:65\n", x);
    }
    n = n - 1;
  }
}

void method_04(void) {
  int x, n = 0;
  printf("digite o numero de vezes para testar: ");
  scanf("%d", &n);
  while (n > 0) {
    x = G_readint("Digite x: \n");
    if (G_fIntervalo(x, 15, 60) == 1) {
      printf("o numero %d pertence ao intervalo fechado 15:60\n", x);
    } else {
      printf("o numero %d NAO pertence ao intervalo fechado 15:60\n", x);
    }

    n = n - 1;
  }
}

void method_05(void) {
  int x = G_readint("Digite o numero: ");
  if (x >= 10 && x <= 30 && x >= 25 && x <= 50)

  {
    printf("O numero pertence a intersecao");
  } else if ((x >= 10 && x <= 30) || (x >= 25 & x <= 50)) {
    printf("O numero pertence a um dos intervalos");
  } else {
    printf("O numero nao pertence a nenhum dos intervalos ");
  }
}

void method_06(void) {
  int x, y = 0;
  printf("digite os numeros: ");
  scanf("%d %d", &x, &y);
  if (G_isPar(x) != 1 && G_isPar(y) == 1) {
    printf("O primeiro numero %d e impar e o segundo numero %d e par", x, y);
  } else if (G_isPar(x) == 1 && G_isPar(y) != 1) {
    printf("O primeiro numero %d e par e o segundo numero %d e impar", x, y);
  } else if (G_isPar(x) != 1 && G_isPar(y) != 1) {
    printf("O primeiro numero %d e impar e o segundo numero %d e impar", x, y);
  } else {
    printf("O primeiro numero %d e par e o segundo numero %d e par", x, y);
  }
}

void method_07(void) {

  int x = G_readint("Digite o numero: ");
  int y = G_readint("Digite o numero: ");

  if (G_isPar(x) == 1 && x < 0 && G_isPar(y) == 0 && y > 0) {
    printf("O primeiro e par e negativo e o segundo e impar e positivo");
  } else {
    printf("os numeros nao atendem os requisitos do exercicio ");
  }
}

void method_08(void) {
  double x = G_readdouble("Digite o numero: ");
  double y = G_readdouble("Digite o numero: ");

  x = x / 3.0;
  if (y == x) {
    printf("O segundo numero %lf e igual a 1/3 do primeiro numero %lf", y, x);
  } else if (y < x) {
    printf("O segundo numero %lf e menor que 1/3 do primeiro numero %lf", y, x);
  } else {
    printf("O segundo numero %lf e maior que 1/3 do primeiro numero %lf", y, x);
  }
}

void method_09(void) {
  double x = G_readdouble("Digite o numero: ");
  double y = G_readdouble("Digite o numero: ");
  double z = G_readdouble("Digite o numero: ");

  if (y != z) {
    if (x > y && x < z) /* || x < y && x > z */
    {
      printf("O primeiro numero esta entre os outros dois\n");
    } else {
      printf("O primeiro numero nao esta entre os outros dois\n");
    }
  } else {
    printf("Os dois numeros sao iguais\n");
  }
}

void method_10(void) {
  int n = 0;
  printf("Digite o numero de vezes para testar: ");
  scanf("%d", &n);
  while (n > 0) {
    double x = G_readdouble("Digite o numero: ");
    double y = G_readdouble("Digite o numero: ");
    double z = G_readdouble("Digite o numero: ");

    if (x != y && x != z && y != z) {
      if (x > y && x > z || x < y && x < z) {
        printf("O primeiro numero NAO esta entre os outros dois\n");
      } else {
        printf("o primeiro numero esta entre os outros dois\n");
      }
    } else {
      printf("existem dois ou mais numeros iguais\n");
    }
    n = n - 1;
  }
}

void method_11e(void) {

  char a = G_readchar("Digite a letra: ");
  char b = G_readchar("Digite a letra: ");
  char c = G_readchar("Digite a letra: ");

  if (a != b && a != c) {
    if (a > b && a < c || a < b && a > c) {
      printf("A primeira letra esta entre as outras duas");
    } else {
      printf("A primeira letra nao esta entre as outras duas");
    }
  } else {
    printf("A primeira letra e igual a uma das outras duas");
  }
}
void method_12e(void) {

  char a = G_readchar("Digite a letra: ");
  char b = G_readchar("Digite a letra: ");
  char c = G_readchar("Digite a letra: ");

  if (b != c) {
    if (a > b && a > c || a < b && a < c) {
      printf("A primeira letra esta fora do intervalo das  outras duas");
    } else if (a == b || a == c) {
      printf("A primeira letra e igual a uma das outras duas");
    }
  } else {
    printf("A segunda letra e igual a terceira letra");
  }
}

int main(int argc, char *argv[]) {

  int opcao = 0;

  printf("%s\n", "Estudo dirigido 02");
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