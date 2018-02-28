#ifndef DATABASE_H
#define DATABASE_H

//----------LIBRARIES----------//

#include "Client.h"
#include <vector>
#include <fstream>
#include <sstream>

class Database
{
private:

	//----------ATRIBUTES----------//

	static Database* instance;
	Database(){}
	~Database(){}

	vector<Client*> cli_data;

public:

	//----------METHODS----------//

	static Database* getInstance()
	{
		if (instance == NULL)
		{
			instance = new Database;
		}

		return instance;
	}

	static bool deleteInstance()
	{
		if (instance != NULL)
		{
			delete instance;
			return true;
		}

		return false;
	}

	void readData(string archivo)
	{
		string i, cn, cln, tc, m, pn, s, sn, c;
		ifstream file;

		file.open("costumers.txt");

		while (getline(file, i, ',')) {
			getline(file, cn, ',');
			getline(file, cln, ',');
			getline(file, tc, ',');
			getline(file, m, ',');
			getline(file, pn, ',');
			getline(file, s, ',');
			getline(file, sn, ',');
			getline(file, c, '\n');

			Client *cli = new Client(i, cn, cln, tc, m, pn, s, sn, c);
			cli_data.push_back(cli);
		}

		file.close();
	}

	void contactClients()
	{
		for (int i = 0; i < cli_data.size(); i++)
			cli_data.at(i)->contactFormat();
	}

	void printAllData()
	{
		for (int i = 0; i < cli_data.size(); i++)
			cli_data.at(i)->printClientData();
	}
};

Database* Database::instance = NULL;

#endif
