#include <iostream>
#include <list>
#include <fstream>
#include <cstdlib>
using namespace std;

//code written in Linux
//code in Linux geschrieben
//github.com/alstonong/lsOneAndTwo to view all commits
//credits: 
//youtube.com/watch?v=lmcK9_0l73Y&ab_channel=MikeShah [serialize and deserialize]
//stackoverflow.com/questions/22269435/how-to-iterate-through-a-list-of-objects-in-c [iterate over list]

class Customer
{
private: 
	string name, vorname, telefonnummer, addresse;
	int geburtsjahr;
	bool fuhrerscheina;

public:
	Customer();
	Customer(string n, string v, string t, string a, int g, bool f);
	string getname() const, getvorname() const, gettelefonnummer() const, getaddresse() const;
	int getgeburtsjahr() const;
	bool getfuhrerscheina() const;
	friend istream& operator>>(istream& is, Customer& c);
	friend ostream& operator<<(ostream& os, const Customer& c);
};

class Motorcycle
{
private:
	string name;
	bool rented;

public:
	Motorcycle(string n);
	void rentm();
};

Customer::Customer() : name(""), vorname(""), telefonnummer(""), geburtsjahr(0), addresse(), fuhrerscheina(false) {}

Customer::Customer(string n, string v, string t, string a, int g, bool f) : name(n), vorname(v), telefonnummer(t), addresse(a), geburtsjahr(g), fuhrerscheina(f) {}

string Customer::getname() const 
{
	return name;
}

string Customer::getvorname() const
{
	return vorname;
}

string Customer::gettelefonnummer() const
{
	return telefonnummer;
}

string Customer::getaddresse() const
{
	return addresse;
}

int Customer::getgeburtsjahr() const
{
	return geburtsjahr;
}

bool Customer::getfuhrerscheina() const
{
	return getfuhrerscheina;
}

istream& operator>>(istream& is, Customer& c)
{
	getline(is, c.name);
	getline(is, c.vorname);
	getline(is, c.telefonnummer);
	is >> c.addresse;
	is >> c.geburtsjahr;
	is >> c.fuhrerscheina;
	return is;
}

ostream& operator<<(ostream& os, const Customer& c)
{
	os << c.name << endl << c.vorname << endl << c.telefonnummer << endl 
		<< c.addresse << endl << c.geburtsjahr << endl << c.fuhrerscheina << endl;
	return os;
}

Motorcycle::Motorcycle(string n) : name(n), rented(false) {}

void Motorcycle::rentm()
{
	rented = true;
}

list<Customer> customerlist;
list<Motorcycle> motorcyclelist;
void addreservation();

int main()
{
	cout << "=============================================" << endl;
	cout << "| Welcome to Motorcycle Management database |" << endl;
	cout << "=============================================" << endl << endl << endl;

	bool z = true;
	do 
	{
		int useroption;
		cout << "==== Management options ====" << endl;
		cout << "(0) -- End database. All data will be saved in \"reservierung.txt\".";
		cout << "------- Customers -------" << endl;
		cout << "(1) -- Manage existing customer" << endl;
		cout << "(2) -- Add a motorcycle reservation" << endl;
		cout << "(3) -- Display all customer data" << endl;
		cout << "(4) -- Delete existing customer" << endl;
		cout << "------- Motorcycles -------" << endl;
		cout << "(1) Add new motorcycle" << endl;
		cout << "(2) Display all motorcycle status" << endl;
		cout << "(3) Delete existing motorcycle" << endl;
		cout << "Option: " << endl;
		cin >> useroption;

		switch (useroption)
		{
			case 0:
			{
				z = false;
				break;
			}
			default: 
			{
				cout << "Invalid option." << endl << endl;
			}
		}
	}
	while (z);

	ofstream reservefile("reservierungen.txt");
	for (const Customer& customer : customerlist)
	{
		reservefile << customer;
	}

	reservefile.close();

	cout << "Grab a coffee...program terminated..." << endl << endl;

	return 0;
}

void addreservation()
{

	customerlist.push_back();
}