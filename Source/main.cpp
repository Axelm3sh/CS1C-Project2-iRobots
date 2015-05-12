#include "myHeader.h"


int main(){

	//initialize the list from file VVVVVVVVVVVVVVVVVVVVVVVVV
	ifstream inFile;
	ofstream oFile;
	inFile.open("myFile.txt");
	CustomerList *myList;
	myList = new CustomerList(inFile);
	inFile.close();

	bool loggedIn; //PROC - used to check if successful login

	string       userName;     //IN   - used to search for "logging in"
	Node<User>*  currentUser; //PROC - used to access menu options as current user

	Transaction* myTrans;
	int          robotQuantity;
	int			 robotModel;
	bool         maintBool;
	int			 maintInt;
	int day;
	int month;
	int year;

	bool isAdmin = false;

	//used for guest to request pamphlet
	string guestName;
	string guestAddrLine1;
	string guestAddrLine2;
	ostringstream outputPamph;
	string        pamphletString;
	bool pamphletRequested = false;

	//used to initialize date to today's date for ouput data
	struct tm * todayTime;
	time_t timeNow;
	time(&timeNow);
	todayTime = localtime(&timeNow );
	day   = todayTime->tm_mday;
	month = todayTime->tm_mon + 1;
	year  = (todayTime->tm_year) + 1900;
	Date today(month, day, year);

	//check to see if a trans was made at all
	bool transactionMade = false;

	//Used for Testimonials
	TestimonialList testList;
	TestimonialNode newNode;
	testList = TakeInput();

	oFile.open("myFile.txt");
	oFile << myList->SaveFile();
	oFile.close();

	int menuOption;   //PROC - used to process user input and decide which menu
					  //       paths to take
	const int userEndBound   = 4;
	const int adminEndBound  = 7;
	const int guestEndBound  = 3;
	int		  endBound;
	string    mainMenu;

	string userToChange;
	bool   userChanged = false;

	loggedIn = false;

	Admin myAdmin;
	string adminPassword;

	menuOption = BoundaryCheck(login, 0, 4);

	//CHECK to see if user, administrator, or guest
while(userName != "exit" && !loggedIn)
{
	switch(menuOption)
	{
	case 1:

		endBound = userEndBound;
		mainMenu  = mainMenuUser;

		cout << "\nEnter Username: ";
		getline(cin,userName);

		//validate that customer exists
		while(userName != "exit" && !loggedIn)
		{
			currentUser = myList->SearchListByName(userName);

			if(currentUser != NULL)
			{
				loggedIn = true;
			cout << "\nHello " << currentUser->GetData().GetName() << ", Welcome to the iRobot Shop!\n";
			}
			else
			{
				cout << "\nPlease try again or enter 'exit' to quit program: ";
				getline(cin,userName);
			}
		}//end while(userName != "exit" && !loggedIn)
		break;
	case 2:
		cout << "\nEnter Administrator Password: ";
		getline(cin,adminPassword);
		//validate  admin privileges
		while(adminPassword != "exit" && !loggedIn)
		{
			if(adminPassword == myAdmin.GetPassword())
			{

				endBound = adminEndBound;
				mainMenu  = mainMenuAdmin;
				cout << "\nHello Administrator, Welcome to the iRobot Shop!\n";
				isAdmin = true;
				loggedIn = true;
			}
			else
			{
				cout << "\nPlease try again or enter 'exit' to quit program: ";
					getline(cin,adminPassword);
					//if they type exit set userName as exit to escape while loop
					if(adminPassword == "exit")
							userName = "exit";
			}
		}//end while
		break;
	case 3:
		endBound = guestEndBound;
		mainMenu  = mainMenuGuest;
		loggedIn = true;
		cout << "\nHello Prospective Customer, Welcome to the iRobot Shop!\n";
		break;
	case 4: cout << HALPME;

			menuOption = BoundaryCheck(login, 0, 4);
		break;
	default:
		userName = "exit";
	}
}//end userName != "exit"

//check to see if unvalidated user chose to exit
if(userName != "exit" && adminPassword != "exit"){

	menuOption = BoundaryCheck(mainMenu, 0, endBound);

		//while the user wishes to stay in the program
		while(menuOption != 0){

		switch (menuOption)
		{


		//Get Information
		case 1:
			//nested switch process Get Info operations
			menuOption = BoundaryCheck(getInfoMenu, 0, 7);
			switch(menuOption)
			{
			case 1:
				cout << robotDescrip;

				cout << "Press any key to continue";
				cin.ignore();
				break;
			case 2:
				cout << warrantyInfo;

				cout << "Press any key to continue";
				cin.ignore();
				break;
			case 3:
				cout << paymentPlans;

				cout << "Press any key to continue";
				cin.ignore();
				break;
			case 4:
				cout << FAQUs;

				cout << "Press any key to continue";
				cin.ignore();
				break;
			case 5:
				cout << suitableEnvironment;

				cout << "Press any key to continue";
				cin.ignore();
				break;
			case 6:
				cout << salesPitch;

				cout << "Press any key to continue";
				cin.ignore();
				break;
			case 7:
				cout << contactUs;

				cout << "Press any key to continue";
				cin.ignore();
			}
			break;

			//Request a Pamphlet
			case 2:
				//check if pamphlet already requested in session
				if(!pamphletRequested){

					menuOption = BoundaryCheck(pamphMenu, 0, 2);

					if(menuOption == 1){
						pamphletRequested = true;
						//check endBound to see if guest, user, or admin
						if(endBound == adminEndBound)
						{
							cout << "\nYou do not need a pamphlet, you are an admin!\n";
							pamphletRequested = false; //Admin reinstialize false
						}
						else
						{

							inFile.open(pamphletFile.c_str());
								while(!inFile.eof())
								{
									getline(inFile, pamphletString);
								outputPamph << pamphletString << endl;
								}
								inFile.close();

								oFile.open(pamphletFile.c_str());
								oFile << outputPamph.str();
								outputPamph.str("");
								outputPamph.clear();


								if(endBound == userEndBound){
									//check if current user already received pamphlet
									if(currentUser->GetData().GetPampReceived()){
										cout << "\nPamphlet has already been sent and is"
												" currently on the way!\n";
									}
									else{
									currentUser->GetData().RequestPamphlet();

									oFile << "\n--------------------------------------------\n";
									oFile << "Pamphlet Requested On " << today.DisplayDate()
										  << " by " << currentUser->GetData().GetName() << endl;
									oFile << "Send To:\n" << currentUser->GetData().GetAddressLine1() << endl;
									oFile << currentUser->GetData().GetAddressLine2();
									oFile << "\n--------------------------------------------\n";
									}
								}
								//guest
								else{
									cout << "Please provide some basic information so we can"
											" get our pamphlet to you!\n";
									cout << "Name:           ";
									getline(cin, guestName);
									cout << "Address Line 1: ";
									getline(cin, guestAddrLine1);
									cout << "Address Line 2: ";
									getline(cin, guestAddrLine2);

									oFile << "\n--------------------------------------------\n";
									oFile << "Pamphlet Requested On " << today.DisplayDate()
										  << " by " << guestName << endl;
									oFile << "Send To:\n" << guestAddrLine1 << endl;
									oFile << guestAddrLine2;
									oFile << "\n--------------------------------------------\n";
								}
								oFile.close();

							}

					}//end if(menuOption == 1)
				}//end if(pamphlet requested)
				else
				{
					cout << "\nYou have already requested a pamphlet this session,"
							" iRobot has been informed\n"
							"and is currently working to get it to you ASAP!\n";
				}

				cout << "Press any key to continue";
				cin.ignore();
				break;
		case 3:
			menuOption = BoundaryCheck(testimonialMenu, 0, 2);
			//nested switch process testimonial operations
			switch(menuOption)
			{
			case 1:
				cout << "Reviews from previous purchasers of the iRobot Bomb Detector:\n";

				testList.PrintAll();

				cout << "Press any key to continue";
				cin.ignore();
				break;
			case 2:
				cout << "If you have purchased a bomb detector in the past, please give your feedback.\n";

				newNode = NewTestimonial();

				if(newNode.user != "")
				{
					testList.Add(newNode);

					WriteToFile(testList);
				}
				cout << "\nPress any key to continue\n";
				cin.ignore();
			}
			break;


			break;


		//Enter the shop
		case 4:
			menuOption = BoundaryCheck(shopMenu, 0, 2);

			//nested switch process shop operations
			switch(menuOption)
			{
			case 1:
				cout << paymentPlans;

				cout << "Press any key to continue";
				cin.ignore();
				break;
			case 2:
				if(!isAdmin){
				transactionMade = true;
				robotModel    = BoundaryCheck(buyRobotType, 0, 3);
				robotQuantity = BoundaryCheck(howManyRobots, 0, 5);
				maintInt      = BoundaryCheck(maintPlan, 0, 3);
				if(maintInt == 1)
				{
					maintBool = true;
				}
				else{
					maintBool = false;
				}

				myTrans = new Transaction(today, robotModel, maintBool, robotQuantity);

				currentUser->GetData().AddTransaction(*myTrans);

				delete myTrans;
				}
				else{
					cout << "\nAdministrators can not make purchases!\n"
							"If you want to make a purchase add yourself as a "
							"new customer then log in as a user!\n\n";
				}

				cout << "Press any key to continue";
				cin.ignore();
				break;
			default:
				cout << "returning to main menu";

				cout << "Press any key to continue";
				cin.ignore();
			}
			break;
			//Edit customer information
			case 5:
				cout << "\nPlease enter the user you would like to edit: ";
				getline(cin, userToChange);
				userChanged = false; //Reinitialize
				while(userToChange != "exit" && !userChanged)
				{
					if(myList->SearchListByName(userToChange) != NULL)
					{
						myList->EditCustomer(userToChange);
						userChanged = true;
					}
					else
					{
						cout << "\nPlease try again or enter 'exit' to return to main menu: ";
							getline(cin,userToChange);
					}
				}

				userToChange.clear();

					cout << "Press any key to continue";
					cin.ignore();

				break;
			//View/Print customer List
			case 6:
				menuOption = BoundaryCheck(viewCustomerListMenu, 0, 4);
				//nested switch process view/print customer list operations

				switch(menuOption) {

				case 1:

					cout << myList->PrintCustList();

					cout << "\nPress any key to continue";
					cin.ignore();
					break;
				case 2:
					cout << myList->PrintCustList(true);
					cout << "\nPress any key to continue";
								cin.ignore();
					break;
				case 3:
					oFile.open("myFile.txt");
					oFile << myList->SaveFile();
					oFile.close();

					delete myList;
					inFile.open("myFile.txt");
					myList = new CustomerList(inFile);
					inFile.close();

					oFile.open("PrintedCustomerFile.txt");
					oFile << myList->PrintCustList();
					oFile.close();

					cout << "\nCustomer File has been updated!";
					cout << "\nPress any key to continue";
					cin.ignore();
					break;
				case 4:
					oFile.open("PrintedKeyCustomerFile.txt");
					oFile << myList->PrintCustList(true);
					oFile.close();

					cout << "\nPress any key to continue";
								cin.ignore();

				}
			break;
			case 7:
					myList->CreateNewCustomer();
		}//end main user option switch statement

		menuOption = BoundaryCheck(mainMenu, 0, endBound);

		}//end while(menuOption != 0)

	oFile.open("myFile.txt");
	oFile << myList->SaveFile();
	oFile.close();

//	oFile.open("transactions.txt");
//	oFile << myList.PrintCustWithTrans();
//	oFile.close();

	//OUTPUT - only output transactions if one was made
	if(transactionMade){
	myList->SaveTransactions("transactionFile.txt");
	}

	oFile.open("PrintedCustomerFile.txt");
	oFile << myList->PrintCustList();
	oFile.close();
}

	cout << "\nThank you for using this program";

return 0;
}
