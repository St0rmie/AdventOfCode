#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vec;

vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

vector<int> parser (string line){
    vector<string> v;
    vector<string> v1;
    vector<string> v2;
    vector<int> time;

    v = split(line,',');
    v1 = split(v[0],'-');
    v2 = split(v[1],'-');

    time.push_back(stoi(v1[0]));
    time.push_back(stoi(v1[1]));
    time.push_back(stoi(v2[0]));
    time.push_back(stoi(v2[1]));
    return time;
}

bool overlap(int b1, int e1, int b2, int e2){
    for(int i = b1;i<=e1;i++){
        if(i>=b2 && i<=e2)
            return true;
    }
    return false;
}

int main(){
    string line;
    vector<int> timestamps;
    vector<int> pairsOverlapping;
    int pairNumber = 1;

    while(getline(cin,line)){
        timestamps = parser(line);
        if(overlap(timestamps[0],timestamps[1],timestamps[2],timestamps[3])){
            pairsOverlapping.push_back(pairNumber);
        }
    }
    cout << " PART 2: no. overlapping pairs " << pairsOverlapping.size() << endl;

}