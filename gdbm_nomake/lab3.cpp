#include <iostream>
#include <sstream>
#include <map>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include <gdbm.h>


using namespace std;
ofstream log;
GDBM_FILE dbf;
vector<string>outtest;
vector <vector<string> >wholefile;
vector <string> row;
map<int,string>mapme;
vector <string> newsome;
vector <datum> keys;
vector <datum> values;



//The compiling command
//using the makefile to build use the command 'make' this will build the file
//after the build is complete it creates a executable named hello, to run the program type './hello'
// enjoy the program
//if you choose not to use the make file u can type the following commands
// g++ -I/opt/gdbm-1.8.3/include lab3.cpp -o lab3 -lgdbm
//./lab3


char* toChar(string keystring){
	char * writable = new char[keystring.size() + 1];
	std::copy(keystring.begin(), keystring.end(), writable);
	writable[keystring.size()] = '\0'; 
	return writable;
}
vector <string> split(char del,string line,vector<string>ele){   // reading the file
	stringstream ss(line);
	string item;
	while(getline(ss,item,del)){
		ele.push_back(item);
	}
	return ele; 
}


void readinpFile(ifstream &file){ 
	string line;		
	if(file.is_open()){
		while(getline(file,line)){
			row = split(',',line,row);
			string vall= row.at(0);
			if(row.at(0).size() != 6 ){

				cout << "The following student number: " << row.at(0)<<","<< row.at(1) << "has an invalid length check 'logfile.txt' for more info" << endl;
				log << "The following student : " << row.at(0)<<","<< row.at(1) << "has an invalid student number length" << endl;
			}
			for(int ju = 0;ju < newsome.size();ju++){
				if(newsome.at(ju).compare(vall) == 0){
					cout << "There is a duplicate of this student number: "<<vall<<" check 'logfile.txt' for more info"<<endl;		
					log <<"The student number : "<<vall <<" already exist"<<endl;				
				}
			}
			newsome.push_back(row.at(0));
			wholefile.push_back(row);
			row.clear();
		}
	}else{
		cout << "There is Something wrong with the input file, make sure its closed" <<endl;
	}

}


//writes the input file to gdbm
void writeFileinpToGdbm(){			
	dbf = gdbm_open ("tester", 0, GDBM_NEWDB, 0644, 0);	
	for(int hj = 0;hj < wholefile.size();hj++){
		string keystring = wholefile.at(hj).at(0);
		string valstring = wholefile.at(hj).at(1);
		char *keyz = toChar(keystring);
		char *valuez = toChar(valstring);				
		datum key = {keyz, 10};
		datum value = {valuez, 20};
		gdbm_store(dbf,key,value,-1);
	}
}


//prints our first and last fifteen items
void printOutputFifteen(string flag,ofstream &myfile){

	if(flag.compare("ASC") == 0){
	std::map<int,string>::iterator it;
	cout <<"   \nAscending order \n"<< endl;
	int coutn = 0;
	for (it=mapme.begin(); it!=mapme.end(); ++it){
		myfile << it->first << ","<<it->second << endl;
		if(coutn == 0){cout<<"\nFirst 15 students:\n"<<endl;}
		if(coutn == mapme.size() - 15){cout<<"\nLast 15 students:\n"<<endl;}
		if(coutn < 15){
			cout<< it->first <<","<<it->second<<endl;
		}
		if(coutn > mapme.size() - 15){
			cout<< it->first <<","<< it->second <<endl;
		}
		coutn++;
	}
return;
	}
	if(flag.compare("DESC") == 0 ){
	std::map<int,string>::reverse_iterator itr;
	cout << "   \nDescending order \n" << endl;
	int rcoutn = 0;
	for (itr = mapme.rbegin(); itr!=mapme.rend(); ++itr){
		myfile << itr->first << ","<<itr->second << endl;
		if(rcoutn == 0){cout<<"\nFirst 15 students:\n"<<endl;}
		if(rcoutn == mapme.size() - 15){cout<<"\nLast 15 students:\n"<<endl;}
		if(rcoutn < 15){
			cout<< itr->first <<","<<itr->second<<endl;
		}
		if(rcoutn > mapme.size() - 15){
			cout<< itr->first <<","<< itr->second <<endl;
		}
		rcoutn++;	

	}
return;
}
//else{cout<<"not a valid flag"<<endl;}
	if(flag.compare("ASC") != 0 || flag.compare("DESC") != 0 ){cout<<"not a valid flag"<<endl;return;}	
}

void Write15toGdbm(){

datum nextkey = gdbm_firstkey (dbf);
for(int hhy = 0;hhy < wholefile.size()-1;hhy++){
	nextkey = gdbm_nextkey (dbf, nextkey);
	outtest.push_back(gdbm_fetch(dbf,nextkey).dptr);
	int relvalue = atoi((nextkey.dptr));
	mapme.insert (pair<int,string>(relvalue,gdbm_fetch(dbf,nextkey).dptr));

	

}

}

int main(int argc, char* argv[]){			

ifstream file;			// The input file containing nums	
file.open("lab3Input.txt");
				
ofstream outfile;		//writing to output file 		
outfile.open("lab3Output.txt");
//to beable to write to output file 		
log.open("logfile.txt");

string flag;
cout << "Choose either ASC or DESC (ordering of the numbers)" << endl;
cout << "ASC : ascending order" << endl;
cout << "DESC : descending order" << endl;
cin >> flag;

readinpFile(file);

writeFileinpToGdbm();

Write15toGdbm();

printOutputFifteen(flag,outfile);



gdbm_close(dbf);
file.close();
outfile.close();
file.close();
}


