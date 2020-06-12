#include<fstream>
#include<cstdlib>
#include<string>
#include<iostream>

using namespace std;
int main(){
    for(int i=10000; i<=30000; i+=1000){
        for(int j=1; j<=3; j++){
            string exec = "./run ./data/" + to_string(i) + "/" + to_string(j) + ".txt ";
            string QS = "./data/" + to_string(i) + "/QS_" + to_string(j) + ".txt ";
            string PS = "./data/" + to_string(i) + "/PS_" + to_string(j) + ".txt ";
            cout<<exec+QS+PS<<'\n';
            system((exec+QS+PS).c_str());
            //cout<<exec2+BF<<'\n';
            //system((exec2+BF).c_str());
        }
    }
}