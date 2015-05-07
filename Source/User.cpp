#include "User.h"

User::User(){
	name     = "sdfadsf";
	address1 = "sdkfjds2 22 ";
	address2 = "city, state, zipcode";
	key      = true;
	rating   = " 77";
	isAdmin  = false;
}

User::User(const User& other) {
	name    = other.name;
	address1 = other.address1;
	address2 = other.address2;
	key     = other.key;
	rating  = other.rating;
	isAdmin = other.isAdmin;
	myTransactions = other.myTransactions;
}



User::User(string myName){
	name     = myName;
	address1 = "sdkfjds2 22 ";
	address2 = "city, state, zipcode";
	key      = true;
	rating   = " 77";
	isAdmin  = false;
//	myTransactions.ClearList();
}

User::~User(){

}

void User::SetValues(string myName, string myAddress, string myAddress2,
					 bool myKey, string myRating)
{

	 name             = myName;
	 address1         = myAddress;
	 address2		  = myAddress2;
	 key              = myKey;
	 rating           = myRating;
}


string User::PrintUser()
{
	ostringstream output;

	output << "\nCustomer: " << name << endl;
	output << "Address   : " << address1 << endl;
	output << "            " << address2 << endl;
	output << "Rating    : " << rating << endl;
	output << "Key       : ";
	if(key)
		output << "Yes";
	else
		output << "Nice To Have";
	output << endl;

	return output.str();
}

void User::SetAddress(string addr)
{
		address1 = addr;
}

void User::SetAddress2(string addr)
{
		address2 = addr;
}

void User::SetName(string myName)
{
		name = myName;
}

string User::GetName()
{
	return name;
}

bool User::operator<(const User& other)
{

	return (name < other.name);
}

bool User::GetKey()
{

	return key;
}

void User::AddTransaction(Transaction newTrans)
{
	Node<Transaction>* tranPtr;
	tranPtr = new Node<Transaction>;
	tranPtr->SetData(newTrans);
	myTransactions.AddNode(tranPtr);

}

string User::OutputTransactions()
{
	Node<Transaction>* tranPtr;
	ostringstream output;
	tranPtr = myTransactions.GetHead();

	while(tranPtr != NULL)
	{
		output << tranPtr->GetData().PrintTrans();
		tranPtr = tranPtr->GetNext();
	}

	return output.str();
}

User& User::operator=(const User& other)
{

	name    	= other.name;
	address1	= other.address1;
	address2	= other.address2;
	key     	= other.key;
	rating  	= other.rating;
	isAdmin 	= other.isAdmin;
	myTransactions = other.myTransactions;

	return *this;
}
