#include <iostream>
#include <string>
using namespace std;
int main()
{

string s = "scott>=tiger>=mushroom";
string delimiter = ">=";

size_t pos = 0;
string token;
while ((pos = s.find(delimiter)) != string:: npos) {
    token = s.substr(0, pos);
    cout << token << endl;
    s.erase(0, pos + delimiter.length());
}
cout << s << endl;
}
