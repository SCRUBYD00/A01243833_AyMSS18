#include <iostream>
#include <list>
#include <string>

using namespace std;

class DocPart 
{
public:
	string text;

	virtual string toLatex() = 0;
	virtual string toHTML() = 0;
	virtual string toText() = 0;
};

class Text : public DocPart 
{
public:
	string toHTML() 
	{
		return text;
	}

	string toLatex() 
	{
		return text;
	}
	
	string toText() 
	{
		return text;
	}
};

class Bold : public DocPart 
{
	string toHTML() 
	{
		return "<b>" + text + "</b>";
	}

	string toLatex() 
	{
		return "\\textbf {" + text + "}";
	}

	string toText() 
	{
		return text;
	}
};

class HyperLink : public DocPart 
{
public:
	string URL;

	string toHTML() 
	{
		return "<a href='" + URL + "'>" + text + "</a>";
	}

	string toLatex() 
	{
		return "\\href {" + URL + "}{" + text + "}";
	}

	string toText() 
	{
		return text + URL;
	}
};

class Document 
{
public:
	list<DocPart*> docpart;
	string toHtml() 
	{
		string out = "";
		for (DocPart* d : docpart) 
		{
			out += d->toHTML();
		}
		return out;

	}

	string toLatex() 
	{
		string out = "";
		for (DocPart* d : docpart) 
		{
			out += d->toLatex();
		}
		return out;
	}

	string toText() 
	{
		string out = "";
		for (DocPart* d : docpart) 
		{
			out += d->toText();
		}
		return out;
	}
};



/*int main() 
{
	Document d;
	Text t;
	t.text = "Hola, visita ";
	Bold t2;
	t2.text = "my ";
	HyperLink t3;
	t3.text = "page ";
	t3.URL = "www.mypage.com";

	d.docpart.push_back(&t);
	d.docpart.push_back(&t2);
	d.docpart.push_back(&t3);

	cout << d.toLatex();

	int x;
	cin >> x;

	return 1;
}*/