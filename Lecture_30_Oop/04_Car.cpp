/*
===============================
TOPIC: SIZE OF CLASS IN C++
===============================

1. Size of a class object depends on:
   - Data members (variables)
   - Padding / Memory Alignment

2. Member functions do NOT increase object size
   because functions are stored separately in memory.

3. Padding:
   Compiler adds extra unused bytes to improve
   memory access speed.

4. Memory Alignment:
   Object size is usually multiple of the
   largest datatype size inside the class.

--------------------------------
Example 1:
--------------------------------

class Car{
    int mileage; // 4 bytes
    int cost;    // 4 bytes
};

Total Size:
4 + 4 = 8 bytes

--------------------------------
Example 2:
--------------------------------

class Car{
    int mileage; // 4 bytes
    char cost;   // 1 byte
};

Actual memory:
int  -> 4 bytes
char -> 1 byte
padding -> 3 bytes

Total:
4 + 1 + 3 = 8 bytes

--------------------------------
Important Points:
--------------------------------

-> Functions do not affect sizeof(object)

-> Padding is automatically added by compiler

-> sizeof(object) includes:
   variables + padding

*/

#include <iostream>
using namespace std;

// Class with two int variables
class Car1
{
    int mileage; // 4 bytes
    int cost;    // 4 bytes

public:

    // Function does not affect object size
    void Display()
    {
        cout << "Car1 Function" << endl;
    }
};

// Class with int and char
class Car2
{
    int mileage; // 4 bytes
    char cost;   // 1 byte

public:

    // Function does not affect object size
    void Display()
    {
        cout << "Car2 Function" << endl;
    }
};

int main()
{
    Car1 obj1;
    Car2 obj2;

    // Printing object sizes
    cout << "Size of Car1 Object: "
         << sizeof(obj1) << " bytes" << endl;

    cout << "Size of Car2 Object: "
         << sizeof(obj2) << " bytes" << endl;

    return 0;
}