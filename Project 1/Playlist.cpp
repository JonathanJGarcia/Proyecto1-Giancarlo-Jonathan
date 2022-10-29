#include "pch.h"
#include "Playlist.h"
#include<string>

void Playlist::push(std::string item)
{
	Node* newNode = new Node();;
	newNode->data = item;

	if (Count() == 0) {//lista vacia 
		header = newNode;
		Tail = newNode;
	}
	else {//si hay elementos
		Tail->next = newNode;
		Tail = newNode;
	}

}


void Playlist::RemoveAt(int index)
{
	
	Node* temporal1 = header;
	
	Node* temporal2 = header;
	
	int contador = 0;
	
	if (index == 0)
	{
		header = header->next;
	}
	else 
	{
		
		while (index > contador)
		{
			temporal1 = temporal1->next;
			contador += 1;
		}
		contador = 0;
		
		while ((index - 1) > contador)
		{
			temporal2 = temporal2->next;
			contador += 1;
		}
	}
	
	temporal2->next = temporal1->next;

};

std::string Playlist::pop() {
	if (header == NULL) {

		return "";
	}
	else {
		std::string tempp = header->data;
		Node* temp = header;
		header = header->next;
		delete temp;
		return tempp;
	}
	return 0;
}


int Playlist::Count()
{
	//variable contador
	int cantidad = 0;
	//nodo que nos ayudará a pasar por la lista
	Node* temporal = header;
	//condición, si es null, es decir que se acaba la lista, se acaba el ciclo
	while (temporal != nullptr)
	{
		//cada ciclo se le suma uno a cantidad
		cantidad += 1;
		//temporal adquiere el valor del siguiente nodo hasta que el siguiente sea null
		temporal = temporal->next;
	};
	//se devuelve el valor del contador
	return cantidad;
};


int Playlist::GetItem(int index) {

	int position = 0;
	struct Node* currentNode = header;
	if (Count() > 0)
	{
		while ((currentNode) && position < index) {
			position++;
			currentNode = currentNode->next;
		}

		
	}
	else
	{
		return -1;
	}
}