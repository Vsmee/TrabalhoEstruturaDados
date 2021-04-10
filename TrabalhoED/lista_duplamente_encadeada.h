#pragma once
#include <iostream>


using namespace std;

struct TDado
{
    string autor;
    string nome;
};

template <typename T>
struct TElemento_DE
{
    T dado;
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
TElemento_DE<T>* novo_elemento_lista_DE(T dado) {
    TElemento_DE<T>* novo_elemento = new TElemento_DE<T>;
    novo_elemento->dado = dado;
    novo_elemento->proximo = nullptr;
    return novo_elemento;
}

template <typename T>
void insere_inicio_lista_DE(TLista_DE<T>& lista, T dado) {

    TElemento_DE<T>* novo = novo_elemento_lista_DE(dado);
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
void insere_final_lista_DE(TLista_DE<T>& lista, T dado) {

    TElemento_DE<T>* novo = novo_elemento_lista_DE(dado);
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


        TElemento_DE<T>* novo = novo_elemento_lista_DE(dado);
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
            insere_final_lista_DE(lista, dado);
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

    if (lista.primeiro == nullptr || lista.ultimo == nullptr) {
        cout << "underFlow" << endl;
    }
    else
    {
        /*TElemento_DE<T>* navegador = new TElemento_DE<T>;
        navegador = lista.primeiro;
        while (navegador->proximo != nullptr)
        {
            navegador = navegador->proximo;
        }
        navegador->anterior->proximo = nullptr;*/

        TElemento_DE<T>* temp = new TElemento_DE<T>;
        temp = lista.ultimo;
        lista.ultimo->anterior->proximo = nullptr;
        lista.ultimo = lista.ultimo->anterior;
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
    else if (posicao < 0 || posicao > lista.TAM)
    {
        cout << "posicao invalida" << endl;
    }
    else if (posicao == 0) {
        remove_inicio_lista_DE(lista); //posicao = inicio
    }
    else if (posicao == lista.TAM - 1) //posicao = final
    {
        remove_final_lista_DE(lista);
    }
    else
    {
        TElemento_DE<T>* navegador = new TElemento_DE<T>;
        navegador = lista.primeiro;
        for (int i = 0; i < posicao-1; i++)
        {
            navegador = navegador->proximo;


        }
        //TElemento_DE<T>* temp = new TElemento_DE<T>;
        //temp = navegador;
        navegador->proximo->proximo->anterior = navegador;
        navegador->proximo = navegador->proximo->proximo;
        //delete temp;
        //temp = nullptr;

        lista.TAM--;

    }

}

template <typename T>
void imprime_lista_DE(TLista_DE<T> lista) {

    if (lista.primeiro == nullptr) {
        throw "List Underflow";
    }
    TElemento_DE<T>* navegadorr = new TElemento_DE<T>;
    navegadorr = lista.primeiro;
    while (navegadorr != nullptr)
    {

        cout << "Autor: " << navegadorr->dado.autor;
        cout << " // Nome: " << navegadorr->dado.nome << endl;
        navegadorr = navegadorr->proximo;
    }


}

template <typename T>
T obter_item_lista_DE(TLista_DE<T> lista, int indice) {

     if ((indice < 0) || (indice > lista.TAM) || (lista.primeiro == nullptr && lista.ultimo == nullptr)) // fora do indice ou lista fazia
    {
         return lista.primeiro->dado; // tem q arrumar
    }
     else
     {
             TElemento_DE<T>* navegador = new TElemento_DE<T>;
             navegador = lista.primeiro;
             for (int i = 0; i < indice; i++)
             {
                 navegador = navegador->proximo;

             }
             return navegador->dado;
     }


}

template <typename T>
bool buscar_item_lista_DE(TLista_DE<T> lista, TDado item) {

    TElemento_DE<T>* navegador = new TElemento_DE<T>;
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
int buscar_indice_lista_DE(TLista_DE<T> lista, TDado item) {

    int indice = 0;
    TElemento_DE<T>* navegador = new TElemento_DE<T>;
    navegador = lista.primeiro;
    while (navegador != nullptr)
    {
        if (navegador->dado.autor == item.autor && navegador->dado.nome == item.nome)
        {
            return indice;
        }
        navegador = navegador->proximo;
        indice++;
    }
    return -1;
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

    

    insere_final_lista_DE(playlist, x);
    insere_final_lista_DE(playlist, q);
    insere_final_lista_DE(playlist, e);
    insere_posicao_lista_DE(playlist, q, 1);
    insere_posicao_lista_DE(playlist, q, 0);
    insere_posicao_lista_DE(playlist, e, 5);
    insere_posicao_lista_DE(playlist, e, 8);
    insere_posicao_lista_DE(playlist, e, -1);

    try
    {
        remove_final_lista_DE(playlist);
        remove_inicio_lista_DE(playlist);
        remove_posicao_lista_DE(playlist, 1);
        imprime_lista_DE(playlist);
        cout << playlist.TAM << endl;
        cout << "--------------------------" << endl;
        cout << buscar_item_lista_DE(playlist, q) << endl;
        cout << obter_item_lista_DE(playlist, 0).autor << endl;
        cout << buscar_indice_lista_DE(playlist, q) << endl;
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }



    return 0;
}
