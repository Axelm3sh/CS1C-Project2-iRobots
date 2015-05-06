#include "CustomerList.h"

CustomerList::~CustomerList(){
	//userList.ClearList();
}

void CustomerList::AddCust(User newUser){

	Node<User>* myUser;
	myUser = new Node<User>;
	myUser->SetData(newUser);
	userList.AddNode(myUser);
}


string CustomerList::PrintCustList(){
	Node<User>* myUser;
	ostringstream output;
	myUser = userList.GetHead();

	while(myUser != NULL)
	{
		output << myUser->GetData().PrintUser();
		myUser = myUser->GetNext();
	}

	return output.str();
}

string CustomerList::PrintCustList(bool isKey){
	Node<User>* myUser;
	ostringstream output;
	myUser = userList.GetHead();

	while(myUser != NULL)
	{
		if(myUser->GetData().GetKey()){
		output << myUser->GetData().PrintUser();
		}
		myUser = myUser->GetNext();
	}

	return output.str();
}

string CustomerList::PrintCustWithTrans(){
	Node<User>* myUser;
	ostringstream output;
	myUser = userList.GetHead();

	while(myUser != NULL)
	{
		output << myUser->GetData().PrintUser();
		output << "\nOutputting all transactions for " << myUser->GetData().GetName() << endl;
		output << myUser->GetData().OutputTransactions();
		myUser = myUser->GetNext();
	}

	return output.str();
}

