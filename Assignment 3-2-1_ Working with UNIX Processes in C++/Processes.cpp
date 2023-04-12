//
//  Processes.cpp
//  ITSC 3146
//
//  Created by Bahamon, Julio on 1/12/17.
//

/*
 @file Processes.cpp
 @author Shashank, smondrat@uncc.edu
 @description: <Processess.cpp>
 @course: ITSC 3146
 @assignment: in-class activity [n]
 */

#ifndef Processes_cpp
#define Processes_cpp

#include "Processes.h"

using namespace std;

// Part 1: Working With Process IDs
   pid_t getProcessID(void) // getting processID
{
    // TODO: Add your code here
    pid_t id = getpid(); // new PID to get PID
    return id; // returning PID
}

// Part 2: Working With Multiple Processes
string createNewProcess(void)
{
    //process_id is not declared, declaring it, 
    int process_id;
    //Creating a child process
    pid_t id = fork();
    // DO NOT CHANGE THIS LINE OF CODE
    process_id = id;
    //If the id is -1
    if (id == -1){
        return "Error creating process";
    }
    else if (id == 0){
        cout << "I am a child process! ";
        return "I am bored of my parent, switching programs now";
    }
    //Otherwise
    else{
        cout << "I just became a parent! ";
        int status = 0;
        wait(&status);
        return "My child process just terminated!";
    }
}

// Part 3: Working With External Commands"
   void replaceProcess(char *args[]){
    // craeting a process frmo user
    pid_t id = fork(); // a fork
    //Execute with the new process
    execvp(args[0], args);
}

#endif /* TestProg_cpp */
   int main(){
    cout << "Part1: Working with process IDS\n";
    cout << "Process ID: " << getProcessID() << endl; //method call back
    cout << "Part2: Working with multiple processes\n";
    //Part-II Method call back 
    cout << createNewProcess() << endl;
    //Part-III Call to funtion replace process
    char *args[3] = {(char *)"ls", (char *)"-l", NULL};
    cout << "Part3: Working with external commands\n";
    replaceProcess(args);
    return 0;
}
