#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
using namespace std;

int main(){
    clock_t starttime,endtime;
    starttime = clock();
    int a[100];
    srand(time(NULL));
    for(int i = 0; i < 100; i++){
        a[i] = rand()%100;
    }
    int j;
    int length = sizeof(a) / sizeof(a[0]);
    for(int gap = length / 2; gap > 0; gap /= 2){
        for(int i = gap; i < length; i++){
            int tmp = a[i];
            for(j=i; j>=gap&&tmp<a[j-gap];j-=gap){
                a[j] = a[j-gap];
            }
            a[j] = tmp;
        }
    }

    endtime = clock();
    cout << "the run time is "<<(double)(endtime - starttime)/(CLOCKS_PER_SEC)<<"s"<<endl;
    for (auto it : a){
        cout << it <<" ";
    }
    cout << endl;
    return 0;
}
