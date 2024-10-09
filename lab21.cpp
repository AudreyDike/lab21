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
