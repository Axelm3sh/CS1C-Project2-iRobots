
#ifndef NODETEMPLATE_H_
#define NODETEMPLATE_H_

#include <iostream>
using namespace std;

template<class Type>

class Node
{

public:

	Node<Type>();  //default constructor
	~Node();       //destructor

	void SetData(Type myData);
	void SetNext(Node<Type> *myNode);
	void SetPrev(Node<Type> *myNode);

	Node<Type>* GetNext();
	Node<Type>* GetPrev();
	Type        GetData();

private:
	Node<Type>* next;
	Node<Type>* prev;
	Type data;
};

//default constructor
template<class Type>
Node<Type>::Node()
{
	next = NULL;
	prev = NULL;
}

//destructor
template<class Type>
Node<Type>::~Node()
{
	delete next;
	delete prev;
}

//Set the Node data to passed in data
template<class Type>
void Node<Type>::SetData(Type myData)
{
	data = myData;
}

//Set current node's next value equal to the passed in Node
template<class Type>
void Node<Type>::SetNext(Node<Type> *myNode)
{
	next = myNode;
}

//Set current node's prev value equal to the passed in Node
template<class Type>
void Node<Type>::SetPrev(Node<Type> *myNode)
{
	prev = myNode;
}

//Return a pointer value to the what current Node's next is equal to
template<class Type>
Node<Type>* Node<Type>::GetNext()
{
	return next;
}

//Return a pointer value to the what current Node's prev is equal to
template<class Type>
Node<Type>* Node<Type>::GetPrev()
{
	return prev;
}

//Return a the current data as it's data type
template<class Type>
Type Node<Type>::GetData()
{
	return data;
}


#endif /* NODETEMPLATE_H_ */
