#include "biblioteca.h"
#include <locale.h>
#include <math.h>
#include <stdio.h> //codigo principal
#include <stdlib.h>
#include <string.h>

// STRUCT DE PESSOA
typedef struct
{
    char telefone[11];
    char nome[100];
    char cpf[11];
    int dia;
    int mes;
    int ano;
} pessoa;

// STRUCT DE ANUNCIO DE CASA
typedef struct
{
    char detl[150];
    char rua[100];
    char num[5];
    char compl [200];
    char bairro[50];
    char cidade[50];
    float aluguel;
} anuncio;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    pessoa locador, cliente;
    anuncio casa;
    char comentario[100], com;
    int tam = 0, menu = 1, aluguel = 1;
    int exp, opcao, reserva, estadia, valor;
    FILE *file, *file2;
    int i,j = 5;

    file = fopen("Casas disponiveis.txt", "w");
    fprintf(file,"================== CASAS DISPON�VEIS ==================\n\n");
    fprintf(file,"===== CASA 1 =====\n");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"| %-15s | %-25s | %-35s |\n", "Aeroporto", "Tocantins", "Em frente ao parque IPSG");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"\nDetalhamento:\n");
    fprintf(file,"2 quartos, 1 banheiro, sala, cozinha, garagem para 1 carro.\n");
    fprintf(file,"\nLOCADOR\n");
    fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"| %-15s | %-15s |\n", "Borges", "(64)92639-3926");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"\nVALOR\n");
    fprintf(file,"Aluguel: R$ 1200,00\n");

    fprintf(file,"\n ===== CASA 2 =====\n");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"| %-15s | %-25s | %-35s         |\n", "Sodr�", "Andr� Luiz", "Em frente ao bar Rancho Tardezinha");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"\nDetalhamento:\n");
    fprintf(file,"3 quartos, 2 banheiros, sala e cozinha juntas, garagem para 1 carro.\n");
    fprintf(file,"\nLOCADOR\n");
    fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"| %-15s | %-15s |\n", "Wesley Gonzaga", "(64)92626-6262");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"\nVALOR\n");
    fprintf(file,"Aluguel: R$ 1400,00\n");

    fprintf(file,"\n ===== CASA 3 =====\n");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"| %-15s | %-25s | %-35s         |\n", "Setor Central", "Avenida anhanguera", "Na esquina de frente ao pit dog");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"\nDetalhamento:\n");
    fprintf(file,"2 quartos, 2 banheiro, sala, cozinha, garagem para 2 carros.\n");
    fprintf(file,"\nLOCADOR\n");
    fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"| %-15s | %-15s |\n", "Igor Guilherme", "(64)98676-4444");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"\nVALOR\n");
    fprintf(file,"Aluguel: R$ 1450,00\n");

    fprintf(file,"\n ===== CASA 4 =====\n");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"| %-15s | %-25s | %-35s         |\n", "Setor Aeroporto", "Tiradentes", "De frente ao Parque IPSG");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"\nDetalhamento:\n");
    fprintf(file,"2 quartos, 1su�te, 1 banheiro, sala, cozinha, garagem para 1 carro.\n");
    fprintf(file,"\nLOCADOR\n");
    fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"| %-15s | %-15s |\n", "Caio Passos", "(64)99999-4567");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"\nVALOR\n");
    fprintf(file,"Aluguel: R$ 1600,00\n");

    fprintf(file,"\n ===== CASA 5 =====\n");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"| %-15s | %-25s | %-35s         |\n", "Setor Central", "Avenida anhanguera", "Em frente a pra�a");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"\nDetalhamento:\n");
    fprintf(file,"2 quartos, 1 banheiro social, sala e cozinha.\n");
    fprintf(file,"\nLOCADOR\n");
    fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"| %-15s | %-15s |\n", "Claudia Arraia", "(64)99999-1000");
    fprintf(file,"-----------------------------------------------------------------------------------------------\n");
    fprintf(file,"\nVALOR\n");
    fprintf(file,"Aluguel: R$ 1300,00\n");
    fclose(file);

    file2 = fopen("Casas ocupadas.txt", "w");
    fprintf(file2,"================== CASAS OCUPADAS ==================\n\n");
    fclose(file2);

    // MENU
    while (menu == 1)
    {
        printf(
            "               "
            "======================================================================"
            "======\n");
        printf("                * -------------------------  Bem-vindo ao "
               "Universilar!-------------------* \n ");
        printf("                * ------------------------ Sua plataforma de "
               "alojamento---------------* \n");
        printf("                * ------------------------- para estudantes "
               "universit�rios.--------------* \n");
        printf(
            "               "
            "======================================================================"
            "======\n");
        printf("\n");

        printf("------------------------------------------------- Selecione a "
               "experi�ncia desejada: "
               "-------------------------------------------------\n");
        printf("\n");
        printf("-----------------------------(1) Visualizar "
               "Casas-----------------------(2) Criar "
               "An�ncio--------------------------------------------\n");
        scanf("%d", &exp);
        if(exp == 2){
            j+=1;
        }

        switch (exp)
        {
        case 1:
            // ALUGAR CASAS

            system("cls");
            printf(" || CASAS ||:\n");
            printf("-----------------------------------------------------------------------------------------------\n");
            //CASA 1
            printf("|   %-15s | %-25s | %-35s         | \n", "Bairro: ", "Rua: ", "Complemento: ");
            printf("-----------------------------------------------------------------------------------------------\n");
            printf("|1- %-15s | %-25s | %-35s         | \n", "Aeroporto", "Tocantins", "Em frente ao parque IPSG");
            printf("-----------------------------------------------------------------------------------------------\n");

            //CASA 2
            printf("|2- %-15s | %-25s | %-35s         |\n", "Sodr�", "Andr� Luiz", "Em frente ao bar Rancho Tardezinha");
            printf("-----------------------------------------------------------------------------------------------\n");

            //CASA 3
            printf("|3- %-15s | %-25s | %-35s         |\n", "Setor Central", "Avenida anhanguera", "Na esquina de frente ao pit dog");
            printf("-----------------------------------------------------------------------------------------------\n");

            //CASA 4
            printf("|4- %-15s | %-25s | %-35s         |\n", "Setor Aeroporto", "Tiradentes", "De frente ao Parque IPSG");
            printf("-----------------------------------------------------------------------------------------------\n");

            //CASA 5
            printf("|5- %-15s | %-25s | %-35s         |\n", "Setor Central", "Avenida anhanguera", "Em frente a pra�a");
            printf("-----------------------------------------------------------------------------------------------\n");

            printf("[!]Digite o n�mero da casa desejada para ver mais informa��es[!]\n");
            scanf("%d", &opcao);
            system("cls");
            switch (opcao)
            {
            case 1:
                printf("\\ CASA DISPON�VEL \\:\n");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("| %-15s | %-25s | %-35s |\n", "Aeroporto", "Tocantins", "Em frente ao parque IPSG");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("\nDetalhamento:\n");
                printf("2 quartos, 1 banheiro, sala, cozinha, garagem para 1 carro.\n");
                printf("\nLOCADOR\n");
                printf("| %-15s | %-15s |\n", "Nome", "Contato");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("| %-15s | %-15s |\n", "Borges", "(64)92639-3926");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("\nVALOR\n");
                printf("Aluguel: R$ 1200,00\n");
                valor = 1200;
                fflush(stdin);

                printf("Insira seu nome:");
                scanf("%s", cliente.nome);
                fflush(stdin);
                printf("-----------------------------------------------------------------------------------------------\n");
                tel(cliente.telefone);
                printf("-----------------------------------------------------------------------------------------------\n");
                cpf(cliente.cpf);
                printf("-----------------------------------------------------------------------------------------------\n");

                i = 1;
                while(i == 1){
                    printf("\n Deseja inserir um coment�rio sobre a casa?");
                    printf("\n (Responda com S para sim ou N para N�O)\n");
                    scanf("%c", &com);
                        if(com == 'S' || com == 's'){
                            printf("\nDeixe seu coment�rio: ");
                            fgets(comentario, sizeof(comentario), stdin);
                            getchar();
                            fflush(stdin);
                            i = 0;
                        }else if(com == 'n' || com == 'N'){
                            i = 0;
                        }else{
                            printf("Resposta inv�lida");
                        }
                }

                printf("\nInsira o tempo de estadia(em meses) pretendido para alugar a casa: ");
                scanf("%d", &estadia);
                printf("\n[!]O valor total a ser pago para o locador em %d meses ser� de:", estadia);
                printf("R$ %d,00 [!]\n", pagamento(estadia, valor));

                printf("\n!!Aperte ENTER para confirmar!!\n");
                getchar();
                getchar();

                file = fopen("Casas disponiveis.txt", "w");
                fprintf(file,"================== CASAS DISPON�VEIS ==================\n\n");

                fprintf(file,"\n ===== CASA 2 =====\n");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s         |\n", "Sodr�", "Andr� Luiz", "Em frente ao bar Rancho Tardezinha");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nDetalhamento:\n");
                fprintf(file,"3 quartos, 2 banheiros, sala e cozinha juntas, garagem para 1 carro.\n");
                fprintf(file,"\nLOCADOR\n");
                fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-15s |\n", "Wesley Gonzaga", "(64)92626-6262");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nVALOR\n");
                fprintf(file,"Aluguel: R$ 1400,00\n");

                fprintf(file,"\n ===== CASA 3 =====\n");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s         |\n", "Setor Central", "Avenida anhanguera", "Na esquina de frente ao pit dog");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nDetalhamento:\n");
                fprintf(file,"2 quartos, 2 banheiro, sala, cozinha, garagem para 2 carros.\n");
                fprintf(file,"\nLOCADOR\n");
                fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-15s |\n", "Igor Guilherme", "(64)98676-4444");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nVALOR\n");
                fprintf(file,"Aluguel: R$ 1450,00\n");

                fprintf(file,"\n ===== CASA 4 =====\n");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s         |\n", "Setor Aeroporto", "Tiradentes", "De frente ao Parque IPSG");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nDetalhamento:\n");
                fprintf(file,"2 quartos, 1su�te, 1 banheiro, sala, cozinha, garagem para 1 carro.\n");
                fprintf(file,"\nLOCADOR\n");
                fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-15s |\n", "Caio Passos", "(64)99999-4567");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nVALOR\n");
                fprintf(file,"Aluguel: R$ 1600,00\n");

                fprintf(file,"\n ===== CASA 5 =====\n");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s         |\n", "Setor Central", "Avenida anhanguera", "Em frente a pra�a");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nDetalhamento:\n");
                fprintf(file,"2 quartos, 1 banheiro social, sala e cozinha.\n");
                fprintf(file,"\nLOCADOR\n");
                fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-15s |\n", "Claudia Arraia", "(64)99999-1000");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nVALOR\n");
                fprintf(file,"Aluguel: R$ 1300,00\n");

                fclose(file);

                file2 = fopen("Casas ocupadas.txt", "a");
                fprintf(file2,"===== CASA 1 =====\n");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"| %-15s | %-25s | %-35s |\n", "Aeroporto", "Tocantins", "Em frente ao parque IPSG");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"\nDetalhamento:\n");
                fprintf(file2,"2 quartos, 1 banheiro, sala, cozinha, garagem para 1 carro.\n");
                fprintf(file2,"\nLOCADOR\n");
                fprintf(file2,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"| %-15s | %-15s |\n", "Borges", "(64)92639-3926");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"\nVALOR\n");
                fprintf(file2,"Aluguel: R$ 1200,00\n");
                fprintf(file2,"\nOCUPANTE\n");
                fprintf(file2,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"| %-15s | %-15s |\n", cliente.nome, cliente.telefone);
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");

                fclose(file2);

                system("cls");
                printf("[!]-------------------------PARAB�NS-------------------------[!"
                       "]\n");
                printf(
                    "\n[!]O pedido de reserva dessa casa foi feito com sucesso[!]\n");
                printf("O seu pedido de reserva j� foi feito e ser� confirmado pelo "
                       "locador\n");

                break;
            case 2:
                printf("\\ CASA DISPON�VEL \\:\n");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("| %-15s | %-25s | %-35s |\n", "Sodr�", "Andr� Luiz", "Em frente ao parque IPSG");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("\nDetalhamento:\n");
                printf("3 quartos, 2 banheiros, sala e cozinha juntas, garagem para 1 carro.\n");
                printf("\nLOCADOR\n");
                printf("| %-15s | %-15s |\n", "Nome", "Contato");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("| %-15s | %-15s |\n", "Wesley Gonzaga", "(64)92626-6262");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("\nVALOR\n");
                printf("Aluguel: R$ 1400,00\n");
                valor = 1400;
                fflush(stdin);

                printf("Insira seu nome:");
                scanf("%s", cliente.nome);
                fflush(stdin);
                printf("-----------------------------------------------------------------------------------------------\n");
                tel(cliente.telefone);
                printf("-----------------------------------------------------------------------------------------------\n");
                cpf(cliente.cpf);
                printf("-----------------------------------------------------------------------------------------------\n");

                i = 1;
                while(i == 1){
                    printf("\n Deseja inserir um coment�rio sobre a casa?");
                    printf("\n (Responda com S para sim ou N para N�O)\n");
                    scanf("%c", &com);
                        if(com == 'S' || com == 's'){
                            printf("\nDeixe seu coment�rio: ");
                            fgets(comentario, sizeof(comentario), stdin);
                            getchar();
                            fflush(stdin);
                            i = 0;
                        }else if(com == 'n' || com == 'N'){
                            i = 0;
                        }else{
                            printf("Resposta inv�lida");
                        }
                }

                printf("\nInsira o tempo de estadia(em meses) pretendido para alugar a casa: ");
                scanf("%d", &estadia);
                printf("\n[!]O valor total a ser pago para o locador em %d meses ser� de: ", estadia);
                printf("R$ %d,00 [!]\n", pagamento(estadia, valor));

                printf("\n!!Aperte ENTER para confirmar!!\n");
                getchar();
                getchar();

                file = fopen("Casas disponiveis.txt", "w");
                fprintf(file,"================== CASAS DISPON�VEIS ==================\n\n");
                fprintf(file,"===== CASA 1 =====\n");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Aeroporto", "Tocantins", "Em frente ao parque IPSG");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nDetalhamento:\n");
                fprintf(file,"2 quartos, 1 banheiro, sala, cozinha, garagem para 1 carro.\n");
                fprintf(file,"\nLOCADOR\n");
                fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-15s |\n", "Borges", "(64)92639-3926");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nVALOR\n");
                fprintf(file,"Aluguel: R$ 1200,00\n");

                fprintf(file,"\n ===== CASA 3 =====\n");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s         |\n", "Setor Central", "Avenida anhanguera", "Na esquina de frente ao pit dog");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nDetalhamento:\n");
                fprintf(file,"2 quartos, 2 banheiro, sala, cozinha, garagem para 2 carros.\n");
                fprintf(file,"\nLOCADOR\n");
                fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-15s |\n", "Igor Guilherme", "(64)98676-4444");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nVALOR\n");
                fprintf(file,"Aluguel: R$ 1450,00\n");

                fprintf(file,"\n ===== CASA 4 =====\n");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s         |\n", "Setor Aeroporto", "Tiradentes", "De frente ao Parque IPSG");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nDetalhamento:\n");
                fprintf(file,"2 quartos, 1su�te, 1 banheiro, sala, cozinha, garagem para 1 carro.\n");
                fprintf(file,"\nLOCADOR\n");
                fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-15s |\n", "Caio Passos", "(64)99999-4567");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nVALOR\n");
                fprintf(file,"Aluguel: R$ 1600,00\n");

                fprintf(file,"\n ===== CASA 5 =====\n");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s         |\n", "Setor Central", "Avenida anhanguera", "Em frente a pra�a");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nDetalhamento:\n");
                fprintf(file,"2 quartos, 1 banheiro social, sala e cozinha.\n");
                fprintf(file,"\nLOCADOR\n");
                fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-15s |\n", "Claudia Arraia", "(64)99999-1000");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nVALOR\n");
                fprintf(file,"Aluguel: R$ 1300,00\n");

                fclose(file);

                file2 = fopen("Casas ocupadas.txt", "a");
                fprintf(file2,"===== CASA 2 =====\n");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"| %-15s | %-25s | %-35s |\n", "Sodr�", "Andr� Luiz", "Em frente ao parque IPSG");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"\nDetalhamento:\n");
                fprintf(file2,"3 quartos, 2 banheiros, sala e cozinha juntas, garagem para 1 carro.\n");
                fprintf(file2,"\nLOCADOR\n");
                fprintf(file2,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"| %-15s | %-15s |\n", "Wesley Gonzaga", "(64)92626-6262");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"\nVALOR\n");
                fprintf(file2,"Aluguel: R$ 1400,00\n");
                fprintf(file2,"\nOCUPANTE\n");
                fprintf(file2,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"| %-15s | %-15s |\n", cliente.nome, cliente.telefone);
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");

                fclose(file2);

                system("cls");
                printf("[!]-------------------------PARAB�NS-------------------------[!"
                       "]\n");
                printf(
                    "\n[!]O pedido de reserva dessa casa foi feito com sucesso[!]\n");
                printf("O seu pedido de reserva j� foi feito e ser� confirmado pelo "
                       "locador\n");
                break;
            case 3:
                printf("\\ CASA DISPON�VEL \\:\n");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("| %-15s | %-25s | %-35s |\n", "Setor Central", "Avenida anhanguera", "Na esquina de frente ao pit dog");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("\nDetalhamento:\n");
                printf("2 quartos, 2 banheiro, sala, cozinha, garagem para 2 carros.\n");
                printf("\nLOCADOR\n");
                printf("| %-15s | %-15s |\n", "Nome", "Contato");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("| %-15s | %-15s |\n", "Igor Guilherme", "(64)98676-4444");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("\nVALOR\n");
                printf("Aluguel: R$ 1450,00\n");
                valor = 1450;
                fflush(stdin);

                printf("Insira seu nome:");
                scanf("%s", cliente.nome);
                fflush(stdin);
                printf("-----------------------------------------------------------------------------------------------\n");
                tel(cliente.telefone);
                printf("-----------------------------------------------------------------------------------------------\n");
                cpf(cliente.cpf);
                printf("-----------------------------------------------------------------------------------------------\n");

                i = 1;
                while(i == 1){
                    printf("\n Deseja inserir um coment�rio sobre a casa?");
                    printf("\n (Responda com S para sim ou N para N�O)\n");
                    scanf("%c", &com);
                        if(com == 'S' || com == 's'){
                            printf("\nDeixe seu coment�rio: ");
                            fgets(comentario, sizeof(comentario), stdin);
                            getchar();
                            fflush(stdin);
                            i = 0;
                        }else if(com == 'n' || com == 'N'){
                            i = 0;
                        }else{
                            printf("Resposta inv�lida");
                        }
                }

                printf("\nInsira o tempo de estadia(em meses) pretendido para alugar a casa: ");
                scanf("%d", &estadia);
                printf("\n[!]O valor total a ser pago para o locador ser� de: R$ %d,00 [!]\n", pagamento(estadia, valor));

                printf("\n!!Aperte ENTER para confirmar!!\n");
                getchar();
                getchar();

                file = fopen("Casas disponiveis.txt", "w");
                fprintf(file,"================== CASAS DISPON�VEIS ==================\n\n");
                fprintf(file,"===== CASA 1 =====\n");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Aeroporto", "Tocantins", "Em frente ao parque IPSG");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nDetalhamento:\n");
                fprintf(file,"2 quartos, 1 banheiro, sala, cozinha, garagem para 1 carro.\n");
                fprintf(file,"\nLOCADOR\n");
                fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-15s |\n", "Borges", "(64)92639-3926");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nVALOR\n");
                fprintf(file,"Aluguel: R$ 1200,00\n");

                fprintf(file,"\n ===== CASA 2 =====\n");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s         |\n", "Sodr�", "Andr� Luiz", "Em frente ao bar Rancho Tardezinha");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nDetalhamento:\n");
                fprintf(file,"3 quartos, 2 banheiros, sala e cozinha juntas, garagem para 1 carro.\n");
                fprintf(file,"\nLOCADOR\n");
                fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-15s |\n", "Wesley Gonzaga", "(64)92626-6262");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nVALOR\n");
                fprintf(file,"Aluguel: R$ 1400,00\n");

                fprintf(file,"\n ===== CASA 4 =====\n");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s         |\n", "Setor Aeroporto", "Tiradentes", "De frente ao Parque IPSG");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nDetalhamento:\n");
                fprintf(file,"2 quartos, 1su�te, 1 banheiro, sala, cozinha, garagem para 1 carro.\n");
                fprintf(file,"\nLOCADOR\n");
                fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-15s |\n", "Caio Passos", "(64)99999-4567");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nVALOR\n");
                fprintf(file,"Aluguel: R$ 1600,00\n");

                fprintf(file,"\n ===== CASA 5 =====\n");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s         |\n", "Setor Central", "Avenida anhanguera", "Em frente a pra�a");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nDetalhamento:\n");
                fprintf(file,"2 quartos, 1 banheiro social, sala e cozinha.\n");
                fprintf(file,"\nLOCADOR\n");
                fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-15s |\n", "Claudia Arraia", "(64)99999-1000");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nVALOR\n");
                fprintf(file,"Aluguel: R$ 1300,00\n");

                fclose(file);

                file2 = fopen("Casas ocupadas.txt", "a");
                fprintf(file2,"===== CASA 3 =====\n");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"| %-15s | %-25s | %-35s |\n", "Setor Central", "Avenida anhanguera", "Na esquina de frente ao pit dog");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"\nDetalhamento:\n");
                fprintf(file2,"2 quartos, 2 banheiro, sala, cozinha, garagem para 2 carros.\n");
                fprintf(file2,"\nLOCADOR\n");
                fprintf(file2,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"| %-15s | %-15s |\n", "Igor Guilherme", "(64)98676-4444");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"\nVALOR\n");
                fprintf(file2,"Aluguel: R$ 1450,00\n");
                fprintf(file2,"\nOCUPANTE\n");
                fprintf(file2,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"| %-15s | %-15s |\n", cliente.nome, cliente.telefone);
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");

                fclose(file2);

                system("cls");
                printf("[!]-------------------------PARAB�NS-------------------------[!]\n");
                printf("\n[!]O pedido de reserva dessa casa foi feito com sucesso[!]\n");
                printf("O seu pedido de reserva j� foi feito e ser� confirmado pelo locador\n");
                break;
            case 4:
                printf("\\ CASA DISPON�VEL \\:\n");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("| %-15s | %-25s | %-35s |\n", "Setor Aeroporto", "Tiradentes", "De frente ao Parque IPSG");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("\nDetalhamento:\n");
                printf("2 quartos, 1 su�te, 1 banheiro, sala, cozinha, garagem para 1 carro.\n");
                printf("\nLOCADOR\n");
                printf("| %-15s | %-15s |\n", "Nome", "Contato");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("| %-15s | %-15s |\n", "Caio Passos", "(64)99999-4567");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("\nVALOR\n");
                printf("Aluguel: R$ 1600,00\n");
                valor = 1600;
                fflush(stdin);

                printf("Insira seu nome:");
                scanf("%s", cliente.nome);
                fflush(stdin);
                printf("-----------------------------------------------------------------------------------------------\n");
                tel(cliente.telefone);
                printf("-----------------------------------------------------------------------------------------------\n");
                cpf(cliente.cpf);
                printf("-----------------------------------------------------------------------------------------------\n");

                i = 1;
                while(i == 1){
                    printf("\n Deseja inserir um coment�rio sobre a casa?");
                    printf("\n (Responda com S para sim ou N para N�O)\n");
                    scanf("%c", &com);
                        if(com == 'S' || com == 's'){
                            printf("\nDeixe seu coment�rio: ");
                            fgets(comentario, sizeof(comentario), stdin);
                            getchar();
                            fflush(stdin);
                            i = 0;
                        }else if(com == 'n' || com == 'N'){
                            i = 0;
                        }else{
                            printf("Resposta inv�lida");
                        }
                }

                printf("\nInsira o tempo de estadia(em meses) pretendido para alugar a casa: ");
                scanf("%d", &estadia);
                printf("\n[!]O valor total a ser pago para o locador ser� de: R$ %d,00 [!]\n", pagamento(estadia, valor));

                printf("\n!!Aperte ENTER para confirmar!!\n");
                getchar();
                getchar();

                file = fopen("Casas disponiveis.txt", "w");
                fprintf(file,"================== CASAS DISPON�VEIS ==================\n\n");
                fprintf(file,"===== CASA 1 =====\n");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Aeroporto", "Tocantins", "Em frente ao parque IPSG");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nDetalhamento:\n");
                fprintf(file,"2 quartos, 1 banheiro, sala, cozinha, garagem para 1 carro.\n");
                fprintf(file,"\nLOCADOR\n");
                fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-15s |\n", "Borges", "(64)92639-3926");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nVALOR\n");
                fprintf(file,"Aluguel: R$ 1200,00\n");

                fprintf(file,"\n ===== CASA 2 =====\n");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s         |\n", "Sodr�", "Andr� Luiz", "Em frente ao bar Rancho Tardezinha");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nDetalhamento:\n");
                fprintf(file,"3 quartos, 2 banheiros, sala e cozinha juntas, garagem para 1 carro.\n");
                fprintf(file,"\nLOCADOR\n");
                fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-15s |\n", "Wesley Gonzaga", "(64)92626-6262");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nVALOR\n");
                fprintf(file,"Aluguel: R$ 1400,00\n");

                fprintf(file,"\n ===== CASA 3 =====\n");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s         |\n", "Setor Central", "Avenida anhanguera", "Na esquina de frente ao pit dog");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nDetalhamento:\n");
                fprintf(file,"2 quartos, 2 banheiro, sala, cozinha, garagem para 2 carros.\n");
                fprintf(file,"\nLOCADOR\n");
                fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-15s |\n", "Igor Guilherme", "(64)98676-4444");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nVALOR\n");
                fprintf(file,"Aluguel: R$ 1450,00\n");

                fprintf(file,"\n ===== CASA 5 =====\n");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s         |\n", "Setor Central", "Avenida anhanguera", "Em frente a pra�a");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nDetalhamento:\n");
                fprintf(file,"2 quartos, 1 banheiro social, sala e cozinha.\n");
                fprintf(file,"\nLOCADOR\n");
                fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-15s |\n", "Claudia Arraia", "(64)99999-1000");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nVALOR\n");
                fprintf(file,"Aluguel: R$ 1300,00\n");

                fclose(file);

                file2 = fopen("Casas ocupadas.txt", "a");
                fprintf(file2,"===== CASA 4 =====\n");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"| %-15s | %-25s | %-35s |\n", "Setor Aeroporto", "Tiradentes", "De frente ao Parque IPSG");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"\nDetalhamento:\n");
                fprintf(file2,"2 quartos, 1 su�te, 1 banheiro, sala, cozinha, garagem para 1 carro.\n");
                fprintf(file2,"\nLOCADOR\n");
                fprintf(file2,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"| %-15s | %-15s |\n", "Caio Passos", "(64)99999-4567");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"\nVALOR\n");
                fprintf(file2,"Aluguel: R$ 1600,00\n");
                fprintf(file2,"\nOCUPANTE\n");
                fprintf(file2,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"| %-15s | %-15s |\n", cliente.nome, cliente.telefone);
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");

                fclose(file2);

                system("cls");
                printf("[!]-------------------------PARAB�NS-------------------------[!]\n");
                printf("\n[!]O pedido de reserva dessa casa foi feito com sucesso[!]\n");
                printf("O seu pedido de reserva j� foi feito e ser� confirmado pelo locador\n");
                break;
            case 5:
                printf("\\ CASA DISPON�VEL \\:\n");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("| %-15s | %-25s | %-35s |\n", "Setor Central", "Avenida anhanguera", "Em frente a pra�a");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("\nDetalhamento:\n");
                printf("2 quartos, 1 banheiro social, sala e cozinha.\n");
                printf("\nLOCADOR\n");
                printf("| %-15s | %-15s |\n", "Nome", "Contato");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("| %-15s | %-15s |\n", "Claudia Arraia", "(64)99999-1000");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("\nVALOR\n");
                printf("Aluguel: R$ 1300,00\n");
                valor = 1300;
                fflush(stdin);

                printf("Insira seu nome:");
                scanf("%s", cliente.nome);
                fflush(stdin);
                printf("-----------------------------------------------------------------------------------------------\n");
                tel(cliente.telefone);
                printf("-----------------------------------------------------------------------------------------------\n");
                cpf(cliente.cpf);
                printf("-----------------------------------------------------------------------------------------------\n");

                i = 1;
                while(i == 1){
                    printf("\n Deseja inserir um coment�rio sobre a casa?");
                    printf("\n (Responda com S para sim ou N para N�O)\n");
                    scanf("%c", &com);
                        if(com == 'S' || com == 's'){
                            printf("\nDeixe seu coment�rio: ");
                            fgets(comentario, sizeof(comentario), stdin);
                            getchar();
                            fflush(stdin);
                            i = 0;
                        }else if(com == 'n' || com == 'N'){
                            i = 0;
                        }else{
                            printf("Resposta inv�lida");
                        }
                }

                printf("\nInsira o tempo de estadia(em meses) pretendido para alugar a casa: ");
                scanf("%d", &estadia);
                printf("\n[!]O valor total a ser pago para o locador ser� de: R$ %d,00 [!]\n", pagamento(estadia, valor));

                printf("\n!!Aperte ENTER para confirmar!!\n");
                getchar();
                getchar();

                file = fopen("Casas disponiveis.txt", "w");
                fprintf(file,"================== CASAS DISPON�VEIS ==================\n\n");
                fprintf(file,"===== CASA 1 =====\n");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Aeroporto", "Tocantins", "Em frente ao parque IPSG");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nDetalhamento:\n");
                fprintf(file,"2 quartos, 1 banheiro, sala, cozinha, garagem para 1 carro.\n");
                fprintf(file,"\nLOCADOR\n");
                fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-15s |\n", "Borges", "(64)92639-3926");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nVALOR\n");
                fprintf(file,"Aluguel: R$ 1200,00\n");

                fprintf(file,"\n ===== CASA 2 =====\n");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s         |\n", "Sodr�", "Andr� Luiz", "Em frente ao bar Rancho Tardezinha");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nDetalhamento:\n");
                fprintf(file,"3 quartos, 2 banheiros, sala e cozinha juntas, garagem para 1 carro.\n");
                fprintf(file,"\nLOCADOR\n");
                fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-15s |\n", "Wesley Gonzaga", "(64)92626-6262");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nVALOR\n");
                fprintf(file,"Aluguel: R$ 1400,00\n");

                fprintf(file,"\n ===== CASA 3 =====\n");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s         |\n", "Setor Central", "Avenida anhanguera", "Na esquina de frente ao pit dog");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nDetalhamento:\n");
                fprintf(file,"2 quartos, 2 banheiro, sala, cozinha, garagem para 2 carros.\n");
                fprintf(file,"\nLOCADOR\n");
                fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-15s |\n", "Igor Guilherme", "(64)98676-4444");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nVALOR\n");
                fprintf(file,"Aluguel: R$ 1450,00\n");

                fprintf(file,"\n ===== CASA 4 =====\n");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-25s | %-35s         |\n", "Setor Aeroporto", "Tiradentes", "De frente ao Parque IPSG");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nDetalhamento:\n");
                fprintf(file,"2 quartos, 1su�te, 1 banheiro, sala, cozinha, garagem para 1 carro.\n");
                fprintf(file,"\nLOCADOR\n");
                fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"| %-15s | %-15s |\n", "Caio Passos", "(64)99999-4567");
                fprintf(file,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file,"\nVALOR\n");
                fprintf(file,"Aluguel: R$ 1600,00\n");

                fclose(file);

                file2 = fopen("Casas ocupadas.txt", "a");
                fprintf(file2,"===== CASA 5 =====\n");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"| %-15s | %-25s | %-35s |\n", "Setor Central", "Avenida anhanguera", "Em frente a pra�a");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"\nDetalhamento:\n");
                fprintf(file2,"2 quartos, 1 banheiro social, sala e cozinha.\n");
                fprintf(file2,"\nLOCADOR\n");
                fprintf(file2,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"| %-15s | %-15s |\n", "Claudia Arraia", "(64)99999-1000");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"\nVALOR\n");
                fprintf(file2,"Aluguel: R$ 1600,00\n");
                fprintf(file2,"\nOCUPANTE\n");
                fprintf(file2,"| %-15s | %-15s |\n", "Nome", "Contato");
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");
                fprintf(file2,"| %-15s | %-15s |\n", cliente.nome, cliente.telefone);
                fprintf(file2,"-----------------------------------------------------------------------------------------------\n");

                fclose(file2);

                system("cls");
                printf("[!]-------------------------PARAB�NS-------------------------[!]\n");
                printf("\n[!]O pedido de reserva dessa casa foi feito com sucesso[!]\n");
                printf("O seu pedido de reserva j� foi feito e ser� confirmado pelo locador\n");
                break;


            default:
                printf("// Op��o inv�lida. //\n ");
            }

            printf("\nPara voltar ao menu aperte 1, para sair do site aperte 0\n");
            scanf("%d", &menu);
            system("cls");
            break;
        case 2:
            // ANUNCIAR CASAS
            system("cls");

            printf("// CRIA��O DE AN�NCIO: //\n");
            printf("[!]---------------------------------------------------------------------------------------------[!]\n");
            printf("                      [!]Somente pessoas maiores de 18 anos podem anunciar moradias[!]\n");
            printf("[!]---------------------------------------------------------------------------------------------[!]\n");

            // INFORMA��ES DO LOCADOR

            char nome[50];
            getchar();
            printf("\nNome do locador: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = 0;
            fflush(stdin);
            printf("-----------------------------------------------------------------------------------------------\n");

            tel(locador.telefone);

            printf("-----------------------------------------------------------------------------------------------\n");

            cpf(locador.cpf);

            printf("-----------------------------------------------------------------------------------------------\n");

            data(&locador.dia, &locador.mes, &locador.ano);

            printf("-----------------------------------------------------------------------------------------------\n");

            // ENDERE�O DA CASA
            printf("\n!!Fa�a a descri��o da sua casa!!\n ");

            printf("\nENDERE�O\n");
            printf("-----------------------------------------------------------------------------------------------\n");

            getchar();
            printf("\nBairro: ");
            fgets(casa.bairro, sizeof(casa.bairro), stdin);
            casa.bairro[strcspn(casa.bairro, "\n")] = 0;
            fflush(stdin);

            printf("-----------------------------------------------------------------------------------------------\n");

            printf("\nRua: ");
            fgets(casa.rua, sizeof(casa.rua), stdin);
            casa.rua[strcspn(casa.rua, "\n")] = 0;
            fflush(stdin);

            printf("-----------------------------------------------------------------------------------------------\n");

            printf("\nN�mero da Casa: ");
            fgets(casa.num, sizeof(casa.num), stdin);
            fflush(stdin);

            printf("-----------------------------------------------------------------------------------------------\n");

            printf("\nComplemento: ");
            fgets(casa.compl, sizeof(casa.compl ), stdin);
            casa.compl[strcspn(casa.compl, "\n")] = 0;
            fflush(stdin);

            printf("-----------------------------------------------------------------------------------------------\n");

            printf("\nDetalhamento: ");
            fgets(casa.detl, sizeof(casa.detl), stdin);
            fflush(stdin);

            printf("-----------------------------------------------------------------------------------------------\n");

            printf("\nValor do Aluguel: ");
            printf("R$\t");
            scanf("%f", &casa.aluguel);

            printf("-----------------------------------------------------------------------------------------------\n");
            system("cls");
            printf ("          [!] Confirma��o dos Dados [!]");
            printf("\n-----------------------------------------------------------------------------------------------\n");
            printf("| %-18s | %-40s |\n", "Campo", "Valor Inserido");
            printf("-----------------------------------------------------------------------------------------------\n");
            printf("| %-18s | %-40s \n", "Bairro", casa.bairro);
            printf("| %-18s | %-40s \n", "Rua", casa.rua);
            printf("| %-18s | %-40s \n", "N�mero da Casa", casa.num);
            printf("| %-18s | %-40s \n", "Complemento", casa.compl);
            printf("| %-18s | %-40s \n", "Detalhamento", casa.detl);
            printf("| %-18s | R$ %-38.2f |\n", "Valor do Aluguel", casa.aluguel);
            printf("-----------------------------------------------------------------------------------------------\n");

            printf("\n!!Aperte ENTER para confirmar!!\n");
            getchar();
            getchar();

            file = fopen("Casas disponiveis.txt", "a");
            fprintf(file,"\n ===== CASA %d =====\n", j);
            fprintf(file,"-----------------------------------------------------------------------------------------------\n");
            fprintf(file,"| %-15s | %-25s | %-35s |\n", "Bairro", "Rua", "Complemento");
            fprintf(file,"-----------------------------------------------------------------------------------------------\n");
            fprintf(file,"| %-15s | %-25s | %-35s |\n", casa.bairro, casa.rua, casa.compl);
            fprintf(file,"-----------------------------------------------------------------------------------------------\n");
            fprintf(file,"\nDetalhamento:\n");
            fprintf(file,"%s\n", casa.detl);
            fprintf(file,"\nLOCADOR\n");
            fprintf(file,"| %-15s | %-15s |\n", "Nome", "Contato");
            fprintf(file,"-----------------------------------------------------------------------------------------------\n");
            fprintf(file,"| %-15s | %-15s |\n", nome, locador.telefone);
            fprintf(file,"-----------------------------------------------------------------------------------------------\n");
            fprintf(file,"\nVALOR\n");
            fprintf(file,"Aluguel: R$ %.2f\n", casa.aluguel);

            fclose(file);

            printf("-----------------------------------------------------------------------------------------------\n");
            system("cls");

            printf(
                "[!]-------------------------PARAB�NS-------------------------[!]\n");
            printf(
                "[!]------------Voc� anunciou sua casa com sucesso------------[!]\n");
            printf("\nPara voltar ao menu aperte 1, para sair do site aperte 0\n");
            scanf("%d", &menu);
            system("cls");
            break;
        default:
            printf("// Op��o inv�lida. //\n ");
        }
    }
    return 0;
}
