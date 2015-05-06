/*
 * Transaction.h
 *
 *  Created on: May 5, 2015
 *      Author: Matt
 */

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <string>
#include <sstream>
#include <iomanip>
#include "Date.h"
using namespace std;

class Transaction {
	public:

		Transaction();
		Transaction(Date, int, float, bool);
		~Transaction();

		Date   GetDate();
		int    GetModelNum();
		float  GetPrice();
		bool   HasWarranty();
		string PrintTrans();
		bool operator<(const Transaction&);


	private:
		Date  tranDate;
		int   modelNum;
		float price;
		bool  maintenance;

};



#endif /* TRANSACTION_H_ */
