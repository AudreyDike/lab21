#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MIN_AGE = 1, MAX_AGE = 20, NAME_COUNT = 15, COLOR_COUNT = 15;
string names[NAME_COUNT] = {"Billy", "Nanny", "Gruff", "Daisy", "Shadow", "Rocky", "Butters", "Bucky", "Sunny", "Storm", "Blaze", "Midnight", "Misty", "Luna", "Chloe"};
string colors[COLOR_COUNT] = {"Black", "White", "Brown", "Grey", "Spotted", "Yellow", "Blue", "Green", "Red", "Purple", "Pink", "Orange", "Gold", "Silver", "Mauve"};

class Goat {
public:
    int age;
    string name;
    string color;
  // Default constructor with random values
    Goat() {
        age = rand() % (MAX_AGE - MIN_AGE + 1) + MIN_AGE;
        name = names[rand() % NAME_COUNT];
        color = colors[rand() % COLOR_COUNT];
    }

    // Parameterized constructor
    Goat(int a, string n, string c) : age(a), name(n), color(c) {}
};
class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;
        Node(Goat val, Node* p = nullptr, Node* n = nullptr) {
            data = val;
            prev = p;
            next = n;
        }
    };
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() { head = nullptr; tail = nullptr; }
 // Push back method for Goat objects
    void push_back(Goat goat) {
        Node* newNode = new Node(goat);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Push front method for Goat objects
    void push_front(Goat goat) {
        Node* newNode = new Node(goat);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Print the list forward
    void print() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = head;
        while (current) {
            cout << current->data.name << " (" << current->data.color << ", " << current->data.age << ")" << endl;
            current = current->next;
        }
    }

    // Print the list backward
    void print_reverse() {
        if (!tail) {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = tail;
        while (current) {
            cout << current->data.name << " (" << current->data.color << ", " << current->data.age << ")" << endl;
            current = current->prev;
        }
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
const int MAX_LS = 100;  
const int MIN_LS = 1;
int main() {
    srand(time(0));
    DoublyLinkedList goatList;

    int size = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS;
    for (int i = 0; i < size; ++i) {
        Goat goat; 
        goatList.push_back(goat);
    }

    cout << "Forward: " << endl;
    goatList.print();
    cout << "\n";
    cout << "Backward: " << endl;
    goatList.print_reverse();

    return 0;
}
