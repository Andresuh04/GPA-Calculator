//College GPA Calculator
//Andres Urrutia
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Course {
    string name;
    int creditHours;
    char grade;
};

double gradeToPoint(char grade) {
    switch (grade) {
    case 'A': return 4.0;
    case 'A-': return 3.67;
    case 'B+': return 3.33;
    case 'B': return 3.0;
    case 'B-': return 2.67;
    case 'C+': return 2.33;
    case 'C': return 2.0;
    case 'D': return 1.0;
    case 'F': return 0.0;
    default: return 0.0;
    }
}

double calculateGPA(const vector<Course>& courses) {
    double totalPoints = 0.0;
    int totalCredits = 0;

    for (const auto& course : courses) {
        totalPoints += course.creditHours * gradeToPoint(course.grade);
        totalCredits += course.creditHours;
    }

    return totalCredits ? totalPoints / totalCredits : 0.0;
}

int main() {
    vector<Course> courses;
    int numCourses;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    for (int i = 0; i < numCourses; ++i) {
        Course course;
        cout << "Enter course name: " << endl;
        cin >> course.name;
        cout << "Enter credit hours: " << endl;
        cin >> course.creditHours;
        cout << "Enter grade (A, A-, B+, B, B-, C+, C, D, F): " << endl;
        cin >> course.grade;

        courses.push_back(course);
    }

    double gpa = calculateGPA(courses);
    cout << "Your GPA is: " << gpa << endl;

    return 0;
}
