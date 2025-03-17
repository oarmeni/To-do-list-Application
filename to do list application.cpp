#include <iostream>
#include <string>
#include <vector>
using namespace std;

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. View ToDo List\n";
    cout << "2. Add Item to ToDo List\n";
    cout << "3. Remove Item from ToDo List\n";
    cout << "4. Delete ToDo List\n";
    cout << "5. Logout\n";
    cout << "Enter your choice: ";
}

void displayToDoList(const vector<string>& toDoList) {
    if (toDoList.empty()) {
        cout << "ToDo List is empty." << endl;
        return;
    }
    cout << "ToDo List:" << endl;
    for (int i = 0; i < toDoList.size(); ++i) {
        cout << i + 1 << ") " << toDoList[i] << endl;
    }
}

void addItem(vector<string>& toDoList) {
    string item;
    cout << "Enter item to add: ";
    cin.ignore();
    getline(cin, item);
    toDoList.push_back(item);
    cout << "Item added successfully." << endl;
}

void removeItem(vector<string>& toDoList) {
    displayToDoList(toDoList);
    int choice;
    cout << "Enter the number of the item to remove: ";
    cin >> choice;
    if (choice > 0 && choice <= toDoList.size()) {
        toDoList.erase(toDoList.begin() + choice - 1);
        cout << "Item removed successfully." << endl;
    }
    else {
        cout << "Invalid choice." << endl;
    }
}

void deleteList(vector<string>& toDoList) {
    toDoList.clear();
    cout << "ToDo List deleted successfully." << endl;
}

int main() {
    string username, password, email;
    int attempts = 0;
    int tries = 0;
    char yn;
    int p = 0;
    bool userExists = false;
    vector<string> usernames{ "user1", "user2", "user3", "user4", "user5" };
    vector<string> passwords{ "pass1", "pass2", "pass3", "pass4", "pass5" };
    vector<string> emails{ "user1@gmail.com", "user2@gmail.com", "user3@gmail.com", "user4@gmail.com", "user5@gmail.com" };
    const int maxAttempts = 3;
    const int maxTries = 3;

    vector<vector<string>> userToDoLists = {
        {"Task 1", "Task 2"},
        {"Task 3"},
        {"Task 4", "Task 5"},
        {},
        {"Task 6", "Task 7", "Task 8"}
    };

    cout << "Are you a Registered User? Y/N: ";
    cin >> yn;

    if (yn == 'Y' || yn == 'y') {
        while (attempts < maxAttempts) {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            for (p = 0; p < usernames.size(); p++) {
                if (usernames[p] == username) {
                    userExists = true;
                    break;
                }
            }

            if (userExists && password == passwords[p]) {
                cout << "Login successful!" << endl;
                break;
            }
            else {
                attempts++;
                cout << "Invalid username or password. Try again." << endl;
            }
        }

        if (attempts == maxAttempts) {
            cout << "Too many failed attempts." << endl;
            while (tries < maxTries) {
                cout << "Please enter your verification email: ";
                cin >> email;
                if (userExists && email == emails[p]) {
                    cout << "Verification email successfully sent to: " << email << endl;
                    break;
                }
                else {
                    cout << "This email does not match an existing account. Try Again!" << endl;
                    tries++;
                }
            }
            return 1; 
        }
        while (true) {
            displayMenu();
            int choice;
            cin >> choice;
            switch (choice) {
            case 1:
                displayToDoList(userToDoLists[p]);
                break;
            case 2:
                addItem(userToDoLists[p]);
                break;
            case 3:
                removeItem(userToDoLists[p]);
                break;
            case 4:
                deleteList(userToDoLists[p]);
                break;
            case 5:
                cout << "Logging out..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
    else if (yn == 'N' || yn == 'n') {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        cout << "Enter email: ";
        cin >> email;
        usernames.push_back(username);
        passwords.push_back(password);
        emails.push_back(email);
        userToDoLists.push_back({});
        cout << "Sign Up Successful!" << endl;

        for (int i = 0; i < usernames.size(); i++) {
            cout << usernames[i] << endl;
        }
        p = usernames.size() - 1; 
        while (true) {
            displayMenu();
            int choice;
            cin >> choice;
            switch (choice) {
            case 1:
                displayToDoList(userToDoLists[p]);
                break;
            case 2:
                addItem(userToDoLists[p]);
                break;
            case 3:
                removeItem(userToDoLists[p]);
                break;
            case 4:
                deleteList(userToDoLists[p]);
                break;
            case 5:
                cout << "Logging out..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
    else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    return 0;
}
