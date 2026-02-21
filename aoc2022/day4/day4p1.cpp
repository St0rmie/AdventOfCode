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

int fullyOverlap(int b1, int e1, int b2, int e2){
    return (b1<=b2 && e2<=e1) || (b2<=b1 && e1<=e2);
}

int main(){
    string line;
    vector<int> timestamps;
    vector<int> overlaps;
    int overlapCount = 0;

    while(getline(cin,line)){
        timestamps = parser(line);
        if(fullyOverlap(timestamps[0],timestamps[1],timestamps[2],timestamps[3]))
            overlapCount++;
    }
    cout << " PART 1: Overlap count " << overlapCount << endl;

}