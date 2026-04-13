/*#include <iostream>
#include "Pose.h"

using namespace std;

int main() {
    Pose p1(2.0, 3.0, 45.0);
    Pose p2(5.0, 7.0, 90.0);

    cout << "Initial Pose 1: ";
    p1.print();

    cout << "Initial Pose 2: ";
    p2.print();

    cout << "\nTesting Setters...\n";
    p1.setX(10.0);
    p1.setY(20.0);
    p1.setTh(135.0);

    cout << "Updated Pose 1: ";
    p1.print();

    cout << "\nTesting Distance and Angle Calculation...\n";
    double distance = p1.findDistanceTo(p2);
    double angle = p1.findAngleTo(p2);

    cout << "Distance between Pose 1 and Pose 2: " << distance << " units\n";
    cout << "Angle from Pose 1 to Pose 2: " << angle << " degrees\n";

    cout << "\nTesting Operator Overloads...\n";
    Pose p3 = p1 + p2;
    cout << "Pose 3 (p1 + p2): ";
    p3.print();

    Pose p4 = p2 - p1;
    cout << "Pose 4 (p2 - p1): ";
    p4.print();

    p1 += p2;
    cout << "Pose 1 after += Pose 2: ";
    p1.print();

    cout << "\nTesting Equality Operator...\n";
    Pose p5(5.0, 7.0, 90.0);

    if (p2 == p5) {
        cout << "Pose 2 and Pose 5 are equal.\n";
    }
    else {
        cout << "Pose 2 and Pose 5 are NOT equal.\n";
    }

    cout << "\nTesting Less Than Operator...\n";
    if (p1 < p2) {
        cout << "Pose 1 is less than Pose 2.\n";
    }
    else {
        cout << "Pose 1 is NOT less than Pose 2.\n";
    }

    return 0;
}
*/