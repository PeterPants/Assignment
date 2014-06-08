#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "functions.h"
using namespace std;

    void sort(int ar[], int size)
    {
        int temp;
        for(int i = 0; i < size; i++)
            for(int j = 0; j < size - i - 1; j++)
                if(ar[j] > ar[j + 1])
                {
                    temp = ar[j];
                    ar[j] = ar[j + 1];
                    ar[j + 1] = temp;
                }
    }






