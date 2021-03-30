#pragma once

const int TAM_lista = 80;
const int QNT_lista = 79;

struct Tlista_estatica
{
    int lista[TAM_lista];
    int quantidade = 0;
};

void imprimir_lista(Tlista_estatica l);

void inserir_inicio_listaE(Tlista_estatica& lista, int variavel);

void inserir_posicao_listaE(Tlista_estatica& list, int valor, int posicao);

void remover_inicio_listaE(Tlista_estatica& list);

void remover_fim_listaE(Tlista_estatica& list);

void teste_listaE();


