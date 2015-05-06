#include "myHeader.h"
#include "BoundaryCheck.cpp"

int main(){


//	int menuOption;   //PROC - used to process user input and decide which menu
//					  //       paths to take
//
//	menuOption = BoundaryCheck(login, 0, 4);
//
//	if(menuOption == 1)
//	{
//		//while the user wishes to stay in the program
//		while(menuOption != 0){
//
//		menuOption = BoundaryCheck(mainMenu, 0, 4);
//
//		switch (menuOption)
//		{
//		//Enter the shop
//		case 1:
//			menuOption = BoundaryCheck(shopMenu, 0, 2);
//
//			//nested switch process shop operations
//			switch(menuOption)
//			{
//			case 1:
//				cout << "...purchase options...\n";
//
//				cout << "Press any key to continue";
//				cin.ignore();
//				break;
//			case 2:
//				cout << "...edit previous transactions...\n";
//
//				cout << "Press any key to continue";
//				cin.ignore();
//				break;
//			case 3:
//				cout << "...testimonial operations...\n";
//
//				cout << "Press any key to continue";
//				cin.ignore();
//				break;
//			default:
//				cout << "returning to main menu";
//
//				cout << "Press any key to continue";
//				cin.ignore();
//			}
//			break;
//
//		//Get Information
//		case 2:
//			//nested switch process Get Info operations
//			menuOption = BoundaryCheck(getInfoMenu, 0, 7);
//			switch(menuOption)
//			{
//			case 1:
//				cout << "...robot destription...\n";
//
//				cout << "Press any key to continue";
//				cin.ignore();
//				break;
//			case 2:
//				cout << "..warranty info...\n";
//
//				cout << "Press any key to continue";
//				cin.ignore();
//				break;
//			case 3:
//				cout << "..payment plans...\n";
//
//				cout << "Press any key to continue";
//				cin.ignore();
//				break;
//			case 4:
//				cout << "..faq...\n";
//
//				cout << "Press any key to continue";
//				cin.ignore();
//				break;
//			case 5:
//				cout << suitableEnvironment;
//
//				cout << "Press any key to continue";
//				cin.ignore();
//				break;
//			case 6:
//				cout << salesPitch;
//
//				cout << "Press any key to continue";
//				cin.ignore();
//				break;
//			case 7:
//				cout << "..contact us...\n";
//
//				cout << "Press any key to continue";
//				cin.ignore();
//			}
//			break;
//
//		case 3:
//			menuOption = BoundaryCheck(testimonialMenu, 0, 2);
//			//nested switch process testimonial operations
//			switch(menuOption)
//			{
//			case 1:
//				cout << "...read testimonials...\n";
//
//				cout << "Press any key to continue";
//				cin.ignore();
//				break;
//			case 2:
//				cout << "...add testimonials...\n";
//
//				cout << "Press any key to continue";
//				cin.ignore();
//				break;
//			default:
//				cout << "returning to main menu";
//			}
//			break;
//
//
//			break;
//		//Request a Pamphlet
//		case 4:
//
//			cout << "..confirm that pamphlet will be sent...\n";
//
//			cout << "Press any key to continue";
//			cin.ignore();
//
//		}//end main user option switch statement
//
//
//		}//end while(menuOption != 0)
//
//	}//end if
//
//	//if logging in as an admin
//	else if(menuOption == 2)
//	{
//		//while the user wishes to stay in the program
//		while(menuOption != 0){
//
//		menuOption = BoundaryCheck(mainMenuAdmin, 0, 6);
//
//		switch (menuOption)
//		{
//		//Enter the shop
//		case 1:
//			menuOption = BoundaryCheck(shopMenu, 0, 2);
//
//			//nested switch process shop operations
//			switch(menuOption)
//			{
//			case 1:
//				cout << "...purchase options...\n";
//
//				cout << "Press any key to continue";
//				cin.ignore();
//				break;
//			case 2:
//				cout << "...edit previous transactions...\n";
//
//				cout << "Press any key to continue";
//				cin.ignore();
//				break;
//			case 3:
//				cout << "...testimonial operations...\n";
//
//				cout << "Press any key to continue";
//				cin.ignore();
//				break;
//			default:
//				cout << "returning to main menu";
//
//				cout << "Press any key to continue";
//				cin.ignore();
//			}
//			break;
//
//		//Get Information
//		case 2:
//			//nested switch process Get Info operations
//			menuOption = BoundaryCheck(getInfoMenu, 0, 7);
//			switch(menuOption)
//			{
//			case 1:
//				cout << "...robot destription...\n";
//
//				cout << "Press any key to continue";
//				cin.ignore();
//				break;
//			case 2:
//				cout << "..warranty info...\n";
//
//				cout << "Press any key to continue";
//				cin.ignore();
//				break;
//			case 3:
//				cout << "..payment plans...\n";
//
//				cout << "Press any key to continue";
//				cin.ignore();
//				break;
//			case 4:
//				cout << "..faq...\n";
//
//				cout << "Press any key to continue";
//				cin.ignore();
//				break;
//			case 5:
//				cout << suitableEnvironment;
//
//				cout << "Press any key to continue";
//				cin.ignore();
//				break;
//			case 6:
//				cout << salesPitch;
//
//				cout << "Press any key to continue";
//				cin.ignore();
//				break;
//			case 7:
//				cout << "..contact us...\n";
//
//				cout << "Press any key to continue";
//				cin.ignore();
//			}
//			break;
//
//		case 3:
//			menuOption = BoundaryCheck(testimonialMenu, 0, 2);
//			//nested switch process testimonial operations
//			switch(menuOption)
//			{
//			case 1:
//				cout << "...read testimonials...\n";
//
//				cout << "Press any key to continue";
//				cin.ignore();
//				break;
//			case 2:
//				cout << "...add testimonials...\n";
//
//				cout << "Press any key to continue";
//				cin.ignore();
//			}
//			break;
//
//
//			break;
//		//Request a Pamphlet
//		case 4:
//
//			cout << "..confirm that pamphlet will be sent...\n";
//
//			cout << "Press any key to continue";
//			cin.ignore();
//			break;
//			//Edit customer information
//			case 5:
//					cout << "...edit customer menu...\n";
//
//					cout << "Press any key to continue";
//					cin.ignore();
//
//				break;
//			//View/Print customer List
//			case 6:
//				menuOption = BoundaryCheck(viewCustomerListMenu, 0, 3);
//				//nested switch process view/print customer list operations
//				switch(menuOption)
//				{
//				case 1:
//					cout << "...View Customer LIst..\n";
//
//					cout << "Press any key to continue";
//					cin.ignore();
//					break;
//				case 2:
//					cout << "...Edit Customer List...\n";
//
//					cout << "Press any key to continue";
//					cin.ignore();
//					break;
//				case 3:
//					cout << "...Print Customer List..\n";
//
//					cout << "Press any key to continue";
//					cin.ignore();
//					break;
//				}
//				break;
//
//		}//end main user option switch statement
//
//
//		}//end while(menuOption != 0)
//
//	}//end if

return 0;
}
