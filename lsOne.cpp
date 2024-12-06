#include <iostream>
using namespace std;

//code written in Linux
//code in Linux geschrieben
//github.com/alstonong/lsOneAndTwo to view all commits

//class for creating and saving dates
class Date
{
private: 
	int day, month, year;

public: 
	Date();
	Date(int d, int m, int y); 
	~Date();
	static Date createDate();
	int getday(), getmonth(), getyear();
	void setday(int d), setmonth(int m), setyear(int y);
};

//class for creating and saving Mitarbeiters
class Mitarbeiter
{
private:
	//Task: saved name, vorname, geburtsdatum, grad der Behinderung, Bereits in Anspruch genommener Urlaub
	string name, vorname;
	Date gebdatum;
	int beh, ulbtage, maxulbtage;
	bool filled;

public: 
	Mitarbeiter();
	Mitarbeiter(string n, string v, Date g, int b, int u, int m, bool f); 
	~Mitarbeiter();
	static Mitarbeiter createMitarbeiter();
	bool getfilled();
	string getname(), getvorname(), getgebdatumstring();
	int getbeh(), getulbtage(), getmaxulbtage();
	Date getgebdatum();
	void setgebdatum(), setbeh(), setulbtage(int u), setmaxulbtage();
};

//default Date constructor
Date::Date() : day(0), month(0), year(0) {}

//Date constructor with all date members as parameters
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

//factory function for creating a Date object (learnt Chapter 7: page 7/8 in slide)
Date Date::createDate()
{
	int d, m, y;

	do
	{	
		cout << "Year (Input 1950 - 2030): ";
		cin >> y;
		if (y < 1950 || y > 2030)
		{
			cout << "-- Only years 1950 to 2030 are accpeted. No employee is that old..." << endl;
		}
		else
		{
			break;
		}
	}
	while (true);
	do
	{
		cout << "Month (Input 1 - 12): ";
		cin >> m;
		if (m < 1 || m > 12)
		{
			cout << "-- There are 12 months in a year(every year in fact)... -_-" << endl; 
		}
		else 
		{
			break;
		}
	}
	while (true);
	do
	{
		string month[] = {"January", "February", "March", "April", "May", "June", "July", "August", 
			"September", "October", "November", "December"};
		cout << "Day (Input 1 - 31): ";
		cin >> d;
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		{
			if (d < 1 || d > 31)
			{
				cout << "-- " << month[m - 1] << " has between 1 and 31 days." << endl;
			}
			else
			{
				break;
			}
		}
		else if (m == 4 || m == 6 || m == 9 || m == 11)
		{
			if (d < 1 || d > 30)
			{
				cout << "-- " << month[m - 1] << " has between 1 and 30 days." << endl;
			}
			else
			{
				break;
			}
		}
		else if (m == 2)
		{
			//en.wikipedia.org/wiki/Leap_year
			if (y % 4 == 0 && !(y % 100 == 0 && y % 400 != 0))
			{
				if (d < 1 || d > 29)
				{
					cout << "-- " << month[m - 1] << " in " << y << " has between 1 and 29 days." 
						<< endl;
				}
				else
				{
					break;
				}
			}
			else
			{
				if (d < 1 || d > 28)
				{
					cout << "-- " << month[m - 1] << " in " << y << " has between 1 and 28 days." 
						<< endl;
				}
				else
				{
					break;
				}
			}
		}
	}
	while(true);

	return Date(d, m, y);
}

//destructor for class Date
Date::~Date() {}

//day getter function from class Date
int Date::getday()
{
	return day;
}

//month getter function from class Date
int Date::getmonth()
{
	return month;
}

//year getter function from class Date
int Date::getyear()
{
	return year;
}

//day setter function for class Date
//takes an integer d as parameter to be set as day
void Date::setday(int d)
{
	day = d;
}

//month setter function for class Date
//takes an integer m as parameter to be set as month
void Date::setmonth(int m)
{
	month = m;
}

