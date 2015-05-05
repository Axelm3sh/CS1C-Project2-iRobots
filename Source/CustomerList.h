/*
 * CustomerList.h
 *
 *  Created on: May 5, 2015
 *      Author: Matt
 */

#ifndef CUSTOMERLIST_H_
#define CUSTOMERLIST_H_

#include <string>
#include "User.h"
#include "linkListTemplate.h"
using namespace std;

class CustomerList{

public:
	void AddCust(User);
	void RemoveCust(string name);
	void SortListByName();
	void SortListByNameKeyOnly();
	string PrintList();
	string PrintList(bool keyOnly);
	//MakePurchase
	//EditPrevTransactions

private:

	LinkList<User> userList;
	int            size;

};


#endif /* CUSTOMERLIST_H_ */
