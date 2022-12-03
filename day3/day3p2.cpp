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
    string line,line1,line2,line3;
    vec total,firstline,secondOccurences;
    char commonGroup;
    bool found;
    unsigned int i,j;
    int linesBuffered=0;
    int prioritySum = 0;

    while(getline(cin,line)){
        linesBuffered++;

        if(linesBuffered == 1){
            line1 = line;
        }if(linesBuffered == 2){
            line2 = line;
        }if(linesBuffered == 3){
            line3 = line;

            //registers each occurence in line 1 one time by type
            for(i=0;i<line1.length();i++){
                registerOccurence(line1[i],firstline);
            }

            // compares the occurences of line 1 to the line 2
            for(i=0;i<line2.length();i++){
                for(j=0;j<firstline.size();j++){
                    if(line2[i]==firstline[j]){
                        secondOccurences.push_back(firstline[j]);
                        break;
                    }
                }
            }

            // compares the common occurences of the previous lines to the 3rd.
            for(i=0;i<line3.length();i++){
                for(j=0;j<secondOccurences.size();j++){
                    if(line3[i]==secondOccurences[j]){
                        commonGroup = secondOccurences[j];
                        found = true;
                        break;
                    }
                }
                if(found) break;
            }

            total.push_back(commonGroup);

            firstline.erase(firstline.begin(),firstline.end());
            secondOccurences.erase(secondOccurences.begin(),secondOccurences.end());
            linesBuffered = 0;
            found = false;
        }
    }

    for(i=0;i<total.size();i++){
        prioritySum += priority(total[i]);
    }

    cout << " PART 2: Priority sum " << prioritySum << endl;

}