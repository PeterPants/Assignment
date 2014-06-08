#include <iostream>
#include <fstream>
using namespace std;

int number_of_lines = 0;

void numberoflines();
int main(){
    string line;
    ifstream myfile("he.txt");

    if(myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile,line);
           // cout<< line << endl;
            number_of_lines++;
        }
        myfile.close();
    }
    numberoflines();

}

void numberoflines(){
    number_of_lines--;
    cout<<"number of lines in text file: " << number_of_lines << endl;
}
