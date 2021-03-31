#pragma once

#include <iostream>

using namespace std;


struct TMusica
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
    TElemento_encadeado<T>* inicio;

};

template<typename T>
void inicializa_lista(TLista_encadeada<T>& lista) {
    lista.inicio = nullptr;
};

template<typename T>
TElemento_encadeado<T>* novo_elemento(T dado) {

    TElemento_encadeado<T>* novo = new TElemento_encadeado<T>;
    novo->dado = dado;
    novo->proximo = nullptr;

    return novo;
}

template<typename T>
void insere_no_final(TLista_encadeada<T>& lista, T dado) {

    TElemento_encadeado<T>* novo = novo_elemento(dado);

    if (lista.inicio == nullptr) { // Quando a lista estivar vazio
        lista.inicio = novo;
    }
    else // QUando n estiver vazia
    {
        TElemento_encadeado<T>* navegador = lista.inicio;
        while (navegador->proximo != nullptr)
        {
            navegador = navegador->proximo;
        }
        navegador->proximo = novo;

    }

}

template<typename T>
void remover_inicio_lista(TLista_encadeada<T>& lista) {

    if (lista.inicio == nullptr) {
        throw "List Underflow";
    }
    TElemento_encadeado<T>* temp = lista.inicio;
    lista.inicio = lista.inicio->proximo;
    delete temp;


};


void imprimir_dado(int dado) {
    cout << "Dado: " << dado << endl;

}

void imprimir_dado(TMusica dado) {
    cout << "Autor: " << dado.autor;
    cout << "// Musica: " << dado.nome << endl;

}

template<typename T>
void execultar_lista_encadeada(TLista_encadeada<T> lista) {

    TLista_encadeada<T> navegador = lista;
    while (navegador.inicio != nullptr)
    {

        imprimir_dado(navegador.inicio->dado);

        navegador.inicio = navegador.inicio->proximo;

    }

};

int teste_lista_encadeada()
{
    TLista_encadeada<TMusica> playlist;

    TMusica x;
    x.autor = "x";
    x.nome = "xxx";
    TMusica e;
    e.autor = "e";
    e.nome = "eee";
    TMusica q;
    q.autor = "q";
    q.nome = "qqq";

    inicializa_lista(playlist);
    insere_no_final(playlist, x);
    insere_no_final(playlist, e);
    insere_no_final(playlist, q);


    try
    {
        remover_inicio_lista(playlist);
        remover_inicio_lista(playlist);
        //remover_inicio_lista(playlist);
        //remover_inicio_lista(playlist);
        execultar_lista_encadeada(playlist);

    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }




    return 0;
};

