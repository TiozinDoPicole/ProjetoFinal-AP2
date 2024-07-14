#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CÁLCULO TOTAL DO PAGAMENTO DO ALUGUEL
int pagamento(int x, int y)
{
    if (x == 0)
    {
        return 0;
    }
    else
    {
        return y + pagamento(x - 1, y);
    }
}

void tel(char x[]) {
    int p = 1, tam;

    while (p == 1) {
        printf("\nNúmero de telefone: ");
        fgets(x, 12, stdin);
        x[strcspn(x, "\n")] = 0;
        fflush(stdin);
        tam = strlen(x);

        if (tam != 11) {
            printf("[!]Erro: número de telefone inválido[!]\n");
        } else {
            p = 0;
            break;
        }
    }
}

void cpf(char i[]) {
    int j = 1, tam;

    while (j == 1) {
        printf("\nCPF: ");
        fgets(i, 12, stdin);
        fflush(stdin);
        tam = strlen(i);

        if (tam != 11) {
            printf("Erro: CPF inválido!\n");
        } else {
            j = 0;
            break;
        }
    }
}

void data(int *d, int *m, int *a) {
    int i = 1;

    while (i == 1) {
        printf("\nData de nascimento: \n");
        printf("Dia:");
        scanf("%d", d);
        printf("Mês:");
        scanf("%d", m);
        printf("Ano:");
        scanf("%d", a);

        // Verifica se os valores estão dentro de intervalos válidos
        if (*d < 1 || *d > 31 || *m < 1 || *m > 12 || *a < 1900 || *a > 2006) {
            printf("Erro: data de nascimento inválida!\n");
            i = 1;
        } else {
            i = 0;
            break;
        }
    }
}

#endif // BIBLIOTECA_H_INCLUDED