//year setter function for class Date
//takes an integer y as parameter to be set as year
void Date::setyear(int y)
{
	year = y;
}

//default constructor needed for declaring mitarbeiter array
Mitarbeiter::Mitarbeiter() : name(""), vorname(""), gebdatum(Date()), beh(0), ulbtage(0), maxulbtage(30), filled(false) {}

//Mitarbeiter constructor with all Mitarbeiter data members 
Mitarbeiter::Mitarbeiter(string n, string v, Date g, int b, int u, int m, bool f) : name(n), vorname(v), gebdatum(g), beh(b), ulbtage(u), maxulbtage(m), filled(f) {}; 

//factory function for creating a Mitarbeiter object (learnt Chapter 7: page 7/8 in slide)
Mitarbeiter Mitarbeiter::createMitarbeiter()
{
	string n, v;
	Date g;
	int b;
	int u = 0;
	int m = 30;
	bool f = true;

	cout << "Mitarbeiter surname(family name): ";
	cin >> n;
	cout << "Mitarbeiter first name: ";
	cin >> v;
	cout << "Mitarbeiter date of birth: " << endl;
	g = Date::createDate();

	do 
	{
		cout << "Mitarbeiter degree of disability(in percentage[no more than 100%]): ";
		cin >> b;
		if (b < 0 || b > 100)
		{
			cout << "Mitarbeiter disability can only be between 0 and 100 percent." << endl;
		}
		else
		{
			cout << "\nNew Mitarbeiter added." << endl << endl;
			break;
		}
	}
	while(true);

	return Mitarbeiter(n, v, g, b, u, m, f);
}

//destructor for class Mitarbeiter
Mitarbeiter::~Mitarbeiter() {}

//name getter function from class Mitarbeiter
string Mitarbeiter::getname()
{
	return name;
}

//vorname getter function from class Mitarbeiter
string Mitarbeiter::getvorname()
{
	return vorname;
}

//gebdatum getter function from class Mitarbeiter
//returns a string for the gebdatum date object in the form d/m/y
string Mitarbeiter::getgebdatumstring()
{
	//to_string was used to convert int to string. Converting int to char would work but would require 
	//use of std::string(1, char) to convert to string (which might not be accepted) OR use of char 
	//arrays and pointers (which are not in the scope of part 1: chapters 1 - 9)
	string gebstring = to_string(gebdatum.getday()) + "/" + to_string(gebdatum.getmonth()) + "/" 
		+ to_string(gebdatum.getyear());

	return gebstring;
}

//getbeh getter function from class Mitarbeiter
int Mitarbeiter::getbeh()
{
	return beh;
}

//ulbtage getter function from class Mitarbeiter
int Mitarbeiter::getulbtage()
{
	return ulbtage;
}

//gebdatum getter function from class Mitarbeiter
//returns gebdatum which is an object of the Date class
Date Mitarbeiter::getgebdatum()
{
	return gebdatum;
}

//getfilled getter function from class Mitarbeiter
bool Mitarbeiter::getfilled()
{
	return filled;
}

//gebdatum setter function for class Mitarbeiter
void Mitarbeiter::setgebdatum()
{
	gebdatum = Date::createDate();
	cout << "\nDate of birth updated." << endl << endl;
}

//beh setter function for class Mitarbeiter
//makes sure user is only allowed to set a value between 0 and 100
void Mitarbeiter::setbeh()
{
	int b;
	do 
	{
		cout << "Mitarbeiter degree of disability(in percentage[no more than 100%]): ";
		cin >> b;
		if (b < 0 || b > 100)
		{
			cout << "Mitarbeiter disability can only be between 0 and 100 percent." << endl;
		}
		else
		{
			cout << "\nDegree of disability updated." << endl << endl;
			break;
		}
	}
	while(true);
	beh = b;
}

//ulbtage setter function for class Mitarbeiter
//takes an integer u as parameter to be set as ulbtage
void Mitarbeiter::setulbtage(int u)
{
	ulbtage = u;
}

