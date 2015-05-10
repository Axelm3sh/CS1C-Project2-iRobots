#include "Transaction.h"

Transaction::Transaction(){
	//tranDate =
	modelNum = 223322;
	price = 22.33;
	maintenance = true;
}

Transaction::Transaction(Date myDate, int model, bool maintPlan, int quant){

	tranDate = myDate;

	switch(model){
	case 1:
		modelNum = model;
		price = 50000;
		maintenance = maintPlan;
		break;

	case 2:
		modelNum = model;
		price = 250000;
		maintenance = maintPlan;
		break;


	case 3 :
		modelNum = model;
		price = 500000;
		maintenance = maintPlan;
	}


	quantity = quant;
	totalSpent = quant*price;
	if(maintenance){
		totalSpent += quant*(price*.15);
	}
}



Transaction::~Transaction(){

}


Date Transaction::GetDate(){
	return tranDate;
}

int Transaction::GetModelNum(){
	return modelNum;
}

float Transaction::GetPrice(){
	return price;
}

bool Transaction::HasWarranty(){
	return maintenance;
}

string Transaction::PrintTrans(){
	ostringstream output;

	output << "Date:               "   << tranDate.DisplayDate();

	//cant figure this one out, causes runtime errors
	//output << "Transaction Date:   "   << ctime(&myTime);
	output << "\nModel Number:       "   << modelNum;
	output << "\nPrice Per Bot:      $";
	output << setprecision(2)<< fixed;
	output << price;
	output << "\nQuantity:           " << quantity;
	output << "\nMaintenance Plan:   ";
	if(maintenance){
		output << "Yes";
	}
	else{
		output << "No";
	}
	output << endl;
	output << "Total Cost:         $" << totalSpent;
	output << endl << endl;

	return output.str();
}

bool Transaction::operator<(const Transaction& other){


		return tranDate < other.tranDate;
}
