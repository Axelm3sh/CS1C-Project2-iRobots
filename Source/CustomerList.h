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
#include "BoundaryCheck.h"
#include  <fstream>
using namespace std;

class CustomerList{

public:
	CustomerList(ifstream&);
	~CustomerList();
	void AddCust(User);
	void RemoveCust(string name);
	Node<User>* SearchListByName(string name);
	void SortListByName();
	void SortListByNameKeyOnly();
	string PrintCustList();
	string SaveFile();
	string PrintCustList(bool keyOnly);
	void SaveTransactions(string);
	string PrintCustWithTrans();
	void EditCustomer(string name);
	void CreateNewCustomer();

	//MakePurchase
	//EditPrevTransactions

private:

	LinkList<User> userList;
	int            size;

};


#endif /* CUSTOMERLIST_H_ */
