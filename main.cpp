#include <iostream>
#include <map>

using namespace std;

map<int, int> collectRoles(map<int, int> roles);

int main() {
    int numSides = -1;

    cout << "Enter the number of sides the dice has(treat d100 as a d10):";
    cin  >> numSides;

    map<int, int> roles;
    cout << "Role the dice and enter the results, enter a 0 to quit." << endl;
    roles = collectRoles(roles);


    return 0;
}

map<int, int> collectRoles(map<int, int> roles) {
    int currRole = 0;
    cout << "Role:";
    cin >> currRole;


    return roles;
}