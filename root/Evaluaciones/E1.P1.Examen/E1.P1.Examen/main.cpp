#include "Database.h"

int main()
{
	Database* instance = Database::getInstance();
	instance->readData("customer.txt");
	instance->printAllData();
	instance->contactClients();

	int x;
	cin >> x;

	return 0;
}