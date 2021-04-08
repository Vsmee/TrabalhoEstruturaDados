#pragma once

//const int TAM_lista = 80;

template<typename T>
struct TElemento_lista_estatica
{
    T dado;
};

template<typename T>
struct Tlist_estatic
{
    TElemento_lista_estatica<T>* lista;
    int quantidade;
    int MAX;

};

/*void imprimir_lista_estatica(Tlista_estatica l);

void inserir_inicio_lista_estatica(Tlista_estatica& lista, int variavel);

void inserir_final_lista_estatica(Tlista_estatica& list, int variavel);

void inserir_posicao_lista_estatica(Tlista_estatica& list, int valor, int posicao);

void remover_inicio_lista_estatica(Tlista_estatica& list);

void remover_fim_lista_estatica(Tlista_estatica& list);

void remover_posicao_lista_estatica(Tlista_estatica& list, int posicao);

int buscar_item_lista_estatica(Tlista_estatica list, int item);

void teste_lista_estatica();*/

#include <iostream>
using namespace std;

template<typename T>
void inicializar_lista_estatica(Tlist_estatic<T>& lista, int capacidade) {
    lista.quantidade = 0;
    lista.lista = new TElemento_lista_estatica<T>[capacidade];
    lista.MAX = capacidade;
}

template<typename T>
void imprimir_lista_estatica(Tlist_estatic<T> l) {
    for (int i = 0; i < l.quantidade; i++)
    {
        cout << l.lista[i].dado << endl;
    }
};

template<typename T>
void inserir_inicio_lista_estatica(Tlist_estatic<T>& list, T variavel) {

    for (int i = list.quantidade; i > 0; i--)
    {
        list.lista[i].dado = list.lista[i - 1].dado;
    }

    list.lista[0].dado = variavel;
    list.quantidade++;

};

template<typename T>
void inserir_final_lista_estatica(Tlist_estatic<T>& list, T variavel) {

    if (list.quantidade < list.MAX) {
        list.lista[list.quantidade].dado = variavel;
        list.quantidade++;
    }
    else
    {
        cout << "lista cheia" << endl;
    }

}

template<typename T>
void inserir_posicao_lista_estatica(Tlist_estatic<T>& list, T variavel, int posicao) {

    for (int i = list.quantidade; i > posicao; i--)
    {
        list.lista[i].dado = list.lista[i - 1].dado;
    }

    list.lista[posicao].dado = variavel;
    list.quantidade++;

};

template<typename T>
void remover_inicio_lista_estatica(Tlist_estatic<T>& list) {

    for (int i = 0; i <= list.quantidade; i++)
    {
        list.lista[i].dado = list.lista[i + 1].dado;
    }

    list.quantidade--;

};

template<typename T>
void remover_fim_lista_estatica(Tlist_estatic<T>& list) {


    list.lista[list.quantidade - 1].dado = 0;

    list.quantidade--;

};

template<typename T>
void remover_posicao_lista_estatica(Tlist_estatic<T>& list, int posicao) {

    for (int i = posicao; i <= list.quantidade - 1; i++)
    {
        list.lista[i].dado = list.lista[i + 1].dado;
    }

    list.lista[list.quantidade].dado = 0;
    list.quantidade--;

}

template<typename T>
int buscar_item_lista_estatica(Tlist_estatic<T> list, T item) {

    for (int i = 0; i < list.quantidade; i++)
    {
        if (list.lista[i].dado == item) {
            return i;
        }
    }
    return -1;
}

void teste_lista_estatica() {

    Tlist_estatic<int> list;

    inicializar_lista_estatica(list, 100);

    inserir_inicio_lista_estatica(list, 1);
    inserir_inicio_lista_estatica(list, 2);
    inserir_posicao_lista_estatica(list, 3, 0);
    inserir_posicao_lista_estatica(list, 4, 2);
    remover_inicio_lista_estatica(list);
    remover_fim_lista_estatica(list);
    inserir_final_lista_estatica(list, 5);
    inserir_final_lista_estatica(list, 6);
    remover_posicao_lista_estatica(list, 1);
    remover_posicao_lista_estatica(list, 2);

    cout << buscar_item_lista_estatica(list, 6) << endl;

    cout << "AAAAAAA" << endl;
    cout << "quantidade lista 1: " << list.quantidade << endl;
    imprimir_lista_estatica(list);


}
