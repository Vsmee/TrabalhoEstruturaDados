#include <iostream>
#include "lista_estatica.h"
#include "lista_encadeada.h"
#include "lista_duplamente_encadeada.h"

const int QNT_subeventos = 10;

struct evento {
	string titulo;
	int data_inicio[3] = {0}; // dia/mes/ano (00/00/0000)
	int data_fim[3] = {0}; // dia/mes/ano (00/00/0000)
	int hora[3] = {0}; // sec/min/hora (00:00:00:)
	int vagas;
};

struct subevento {
	string titulo;
	int data[3] = {0}; // dia/mes/ano (00/00/0000)
	int hora[3] = {0}; // sec/min/hora (00:00:00:)
	int vagas;
};

using namespace std;

int main()
{
	TLista_DE<evento> lista_eventos;



	//teste_lista_estatica();
	//teste_lista_encadeada();
	//teste_lista_DE();


}

