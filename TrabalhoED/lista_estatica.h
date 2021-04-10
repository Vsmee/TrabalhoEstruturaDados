/*#include <iostream>
#include "evento.h"

using namespace std;

struct Tlista_estatica{
    int quantidade;
    int lista[10];
};

void imprimir_lista_estatica(Tevento l) {
    for (int i = 0; i < l.quantidade_subeventos; i++)
    {
        cout << l.lista_subevento[i].data << endl;
    }
};

void inserir_inicio_lista_estatica(Tevento& list, Tsubevento variavel) {

    for (int i = list.quantidade_subeventos; i > 0; i--)
    {
        list.lista_subevento [i] = list.lista_subevento [i - 1];
    }

    list.lista_subevento [0] = variavel;
    list.quantidade_subeventos++;

};

void inserir_final_lista_estatica(Tevento& list, Tsubevento variavel) {

    if (list.quantidade_subeventos < QNT_subevento) {
        list.lista_subevento [list.quantidade_subeventos] = variavel;
        list.quantidade_subeventos++;
    }
    else
    {
        cout << "lista cheia" << endl;
    }

}

void inserir_posicao_lista_estatica(Tevento& list, Tsubevento valor, int posicao) {

    for (int i = list.quantidade_subeventos; i > posicao; i--)
    {
        list.lista_subevento[i] = list.lista_subevento[i - 1];
    }

    list.lista_subevento[posicao] = valor;
    list.quantidade_subeventos++;

};

void remover_inicio_lista_estatica(Tevento& list) {

    for (int i = 0; i <= list.quantidade_subeventos; i++)
    {
        list.lista_subevento[i] = list.lista_subevento[i + 1];
    }

    list.quantidade_subeventos--;

};

void remover_fim_lista_estatica(Tevento& list) {


    list.lista_subevento[list.quantidade_subeventos - 1]* = NULL;

    list.quantidade_subeventos--;

};

void remover_posicao_lista_estatica(Tevento& list, int posicao) {

    for (int i = posicao; i <= list.quantidade_subeventos - 1; i++)
    {
        list.lista_subevento[i] = list.lista_subevento[i + 1];
    }

    list.lista_subevento[list.quantidade_subeventos] = 0;
    list.quantidade_subeventos--;

}

int buscar_item_lista_estatica(Tevento list, Tsubevento item) {

    for (int i = 0; i < list.quantidade_subeventos; i++)
    {
        if (list.lista_subevento[i].titulo == item.titulo) {
            return i;
        }
    }
    return -1;
}*/