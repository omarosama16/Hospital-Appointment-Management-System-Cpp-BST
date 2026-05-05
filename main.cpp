#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"

using namespace std;

void saveToFile(string name, int priority, string department)
{
    ofstream file("appointments.txt", ios::app);
    file << name << "\n" << priority << "\n" << department << "\n";
    file.close();
}

void loadFromFile(BST &appointmentTree)
{
    ifstream file("appointments.txt");
    if (!file)
    {
        cout << "appointments.txt not found." << endl;
        return;
    }

    string name, department;
    int priority;
    int count = 0;

    while (getline(file, name))
    {
        file >> priority;
        file.ignore();
        getline(file, department);
        appointmentTree.scheduleAppointment(Appointment(name, priority, department));
        count++;
    }

    file.close();
    cout << count << " appointment(s) loaded from file." << endl;
}

int main()
{
    BST appointmentTree;

    int option;
    do
    {
        cout << "--- Hospital appointment System ---" << endl;
        cout << "1-Schedle an appointment" << endl;
        cout << "2-Display all appointments" << endl;
        cout << "3-Search for an appointment" << endl;
        cout << "4-Cancel an appointment" << endl;
        cout << "5-Display less urgent than" << endl;
        cout << "6-Display more urgent than" << endl;
        cout << "7-Load appointments from file" << endl;
        cout << "0-Exit" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Enter number of opton: ";
        cin >> option;
        cin.ignore();

        if (option == 1)
        {
            string name, department;
            int priority;
            cout << "Enter patient name : ";
            getline(cin, name);
            cout << "Enter priority level : ";
            cin >> priority;
            cin.ignore();
            cout << "Enter department: ";
            getline(cin, department);

            appointmentTree.scheduleAppointment(Appointment(name, priority, department));
            saveToFile(name, priority, department);
        }
        else if (option == 2)
        {
            appointmentTree.displayAll();
        }
        else if (option == 3)
        {
            int priority;
            cout << "Enter the priority level: ";
            cin >> priority;
            cin.ignore();
            appointmentTree.searchAppointment(priority);
        }
        else if (option == 4)
        {
            int priority;
            cout << "Enter the priority level : ";
            cin >> priority;
            cin.ignore();
            appointmentTree.cancelAppointment(priority);
        }
        else if (option == 5)
        {
            int priority;
            cout << "Display more urgent than: ";
            cin >> priority;
            cin.ignore();
            appointmentTree.displayMoreUrgentThan(priority);
        }
        else if (option == 6)
        {
            int priority;
            cout << "Display less urgent than: ";
            cin >> priority;
            cin.ignore();
            appointmentTree.displayLessUrgentThan(priority);
        }
        else if (option == 7)
        {
            loadFromFile(appointmentTree);
        }
        else if (option != 0)
        {
            cout << "invalid option please enter a number from 0 to 7" << endl;
        }
    } while (option != 0);

    return 0;
}

