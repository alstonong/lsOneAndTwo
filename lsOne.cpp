#include <iostream>
using namespace std;

//code written in Linux
//code in Linux geschrieben

class Date
{
private: 
	int day, month, year;

public: 
	Date();
	Date(int d, int m, int y); 
	static Date createDate();
};

class Mitarbeiter
{
private:
	string name, vorname;
	Date gebdatum;
	int beh, ulbtage;
	bool filled;

public: 
	Mitarbeiter();
	Mitarbeiter(string n, string v, Date g, int b, int u, bool f); 
	static Mitarbeiter createEmployee();

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

//Default constructor needed for creating Mitarbeiter array
Mitarbeiter::Mitarbeiter() : name(""), vorname(""), gebdatum(Date()), beh(0), ulbtage(0), filled(false) {}

Mitarbeiter::Mitarbeiter(string n, string v, Date g, int b, int u, bool f) : name(n), vorname(v), gebdatum(g), beh(b), ulbtage(u), filled(f) {}

Mitarbeiter Mitarbeiter::createEmployee()
{
	string n, v;
	Date g;
	int b;
	int u = 30;
	bool f = true;

	cout << "Employee surname(family name): ";
	cin >> n;
	cout << "Employee first name: ";
	cin >> v;
	cout << "Employee date of birth: " << endl;
	Date d = Date::createDate();
	do 
	{
		cout << "Employee level of disability(in percentage[no more than 100%]): ";
		cin >> b;
		if (b < 0 || b > 100)
		{
			cout << "Employee disability can only be between 0 and 100 percent." << endl;
		}
		else
		{
			break;
		}
	}
	while(true);

	return Mitarbeiter(n, v, g, b, u, f);
}

int main()
{
	Mitarbeiter employee = Mitarbeiter::createEmployee();

	cout << "====================================" << endl;
	cout << "| Welcome to Mitarbeiter database. |" << endl;
	cout << "====================================" << endl << endl << endl;

	Mitarbeiter mitarbeiter[500];
	bool z = true;

	do
	{
		int menu;
		
		cout << "++ Mitarbeiter database options ++" << endl;
		cout << "(0) -- Quit Mitarbeiter database." << endl;
		cout << "(1) -- Add new Mitarbeiter." << endl;
		cout << "(2) -- " << endl;
		cout << "(3) -- " << endl;
		cout << "(4) -- " << endl;
		cout << "(5) -- " << endl;
		cout << "Choose an option: ";
		cin >> menu;
		cout << endl;

		switch (menu)
		{
			case 0: 
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
					}
				}
				while (true);
				break;
			case 1: 
			{
				break;
			}

			default:
				cout << "Invalid option. Loading options..." << endl << endl;
				break;
		}
	}
	while (z);

	cout << "Program has been terminated... Now grab some coffee..." << endl;

	return 0;
}
