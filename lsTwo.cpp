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
		if (n.empty())
		{
			cout << "Still need a surname..." << endl;
		}
		else
		{
			break;
		}
	} while (true);

	do
	{
		cout << "Customer first name: ";
		cin >> v;
		if (n.empty())
		{
			cout << "First name is a compulsory field..." << endl;
		}
		else
		{
			break;
		}
	} while (true);

	do
	{
		cout << "Customer telephone number: ";
		cin >> t;
		if (n.empty())
		{
			cout << "Need a number to contact you..." << endl;
		}
		else
		{
			break;
		}
	} while (true);
		
	do
	{
		cout << "Customer address: ";
		cin >> a;
		if (n.empty())
		{
			cout << "I won't go to your house. Promise..." << endl;
		}
		else
		{
			break;
		}
	} while (true);

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
		}
	} while (true);

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
	} while (true);
	
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
	os << c.name << endl << c.vorname << endl << c.telefonnummer << endl 
		<< c.addresse << endl << c.motorcycle << endl << c.geburtsjahr << endl << c.fuhrerscheina << endl;
	return os;
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
	os << m.name << endl << m.rented << endl;
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
void addmotorcycle();
void displayallmotorcycle();
int searchcustomer();

int main()
{
	cout << "=============================================" << endl;
	cout << "| Welcome to Motorcycle Management database |" << endl;
	cout << "=============================================" << endl << endl << endl;

	ifstream inputfile("reservierungen.txt", ios::in);
	Customer inputcustomer;
	Motorcycle inputmotorcycle;
	string inputline;
	while (getline(inputfile, inputline))
	{
		if (inputline == "*")
		{
			break;
		}
		else
		{
			inputfile.putback('\n');
			inputfile.seekg(-inputline.length(), ios::cur);
			inputfile >> inputcustomer;
			customerlist.push_back(inputcustomer);
		}
	}

	while (getline(inputfile, inputline)) 
	{
		if (inputline == "")
		{
			break;
		}
		else
		{
			inputfile.putback('\n');
			cout << "1";
			inputfile.seekg(-inputline.length(), ios::cur);
			cout << "2";
			inputfile >> inputmotorcycle;
			cout << "3";
			motorcyclelist.push_back(inputmotorcycle);
			cout << "4";
		}
	}

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
	Customer c;
	Motorcycle m;
	int icustomer = searchcustomer();
	int imotorcycle;

	do
	{	
		if (icustomer > -1 && icustomer <= customerlist.size())
		{
			auto cstep = customerlist.begin();
			advance(cstep, icustomer);
			c = *cstep;
			break;
		}
		else if (icustomer == -1)
		{
			cout << "This customer does not exist." << endl;
			addcustomer();
			c = customerlist.back();
			break;
		}
		else
		{
			cout << "Unknown error...";
			return;
		}
	} while (true);

	if (!c.getfuhrerscheina())
	{
		cout << c.getname() << ", " << c.getvorname() << " does not possess a motorcycle license (class A)." << endl << endl; 
		return;
	}

	if (c.getmotorcycle() != "")
	{
		cout << c.getname() << ", " << c.getvorname() << " is already renting a motorcycle." << endl << endl;
		return;
	}

	do
	{
		do
		{
			displayallmotorcycle();
			cout << "Motorcycle option[input choice number] OR 0 to cancel reservation: ";
			cin >> imotorcycle;

			if (imotorcycle == 0)
			{
				return;
			}
			else if (imotorcycle > 0 && imotorcycle <= motorcyclelist.size())
			{
				break;
			}
			else
			{
				cout << "-_- Enter only a number in the list...";
			}
		}
		while (true);
		
		auto mstep = motorcyclelist.begin();
		advance(mstep, imotorcycle - 1);
		m = *mstep;

		if (!m.getrented())
		{
			break;
		}
	}
	while (true);

	c.setmotorcycle(m.getname());
	m.rentm();
}

void displayallcustomer()
{
	int count = 1;
	for (const Customer& customer : customerlist)
	{
		cout << "(" << count << ")" << endl;
		cout << "Surname: " << customer.getname() << endl;
		cout << "First name: " << customer.getvorname() << endl;
		cout << "Telephone numebr: " << customer.gettelefonnummer() << endl;
		cout << "Address: " << customer.getaddresse() << endl;
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
	}
	cout << endl;
}

int searchcustomer()
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
			return index;
		}
		index++;
	}

	return -1;
}