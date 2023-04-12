//
//  QuickSort_Skeleton.cpp
//
//  Created by Bahamon, Julio on 6/25/19.
//  UNC Charlotte
//  Copyright © 2019 Bahamon, Julio. All rights reserved.
//
/*
    Student Name: Shashank Mondrati
*/

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

        //  Declaring a new struct to store patient data
        struct patient {
        int age;
        char name[20];
        float balance;
        };
//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY AGE

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE AGE OF THE FIRST PATIENT IS LESS
//         THAN THE SECOND PATIENT'S AGE
//       0 IF THE AGES ARE EQUAL
//       1 OTHERWISE

    int compareAge(const void *a, const void *b){ //comparing age
         int l = ((struct patient *)a)->age; // for first age
        int r = ((struct patient *)b)->age; // for next age
        if(l<r){
            return -1;
        }
        else if(l==r) {
            return 0;
        }
        else {
        return 1;
        }
        
    }
//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY BALANCE DUE

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE BALANCE FOR THE FIRST PATIENT IS LESS
//         THAN THE SECOND PATIENT'S BALANCE
//       0 IF THE BALANCES ARE EQUAL
//       1 OTHERWISE

    int compareBalance(const void *av, const void *bv){
       int pat1 = ((struct patient *)av)->balance;
        int pat2 = ((struct patient *)bv)->balance;
        if(pat1<pat2){
            return -1;
        }
        else if(pat1==pat2){ 
            return 0;
        }
        else{ 
            return 1;
        }
    }
//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY NAME

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE NAME OF THE FIRST PATIENT GOES BEFORE
//         THE SECOND PATIENT'S NAME
//       0 IF THE AGES ARE EQUAL
//       1 OTHERWISE
//
//  HINT: USE THE strncmp FUNCTION
//  (SEE http://www.cplusplus.com/reference/cstring/strncmp/)
    void display(struct patient pat[]){
        for(int i=0;i<6;i++){
       cout<<"\tAge: "<<pat[i].age;
       cout.width(20);std::cout << std::left << "";
       cout<<"Name: "<<pat[i].name;
       int w=20-strlen(pat[i].name);
       cout.width(15+w);std::cout << std::left << "";
       cout<< "Balance Due $: "<<pat[i].balance<<endl;
   }
}
    
    int compareName(const void *a,const void *b){
    patient *A = (patient *)a;
    patient *B = (patient *)b;
    return strcmp(A->name,B->name); // accessing the structs
    }
    

    //  The main program
    int main(){
    int total_patients = 6;
    
    //  Storing some test data
    struct patient patient_list[6] = {
        {25, "Juan Valdez   ", 1250},
        {15, "James Morris  ", 2100},
        {32, "Tyra Banks    ", 750},
        {62, "Maria O'Donell", 375},
        {53, "Pablo Picasso ", 615},
        {22,  "Shashank",       826} // added my own name XD
    };
    
    
    cout << "Patient List: " << endl;
  
    // TODO:
    // IMPLEMENT THE CODE TO DISPLAY THE CONTENTS
    // OF THE ARRAY BEFORE SORTING
    display(patient_list); // displaying the patient list
  
    cout << endl;
  
    qsort (patient_list, 6, sizeof(patient), compareAge); //qsort
    cout << "Sorting..." << endl;
  
    // TODO:
    // CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT AGE
  
    cout << "Patient List - Sorted by Age: " << endl;
    display(patient_list);
    // TODO:
    // DISPLAY THE CONTENTS OF THE ARRAY
    // AFTER SORTING BY AGE
  
    cout << endl;
  
  
    cout << "Sorting..." << endl;
  
    // TODO:
    // CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT BALANCE
    qsort (patient_list, 6, sizeof(patient), compareBalance);
    cout << "Patient List - Sorted by Balance Due: " << endl;
    display(patient_list);
    // TODO:
    // DISPLAY THE CONTENTS OF THE ARRAY
    // AFTER SORTING BY BALANCE
  
    cout << endl;
  
  
    cout << "Sorting..." << endl;
  
    // TODO:
    // CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT NAME
    qsort (patient_list, 6, sizeof(patient), compareName);
    cout << "Patient List - Sorted by Name: " << endl;
    display(patient_list);
    // TODO:
    // DISPLAY THE CONTENTS OF THE ARRAY
    // AFTER SORTING BY NAME
  
    cout << endl;
  
    return 0;
}
