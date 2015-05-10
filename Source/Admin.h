/*
 * Admin.h
 *
 *  Created on: May 5, 2015
 *      Author: Matt
 */

#ifndef ADMIN_H_
#define ADMIN_H_

#include <string>
#include "User.h"
using namespace std;

class Admin: public User{

public:

	Admin();
	~Admin();
	string GetPassword();

private:

	string password;
};



#endif /* ADMIN_H_ */
