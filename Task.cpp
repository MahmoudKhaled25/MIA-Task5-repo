//
// Created by Blu-ray on 8/12/2023.
//
/*********************************************************************************************
 * @file    :   Task.cpp
 * @brief   :   This file contains the implementations of the member functions of the Task class declared in the Task.h file.
                It includes the necessary headers and defines the functions.
*********************************************************************************************/
#include "Task.h"

// Function: operator=
// Description: Assignment operator overload to copy the contents of one task to another.
Task &Task::operator=(const Task &rhs)
{
    if (this == &rhs)
        return *this;

    delete [] description;

    description = new char[strlen(rhs.description)+1];
    strcpy(description, rhs.description);

    index = rhs.index;
    completed = rhs.completed;

    return *this;
}

// Function: operator=
// Description: Move assignment operator overload to move the contents of one task to another.
Task &Task::operator=(Task &&rhs)noexcept
{
    if (this == &rhs)
        return *this;

    delete [] description;
    description = rhs.description;

    rhs.description = nullptr;

    index = rhs.index;
    completed = rhs.completed;

    return *this;
}

// Function: operator<<
// Description: Overloaded insertion operator to print the task details in a formatted manner.
std::ostream &operator<<(std::ostream &os, const Task &obj)
{
    os << std::left << std::setw(8) << obj.index;

    if (obj.completed)
    {
        os << std::setw(15) << "Completed";
    }
    else
    {
        os << std::setw(15) << "Incomplete";
    }
    os << std::setw(50) << obj.description << std::endl;


    return os;
}

// Function: Task (constructor)
// Description: Parameterized constructor to initialize the Task object with provided values.
Task::Task(const char *descriptionVal, const unsigned int indexVal, const bool completedVal)
        : index{indexVal}, completed{completedVal}
{
    if (nullptr != descriptionVal)
    {
        description = new char [strlen(descriptionVal)];
        strcpy(description, descriptionVal);
    }
    else
    {
        description = new char ;
        *description = '\0';
    }

}

// Function: Task (copy constructor)
// Description: Copy constructor to create a new Task object by copying the contents of another Task object.
Task::Task(const Task &obj)
        : Task{obj.description, obj.index, obj.completed}
{}

// Function: Task (move constructor)
// Description: Move constructor to create a new Task object by moving the contents of another Task object.
Task::Task(Task &&obj)noexcept
        : index{obj.index}, completed{obj.completed}
{
    description = obj.description;
    obj.description = nullptr;
}

// Function: ~Task (destructor)
// Description: Destructor to clean up the dynamically allocated memory for the description.
Task::~Task()
{
    delete [] description;
}

// Function: toggleCompletion
// Description: Toggles the completion state of the task (completed/incomplete).
void Task::toggleCompletion()
{
    completed = !completed;
}