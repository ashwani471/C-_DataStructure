#include<iostream>
using namespace std;

void display(int *arr,int n){
    for(int i=0 ; i< n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insert(int *arr,int len,int idx,int x,int n){
   for(int i=len;i>idx;i--){
    arr[i]=arr[i-1];
   }
   arr[idx]=x;
   len++;
//    cout<<len;
   display(arr,len);
}

void Delete(int *arr , int idx , int len){
    // cout<<len;
    for(int i=idx;i<len;i++){
        arr[i]=arr[i+1];
    }
    display(arr,len);
    len--;
}

int linearSearch(int *arr , int len , int x){
    for(int i=0;i<len ; i++){
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}

int binarySearch(int *arr ,int low , int high , int key){
    while(low<=high){
      int mid = (low+high)/2;
      if(arr[mid] == key){
        return mid;
      }else if(arr[mid]>key){
        high = mid-1;
      }else{
        low = mid+1;
      }
    }
    return -1;
}



int main(){
    int n;
    cout<<"Enter the size of an Array:";
    cin>>n;
    int *arr = new int[n];
    int len;
    cout<<" Enter the Number of element you want to Put:";
    cin>>len;
    bool flag = 0;
    bool idea = 0;

    for(int i = 0 ; i < len ;i++){
        cout<<"Enter " << i+1 << " element:";
         cin>>arr[i];      
    }

       cout<<"You want to Enter more element Please confirm by pressing 1 or decline by pressing 0:";
            cin>>idea;
            if(idea == 1){
               int prevLen=len;
               cout<<"Enter how many element you want to enter:";
               int moreElem;
               cin>>moreElem;
               len = len + moreElem;
               if(len >= n ){
                n = 2*n;
                int prevN=n;
                int *arr1 = new int[n];
                for(int i=0 ; i<prevLen; i++){
                     arr1[i] = arr[i];
                }
                for(int j=prevLen; j<prevLen+moreElem; j++){
                    // cout<<prevLen+moreElem;
                    cout<<"Enter "<< j+1 <<" element: ";
                    cin>>arr1[j];
                }
                delete arr;
                bool insrt;
                cout<<"Do you want to insert a Element at any index If yes then press 1 otherwise press 0:";
                cin>>insrt;
                if(insrt == 1){
                    int indx;
                    int insrtNmbr;
                    cout<<"Give me the index:";
                    cin>>indx;
                    cout<<"Give me the number that you want to insert:";
                    cin>>insrtNmbr;
                    bool dltAns;
                    int dltIdx;
                    if(indx<=n && len<n){
                        insert(arr1,len,indx,insrtNmbr,n);
                        cout<<"Do you want to delete an element press 1 if YES or 0 if NO:";
                        cin>>dltAns;
                        if(dltAns==1){
                           cout<<"give me the Delete Index:";
                           cin>>dltIdx;
                           if(dltIdx>len){
                            cout<<"give me the valid index";
                           }else{
                           Delete(arr1,dltIdx,len);
                           }
                        }  
                        bool searchElm;
                        int elem;
                            cout<<"Do you want to search any digit if YES then press 1 otherwise press 0:";
                            cin>>searchElm;
                            cout<<"Give me the Element that you want to search:";
                            cin>>elem;
                            if(searchElm == 1){
                                cout<<"Element is Found on index :"<<linearSearch(arr1,len,elem);

                                cout<<"Element is found on index:"<<binarySearch(arr1,0,len,elem);
                        }

                    }else{
                        n=prevN+1;
                        int *arr2 = new int[n];
                        for(int i=0;i<prevN;i++){
                            arr2[i]=arr1[i];
                        }
                         insert(arr2,len,indx,insrtNmbr, n);
                    }
            }
                // display(arr1,len);
                
               }else{
                for(int i=prevLen ; i<len ; i++){
                    cin>>arr[i];
                }
                display(arr,len);
               }
            }
            else{
                display(arr,len);
            }
            
            // insert(arr)
            // bubbleSort(arr,len);
           
}