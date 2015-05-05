/*
 * TransactionList.h
 *
 *  Created on: May 5, 2015
 *      Author: Matt
 */

#ifndef TRANSACTIONLIST_H_
#define TRANSACTIONLIST_H_
#include "Transaction.h"
#include "linkListTemplate.h"
using namespace std;

class TransactionList{
	public:

		void AddTrans(Transaction myTrans);
		bool RemoveTrans(string name, Date date);
		string PrintList();

	private:

		LinkList<Transaction> myTransactions;
		int size;

};



#endif /* TRANSACTIONLIST_H_ */
