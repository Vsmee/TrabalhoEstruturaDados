#include <iostream>
#include "lista_estatica_template.h"
#include "lista_encadeada.h"
#include "lista_duplamente_encadeada.h"
#include "evento.h"

using namespace std;

void mostrar_menu(int& menu) {

	cout << "###################################" << endl;
	cout << "###################################" << endl;
	cout << "##### 0- Sair do Menu         #####" << endl;
	cout << "##### 1- Criar Evento         #####" << endl;
	cout << "##### 2- Criar Subevento      #####" << endl;
	cout << "##### 3- Visualizar Eventos   #####" << endl;
	cout << "#####                         #####" << endl;
	cout << "#####                         #####" << endl;
	cout << "###################################" << endl;
	cout << "###################################" << endl;
	cout << "comando: ";
	cin >> menu;

}

void mostrar_eventos_listados(TLista_DE<Tevento> lista_eventos) {

	int i = 0;
	cout << "Eventos Disponiveis: " << endl;
	TElemento_DE<Tevento>* navegador = lista_eventos.primeiro;
	i++;
	cout << i << "- " << navegador->dado.titulo << endl;
	while (navegador->proximo != nullptr)
	{
		navegador = navegador->proximo;
		i++;
		cout << i << "- " << navegador->dado.titulo << endl;
	}

}

void mostar_subeventos_listados(Tlista_esta<Tsubevento> lista_subevento) {

	for (int i = 1; i <= lista_subevento.quantidade; i++) {
		cout << i << "- " << lista_subevento.indice[i-1].dado.titulo << endl;
	}

}

void visualizar_lista_espera(){}

void visualizar_lista_pessoas(){}

void visualizar_subevento(Tlista_esta<Tsubevento> lista_subevento, int indice){
	cout << "Titulo: " << lista_subevento.indice[indice].dado.titulo << endl;
	cout << "Data de inicio" << lista_subevento.indice[indice].dado.data.dia
		<< "/" << lista_subevento.indice[indice].dado.data.mes
		<< "/" << lista_subevento.indice[indice].dado.data.ano << endl;
	cout << "Horario: " << lista_subevento.indice[indice].dado.hora.hora << "h "
		<< lista_subevento.indice[indice].dado.hora.minuto << "min " 
		<< lista_subevento.indice[indice].dado.hora.segundo << "sec " << endl;
	cout << "Numero de vagas:" << lista_subevento.indice[indice].dado.vagas << endl;

}

void visualizar_evento(Tevento dado) {
	system("cls");
	cout << "Titulo: "<< dado.titulo << endl;
	cout << "Data de inicio: " << dado.data_inicio.dia 
		<< "/"<< dado.data_inicio.mes
		<< "/" << dado.data_inicio.ano << endl;
	cout << "Data de termino: " << dado.data_fim.dia 
		<< "/" << dado.data_inicio.mes 
		<< "/" << dado.data_inicio.ano << endl;
	cout << "Numero de vagas: " << dado.vagas << endl;

	int escolher_subevento = 1;
	cout << "Lista de subeventos registrados: " << endl;
	cout << "0 = sair" << endl;
	mostar_subeventos_listados(dado.lista_subevento);
	cout << "Escolher subevento: ";
	cin >> escolher_subevento;
	while (escolher_subevento != 0) {
		system("cls");
		visualizar_subevento(dado.lista_subevento, escolher_subevento - 1);
		cout << "Lista de subeventos registrados: " << endl;
		cout << "0 = sair" << endl;
		mostar_subeventos_listados(dado.lista_subevento);
		cout << "Escolher subevento: ";
		cin >> escolher_subevento;
	}


}

int main()
{
	int menu = -1;
	TLista_DE<Tevento> lista_eventos;
	inicializa_list_DE(lista_eventos);

	while (menu != 0)
	{
		mostrar_menu(menu);
		if (menu == 1)
		{
			
			//Tevento<Tsubevento> show1 = novo_evento<Tsubevento>();
			Tevento show1 = teste_novo_evento(1);
			insere_final_lista_DE(lista_eventos, show1);
		}
		if (menu == 2)
		{
			system("cls");
			if(lista_eventos.TAM > 0){
				mostrar_eventos_listados(lista_eventos);
				cout << "Escolha um evento: ";
				int numero_evento_escolhido;
				cin >> numero_evento_escolhido;
				//Tsubevento sub1 = novo_subevento();
				Tsubevento sub1 = teste_novo_subevento(3);
				if (navegador_lista_DE<Tevento>(lista_eventos, numero_evento_escolhido)->dado.lista_subevento.quantidade == 0)
				{
					inicializar_lista_estatica(navegador_lista_DE<Tevento>(lista_eventos, numero_evento_escolhido)->dado.lista_subevento, 10);
				};
				inserir_final_lista_estatica(navegador_lista_DE<Tevento>(lista_eventos, numero_evento_escolhido)->dado.lista_subevento, sub1);
			}
			else {
				cout << "Nao foi possivel adicionar um subevento, pois a lista de eventos esta vazia (Adicione um evento)" << endl;
			}
		}
		if (menu == 3)
		{
			system("cls");
			int numero_evento_escolhido;
			mostrar_eventos_listados(lista_eventos);
			cout << "Escolha um evento: ";
			cin >> numero_evento_escolhido;
			numero_evento_escolhido--;
			Tevento evento_escolhido = navegador_lista_DE<Tevento>(lista_eventos, numero_evento_escolhido)->dado;
			visualizar_evento(evento_escolhido);

		}
		system("cls");
	}
	
	//teste_lista_estatica();
	//teste_lista_encadeada();
	//teste_lista_DE();

}

