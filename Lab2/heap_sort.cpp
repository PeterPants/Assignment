
#include <iostream>
#include <stdlib.h>
#include "functions.h"
using namespace std;

void heapsort(int array[], int size);
void buildheap(int array[], int size);
void percolateDown(int heap[], int size, int id);


void heapsort(int array[], int size) {
	buildheap(array, size);
	int heapsize = size;

	for(int i=size-1; i>0; i--) {
		int temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		heapsize--;
		percolateDown(array, heapsize, 0);
	}
}

void buildheap(int array[], int size) {
	for(int i=size/2; i>=0; i--) {

		percolateDown(array, size, i);
	}
}

void percolateDown(int array[], int size, int id) {
	int current = id;
	int max;
	while(true) {
		int left = current*2+1;
		int right = current*2+2;
		if(left >= size)
			return;
		else if(right >= size)
			max = left;
		else if(array[left] > array[right])
			max = left;
		else if(array[left] < array[right])
			max = right;
		if(array[max] > array[current]) {
			int temp = array[max];
			array[max] = array[current];
			array[current] = temp;
			current = max;
		} else
			return;
	}
}
