#ifndef PESSOA_H
#define PESSOA_H

struct Pessoa{

    char nome[100];
    int idade;
    char ender[100];
};

typedef struct Pessoa Pessoa;

Pessoa* p_cria(char nome[100], int idade, char ender[100]);

void p_acessa(Pessoa* p, char nome[100], int* idade, char ender[100]);

void p_atribui(Pessoa* p, char nome[100], int idade, char ender[100]);

void p_libera(Pessoa* p);

#endif