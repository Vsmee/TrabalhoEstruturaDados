#pragma once
#include <iostream>
using namespace std;

const int QNT_subevento = 10;

struct TData {
	int dia = 0;
	int mes = 0;
	int ano = 0;
};

struct THoras
{
	int hora = 0;
	int minuto = 0;
	int segundo = 0;
};

template <typename Tsub>
struct Tevento {
	string titulo;
	TData data_inicio; // dia/mes/ano (00/00/0000)
	TData data_fim; // dia/mes/ano (00/00/0000)
	THoras hora; // sec/min/hora (00:00:00:)
	int vagas;
	Tlista_esta<Tsub> lista_subevento;

};

struct Tsubevento {
	string titulo;
	TData data; // dia/mes/ano (00/00/0000)
	THoras hora; // hora/min/sec (00:00:00:)
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
	cin >> evento.data_inicio.dia;
	while (evento.data_inicio.dia < 1 || evento.data_inicio.dia > 31)
	{
		cout << "Dia invalido, tente novamente: ";
		cin >> evento.data_inicio.dia;
	}
	cout << "Mes: ";
	cin >> evento.data_inicio.mes;
	while (evento.data_inicio.mes < 1 || evento.data_inicio.mes > 12)
	{
		cout << "Mes invalido, tente novamente: ";
		cin >> evento.data_inicio.mes;
	}
	cout << "ano: ";
	cin >> evento.data_inicio.ano;
	while (evento.data_inicio.ano < 2021)
	{
		cout << "Ano invalido, tente novamente: ";
		cin >> evento.data_inicio.ano;
	}

	cout << "--- Data de Termino---" << endl;
	cout << "Dia: ";
	cin >> evento.data_fim.dia;
	while (evento.data_fim.dia < 1 || evento.data_fim.dia > 31)
	{
		cout << "Dia invalido, tente novamente: ";
		cin >> evento.data_fim.dia;
	}
	cout << "Mes: ";
	cin >> evento.data_fim.mes;
	while (evento.data_fim.mes < 1 || evento.data_fim.mes > 12)
	{
		cout << "Mes invalido, tente novamente: ";
		cin >> evento.data_fim.mes;
	}
	cout << "ano: ";
	cin >> evento.data_fim.ano;
	while (evento.data_fim.ano < 2021)
	{
		cout << "Ano invalido, tente novamente: ";
		cin >> evento.data_fim.ano;
	}

	cout << "--- Horario do Evento --- " << endl;
	cout << "Hora: ";
	cin >> evento.hora.hora;
	while (evento.hora.hora < 0 || evento.hora.hora > 23)
	{
		cout << "Hora invalida, tente novamente: ";
		cin >> evento.hora.hora;
	}
	cout << "Minuto: ";
	cin >> evento.hora.minuto;
	while (evento.hora.minuto < 0 || evento.hora.minuto > 59)
	{
		cout << "Minuto invalido, tente novamente: ";
		cin >> evento.hora.minuto;
	}
	cout << "segundo: ";
	cin >> evento.hora.segundo;
	while (evento.hora.segundo < 0 || evento.hora.segundo > 59)
	{
		cout << "Segundo invalido, tente novamente: ";
		cin >> evento.hora.segundo;
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
	cin >> evento.data.dia;
	while (evento.data.dia < 1 || evento.data.dia > 31)
	{
		cout << "Dia invalido, tente novamente: ";
		cin >> evento.data.dia;
	}
	cout << "Mes: ";
	cin >> evento.data.mes;
	while (evento.data.mes < 1 || evento.data.mes > 12)
	{
		cout << "Mes invalido, tente novamente: ";
		cin >> evento.data.mes;
	}
	cout << "ano: ";
	cin >> evento.data.ano;
	while (evento.data.ano < 2021)
	{
		cout << "Ano invalido, tente novamente: ";
		cin >> evento.data.ano;
	}

	cout << "--- Horario do Evento --- " << endl;
	cout << "Hora: ";
	cin >> evento.hora.hora;
	while (evento.hora.hora < 0 || evento.hora.hora > 23)
	{
		cout << "Hora invalida, tente novamente: ";
		cin >> evento.hora.hora;
	}
	cout << "Minuto: ";
	cin >> evento.hora.minuto;
	while (evento.hora.minuto < 0 || evento.hora.minuto > 59)
	{
		cout << "Minuto invalido, tente novamente: ";
		cin >> evento.hora.minuto;
	}
	cout << "segundo: ";
	cin >> evento.hora.segundo;
	while (evento.hora.segundo < 0 || evento.hora.segundo > 59)
	{
		cout << "Segundo invalido, tente novamente: ";
		cin >> evento.hora.segundo;
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
	evento.data_inicio.ano = variavel;
	evento.data_inicio.dia = variavel;
	evento.data_inicio.mes = variavel;

	evento.data_fim.ano = variavel;
	evento.data_fim.dia = variavel;
	evento.data_fim.mes = variavel;

	evento.hora.hora = variavel;
	evento.hora.minuto = variavel;
	evento.hora.segundo = variavel;
	evento.vagas = variavel * 10;
	return evento;

}

Tsubevento teste_novo_subevento(int variavel) {
	Tsubevento evento;

	evento.titulo = "teste subevento";

	evento.data.ano = variavel;
	evento.data.dia = variavel;
	evento.data.mes = variavel;

	evento.hora.hora = variavel;
	evento.hora.minuto = variavel;
	evento.hora.segundo = variavel;

	evento.vagas = variavel * 10;
	return evento;

}
