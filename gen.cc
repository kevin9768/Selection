#include<fstream>
using namespace std;
int main() {
    ofstream gen;
    gen.open("./gen.txt");
    gen<<20000<<' ';
    gen<<2500<<'\n';

    for(int i=0; i<20000; i++){
        gen<<5000<<' ';
    }
}