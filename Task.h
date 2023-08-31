//
// Created by Blu-ray on 8/12/2023.
//
/*********************************************************************************************
 * @file    :    Task.h
 * @brief   :    This header file defines the Task class, which represents a single task in the Minions Task Manager.
                 It includes the necessary headers and declares the class and its member functions and variables.
*********************************************************************************************/

#ifndef INC_1_3_TASK_H
#define INC_1_3_TASK_H

#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>

class Task
{
    // Class Friends
    friend bool inquireAddTask(std::vector <Task> &tasksList);
    friend long long int binSearch(const std::vector <Task> &tasksList, long long int startTask, long long int endTask, unsigned int value);
    friend std::ostream &operator<<(std::ostream &, const Task &);

    // Default values for class objects if no values provided
    static constexpr const char *defaultDescription = nullptr;
    static constexpr const unsigned int defaultIndex = 0;
    static constexpr const bool defaultCompleted = false;
private:
    char *description; // C-Style string for task description
    unsigned int index;
    bool completed;
public:
    // Operator Overloading
    Task &operator=(const Task &rhs);
    Task &operator=(Task &&rhs)noexcept;

    // Class Methods
    void toggleCompletion();

    // Class Constructors and Destructor
    explicit Task(const char *descriptionVal = defaultDescription, unsigned int indexVal = defaultIndex, bool completedVal = defaultCompleted);
    Task(const Task &obj);
    Task(Task &&obj)noexcept;
    ~Task();
};


#endif //INC_1_3_TASK_H
