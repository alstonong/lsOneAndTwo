#include <iostream>
#include <list>
#include <fstream>
#include <cstdlib>
using namespace std;

//code written in Linux
//code in Linux geschrieben
//github.com/alstonong/lsOneAndTwo to view all commits

//credits: 
//https://www.youtube.com/watch?v=lmcK9_0l73Y&ab_channel=MikeShah [serialize and deserialize]
//https://stackoverflow.com/questions/22269435/how-to-iterate-through-a-list-of-objects-in-c [iterate over list]

//in case some of my code is flagged on stackoverflow, this is my post: https://stackoverflow.com/questions/79276706/ifstream-creating-an-extra-element-at-the-beginning-of-a-list

//Customer class
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
	//Getters
	string getname() const, getvorname() const, gettelefonnummer() const, getaddresse() const, getmotorcycle() const;
	int getgeburtsjahr() const;
	bool getfuhrerscheina() const;
	//Setters
	void setmotorcycle(string m), settelefonnummer(), setaddresse(), setgeburtsjahr(), setfuhrerscheina();
	//Customer <<, >> and < operator overload
	friend istream& operator>>(istream& is, Customer& c);
	friend ostream& operator<<(ostream& os, const Customer& c);
	friend bool operator<(const Customer& cone, const Customer& ctwo);
};

//Motorcycle class
class Motorcycle
{
private:
	string name;
	bool rented;

public:
	Motorcycle();
	Motorcycle(string n);
	static Motorcycle createMotorcycle();
	//Motorcycle getters
	string getname() const;
	bool getrented() const;	
	//Function to change rented status
	void rentm(), returnm();
	//Motorcycle <<, >> and < operator overload
	friend istream& operator>>(istream& is, Motorcycle& m);
	friend ostream& operator<<(ostream& os, const Motorcycle& m);
	friend bool operator<(const Motorcycle& mone, const Motorcycle& mtwo);
};

