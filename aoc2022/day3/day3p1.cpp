#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<char> vec;

void registerOccurence(char c,vec &v){
    unsigned int i;
    for(i=0;i<v.size();i++){
        if(c == v[i]){
            return;
        }
    }
    v.push_back(c);
}

int priority(char c){
    if(c<'a')
        return c - 64 + 26;
    return c - 96;
}

int main(){
    string line;
    vec total,totaline;
    unsigned int half,i,j;
    int prioritySum = 0;

    while(getline(cin,line)){
        half = line.length()/2;

        for(i=0;i<half;i++){
            for(j=half;j<line.length();j++){
                if(line[i]==line[j]){
                    registerOccurence(line[i],totaline);
                }
            }
        }

        for(i=0;i<totaline.size();i++){
            total.push_back(totaline[i]);
        }

        totaline.erase(totaline.begin(),totaline.end());
    }

    for(i=0;i<total.size();i++){
        prioritySum += priority(total[i]);
    }

    cout << " PART 1: Priority sum " << prioritySum << endl;

}