
//PART ONE CODE

/*#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <algorithm>

#include <time.h>
#include "functions.h"
using namespace std;
int compare(const void *elem1,const void *elem2){
return *(int*)elem1-*(int*)elem2;
}
int main() {
	cout << "Please enter the size of the array" <<endl;
	int size;
	cin >> size;
	int arrayToSort[size];
	for(int i=0; i<size; i++){
		arrayToSort[i] = 1+rand()%65536;
	}

	cout <<"\nThe unsorted array is\n"<< endl;
	printArray(arrayToSort, size);

	cout <<"\n";
	cout <<"\nThe sorted array using the HeapSort then becomes.. \n"<< endl;
	clock_t tStart= clock();
	heapsort(arrayToSort, size);
	printArray(arrayToSort, size);
	cout <<"Time taken in seconds: " <<(float)(clock()-tStart)/CLOCKS_PER_SEC <<"\n"<< endl;
	random_shuffle(&arrayToSort[0], &arrayToSort[size]);
	cout << "\nShuffle before Bubble sort: \n "<<endl;
	printArray(arrayToSort, size);
        sort(arrayToSort, size);
        cout << "\nAfter Bubble sorting: \n"<<endl;
	printArray(arrayToSort, size);
	random_shuffle(&arrayToSort[0], &arrayToSort[size]);
	cout << "\nBefore Doing Quick sort: \n "<<endl;
	printArray(arrayToSort, size);
	cout << "\nAfter QUICK sorting: \n"<<endl;
	qsort(arrayToSort,size,sizeof(int),compare);
	printArray(arrayToSort, size);

}
*/
//PART TWO OF QUESTION

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <algorithm>

#include <time.h>
#include "functions.h"
using namespace std;
int compare(const void *elem1,const void *elem2){
return *(int*)elem1-*(int*)elem2;
}
int main() {
  //  clock_t entireProgramTime = clock();
	cout << "Please enter the size of the array" <<endl;
	int size;
	cin >> size;
	int arrayToSort[size];
	for(int i=0; i<size; i++){
		arrayToSort[i] = 1+rand()%65536;
	}


	cout <<"\n";

	clock_t heapSortTime= clock();
	heapsort(arrayToSort, size);
	cout <<"Time taken by heapSort() in seconds: " <<(float)(clock()-heapSortTime)/CLOCKS_PER_SEC <<"\n"<< endl;
	random_shuffle(&arrayToSort[0], &arrayToSort[size]);


	clock_t bubbleSortTime = clock();
        sort(arrayToSort, size);
        cout <<"Time taken by bubbleSort() in seconds: " <<(float)(clock()-bubbleSortTime)/CLOCKS_PER_SEC <<"\n"<< endl;


	clock_t qSortTime = clock();

	qsort(arrayToSort,size,sizeof(int),compare);

	cout <<"Time taken by quickSort() in seconds: " <<(float)(clock()-qSortTime )/CLOCKS_PER_SEC <<"\n"<< endl;

}
