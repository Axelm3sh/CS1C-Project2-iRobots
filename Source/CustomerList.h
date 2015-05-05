/*
 * CustomerList.h
 *
 *  Created on: May 5, 2015
 *      Author: Matt
 */

#ifndef CUSTOMERLIST_H_
#define CUSTOMERLIST_H_

#include <string>
using namespace std;

class CustomerList{


public:
	void AddCust(User);
	void RemoveCust(string name);
	void SortListByName();
	void SortListByNameKeyOnly();
	string PrintCustomer();
	string PrintList();
	string PrintList(bool);
	//MakePurchase
	//EditPrevTransactions


private:

	LinkList<User> userList;
	int            size;


};



#endif /* CUSTOMERLIST_H_ */
