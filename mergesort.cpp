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
void merge(int *a, int l, int mid, int r){
    int len = r - l + 1;
    int aux[len];
    // 初始化，i指向左半部分的起始索引位置l；j指向右半部分起始索引位置mid+1
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {

        if (i > mid) {  // 如果左半部分元素已经全部处理完毕
            a[k] = aux[j - l];
            j++;
        } else if (j > r) {   // 如果右半部分元素已经全部处理完毕
            a[k] = aux[i - l];
            i++;
        } else if (aux[i - l]<aux[j - l]) {  // 左半部分所指元素 < 右半部分所指元素
            a[k] = aux[i - l];
            i++;
        } else {  // 左半部分所指元素 >= 右半部分所指元素
            a[k] = aux[j - l];
            j++;
        }
    }

}

void sort(int *a, int l, int r){
    if (l >= r ){
        return ;
    }
    int mid = (l + r)/2;
    sort(a,l,mid);
    sort(a,mid,r);
    if(a[mid]>a[mid+1]){
        merge(a,l,mid,r);
    }

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
    sort (a,0,length-1);
    endtime = clock();
    cout << "the run time is "<<(double)(endtime - starttime)/(CLOCKS_PER_SEC)<<"s"<<endl;
    for (auto it : a){
        cout << it <<" ";
    }
    cout << endl;
    return 0;
}
