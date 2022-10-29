#include "pch.h"
#include "Reciente.h"
#include <string>


void Reciente::push(std::string item)
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


void Reciente::RemoveAt(int index)
{
	//nodo 1, el que se eliminará
	Node* temporal1 = header;
	//nodo 2, el que apuntará al nodo al que estaba apuntando el nodo que se eliminará
	Node* temporal2 = header;
	//variable contador
	int contador = 0;
	//si el indice es 0, solo se corre el header
	if (index == 0)
	{
		header = header->next;
	}
	else //si no es 0, se ejecuta este código
	{
		//se encuentra el valor del nodo 1
		while (index > contador)
		{
			temporal1 = temporal1->next;
			contador += 1;
		}
		contador = 0;
		//se encuentra el valor del nodo 1
		while ((index - 1) > contador)
		{
			temporal2 = temporal2->next;
			contador += 1;
		}
	}
	//el elemento anterior ahora apunta al elemento donde antes apuntaba el eliminado
	temporal2->next = temporal1->next;
};



std::string Reciente::pop() {
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

int Reciente::Count()
{
	
	int cantidad = 0;
	
	Node* temporal = header;
	
	while (temporal != nullptr)
	{
		
		cantidad += 1;
		
		temporal = temporal->next;
	};
	
	return cantidad;
};


int Reciente::GetItem(int index) {

	int position = 0;
	struct Node* currentNode = header;
	if (Count() > 0)
	{
		while ((currentNode) && position < index) {
			position++;
			currentNode = currentNode->next;
		}
		return std::stoi(currentNode->data);
		
	}
	else
	{
		return -1;
	}
}