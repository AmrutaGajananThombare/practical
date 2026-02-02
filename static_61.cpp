#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    static int totalStudents;   
    int rollno;                 
    string name;                
public:
    
    Student(int r = 0, string n = "") : rollno(r), name(n) {
        totalStudents++;
    }

    static int getTotalStudents() {
        return totalStudents;
    }

    void setRollNo(int r) {
        rollno = r;
    }

    int getRollNo() const {
        return rollno;
    }

    void setName(const string& n) {
        name = n;
    }

    string getName() const {
        return name;
    }
};

int Student::totalStudents = 0;

int main() {
    Student s1;
    s1.setRollNo(101);
    s1.setName(" A1 ");

    Student s2;
    s2.setRollNo(102);
    s2.setName(" A2 ");

    Student s3(103, " A3");  

    cout << "Student 1: Roll No = " << s1.getRollNo() << ", Name = " << s1.getName() << endl;
    cout << "Student 2: Roll No = " << s2.getRollNo() << ", Name = " << s2.getName() << endl;
    cout << "Student 3: Roll No = " << s3.getRollNo() << ", Name = " << s3.getName() << endl;

    cout << "Total number of students: " << Student::getTotalStudents() << endl;

    return 0;
}

