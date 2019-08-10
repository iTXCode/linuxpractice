#include<iostream>
using namespace std;

 void sort(int arr[], int num){ 
	  for (int i = 0; i < num; i++){
	     for (int j = i; j < num - i-1; j++){
			       if (arr[j]> arr[j+1]){
				         int tmp = arr[j+1];
				         arr[j+1]= arr[j];
				         arr[j] = tmp;	
			}	
		}
	}
	  cout << "sort after:";
	   for (int i = 0; i < num; i++){
		    cout << arr[i] << " ";
		
	}
	   cout << endl;
	
}

 int main(){
	 int arr[] = { 1, 23, 45, 6, 7, 8, 89, 65, 34, 64, 778, 100 };
	 size_t sz = sizeof(arr) / sizeof(arr[0]);
	 cout << "sort before:";
	 for (size_t i = 0; i < sz; i++){
		 cout << arr[i] << " ";

	 }
	 cout << endl;
	 sort(arr, sz);
	 return 0;
}
