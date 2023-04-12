#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
* Student Name: Shashank Mondrati
* Student ID: 801026182
* Class: ITSC-3146
*/
int main(){
    int n=4;
    int my_ints[4]; // array of ints
    int *my_ptrs[4]; // array of pointers
    for(int i=0;i<4;i++){
        cout<<"Please enter your numbers: "<< endl;
        cin>>my_ints[i];
        
    }
    for(int i=0;i<4;i++){
        my_ptrs[i]=&my_ints[i];
    }
    // now to sort the array with pointers
   for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
             if(*(my_ptrs[i]) > *(my_ptrs[j])){
                int *tempV= (my_ptrs[i]);
                (my_ptrs[i])= (my_ptrs[j]);
                (my_ptrs[j])=tempV;
            }
        }
    }
    
    std::cout << "The Sorted Array: " << std::endl;
    for(int i=0;i<n;i++){
        std::cout << (*(my_ptrs[i])) <<" \t";
        
    }
    
    
}