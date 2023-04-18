// Your Programmmer and Program Information Here
#include <iostream>
#include "Circle.h"
using namespace std;
int readInt(string inputType = "", int min = INT_MIN, int max = INT_MAX);
int main()
{
    const int NUMB_CIRCLES = 4;
    // define an array of Circles
    Circle circleArray[NUMB_CIRCLES] = {
    Circle(50, 50, 10, Circle::RED), // fully initialized Valid Circle
    Circle(5, 5, 10, Circle::GREEN), // fully initialized but with an
                                        //    Invalid Circle radius
    Circle(80, 80) // partially initialized
    
        //  Note any remaining Circles in array are uninitialized

    };
    cout << "\nCIRCLE CLASS TEST CLIENT PROGRAM:\n";
    // display content of circleArray array testing displayCircle
    for (int i = 0; i < NUMB_CIRCLES; i++)
    {
        cout << "\nCircle #" << i + 1 << ":\n";
        circleArray[i].displayCircle();
    }
    Circle newCircle; // another circle to test public mutator functions
    int x, y; // to store coordinates of a Circle center point
    double r; // to store radius of a Circle
    int choice; // menu selection for Color
    bool isEqual; // result of testing equality of two Circles
    cout << "\n\nTesting invalid coordinates\n";
    cout << "\nThe next Circle is:\n";
    Circle cr(-1, 101, 5.5, static_cast<Circle::Color>(5));
    cr.displayCircle();
    cout << "\n\nTesting invalid negative radius and invalid Color\n";
    cout << "\nThe next Circle is:\n";
    Circle cr2(10, 10, -1, static_cast<Circle::Color>(6));
    cr2.displayCircle();
    // User testing 
    while (false);
    {
        cout << "\n\nEnter information for a new Circle.\n";
        cout << "\nEnter the X coordinate: ";
        cin >> x;
        cout << "\nEnter the Y coordinate: ";
        cin >> y;
        newCircle.setCoordinates(x, y);
        cout << "\nEnter the Radius of Circle: ";
        cin >> r;
        newCircle.setRadius(r);
        cout << "\nSelect a Color for Circle:\n";
        cout << "\t1. UNDEFINED" << endl;   // ordered list all Color enumerators
            cout << "\t2. BLACK" << endl;
        cout << "\t3. RED" << endl;
        cout << "\t4. BLUE" << endl;
        cout << "\t5. GREEN" << endl;
        cout << "\t6. YELLOW" << endl;
        choice = readInt("Color choice", 1, 6);
        newCircle.setColor(static_cast<Circle::Color>(choice - 1));
        cout << "\nThe new Circle is:\n";
        newCircle.displayCircle();
        // Test isEqual member function
        cout << "\n\nCheck if Circle class objects are equivalent.\n\n"
            << "Does this new circle equal the first circle?  \n";
        if (newCircle == circleArray[0])
            cout << "Yes: newCircle == circleArray[0]\n";
        else
            cout << "No: newCircle != circleArray[0]\n";
        // Test assignment of new Circle to the last Circle in array.\n";
        circleArray[3] = newCircle;
        cout << "\nAfter circleArray[3] = newCircle \n"
            << "Does this new circle equal the last circle?\n";
        isEqual = newCircle == circleArray[3];
        if (isEqual)
            cout << boolalpha << isEqual << ": newCircle "
            << (isEqual ? "==" : "!=") << " circleArray[3]\n";
        system("pause");
        cout << "\nThe final content of circleArray:";
        for (int i = 0; i < NUMB_CIRCLES; i++)
        {
            cout << "\nCircle #" << i + 1 << ":\n";
            circleArray[i].displayCircle();
        }
    }
    return 0;
}
/************************************readInt********************************
// description: Reads and validates an integer in the range between min and max.
// inputType: describes to user the type of data to reenter if error
encountered
// min:    the minimum acceptable value
// max:    the maximum acceptable value
// precondition: user has been prompted for input
//  inputType may be assigned a value, default argument is empty string
//  min and max may be assigned values, default arguments are system defaults
for int
//  uses header files: iostream, string, limits, cctype
// postcondition: a valid integer in the range min to max has been returned
******************************************************************************/
int readInt(string inputType, int min, int max)
{
    int anyInt;
    bool valid;
    do
    {
        cin >> anyInt;
        valid = anyInt >= min && anyInt <= max;
        // fails if out of valid range or if enters input fails state or 
        //   if a valid integer is followed by a non-integer char
        if (!valid || cin.fail() || !isspace(cin.peek()))
        {
            cout << "\nInvalid Input! " << inputType << " must be a whole number "
                << "between " << min << " and " << max << ".\nPlease try again. ---> ";
            cin.clear();  //  clears fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            valid = false;
        }
    } while (!valid);
    cin.ignore(100, '\n');
    return anyInt;
}
