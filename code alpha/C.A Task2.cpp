#include <iostream>
using namespace std;

int main() {

    string usernames[100];
    string passwords[100];
    int userCount = 0;

    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {

            string username, password;
            bool exists = false;

            cout << "\nEnter Username: ";
            cin >> username;

            // Check duplicate username
            for(int i = 0; i < userCount; i++) {
                if(usernames[i] == username) {
                    exists = true;
                    break;
                }
            }

            if(exists) {
                cout << "Username already exists!\n";
            } else {

                cout << "Enter Password: ";
                cin >> password;

                usernames[userCount] = username;
                passwords[userCount] = password;
                userCount++;

                cout << "Registration Successful!\n";
            }
        }

        else if(choice == 2) {

            string username, password;
            bool found = false;

            cout << "\nEnter Username: ";
            cin >> username;

            cout << "Enter Password: ";
            cin >> password;

            // Check login
            for(int i = 0; i < userCount; i++) {
                if(usernames[i] == username && passwords[i] == password) {
                    found = true;
                    break;
                }
            }

            if(found)
                cout << "Login Successful!\n";
            else
                cout << "Invalid Username or Password!\n";
        }

        else if(choice == 3) {
            cout << "Exiting program...\n";
        }

        else {
            cout << "Invalid choice!\n";
        }

    } while(choice != 3);

    return 0;
}
