#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <xlocmes>

using namespace std;

/*enum class State {
    AL, AK, AZ, AR, CA, CO, CT, DE, DC, FL, GA, HI, ID, IL, IN, IA, KS, KY, LA, ME,
    MD, MA, MI, MN, MS, MO, MT, NE, NV, NH, NJ, NM, NY, NC, ND, OH, OK, OR, PA, RI,
    SC, SD, TN, TX, UT, VT, VA, WA, WV, WI, WY
};*/

class Patient {
private:
    string ssn;
    string firstName;
    string lastName;
    char middleInitial;
    string address;
    string city;
    string state; // State input as char[2]
    string zip;

public:
    void inputData() {
        /*cout << "Enter SSN (9 digits): ";
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
        cin >> city;*/

        cout << "Enter state code (2 characters): ";
        cin >> state;

        while (isValidState(state) == false)
        {
            cout << "ERROR: Invalid State" << '\n';
            cout << "Enter state code (2 characters): ";
            cin >> state;
            isValidState(state);
        }

        cout << "Enter ZIP code: ";
        cin >> zip;
    }

    bool isValidState(string state) {
        
        // Step 1: open .csv file
        ifstream stateFile("states.csv");

        // Step 2: validate if .csv file is open
        if(!stateFile.is_open()) std:cout << "ERROR: File Not Open";

        // Step 3: Validate data
        string stateCSV;

        while (stateFile.good())
        {
            while (getline(stateFile, stateCSV, '\n')) 
            {
                if (state.compare(stateCSV) == 0)
                {
                    stateFile.close();
                    return true;
                } 
            }         
        }
        stateFile.close();
        return false;        
    }
};

int main() {
    Patient patient;
    patient.inputData();

    return 0;
}
