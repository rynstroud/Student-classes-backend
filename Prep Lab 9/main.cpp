//  Created by Ryn Stroud on 11/28/19.
//  Copyright © 2019 Ryn Stroud. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
public:
    Student(string initialName = "No Name") {
        name = initialName;
    }

    virtual void ToStr() {
        cout << name << " is an undergraduate student." << endl;
    }

protected:
    string name;
};

class GradStudent : public Student {
public:
    GradStudent(string initialName = "none", string initialResearchArea = "none") {
        name = initialName;
        researchArea = initialResearchArea;
    }

    virtual void ToStr() {
        cout << name << " is a graduate student researching the area of " << researchArea << "." << endl;
    }

private:
    string researchArea;
};

int main() {
    string usrOption;
    string inpName;
    string inpResearch;
    const string UNDERGRAD_RSCH = "NO";
    Student* newStudent = nullptr;
    vector<Student*> classMembers;

    do {
        cout << "Option: ";
        cin >> usrOption;
       cout << endl;
        if (usrOption == "print") {
            for (int i = 0; i < classMembers.size(); i++) {
                classMembers.at(i)->ToStr();
            }           }
        }

        else if (usrOption == "add") {
            cout << "Name: ";
            cin >> inpName;
            cout << endl;
            cout << "If grad student enter a one word research area, else enter \"NO\": ";
            cin >> inpResearch;
            cout << endl;
            // create new objects for either a Student or a GradStudent
            if (inpResearch == UNDERGRAD_RSCH) {
                newStudent = new Student(inpName);
            }
            else {
                newStudent = new GradStudent(inpName, inpResearch);
            }
                // the pointer to the classMember vector.
            classMembers.push_back(newStudent);

        }
    } while (usrOption != "quit");
    return 0;
}
