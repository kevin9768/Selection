#include<fstream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<iostream>

using namespace std;
int main(){
    srand(time(NULL));
    ofstream f;
    for(int i=10000;i<=30000; i+=1000){
        for(int j=1;j<=3;j++){
            if(j==1){
                string dir = "mkdir ./data/" + to_string(i);
                system(dir.c_str());
            }
            string s=to_string(i), c=to_string(j);
            
            string out = "./data/" + s + "/" + c +".txt";
            cout<<out<<endl;
            f.open(out.c_str(), ios_base::trunc | ios_base::in);

            //n
            f<<i<<' ';
            //k
            f<<(1 + rand()%i)<<'\n';
            for(int k=0; k<i; k++){
                f<<(1 + rand()%20000)<<' ';
            }
            f.close();
        }
    }
}