//	Hector Alberto Lopez Palomino		A01243833		Examen 2

#ifndef EVALUACION_H
#define EVALUACION_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Visitor
{
public:
	virtual void visit(Estrategia&) = 0;
	virtual void visit(Aventura&) = 0;
	virtual void visit(Aprendizaje&) = 0;
};

class IncrementVisitor : public Visitor
{
public:
	void visit(Estrategia& est)
	{
		est.precio = est.precio * 1.1;
	}

	void visit(Aventura& ave)
	{
		ave.precio = ave.precio * 1.1;
	}

	void visit(Aprendizaje& apr)
	{
		apr.precio = apr.precio * 1.1;
	}
};

class DecrementVisitor : public Visitor
{
	void visit(Estrategia& est)
	{
		est.precio = est.precio / 1.1;
	}

	void visit(Aventura& ave)
	{
		ave.precio = ave.precio / 1.1;
	}

	void visit(Aprendizaje& apr)
	{
		apr.precio = apr.precio / 1.1;
	}
};

class Observer
{
public:
	virtual void update(string, Juego*) = 0;
};

class Client : public Observer
{
private:
	string titulo;

public:
	void update(string l, Juego* j)
	{
		cout << titulo << ", recuerda que ya llego a el juego " << j->getTitulo << " pasa a cualquiera de nuestras sucursales a comprarlo!" << endl;
	}
};

class Juego
{
	friend class Almacen;
protected:
	int numSerie;
	float precio;
	string titulo;
	string lanzamiento;
	vector <Observer*> clientes;

public:
	virtual Juego* clone() = 0;
	virtual void accept(Visitor*) = 0;

	void Concepcion()
	{
		cout << titulo << "Ejecutando Metodo: CONCEPCION..." << endl;
	}

	void Diseno()
	{
		cout << titulo << "Ejecutando Metodo: DISENO..." << endl;
	}

	void Planificacion()
	{
		cout << titulo << "Ejecutando Metodo: PLANIFICACION..." << endl;
	}

	void Produccion()
	{
		cout << titulo << "Ejecutando Metodo: PRODUCCION..." << endl;
	}

	void Prueba()
	{
		cout << titulo << "Ejecutando Metodo: PRUEBA..." << endl;
	}

	string getTitulo()
	{
		return titulo;
	}

	void attach(Observer* o) {
		clientes.push_back(o);
	}

	void dettach(Observer* o)
	{
		for (int i = 0; i < clientes.size(); i++)
		{
			if (clientes[i] == o)
			{
				clientes.erase(clientes.begin() + i);
				return;
			}
		}
	}

	void notifyAll(string release, Juego* vg)
	{
		for (int i = 0; i < clientes.size(); i++)
		{
			clientes[i]->update(release, vg);
		}
	}

	bool operator < (const Juego& cmp) const
	{
		return (precio < cmp.precio);
	}

	bool operator > (const Juego& cmp) const
	{
		return (precio > cmp.precio);
	}
};

template <class Subclass>
class CloneCRTP : public Juego
{
public:
	Juego* clone()
	{
		return new Subclass(*this);
		return new dynamic_cast <Subclass&> (*this);
	}
};

class Estrategia : public CloneCRTP<Estrategia>
{
	friend class IncrementVisitor;
	friend class DecrementVisitor;
	
protected:
	int nivel;
	string nomPersonaje;
	string raza;

public:
	Estrategia()
	{

	}

	Estrategia(int ns, float p, string t, string l)
	{
		numSerie = ns;
		precio = p;
		titulo = t;
		lanzamiento = l;
	}

	Estrategia(const Estrategia& temp)
	{
		numSerie = temp.numSerie;
		precio = temp.precio;
		titulo = temp.titulo;
		lanzamiento = temp.lanzamiento;
	}

	Juego* clone()
	{
		return new Estrategia(*this);
	}

	void accept(Visitor* v)
	{
		v->visit(*this);
	}
};

class Aventura : public CloneCRTP<Aventura>
{
	friend class IncrementVisitor;
	friend class DecrementVisitor;

protected:
	int vida;
	int armadura;
	int dano;

public:
	Aventura()
	{

	}

	Aventura(int ns, float p, string t, string l)
	{
		numSerie = ns;
		precio = p;
		titulo = t;
		lanzamiento = l;
	}

	Aventura(const Aventura& temp)
	{
		numSerie = temp.numSerie;
		precio = temp.precio;
		titulo = temp.titulo;
		lanzamiento = temp.lanzamiento;
	}

	Juego* clone()
	{
		return new Aventura(*this);
	}

	void accept(Visitor* v)
	{
		v->visit(*this);
	}
};

class Aprendizaje : public CloneCRTP<Aprendizaje>
{
	friend class IncrementVisitor;
	friend class DecrementVisitor;

protected:
	int puntuacion;

public:
	Aprendizaje()
	{

	}

	Aprendizaje(int ns, float p, string t, string l)
	{
		numSerie = ns;
		precio = p;
		titulo = t;
		lanzamiento = l;
	}

	Aprendizaje(const Aprendizaje& temp)
	{
		numSerie = temp.numSerie;
		precio = temp.precio;
		titulo = temp.titulo;
		lanzamiento = temp.lanzamiento;
	}

