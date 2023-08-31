/********************************************************************************************
 * @author  :   Mahmoud Khaled
 * @date    :   8/12/2023
 * @details :   Minions Task Manager. This project implements a task management system called "Minions Task Manager".
                It allows users to add tasks, view tasks, remove tasks, and change the state of tasks (completed/incomplete).
                The tasks are stored in a vector and various utility functions are provided to perform these operations.
 **********************************************************************************************

*********************************************************************************************
 * @file    :   main.cpp
 * @brief   :   This file contains the main function of the Minions Task Manager program.
                It includes the necessary headers and defines the main menu and functions for adding, removing, and toggling task completion.
*********************************************************************************************/
#include <iostream>
#include <vector>
#include <windows.h>

#include "Task.h"
#include "utilFunctions.h"
/*********************************************************************************************/
using namespace std;

enum availableSelections{ADD_TASK = 1, VIEW_TASKS, REMOVE_TASK, TOGGLE_STATE, EXIT};

vector<Task>tasksList;

void addTask ();
void removeTask ();
void toggleTaskCompletion();
void printSelectionList();
/*********************************************************************************************/
int main()
{
    unsigned short selection;

    printSelectionList();
    do
    {
        cout << "\nSelect an option: ";
        cin >> selection;
        cout << "\n";
        getchar();

        switch (selection)
        {
            case ADD_TASK:
                addTask();
                break;
            case VIEW_TASKS:
                cout << tasksList;
                break;
            case REMOVE_TASK:
                removeTask();
                break;
            case TOGGLE_STATE:
                toggleTaskCompletion();
                break;
            case EXIT:
                cout << "Exiting Minions Task Manager. Have a great day!" << endl;
                break;
            default:
                cout << "Invalid Selection. Program exit ";
                for (int i = 0; i < 5; ++i)
                {
                    cout << ".";
                    Sleep(200);
                }
                selection = EXIT;
        }

    } while (EXIT != selection);

    return 0;
}
/*********************************************************************************************/
void addTask ()
{
    if (inquireAddTask(tasksList))
    {
        cout << "Task added successfully!" << endl;
    }
    else
    {
        cout << "Failed to add the task!" << endl;
    }
}
/*********************************************************************************************/
void removeTask ()
{
    if(inquireRemoveTask(tasksList))
    {
        cout << "Task removed successfully!" << endl;
    }
    else
    {
        cout << "Task not founded!" << endl;
    }
}
/*********************************************************************************************/
void toggleTaskCompletion()
{
    if (inquireToggling(tasksList))
    {
        std::cout << "Task state changed successfully!" << std::endl;
    }
    else
    {
        cout << "Task not founded!" << endl;
    }
}
/*********************************************************************************************/
void printSelectionList()
{
    cout <<
         "Minions Task Manager\n" <<
         "1. Add Task\n" <<
         "2. View Tasks\n" <<
         "3. Remove Task\n" <<
         "4. Change task state\n" <<
         "5. Exit" << endl;
}
/*********************************************************************************************/
