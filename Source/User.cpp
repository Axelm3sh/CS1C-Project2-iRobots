#include "User.h"

User::User(){
	name     = "sdfadsf";
	address  = "sdkfjds2 22 ";
	key      = true;
	rating   = " 77";
	isAdmin  = false;
}

User::User(string myName){
	name     = myName;
	address  = "sdkfjds2 22 ";
	key      = true;
	rating   = " 77";
	isAdmin  = false;
}

User::~User(){

}

string User::PrintUser(){
	ostringstream output;

	output << "\nCustomer: " << name << endl;
	output << "Address   : " << address << endl;
	output << "Rating    : " << rating << endl;
	output << "Key       : ";
	if(key)
		output << "yes";
	else
		output << "no";
	output << endl;

	return output.str();
}

void User::SetAddress(string addr){
		address = addr;
}

void User::SetName(string myName){
		name = myName;
}

string User::GetName(){
	return name;
}

bool User::operator<(const User& other){

	return (name < other.name);

}