//sets ulbtage based on Mitarbeiter gebdatum and beh
void Mitarbeiter::setmaxulbtage()
{
	//Task: Every employee is entitled to 30 days vacation
	maxulbtage = 30;

	//Task: Employees turned 50 by January 1st 2024 receive 32 days vacation
	if (gebdatum.getyear() < 1974)
	{
		maxulbtage += 2;
	}

	//Task: Employees with a degree of disability of at least 50% receive an additional 5 days vacation
	if (beh >= 50)
	{
		maxulbtage += 5;
	}
}

//maxulbtage getter function from class Mitarbeiter
int Mitarbeiter::getmaxulbtage()
{
	return maxulbtage;
}

//Task: array to store 500 Mitarbeiter objects
Mitarbeiter mitarbeiter[500];
//all function are defined below int main()
//Task: creation of a Mitarbeiter object
void addmittoarray();
int searchmitbyname();
void editmitinarray();
//Task: deletion of a Mitarbeiter object
void deletemitfromarray();
//Task: entering Mitarbeiter object vacation days by date input
void addmitvacday(int index);
bool datevalid(Date dateone, Date datetwo);
bool lastdayinmonth(Date date);
//Task: searching for Mitarbeiter object with output of his data and displays vacation he has left
void displaymitbyname();
void bubblesortmitarraybyname();
//Task: list all stored Mitarbeiter object data
void listallmitsorted();

int main()
{
	cout << "====================================" << endl;
	cout << "| Welcome to Mitarbeiter database. |" << endl;
	cout << "====================================" << endl;
	cout << "**Behold the best Mitarbeiter database ever." << endl << endl << endl;

	bool z = true;

	do
	{
		int menu;
		
		cout << "++ Mitarbeiter database options ++" << endl;
		cout << "(0) -- Quit Mitarbeiter database" << endl;
		cout << "(1) -- Add new Mitarbeiter" << endl;
		cout << "(2) -- Edit existing Mitarbeiter/Add vacation" << endl;
		cout << "(3) -- Delete a Mitarbeiter" << endl;
		cout << "(4) -- Display a Mitarbeiter by name" << endl;
		cout << "(5) -- List all Mitarbeiter [sorted by surname(family name)]" << endl;
		cout << "Choose an option: ";
		cin >> menu;
		cout << endl;

		switch (menu)
		{
			case 0: 
			{
				do 
				{
					char exitconf;
					cout << "!!! You are about to quit the database. No information will be " 
						<< "saved. !!!" << endl;
					cout << "Enter \"y\" to quit or \"n\" to cancel: ";
					cin >> exitconf;
					cout << endl;

					if (exitconf == 'y' || exitconf == 'Y')
					{
						cout << "Program termination confirmed..." << endl << endl;
						z = false;
						break;
					}
					else if (exitconf == 'n' || exitconf == 'N')
					{
						cout << "Program termination denied..." << endl << endl;
						break;
					}
					else 
					{
						cout << "Wrong key input..." << endl << endl;
						//Without c.ignore(), an infinite error loop will happen
						//Ignores up to 10000 characters or when newline is input
						cin.ignore(10000, '\n');
					}
				}
				while (true);
				break;
			}
			case 1: 
			{
				addmittoarray();
				break;
			}
			case 2:
			{
				editmitinarray();
				break;
			}
			case 3:
			{
				deletemitfromarray();
				break;
			}
			case 4: 
			{
				displaymitbyname();
				break;
			}
			case 5:
			{
				listallmitsorted();
				break;
			}
			default:
			{
				cout << "Invalid option. Loading valid options..." << endl << endl;
				break;
			}
		}
	}
	while (z);

	cout << "Program has been terminated... Now grab some coffee..." << endl << endl;

	return 0;
}

//adds a Mitarbeiter object to the mitarbeiter array
void addmittoarray()
{
	for (int i = 0; i < 500; i++)
	{
		if (!mitarbeiter[i].getfilled())
		{
			mitarbeiter[i] = Mitarbeiter::createMitarbeiter();
			break;
		}
	}
}

