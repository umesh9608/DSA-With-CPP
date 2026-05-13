  //Search in a roated array
  #include<iostream>
using namespace std;

int search(int arr[], int n, int target){
    int start = 0;
    int end = n - 1;

    while(start <= end){
        int mid = start + (end - start) / 2;

        // element found
        if(arr[mid] == target){
            return mid;
        }

        // left part sorted
        if(arr[start] <= arr[mid]){

            // target exists in left part
            if(target >= arr[start] && target < arr[mid]){
                end = mid - 1;
            }else{
                start = mid + 1;
            }

        }
        // right part sorted
        else{

            // target exists in right part
            if(target > arr[mid] && target <= arr[end]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main(){

    int arr[] = {5,6,7,8,9,1,2,3,4};
    int n = 9;
    int target = 2;

    int ans = search(arr, n, target);

    if(ans != -1){
        cout << "Element found at index: " << ans;
    }else{
        cout << "Element not found";
    }

    return 0;
}