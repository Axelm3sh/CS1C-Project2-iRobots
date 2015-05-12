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
		string				  pampString;
		bool				  pampBool;



			while(!inFile.eof()){
				//newUser = new User;
				getline(inFile, myName);

				getline(inFile, myAddress);
				getline(inFile, myAddress2);
				getline(inFile, myRating);
				getline(inFile, myStringKey);
				if(myStringKey == "key")
				{
					myKey = true;
				}
				else{
					myKey = false;
				}
				getline(inFile, pampString);
				if(pampString == "not received"){
					pampBool = false;
				}
				else{
					pampBool = true;
				}

				newUser.SetValues(myName, myAddress, myAddress2,
								  myKey, myRating, pampBool);

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
		//output << "\nCustomer Info:\n";
		//output << myUser->GetData().PrintUser();
		//output << "Outputting all transactions for " << myUser->GetData().GetName() << endl;
		//output << "---------------------------------------------------";
		output << myUser->GetData().OutputTransactions();
		myUser = myUser->GetNext();
	}

	return output.str();
}



void CustomerList::RemoveCust(string name) //find ignore, check if list is empty, output of user that was deleted
{
	Node<User>* deletePtr;
	Node<User>* searchPtr;
	User targetUser;
	bool found = false;
	int count = 1;

	searchPtr = userList.GetHead(); //Assign search marker to head
	targetUser = searchPtr->GetData();//Put first node data in temp holder


	while(searchPtr != NULL && !found) //Make sure list isn't empty
	{

		//Check target is first item in list
		if(targetUser.GetName() == name && searchPtr == userList.GetHead())
		{
			userList.DeleteNode(1); //Explicitly call DeleteNode to handle head delete

			found = true;
		}
		else //Non-Primary Element Removal
		{
			searchPtr = searchPtr->GetNext(); //Move search marker to next node
			count ++;
			if(searchPtr != NULL) //Check if SearchPtr is Null, cannot hold data
			{
				targetUser = searchPtr->GetData();//Assign data to temp hold
			}

			if(targetUser.GetName() == name) //Check Element
			{

				deletePtr = searchPtr;//Deletion marker set to search target

				if(deletePtr->GetNext() != NULL)//Check if target isn't last elem
				{
					//Node before deletion marker has it's next set to node located
					//after deletion Marker, repairing node
					searchPtr->SetNext(deletePtr->GetNext());

					userList.DeleteNode(count);
					found = true;
				}
				else //Deleting last element
				{
					searchPtr->SetNext(NULL);

					count = userList.GetSize();
					userList.DeleteNode(count);
					found = true;
				}
			}
		}
	}

	if(!found)
	{
		cout << "User was not found!\n";
	}
	else
	{
		cout << targetUser.GetName() << " was found! Deleting user.\n";
	}
}


string CustomerList::SaveFile(){

	ostringstream output;
	Node<User>* myUser;

	myUser = userList.GetHead();

	while(myUser->GetNext() != NULL)
	{
		output << myUser->GetData().PrintUserToFile();
		output << endl;
		myUser = myUser->GetNext();
	}
	//prevents extra blank line being printed at the bottom of the file
	output << myUser->GetData().PrintUserToFile();

	return output.str();
}

Node<User>* CustomerList::SearchListByName(string name)
{
	Node<User>* searchPtr;
	User targetUser;
	bool found = false;

	searchPtr = userList.GetHead(); //Assign search marker to head
	targetUser = searchPtr->GetData();//Put first node data in temp holder

	while(searchPtr != NULL && !found) //Make sure list isn't empty
	{
		if(targetUser.GetName() == name) //Check Element
		{
				found = true;
		}
		else
		{
			searchPtr = searchPtr->GetNext(); //Move search marker to next node
			if(searchPtr != NULL) //ignore assign data if NULL
			{
				targetUser = searchPtr->GetData();//Put node data in temp holder
			}
		}
	}

	if(!found)
	{
		cout << "User was not found!\n";
	}
	else
	{
		cout << targetUser.GetName() << " was found!\n";
	}

	return searchPtr;
}