//All member functions defined below
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
		
	string st, nu, po, ci;
	cout << "Customer address...\n";
	do
	{
		cout << "Street: ";
		getline(cin, st);
		if (st.empty())
		{
			cout << "Missing street. I won't go to your house. Promise..." << endl;
		}
		else
		{
			break;
		}
	} 
	while (true);

	do
	{
		cout << "Number: ";
		getline(cin, nu);
		if (nu.empty())
		{
			cout << "Missing number. I won't go to your house. Promise..." << endl;
		}
		else
		{
			break;
		}
	}
	while (true);

	do
	{
		cout << "Postal code: ";
		getline(cin, po);
		if (po.empty())
		{
			cout << "Missing postal code. I won't go to your house. Promise..." << endl;
		}
		else
		{
			break;
		}
	} while (true);
	
	do
	{
		cout << "City: ";
		getline(cin, ci);
		if (ci.empty())
		{
			cout << "Missing city. I won't go to your house. Promise..." << endl;
		}
		else
		{
			break;
		}
	} while (true);

	a = st + " " + nu + " " + po + " " + ci;

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
		}
	}
	while (true);

	char userchar;
	do
	{
		cout << "Customer motorcycle license (class A) possession: " << endl;
		cout << "y/Y for yes; n/N for no: ";
		cin >> userchar;
		cin.ignore(10000, '\n');
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
			cin.clear();
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

void Customer::settelefonnummer()
{
	string t;
	do
	{
		cin.ignore(10000, '\n');
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
	telefonnummer = t;
	cout << endl;
	cout << "Telephone number saved." << endl << endl;
}

void Customer::setaddresse()
{
	string a;
	cin.ignore(10000, '\n');
	string st, nu, po, ci;
	cout << "Customer address...\n";
	do
	{
		cout << "Street: ";
		getline(cin, st);
		if (st.empty())
		{
			cout << "Missing street. I won't go to your house. Promise..." << endl;
		}
		else
		{
			break;
		}
	} 
	while (true);

	do
	{
		cout << "Number: ";
		getline(cin, nu);
		if (nu.empty())
		{
			cout << "Missing number. I won't go to your house. Promise..." << endl;
		}
		else
		{
			break;
		}
	}
	while (true);

	do
	{
		cout << "Postal code: ";
		getline(cin, po);
		if (po.empty())
		{
			cout << "Missing postal code. I won't go to your house. Promise..." << endl;
		}
		else
		{
			break;
		}
	} while (true);
	
	do
	{
		cout << "City: ";
		getline(cin, ci);
		if (ci.empty())
		{
			cout << "Missing city. I won't go to your house. Promise..." << endl;
		}
		else
		{
			break;
		}
	} while (true);

	a = st + " " + nu + " " + po + " " + ci;
	addresse = a;
	cout << endl;
	cout << "Address saved." << endl << endl;
}

void Customer::setgeburtsjahr()
{
	int g;
	do
	{
		cin.ignore(10000, '\n');
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
		}
	} 
	while (true);
	geburtsjahr = g;
	cout << endl;
	cout << "Year of birth saved." << endl << endl;
}

void Customer::setfuhrerscheina()
{
	bool f;
	char userchar;
	do
	{
		cin.ignore(10000, '\n');
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
			cin.clear();
		}
	} 
	while (true);	
	fuhrerscheina = f;
	cout << endl;
	cout << "Motorcycle license (class A) possession saved." << endl << endl;
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

//Double linked lists for customers and motorcycles
list<Customer> customerlist;
list<Motorcycle> motorcyclelist;
//All functions defined under int main()
void editexistingcustomer();
void addcustomer();
void rentmotorcycle();
void returnmotorcycle();
void displayallcustomer();
void displaycustomerrentstatus();
void deletecustomer();
void addmotorcycle();
void displayallmotorcycle();
void deletemotorcycle();
//Fucntion to save into txt file
void savefile();

int main()
{
	cout << "=============================================" << endl;
	cout << "| Welcome to Motorcycle Management database |" << endl;
	cout << "=============================================" << endl << endl << endl;

	ifstream checkfile("reservierungen.txt", ios::in);
	ifstream inputfile;
	Customer inputcustomer;
	Motorcycle inputmotorcycle;

	//Check to see if reservierungen.txt exists
	//If no, one is created and 4 motorcycles are added initially
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

	checkfile.close();
	inputfile.open("reservierungen.txt", ios::in);

	//Reads the reservierungen.txt file into the customer list
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

	//Reads the reservierungen.txt file into the motorcycle list
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
		//Management user menu (features)
		int useroption;
		cout << "==== Management options ====" << endl;
		cout << "(0) -- End database. All data will be saved in \"reservierung.txt\"." << endl;
		cout << "------- Customers -------" << endl;
		cout << "(1) -- Manage existing customer" << endl;
		cout << "(2) -- Add a customer" << endl;
		cout << "(3) -- Add a motorcycle reservation" << endl;
		cout << "(4) -- Return a motorcycle" << endl;
		cout << "(5) -- Display all customer data" << endl;
		cout << "(6) -- Delete existing customer" << endl;
		cout << "------- Motorcycles -------" << endl;
		cout << "(7) -- Add new motorcycle" << endl;
		cout << "(8) -- Display all motorcycle status" << endl;
		cout << "(9) -- Delete existing motorcycle" << endl;
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
				case 1:
				{
					editexistingcustomer();
					savefile();
					break;
				}
				case 2:
				{
					addcustomer();
					savefile();
					break;
				}
				case 3:
				{
					rentmotorcycle();
					savefile();
					break;
				}
				case 4: 
				{
					returnmotorcycle();
					savefile();
					break;
				}
				case 5: 
				{
					displayallcustomer();
					savefile();
					break;
				}
				case 6: 
				{
					deletecustomer();
					savefile();
					break;
				}
				case 7:
				{
					addmotorcycle();
					savefile();
					break;
				}
				case 8:
				{
					displayallmotorcycle();
					savefile();
					break;
				}
				case 9:
				{
					deletemotorcycle();
					savefile();
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

	//Function called to save everything at program termination
	savefile();

	cout << "Grab a coffee...program terminated..." << endl << endl;

	return 0;
}

void savefile()
{
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
}

//Function calls another user menu to change a customer's information
void editexistingcustomer()
{
	do
	{
		int useroptiontwo;
		cout << "==== Customer options ====" << endl;
		cout << "(0) -- End customer edits" << endl;
		cout << "------- Customers -------" << endl;
		cout << "(1) -- Change telephone number" << endl;
		cout << "(2) -- Change address" << endl;
		cout << "(3) -- Change year of birth" << endl;
		cout << "(4) -- Change possession of motorcycle license (class A)" << endl;
		cout << "Option: ";
		cin >> useroptiontwo;
		cin.ignore();
		cout << endl;

		Customer* c = nullptr;
		int icustomer;

		if (useroptiontwo != 0)
		{
			displaycustomerrentstatus();
			cout << "Customer option: ";
			cin >> icustomer;
			icustomer--;
			cout << "\n";

			auto cstep = customerlist.begin();
			advance(cstep, icustomer);
			c = &(*cstep);
		}

		if (icustomer > -1 && icustomer <= customerlist.size())
		{
			//switch case calls setters respectively
			switch (useroptiontwo)
			{
				case 0: 
				{
					cout << "Back to management options..." << endl << endl;
					return;
				}
				case 1:
				{
					c->settelefonnummer();
					break;
				}
				case 2:
				{
					c->setaddresse();
					break;
				}
				case 3:
				{
					c->setgeburtsjahr();
					break;
				}
				case 4:
				{
					c->setfuhrerscheina();
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
			cout << "Please input the right customer number." << endl << endl;
		}
	}
	while (true);
}

//Function that just creates a new customer object and adds it to the customer list
void addcustomer()
{
	Customer c = Customer::createCustomer();
	customerlist.push_back(c);
	cout << "New customer added..." << endl << endl;
}

//Function to rent motorcyle
void rentmotorcycle()
{
	Customer* c = nullptr;
	Motorcycle* m = nullptr;
	displaycustomerrentstatus();
	int icustomer;
	int imotorcycle;
	cout << "Customer option OR 0 to add customer: ";
	cin >> icustomer;
	icustomer--;
	cout << "\n";

	//Checks which customer intends to rent a motorcycle
	do
	{
		//Assigns the customer to c for editing when found	
		if (icustomer > -1 && icustomer <= customerlist.size())
		{
			auto cstep = customerlist.begin();
			advance(cstep, icustomer);
			c = &(*cstep);
			break;
		}
		//If the customer does not exist, he/she can be added
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

	//Checks if customer possesses a class A license
	if (!c->getfuhrerscheina())
	{
		cout << c->getname() << ", " << c->getvorname() << " does not possess a motorcycle license (class A)." << endl << endl; 
		return;
	}

	//Checks if customer is currently renting a motorcycle
	if (c->getmotorcycle() != "none")
	{
		cout << c->getname() << ", " << c->getvorname() << " is already renting a motorcycle." << endl << endl;
		return;
	}

	do
	{
		//Shows the available motorcycles to rent
		do
		{
			displayallmotorcycle();
			cout << "Motorcycle option OR 0 to cancel reservation: ";
			cin >> imotorcycle;
			imotorcycle--;
			cout << "\n";

			//Allows user to cancel reservation if a desired motorcycle is not found
			if (imotorcycle == -1)
			{
				cout << "Motorcycle reservation cancelled." << endl << endl;
				return;
			}
			//If a desired motorcycle is found, the loop is broken
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

		//Assigns the desired motorcycle to variable m
		auto mstep = motorcyclelist.begin();
		advance(mstep, imotorcycle);
		m = &(*mstep);

		//If the desired motorcycle is not currently being rented, the loop breaks
		if (!m->getrented())
		{
			cout << "Motorcycle rented..." << endl << endl;
			break;
		}

		cout << "Motorcycle is not available for rent..." << endl << endl;
	}
	while (true);

	//Sets the customer's motorcycle motorcycle variable and marks the desired motorcycle as rented 
	c->setmotorcycle(m->getname());
	m->rentm();
}

//Function to return a motorcycle
void returnmotorcycle()
{	
	Customer* c = nullptr;
	Motorcycle* m = nullptr;
	//Displays all customer's rental status
	displaycustomerrentstatus();
	int icustomer;
	int imotorcycle;
	cout << "Customer option OR 0 to cancel return: ";
	cin >> icustomer;
	icustomer--;
	cout << "\n";

	//Assigns the chosen customer to c
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
			cout << "Motorcycle return cancelled." << endl << endl;
			return;
		}
		else
		{
			cout << "Unknown error1...\n\n";
			cin.clear();
			cin.ignore(10000, '\n');
			return;
		}
	} 
	while (true);

	//Checks if the customer chosen is currently renting a motorcycle
	if (c->getmotorcycle() == "none")
	{
		cout << c->getname() << ", " << c->getvorname() << " is not currently renting a motorcycle." << endl << endl;
		return;
	}

	//For loop to find the motorcycle that the chosen customer is renting and then deletes the customer
	for (int i = 0; i <= motorcyclelist.size(); i++)
	{
		auto mstep = motorcyclelist.begin();
		advance(mstep, i);
		m = &(*mstep);
		if (c->getmotorcycle() == m->getname())
		{
			c->setmotorcycle("none");
			//The code in the block can be commented out should the user not want to delete the customer upon return of motorcycle.
			{
				auto cstep = customerlist.begin();
				advance(cstep, icustomer);
				customerlist.erase(cstep);
				cout << "Customer deleted." << endl << endl;
			}
			m->returnm();
			return;
		}
	}

	cout << "Unknown error2...\n\n";
}

//Displays all customers in the database
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

//Removes a customer from the customer list
void deletecustomer()
{
	Customer* c = nullptr;
	displaycustomerrentstatus();
	int icustomer;
	cout << "Customer option OR 0 to cancel deletion: ";
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
			cout << "Customer deletion cancelled." << endl << endl;
			return;
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

	//Customer can only be deleted if they're not currently renting a motorcycle
	if (c->getmotorcycle() == "none")
	{
		auto cstep = customerlist.begin();
		advance(cstep, icustomer);
		customerlist.erase(cstep);
		cout << "Customer deleted." << endl << endl;
	}
	else
	{
		cout << c->getname() << ", " << c->getvorname() << " cannot be deleted when renting a motocycle." << endl << endl;
	}
}

//Displays all customer's rental status
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

//Function to add a new Motorcycle object
void addmotorcycle()
{
	Motorcycle m = Motorcycle::createMotorcycle();
	motorcyclelist.push_back(m);
	cout << "New motorcycle added..." << endl << endl;	
}

//Displays all motorcycles and their status
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

//Deletes a motorcycle object from the motorcycle list
void deletemotorcycle()
{
	Motorcycle* m = nullptr;
	displayallmotorcycle();
	int imotorcycle;
	cout << "Motorcycle option OR 0 to cancel deletion: ";
	cin >> imotorcycle;
	imotorcycle--;
	cout << endl;

	do
	{	
		if (imotorcycle > -1 && imotorcycle <= customerlist.size())
		{
			auto mstep = motorcyclelist.begin();
			advance(mstep, imotorcycle);
			m = &(*mstep);
			break;
		}
		else if (imotorcycle == -1)
		{
			cout << "Motorcycle deletion cancelled." << endl << endl;
			return;
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

	//Only allows deletion if they're not currently being rented
	if (m->getrented() == false)
	{
		auto mstep = motorcyclelist.begin();
		advance(mstep, imotorcycle);
		motorcyclelist.erase(mstep);
		cout << "Motorcycle deleted." << endl << endl;
	}
	else
	{
		cout << m->getname() << " cannot be deleted when being rented." << endl << endl;
	}	
}