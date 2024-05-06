/*
Aluno: Gabriel Xavier Borges
Matricula: 805347
Prova 01

Gabarito: 

Questao 01 = a.) -1
Questao 02 = b.) 1
Questao 03 = c.) a = 3; b = 5 * 3; c = (2* x + 3 ) / 3 
Questao 04 = d.) 1 1 2 4 6
Questao 05 = d.) f_05("14641") = 2 
*/



#include "gxb.h"
#include "io.h"

int f_01(char p[])
{
    int x = 0, y = 0;
    bool r = false, s = false, t = false;
    bool u = false, v = false, w = false;

    for (x = 0; x < strlen(p); x = x + 1)
    {
        r = ('a' <= p[x] && p[x] <= 'z');
        s = ('A' <= p[x] && p[x] <= 'Z');
        t = ('0' <= p[x] && p[x] <= '9');
        u = (r || s) && !w;
        v = !u && t;
        w != v;
        if (u)
            y = y + 1;
        else if (v)
            y = y - 1;
        return (y);
    }
}
void method_01(void)
{
    printf("%d", f_01 ("5aP4+0_Sr4nK0"));
}

int f_02 (int a, int b)
{
    if(a % 2 == 0 && b % 2 == 0) return (f_02(a/2, b/2));
    else
    if(a % 2 != 0 && b % 2 == 0) return (f_02(b%a, b/2));
    else
    if(a % 2 == 0 && b % 2 != 0) return (f_02(a/2, a%b));
    return ((a-1) % (b-1)/2);
}
void method_02(void)
{
    printf("\nf_02(30,72) = %d\n", f_02(30, 72));
}
void method_03(void)
{
    for(int x = 1; x <= 5; x = x + 1)
    {
        printf("\nx = %d", 2 * x + 1);
    }
    printf("\n");
    for(int x = 3; x <= 3 * 5; x = x + 3 )
    {
        printf("\nx = %d", (2*x+3) / 3);
    }
    printf("\n");
    // for(int x = 1; x <= 5 + 3; x = x + 3 )
    // {
    //     printf("\nx = %d", 2 * x - 3);
    // }
    // printf("\n");
    // for(int x = 3; x <= 5 + 3; x = x + 3 )
    // {
    //     printf("\nx = %d", 3 * x/2-3);
    // }
    // printf("\n");
    // for(int x = 1; x <= 3 * 5; x = x + 3 )
    // {
    //     printf("\nx = %d", x-x/3);
    // }
}
void method_04(void)
{
    int x = 1, y = 1, v = 0, w = 0, m = 2, n = 0;
    printf("\nn = ");
    scanf("%d", &n);
    getchar();
    printf("%d %d ",x , y);
    while(m < n) {v = x + y; m = m + 1; printf("%d ", v);
    if(m < n - 1){w = x + y + v; m = m + 1; printf("%d ", w);}
    x = v; y = w;}
}

int f_05 (char *s)
{
    int x = 0, y = strlen(s) - 1;
    while (x <= y && s[x] == s[y])
    {
        x = x + 1;
        y = y - 1;
    }
    return (x - y + s[x] - s[y]);
}
void method_05(void)
{
    printf("%d", f_05("14641"));
}

// Exercicio 06

bool funcao06(int n)
{
    bool primo(int n)
    {
        for (int i = 2; i < n / 2; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
}
void method_06(void)
{
    int n, a, b, c, count;

    for (int i = 11; i < 99; i++)
    {
        if (funcao06(i) == 1) // true
        {
            // printf("%d i = %d", i);
            a = i / 10;       // 37 = 3    || 13 = 1
            b = i % 10;       // 37 = 7    || 13 = 3
            c = (10 * b) + a; // 73        || 31
            // printf(" c = %d", c);
            // printf("\n");
            if (funcao06(c) == 1 && i < c)
            {
                printf("%d ", i);
                printf("%d ", c);
                printf("\n");
                count++;
            }
        }
    }
    printf("\ncount Sheldon = %d ", count);
}

int funcao07 (char *string)
{
    int tamanho = strlen(string);
    int t = 0, u = 0, erro = 0;

    for(int i = 0; i < tamanho; i++)
    {
        if(string[i] == 'T' || string[i] == 't')
        {
            t++;
        }
        else if(string[i] == 'U' || string[i] == 'u')
        {
            u++;
        }
    }

    if(t >= 1 && u == 0)
    {
        return (1);
    }
    else if(u >= 1 && t == 0)
    {
        return (2);
    }
    else if(t == 0 && u == 0)
    {
        return (0);
    }
    else
    {
        return (-1);
    }
}
void method_07(void)
{
    char string [80];
    printf("Digite a sequencia: ");
    scanf("%s", string);
    getchar();

    int result = funcao07(string);

    if(result == 1)
    {
        printf("DNA\n");
    }
    else if(result == 2)
    {
        printf("RNA\n");
    }
    else if(result == 0)
    {
        printf("INDEFINIDA\n");
    }
    else if(result == -1)
    {
        printf("ERRO.\n");
    }
}

// Exercicio08

bool funcao08(char *string)
{
    int count = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] >= '0' && string[i] <= '9')
        {
            count++;
        }
    }
    printf("count = %d\n", count);
    if (count != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void method_08(void)
{
    char string[80];
    int sum1 = 0;
    int sum2 = 0;
    int aux = 0;
    printf("Digite uma string: ");
    scanf("%s", string);
    getchar();

    if (funcao08(string) == 1)
    {
        for (int i = 0; i < strlen(string); i++)
        {
            sum1 = sum1 + (string[i] - 48);
        }
        for (int i = 0; i < strlen(string); i++)
        {
            aux = string[i] - 48;
            sum2 = sum2 + (aux * aux * aux);
        }
    }
    sum1 = sum1 * sum1;
    printf("sum1 = %d \n", sum1);
    printf("sum2 = %d ", sum2);

    if(sum1 == sum2)
    {
        printf("\nAfirmativa correta.");
    }
    else
    {
        printf("\nAfirmativa incorreta.");
    }
}

int main(int argc, char *argv[])
{

    int opcao = 0;

    printf("%s\n", "Prova 01");
    printf("%s\n", "Autor: Gabriel Xavier Borges");
    printf("\n");

    do
    {

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

        printf("\n%s", "Opcao = ");
        scanf("%d", &opcao);
        getchar();

        printf("\n%s%d", "Opcao = ", opcao);
        printf("\n");

        switch (opcao)
        {
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
        default:
            printf("\nERRO: Opcao invalida.\n");
            break;
        }
    } while (opcao != 0);

    printf("\n\nApertar ENTER para terminar.");
    getchar();
    return (0);
}
