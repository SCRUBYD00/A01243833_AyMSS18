#ifndef CLIENT_H
#define CLIENT_H

//----------LIBRARIES----------//

#include "Command.h"
#include <string>

class Client
{
private:

	//----------ATRIBUTES----------//

	string id;
	string cli_name;
	string cli_lname;
	string type_comm;
	string mail;
	string phone_num;
	string street;
	string s_num;
	string col;

	Receiver *re;
	Caller *call;

public:

	//----------METHODS----------//

	Client(){}

	Client(string i, string cn, string cln, string tc, string m, string pn, string s, string sn, string c) : id(i), cli_name(cn), cli_lname(cln), type_comm(tc), mail(m), phone_num(pn), street(s), s_num(sn), col(c)
	{
		re = new Receiver;
		call = new Caller;

		if (type_comm == "mail")
		{
			call->setCommand(new ConcreteCommandEmail(re));
		}

		if (type_comm == "phone_call")
		{
			call->setCommand(new ConcreteCommandPhone(re));
		}

		if (type_comm == "sms")
		{
			call->setCommand(new ConcreteCommandSMS(re));
		}
	}

	void contactFormat()
	{
		call->executeAction();
	}

	void printClientData()
	{
		cout << "ID: " << id << endl;
		cout << "Name: " << cli_name << " " << cli_lname << endl;
		cout << "Contact Method: " << type_comm << endl;
		cout << "Email: " << mail << endl;
		cout << "Phone: " << phone_num << endl;
		cout << "Address: " << street << ", " << s_num << ", " << col << endl << endl;
	}
};
#endif