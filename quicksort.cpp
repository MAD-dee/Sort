#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
using namespace std;


void swap(int *nums, int a, int b){
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}

void quicksort(int *a, int l, int r){
    if (l >= r ){
        return ;
    }
    int i,j,base,tmp;
    i = l, j = r;
    swap(a,l,rand()%((r-l+1))+l);
    base = a[l];//选取最左边数为基准
    while(i < j){
        while (a[j] >= base && i < j){
            j--;
        }
        while (a[i] <= base && i < j){
            i++;
        }
        if (i < j){
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    //基准数归位
    a[l] = a[i];
    a[i] = base;
    quicksort(a,l,i-1);
    quicksort(a,i+1,r);
}


int main(){
    clock_t starttime,endtime;
    int a[100];
    srand(time(NULL));
    for(int i = 0; i < 100; i++){
        a[i] = rand()%1000;
    }
    int length = sizeof(a) / sizeof(a[0]);
    starttime = clock();
    quicksort (a,0,length-1);
    endtime = clock();
    cout << "the run time is "<<(double)(endtime - starttime)/(CLOCKS_PER_SEC)<<"s"<<endl;
    for (auto it : a){
        cout << it <<" ";
    }
    cout << endl;
    return 0;
}
