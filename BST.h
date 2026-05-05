#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;

class Appointment {
public:
    string patientName;
    int    priorityLevel;
    string department;

    Appointment() : priorityLevel(0) {}

    Appointment(string name, int priority, string dept)
        : patientName(name), priorityLevel(priority), department(dept) {}

    void display() const {
        cout << "[" << patientName << ", "
             << priorityLevel << ", "
             << department << "]" << endl;
    }
};


class Node {
public:
    Appointment data;
    Node* left;
    Node* right;

    Node(Appointment appt) : data(appt), left(nullptr), right(nullptr) {}
};


class BST {
private:
    Node* root;

    Node* insert(Node* node, Appointment appt) {
        if (node == nullptr)
            return new Node(appt);


        if (appt.priorityLevel <= node->data.priorityLevel)
            node->left = insert(node->left, appt);
        else
            node->right = insert(node->right, appt);

        return node;
    }

    void inOrder(Node* node) const {
        if (node == nullptr) return;
        inOrder(node->left);
        node->data.display();
        inOrder(node->right);
    }

    int search(Node* node, int priority) const {
        if (node == nullptr) return 0;

        int count = 0;

        count += search(node->left, priority);

        if (node->data.priorityLevel == priority) {
            node->data.display();
            count++;
        }

        count += search(node->right, priority);

        return count;
    }

    Node* cancel(Node* node, int priority, int& count) {
        if (node == nullptr) return nullptr;

        node->left  = cancel(node->left,  priority, count);
        node->right = cancel(node->right, priority, count);

        if (node->data.priorityLevel == priority) {
            count++;

            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {

                Node* rightMost = node->left;
                while (rightMost->right != nullptr)
                    rightMost = rightMost->right;
                rightMost->right = node->right;
                Node* temp = node->left;
                delete node;
                return temp;
            }
        }

        return node;
    }


    int displayMoreUrgent(Node* node, int priority) const {
        if (node == nullptr) return 0;

        int count = 0;
        count += displayMoreUrgent(node->left, priority);

        if (node->data.priorityLevel <= priority) {
            node->data.display();
            count++;
        }

        count += displayMoreUrgent(node->right, priority);

        return count;
    }


    int displayLessUrgent(Node* node, int priority) const {
        if (node == nullptr) return 0;

        int count = 0;
        count += displayLessUrgent(node->left, priority);

        if (node->data.priorityLevel >= priority) {
            node->data.display();
            count++;
        }

        count += displayLessUrgent(node->right, priority);

        return count;
    }


    void destroy(Node* node) {
        if (node == nullptr) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}

    ~BST() { destroy(root); }

    void scheduleAppointment(Appointment appt) {
        root = insert(root, appt);
        cout << "Appointment scheduled." << endl;
    }


    void displayAll() const {
        if (root == nullptr) {
            cout << "No appointments available." << endl;
            return;
        }
        inOrder(root);
    }


    void searchAppointment(int priority) const {
        int count = search(root, priority);
        if (count == 0)
            cout << "No appointments found with priority " << priority << "." << endl;
        else
            cout << "//" << count << " appointment(s) found" << endl;
    }


    void cancelAppointment(int priority) {
        int count = 0;
        root = cancel(root, priority, count);
        if (count == 0)
            cout << "No appointments found with priority " << priority << "." << endl;
        else
            cout << "//" << count << " appointment(s) cancelled" << endl;
    }

    void displayMoreUrgentThan(int priority) const {
        int count = displayMoreUrgent(root, priority);
        if (count == 0)
            cout << "No appointments found." << endl;
        else
            cout << "//" << count << " appointment(s) found" << endl;
    }

    void displayLessUrgentThan(int priority) const {
        int count = displayLessUrgent(root, priority);
        if (count == 0)
            cout << "No appointments found." << endl;
        else
            cout << "//" << count << " appointment(s) found" << endl;
    }
};

#endif
