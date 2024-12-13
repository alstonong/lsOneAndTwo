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
	string name, vorname, telefonnummer, addresse, motorcycle;
	int geburtsjahr;
	bool fuhrerscheina;

public:
	Customer();
	Customer(string n, string v, string t, string a, string m, int g, bool f);
	static Customer createCustomer();
	string getname() const, getvorname() const, gettelefonnummer() const, getaddresse() const, getmotorcycle() const;
	int getgeburtsjahr() const;
	bool getfuhrerscheina() const;
	void setmotorcycle(string m);
	friend istream& operator>>(istream& is, Customer& c);
	friend ostream& operator<<(ostream& os, const Customer& c);
	friend bool operator<(const Customer& cone, const Customer& ctwo);
};

class Motorcycle
{
private:
	string name;
	bool rented;

public:
	Motorcycle();
	Motorcycle(string n);
	static Motorcycle createMotorcycle();
	string getname() const;
	bool getrented() const;
	void rentm(), returnm();
	friend istream& operator>>(istream& is, Motorcycle& m);
	friend ostream& operator<<(ostream& os, const Motorcycle& m);
	friend bool operator<(const Motorcycle& mone, const Motorcycle& mtwo);
};

Customer::Customer() : name(""), vorname(""), telefonnummer(""), addresse(""), motorcycle("none"), geburtsjahr(0), fuhrerscheina(false) {}

Customer::Customer(string n, string v, string t, string a, string m, int g, bool f) : name(n), vorname(v), telefonnummer(t), addresse(a), motorcycle(m), geburtsjahr(g), fuhrerscheina(f) {}

