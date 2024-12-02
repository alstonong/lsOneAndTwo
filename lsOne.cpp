#include <iostream>
using namespace std;

//code written in Linux
//code in Linux geschrieben

class Date
{
private: 
	int day, month, year;

public: 
	Date(int d, int m, int y);
};

class Mitarbeiter
{
private:
	string name, vorname;
	Date gebdatum;
	int beh, ulbtage;

public: 
	Mitarbeiter(string n, string v, Date g, int b);
};

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

//Factory function (learnt Chapter 7: page 7/8 in slide)
static Date createDate()
{
	int d, m, y;

	cout << "Year (1 - 3000): ";
	cin >> y;
	cout << "Month (1 - 12): ";
	cin >> m;
	do
	{
		cout << "Day (1 - 31): ";
		cin >> d;
		cout << endl;
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		{
			if (d < 32)
			{
				cout << "The month of " << m << " does not have " << d << " days." << endl << endl;
			}
			else
			{
				break;
			}
		}
		else if (m == 4 || m == 6 || m == 9 || m == 11)
		{
			if (d < 31)
			{
				cout << "The month of " << m << " does not have " << d << " days." << endl << endl;
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
				if (d < 29)
				{
					cout << "The month of " << m << " in " << y << " does not have " << d 
						<< " days." << endl << endl;
				}
				else
				{
					break;
				}
			}
			else
			{
				if (d < 28)
				{
					cout << "The month of " << m << " in " << y << " does not have " << d 
						<< " days." << endl << endl;
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

Mitarbeiter::Mitarbeiter(string n, string v, Date g, int b) : name(n), vorname(v), gebdatum(g), beh(b), ulbtage(30) {}

int main()
{
	cout << "====================================" << endl;
	cout << "| Welcome to Mitarbeiter database. |" << endl;
	cout << "====================================" << endl << endl << endl;

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
				string name, vorname;
				cout << "Mitarbeiter name(nachname/surname): ";
				cin >> name;
				cout << "Mitarbeiter vorname(first name): ";
				cin >> vorname;
				cout << "Mitarbeiter Geburtsdatum(birthdate): ";
				break;

			default:
				cout << "Invalid option. Loading options..." << endl << endl;
				break;
		}
	}
	while (z);

	cout << "Program has been terminated... Now grab some coffee..." << endl;

	return 0;
}
