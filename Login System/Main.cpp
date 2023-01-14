//Made by Christopher Mili and Lukas Yamazaki

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int login() {
	int storedLine;
	int line = 1;
	int uver = 0;
	int pver = 0;
	int login = 0;
	string userName;
	string password;
	string yourPhrase;
	string s;
	//Loading files for Login
	ifstream p("Saved Passwords.txt", ios_base::app);
	ifstream u("Saved Logins.txt", ios_base::app);
	ifstream t("Saved text.txt", ios_base::app);

	cout << "Username: ";
	getline(cin, userName);
	cout << "Password: ";
	getline(cin, password);

	for (int i = 1; i <= line; i++) {
		getline(u, s);

		if (s != userName) {
			line++;
			uver = 1;
		}
		else {
			storedLine = i;
		}
	}
	for (int i = 1; i <= storedLine; i++) {
		getline(p, s);

		if (s == password && i == storedLine) {
			pver = 1;
		}
	}

	if (pver == 1 && uver == 1) {
		cout << "stupid Ni";
	}

	cout << endl << endl << uver << endl << pver;

	return 0;
}

int main() {
	string userName;
	string password;
	string yourPhrase;
	
	int choice;
	
	cout << "Would you like to \n1. Register\n2. Login\nChoice: ";
	cin >> choice;
	cin.ignore();

		//register
		if (choice == 1) {
			//Loading files for register
			ofstream p("Saved Passwords.txt", ios_base::app);
			ofstream u("Saved Logins.txt", ios_base::app);
			ofstream t("Saved text.txt", ios_base::app);
			
			//gathering info
			cout << "Username(No Spaces): ";
			getline(cin, userName);
			u << userName << endl;
			cout << "Password(No Spaces): ";
			getline(cin, password);
			p << password << endl;
			cout << "Phrase to Save: ";
			getline(cin, yourPhrase);
			t << yourPhrase << endl;
		}
		//login
		else if (choice == 2) {
			
			login();

		}
}