#include <iostream>
#include "lista_estatica.h"
#include "lista_encadeada.h"
#include "lista_duplamente_encadeada.h"

const int QNT_subeventos = 10;

struct Tevento {
	string titulo;
	int data_inicio[3] = {0}; // dia/mes/ano (00/00/0000)
	int data_fim[3] = {0}; // dia/mes/ano (00/00/0000)
	int hora[3] = {0}; // sec/min/hora (00:00:00:)
	int vagas;
};

struct Tsubevento {
	string titulo;
	int data[3] = {0}; // dia/mes/ano (00/00/0000)
	int hora[3] = {-1}; // hora/min/sec (00:00:00:)
	int vagas;
};

Tevento novo_evento() {

	Tevento evento;
	cout << "--- Titulo do Evento --- " << endl;
	cout << "Titulo: ";
	cin >> evento.titulo;

	cout << "--- Data de Inicio ---" << endl;
	cout << "Dia: ";
	cin >> evento.data_inicio[0];
	while (evento.data_inicio[0] < 1 || evento.data_inicio[0] > 31)
	{
		cout << "Dia invalido, tente novamente: ";
		cin >> evento.data_inicio[0];
	}
	cout << "Mes: ";
	cin >> evento.data_inicio[1];
	while (evento.data_inicio[1] < 1 || evento.data_inicio[1] > 12)
	{
		cout << "Mes invalido, tente novamente: ";
		cin >> evento.data_inicio[1];
	}
	cout << "ano: ";
	cin >> evento.data_inicio[2];
	while (evento.data_inicio[2] < 2021)
	{
		cout << "Ano invalido, tente novamente: ";
		cin >> evento.data_inicio[2];
	}

	cout << "--- Data de Termino---"<< endl;
	cout << "Dia: ";
	cin >> evento.data_fim[0];
	while (evento.data_fim[0] < 1 || evento.data_fim[0] > 31)
	{
		cout << "Dia invalido, tente novamente: ";
		cin >> evento.data_fim[0];
	}
	cout << "Mes: ";
	cin >> evento.data_fim[1];
	while (evento.data_fim[1] < 1 || evento.data_fim[1] > 12)
	{
		cout << "Mes invalido, tente novamente: ";
		cin >> evento.data_fim[1];
	}
	cout << "ano: ";
	cin >> evento.data_fim[2];
	while (evento.data_fim[2] < 2021)
	{
		cout << "Ano invalido, tente novamente: ";
		cin >> evento.data_fim[2];
	}

	cout << "--- Horario do Evento --- " << endl;
	cout << "Hora: ";
	cin >> evento.hora[0];
	while (evento.hora[0] < 0 || evento.hora[0] > 23)
	{
		cout << "Hora invalida, tente novamente: ";
		cin >> evento.hora[0];
	}
	cout << "Minuto: ";
	cin >> evento.hora[1];
	while (evento.hora[1] < 0 || evento.hora[1] > 59)
	{
		cout << "Minuto invalido, tente novamente: ";
		cin >> evento.hora[1];
	}
	cout << "segundo: ";
	cin >> evento.hora[2];
	while (evento.hora[2] < 0 || evento.hora[2] > 59)
	{
		cout << "Segundo invalido, tente novamente: ";
		cin >> evento.hora[2];
	}

	cout << "--- Vagas --- " << endl;
	cout << "Vagas: ";
	cin >> evento.vagas;
	while (evento.vagas < 0)
	{
		cout << "Vaga invalida, tente novamente: ";
		cin >> evento.vagas;
	}
	
	return evento;

}

Tevento teste_novo_evento(int variavel) {
	Tevento evento;

	evento.titulo = "teste";
	for (int i = 0; i < 3; i++)
	{
		evento.data_fim[i] = variavel+1;
	}
	for (int i = 0; i < 3; i++)
	{
		evento.data_inicio[i] = variavel;
	}
	for (int i = 0; i < 3; i++)
	{
		evento.hora[i] = variavel;
	}
	evento.vagas = variavel * 10;
	return evento;

}

Tsubevento novo_subevento() {

	Tsubevento evento;
	cout << "--- Titulo do Subevento --- " << endl;
	cout << "Titulo: ";
	cin >> evento.titulo;

	cout << "--- Data de Inicio ---" << endl;
	cout << "Dia: ";
	cin >> evento.data[0];
	while (evento.data[0] < 1 || evento.data[0] > 31)
	{
		cout << "Dia invalido, tente novamente: ";
		cin >> evento.data[0];
	}
	cout << "Mes: ";
	cin >> evento.data[1];
	while (evento.data[1] < 1 || evento.data[1] > 12)
	{
		cout << "Mes invalido, tente novamente: ";
		cin >> evento.data[1];
	}
	cout << "ano: ";
	cin >> evento.data[2];
	while (evento.data[2] < 2021)
	{
		cout << "Ano invalido, tente novamente: ";
		cin >> evento.data[2];
	}
	
	cout << "--- Horario do Evento --- " << endl;
	cout << "Hora: ";
	cin >> evento.hora[0];
	while (evento.hora[0] < 0 || evento.hora[0] > 23)
	{
		cout << "Hora invalida, tente novamente: ";
		cin >> evento.hora[0];
	}
	cout << "Minuto: ";
	cin >> evento.hora[1];
	while (evento.hora[1] < 0 || evento.hora[1] > 59)
	{
		cout << "Minuto invalido, tente novamente: ";
		cin >> evento.hora[1];
	}
	cout << "segundo: ";
	cin >> evento.hora[2];
	while (evento.hora[2] < 0 || evento.hora[2] > 59)
	{
		cout << "Segundo invalido, tente novamente: ";
		cin >> evento.hora[2];
	}

	cout << "--- Vagas --- " << endl;
	cout << "Vagas: ";
	cin >> evento.vagas;
	while (evento.vagas < 0)
	{
		cout << "Vaga invalida, tente novamente: ";
		cin >> evento.vagas;
	}

	return evento;

}

Tsubevento teste_novo_subevento(int variavel) {
	Tsubevento evento;

	evento.titulo = "teste subevento";
	for (int i = 0; i < 3; i++)
	{
		evento.data[i] = variavel;
	}
	for (int i = 0; i < 3; i++)
	{
		evento.hora[i] = variavel;
	}
	evento.vagas = variavel * 10;
	return evento;

}

using namespace std;

int main()
{
	TLista_DE<Tevento> lista_eventos;
	inicializa_list_DE(lista_eventos);

	//Tevento show1 = novo_evento();
	//Tsubevento sub1 = novo_subevento();

	Tevento event1 = teste_novo_evento(1);
	Tsubevento sub1 = teste_novo_subevento(2);

	insere_inicio_lista_DE(lista_eventos, event1);
	cout << lista_eventos.primeiro->dado.titulo << endl;


	//teste_lista_estatica();
	//teste_lista_encadeada();
	//teste_lista_DE();


}

