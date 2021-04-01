#pragma once
#include <iostream>
#include <string>


using namespace std;

struct TDado
{
    string autor;
    string nome;
};

template <typename T>
struct TElemento_DE
{
    TDado dado;
    TElemento_DE<T>* proximo;
    TElemento_DE<T>* anterior;
};

template <typename T>
struct TLista_DE
{
    TElemento_DE<T>* primeiro = nullptr;
    TElemento_DE<T>* ultimo = nullptr;
    int TAM = 0;
};


template <typename T>
void inicializa_list_DE(TLista_DE<T>& lista) {

    lista.primeiro = nullptr;
    lista.ultimo = nullptr;
}

template <typename T>
TElemento_DE<T>* novo_elemento_lista_D_E(T dado) {
    TElemento_DE<T>* novo_elemento = new TElemento_DE<T>;
    novo_elemento->dado = dado;
    novo_elemento->proximo = nullptr;
    return novo_elemento;
}

template <typename T>
void insere_inicio_lista_DE(TLista_DE<T>& lista, T dado) {

    TElemento_DE<T>* novo = novo_elemento_lista_D_E(dado);
    if (lista.primeiro == nullptr && lista.ultimo == nullptr) {
        novo->anterior = nullptr;
        lista.primeiro = novo;
        lista.ultimo = novo;
        lista.TAM++;
    }
    else
    {
        novo->proximo = lista.primeiro;
        lista.primeiro = novo;
        lista.TAM++;
    }

}

template <typename T>
void insere_final_DE(TLista_DE<T>& lista, T dado) {

    TElemento_DE<T>* novo = novo_elemento_lista_D_E(dado);
    if (lista.primeiro == nullptr && lista.ultimo == nullptr) {
        novo->anterior = nullptr;
        lista.primeiro = novo;
        lista.ultimo = novo;
        lista.TAM++;

    }
    else
    {
        TElemento_DE<T>* navegador = new TElemento_DE<T>;
        navegador = lista.primeiro;
        while (navegador->proximo != nullptr)
        {
            navegador = navegador->proximo;
        }
        navegador->proximo = novo;
        novo->anterior = navegador;
        lista.ultimo = novo;
        lista.TAM++;
    }

}

template <typename T>
void insere_posicao_lista_DE(TLista_DE<T>& lista, T dado, int posicao) { 

    if (posicao < 0 || posicao > lista.TAM)
    {
        cout << "posicao invalida" << endl;
    }
    else
    {


        TElemento_DE<T>* novo = novo_elemento_lista_D_E(dado);
        if (lista.primeiro == nullptr && lista.ultimo == nullptr) { //lista fazia
            novo->anterior = nullptr;
            lista.primeiro = novo;
            lista.ultimo = novo;
            lista.TAM++;
        }
        else if (posicao == 0) {
            insere_inicio_lista_DE(lista, dado); //posicao = inicio
        }
        else if (posicao == lista.TAM) //posicao = final
        {
            insere_final_DE(lista, dado);
        }
        else // posicao entre o fim e o inicio
        {
            TElemento_DE<T>* navegador = new TElemento_DE<T>;
            navegador = lista.primeiro;
            for (int i = 0; i < posicao - 1; i++)
            {
                navegador = navegador->proximo;

            }
            novo->anterior = navegador;
            novo->proximo = navegador->proximo;
            navegador->proximo = novo;
            navegador->proximo->anterior = novo;

            lista.TAM++;
        }
    }
    

}

template <typename T>
void remove_inicio_lista_DE(TLista_DE<T>& lista) {

    if (lista.primeiro == nullptr) {
        cout << "underFlow" << endl;
    }
    else
    {
        TElemento_DE<T>* temp = new TElemento_DE<T>;
        temp = lista.primeiro;

        lista.primeiro = lista.primeiro->proximo;
        delete temp;
        temp = nullptr;

        lista.TAM--;

    }

}

template <typename T>
void remove_final_lista_DE(TLista_DE<T>& lista) {

    if (lista.primeiro == nullptr) {
        cout << "underFlow" << endl;
    }
    else
    {
        /*TElemento_D_E<T>* navegador = new TElemento_D_E<T>;
        navegador = lista.primeiro;
        while (navegador->proximo != nullptr)
        {
            navegador = navegador->proximo;
        }
        navegador->anterior->proximo = nullptr;*/

        TElemento_DE<T>* temp = new TElemento_DE<T>;
        temp = lista.ultimo;
        lista.ultimo = lista.ultimo->anterior;
        lista.ultimo->proximo = nullptr;
        delete temp;
        temp = nullptr;

        lista.TAM--;

    }

}

template <typename T>
void remove_posicao_lista_DE(TLista_DE<T>& lista, int posicao) {

    if (lista.primeiro == nullptr) {
        cout << "underFlow" << endl;
    }
    else
    {
        TElemento_DE<T>* navegador = new TElemento_DE<T>;
        navegador = lista.primeiro;
        for (int i = 0; i < posicao-1; i++)
        {
            navegador = navegador->proximo;

        }
        TElemento_DE<T>* temp = new TElemento_DE<T>;
        temp = navegador->proximo;

        navegador->anterior->proximo = navegador->proximo->proximo;

        delete temp;
        temp = nullptr;

        lista.TAM--;

    }

}

template <typename T>
void imprime_lista_DE(TLista_DE<T> lista) {

    for (; lista.primeiro != nullptr; lista.primeiro = lista.primeiro->proximo)
    {
        cout << "Autor: " << lista.primeiro->dado.autor;
        cout << " // Nome: " << lista.primeiro->dado.nome << endl;
    }

}

int teste_lista_DE()
{
    TLista_DE<TDado> playlist;

    TDado x;
    x.nome = "x";
    x.autor = "xxx";
    TDado q;
    q.nome = "q";
    q.autor = "qqq";
    TDado e;
    e.nome = "e";
    e.autor = "eee";

    inicializa_list_DE(playlist);

    insere_final_DE(playlist, x);
    insere_final_DE(playlist, q);
    insere_final_DE(playlist, e);
    insere_inicio_lista_DE(playlist, e);
    remove_final_lista_DE(playlist);
    insere_posicao_lista_DE(playlist, q, 1);
    insere_posicao_lista_DE(playlist, q, 0);
    insere_posicao_lista_DE(playlist, e, 5);
    insere_posicao_lista_DE(playlist, e, 8);
    insere_posicao_lista_DE(playlist, e, -1);
    remove_inicio_lista_DE(playlist);
    remove_posicao_lista_DE(playlist, 2);




    imprime_lista_DE(playlist);
    cout << playlist.TAM << endl;
    return 0;
}
