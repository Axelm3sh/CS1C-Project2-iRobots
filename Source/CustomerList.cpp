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
				if(myStringKey == "key")
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
		output << "Outputting all transactions for " << myUser->GetData().GetName() << endl;
		output << "---------------------------------------------------";
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
		if(searchPtr != NULL && targetUser.GetName() == name) //Check Element
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
	char yesNo;
	bool newKey = false;
	bool valid = false;
	bool exit = false;


	string menu = "What information would you like to edit?\n"
			       	    " 1) Name\n"
				   	    " 2) Address 1\n"
						" 3) Address 2\n"
				   	   	" 4) Rating\n"
				   	   	" 5) Key\n"
						" 0) EXIT\n"
						"Enter Command: ";


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
			cout << menu;
			cin >> command;
			cin.ignore(100,'\n');

			while(!exit)
			{
				switch(command)
				{
				case 1: cout << "Enter new name: ";
						getline(cin,newName);
						searchPtr->GetData().SetName(newName);
						cout << searchPtr->GetData().GetName();
						cin.ignore();

						break;
				case 2: cout << "Enter new Address 1: ";
						getline(cin,newAddressOne);
						searchPtr->GetData().SetAddress(newAddressOne);
						break;
				case 3: cout << "Enter new Address 2: ";
						getline(cin,newAddressTwo);
						searchPtr->GetData().SetAddress(newAddressTwo);
						break;
				case 4: cout << "Enter new Rating: ";
						getline(cin,newRating);
						searchPtr->GetData().SetRating(newRating);
						break;
				case 5: cout << "Edit key user(Y/N): ";
						cin.get(yesNo);
						cin.ignore(100,'\n');
						while(!valid)
						{
							if(toupper(yesNo == 'Y'))
							{
								newKey = true;
								searchPtr->GetData().SetKey(newKey);
								valid = true;
							}
							else if(toupper(yesNo == 'N'))
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
						 exit = true;
						break;

				}

				cout << menu;
				cin >> command;
				cin.ignore(100,'\n');
			}

			found = true;
		}
		else //Non-Primary Element Removal
		{
			searchPtr = searchPtr->GetNext(); //Move search marker to next node
		}
	}

	searchPtr = NULL;
	delete searchPtr;
}


