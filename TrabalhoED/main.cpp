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

template<typename T>
void mostra_lista_eventos(TLista_DE<T>& lista_eventos) {

	int i = 0;
	cout << "Eventos Disponiveis: " << endl;
	TElemento_DE<T>* navegador = lista_eventos.primeiro;
	while (navegador->proximo != nullptr)
	{
		navegador = navegador->proximo;
		i++;
		cout << i << "- " << navegador->dado << endl;
		
	}
	lista_eventos.primeiro->dado;
}
int main()
{
	int menu = -1;
	TLista_DE<Tevento<Tsubevento>> lista_eventos;
	inicializa_list_DE(lista_eventos);
	

	//Tsubevento sub1 = novo_subevento();
	Tsubevento sub1 = teste_novo_subevento(2);

	while (menu != 0)
	{
		mostra_menu(menu);
		if (menu == 1)
		{
			//Tevento<Tsubevento> show1 = novo_evento<Tsubevento>();
			insere_final_lista_DE(lista_eventos, teste_novo_evento<Tsubevento>(1));
		}
		if (menu == 2)
		{
			//mostra_lista_eventos<Tevento<Tsubevento>>(lista_eventos);
			Tsubevento sub1 = novo_subevento();
			inicializar_lista_estaticaTP(lista_eventos.primeiro->dado.lista_subevento, 10);
			inserir_final_lista_estaticaTP(lista_eventos.primeiro->dado.lista_subevento, sub1);
			
		}
		//system("cls");
	}
	cout << lista_eventos.primeiro->dado.lista_subevento.indice[0].dado.titulo << endl;

	//teste_lista_estatica();
	//teste_lista_encadeada();
	//teste_lista_DE();


}

