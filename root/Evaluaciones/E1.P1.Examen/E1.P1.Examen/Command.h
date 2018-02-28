#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>

using namespace std;

class Command
{
public:
	virtual void execute() = 0;
};

class Receiver
{
public:
	void contactFormEmail()
	{
		cout << "Contacting Email" << endl;
	}

	void contactFormPhone()
	{
		cout << "Contacting Phone" << endl;
	}

	void contactFormSMS()
	{
		cout << "Contacting SMS" << endl;
	}
};

class Caller
{
private:
	Command *my_cmd;

public:
	void setCommand(Command *cmd)
	{
		my_cmd = cmd;
	}

	void executeAction()
	{
		my_cmd->execute();
	}
};

class ConcreteCommandEmail : public Command
{
private:
	Receiver *my_r;

public:
	ConcreteCommandEmail(Receiver *r) : my_r(r){}
	void execute()
	{
		my_r->contactFormEmail();
	}
};

class ConcreteCommandPhone : public Command
{
private:
	Receiver *my_r;

public:
	ConcreteCommandPhone(Receiver *r) : my_r(r) {}
	void execute()
	{
		my_r->contactFormPhone();
	}
};

class ConcreteCommandSMS : public Command
{
private:
	Receiver *my_r;

public:
	ConcreteCommandSMS(Receiver *r) : my_r(r) {}
	void execute()
	{
		my_r->contactFormSMS();
	}
};
#endif