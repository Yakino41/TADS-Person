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
        printf("1 - Criar pessoa\n");
        printf("2 - Mostrar Lista\n");
        printf("3 - Remover pessoa\n");
        printf("4 - alterar pessoa\n");
        printf("5 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao){
            
        case 1: // Opção para criar uma nova pessoa e adicioná-la à lista
            printf("Digite o nome: \n");
            getchar();               // Limpa o buffer do teclado
            fgets(nome, 100, stdin); // Lê o nome com espaços

            printf("Digite a idade: ");
            scanf("%d", &idade);

            printf("Digite o endereço: ");
            getchar();                // Limpa o buffer do teclado
            fgets(ender, 100, stdin); // Lê o endereço com espaços

            Pessoa *p = p_cria(nome, idade, ender);
            if (p == NULL)
            {
                printf("Erro ao criar pessoa\n");
                return 1;
            }
            lista[contador++] = p;
            break;
            
        case 2: // Opção para mostrar a lista de pessoas
        if (contador == 0){ //Verifica se a lista está vazia
                printf("Nenhuma pessoa cadastrada!\n");
                break;
            }
            for (int i = 0; i < contador; i++){
                p_acessa(lista[i], nome, &idade, ender);
                printf("Pessoa %d\n Nome: %s \nIdade: %d \nEndereço: %s", i + 1, nome, idade, ender);
            }
            break;
            
        case 3: // Opção para remover uma pessoa da lista
            printf("Digite o número da pessoa a ser removida: ");
            int num;
            scanf("%d", &num);
            if (num > 0 && num <= contador)
            {
                p_libera(lista[num - 1]);
                for (int i = num - 1; i < contador - 1; i++) // Desloca as pessoas restantes para preencher o espaço vazio
                {
                    lista[i] = lista[i + 1];
                }
                contador--;
            }
            else{
                printf("Número inválido!\n");
            }
            break;
            
        case 4: // Opção para alterar os dados de uma pessoa
            printf("Digite o número da pessoa a ser alterada: ");
            scanf("%d", &num);
            if (num > 0 && num <= contador){
                printf("Digite o novo nome: ");
                getchar();               // Limpa o buffer do teclado
                fgets(nome, 100, stdin); // Lê o novo nome com espaços

                printf("Digite a nova idade: ");
                scanf("%d", &idade);

                printf("Digite o novo endereço: ");
                getchar();                // Limpa o buffer do teclado
                fgets(ender, 100, stdin); // Lê o novo endereço com espaços
                p_atribui(lista[num - 1], nome, idade, ender);
            }
            else
            {
                printf("Número inválido!\n");
            }
            break;
            
        case 5: // Opção para sair do programa
            printf("Saindo...\n");
            for (int i = 0; i < contador; i++)
            {
                p_libera(lista[i]);
            }
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (opcao != 5);
    return 0;
}