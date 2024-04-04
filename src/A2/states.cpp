#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

enum class State {
    AL, AK, AZ, AR, CA, CO, CT, DE, DC, FL, GA, HI, ID, IL, IN, IA, KS, KY, LA, ME,
    MD, MA, MI, MN, MS, MO, MT, NE, NV, NH, NJ, NM, NY, NC, ND, OH, OK, OR, PA, RI,
    SC, SD, TN, TX, UT, VT, VA, WA, WV, WI, WY
};

class Patient {
private:
    string ssn;
    string firstName;
    string lastName;
    char middleInitial;
    string address;
    string city;
    char state[2]; // State input as char[2]
    string zip;

public:
    void inputData() {
        cout << "Enter SSN (9 digits): ";
        cin >> ssn;

        cout << "Enter first name: ";
        cin >> firstName;

        cout << "Enter last name: ";
        cin >> lastName;

        cout << "Enter middle initial: ";
        cin >> middleInitial;

        cin.ignore(); // Ignore newline character
        cout << "Enter address: ";
        getline(cin, address);

        cout << "Enter city: ";
        cin >> city;

        cout << "Enter state code (2 characters): ";
        cin >> state;

        cout << "Enter ZIP code: ";
        cin >> zip;
    }

    bool isValidState() {
        unordered_set<string> validStateCodes = readValidStateCodesFromFile("states.csv");
        string stateStr(state + 2); // Convert char[2] to string
        return validStateCodes.find(stateStr) != validStateCodes.end();
    }

private:
    unordered_set<string> readValidStateCodesFromFile(const string& filename) {
        unordered_set<string> validStateCodes;
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                stringstream ss(line);
                string stateCode;
                getline(ss, stateCode, ','); // Assuming state code is the first column
                validStateCodes.insert(stateCode);
            }
            file.close();
        } else {
            cout << "Unable to open file: " << filename << endl;
        }
        return validStateCodes;
    }
};

int main() {
    Patient patient;
    patient.inputData();

    if (patient.isValidState()) {
        cout << "State is valid." << endl;
    } else {
        cout << "State is not valid." << endl;
    }

    return 0;
}
