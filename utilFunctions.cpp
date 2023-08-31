//
// Created by Blu-ray on 8/12/2023.
//
/*********************************************************************************************
 * @file    :   utilFunctions.cpp
 * @brief   :   This file contains the implementations of the utility functions declared in the utilFunctions.h file.
                It includes the necessary headers and defines the functions and operator overloads.
*********************************************************************************************/


#include "utilFunctions.h"

#define CALC_PENULTIMATE_INDEX(SIZE) ((SIZE) - 2)
#define INITIAL_INDEX 1
#define INDEX_INCREMENT_UNIT 1
#define NOT_FOUND (-1)

// Function: operator>>
// Description: Overloaded extraction operator to read a line of characters into a char pointer (Take a c-style string from the dynamically).
std::istream &operator>>(std::istream &is, char *(&str))
{
    char *buff;

    buff = new char [1000];
    is.getline(buff, 1000);

    str = new char [strlen(buff) + 1];
    strcpy(str, buff);

    delete [] buff;

    return is;
}

// Function: operator<<
// Description: Overloaded insertion operator to print the vector of tasks.
std::ostream &operator<<(std::ostream &os, const std::vector <Task> &tasksList)
{
    if (!tasksList.empty())
    {
        os << std::left << std::setw(8) << "Index"
           << std::setw(15) << "State"
           << std::setw(50) << "Description" << std::endl;

        os << std::setfill('-') << std::setw(38) << "" << std::setfill(' ') << std::endl;

        for (const auto &obj: tasksList) {
            os << obj;
        }

    }
    else
    {
        os << "Tasks list is empty !" << std::endl;
    }

    return os;
}

// Function: getTask
// Description: Prompt the user to enter a task description and create a Task object.
Task getTask ()
{
    char *description = nullptr;

    std::cout << "Enter task description: ";
    std::cin >> description;

    Task retTask {description};

    delete [] description;

    return retTask;
}

// Function: binSearch
// Description: Search for the task index in the tasks vector using binary search.
long long int binSearch(const std::vector <Task> &tasksList, long long int startTask, long long int endTask, unsigned int value)
{
    long long middle;

    if (!tasksList.empty())
    {
        while (startTask <= endTask)
        {
            middle = (int)(startTask + (endTask - startTask) / 2);

            if (tasksList.at(middle).index == value)
                return middle;

            if (tasksList.at(middle).index > value)
                endTask = middle - 1;
            else if (tasksList.at(middle).index < value)
                startTask = middle + 1;
        }
    }

    return NOT_FOUND;
}

// Function: inquireAddTask
// Description: Returns true if success to add the task to tasks list with unique address and returns false if not.
bool inquireAddTask(std::vector <Task> &tasksList)
{
    bool retVal;

    if (!tasksList.empty())
    {
        tasksList.push_back(std::move(getTask()));
        tasksList.back().index = tasksList.at(CALC_PENULTIMATE_INDEX(tasksList.size())).index + INDEX_INCREMENT_UNIT;
        if (tasksList.back().index >= tasksList.at(CALC_PENULTIMATE_INDEX(tasksList.size())).index)
        {
            retVal = true;
        }
        else
        {
            retVal = false;
            tasksList.pop_back();
        }
    }
    else
    {
        tasksList.push_back(std::move(getTask()));
        tasksList.at(0).index = INITIAL_INDEX;
        retVal = true;
    }

    return retVal;
}

// Function: inquireRemoveTask
// Description: Prompt the user to enter a task ID for removal and remove the task from the vector.
bool inquireRemoveTask(std::vector <Task> &tasksList)
{
    unsigned int removedId;
    long long removedIdIndex;
    bool retVal;

    std::cout << "Enter task ID to remove: ";
    std::cin >> removedId;

    removedIdIndex = binSearch(tasksList, 0, static_cast<long long>(tasksList.size() - 1), removedId);

    if (NOT_FOUND != removedIdIndex)
    {
        tasksList.erase(tasksList.begin() + removedIdIndex);
        retVal = true;
    }
    else
    {
        retVal = false;
    }

    return retVal;
}

// Function: inquireToggling
// Description: Prompt the user to enter a task ID to change its state (completed/incomplete).
bool inquireToggling(std::vector <Task> &tasksList)
{
    unsigned int changedId;
    long long changedIdIndex;
    bool retVal;

    std::cout << "Enter task ID to change its state: ";
    std::cin >> changedId;

    changedIdIndex = binSearch(tasksList, 0, static_cast<long long>(tasksList.size() - 1), changedId);
    if (NOT_FOUND != changedIdIndex)
    {
        tasksList.at(changedIdIndex).toggleCompletion();
        retVal = true;
    }
    else
    {
        retVal = false;
    }
    return retVal;
}
