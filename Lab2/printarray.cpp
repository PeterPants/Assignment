#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "functions.h"
using namespace std;
void printArray(int array[], int size) {
	int v=10;
	for(int i=0; i<size; i++) {
		if(i==v and v<size){cout<<"\n";v=v+10;}
		cout << array[i] << " ";
	}
	cout << endl;
}
