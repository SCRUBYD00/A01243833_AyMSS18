//#include "Clone.h"
//#include "Prototype.h"
#include "Mobiles.h"

int main()
{
	// main para "Clone.h"
	/*Prueba p;
	Prueba* z = new Prueba(2);

	cout << "Antes " << *(z->val) << endl;

	Prueba w = *z;
	
	cout << "Copia " << *w.val << endl;

	*w.val = 8;

	cout << "Original z: " << *(z->val) << endl;
	cout << "Copia w: " << *(w.val) << endl;*/
	
	// main para "Prototype.h"
	/*Concrete1* c1 = new Concrete1;*/

	Mobiles* t = new Tablet("Samsung", "TS3", "Hector", "1.0");
	Mobiles* t2 = new Tablet("Apple", "iPad", "Locatel", "2.0");
	Mobiles* sp = new Smartphone("Samsung", "S8", "Pedro", "2.11");
	Mobiles* sp2 = new Smartphone("Apple", "iPhone", "Antony", "3.21");
	Mobiles* sw = new Smartwatch("Samsung", "Galaxy Gear 2", "Chucho", "1.0");
	Mobiles* sw2 = new Smartwatch("Apple", "Apple Watch", "Jacinto", "1.2");
	
	t->turnOn();
	t->turnOff();
	t->restart();
	t->reset();
	t2->turnOn();
	t2->turnOff();
	t2->restart();
	t2->reset();
	sp->turnOn();
	sp->turnOff();
	sp->restart();
	sp->reset();
	sp2->turnOn();
	sp2->turnOff();
	sp2->restart();
	sp2->reset();
	sw->turnOn();
	sw->turnOff();
	sw->restart();
	sw->reset();
	sw2->turnOn();
	sw2->turnOff();
	sw2->restart();
	sw2->reset();



	int x;
	cin >> x;

	return 0;
}