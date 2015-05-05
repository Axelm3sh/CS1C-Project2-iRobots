
#ifndef LINKLISTTEMPLATE_H_
#define LINKLISTTEMPLATE_H_

#include <iostream>
#include <string>
#include "nodeTemplate.h"
#include <sstream>
using namespace std;

template<class Type>

class LinkList
{

public:

	LinkList();                      //default constructor
	LinkList(const LinkList<Type>&); //rev copy constructor
	~LinkList();					 //destructor

	void AddNode(Node<Type>* newNode);
	void AddNode(Node<Type>* newNode, int location);
	void DeleteNode(int);
	void ClearList();
	Node<Type>* GetHead();

	string OutputList();
	int         GetSize();

private:

	Node<Type>* head;
	Node<Type>* tail;
	int         size;

};

//default constructor
template<class Type>
LinkList<Type>::LinkList()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

//copy constructor
template<class Type>
LinkList<Type>::LinkList(const LinkList<Type>& otherList)
{
	Node<Type>* sptr;    //PROC - used to traverse through otherList
	Node<Type>* newNode; //PROC - used to add Nodes to current LinkList

	//SET sptr and size equal to values from otherList
	sptr = otherList.head;
	size = otherList.size;

	//PROC - before entering while loop add the first node to the current list
	newNode = new Node<Type>;
	newNode->SetData(sptr->GetData());
	head = newNode;
	tail = newNode;
	newNode->SetPrev(NULL);
	newNode->SetNext(NULL);
	sptr = sptr->GetNext();

	//PROC - continue to copy Nodes from otherList until sptr reaches NULL vale
	while(sptr != NULL)
	{
		newNode = new Node<Type>;
		newNode->SetData(sptr->GetData());
		newNode->SetNext(head);
		newNode->SetPrev(NULL);
		head->SetPrev(newNode);
		head = newNode;
		sptr = sptr->GetNext();
	}

	//deallocate memory
	sptr    = NULL;
	newNode = NULL;
	delete sptr;
	delete newNode;
}

//destructor
template<class Type>
LinkList<Type>::~LinkList()
{
	ClearList();
}

//add a new node to the LinkList
template<class Type>
void LinkList<Type>::AddNode(Node<Type>* newNode)
{
	Node<Type>* node = new Node<Type>;  //PROC - used to add new node to the list
	Node<Type>* sptr;
	bool        found = false;
	sptr = head;

	node->SetData(newNode->GetData());
	size++;
	//IF the list is empty
	if (head == NULL)
	{
		node->SetNext(NULL);
		node->SetPrev(NULL);
		head = node;
		tail = node;
	}
	else if(node->GetData() < sptr->GetData()){
		node->SetNext(head);
		node->SetPrev(NULL);
		head->SetPrev(node);
		head = node;
	}
	else
	{
		while(sptr != NULL && !found){
		if(node->GetData() < sptr->GetData())
		{
			found = true;
		}
		else{
			sptr = sptr->GetNext();
		}

		}//end while

		if(found)
		{
			node->SetNext(sptr);
			node->SetPrev(sptr->GetPrev());
			sptr->GetPrev()->SetNext(node);
			sptr->SetPrev(node);

		}
		else{
			node->SetPrev(tail);
			node->SetNext(NULL);
			tail->SetNext(node);
			tail = node;
		}
	}
}

