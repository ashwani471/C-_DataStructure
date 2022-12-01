#include<iostream>
using namespace std;

int fib[10] = {-1};

int Power(int x , int n){

    if(x>0){
        if(n==0){
            return 1;
        }
        int smallPower = x*Power(x,n-1);
        return smallPower;
    }
}

int Count(int n){
    if(n==0){
        return 0;
    }
    int smallNumber = Count(n/10);
    return smallNumber+1;
}

int Fibo(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int smalloutput1 = Fibo(n-1);
    int smalloutput2 = Fibo(n-2);
    return smalloutput1+smalloutput2;
}

bool is_Sorted(int arr[] , int n){
    if(n==0 || n==1 ){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    bool smallOutput = is_Sorted(arr+1 , n-1);
    return smallOutput;
}

int arraySum(int arr[],int n){
    if(n==1){
        return arr[0];
    }
    int smallOutput = arraySum(arr+1,n-1);
    return smallOutput+arr[0];
}

bool searchElement(int arr[] , int n , int x){
    if(n==0){
        return false; 
    }
    if(arr[0]==x){
        return true;
    }
   bool smallOutput = searchElement(arr+1, n-1, x);
    return smallOutput;
}

int firstIndex(int arr[],int n,int x){
    if(n==0){
        return -1;
    }
    if(arr[0]==x){
        return 0;
    }
    int smallOutput = firstIndex(arr+1,n-1,x); 
    // return smallOutput+1;
    if(smallOutput==-1){
        return -1;
    }else{
        smallOutput+1;
    }
}

int lastIndex(int arr[],int n,int x){
    if(n==0){
        return -1;
    }
    int smalloutput = lastIndex(arr+1,n-1,x);
    if(smalloutput!=-1){
        return smalloutput+1;
    }
    if(arr[0]==x){
        return 0;
    }else{
        return smalloutput;
    }
}


void TreeRecursion(int n){
    if(n>0){
        cout<<n<<" ";
        TreeRecursion(n-1);
        TreeRecursion(n-1);

    }
}

int nestedRecursion(int n){
    if(n>100){
        return n-10;
    }else{
        return nestedRecursion(nestedRecursion(n+11));
    }
}

int SumOfNaturalNumber(int n){
    if(n==0){
      return 0;
    }
    int smallOutput = SumOfNaturalNumber(n-1)+n;
    return smallOutput;
}



int mFibo(int n){
    if(n<=1){
       fib[n]=n;
       return n;
    }
    else{
        if(fib[n-2]==-1){
          fib[n-2]=mFibo(n-2);
        }
        if(fib[n-1]==-1){
            fib[n-1]=mFibo(n-1);
        }
        return fib[n-2]+fib[n-1];
    }
}

int multiplicationRec(int m , int n){
    if(n<m){
        if(n==0){
            return 0;
        }
        int smalloutput = multiplicationRec(m,n-1);
        return smalloutput+m;
    }else{
        if(m==0){
            return 0;
        }
        int smalloutput = multiplicationRec(m-1,n);
        return smalloutput+n;
    }
}

int countZero(int n){
    if(n<=9&&n>=0){
           if(n==0){
            return 1;
           }else{
            return 0;
           }
    }
 int smallOutput = countZero(n/10);
 if(n%10==0){
    return smallOutput+1;
 }else{
    return smallOutput;
 }

}

static int p=1;
static int f=1;

double taylorSeries(int e , int n){
if(n==0){
    return 1;
}
double smallOutput = taylorSeries(e,n-1);
p=p*e;
f=f*n;
return smallOutput+p/f;
}
static double g=1;
// static int s=1;
double geometricSum(int n,int x){
    if(n==0){
        return 1;
    }
    double smallOutput = geometricSum(n-1,x);
    g=g*x;
    return smallOutput + 1/g;
}

bool checkPalindromeRec(char str[],int s,int e){
    if(s==e){
        return true;
    }
    if(str[s]!=str[e]){
        return false;
    }
    bool smallOutput = checkPalindromeRec(str,s+1,e-1);
    return smallOutput;
}

void replacePi(char str[] , int st ,  int e){
    if(str[st]=='\0' || str[st+1]=='\0'){
        return;
    }
    replacePi(str,st+1,e-1);
    if(str[st]=='p'&&str[st+1]=='i'){
        for(int i = e;i>=st+2;i--){
            str[i+2]=str[i];
        }
        str[st]='3';
        str[st+1]='.';
        str[st+2]='1';
        str[st+3]='4';
    }
}

void removeX(char str[]){

if(str[0]=='\0'){
    return;
}

  if(str[0]!='x'){
    removeX(str+1);
  }else{
    int i=1;
    for(;str[i]!='\0';i++){
        str[i-1]=str[i];
    }
    str[i-1]=str[i];
    removeX(str);
  }

}

// int stringtoInteger(char str[],int n){
//     if(n==0){
//         int a = str[n]-'0';
//         return a;
//     }
//     int y=stringtoInteger( str,n-1);
//            int x=str[n]-'0';
//            y=y*10+x;
    
// }

// static int count=0;

// int * allIndeces(int arr[],int idx,int x,int count,int e){
//     if(idx==e){
//         int iarr[count];
//         return iarr;
//     }
//     int *ptr;
//     if(arr[idx]==x){
        
//         ptr=allIndeces(arr,idx+1,x,count+1,e);
//         ptr[count]=idx;
//     }else{
//         ptr=allIndeces(arr,idx+1,x,count,e);
//     }
//     return ptr;
// }

void pairStar(char str[],int n){
    if(n==0){
        return;
    }
    if(str[0]==str[1]){
        for(int i=1;i<n;i++){
            str[i+1]=str[i];
        }
        str[1]='*';
        pairStar(str+2,n-2);
    }else{
        pairStar(str+1,n-1);
    }
}

void replaceChar(char str[] , char c1,char c2){
    if(str[0]=='\0'){
        return;
    }
    if(str[0]==c1){
        str[0]=c2;
    }
    replaceChar(str+1,c1,c2);
}

void removeConsecutiveDuplicates(char str[]){
    if(str[0]=='\0'|| str[1]=='\0'){
       return;
    }
    if(str[0]==str[1]){
        int i=1;
        for(;str[i]!='\0';i++){
            str[i-1]=str[i];
        }
        str[i-1]=str[i];
        removeConsecutiveDuplicates(str);
    }else{
        removeConsecutiveDuplicates(str+1);
    }
}

void merge(int input[],int si,int mid,int ei){
    int i=si;
    int j=mid+1;
    int *output= new int[ei-si+1];
    int k=0;
    while(i<=mid&& j<=ei){

        if(input[i]<input[j]){
            output[k]=input[i];
            i++;
            k++;
        }else{
             output[k]=input[j];
             k++;
             j++;    
        }

        if(i<=mid){
            output[k]=input[i];
            i++;k++;
        }
        if(j<=ei){
            output[k]=input[i];
            j++;
            k++;
        }
   }
   int i=0;
   for(;i<=ei;i++){
    input[i]=output[i];
    i++;
   }
}

void mergeSort(int input[],int si,int ei){
    if(si>=ei){
        return;
    }
    int mid = (si+ei)/2;
    mergeSort(input,si,mid);
    mergeSort(input,mid+1,ei);
    merge(input,si,mid,ei);
}

int main(){
    int n;
    cout<<"Enter a number:";
    // cout<<"Enter the power:";
    cin>>n;
    int *input = new int[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    mergeSort(input,0,n-1);
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
    // int x;
    // cout<<"Enter the value of x:";
    // cin>>x;
    // // cout<<taylorSeries(x,n);
    // cout<<geometricSum(n,x);

    //  char str[50];
    //  cout<<"Enter a string:";
    //  cin>>str;
    //  int len=0;
    //  for(int i=0;str[i]!='\0';i++){
    //       len++;
    //  }
    //  removeConsecutiveDuplicates(str);
    // cout<<str;
    //  char c1;
    //  cout<<"Enter c1:";
    //  cin>>c1;
    //  char c2;
    //  cout<<"Enter c2:";
    //  cin>>c2;
    //  pairStar(str,len-1);
    // replaceChar(str,c1,c2);
    //  cout<<str;
    //  cout<<len;
    //  int st=0;
    //  int end=len-1;
    //  cout<<stringtoInteger(str,end);
    //   cout<<checkPalindromeRec(str,st,end);
    // replacePi(str,st,end);
    // cout<<str<<endl;
    // removeX(str);
    // cout<<str;


    // int m;
    // cout<<"Enter a second no:";
    // cin>>m;
    // cout<<multiplicationRec(m,n);
    // cout<<countZero(n);
    // int i;
    // for(i=0;i<10;i++){
    //     fib[i]=-1;
    // }
    // int *arr = new int[n];
    // for(int i=0 ; i<n ; i++){
    //     cin>>arr[i];
    // } 
    // int *ptr=allIndeces(arr,0,x,0,n-1);
    // for(int i=0;i<2;i++){
    //     cout<<ptr[i]<<" ";
    // }
    // int x;
    // cout<<"Enter a Element that you want to search:";
    // cin>>x;
    // TreeRecursion(n);
    // cout<<nestedRecursion(97);
    // cout<<SumOfNaturalNumber(n);
    // cout<<mFibo(n);
    // cout<<is_Sorted(arr, n);
    // cout<<arraySum(arr,n);
    // cout<<searchElement(arr,n,x);
    // cout<<firstIndex(arr,n,x);
    // cout<<lastIndex(arr,n,x);
    // int x;
    // cout<<"Enter the value:";
    // cin>>x;
    // cout<<Power(x,n);

    //  cout<<Count(n);
    // cout<<Fibo(n);
}






