#include <iostream>
using namespace std;

int main() {

    int n;
    float grade[100], credit[100];
    float totalCredits = 0;
    float totalGradePoints = 0;

    cout << " CGPA CALCULATOR " << endl;
    cout << "Enter number of courses: ";
    cin >> n;

    // Check if number of courses is valid
    if(n <= 0) {
        cout << "Invalid number of courses!" << endl;
        return 0;
    }

    // Input section
    for(int i = 0; i < n; i++) {

        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter Grade (e.g., 4.0, 3.5): ";
        cin >> grade[i];

        cout << "Enter Credit Hours: ";
        cin >> credit[i];

        // Validation for credit hours
        if(credit[i] <= 0) {
            cout << "Invalid credit hours! Please enter positive value." << endl;
            return 0;
        }

        totalCredits = totalCredits + credit[i];
        totalGradePoints = totalGradePoints + (grade[i] * credit[i]);
    }

    // Check division safety
    if(totalCredits == 0) {
        cout << "Total credits cannot be zero. CGPA cannot be calculated." << endl;
        return 0;
    }

    float gpa = totalGradePoints / totalCredits;

    // Output Section
    cout << "\n Course Details" << endl;

    for(int i = 0; i < n; i++) {
        cout << "Course " << i + 1
             << " | Grade: " << grade[i]
             << " | Credit: " << credit[i] << endl;
    }

    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Semester GPA: " << gpa << endl;
    cout << "Overall CGPA: " << gpa << endl;

    cout << "\n Calculation Complete " << endl;

    return 0;
}
