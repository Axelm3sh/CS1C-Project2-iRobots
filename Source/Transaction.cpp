#include "Transaction.h"

Transaction::Transaction(){
	//tranDate =
	modelNum = 223322;
	price = 22.33;
	maintenance = true;
}

Transaction::Transaction(Date myDate, int model, float cost, bool maintPlan){
	tranDate = myDate;
	modelNum = model;
	price = cost;
	maintenance = maintPlan;
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

	output << "\nDate:             "   << tranDate.DisplayDate();
	output << "\nModel Number:     "   << modelNum;
	output << "\nPrice:            $";
	output << setprecision(2)<< fixed;
	output << price;
	output << "\nMaintenance Plan: ";
	if(maintenance){
		output << "Yes";
	}
	else{
		output << "No";
	}
	output << endl;

	return output.str();
}

bool Transaction::operator<(const Transaction& other){


		return tranDate < other.tranDate;
}
