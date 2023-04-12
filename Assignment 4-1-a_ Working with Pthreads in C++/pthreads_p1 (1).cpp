/*
@author: Shashank 
@author Aaron
@author: Daniel
@author: Eli
@author: Hima
*/
#include <iostream>
#include <pthread.h>
#define THREAD_COUNT 4
using namespace std;
const char *my_messages[4] = {"English: Hello!",
                              "French: Bonjor!",
                              "Spanish: Hola!",
                              "German: Guten Tag!"

};
void *printMessage (void *arg)
{
    // TODO: Add code that implements
    //       the thread's functionality
    int *ind = (int *)arg;
    cout << my_messages[*ind] << endl;
    return 0;
}
int main()
{
    pthread_t id[THREAD_COUNT];
    int rc, i;
    int loc[] = {0, 1, 2, 3};
    for (int i = 0; i < THREAD_COUNT; i++)
    {
        rc = pthread_create(&id[i], NULL, printMessage, &loc[i]);
        if (rc)
        {
            cout << "Error return code from pthread_create() is" << rc << endl;
        }
    }
    pthread_exit(0);
}