Customer Customer::createCustomer()
{
	string n, v, t, a, m;
	int g;
	bool f;
	do
	{
		cout << "Customer surname: ";
		cin >> n;
		cin.ignore(10000, '\n');
		if (n.empty())
		{
			cout << "Still need a surname..." << endl;
		}
		else
		{
			break;
		}
	} 
	while (true);

	do
	{
		cout << "Customer first name: ";
		cin >> v;
		cin.ignore(10000, '\n');
		if (v.empty())
		{
			cout << "First name is a compulsory field..." << endl;
		}
		else
		{
			break;
		}
	} 
	while (true);

	do
	{
		cout << "Customer telephone number: ";
		getline(cin, t);
		if (t.empty())
		{
			cout << "Need a number to contact you..." << endl;
		}
		else
		{
			break;
		}
	} 
	while (true);
		
	do
	{
		cout << "Customer address: ";
		getline(cin, a);
		if (a.empty())
		{
			cout << "I won't go to your house. Promise..." << endl;
		}
		else
		{
			break;
		}
	} 
	while (true);

	do
	{
		cout << "Customer year of birth: ";
		cin >> g;
		if (cin.good())
		{
			break;
		}
		else
		{
			cout << "Still need the year of birth..." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
	} 
	while (true);

	char userchar;
	do
	{
		cout << "Customer motorcycle license (class A) possession: " << endl;
		cout << "y/Y for yes; n/N for no: ";
		cin >> userchar;
		cin.ignore(100, '\n');
		if (userchar == 'Y' || userchar == 'y')
		{
			f = true;
			break;
		}
		else if (userchar == 'N' || userchar == 'n')
		{
			f = false;
			break;
		}
		else
		{
			cout << "Surely it's not hard to enter a letter..." << endl;
		}
	} 
	while (true);
	
	m = "none";

	cout << endl;

	return Customer(n, v, t, a, m, g, f);
}

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

string Customer::getmotorcycle() const
{
	return motorcycle;
}

int Customer::getgeburtsjahr() const
{
	return geburtsjahr;
}

bool Customer::getfuhrerscheina() const
{
	return fuhrerscheina;
}

void Customer::setmotorcycle(string m)
{
	motorcycle = m;
}

istream& operator>>(istream& is, Customer& c)
{
	getline(is, c.name);
	getline(is, c.vorname);
	getline(is, c.telefonnummer);
	getline(is, c.addresse);
	getline(is, c.motorcycle);
	is >> c.geburtsjahr;
	is.ignore();
	string f;
	getline(is, f);
	if (f == "1")
	{
		c.fuhrerscheina = true;
	}
	else 
	{
		c.fuhrerscheina = false;
	}
	return is;
}

ostream& operator<<(ostream& os, const Customer& c)
{
	os << c.name << '\n'
		<< c.vorname << '\n'
		<< c.telefonnummer << '\n'
		<< c.addresse << '\n'
		<< c.motorcycle << '\n'
		<< c.geburtsjahr << '\n'
		<< c.fuhrerscheina << '\n';
	return os;
}

bool operator<(const Customer& cone, const Customer& ctwo)
{
	return cone.name < ctwo.name;
}

Motorcycle::Motorcycle() : name(""), rented(false) {}

Motorcycle::Motorcycle(string n) : name(n), rented(false) {}

Motorcycle Motorcycle::createMotorcycle()
{
	string n;
	cout << "Motorcycle name: ";
	getline(cin, n);
	return Motorcycle(n);
}

string Motorcycle::getname() const
{
	return name;
}

bool Motorcycle::getrented() const
{
	return rented;
}

void Motorcycle::rentm()
{
	rented = true;
}

void Motorcycle::returnm()
{
	rented = false;
}

istream& operator>>(istream& is, Motorcycle& m)
{
	getline(is, m.name);
	string r;
	getline(is, r);
	if (r == "1")
	{
		m.rented = true;
	}
	else 
	{
		m.rented = false;
	}
	return is;
}

ostream& operator<<(ostream& os, const Motorcycle& m)
{
	os << m.name << '\n' << m.rented << '\n';
	return os;
}

bool operator<(const Motorcycle& mone, const Motorcycle& mtwo)
{
	return mone.name < mtwo.name;
}

list<Customer> customerlist;
list<Motorcycle> motorcyclelist;
void addcustomer();
void rentmotorcycle();
void displayallcustomer();
void displaycustomerrentstatus();
void addmotorcycle();
void displayallmotorcycle();
int searchcustomer();

int main()
{
	cout << "=============================================" << endl;
	cout << "| Welcome to Motorcycle Management database |" << endl;
	cout << "=============================================" << endl << endl << endl;

	ifstream checkfile("reservierungen.txt", ios::in);
	ifstream inputfile;
	Customer inputcustomer;
	Motorcycle inputmotorcycle;

	if (!checkfile.is_open())
	{
		ofstream newfile("reservierungen.txt", ios::out);
		newfile << "*" << endl;
		inputmotorcycle = Motorcycle("Suzuki GSX-8S");
		newfile << inputmotorcycle;
		inputmotorcycle = Motorcycle("Honda TransAlp");
		newfile << inputmotorcycle;
		inputmotorcycle = Motorcycle("BMW F 650 GS");
		newfile << inputmotorcycle;
		inputmotorcycle = Motorcycle("Ducati Streetfighter V4");
		newfile << inputmotorcycle;
		newfile << "*" << endl;
	}

	inputfile.open("reservierungen.txt", ios::in);

	while (true)
	{
		if (inputfile.peek() == '*')
		{
			string discard;
			getline(inputfile, discard);
			break;
		}

		inputfile >> inputcustomer;
		customerlist.push_back(inputcustomer);
	}

	while(true)
	{
		if (inputfile.peek() == '*')
		{
			string discard;
			getline(inputfile, discard);
			break;
		}

		inputfile >> inputmotorcycle;
		motorcyclelist.push_back(inputmotorcycle);
	}

	inputfile.close();

	bool z = true;
	do 
	{
		int useroption;
		cout << "==== Management options ====" << endl;
		cout << "(0) -- End database. All data will be saved in \"reservierung.txt\"." << endl;
		cout << "------- Customers -------" << endl;
		cout << "(1) -- Manage existing customer" << endl;
		cout << "(2) -- Add a customer" << endl;
		cout << "(3) -- Add a motorcycle reservation" << endl;
		cout << "(4) -- Display all customer data" << endl;
		cout << "(5) -- Delete existing customer" << endl;
		cout << "------- Motorcycles -------" << endl;
		cout << "(6) Add new motorcycle" << endl;
		cout << "(7) Display all motorcycle status" << endl;
		cout << "(8) Delete existing motorcycle" << endl;
		cout << "Option: ";
		cin >> useroption;
		cin.ignore();
		cout << endl;

		if (cin.good())	
		{
			switch (useroption)
			{
				case 0:
				{
					z = false;
					break;
				}
				case 2:
				{
					addcustomer();
					break;
				}
				case 3:
				{
					rentmotorcycle();
					break;
				}
				case 4: 
				{
					displayallcustomer();
					break;
				}
				case 6:
				{
					addmotorcycle();
					break;
				}
				case 7:
				{
					displayallmotorcycle();
					break;
				}
				default: 
				{
					cout << "Invalid option." << endl << endl;
					break;
				}
			}
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Only integer inputs are accepted..." << endl << endl;
		}
	}
	while (z);

	ofstream outputfile("reservierungen.txt", ios::out | ios::trunc);
	for (const Customer& customer : customerlist)
	{
		outputfile << customer;
	}

	outputfile << "*" << endl;

	for (const Motorcycle& motorcycle : motorcyclelist)
	{
		outputfile << motorcycle;
	}

	outputfile << "*" << endl;

	outputfile.close();

	cout << "Grab a coffee...program terminated..." << endl << endl;

	return 0;
}

void addcustomer()
{
	Customer c = Customer::createCustomer();
	customerlist.push_back(c);
	cout << "New customer added..." << endl << endl;
}

void rentmotorcycle()
{
	Customer* c = nullptr;
	Motorcycle* m = nullptr;
	displaycustomerrentstatus();
	int icustomer;
	int imotorcycle;
	cout << "Enter -1 to add a customer...\n";
	cout << "Customer number: ";
	cin >> icustomer;
	icustomer--;
	cout << "\n";

	do
	{	
		if (icustomer > -1 && icustomer <= customerlist.size())
		{
			auto cstep = customerlist.begin();
			advance(cstep, icustomer);
			c = &(*cstep);
			break;
		}
		else if (icustomer == -1)
		{
			cout << "Adding new customer..." << endl;
			cin.ignore(10000, '\n');
			addcustomer();
			c = &customerlist.back();
			break;
		}
		else
		{
			cout << "Unknown error...\n\n";
			cin.clear();
			cin.ignore(10000, '\n');
			return;
		}
	} 
	while (true);

	if (!c->getfuhrerscheina())
	{
		cout << c->getname() << ", " << c->getvorname() << " does not possess a motorcycle license (class A)." << endl << endl; 
		return;
	}

	if (c->getmotorcycle() != "none")
	{
		cout << c->getname() << ", " << c->getvorname() << " is already renting a motorcycle." << endl << endl;
		return;
	}

	do
	{
		do
		{
			displayallmotorcycle();
			cout << "Motorcycle option[input choice number] OR 0 to cancel reservation: ";
			cin >> imotorcycle;

			if (imotorcycle == -1)
			{
				cout << "Reservation cancelled." << endl;
				return;
			}
			else if (imotorcycle > -1 && imotorcycle <= motorcyclelist.size())
			{
				break;
			}
			else
			{
				cout << "-_- Enter only a number in the list...";
			}
		}
		while (true);
		
		imotorcycle--;
		auto mstep = motorcyclelist.begin();
		advance(mstep, imotorcycle);
		m = &(*mstep);

		if (!m->getrented())
		{
			cout << "Motorcycle rented..." << endl;
			break;
		}

		cout << "Motorcycle is not available for rent..." << endl;
	}
	while (true);

	c->setmotorcycle(m->getname());
	m->rentm();
}

void displayallcustomer()
{
	customerlist.sort();
	int count = 1;
	for (const Customer& customer : customerlist)
	{
		cout << "(" << count << ")" << endl;
		cout << "Surname: " << customer.getname() << endl;
		cout << "First name: " << customer.getvorname() << endl;
		cout << "Telephone numebr: " << customer.gettelefonnummer() << endl;
		cout << "Address: " << customer.getaddresse() << endl;
		cout << "Current motorcycle rented: " << customer.getmotorcycle() << endl;
		cout << "Year of birth: " << customer.getgeburtsjahr() << endl;
		if (customer.getfuhrerscheina())
		{
			cout << "Motorcycle license (class A) possession: Yes" << endl;
		}
		else
		{
			cout << "Motorcycle license (class A) possession: No" << endl;
		}
		cout << endl;
		count++;
	}
	cout << endl;
}

void displaycustomerrentstatus()
{
	customerlist.sort();
	int count = 1;
	for (const Customer& customer : customerlist)
	{
		cout << "(" << count << ") " << customer.getname() << ", " << customer.getvorname() << " || "
		<< "Current motorcycle rented: " << customer.getmotorcycle() << " || ";
		if (customer.getfuhrerscheina())
		{
			cout << "Motorcycle license (class A) possession: Yes" << endl;
		}
		else
		{
			cout << "Motorcycle license (class A) possession: No" << endl;
		}
		count++;
	}
	cout << endl;
}

void addmotorcycle()
{
	Motorcycle m = Motorcycle::createMotorcycle();
	motorcyclelist.push_back(m);
	cout << "New motorcycle added..." << endl << endl;	
}

void displayallmotorcycle()
{
	motorcyclelist.sort();
	int count = 1;
	for (const Motorcycle& motorcycle : motorcyclelist)
	{
		cout << "(" << count << ") ";
		if (motorcycle.getrented())
		{
			cout << motorcycle.getname() << " || Status: Unavailable";
		}
		else
		{
			cout << motorcycle.getname() << " || Status: Available";
		}
		cout << endl;
		count ++;
	}
	cout << endl;
}

/*
void searchcustomer()
{
	string s, f;
	cout << "Search by surname[case sensitive]: ";
	cin >> s;
	cout << "And first name[case sensitive]: ";
	cin >> f;
	cout << endl;

	int index = 0;
	for (const Customer& customer : customerlist)
	{
		if (s == customer.getname() && f == customer.getvorname())
		{

		}
		index++;
	}
}
*/