#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
using namespace std;

int main(){
    clock_t starttime,endtime;
    starttime = clock();
   int a[1000];
    srand(time(NULL));
    for(int i = 0; i < 1000; i++){
        a[i] = rand()%1000;
    }
    bool sorted = false;//借助bool标志位。提前退出。
    int length = sizeof(a) / sizeof(a[0]);
    while(!sorted){
        sorted = true;
        for (int i = 0; i < length - 1; i++){
        for (int j = 0; j < length - i -1; j++){
           if(a[j] > a[j+1]){
               int tmp = a[j+1];
               a[j+1] = a[j];
               a[j] = tmp;
               sorted = false;
           } 
        }
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
