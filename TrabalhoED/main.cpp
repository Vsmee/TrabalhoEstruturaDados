#include <iostream>
#include "lista_estatica_template.h"
#include "lista_encadeada.h"
#include "lista_duplamente_encadeada.h"
#include "evento.h"

using namespace std;

void mostrar_menu(int& menu) {

	cout << "########################################" << endl;
	cout << "########################################" << endl;
	cout << "##### 0- Sair do Menu              #####" << endl;
	cout << "##### 1- Criar Evento              #####" << endl;
	cout << "##### 2- Criar Subevento           #####" << endl;
	cout << "##### 3- Visualizar Eventos        #####" << endl;
	cout << "##### 4- Inscrever participante    #####" << endl;
	cout << "##### 5- Remover participante      #####" << endl;
	cout << "########################################" << endl;
	cout << "########################################" << endl;
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

void mostrar_subeventos_listados(Tlista_esta<Tsubevento> lista_subevento) {

	for (int i = 1; i <= lista_subevento.quantidade; i++) {
		cout << i << "- " << lista_subevento.indice[i-1].dado.titulo << endl;
	}

}

void visualizar_lista_inscritos(Tlista_esta<TPessoa> lista_incritos){
	for ( int i = 0; i < lista_incritos.quantidade; i++)
	{
		cout << "Inscrito " << i + 1 <<
			"= Nome: " << lista_incritos.indice[i].dado.nome <<
			"; RG: " << lista_incritos.indice[i].dado.rg << endl;
	}

}

void visualizar_subevento(Tlista_esta<Tsubevento> lista_subevento, int indice){
	int varivel_lista_inscritos;
	cout << "Titulo: " << lista_subevento.indice[indice].dado.titulo << endl;
	cout << "Data de inicio" << lista_subevento.indice[indice].dado.data.dia
		<< "/" << lista_subevento.indice[indice].dado.data.mes
		<< "/" << lista_subevento.indice[indice].dado.data.ano << endl;
	cout << "Horario: " << lista_subevento.indice[indice].dado.hora.hora << "h "
		<< lista_subevento.indice[indice].dado.hora.minuto << "min " 
		<< lista_subevento.indice[indice].dado.hora.segundo << "sec " << endl;
	cout << "Numero de vagas:" << lista_subevento.indice[indice].dado.vagas << endl;
	cout << "Visualizar: Lista de inscritos(1); Lista de espera (2); Nenhuma (0);" << endl;
	cout << "Comando: ";
	cin >> varivel_lista_inscritos;
	if (varivel_lista_inscritos == 1) {
		visualizar_lista_inscritos(lista_subevento.indice[indice].dado.lista_incricoes);
	}
	else if (varivel_lista_inscritos == 2)
	{
		visualizar_lista_inscritos(lista_subevento.indice[indice].dado.lista_espera);
	}
	cout << endl;
}

void visualizar_evento(Tevento dado) {
	system("cls");
	int varivel_lista_inscritos;
	cout << "Titulo: "<< dado.titulo << endl;
	cout << "Data de inicio: " << dado.data_inicio.dia 
		<< "/"<< dado.data_inicio.mes
		<< "/" << dado.data_inicio.ano << endl;
	cout << "Data de termino: " << dado.data_fim.dia 
		<< "/" << dado.data_inicio.mes 
		<< "/" << dado.data_inicio.ano << endl;
	cout << "Numero de vagas: " << dado.vagas << endl;
	cout << "Visualizar: Lista de inscritos(1); Lista de espera (2); Nenhuma (0);" << endl;
	cout << "Comando: ";
	cin >> varivel_lista_inscritos;
	if (varivel_lista_inscritos == 1) {
		visualizar_lista_inscritos(dado.lista_incricoes);
	}
	else if(varivel_lista_inscritos == 2)
	{
		visualizar_lista_inscritos(dado.lista_espera);
	}

	int escolher_subevento = 1;
	cout << "Lista de subeventos registrados: " << endl;
	cout << "0 = sair" << endl;
	mostrar_subeventos_listados(dado.lista_subevento);
	cout << "Escolher subevento: ";
	cin >> escolher_subevento;
	while (escolher_subevento != 0) {
		system("cls");
		visualizar_subevento(dado.lista_subevento, escolher_subevento - 1);
		cout << "Lista de subeventos registrados: " << endl;
		cout << "0 = sair" << endl;
		mostrar_subeventos_listados(dado.lista_subevento);
		cout << "Escolher subevento: ";
		cin >> escolher_subevento;
	}

}


bool verificador_sobrecarregado_lista_estatica(Tlista_esta<TPessoa> list, int indice, TPessoa item) {

	string nome = item.nome;
	string rg = item.rg;
	if (list.indice[indice].dado.nome == item.nome && list.indice[indice].dado.rg == item.rg) {
		return true;
	}
	return false;

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

				TElemento_DE<Tevento>* evento_escolhido = new TElemento_DE<Tevento>;
				evento_escolhido = navegador_lista_DE(lista_eventos, numero_evento_escolhido);

				if (evento_escolhido->dado.lista_subevento.quantidade == 0)
				{
					inicializar_lista_estatica(evento_escolhido->dado.lista_subevento , 10);
				};
				inserir_final_lista_estatica(evento_escolhido->dado.lista_subevento, sub1);
				evento_escolhido = nullptr;
			}
			else {
				cout << "Nao foi possivel adicionar um subevento, pois a lista de eventos esta vazia (Adicione um evento)" << endl;
			}
		}
		if (menu == 3)
		{
			system("cls");
			int numero_evento_escolhido; // !! 3
			mostrar_eventos_listados(lista_eventos);
			cout << "Escolha um evento: ";
			cin >> numero_evento_escolhido;
			numero_evento_escolhido;
			Tevento evento_escolhido = navegador_lista_DE<Tevento>(lista_eventos, numero_evento_escolhido)->dado;
			visualizar_evento(evento_escolhido);

		}
		if (menu == 4) 
		{
			system("cls");
			int numero_evento_escolhido;
			int numero_subevento_escolhido;
			int escolha_evento_sub;

			TPessoa pessoa = teste_nova_pessoa();

			mostrar_eventos_listados(lista_eventos);
			cout << "Escolher um evento: ";
			cin >> numero_evento_escolhido;
			system("cls");
			cout << "Increver pessoa: nesse evento (1) ou subevento desse evento (2)";
			cin >> escolha_evento_sub;

			TElemento_DE<Tevento>* evento_escolhido = new TElemento_DE<Tevento>;
			evento_escolhido = navegador_lista_DE(lista_eventos, numero_evento_escolhido);

			evento_escolhido->dado.lista_incricoes.MAX = 1; // Para tirar lixo de memoria e nao entrar na lista de espera antes de iniciar a lista de inscricoes
	

			if (escolha_evento_sub == 1) {

				if (evento_escolhido->dado.lista_incricoes.quantidade >= evento_escolhido->dado.lista_incricoes.MAX)
				{
					if (evento_escolhido->dado.lista_espera.quantidade == 0)
					{
						inicializar_lista_estatica(evento_escolhido->dado.lista_espera, evento_escolhido->dado.lista_incricoes.MAX*0.10);
					};
					inserir_final_lista_estatica(evento_escolhido->dado.lista_espera, pessoa);
				}
				else if (evento_escolhido->dado.lista_incricoes.quantidade == 0)
				{
					inicializar_lista_estatica(evento_escolhido->dado.lista_incricoes, evento_escolhido->dado.vagas);
				};
				inserir_final_lista_estatica(evento_escolhido->dado.lista_incricoes, pessoa);
			}
			else if (buscar_item_lista_estatica<TPessoa>(evento_escolhido->dado.lista_incricoes,pessoa)){
			
				mostrar_subeventos_listados(evento_escolhido->dado.lista_subevento);
				cout << "Escolher um Subevento: ";
				cin >> numero_subevento_escolhido;
				Tlista_esta<TPessoa>* lista_inscricoes_subevento = &evento_escolhido->dado.lista_subevento.indice[numero_evento_escolhido-1].dado.lista_incricoes;
				Tlista_esta<TPessoa>* lista_espera_subevento = &evento_escolhido->dado.lista_subevento.indice[numero_evento_escolhido - 1].dado.lista_espera;

				if (lista_espera_subevento->MAX <= 0) // Para tirar lixo de memoria e nao entrar na lista de espera antes de iniciar a lista de inscricoes
				{
					lista_inscricoes_subevento->MAX = 1;
				}

				if (lista_inscricoes_subevento->quantidade >= lista_inscricoes_subevento->MAX)
				{
					if (lista_espera_subevento->quantidade == 0)
					{
						inicializar_lista_estatica(*lista_espera_subevento, lista_inscricoes_subevento->MAX*0.10);
					};
					inserir_final_lista_estatica(*lista_espera_subevento, pessoa);
				}
				else if (lista_inscricoes_subevento->quantidade == 0)
				{
					inicializar_lista_estatica(*lista_inscricoes_subevento, evento_escolhido->dado.vagas);
				};
				inserir_final_lista_estatica(*lista_inscricoes_subevento, pessoa);

			}

		}
		if (menu == 5)
		{

		}
		//system("cls");
	}
	
	//teste_lista_estatica();
	//teste_lista_encadeada();
	//teste_lista_DE();

}