//searches for a Mitarbeiter object in the mitarbeiter array by input of name and vorname
int searchmitbyname()
{
	string ms, mf;
	cout << "Mitarbeiter surname(family name) [case sensitive]: ";
	cin >> ms;
	cout << "Mitarbeiter first name [case sensitive]: ";
	cin >> mf;

	for (int i = 0; i < 500; i++)
	{
		if (mitarbeiter[i].getname() == ms)
		{
			if (mitarbeiter[i].getvorname() == mf)
			{
				return i;
			}
		}
	}

	cout << "Mitarbeiter with the name " << mf << " " << ms << " doesn't exist." << endl << endl;
	return -1;
}

//shows user options to edit a Mitarbeiter object in mitarbeiter array
void editmitinarray()
{
	cout << "To edit a Mitarbeiter, please input the following..." << endl;
	int index = searchmitbyname();
	cout << endl;
	
	if (index == -1)
	{
		return;
	}

	bool y = true;

	do
	{
		int editmenu;

		cout << "++ Mitarbeiter editing options ++" << endl;
		cout << "**Surname(family name) and first name cannot be changed." << endl;
		cout << "(0) -- Quit editing" << endl;
		cout << "(1) -- Change date of birth" << endl;
		cout << "(2) -- Change disability status" << endl;
		cout << "(3) -- Add vacation days" << endl;
		cout << "Choose an option: ";
		cin >> editmenu;
		cout << endl;

		switch (editmenu)
		{
			case 0:
			{
				y = false;
				break;	
			}
			case 1:
			{
				cout << "To change date of birth, please input the following..." << endl;
				mitarbeiter[index].setgebdatum();
				break;
			}
			case 2:
			{
				cout << "To change disability status, please input the following..." << endl;
				mitarbeiter[index].setbeh();
				break;
			}
			case 3: 
			{
				cout << "To add vacation days, please input the following..." << endl;
				addmitvacday(index);
				break;
			}
		}
	}
	while (y);
}

//allows user to add vacation days by input of the start and end days of said vacation
void addmitvacday(int index)
{
	cout << "First day of vacation...";
	Date dateone = Date::createDate();
	cout << "\nFirst day back to work...";
	Date datetwo = Date::createDate();
	cout << endl;

	Date gebdatum = mitarbeiter[index].getgebdatum();
	mitarbeiter[index].setmaxulbtage();
	int addeddaycount = 0;

	//makes sure second day isn't smaller than the first
	if (!datevalid(dateone, datetwo))
	{
		cout << "Invalid set of dates..." << endl;
		return;
	}

	while (true)
	{
		int y = dateone.getyear();
		int m = dateone.getmonth();
		int d = dateone.getday();

		if (lastdayinmonth(dateone))
		{
			if (m == 12)		
			{
				dateone.setday(1);
				dateone.setmonth(1);
				dateone.setyear(y + 1);
			}
			else
			{
				dateone.setday(1);
				dateone.setmonth(m + 1);
			}
		}
		else
		{
			dateone.setday(d + 1);
		}

		addeddaycount++;

		if (!datevalid(dateone, datetwo))
		{
			break;
		}
	}

	//checks if ulbtage and extra vacation days exceed maxulbtage
	//if yes, extra vacation days will not be added
	if (mitarbeiter[index].getulbtage() + addeddaycount <= mitarbeiter[index].getmaxulbtage() 
			&& addeddaycount != 0) 
	{
		mitarbeiter[index].setulbtage(mitarbeiter[index].getulbtage() + addeddaycount);
		cout << addeddaycount << " vacation days added." << endl << endl;
	}
	else
	{
		cout << endl << mitarbeiter[index].getname() << ", " << mitarbeiter[index].getvorname() << " doesn't"
			<< " have enough vacation days." << endl << endl;
	}
}

