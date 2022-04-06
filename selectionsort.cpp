#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
using namespace std;

int main(){
    clock_t starttime,endtime;
    starttime = clock();
    int a[] = {1, 2, 10, 11, 5, 9, 2};
    int length = sizeof(a) / sizeof(a[0]);
    int min_index;
    for (int i = 0; i < length -1; i++){
        min_index = i ;
        for (int j = i+1; j < length; j++){
            if(a[min_index] > a[j]){
                min_index = j;
            }
        }
        int tmp = a[i];
        a[i] = a[min_index];
        a[min_index] = tmp;
    }
    endtime = clock();
    cout << "the run time is "<<(double)(endtime - starttime)/(CLOCKS_PER_SEC)<<"s"<<endl;
    for (auto it : a){
        cout << it <<" ";
    }
    cout << endl;
    return 0;
}