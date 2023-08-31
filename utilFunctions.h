//
// Created by Blu-ray on 8/12/2023.
//
/*********************************************************************************************
 * @file    :   utilFunctions.h
 * @brief   :   This header file defines utility functions used in the Minions Task Manager.
                It includes the necessary headers and declares the functions and operator overloads.
*********************************************************************************************/

#ifndef INC_1_3_UTIL_FUNCTIONS_H
#define INC_1_3_UTIL_FUNCTIONS_H

#include "Task.h"

// Operator overloads
std::istream &operator>>(std::istream &, char *(&));
std::ostream &operator<<(std::ostream &, const std::vector <Task> &);

// Utility functions
Task getTask ();
long long int binSearch(const std::vector <Task> &tasksList, long long int startTask, long long int endTask, unsigned int value);
bool inquireAddTask(std::vector <Task> &);
bool inquireRemoveTask(std::vector <Task> &);
bool inquireToggling(std::vector <Task> &tasksList);

#endif //INC_1_3_UTIL_FUNCTIONS_H
