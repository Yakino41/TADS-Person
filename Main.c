#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pessoa.h"

Pessoa *p_cria(char nome[100], int idade, char ender[100])
{
    Pessoa *p = (Pessoa *)malloc(sizeof(Pessoa));

    if (p == NULL)
    {
        printf("Erro");
        return NULL;
    }
    strcpy(p->nome, nome);
    p->idade = idade;
    strcpy(p->ender, ender);

    return p;
}

void p_acessa(Pessoa *p, char nome[100], int *idade, char ender[100])
{
    if (p == NULL)
        return;
    if (nome)
        strcpy(nome, p->nome);
    if (idade)
        *idade = p->idade;
    if (ender)
        strcpy(ender, p->ender);
}

void p_atribui(Pessoa *p, char nome[100], int idade, char ender[100])
{
    if (p == NULL)
        return;

    strcpy(p->nome, nome);
    p->idade = idade;
    strcpy(p->ender, ender);
}

void p_libera(Pessoa *p)
{
    if (p != NULL)
    {
        free(p);
        printf("Espaço Liberado\n");
    }
}

int main()
{

    char nome[100];
    int idade;
    char ender[100];
    Pessoa *lista[100]; // Lista de pessoas
    int contador = 0; // Contador de pessoas na lista
    int opcao;
    
    do{
        printf("Escolha uma opção:\n");
        printf("1 - Create person\n");
        printf("2 - Show List\n");
        printf("3 - Remove person\n");
        printf("4 - Change person\n");
        printf("5 - Exit\n");
        scanf("%d", &opcao);

        switch (opcao){
            
        case 1: // Opção para criar uma nova pessoa e adicioná-la à lista
            printf("Enter name: \n");
            getchar();               // Limpa o buffer do teclado
            fgets(nome, 100, stdin); // Lê o nome com espaços

            printf("Enter age: ");
            scanf("%d", &idade);

            printf("Enter the address: ");
            getchar();                // Limpa o buffer do teclado
            fgets(ender, 100, stdin); // Lê o endereço com espaços

            Pessoa *p = p_cria(nome, idade, ender);
            if (p == NULL)
            {
                printf("Error creating person\n");
                return 1;
            }
            lista[contador++] = p;
            break;
            
        case 2: // Option to show the list of people
        if (contador == 0){ //Checks if the list is empty
                printf("No one registered!\n");
                break;
            }
            for (int i = 0; i < contador; i++){
                p_acessa(lista[i], nome, &idade, ender);
                printf("Person %d\n Name: %s \nAge: %d \nAddress: %s", i + 1, nome, idade, ender);
            }
            break;
            
        case 3: // Option to remove a person from the list
            printf("Enter the number of the person to be removed: ");
            int num;
            scanf("%d", &num);
            if (num > 0 && num <= contador)
            {
                p_libera(lista[num - 1]);
                for (int i = num - 1; i < contador - 1; i++) // Move the remaining people to fill the empty space.
                {
                    lista[i] = lista[i + 1];
                }
                contador--;
            }
            else{
                printf("Invalid number!\n");
            }
            break;
            
        case 4: // Option to change a person's data
            printf("Enter the number of the person to be changed: ");
            scanf("%d", &num);
            if (num > 0 && num <= contador){
                printf("Enter new name: ");
                getchar();               // Clears the keyboard buffer
                fgets(nome, 100, stdin); // Read the new name with spaces.

                printf("Enter the new age: ");
                scanf("%d", &idade);

                printf("Enter the new address: ");
                getchar();                // Clears the keyboard buffer
                fgets(ender, 100, stdin); // Read the new address with spaces
                p_atribui(lista[num - 1], nome, idade, ender);
            }
            else
            {
                printf("Invalid number!\n");
            }
            break;
            
        case 5: // Option to exit the program
            printf("Leaving...\n");
            for (int i = 0; i < contador; i++)
            {
                p_libera(lista[i]);
            }
            break;
        default:
            printf("Invalid option!\n");
            break;
        }
    } while (opcao != 5);
    return 0;
}
