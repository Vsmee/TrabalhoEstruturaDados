#pragma once

const int TAM_lista = 80;


struct Tlista_estatica
{
    int lista[TAM_lista];
    int quantidade = 0;
};

void imprimir_lista_estatica(Tlista_estatica l);

void inserir_inicio_lista_estatica(Tlista_estatica& lista, int variavel);

void inserir_final_lista_estatica(Tlista_estatica& list, int variavel);

void inserir_posicao_lista_estatica(Tlista_estatica& list, int valor, int posicao);

void remover_inicio_lista_estatica(Tlista_estatica& list);

void remover_fim_lista_estatica(Tlista_estatica& list);

void remover_posicao_lista_estatica(Tlista_estatica& list, int posicao);

int buscar_item_lista_estatica(Tlista_estatica list, int item);

void teste_lista_estatica();