//add a new node to the LinkList (overloaded to accept the location of where to add the node)
template<class Type>
void LinkList<Type>::AddNode(Node<Type>* newNode, int location)
{
	try{
		Node<Type>* node    = new Node<Type>;  //PROC - used to add new node to the list
		Node<Type>* tempPtr = new Node<Type>;  //PROC - used to add new node to the middle of list
		tempPtr = head;

		//IF a valid location
		if(size != 0 && (location > 0 && location <= size)){
			node->SetData(newNode->GetData());
			cout << "\nAdding " << node->GetData() << " to location " << location << endl;

			//IF adding to the head
			if(location == 1){
				node->SetNext(head);
				node->SetPrev(NULL);
				head->SetPrev(node);
				head = node;
				size++;
			}
			//IF adding to the tail
			else if(location == size)
			{
				node->SetPrev(tail);
				node->SetNext(NULL);
				tail->SetNext(node);
				tail = node;
				size++;
			}
			//ELSE the Node to delete is located at neither the head
			//     nor the tail of the LinkList
			else{
				//FOR loop is used to place temp at correct location for addition
				for(int index = 1; index < location-1; index++){
						tempPtr = tempPtr->GetNext();
					}
					node->SetPrev(tempPtr);

					node->SetNext(tempPtr->GetNext());

					tempPtr->GetNext()->SetPrev(node);

					tempPtr->SetNext(node);
					size++;
			}

			//deallocate memory
			tempPtr = NULL;
			node    = NULL;
			delete node;
			delete tempPtr;
		}
		//IF the LinkList is empty
		else if(size == 0)
		{
			cout << "List is empty so node will be the only node on the list\n";
			node->SetNext(NULL);
			node->SetPrev(NULL);
			head = node;
			tail = node;
			size++;
		}
		//ELSE then location is not valid so throw location and prompt for new input
		else{
			throw location;
		}
	}
	catch(int){
		cout << endl << location << " is an invalid location! Enter a value "
				"between 1 and " << size << ": ";
		cin  >> location;
		cin.ignore(1000,'\n');
		AddNode(newNode, location);
	}
}


//clears the LinkList
template<class Type>
void LinkList<Type>::ClearList(){

	Node<Type>* sptr;

	while(head->GetNext() != NULL){
		sptr = head;
		head = sptr->GetNext();
		sptr->SetNext(NULL);
		sptr->SetPrev(NULL);
		head->SetPrev(NULL);
		delete sptr;
	}
	sptr = head;
	size = 0;
	head = NULL;
	tail = NULL;
	delete sptr;

}

//Returns the head
template<class Type>
Node<Type>* LinkList<Type>::GetHead(){
return head;
}

//Deletes the node located at the passed in location
template<class Type>
void LinkList<Type>::DeleteNode(int location)
{
	try{
		//IF a valid location
		if(location > 0 && location <= size){
			Node<Type>* sptr;      //PROC - used to traverse through LinkList
								   //       and the delete the desired Node
			sptr = head;
			//IF the LinkList consists of only one Node
			if(location == 1 && size == 1)
			{
				head = NULL;
				tail = NULL;
				size --;
			}
			//IF the Node to delete is the first Node
			else if(location == 1){
				head = sptr->GetNext();
				head->SetPrev(NULL);
				size--;
			}
			//IF the Node to delete is the last node
			else if(location == size)
			{
				//FOR loop is used to place sptr at correct location for deletion
				for(int index = 1;index < size; index++){
					sptr = sptr->GetNext();
				}
				tail = sptr->GetPrev();
				sptr->GetPrev()->SetNext(NULL);
				size--;
			}
			//ELSE the Node to delete is located at neither the head
			//     nor the tail of the LinkList
			else{
				//FOR loop is used to place sptr at correct location for deletion
				for(int index = 1; index < location; index++){
						sptr = sptr->GetNext();
					}

					sptr->GetPrev()->SetNext(sptr->GetNext());
					sptr->GetNext()->SetPrev(sptr->GetPrev());
					size--;
			}

			//deallocate memory
			sptr->SetNext(NULL);
			sptr->SetPrev(NULL);
			delete sptr;
		}
		//IF the list is empty
		else if(size == 0){
				cout << "\nCannot delete from an empty list!\n";
		}
		//ELSE then location is not valid so throw location and prompt for new input
		else{
			throw location;
		}
	}
	catch(int){
		cout << endl << location << " is an invalid location! Enter a value "
				"between 1 and " << size << ": ";
		cin  >> location;
		cin.ignore(1000,'\n');
		DeleteNode(location);
	}
}

//outputs the contents of entire LinkList
template<class Type>
string LinkList<Type>::OutputList()
{
	ostringstream output;   //PROC - used to store all output info, is returned
							//       as a string
	Node<Type>* sptr;       //PROC - used to traverse through LinkList nodes
	sptr = head;
	while (sptr != NULL)
	{
		output << sptr->GetData() << ' ';
		sptr = sptr->GetNext();
	}

	return output.str();
}

//Returns the size of the list
template<class Type>
int LinkList<Type>::GetSize(){
	return size;
}


#endif /* LINKLISTTEMPLATE_H_ */
