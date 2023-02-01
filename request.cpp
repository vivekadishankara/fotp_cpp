#include <iostream>
#include <fstream>
#include <map>
// #include <string>

using namespace std;

map<string, string> parse_request(string &str, int N){
    string entry="";
    string key, value;
    map <string, string> request_map;
    
    for (int i=0; i<=N; i++){
        if (i==N || str[i]=='|' || str[i]==':'){
            if (str[i]==':'){
                key = entry;
            } else {
                value = entry;
                request_map.insert({key, value});
            }
            entry = "";
            continue;
        }
        else
            entry += str[i];
        
    }
    return request_map;
}

int main(){
    ifstream myfile ("request_480069891");
    string mystring;

    if (myfile.is_open()){
        myfile >> mystring;
        int N = mystring.length();
        map<string, string> request_map = parse_request(mystring, N);
        map<string, string>::iterator it = request_map.begin();

        while (it != request_map.end()){
            cout<<it->first<<":\t"<<it->second<<endl;
            it++;
        }
    }
}
