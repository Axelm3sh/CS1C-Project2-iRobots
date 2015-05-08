#include "myHeader.h"
#include "BoundaryCheck.cpp"

int main(){



	//initialize the list from file VVVVVVVVVVVVVVVVVVVVVVVVV
	ifstream inFile;
	ofstream oFile;
	inFile.open("inFile.txt");
	CustomerList myList(inFile);
	inFile.close();

	Node<User>* newUser;
	Transaction myTrans;



	//newUser = myList.SearchListByName("Saddleback College");
	myList.EditCustomer("Saddleback College");

//	newUser = myList.SearchListByName("CIA");
//	newUser->GetData().SetName("aslkdjfkldsf");


	cout << myList.PrintCustList();

	//cout << newUser->GetData().PrintUser();

	oFile.open("myFile.txt");
	oFile << myList.SaveFile();
	oFile.close();

	cout << myList.PrintCustList();

	//the menu down below is updated!!!

	int menuOption;   //PROC - used to process user input and decide which menu
					  //       paths to take
	const int userEndBound  = 4;
	const int adminEndBound = 6;
	int		  endBound;
	string    mainMenu;

	menuOption = BoundaryCheck(login, 0, 2);

	if(menuOption == 1)
	{
		endBound = userEndBound;
		mainMenu  = mainMenuUser;
	}
	else{
		endBound = adminEndBound;
		mainMenu  = mainMenuAdmin;
	}


		//while the user wishes to stay in the program
		while(menuOption != 0){

		menuOption = BoundaryCheck(mainMenu, 0, endBound);

		switch (menuOption)
		{
		//Enter the shop
		case 1:
			menuOption = BoundaryCheck(shopMenu, 0, 2);

			//nested switch process shop operations
			switch(menuOption)
			{
			case 1:
				cout << "...purchase options...\n";

				cout << "Press any key to continue";
				cin.ignore();
				break;
			case 2:
				cout << "...edit previous transactions...\n";

				cout << "Press any key to continue";
				cin.ignore();
				break;
			case 3:
				cout << "...testimonial operations...\n";//TODO fixplz

				cout << "Press any key to continue";
				cin.ignore();
				break;
			default:
				cout << "returning to main menu";

				cout << "Press any key to continue";
				cin.ignore();
			}
			break;

		//Get Information
		case 2:
			//nested switch process Get Info operations
			menuOption = BoundaryCheck(getInfoMenu, 0, 7);
			switch(menuOption)
			{
			case 1:
				cout << "...robot destription...\n";

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
				cout << "..faq...\n";

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

		case 3:
			menuOption = BoundaryCheck(testimonialMenu, 0, 2);
			//nested switch process testimonial operations
			switch(menuOption)
			{
			case 1:
				cout << "...read testimonials...\n";

				cout << "Press any key to continue";
				cin.ignore();
				break;
			case 2:
				cout << "...add testimonials...\n";

				cout << "Press any key to continue";
				cin.ignore();
			}
			break;


			break;
		//Request a Pamphlet
		case 4:

			menuOption = BoundaryCheck(pamphMenu, 0, 2);

			if(menuOption == 1){

			}

			cout << "Press any key to continue";
			cin.ignore();
			break;
			//Edit customer information
			case 5:
					cout << "...edit customer menu...\n";

					cout << "Press any key to continue";
					cin.ignore();

				break;
			//View/Print customer List
			case 6:
				menuOption = BoundaryCheck(viewCustomerListMenu, 0, 3);
				//nested switch process view/print customer list operations
				switch(menuOption)
				{
				case 1:
					cout << "...View Customer LIst..\n";

					cout << "Press any key to continue";
					cin.ignore();
					break;
				case 2:
					cout << "...Edit Customer List...\n";

					cout << "Press any key to continue";
					cin.ignore();
					break;
				case 3:
					cout << "...Print Customer List..\n";

					cout << "Press any key to continue";
					cin.ignore();
					break;
				}
				break;

		}//end main user option switch statement

		menuOption = BoundaryCheck(mainMenu, 0, endBound);

		}//end while(menuOption != 0)

	oFile.open("myFile.txt");
	oFile << myList.SaveFile();
	oFile.close();

	oFile.open("transactions.txt");
	oFile << myList.PrintCustWithTrans();
	oFile.close();

return 0;
}
