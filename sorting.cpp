#include<iostream>
#define MAX 10
using namespace std;

void selection_sort(int array[]);
void bubble_sort(int array[]);
void insertion_sort(int array[]);
void print_array(int array[]);
void merge_sort(int array[],int start,int last);
void merge(int array[],int temp[],int start1,int last1,int start2, int last2);
void quick_sort(int array[],int low,int up);
int partition(int array[],int low, int up);
void copy(int array[],int temp[],int start1,int last2);

int main(){
    int array[10]={18,1,2,6,4,17,23,14,10,7};
    print_array(array);
    //selection_sort(array);
    //bubble_sort(array);
    //insertion_sort(array);
    //merge_sort(array,0,MAX);
    quick_sort(array,0,MAX-1);
    print_array(array);
    return 0;
}

void selection_sort(int array[]){
    cout<<"\nThis is selection sort"<<endl;
    int i,j,min,temp;

    for(i=0;i<MAX-1;i++){
        min=i;
        for(j=i+1;j<MAX;j++){
            if(array[min]>array[j])
                min=j;
        }
        if(i!=min){
                temp=array[min];
                array[min]=array[i];
                array[i]=temp;
            }
    }
    print_array(array);
}

void bubble_sort(int array[]){
    cout<<"\nThis is bubble sort"<<endl;
    int i,j,change,temp;
    for(i=0;i<MAX;i++){
       for(j=0;j<MAX-1-i;j++){
           change=0;
            if(array[j]>array[j+1]){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                change++;
            }
        }
        if(change==0)
            break;
    }
    print_array(array);
}

void insertion_sort(int array[]){
    cout<<"\nThis is Insertion sort"<<endl;
    int i,j,k;
    for(i=1;i<MAX;i++){
        k=array[i];
       for(j=i-1;j>=0&&k<array[j];j--)
           array[j+1]=array[j];
    array[j+1]=k;
    }
        print_array(array);
}
void quick_sort(int array[],int low,int up){
    int p;
    if(low>up)
        return;
    p=partition(array,low,up);
    quick_sort(array,low,p-1);
    quick_sort(array,p+1,up);
}
int partition(int array[],int low, int up){
    int i=low+1,j=up,pivot=array[low],temp;
    while(i<=j){
        while(array[i]<pivot&&i<up)
            i++;
        while(array[j]>pivot)
            j--;
        if(i<j){
            temp=array[j];
            array[j]=array[i];
            array[i]=temp;
            i++;
            j--;
        }else
            i++;
    }
    array[low]=array[j];
    array[j]=pivot;
    return j;
}
void merge_sort(int array[],int start,int last){
    int mid;
    int temp[MAX];
    if(start<last){
        mid=(start+last)/2;
        merge_sort(array,start,mid);
        merge_sort(array,mid+1,last);
        merge(array,temp,start,mid,mid+1,last);
        copy(array,temp,start,last);
    }
}
void merge(int array[],int temp[],int start1,int last1,int start2, int last2){
    int i=start1,j=start2,k=start1;
    while ((i<=last1)&&(j<=last2))
    {
        if(array[i]<array[j])
            temp[k++]=array[i++];
        else 
            temp[k++]=array[j++];
    }
    while (i<=last1)
        temp[k++]=array[i++];
    while (j<=last2)
        temp[k++]=array[j++];    
}
void copy(int array[],int temp[],int start1,int last2){
    for(int i=start1;i<=last2;i++){
        array[i]=temp[i];
    }
}
void print_array(int array[]){
    cout<<endl;
    for(int i=0;i<MAX;i++)
        cout<<" "<<array[i];
    cout<<endl;
}