//helper function for addmitvaday() to see if dateone is actually smaller than datetwo
//requires two Date objects as parameters to be compared
bool datevalid(Date dateone, Date datetwo)
{
	int yone = dateone.getyear();
	int mone = dateone.getmonth();
	int done = dateone.getday();
	int ytwo = datetwo.getyear();
	int mtwo = datetwo.getmonth();
	int dtwo = datetwo.getday();

	if (yone < ytwo)
	{
		return true;
	}
	else if (yone == ytwo)
	{
		if (mone < mtwo)
		{
			return true;
		}
		else if (mone == mtwo)
		{
			if (done < dtwo)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//helper function to check if the day is the last day in the month
//takes a Date as a parameter and returns true or false
bool lastdayinmonth(Date date)
{
	int y = date.getyear();
	int m = date.getmonth();
	int d = date.getday();

	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		if (d == 31)
		{
			return true;
		}
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		if (d == 30)
		{
			return true;
		}
	}
	else if (m == 2)
	{
		if (y % 4 == 0 && !(y % 100 == 0 && y % 400 != 0))
		{
			if (d == 29)
			{
				return true;
			}
		}
		else
		{
			if (d == 28)
			{
				return true;
			}
		}
	}

	return false;
}

//deletes a Mitarbeiter object from mitarbeiter array
void deletemitfromarray()
{
	int index = searchmitbyname();
	mitarbeiter[index] = Mitarbeiter();

	cout << "\nMitarbeiter deleted." << endl << endl;
}

//shows user data of a Mitarbeiter object from the mitarbeiter array
//will prompt user for name and vorname
void displaymitbyname()
{
	cout << "To display a Mitarbeiter, please input the following..." << endl;
	int index = searchmitbyname();

	if (index > -1 && index < 500)
	{
		Mitarbeiter mittbd = mitarbeiter[index];
		cout << "========== Displaying Mitarbeiter ==========" << endl;
		cout << "\nMitarbeiter surname(family name): " << mittbd.getname() << endl;
		cout << "Mitarbeiter first name: " << mittbd.getvorname() << endl;
		cout << "Mitarbeiter date of birth: " << mittbd.getgebdatumstring() << endl;
		cout << "Mitarbeiter degree of disability: " << mittbd.getbeh() << "%" << endl;
		cout << "Mitarbeiter vacation day(s) taken: " << mittbd.getulbtage() << endl;
		cout << "Mitarbeiter vacation day(s) remaining: " << mittbd.getmaxulbtage() - mittbd.getulbtage() 
			<< endl << endl;
	}
}

//bubble sorts the mitarbeiter array by name
void bubblesortmitarraybyname()
{
	Mitarbeiter temp;

	for (int i = 0; i < 499; ++i)
	{
		for (int j = 0; j < 499 - i; ++j)
		{
			if (mitarbeiter[j].getname() > mitarbeiter[j + 1].getname())
			{
				temp = mitarbeiter[j];
				mitarbeiter[j] = mitarbeiter[j + 1];
				mitarbeiter[j + 1] = temp;
			}
		}
	}
}

//lists all Mitarbeiter objects in the mitarbeiter array that have the data "filled" as true bubble sorted by name
void listallmitsorted()
{
	bubblesortmitarraybyname();

	int count = 1;
	for (int i = 0; i < 500; i++)
	{
		if (mitarbeiter[i].getfilled())
		{
			Mitarbeiter mittbd = mitarbeiter[i];
			cout << count << ". ===============================" << endl;
			cout << "Mitarbeiter surname(family name): " << mittbd.getname() << endl;
			cout << "Mitarbeiter first name: " << mittbd.getvorname() << endl;
			cout << "Mitarbeiter date of birth: " << mittbd.getgebdatumstring() << endl;
			cout << "Mitarbeiter degree of disability: " << mittbd.getbeh() << "%" << endl;
			cout << "Mitarbeiter vacation day(s) taken: " << mittbd.getulbtage() << endl;
			cout << "Mitarbeiter vacation day(s) remaining: " 
				<< mittbd.getmaxulbtage() - mittbd.getulbtage() << endl << endl;
			
			count++;
		}
	}
}
