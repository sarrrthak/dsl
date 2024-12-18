#include <iostream>
#include <string>
using namespace std;
struct Node {
int PRN;
string name;
Node* next;
};
Node* president = nullptr;
Node* secretary = nullptr;
// Function to add a new member
void addMember(Node*& head, int PRN, string name) {
Node* newNode = new Node;
newNode->PRN = PRN;
newNode->name = name;
newNode->next = nullptr;
if (head == nullptr) {
head = newNode;
secretary = newNode;
} else {
Node* current = head;
while (current->next != nullptr) {
current = current->next;
}
current->next = newNode;
secretary = newNode;
}
}
// Function to add a new president at the start
void addPresident(Node*& head, int PRN, string name) {
Node* newNode = new Node;
newNode->PRN = PRN;
newNode->name = name;
newNode->next = head;
head = newNode;
president = newNode;
// Update secretary if the list was empty
if (secretary == nullptr) {
secretary = newNode;
}
}
// Function to add a new secretary at the end
void addSecretary(Node*& head, int PRN, string name) {
Node* newNode = new Node;
newNode->PRN = PRN;
newNode->name = name;
newNode->next = nullptr;
if (head == nullptr) {
head = newNode;
president = newNode;
secretary = newNode;
} else {
Node* current = head;
while (current->next != nullptr) {
current = current->next;
}
current->next = newNode;
secretary = newNode;
}
}
// Function to delete a member by PRN
void deleteMember(Node*& head, int PRN) {
if (head == nullptr) {
cout << "List is empty." << endl;
return;
}
if (head->PRN == PRN) {
Node* temp = head;
head = head->next;
delete temp;
return;
}
Node* current = head;
while (current->next != nullptr && current->next->PRN != PRN) {
current = current->next;
}
if (current->next == nullptr) {
cout << "Member not found." << endl;
return;
}
Node* temp = current->next;
current->next = current->next->next;
delete temp;
}
// Function to compute the total number of members
int countMembers(Node* head) {
int count = 0;
while (head != nullptr) {
count++;
head = head->next;
} return count;
}
// Function to display members
void displayMembers(Node* head) {
if (head == nullptr) {
cout << "List is empty." << endl;
return;
}
cout << "President: " << head->name << endl;
head = head->next;
while (head != nullptr) {
cout << head->name << endl;
head = head->next;
}
cout << "Secretary: " << secretary->name << endl;
}
int main() {
Node* clubMembers = nullptr;
int choice;
do {
cout << "\nMenu:\n";
cout << "1. Add member\n";
cout << "2. Delete member\n";
cout << "3. Count members\n";
cout << "4. Display members\n";
cout << "5. Add president\n";
cout << "6. Add secretary\n";
cout << "7. Exit\n";
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
case 1: {
int PRN;
string name;
cout << "Enter PRN: ";
cin >> PRN;
cout << "Enter name: ";
cin >> name;
addMember(clubMembers, PRN, name);
break;
}
case 2: {
int PRN;
cout << "Enter PRN to delete: ";
cin >> PRN;
deleteMember(clubMembers, PRN);
break;
}
case 3: {
int totalMembers = countMembers(clubMembers);
cout << "Total members: " << totalMembers << endl;
break;
}
case 4: {
displayMembers(clubMembers);
break;
}
case 5: {
int PRN;
string name;
cout << "Enter PRN for president: ";
cin >> PRN;
cout << "Enter name for president: ";
cin >> name;
addPresident(clubMembers, PRN, name);
break;
}
case 6: {
int PRN;
string name;
cout << "Enter PRN for secretary: ";
cin >> PRN;
cout << "Enter name for secretary: ";
cin >> name;
addSecretary(clubMembers, PRN, name);
break;
}
case 7: {
cout << "Exiting...\n";
break;
}
default: {
cout << "Invalid choice.\n";
break;
}
}
} while (choice != 7);
return 0;
}
