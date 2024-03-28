#include "CourseList.h"

#include <iostream>


CourseList::CourseList() : head(nullptr) {}

CourseList::~CourseList()

{
    deleteAllNodes();
}

void CourseList::addCourse(const string& courseCode, int creditHours, char grade)

{
    CourseNode* newNode = new CourseNode;

    newNode->courseCode = courseCode;

    newNode->creditHours = creditHours;

    newNode->grade = grade;

    newNode->next = nullptr;

    if (head == nullptr || head->courseCode >= courseCode)

    {
        newNode->next = head;

        head = newNode;
    }

    else 

    {
        CourseNode* current = head;

        while (current->next != nullptr && current->next->courseCode < courseCode)

        {
            current = current->next;
        }

        newNode->next = current->next;

        current->next = newNode;
    }
}

void CourseList::deleteCourse(const string& courseCode)
{
    if (head == nullptr)

        return;

    if (head->courseCode == courseCode)

    {
        CourseNode* temp = head;

        head = head->next;

        delete temp;

        return;
    }

    CourseNode* current = head;

    while (current->next != nullptr && current->next->courseCode != courseCode)

    {
        current = current->next;
    }

    if (current->next == nullptr)

        return;

    CourseNode* temp = current->next;

    current->next = current->next->next;

    delete temp;
}

void CourseList::deleteAllNodes()

{
    CourseNode* current = head;

    while (current != nullptr)

    {
        CourseNode* next = current->next;

        delete current;

        current = next;
    }

    head = nullptr;
}

void CourseList::displayList() const 
{

    if (head == nullptr) 

    {
        cout << "The list is empty." << endl;

        return;
    }

    cout << "Course List:" << endl;

    CourseNode* current = head;

    while (current != nullptr)

    {
        cout << "Course Code: " << current->courseCode << ", Credit Hours: "

            << current->creditHours 

            << ", Grade: " << current->grade << endl;

        current = current->next;
    }
}
