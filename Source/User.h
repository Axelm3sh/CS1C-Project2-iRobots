/*
 * User.h
 *
 *  Created on: May 5, 2015
 *      Author: Matt
 */

#ifndef USER_H_
#define USER_H_

#include <string>
#include "linkListTemplate.h"
#include "Transaction.h"
#include <sstream>
using namespace std;

class User{

public:
	User();
	//copy constructor
	User(const User&);
	User(string);
	~User();

	void SetValues(string, string, string, bool, string);
	void SetName(string);
	void SetRating(string);
	void SetKey(bool);
	void SetAddress(string);
	void SetAddress2(string);
	bool operator<(const User&);
	void RequestPamphlet();
	bool ContactShop();

	void AddTransaction(Transaction);

	string GetName();
	bool   GetKey();
	string GetRating();
	bool   GetIsAdmin();
	string PrintUser();
	string PrintUserToFile();
	string OutputTransactions();
	User& operator=(const User&);

private:
	string 				  name;
	string 				  address1;
	string				  address2;
	bool   				  key;
	string 				  rating;
	LinkList<Transaction> myTransactions;
	bool   				  isAdmin;
	bool 				  requestPamph;

};



#endif /* USER_H_ */
