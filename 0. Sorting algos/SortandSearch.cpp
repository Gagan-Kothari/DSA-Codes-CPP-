#include <iostream>
using namespace std;

void printdata(int data[],int s){
    int k{0};
    for(k=0;k<s;k++){
        cout << "\t" <<data[k];
    }
}

// SORTINGS: 

void bubblesort(int data[],int s){
    int i{0};
    int j{0};
    int temp{0};
    for(i=0;i<s;i++){
        for(j=0;j<s-i-1;j++){
            if(data[j]>data[j+1]){
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
        printdata(data,s);
        cout << endl;
    }
}

void insertsort(int data[],int s){
    int i=0;
    int j=0;
    int temp=0;
    for(i=1;i<s;i++){
        temp = data[i];
        j=i-1;
        while(j>=0 && data[j]>temp){
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = temp;
        printdata(data,s);
        cout << endl;
    }
}

void selectsort(int data[],int s){
    int ptr=0;
    int min=0;
    int temp=0;
    for(int i=0;i<s;i++){
        min = i;
        for(ptr=i+1;ptr<s;ptr++){
            if(data[min] > data[ptr]){
                min = ptr;
            }
        }
        temp = data[min];
        data[min] = data[i];
        data[i] = temp;
        printdata(data,s);
        cout << endl;
    }
}

void merge(int data[], int low, int mid, int high){
    int i;
    int j;
    int k;
    int size1 = mid - low + 1;
    int size2 = high - mid;
    int b[size1];
    int c[size2];

    for (i = 0; i < size1; i++) 
        b[i] = data[low + i];
    for (j = 0; j < size2; j++)
        c[j] = data[mid + 1 + j];

    i = 0;
    j = 0;
    k = low;
    while (i < size1 && j < size2) {
        if (b[i] <= c[j]) {
            data[k] = b[i];
            i++;
        }
        else {
            data[k] = c[j];
            j++;
        }
        k++;
    }
    while (i < size1) {
        data[k] = b[i];
        i++;
        k++;
    }
    while (j < size2) {
        data[k] = c[j];
        j++;
        k++;
    }
}

void mergesort(int data[], int low, int high){
    if (low < high) {
        int mid = (low + high)/2;
        mergesort(data, low, mid);
        mergesort(data, mid + 1, high);
        merge(data, low, mid, high);
    }
}

int partition(int data[],int low,int high){
    int indx = data[low];
    int left = low;
    for(int i=low+1;i<=high;i++){
        if(data[i]<indx){
            left++;
            int temp1;
            temp1 = data[left];
            data[left] = data[i];
            data[i] = temp1;
        }
    }
    int temp2;
    temp2 = data[left];
    data[left] = data[low];
    data[low] = temp2;
    return left;
}

void quicksort(int data[],int low,int high){
    if (low<high){
        int indxloc = partition(data,low,high);
        quicksort(data,low,indxloc-1);
        quicksort(data,indxloc+1,high);
        printdata(data,high+1);
        cout << endl;
    }
}

// SEARCHING: 
void linearsearch(int data[],int s){
    int v{0};
    int i{0};
    cout << "Enter the value: ";
    cin >> v;
    for(i=0;i<s;i++){
        if (data[i] == v){
            cout << "The Value is at Index number: " <<  i;
        }
    }
}

void binarysearch(int data[],int val,int low,int high){
    int mid = (low+high)/2;
    if (val == data[mid]){
        cout << "The value is at index Number: " << mid << endl;
    }
    else if(val>data[mid]){
        binarysearch(data,val,mid+1,high);
    }
    else{
        binarysearch(data,val,low,mid-1);
    }
}

int main(){
    int data[]={4,7,3,8,5,9,1,2};
    int size=sizeof(data)/sizeof(data[0]);
    int option;
    int inp;
    int x=1;
    do{
        cout << "======================= Searching and Sorting =======================" << endl;
        cout << "MENU:" << endl;
        cout << "1.Sort" << endl;
        cout << "2.Search" << endl;
        cout << "0.Exit" << endl;
        cin >> option;
        switch(option){
            case 1:
                cout << "======================= Sorting Menu =======================" << endl;
                cout << "1.Bubble Sort" << endl;
                cout << "2.Insert Sort" << endl;
                cout << "3.Selection Sort" << endl;
                cout << "4.Merge Sort" << endl;
                cout << "5.Quick Sort" << endl;
                cin >> inp;
                switch(inp){
                    case 1:
                        cout << "Array before Sort: " << endl;
                        printdata(data,size);
                        cout << endl;
                        cout << "Procedure: " << endl;
                        bubblesort(data,size);
                        cout << "Array After Sort: " << endl;
                        printdata(data,size);
                        cout << endl;
                        break;
                    
                    case 2:
                        cout << "Array before Sort: " << endl;
                        printdata(data,size);
                        cout << endl;
                        cout << "Procedure: " << endl;
                        insertsort(data,size);
                        cout << "Array After Sort: " << endl;
                        printdata(data,size);
                        cout << endl;
                        break;
                    
                    case 3:
                        cout << "Array before Sort: " << endl;
                        printdata(data,size);
                        cout << endl;
                        cout << "Procedure: " << endl;
                        selectsort(data,size);
                        cout << "Array After Sort: " << endl;
                        printdata(data,size);
                        cout << endl;
                        break;
                    
                    case 4:
                        cout << "Array before Sort: " << endl;
                        printdata(data,size);
                        cout << endl;
                        mergesort(data,0,size-1);
                        cout << "Array After Sort: " << endl;
                        printdata(data,size);
                        cout << endl;
                        break;

                    case 5:
                        cout << "Array before Sort: " << endl;
                        printdata(data,size);
                        cout << endl;
                        cout << "Array after Sort: " << endl;
                        quicksort(data,0,size-1);
                        printdata(data,size);
                        cout << endl;
                        break;

                }
                break;
            case 2:
                cout << "======================= Searching Menu =======================" << endl;
                cout << "1.Linear Search" << endl;
                cout << "2.Binary Search" << endl << endl;
                cout << "PLEASE MAKE SURE THAT THE ARRAY IS SORTED FOR BINARY SEARCH." << endl;
                cin >> inp;
                switch(inp){
                    case 1:
                        linearsearch(data,size);
                        cout << endl;
                        break;
                    
                    case 2:
                        int val {0};
                        cout << "Enter the value to search: ";
                        cin >> val;
                        cout << "The array is: " << endl;
                        printdata(data,size);
                        cout << endl;
                        binarysearch(data,val,0,size-1);
                        break;
                }
                break;
            case 0:
                x=0;
                cout << "Exited Successfully.";
        }
    }while(x);
}