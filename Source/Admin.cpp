#include "Admin.h"

Admin::Admin()
:User("Administrator")
{
	password = "password";
}

string Admin::GetPassword(){
	return password;
}



