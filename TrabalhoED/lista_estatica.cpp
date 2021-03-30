#include <iostream>
#include "lista_estatica.h"

using namespace std;


void imprimir_lista(Tlista_estatica l) {
    for (int i = 0; i < l.quantidade; i++)
    {
        cout << l.lista[i] << endl;
    }
};

void inserir_inicio_listaE(Tlista_estatica& list, int variavel) {

    for (int i = list.quantidade; i > 0; i--)
    {
        list.lista[i] = list.lista[i - 1];
    }

    list.lista[0] = variavel;
    list.quantidade++;

};

void inserir_final_listaE(Tlista_estatica& list, int variavel) {

    if (list.quantidade < TAM_lista) {
        list.lista[list.quantidade] = variavel;
        list.quantidade++;
    }
    else
    {
        cout << "lista cheia" << endl;
    }

}

void inserir_posicao_listaE(Tlista_estatica& list, int valor, int posicao) {

    for (int i = list.quantidade; i > posicao; i--)
    {
        list.lista[i] = list.lista[i - 1];
    }

    list.lista[posicao] = valor;
    list.quantidade++;

};

void remover_inicio_listaE(Tlista_estatica& list) {

    for (int i = 0; i <= list.quantidade; i++)
    {
        list.lista[i] = list.lista[i + 1];
    }

    list.quantidade--;

};

void remover_fim_listaE(Tlista_estatica& list) {


    list.lista[list.quantidade - 1] = 0;

    list.quantidade--;

};

void remover_posicao_listaE(Tlista_estatica& list, int posicao) {

    for (int i = posicao; i <= list.quantidade-1; i++)
    {
        list.lista[i] = list.lista[i + 1];
    }

    list.lista[list.quantidade] = 0;
    list.quantidade--;

}

int buscar_item_listaE(Tlista_estatica list, int item) {

    for (int i = 0; i < list.quantidade; i++)
    {
        if (list.lista[i] == item) {
            return i;
        }
    }
    return -1;
}

void teste_listaE() {

    
    Tlista_estatica list;

    inserir_inicio_listaE(list, 1);
    inserir_inicio_listaE(list, 2);
    inserir_posicao_listaE(list, 3, 0);
    inserir_posicao_listaE(list, 4, 2);
    remover_inicio_listaE(list);
    remover_fim_listaE(list);
    inserir_final_listaE(list, 5);
    inserir_final_listaE(list, 6);
    remover_posicao_listaE(list, 1);
    remover_posicao_listaE(list, 2);

    cout << buscar_item_listaE(list, 6) << endl;


    cout << "quantidade lista 1: " << list.quantidade << endl;
    imprimir_lista(list);
 

}