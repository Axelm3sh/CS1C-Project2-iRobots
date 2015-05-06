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
#include  <fstream>
using namespace std;

class CustomerList{

public:
	CustomerList(ifstream&);
	~CustomerList();
	void AddCust(User);
	void RemoveCust(string name);
	void SortListByName();
	void SortListByNameKeyOnly();
	string PrintCustList();
	string PrintCustList(bool keyOnly);
	string PrintCustWithTrans();
	//MakePurchase
	//EditPrevTransactions

private:

	LinkList<User> userList;
	int            size;

};


#endif /* CUSTOMERLIST_H_ */
