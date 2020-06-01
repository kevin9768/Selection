#include <fstream>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
int n, k;
int prunes(vector<int> arr, int _k){
    //Step 1
    if(arr.size()<5){
        sort(arr.begin(), arr.end());
        return arr[_k-1];
    }

    //Step 2
    int n_sub = ceil(arr.size()/5.0);
    vector<vector<int> > sub(n_sub, vector<int>());

    int idx=0;
    for(int i=0; i<arr.size(); i++){
        sub.at(idx).push_back(arr[i]);
        if(i%5==4)
            idx++;
    }
    if(idx<n_sub)
        for(int i=sub[idx].size(); i<5; i++)
            sub[idx][i] = INT32_MAX;

    //Step 3
    for(auto &i: sub)
        sort(i.begin(), i.end());
    
    //Step 4
    vector<int> medians_sub;
    for(auto &i: sub){
        int m = prunes(i, 3);
        medians_sub.push_back(m);
    }
    int p = prunes(medians_sub, medians_sub.size()/2);

    //Step 5
    vector<int> s1, s2, s3;
    for(auto i: arr){
        if(i<p)
            s1.push_back(i);
        else if(i==p)
            s2.push_back(i);
        else
            s3.push_back(3);
    }

    //Step 6
    if(s1.size()>=_k)
        return prunes(s1, _k);
    else if(s1.size()+s2.size()>=_k)
        return p;
    else
        return prunes(s3, _k - (s1.size()+s2.size()));

}

void prunesearch(vector<int> arr, ofstream& PS){
    clock_t start, end;
    start = clock();
    int ans = prunes(arr, k);
    end = clock();

    double taken = double(end - start)/ double(CLOCKS_PER_SEC);
    PS<<ans<<'\n';
    PS<<taken<<setprecision(5)<<'\n';
}

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void q_sort(vector<int>& arr, int l, int r){
    if(l>=r)    return;
    int pivot=arr[r], i=l-1, j;

    for(j=l; j<=r-1; j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);

    q_sort(arr, l, i);
    q_sort(arr, i+2, r);
}

void quicksort(vector<int> arr, ofstream& QS){
    clock_t start,end;
    start = clock();
    q_sort(arr, 0, n-1);
    end = clock();

    double taken = double(end - start)/ double(CLOCKS_PER_SEC);
    QS<<arr[k-1]<<'\n';
    QS<<taken<<setprecision(5)<<'\n';
}

int main(int argc, char** argv){
    ifstream input;
    ofstream QS, PS;

    if(argc==1){
        input.open("./input.txt");
        QS.open("./QS.txt");
        PS.open("./PS.txt");
    }
    else if(argc==4){
        input.open(argv[1]);
        QS.open(argv[2]);
        //PS.open(argv[3]);
    }

    input>>n>>k;

    vector<int> arr;
    for(int i=0; i<n; i++){
        int a;
        input>>a;
        arr.push_back(a);
    }

    quicksort(arr, QS);
    prunesearch(arr, PS);
}