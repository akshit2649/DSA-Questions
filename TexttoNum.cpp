#include <bits/stdc++.h>
using namespace std;

 long long merge(long long arr[],long long temp[], long long l, long long mid, long long r){
        long long inv=0;

        int i,j,k;
        i=l;
        j = mid;
        k = l;
        while((i<=mid) and (j<=r)){
        	if(arr[i]<=arr[j]){
        		temp[k++] = arr[i++];
        	}
        	else{
        		temp[k++] = arr[j++];
        		inv+=mid-i;
        	}
        }

        while(i <= mid-1) temp[k++] = arr[i++];

        while(j <= r) temp[k++] = arr[j++];

        for(i<=l; i<=r; i++) arr[i] = temp[i];

        	return inv;
        
        // int n1 = mid-l+1;
        // int n2 = r-mid;
        
        // int a[n1];
        // int b[n2];
        
      
        // for(int i=0;i<n1;i++){
        //     a[i] = arr[l+i];
        // }
        
        // for(int i=0;i<n2;i++){
        //     b[i] = arr[mid+1+i];
        // }
        
        //   int i=0, j=0, k=l;
        
        // while(i<n1  and j<n2){
        //     if(a[i]<b[j]){
        //         arr[k] = a[i];
        //         i++;
        //         k++;
        //     }
        //     else{
        //         arr[k] = b[j];
        //         inv+=n1-i;
        //         j++;
        //         k++;
        //     }
        // }
        
        // while(i<n1){
        //     arr[k] = a[i];
        //     k++;
        //     i++;
        // }
        
        // while(j<n2){
        //     arr[k] = b[j];
        //     j++;
        //     k++;
        // }
        return inv;
    }

 long long mergeSort(long long arr[],long long temp[], long long l, long long r){
      long long inv = 0;
          
      if(l<r){
         
          long long mid = (l+r)/2;
          inv+=mergeSort(arr,temp, l, mid);
          inv+=mergeSort(arr,temp, mid+1, r);
          inv+=merge(arr,temp, l, mid+1, r);
      }
      return inv;
  }

int main(){
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	long long n;
	cin>>n;
	long long arr[n];
	long long temp[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	cout<<mergeSort(arr,temp,0,n-1);

	return 0;
}

