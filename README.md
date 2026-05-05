#  Hospital Appointment Management System (C++)

##  Overview

This is a simple command-line based Hospital Appointment Management System implemented in C++.
The system allows users to schedule, manage, and organize patient appointments based on priority using a Binary Search Tree (BST).

---

##  Features

* Schedule a new appointment
* Display all appointments (sorted by priority)
* Search for appointments by priority
* Cancel appointments
* Display appointments based on urgency level
* Save appointments to a file
* Load appointments from a file

---

##  Data Structure Used

The system uses a **Binary Search Tree (BST)** to store and manage appointments efficiently.

* Each node represents an appointment
* Appointments are ordered by priority level
* Lower priority values represent more urgent cases

---

##  Project Structure

```
├── main.cpp          # Main program logic and user interface
├── BST.h             # Binary Search Tree implementation
├── appointments.txt  # File used for storing appointments
```

---

##  How to Run

### 1. Compile the program

```bash
g++ main.cpp -o app
```

### 2. Run the program

```bash
./app
```

---

##  Usage

After running the program, you will be presented with a menu:

```
1 - Schedule an appointment
2 - Display all appointments
3 - Search for an appointment
4 - Cancel an appointment
5 - Display less urgent appointments
6 - Display more urgent appointments
7 - Load appointments from file
0 - Exit
```

Follow the on-screen instructions to interact with the system.

---

## File Storage

Appointments are stored in a text file (`appointments.txt`) in the following format:

```
Patient Name
Priority Level
Department
```

---

## Limitations

* No input validation for incorrect data types
* Duplicate appointments may occur
* File handling is basic and appends data only
* User interface is command-line based

---

## Author

Developed as a C++ project demonstrating data structures and file handling concepts.

---
