//#include "FactoryMethod.h"
#include "Vehicles.h"

int main(int argc, const char * argv[])
{
	/* "FactoryMethod.h" main
	Creator* client = new ConcreteCreator();
	Product* myProduct = client->createProduct(1);*/

	Creator* retailer = new Creator();
	Vehicle* productCar = retailer->create<BMW>();

	int x;
	cin >> x;

	return 0;
}