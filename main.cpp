
#include <iostream>

#include "CourseList.h"


int main()

{

    CourseList courseList;

    int choice;

    string courseCode;

    int creditHours;

    char grade;



    do

    {
        cout << "\nMenu:\n";

        cout << "1. Add Course\n";

        cout << "2. Delete A Course\n";

        cout << "3. Delete All Courses\n";

        cout << "4. Display Course list\n";

        cout << "5. Exit program\n";

        cout << "Pick a number 1-5. ";

        cin >> choice;

        switch (choice)
        {

        case 1:

            cout << "Enter Course Code: ";

            cin >> courseCode;

            cout << "Enter Number of Credit (hours): ";

            cin >> creditHours;

            cout << "What Letter Grade Did You Get?: ";

            cin >> grade;

            courseList.addCourse(courseCode, creditHours, grade);

            cout << "Course added. Good Job!.\n";

            break;

        case 2:

            cout << "Enter course code to delete: ";

            cin >> courseCode;

            courseList.deleteCourse(courseCode);

            cout << "Course deleted successfully.\n";

            break;

        case 3:

            courseList.deleteAllNodes();

            cout << "All courses deleted successfully.\n";

            break;

        case 4:

            cout << "Course List:\n";

            courseList.displayList();

            break;

        case 5:

            cout << "Exiting program.\n";

            break;

        default:

            cout << "Invalid choice. Please try again.\n";

        }

    } 
    
    while (choice != 5);


    return 0;
}

