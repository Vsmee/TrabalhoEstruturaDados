#include <iostream>
#include "lista_estatica_template.h"
#include "lista_encadeada.h"
#include "lista_duplamente_encadeada.h"
#include "evento.h"

using namespace std;

void mostra_menu(int& menu) {

	cout << "##############################" << endl;
	cout << "##############################" << endl;
	cout << "##### 0- Sair do Menu    #####" << endl;
	cout << "##### 1- Criar Evento    #####" << endl;
	cout << "##### 2- Criar Subevento #####" << endl;
	cout << "#####                    #####" << endl;
	cout << "#####                    #####" << endl;
	cout << "#####                    #####" << endl;
	cout << "##############################" << endl;
	cout << "##############################" << endl;
	cout << "comando: ";
	cin >> menu;

}

void mostra_lista_eventos(TLista_DE<Tevento>& lista_eventos) {

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
	cout << "Escolha um evento: " << endl;

}

int main()
{
	int menu = -1;
	TLista_DE<Tevento> lista_eventos;
	inicializa_list_DE(lista_eventos);
	

	//Tsubevento sub1 = novo_subevento();
	Tsubevento sub1 = teste_novo_subevento(2);

	while (menu != 0)
	{
		mostra_menu(menu);
		if (menu == 1)
		{
			//Tevento<Tsubevento> show1 = novo_evento<Tsubevento>();
			insere_final_lista_DE(lista_eventos, teste_novo_evento(1));
		}
		if (menu == 2)
		{
			mostra_lista_eventos(lista_eventos);
			int evento_escolhido;
			cin >> evento_escolhido;
			Tsubevento sub1 = novo_subevento();
			Tlista_esta<Tsubevento> listaes_colhida =  navegador_lista_DE<Tevento>(lista_eventos, evento_escolhido)->dado.lista_subevento;
			inicializar_lista_estaticaTP(listaes_colhida, 10);
			inserir_final_lista_estaticaTP(listaes_colhida, sub1);
			
		}
		//system("cls");
	}

	//teste_lista_estatica();
	//teste_lista_encadeada();
	//teste_lista_DE();


}

