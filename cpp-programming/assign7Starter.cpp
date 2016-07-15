#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Define a Person class, including age, gender, and yearlyIncome.
class Person {
    public:
        Person();
        void Print();
        void SetData(int a); // FIXME Also set gender and yearly income
        int GetAge();
    private:
        int age;
        string gender;
        int yearlyIncome;
};

// Constructor for the Person class.
Person::Person() {
    age = 0;
    gender = "default";
    yearlyIncome = 0;
    return;
}

// Print the Person class.
void Person::Print() {
    cout << "Age = " << this->age
         << ", gender = " << this->gender
         << ", yearly income = " << this->yearlyIncome
         << endl;
    return;
}

// Set the age, gender, and yearlyIncome of a Person.
void Person::SetData(int a) {   // FIXME Also set gender and yearly income
    this->age = a;
    return;
}

// Get the age of a Person.
int Person::GetAge() {
    return this->age;
}

// Get a filename from program arguments, then make a Person for each line in the file.
bool ReadPeopleFromFile(int argc, char* argv[], vector<Person> &people) {
    Person tmpPrsn;
    ifstream inFS;
    int tmpAge = 0;
    string tmpGender = "";
    int tmpYI = 0;
    
    if (argc != 2) {
        cout << "\nUsage: [EXECUTABLE FILE] [TEXT DATA FILE], e.g. myprog.exe dev_people.txt" << endl;
        return true; // indicates error
    }
    
    cout << "Opening file " << argv[1] << ".\n";
    inFS.open(argv[1]); // Try to open file
    if (!inFS.is_open()) {
        cout << "Could not open file " << argv[1] << ".\n";
        return true; // indicates error
    }
    
    while (!inFS.eof()) {
        inFS >> tmpAge;
        inFS >> tmpGender;
        inFS >> tmpYI;
        tmpPrsn.SetData(tmpAge); // FIXME Also set gender and yearly income
        tmpPrsn.Print();
        people.push_back(tmpPrsn);
    }
    inFS.close();
    cout << "Finished reading file." << endl;
    
    return false; // indicates no error
}

// Ask user to enter age range.
void GetUserInput(int &ageLowerRange, int&ageUpperRange) {
    cout<<"\nEnter lower range of age: ";
    cin >> ageLowerRange;
    
    cout << "Enter upper range of age: ";
    cin >> ageUpperRange;
    
    return;
}

// Return people within the given age range.
vector<Person> GetPeopleInAgeRange(vector<Person> ppl, int lowerRange, int upperRange) {
    unsigned int i = 0;
    
    vector<Person> pplInAgeRange;
    int age = 0;
    for (i = 0; i < ppl.size(); ++i) {
        age = ppl.at(i).GetAge();
        if ((age >= lowerRange) && (age <= upperRange)) {
            pplInAgeRange.push_back(ppl.at(i));
        }
    }
    
    return pplInAgeRange;
}

int main(int argc, char* argv[]) {
    vector<Person> ptntlCstmrs;
    bool hadError = false;
    int ageLowerRange = 0;
    int ageUpperRange = 0;
    
    hadError = ReadPeopleFromFile(argc, argv, ptntlCstmrs);
    if( hadError ) {
        return 1; // indicates error
    }
    
    GetUserInput(ageLowerRange, ageUpperRange);
    ptntlCstmrs = GetPeopleInAgeRange(ptntlCstmrs, ageLowerRange, ageUpperRange);
    
    // FIXME Add the function GetPeopleWithSpecificGender
    //FIXME Addthefunction GetPeopleInIncomeRange
    
    cout << "\nNumber of potential customers = "<<ptntlCstmrs.size() << endl;
    
    return 0;
}
