/*
@author Shashank
*/
#include <thread>
#include <iostream>
//declare SIZE of an array
#define SIZE 10

using namespace std;

//declaring an array of 10
int arr[SIZE];

void *countNegatives(void *arg) // counting the negatives
{
    int count = 0; // starting from 0
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] < 0) // if its less than 0 its neg
            count++; // increasing the count by 1 for every neg#
    }
    cout << "Total negative numbers: " << count << endl;
}
void *average(void *arg) // counting the average
{
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        sum += arr[i];
    }
    cout << "Average: " << sum / 10.0 << endl; // averge = sum of total numbers / total digits XDx
}
void *reverse(void *arg) // reversing the array by post decrementing the for loop
{
    cout << "Numbers Reversed: " << endl;
    for (int i = SIZE - 1; i >= 0; i--)
    {
        cout << arr[i] << endl; // reversing the numbers
    }
}

int main()

{

    pthread_t threads[3];
    //taking input from user upto any kind of integers
    cout << "Enter Ten Integers of Any Type: \n";
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i]; // user input 10 digits in an singular dimensional array 1D
    }
    //creating thread for counting neg #'s' in an array
    int ret = pthread_create(&threads[0], NULL, countNegatives, (void *)0); // creating a pthread for counting negatives

    if (ret)
    {
        cout << "Error:Unable to create a NewProcess," << ret << endl; // if cant should display a messsage
    }
    void *stat;
    pthread_join(threads[0], &stat);
    //creating a thread for calculating average
    ret = pthread_create(&threads[1], NULL, average, (void *)1);

    if (ret)
    {
        cout << "Error:Unable to create a NewProcess," << ret << endl;
    }
    pthread_join(threads[1], &stat);

    ret = pthread_create(&threads[2], NULL, reverse, (void *)2);

    if (ret)
    {
        cout << "Error:Unable to create a NewProcess," << ret << endl;
    }

    pthread_join(threads[2], &stat);
}