	Juego* clone()
	{
		return new Aprendizaje(*this);
	}

	void accept(Visitor* v)
	{
		v->visit(*this);
	}
};

class Creator
{
private:
	static Creator* instance;
	static int cont;

	Creator()
	{
		cont = 0;
	}

	~Creator()
	{

	}

	static void addRef()
	{
		cont++;
	}

	static void delRef()
	{
		--cont;
	}

public:

	static Creator* getInstance()
	{
		if (instance == nullptr)
		{
			instance = new Creator;
		}

		addRef();
		return instance;
	}

	static void destroyInstance()
	{
		delRef();

		if (instance != nullptr && cont == 0)
		{
			delete instance;
			instance = nullptr;
		}
	}

	template <class VJ>
	VJ* factMethod(int, float, string, string)
	{
		return new J(ns, p, t, l);
	}

	template <class VJ>
	VJ* create(int, float, string, string)
	{
		VJ* juego = factMethod(ns, p, t, l);
		juego->Concepcion();
		juego->Diseno();
		juego->Planificacion();
		juego->Produccion();
		juego->Prueba();
		return juego;
	}
};

Creator* Creator::instance = nullptr;

class Almacen 
{
private:
	vector<Juego*> almacen;

public:
	Almacen()
	{

	}

	void agregarJuego(Juego* v)
	{
		almacen.push_back(v);
	}

	void eliminarTitulo(string t)
	{
		for (int i = 0; i < almacen.size(); i++)
		{
			if (almacen[i]->titulo == t)
			{
				almacen.erase(almacen.begin() + i);
				break;
			}

			else if (i == almacen.size())
			{
				cout << "ERROR: JUEGO NO EXISTENTE!!" << endl;
			}
		}
	}

	void eliminarNumSerie(int ns)
	{
		for (int i = 0; i < almacen.size(); i++)
		{
			if (almacen[i]->numSerie == ns)
			{
				almacen.erase(almacen.begin() + i);
				break;
			}

			else if (i == almacen.size())
			{
				cout << "ERROR: JUEGO NO EXISTENTE!!" << endl;
			}
		}
	}
	
	void organizaAlmacen()
	{
		sort(almacen.begin(), almacen.end());
	}

	void buscaTitulo(string t)
	{
		if (almacen.size() == 0)
		{
			cout << endl << "ERROR: EL ALMACEN SE ENCUENTRA VACIO!!" << endl;
		}

		else
		{
			for (int i = 0; i < almacen.size(); i++)
			{
				if (almacen[i]->titulo == t)
				{
					cout << "Juego #" << i << "\n";
					cout << "Titulo: " << almacen[i]->titulo << "\n";
					cout << "Fecha de Lanzamiento: " << almacen[i]->lanzamiento << "\n";
					cout << "Precio: " << almacen[i]->precio << "\n";
					cout << "# Serial: " << almacen[i]->numSerie << "\n\n";
				}

				else
				{
					cout << "ERROR: NO SE PUDO ENCONTRAR EL JUEGO!!" << endl;
				}
			}
		}
	}

	void buscaNumSerie(int ns)
	{
		if (almacen.size() == 0)
		{
			cout << endl << "ERROR: EL ALMACEN SE ENCUENTRA VACIO!!" << endl;
		}

		else
		{
			for (int i = 0; i < almacen.size(); i++)
			{
				if (almacen[i]->numSerie == ns)
				{
					cout << "Juego #" << i << "\n";
					cout << "Titulo: " << almacen[i]->titulo << "\n";
					cout << "Fecha de Lanzamiento: " << almacen[i]->lanzamiento << "\n";
					cout << "Precio: " << almacen[i]->precio << "\n";
					cout << "# Serial: " << almacen[i]->numSerie << "\n\n";
				}

				else
				{
					cout << "ERROR: NO SE PUDO ENCONTRAR EL JUEGO!!" << endl;
				}
			}
		}
	}

	int tamanoAlmacen() 
	{
		return almacen.size();
	}

	void imprimirAlmacen()
	{
		if (almacen.size() == 0)
		{
			cout << endl << "No hay juegos en el almacen" << endl;
		}

		else
		{
			for (int i = 0; i < almacen.size(); i++)
			{
				cout << "Juego #" << i << "\n";
				cout << "Titulo: " << almacen[i]->titulo << "\n";
				cout << "Fecha de Lanzamiento: " << almacen[i]->lanzamiento << "\n";
				cout << "Precio: " << almacen[i]->precio << "\n";
				cout << "# Serial: " << almacen[i]->numSerie << "\n\n";
			}
		}
	}

	void accept(Visitor* visitor)
	{
		for (int i = 0; i < almacen.size(); i++)
		{
			almacen[i]->accept(visitor);
		}
	}

	void cambioPrecio(bool cambio)
	{
		if (cambio)
		{
			IncrementVisitor* incrementVisitor = new IncrementVisitor;
			accept(incrementVisitor);
		}

		else
		{
			DecrementVisitor* decrementvisitor = new DecrementVisitor;
			accept(decrementvisitor);
		}
	}
};
#endif