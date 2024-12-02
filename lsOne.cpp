#include <iostream>
using namespace std;

//code written in Linux
//code in Linux geschrieben

int main()
{
	cout << "====================================" << endl;
	cout << "| Welcome to Mitarbeiter database. |" << endl;
	cout << "====================================" << endl << endl;

	bool z = true;

	do
	{
		int menu;
		
		cout << "++ Mitarbeiter database options ++" << endl;
		cout << "(0) -- Quit Mitarbeiter database." << endl;
		cout << "(1) -- " << endl;
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

			default:
				cout << "Invalid option. Loading options..." << endl << endl;
				break;
		}
	}
	while (z);

	cout << "Program has been terminated... Now grab some coffee..." << endl;

	return 0;
}
