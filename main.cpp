#include <iostream>
#include <iomanip>
#include <map>
#include <fstream>

using namespace std;

map<int, int> collectRoles(map<int, int> roles, int numSides);
void getResults(ofstream& out, map<int, int> roles, int numSides);

int NUM_ROLES_I = 0;
double NUM_ROLES_D = 0.0;

int main(int argc, char * argv[]) {
    int numSides = -1;

    cout << "Enter the number of sides the dice has(treat d100 as a d10):";
    cin  >> numSides;

    map<int, int> roles;
    cout << "Roll the dice and enter the results, enter a 0 to quit." << endl;
    roles = collectRoles(roles, numSides);

    ofstream out(argv[1]);
    if (!out.is_open()) {
        cout << "failed to open output" << endl;
        return 1;
    }
    getResults(out, roles, numSides);

    return 0;
}

map<int, int> collectRoles(map<int, int> roles, int numSides) {
    int currRole = 0;
    cout << "Roll:";
    cin >> currRole;

    if (currRole == 0) {
        return roles;
    }
    else if (currRole < 0 || currRole > numSides) {
        cout << "Please enter a valid roll." << endl;
        roles = collectRoles(roles, numSides);
    }
    else {
        if (roles.find(currRole) == roles.end()) {
            roles.insert({currRole, 1});
        }
        else {
            ++roles.find(currRole)->second;
        }
        ++NUM_ROLES_I;
        ++NUM_ROLES_D;
        roles = collectRoles(roles, numSides);
    }

    return roles;
}

void getResults(ofstream& out, map<int, int> roles, int numSides) {
    out << "RESULTS" << endl << "TOTALS" << endl;

    for (int i = 1; i <= numSides; ++i) {
        out << i << ": ";

        if (roles.find(i) == roles.end()) {
            out << "0" << endl;
        }
        else {
            out << roles.find(i)->second << endl;
        }
    }
    out << "total: " << NUM_ROLES_I << endl << endl;

    out << "PERCENTAGES" << endl;
    for (int i = 1; i <= numSides; ++i) {
        out << i << ": ";

        if (roles.find(i) == roles.end()) {
            out << "0%" << endl;
        }
        else {
            out << fixed << setprecision(2);
            out << (roles.find(i)->second / NUM_ROLES_D) * 100 << "%" << endl;
        }
    }
    out << "ideal: " << (100.0 / numSides) << "%" << endl << endl;
}