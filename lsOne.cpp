#include <iostream>
using namespace std;

//code written in Linux
//code in Linux geschrieben
//github.com/alstonong/lsOneAndTwo to view commits

class Date
{
private: 
	int day, month, year;

public: 
	Date();
	Date(int d, int m, int y); 
	static Date createDate();
	int getday(), getmonth(), getyear();
	void setday(int d), setmonth(int m), setyear(int y);
};

class Mitarbeiter
{
private:
	string name, vorname;
	Date gebdatum;
	int beh, ulbtage, maxulbtage;
	bool filled;

public: 
	Mitarbeiter();
	Mitarbeiter(string n, string v, Date g, int b, int u, int m, bool f); 
	static Mitarbeiter createMitarbeiter();
	bool getfilled();
	string getname(), getvorname(), getgebdatumstring();
	int getbeh(), getulbtage(), getmaxulbtage();
	Date getgebdatum();
	void setgebdatum(), setbeh(), setulbtage(int u), setmaxulbtage();
};

//Default constructor needed for creating default Mitarbeiter constructor
Date::Date() : day(0), month(0), year(0) {}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

//Factory function (learnt Chapter 7: page 7/8 in slide)
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

int Date::getday()
{
	return day;
}

int Date::getmonth()
{
	return month;
}

int Date::getyear()
{
	return year;
}

void Date::setday(int d)
{
	day = d;
}

void Date::setmonth(int m)
{
	month = m;
}

void Date::setyear(int y)
{
	year = y;
}

//Default constructor needed for creating Mitarbeiter array
Mitarbeiter::Mitarbeiter() : name(""), vorname(""), gebdatum(Date()), beh(0), ulbtage(0), maxulbtage(30), filled(false) {}

Mitarbeiter::Mitarbeiter(string n, string v, Date g, int b, int u, int m, bool f) : name(n), vorname(v), gebdatum(g), beh(b), ulbtage(u), maxulbtage(m), filled(f) {}; 

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
			cout << "New Mitarbeiter added." << endl << endl;
			break;
		}
	}
	while(true);

	return Mitarbeiter(n, v, g, b, u, m, f);
}

string Mitarbeiter::getname()
{
	return name;
}

string Mitarbeiter::getvorname()
{
	return vorname;
}

string Mitarbeiter::getgebdatumstring()
{
	//to_string was used to convert int to string. Converting int to char would work but would require 
	//use of std::string(1, char) to convert to string (which might not be accepted) OR use of char 
	//arrays and pointers (which are not in the scope of part 1: chapters 1 - 9)
	string gebstring = to_string(gebdatum.getday()) + "/" + to_string(gebdatum.getmonth()) + "/" 
		+ to_string(gebdatum.getyear());

	return gebstring;
}

int Mitarbeiter::getbeh()
{
	return beh;
}

int Mitarbeiter::getulbtage()
{
	return ulbtage;
}

Date Mitarbeiter::getgebdatum()
{
	return gebdatum;
}

bool Mitarbeiter::getfilled()
{
	return filled;
}

void Mitarbeiter::setgebdatum()
{
	gebdatum = Date::createDate();
	cout << "Date of birth updated." << endl << endl;
}

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
			cout << "Degree of disability updated." << endl << endl;
			break;
		}
	}
	while(true);
	beh = b;
}

void Mitarbeiter::setulbtage(int u)
{
	ulbtage = u;
}

void Mitarbeiter::setmaxulbtage()
{
	if (gebdatum.getyear() + 50 > 2023)
	{
		if (beh > 49)
		{
			maxulbtage = 37;
		}
		else
		{
			maxulbtage = 32;
		}
	}
	else
	{
		if (beh > 49)
		{
			maxulbtage = 35;
		}
		else
		{
			maxulbtage = 30;
		}
	}
}

int Mitarbeiter::getmaxulbtage()
{
	return maxulbtage;
}

Mitarbeiter mitarbeiter[500];
void addmittoarray();
int searchmitbyname();
void editmitinarray();
void displaymitbyname();
void addmitvacday(int index);
bool datevalid(Date dateone, Date datetwo);
bool lastdayinmonth(Date date);
void increasedate(Date date);

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
		cout << "(2) -- Edit existing Mitarbeiter" << endl;
		cout << "(3) -- " << endl;
		cout << "(4) -- Display a Mitarbeiter by name" << endl;
		cout << "(5) -- " << endl;
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
			case 4: 
			{
				displaymitbyname();
				break;
			}
			default:
			{
				cout << "Invalid option. Loading options..." << endl << endl;
				break;
			}
		}
	}
	while (z);

	cout << "Program has been terminated... Now grab some coffee..." << endl << endl;

	return 0;
}

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

	cout << "Mitarbeiter with the name " << ms << " " << mf << " doesn't exist." << endl << endl;
	return -1;
}

void editmitinarray()
{
	cout << "To edit a Mitarbeiter, please input the following..." << endl;
	int index = searchmitbyname();

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

void addmitvacday(int index)
{
	cout << "First day of vacation...";
	Date dateone = Date::createDate();
	cout << "\nFirst day back to work...";
	Date datetwo = Date::createDate();
	Date gebdatum = mitarbeiter[index].getgebdatum();
	mitarbeiter[index].setmaxulbtage();

	if (!datevalid(dateone, datetwo))
	{
		cout << "Invalid set of dates..." << endl;
		return;
	}

	while (mitarbeiter[index].getulbtage() < mitarbeiter[index].getmaxulbtage())
	{
		mitarbeiter[index].setulbtage(mitarbeiter[index].getulbtage() + 1);
		increasedate(dateone);

		if (!datevalid(dateone, datetwo))
		{
			break;
		}
		cout << dateone.getday() << endl;
	}
}

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

void increasedate(Date date)
{
	int y = date.getyear();
	int m = date.getmonth();
	int d = date.getday();

	if (lastdayinmonth(date))
	{
		if (m == 12)
		{
			date.setday(1);
			date.setmonth(1);
			date.setyear(y + 1);
		}
		else
		{
			date.setday(1);
			date.setmonth(m + 1);
		}
	}
	else
	{
		date.setday(d + 1);
	}
}

void displaymitbyname()
{
	cout << "To display a Mitarbeiter, please input the following..." << endl;
	int index = searchmitbyname();

	if (index > -1 && index < 500)
	{
		Mitarbeiter mittbd = mitarbeiter[index];
		cout << "\nMitarbeiter surname(family name): " << mittbd.getname() << endl;
		cout << "Mitarbeiter first name: " << mittbd.getvorname() << endl;
		cout << "Mitarbeiter date of birth: " << mittbd.getgebdatumstring() << endl;
		cout << "Mitarbeiter degree of disability: " << mittbd.getbeh() << "%" << endl;
		cout << "Mitarbeiter vacation day(s) taken: " << mittbd.getulbtage() << endl << endl;
	}
}
