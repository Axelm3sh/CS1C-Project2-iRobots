#include "CustomerList.h"

	CustomerList::CustomerList(ifstream& inFile){
		User newUser;
		Transaction myTrans;
		string address;
		string 				  myName;
		string 				  myAddress;
		string   			  myStringKey;
		bool   				  myKey;
		string 				  myRating;



			while(!inFile.eof()){
				//newUser = new User;
				getline(inFile, myName);

				getline(inFile, myAddress);
				getline(inFile, myRating);
				if(myRating == "key")
				{
					myKey = true;
				}
				else{
					myKey = false;
				}
				getline(inFile, myStringKey);

				newUser.SetValues(myName, myAddress, myKey, myRating);

			    AddCust(newUser);

			}
	}

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

