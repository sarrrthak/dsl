#include <iostream>
using namespace std;
#define SIZE 5
class PizzaParlor {
int porder[SIZE];
int front, rear;
public:
PizzaParlor() {
front = rear = -1;
}
bool isFull() {
return (front == 0 && rear == SIZE - 1) || (front == rear + 1) % SIZE;
}
bool isEmpty() {
return front == -1;
}
void acceptOrder(int item);
void makePayment(int n);
void viewPendingOrders();
};
void PizzaParlor::acceptOrder(int item) {
if (isFull()) {
cout << "\nSorry, we cannot accept more orders at the moment.\n";
} else {
if (front == -1) {
front = rear = 0;
} else {
rear = (rear + 1) % SIZE;
}
porder[rear] = item;
cout << "Order accepted successfully.\n";
}
}
void PizzaParlor::makePayment(int n) {
if (isEmpty()) {
cout << "\nNo pending orders to process.\n";
} else {
cout << "\nDelivering orders: ";
for (int i = 0; i < n; i++) {
int item = porder[front];
cout << "\t" << item;
if (front == rear) {
front = rear = -1; // Reset if the queue is empty
} else {
front = (front + 1) % SIZE;
}
}
cout << "\nTotal amount: " << n * 100 << " units.\n";
cout << "Thank you for visiting. See you again!\n";
}
}
void PizzaParlor::viewPendingOrders() {
if (isEmpty()) {
cout << "\nNo pending orders.\n";
} else {
cout << "\nPending orders are: ";
int temp = front;
while (temp != rear) {
cout << "\t" << porder[temp];
temp = (temp + 1) % SIZE;
}
cout << "\t" << porder[rear] << endl;
}
}
int main() {
PizzaParlor p1;
int choice, pizzaType, quantity;
do {
cout << "\n***** Welcome to Pizza Parlor *****";
cout << "\n1. Accept Order";
cout << "\n2. Make Payment";
cout << "\n3. View Pending Orders";
cout << "\n4. Exit";
cout << "\nEnter your choice: ";
cin >> choice;
switch (choice) {
case 1:
cout << "\nWhat type of pizza would you like to order?\n";
cout << "1. Veg Soya Pizza\n2. Veg Butter Pizza\n3. Egg Pizza\n";
cout << "Enter your choice: ";
cin >> pizzaType;
p1.acceptOrder(pizzaType);
break;
case 2:
cout << "\nHow many pizzas would you like to pay for? ";
cin >> quantity;
p1.makePayment(quantity);
break;
case 3:
p1.viewPendingOrders();
break;
case 4:
cout << "Exiting... Thank you for visiting!\n";
break;
default:
cout << "Invalid choice, please try again.\n";
}
} while (choice != 4);
return 0;
}
