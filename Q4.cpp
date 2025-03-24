#include <iostream>
#include <vector>
using namespace std;

class Person {
protected:
    string name, id, address, phoneNumber, email;

public:
    Person(string n, string i, string addr, string phone, string mail)
        : name(n), id(i), address(addr), phoneNumber(phone), email(mail) {}

    virtual ~Person() {}

    virtual void displayInfo() const {
        cout << "Name: " << name << "\nID: " << id << "\nAddress: " << address
             << "\nPhone: " << phoneNumber << "\nEmail: " << email << endl;
    }

    virtual void updateInfo(string newAddress, string newPhone, string newEmail) {
        address = newAddress;
        phoneNumber = newPhone;
        email = newEmail;
    }
};

class Student : public Person {
private:
    vector<string> coursesEnrolled;
    double GPA;
    int enrollmentYear;

public:
    Student(string n, string i, string addr, string phone, string mail, double gpa, int year)
        : Person(n, i, addr, phone, mail), GPA(gpa), enrollmentYear(year) {}

    void enrollCourse(string course) {
        coursesEnrolled.push_back(course);
    }

    void displayInfo() const override {
        cout << "--- Student Info ---\n";
        Person::displayInfo();
        cout << "GPA: " << GPA << "\nEnrollment Year: " << enrollmentYear << "\nCourses Enrolled: ";
        for (const auto& course : coursesEnrolled) {
            cout << course << " ";
        }
        cout << endl;
    }
};

class Professor : public Person {
private:
    string department;
    vector<string> coursesTaught;
    double salary;

public:
    Professor(string n, string i, string addr, string phone, string mail, string dept, double sal)
        : Person(n, i, addr, phone, mail), department(dept), salary(sal) {}

    void assignCourse(string course) {
        coursesTaught.push_back(course);
    }

    void displayInfo() const override {
        cout << "--- Professor Info ---\n";
        Person::displayInfo();
        cout << "Department: " << department << "\nSalary: $" << salary << "\nCourses Taught: ";
        for (const auto& course : coursesTaught) {
            cout << course << " ";
        }
        cout << endl;
    }
};

class Staff : public Person {
private:
    string department, position;
    double salary;

public:
    Staff(string n, string i, string addr, string phone, string mail, string dept, string pos, double sal)
        : Person(n, i, addr, phone, mail), department(dept), position(pos), salary(sal) {}

    void displayInfo() const override {
        cout << "--- Staff Info ---\n";
        Person::displayInfo();
        cout << "Department: " << department << "\nPosition: " << position << "\nSalary: $" << salary << endl;
    }
};

class Course {
private:
    string courseId, courseName, instructor, schedule;
    int credits;
    vector<Student*> enrolledStudents;

public:
    Course(string id, string name, int cred, string instr, string sched)
        : courseId(id), courseName(name), credits(cred), instructor(instr), schedule(sched) {}

    void registerStudent(Student* student) {
        enrolledStudents.push_back(student);
    }

    void calculateGrades() {
        cout << "Calculating grades for " << courseName << endl;
    }

    void displayCourseInfo() const {
        cout << "--- Course Info ---\n";
        cout << "Course ID: " << courseId << "\nName: " << courseName << "\nCredits: " << credits
             << "\nInstructor: " << instructor << "\nSchedule: " << schedule << "\nStudents Enrolled: " << enrolledStudents.size() << endl;
    }
};

int main() {
    Student s1("Alice", "S101", "123 Street", "555-1234", "alice@mail.com", 3.8, 2022);
    Professor p1("Dr. Smith", "P202", "456 Avenue", "555-5678", "smith@mail.com", "Computer Science", 75000);
    Staff st1("Bob", "ST303", "789 Road", "555-9101", "bob@mail.com", "HR", "Manager", 50000);
    Course c1("CS101", "Intro to Programming", 4, "Dr. Smith", "Mon-Wed 10:00 AM");

    s1.enrollCourse("CS101");
    p1.assignCourse("CS101");
    c1.registerStudent(&s1);

    cout << "\n--- Display Information ---\n";
    s1.displayInfo();
    cout << endl;
    p1.displayInfo();
    cout << endl;
    st1.displayInfo();
    cout << endl;
    c1.displayCourseInfo();

    return 0;
}
