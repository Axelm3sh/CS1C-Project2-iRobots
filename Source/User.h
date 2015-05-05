/*
 * User.h
 *
 *  Created on: May 5, 2015
 *      Author: Matt
 */

#ifndef USER_H_
#define USER_H_

#include <string>
using namespace std;

class User{

public:
	User();
	~User();

	void SetRating(string);
	void SetKey(bool);
	void SetAddress(string);

	void RequestPamphlet();
	bool ContactShop();

	string GetName();
	bool   GetKey();
	string GetRating();
	bool   GetIsAdmin();

private:
	string 			name;
	string 			address;
	bool   			key;
	string 			rating;
	TransactionList myTransactions;
	bool   			isAdmin;

};



#endif /* USER_H_ */
