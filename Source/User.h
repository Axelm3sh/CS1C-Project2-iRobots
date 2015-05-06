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

	void SetValues(string, string, bool, string);
	void SetName(string);
	void SetRating(string);
	void SetKey(bool);
	void SetAddress(string);
	bool operator<(const User&);
	void RequestPamphlet();
	bool ContactShop();

	void AddTransaction(Transaction);

	string GetName();
	bool   GetKey();
	string GetRating();
	bool   GetIsAdmin();
	string PrintUser();
	string OutputTransactions();
	User& operator=(const User&);

private:
	string 				  name;
	string 				  address;
	bool   				  key;
	string 				  rating;
	LinkList<Transaction> myTransactions;
	bool   				  isAdmin;

};



#endif /* USER_H_ */
