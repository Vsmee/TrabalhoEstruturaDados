#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct TElemento_lista_estatica
{
    T dado;
};

template<typename T>
struct Tlista_esta
{
    TElemento_lista_estatica<T>* indice;
    int quantidade;
    int MAX;

};

template<typename T>
void inicializar_lista_estaticaTP(Tlista_esta<T>& lista, int capacidade) {
    lista.quantidade = 0;
    lista.indice = new TElemento_lista_estatica<T>[capacidade];
    lista.MAX = capacidade;
}

template<typename T>
void imprimir_lista_estaticaTP(Tlista_esta<T> l) {
    for (int i = 0; i < l.quantidade; i++)
    {
        cout << l.indice[i].dado << endl;
    }
};

template<typename T>
void inserir_inicio_lista_estaticaTP(Tlista_esta<T>& list, T variavel) {

    for (int i = list.quantidade; i > 0; i--)
    {
        list.indice[i].dado = list.indice[i - 1].dado;
    }

    list.indice[0].dado = variavel;
    list.quantidade++;

};

template<typename T>
void inserir_final_lista_estaticaTP(Tlista_esta<T>& list, T variavel) {

    if (list.quantidade < list.MAX) {
        list.indice[list.quantidade].dado = variavel;
        list.quantidade++;
    }
    else
    {
        cout << "lista cheia" << endl;
    }

}

template<typename T>
void inserir_posicao_lista_estaticaTP(Tlista_esta<T>& list, T variavel, int posicao) {

    for (int i = list.quantidade; i > posicao; i--)
    {
        list.indice[i].dado = list.indice[i - 1].dado;
    }

    list.indice[posicao].dado = variavel;
    list.quantidade++;

};

template<typename T>
void remover_inicio_lista_estaticaTP(Tlista_esta<T>& list) {

    for (int i = 0; i <= list.quantidade; i++)
    {
        list.indice[i].dado = list.indice[i + 1].dado;
    }

    list.quantidade--;

};

template<typename T>
void remover_fim_lista_estaticaTP(Tlista_esta<T>& list) {


    list.indice[list.quantidade - 1].dado = 0;

    list.quantidade--;

};

template<typename T>
void remover_posicao_lista_estaticaTP(Tlista_esta<T>& list, int posicao) {

    for (int i = posicao; i <= list.quantidade - 1; i++)
    {
        list.indice[i].dado = list.indice[i + 1].dado;
    }

    list.indice[list.quantidade].dado = 0;
    list.quantidade--;

}

template<typename T>
int buscar_item_lista_estaticaTP(Tlista_esta<T> list, T item) {

    for (int i = 0; i < list.quantidade; i++)
    {
        if (list.indice[i].dado == item) {
            return i;
        }
    }
    return -1;
}

/*void teste_lista_estaticaTP() {

    Tlista_esta<int> list;

    inicializar_lista_estaticaTP(list, 100);

    inserir_inicio_lista_estaticaTP(list, 1);
    inserir_inicio_lista_estaticaTP(list, 2);
    inserir_posicao_lista_estaticaTP(list, 3, 0);
    inserir_posicao_lista_estaticaTP(list, 4, 2);
    remover_inicio_lista_estaticaTP(list);
    remover_fim_lista_estaticaTP(list);
    inserir_final_lista_estaticaTP(list, 5);
    inserir_final_lista_estaticaTP(list, 6);
    remover_posicao_lista_estaticaTP(list, 1);
    remover_posicao_lista_estaticaTP(list, 2);

    cout << buscar_item_lista_estaticaTP(list, 6) << endl;

    cout << "AAAAAAA" << endl;
    cout << "quantidade lista 1: " << list.quantidade << endl;
    imprimir_lista_estaticaTP(list);

}*/