void CustomerList::EditCustomer(string name)
{
	Node<User>* searchPtr;
	bool found = false;
	int command;
	string newName;
	string newAddressOne;
	string newAddressTwo;
	string newRating;
	int    rating;
	char yesNo;
	bool newKey = false;
	bool valid = false;

	string menu = "\nWhat information would you like to edit?\n"
			       	    " 1) Name\n"
				   	    " 2) Address 1\n"
						" 3) Address 2\n"
				   	   	" 4) Rating\n"
				   	   	" 5) Key\n"
						" 0) EXIT\n"
						"Enter Command: ";

	string rateMenu =     "[1] - Very Interested"
						"\n[2] - Somewhat Interested"
						"\n[3] - Not Interested"
						"\n[4] - Never Call Again"
						"\nEnter new Rating: ";


	searchPtr = userList.GetHead(); //Assign search marker to head


	while(searchPtr != NULL && !found) //Make sure list isn't empty
	{

		//Check target is first item in list
		if(searchPtr->GetData().GetName() == name)
		{
//			command = BoundaryCheck(menu, 0, 5);
			// ************************
			// DELETE
			//************************

			command = BoundaryCheck(menu, 0, 5);

			while(command != 0)
			{
				switch(command)
				{
				case 1: cout << "Enter new name: ";
						getline(cin,newName);
						searchPtr->GetData().SetName(newName);
						break;
				case 2: cout << "Enter new Address 1: ";
						getline(cin,newAddressOne);
						searchPtr->GetData().SetAddress(newAddressOne);
						break;
				case 3: cout << "Enter new Address 2: ";
						getline(cin,newAddressTwo);
						searchPtr->GetData().SetAddress(newAddressTwo);
						break;
				case 4:

					rating = BoundaryCheck(rateMenu, 0, 4);

						switch (rating){
						case 1: newRating = "very interested";
							break;
						case 2: newRating = "somewhat interested";
							break;
						case 3: newRating = "somewhat interested";
							break;
						case 4:	newRating = "never call again";
						}
						searchPtr->GetData().SetRating(newRating);
						break;
				case 5: cout << "Set User As Key Customer(Yes/No): ";
						cin.get(yesNo);
						cin.ignore(100,'\n');
						while(!valid)
						{
							if(toupper(yesNo) == 'Y')
							{
								newKey = true;
								searchPtr->GetData().SetKey(newKey);
								valid = true;
							}
							else if(toupper(yesNo) == 'N')
							{
								newKey = false;
								searchPtr->GetData().SetKey(newKey);
								valid = true;
							}
							else
							{
								cout << "Edit key user(Y/N): ";
								cin.get(yesNo);
								cin.ignore(100,'\n');
							}
						}
						break;
				case 0 : cout << "Exiting.\n";
						break;

				}

				command = BoundaryCheck(menu, 0, 5);

			}

			found = true;
		}
		else
		{
			searchPtr = searchPtr->GetNext(); //Move search marker to next node
		}
	}

	searchPtr = NULL;
	delete searchPtr;
}

void CustomerList::CreateNewCustomer(){

	string newName;
	string newAddressOne;
	string newAddressTwo;
	string newRating;
	int    rating;
	char yesNo;
	bool newKey = false;
	bool valid = false;
	User newUser;

	string menu = "\nWhat information would you like to edit?\n"
			       	    " 1) Name\n"
				   	    " 2) Address 1\n"
						" 3) Address 2\n"
				   	   	" 4) Rating\n"
				   	   	" 5) Key\n"
						" 0) EXIT\n"
						"Enter Command: ";

	string rateMenu =     "[1] - Very Interested"
						"\n[2] - Somewhat Interested"
						"\n[3] - Not Interested"
						"\n[4] - Never Call Again"
						"\nEnter new Rating: ";

			 cout << "Enter new name: ";
			getline(cin,newName);

			 cout << "Enter new Address 1: ";
			getline(cin,newAddressOne);

			 cout << "Enter new Address 2: ";
			getline(cin,newAddressTwo);

				rating = BoundaryCheck(rateMenu, 0, 4);

					switch (rating){
					case 1: newRating = "very interested";
						break;
					case 2: newRating = "somewhat interested";
						break;
					case 3: newRating = "somewhat interested";
						break;
					case 4:	newRating = "never call again";
					}
		 cout << "Set User As Key Customer(Yes/No): ";
			cin.get(yesNo);
			cin.ignore(100,'\n');
			while(!valid)
			{
				if(toupper(yesNo) == 'Y')
				{
					newKey = true;
					valid = true;
				}
				else if(toupper(yesNo) == 'N')
				{
					newKey = false;
					valid = true;
				}
				else
				{
					cout << "Edit key user(Y/N): ";
					cin.get(yesNo);
					cin.ignore(100,'\n');
				}
			}


			newUser.SetValues(newName, newAddressOne,
					newAddressTwo, newKey, newRating, false);

			AddCust(newUser);
}

void CustomerList::SaveTransactions(string fileName){
	Node<User>* myUser;
	ostringstream output;
	myUser = userList.GetHead();
	ifstream inFile;
	ofstream oFile;
    string allTrans;

    //read in previous file so we can add to it without deleting
	//previous contents
	inFile.open(fileName.c_str());
	while(!inFile.eof()){
		getline(inFile, allTrans);
	output << allTrans << endl;
	}
	inFile.close();

	oFile.open(fileName.c_str());
	oFile << output.str();

	while(myUser != NULL)
	{
		oFile << myUser->GetData().OutputTransactions();
		myUser = myUser->GetNext();
	}

	oFile.close();
}
