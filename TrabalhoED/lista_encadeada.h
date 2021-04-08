#pragma once

#include <iostream>

using namespace std;


struct Tdado
{
    string autor;
    string nome;

};

template<typename T>
struct TElemento_encadeado
{
    T dado;
    TElemento_encadeado<T>* proximo;
};

template<typename T>
struct TLista_encadeada {
    TElemento_encadeado<T>* primeiro;
    int TAM = 0;

};

template<typename T>
void inicializa_lista(TLista_encadeada<T>& lista) {
    lista.primeiro = nullptr;
};

template<typename T>
TElemento_encadeado<T>* novo_elemento_encadeado(T dado) {

    TElemento_encadeado<T>* novo = new TElemento_encadeado<T>;
    novo->dado = dado;
    novo->proximo = nullptr;

    return novo;
}

template<typename T>
void insere_no_inicio_lista_encadeada(TLista_encadeada<T>& lista, T dado) {

    TElemento_encadeado<T>* novo = novo_elemento_encadeado(dado);

    if (lista.primeiro == nullptr) { // Quando a lista estiver vazia
        lista.primeiro = novo;
    }
    else // QUando n estiver vazia
    {
        novo->proximo = lista.primeiro;
        lista.primeiro = novo;  
    }
    lista.TAM++;

}

template<typename T>
void insere_no_final_lista_encadeada(TLista_encadeada<T>& lista, T dado) {

    TElemento_encadeado<T>* novo = novo_elemento_encadeado(dado);

    if (lista.primeiro == nullptr) { // Quando a lista estiver vazia
        lista.primeiro = novo;

    }
    else // QUando n estiver vazia
    {
        TElemento_encadeado<T>* navegador = lista.primeiro;
        while (navegador->proximo != nullptr)
        {
            navegador = navegador->proximo;
        }
        navegador->proximo = novo;


    }
    lista.TAM++;

}

template<typename T>
void insere_na_posicao_lista_encadeada(TLista_encadeada<T>& lista, T dado, int posicao){

    TElemento_encadeado<T>* novo = novo_elemento_encadeado(dado);

    if (lista.primeiro == nullptr) { // Quando a lista estivar vazio
        lista.primeiro = novo;

    }
    else // QUando n estiver vazia
    {
        TElemento_encadeado<T>* navegador = lista.primeiro;
        for (int i = 0; i < posicao-1; i++)
        {
            navegador = navegador->proximo;

        }
        novo->proximo = navegador->proximo;
        navegador->proximo = novo;
    }
    lista.TAM++;

}

template<typename T>
void remover_inicio_lista_encadeada(TLista_encadeada<T>& lista) {

    if (lista.primeiro == nullptr) {
        throw "List Underflow";
    }
    TElemento_encadeado<T>* temp = lista.primeiro;
    lista.primeiro = lista.primeiro->proximo;
    delete temp;
    lista.TAM--;

};

template<typename T>
void remover_final_lista_encadeada(TLista_encadeada<T>& lista) {

    if (lista.primeiro == nullptr) {
        throw "List Underflow";
    }

    TElemento_encadeado<T>* navegador = lista.primeiro;
    while (navegador->proximo->proximo != nullptr)
    {
        navegador = navegador->proximo;
    }
    TElemento_encadeado<T>* temp = navegador->proximo;
    navegador->proximo = nullptr;
    delete temp;
    lista.TAM--;

};

template<typename T>
void remover_posicao_lista_encadeada(TLista_encadeada<T>& lista, int posicao) {

    if (lista.primeiro == nullptr) {
        throw "List Underflow";
    }
    TElemento_encadeado<T>* navegador = lista.primeiro;
    for (int i = 0; i < posicao - 1; i++)
    {
        navegador = navegador->proximo;

    }
    TElemento_encadeado<T>* temp = navegador->proximo;
    navegador->proximo = navegador->proximo->proximo;
    delete temp;
    lista.TAM--;

};

void imprimir_dado(int dado) {
    cout << "Dado: " << dado << endl;

}

void imprimir_dado(Tdado dado) {
    cout << "Autor: " << dado.autor;
    cout << "// Musica: " << dado.nome << endl;

}

template<typename T>
void imprimir_lista_encadeada(TLista_encadeada<T> lista) {


    TLista_encadeada<T> navegador = lista;
    while (navegador.primeiro != nullptr)
    {

        imprimir_dado(navegador.primeiro->dado);

        navegador.primeiro = navegador.primeiro->proximo;

    }

};

template <typename T>
T obter_item_lista_encadeada(TLista_encadeada<T> lista, int indice) {

    if ((indice < 0) || (indice > lista.TAM) || (lista.primeiro == nullptr)) // fora do indice ou lista fazia
    {
        return lista.primeiro->dado; // tem q arrumar
    }
    else
    {
        TElemento_encadeado<T>* navegador = new TElemento_encadeado<T>;
        navegador = lista.primeiro;
        for (int i = 0; i < indice; i++)
        {
            navegador = navegador->proximo;

        }
        return navegador->dado;
    }


}

template <typename T>
bool buscar_item_lista_encadeada(TLista_encadeada<T> lista, Tdado item) {

    TElemento_encadeado<T>* navegador = new TElemento_encadeado<T>;
    navegador = lista.primeiro;
    while (navegador->proximo != nullptr)
    {
        if (navegador->dado.autor == item.autor && navegador->dado.nome == item.nome)
        {
            return true;
        }
        navegador = navegador->proximo;
    }
    return false;
}

template <typename T>
int buscar_indice_lista_encadeada(TLista_encadeada<T> lista, Tdado item) {

    int indice = 0;
    TElemento_encadeado<T>* navegador = new TElemento_encadeado<T>;
    navegador = lista.primeiro;
    while (navegador != nullptr)
    {
        if ((navegador->dado.autor == item.autor) && (navegador->dado.nome == item.nome))
        {
            return indice;
        }
        navegador = navegador->proximo;
        indice++;
    }
    return -1;
}

int teste_lista_encadeada()
{
    TLista_encadeada<Tdado> playlist;

    Tdado x;
    x.autor = "x";
    x.nome = "xxx";
    Tdado e;
    e.autor = "e";
    e.nome = "eee";
    Tdado q;
    q.autor = "q";
    q.nome = "qqq";

    inicializa_lista(playlist);
    insere_no_final_lista_encadeada(playlist, x);
    insere_no_final_lista_encadeada(playlist, e);
    insere_no_final_lista_encadeada(playlist, q);
    insere_no_inicio_lista_encadeada(playlist, q);
    insere_na_posicao_lista_encadeada(playlist, q, 2);


    try
    {
        
        remover_inicio_lista_encadeada(playlist);
        remover_final_lista_encadeada(playlist);
        remover_posicao_lista_encadeada(playlist, 1);
        imprimir_lista_encadeada(playlist);

    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }

    cout << obter_item_lista_encadeada(playlist, 0).autor << endl;
    cout << buscar_item_lista_encadeada(playlist, e) << endl;
    cout << buscar_indice_lista_encadeada(playlist, e) << endl;


    return 0;
};
