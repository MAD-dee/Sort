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
    int length = sizeof(a) / sizeof(a[0]);
    for (int i = 1; i < length; i++){
        for (int j = i; j > 0; j--){
            if(a[j] < a[j-1]){
                int tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                
            }
            else{
                break;
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
