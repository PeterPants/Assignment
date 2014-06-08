#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int compare(const void *elem1,const void *elem2){
return *(int*)elem1-*(int*)elem2;
}

void printArray(int array[], int size) {
	int v=10;
	for(int i=0; i<size; i++) {
		if(i==v and v<size){cout<<"\n";v=v+10;}
		cout << array[i] << " ";
	}
	cout << endl;
}

void printArray_back(int array[], int size) {
	int v=10;
	for(int i=size-15; i<size; i++) {
		if(i==v and v<size){cout<<"\n";v=v+10;}
		cout << array[i] << " ";
	}
	cout << endl;
}



int main() {
 int arr [32]={};
 int size=32;
 string STRING;
 string com = ",";
 string token;
 ifstream myReadFile;
 myReadFile.open("names.txt");
 int i=0;
 if (myReadFile.is_open()) {
 while (!myReadFile.eof()) {
	        getline(myReadFile,STRING); // Saves the line in STRING.
		size_t position= STRING.find(com);
		token=STRING.substr(0,position);	        
		//cout<<token<<"\n"; // Prints our STRING.
		int numb;
		istringstream ( token ) >> numb;
		arr[i]=numb;
		i++;
		

 }

 int y=sizeof(arr)/sizeof(*arr);
 cout << "unsorted array is then"<< endl;
 printArray(arr, size);
 cout << "sorted array is then"<< endl;
 qsort(arr,size,sizeof(int),compare);
 printArray(arr, size);
 cout<<"getting the last 15 elements"<< endl;
 printArray_back(arr,size);

}

myReadFile.close();
return 0;
}


