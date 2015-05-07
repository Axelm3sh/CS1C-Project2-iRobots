#include "CustomerList.h"

	CustomerList::CustomerList(ifstream& inFile){
		User newUser;
		Transaction myTrans;
		string address;
		string 				  myName;
		string 				  myAddress;
		string				  myAddress2;
		string   			  myStringKey;
		bool   				  myKey;
		string 				  myRating;



			while(!inFile.eof()){
				//newUser = new User;
				getline(inFile, myName);

				getline(inFile, myAddress);
				getline(inFile, myAddress2);
				getline(inFile, myRating);
				getline(inFile, myStringKey);
				if(myRating == "key")
				{
					myKey = true;
				}
				else{
					myKey = false;
				}

				newUser.SetValues(myName, myAddress, myAddress2,
								  myKey, myRating);

			    AddCust(newUser);

			}
	}

CustomerList::~CustomerList(){
	//userList.ClearList();
}

void CustomerList::AddCust(User newUser){

	Node<User>* myUser;
	myUser = new Node<User>;
	myUser->SetData(newUser);
	userList.AddNode(myUser);
}

void CustomerList::RemoveCust(string name)
{
	Node<User>* deletePtr;
	Node<User>* searchPtr;
	User targetUser;
	bool found = false;

	searchPtr = userList.GetHead(); //Assign search marker to head
	targetUser = searchPtr->GetData();//Put first node data in temp holder


	while(searchPtr != NULL && !found) //Make sure list isn't empty
	{

		//Check target is first item in list
		if(targetUser.GetName() == name && searchPtr == userList.GetHead())
		{
//			deletePtr = searchPtr; //deletion marker set at search target
//			searchPtr = searchPtr->GetNext(); //Move search marker to next node
//			userList.head = searchPtr;	//Repair head link to second element
//
//			delete deletePtr; //Delete

			userList.DeleteNode(1); //Explicitly call DeleteNode to handle head delete

			found = true;
		}
		else //Non-Primary Element Removal
		{
			searchPtr = searchPtr->GetNext(); //Move search marker to next node
			if(searchPtr != NULL) //Check if SearchPtr is Null, cannot hold data
			{
				targetUser = searchPtr->GetData();//Assign data to temp hold
			}

			if(targetUser.GetName() == name) //Check Element
			{
				deletePtr = searchPtr;//Deletion marker set to search target
				searchPtr = searchPtr->GetPrev(); //Move search ptr one node back

				if(deletePtr->GetNext() != NULL)//Check if target isn't last elem
				{
					//Node before deletion marker has it's next set to node located
					//after deletion Marker, repairing node
					searchPtr->SetNext(deletePtr->GetNext());

					delete deletePtr;
					found = true;
				}
				else //Deleting last element
				{
					searchPtr->SetNext(NULL);

					delete deletePtr;
					found = true;
				}
			}
		}
	}
}



string CustomerList::PrintCustList(){
	Node<User>* myUser;
	ostringstream output;
	myUser = userList.GetHead();

	while(myUser != NULL)
	{
		output << myUser->GetData().PrintUser();
		myUser = myUser->GetNext();
	}

	return output.str();
}

string CustomerList::PrintCustList(bool isKey){
	Node<User>* myUser;
	ostringstream output;
	myUser = userList.GetHead();

	while(myUser != NULL)
	{
		if(myUser->GetData().GetKey()){
		output << myUser->GetData().PrintUser();
		}
		myUser = myUser->GetNext();
	}

	return output.str();
}

string CustomerList::PrintCustWithTrans(){
	Node<User>* myUser;
	ostringstream output;
	myUser = userList.GetHead();

	while(myUser != NULL)
	{
		output << myUser->GetData().PrintUser();
		output << "\nOutputting all transactions for " << myUser->GetData().GetName() << endl;
		output << myUser->GetData().OutputTransactions();
		myUser = myUser->GetNext();
	}

	return output.str();
}

