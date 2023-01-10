#include <iostream>
using namespace std;
 
//i -> node
void heapify(int arr[], int N, int i)
{
 
    int largest = i;
 
    int l = 2 * i + 1;
 
    int r = 2 * i + 2;
 
    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < N && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, N, largest);
    }
}
 
void heapSort(int arr[], int N)
{
 
    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
 
    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {
 
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
 
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    heapSort(arr, N);
 
    cout << "Sorted array is \n";
    printArray(arr, N);
}



//#include <iostream>
//#include<vector>
//using namespace std;
//void heapify(vector <int>& v , int i , int n)
//{
//    //storing the parent in temp
//    int largest = v[i];
//    int child = 0;
//    while(2*i <= n)
//    {
//         child = 2*i;
//        //to check if right child value is there and is greater than left child
//        if((child < n) && (v[child+1] > v[child]))
//        {
//            child = child+1;
//        }
//        //if child is greater than parent 
//        if(v[child] > largest)
//        {
//            //swap krdiya parent sath
//            v[i] = v[child];
//        }
//        else 
//            break;
//        i = child;
//    }
//    v[i] = largest;
//}
//void heapSort(vector <int> &v, int n)
//{
//    while(n>0)
//    {
//        int temp = v[1];
//        v[1] = v[n];
//        v[n] = temp ;
//        n--;
//        for(int j = n/2 ; j >=1 ; j--)
//            {
//                heapify(v, j , n);
//            }
//         
//    }
//}
//int main()
//{
//    int n ;
//    
//    vector<int> v = {1 , 4 , 5 , 2 ,3,6 ,7};
//    n = v.size();
//    
//    //because baki leaf nodes hai  
//    for(int i = n/2 ; i >=1 ; i--)
//    {
//        heapify(v, i , n);
//    }
//    n--;
//    heapSort(v, n);
//    for(int i = 0 ; i < v.size() ;i++)
//    {
//        cout<<v[i];
//    }
//
//    return 0;
//}

