/*
Aluno: Gabriel Xavier Borges
Matricula: 805347
*/

/*
    GABARITO
    q01 -> 2;
    q02 -> [bqbubebi];
    q03 -> Weiss Grun
    q04 -> [cstnhlda]
    q05 -> [padre] [perda]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int q_01(int m, int n, int a[])
{
    int x = 0;
    if (0 < m && m < n - 1 &&
        a[m - 1] - a[m] > 0 && a[m] - a[m + 1] < 0)
    {
        x = 1;
    }
    if (0 < m && m < n)
    {
        if (x >= 0)
        {
            x = x + q_01(m - 1, n, a);
        }
        else
            ({ x = -m; });
    }
    return (x);
}
void method_01(void)
{
    int array[6] = {7, 9, 6, 8, 3, 5};
    int n = 6;
    printf("\nq_01 = %d\n", q_01(n - 1, n, array));
}

void q_02(char *p, char *q)
{
    char *r = calloc(strlen(p) * strlen(q) + 1, sizeof(char));
    int k = 0;
    for (int x = 0; x < strlen(p); x++)
    {
        for (int y = 0; y < strlen(q); y++)
        {
            if (x == strlen(p) / 2)
            {
                r[k] = p[x];
                r[k + 1] = q[y];
                k = k + 2;
                if (k > 6)
                {
                    y = strlen(q);
                    x = strlen(p);
                }
            }
        }
    }
    printf("[%s]\n", r);
}
void method_02(void)
{
    char *p = calloc(9, sizeof(char));
    char *q = calloc(7, sizeof(char));
    p = "goiabada";
    q = "queijo";
    q_02(p, q);
}

void q_03(int a, int b, int c, char m[][3][7])
{
    for (int x = 0; x < a; x++)
    {
        for (int y = 0; y < b; y++)
        {
            if ('A' < m[x][0][0] && m[x][0][0] < 'Z')
            {
                printf("%8s", m[x][2]);
                y = b;
            }
            printf("\n");
        }
    }
}
void method_03(void)
{
    char m[3][3][7] = {{{"Azul"}, {"Blue"}, {"Blau"}},
                       {{"Branco"}, {"White"}, {"Weiss"}},
                       {{"Verde"}, {"Green"}, {"Grun"}}};

    q_03(3, 3, 7, m);
}

void q_04(char *p)
{
    for (int y = 0; y < strlen(p); y = y + 1)
    {
        if (y < strlen(p) - 1 && (p[y] == 'a' || p[y] == 'o'))
        {
            for (int z = y; z < strlen(p); z = z + 1)
            {
                p[z] = p[z + 1];
            }
        }
    }
    printf("[%s]\n", p);
}
void method_04(void)
{
    char *p = (char *)calloc(100, sizeof(char));
    scanf("%s", p);
    q_04(p);
}

char *q_05(int x, int y, char *p)
{
    char c = '_';
    if (0 <= x && x < strlen(p) && 0 <= y && y < strlen(p))
    {
        c = p[x];
        p[x] = p[y];
        p[y] = c;
    }
    return (p);
}
void method_05(void)
{
    char *p = calloc(6, sizeof(char));
    char z[6] = "perda";
    p = q_05(1, 4, q_05(2, 3, z));
    printf("[%s]\n", p);

    char *q = calloc(6, sizeof(char));
    q = q_05(2, 3, q_05(1, 4, z));
    printf("[%s]\n", q);
}

int q_06(char *p)
{
    char c = '0';
    int count = 0;
    int sum = 0;
    for (int i = 0; i < strlen(p); i++)
    {
        c = p[i];
        if (c >= 'A' && c <= 'I')
        {
            count += c - 'A' + 1;
        }
        else if (c >= 'J' && c <= 'R')
        {
            count += c - 'J' + 1;
        }
        else if (c >= 'S' && c <= 'Z')
        {
            count += c - 'S' + 1;
        }
    }
    // printf("%d", count);
    if (count == 11 || count == 22)
    {
        return count;
    }
    else
    {
        sum = count / 10;
        sum += count % 10;
    }
    return sum;
}
void method_06(void)
{
    printf("[%d]", q_06("MARIA DA SILVA"));
    printf("\n[%d]", q_06("ZIRALDO"));
}

struct Datas
{
    int dias[3];
    struct Data
    {
        int dia, mes, ano;
    } data[3];
};

int q_07(struct Datas *Data)
{
    int x = 365;
    int p = 0;
    int z = 0;

    for (int i = 0; i < 3; i++)
    {
        int dias = Data->dias[i];

        Data->data[i].ano = dias / 365;
        dias %= 365;
        Data->data[i].mes = dias / 30 + 1;
        Data->data[i].dia = dias % 30 + 1;

        z = (12 - Data->data[i].mes) * 30 + (30 - Data->data[i].dia) + 1;
        if (z < x)
        {
            x = z;
            p = i;
        }
    }

    p = p + 1;
    return p;
}
void method_07(void)
{
    struct Datas datas = {.dias = {9876, 8967, 6789}};

    int professor = q_07(&datas);
    printf("professor = %d\n", professor);
}

void method_08(void)
{
    FILE *arquivo1 = fopen("DADOS.TXT", "rt");
    FILE *arquivo2 = fopen("RESULTADO.TXT", "wt");
    FILE *arquivo3 = fopen("AUXILIAR.TXT", "wt");
    int x = 0;

    if (arquivo1 != NULL && arquivo2 != NULL && arquivo3 != NULL)
    {
        while (!feof(arquivo1))
        {
            fscanf(arquivo1, "%d", &x);
            if (x % 2 != 0)
            {
                fprintf(arquivo2, "%d\n", x);
            }
            else
            {
                fprintf(arquivo3, "%d\n", x);
            }
        }
    }
    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivo3);

    FILE *arquivo4 = fopen("RESULTADO.TXT", "a");
    FILE *arquivo5 = fopen("AUXILIAR.TXT", "rt");

    if (arquivo4 != NULL && arquivo5 != NULL)
    {
        fscanf(arquivo5, "%d", &x);
        while (!feof(arquivo5))
        {
            fprintf(arquivo4, "%d\n", x);
            fscanf(arquivo5, "%d", &x);
        }
    }
    fclose(arquivo4);
    fclose(arquivo5);
}

int main(int argc, char *argv[])
{

    int opcao = 0;

    printf("%s\n", "Prova 02");
    printf("%s\n", "Autor: Gabriel Xavier Borges");
    printf("\n");

    do
    {

        printf("\n%s\n", "Opcoes:");
        printf("\n%s", "0 - Terminar");
        printf("\n%s", "1 - q_01");
        printf("\n");
        printf("\n%s", "2 - q_02");
        printf("\n");
        printf("\n%s", "3 - q_03");
        printf("\n");
        printf("\n%s", "4 - q_04");
        printf("\n");
        printf("\n%s", "5 - q_05");
        printf("\n");
        printf("\n%s", "6 - q_06");
        printf("\n");
        printf("\n%s", "7 - q_07");
        printf("\n");
        printf("\n%s", "8 - q_08");
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