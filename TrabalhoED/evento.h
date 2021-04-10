#pragma once
#include <iostream>
using namespace std;

const int QNT_subevento = 10;

template <typename Tsub>
struct Tevento {
	string titulo;
	int data_inicio[3] = { 0 }; // dia/mes/ano (00/00/0000)
	int data_fim[3] = { 0 }; // dia/mes/ano (00/00/0000)
	int hora[3] = { 0 }; // sec/min/hora (00:00:00:)
	int vagas;
	Tlista_esta<Tsub> lista_subevento;

};

struct Tsubevento {
	string titulo;
	int data[3] = { 0 }; // dia/mes/ano (00/00/0000)
	int hora[3] = { -1 }; // hora/min/sec (00:00:00:)
	int vagas;
};

template <typename Tsub>
Tevento<Tsub> novo_evento() {

	Tevento<Tsubevento> evento;
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

	cout << "--- Data de Termino---" << endl;
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

template <typename Tevent>
Tevento<Tevent> teste_novo_evento(int variavel) {
	Tevento<Tevent> evento;

	evento.titulo = "teste";
	for (int i = 0; i < 3; i++)
	{
		evento.data_fim[i] = variavel + 1;
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
