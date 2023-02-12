#include<iostream>
using namespace std;

int fibo_helper(int *ans ,int n){
    if(n<=1){
        return n;
    }
    if(ans[n]!=-1){
        return ans[n];
    }
    int a = fibo_helper(ans , n-1);
    int b = fibo_helper(ans , n-2);

    ans[n]=a+b;
    return ans[n];
}

int fibo(int n){
    int *ans = new int[n+1];
    for(int i=0 ;i<=n ;i++){
        ans[i]=-1;
    }
    return fibo_helper(ans , n);
}

int fibo_2(int n){
    int *ans = new int[n+1];
    for(int i=0 ;i<=n ;i++){
        ans[i]=-1;
    }
    ans[0]=0;
    ans[1]=1;
    for(int i=2;i<=n;i++){
        ans[i]=ans[i-1]+ans[i-2];
    }
    return ans[n];
}

int min_step(int n){
    if(n<=1){
        return 0;
    }
    int x = min_step(n-1);
    int y = INT32_MAX;
    int z = INT32_MAX;

    if(n%2==0){
        y=min_step(n/2);
    }
    if(n%3==0){
        z=min_step(n/3);
    }
    int ans = min(x, min(y,z));
    return ans;
}


int minStepHelper(int *ans , int n){
    if(n<=1){
        return 0;
    }
    if(ans[n]!=-1){
        return ans[n];
    }
    int x = minStepHelper(ans,n-1);
    int y = INT32_MAX;
    int z = INT32_MAX;
    if(n%2==0){
     y = minStepHelper(ans,n/2);
    }
    if(n%3==0){
        z=minStepHelper(ans,n/3);
    }
    int output = min(x,min(y,z))+1;

    ans[n]=output;
    return output;
}

int minStep(int n){
    int *ans = new int[n+1];
    for(int i=0 ;i<n ;i++){
        ans[i]=-1;
    }
    minStepHelper(ans,n);
}

int countSteptoOne(int n){
    int *ans = new int[n+1];
    for(int i=2 ;i<n ;i++){
        ans[i]=-1;
    }
    ans[0]=0;
    ans[1]=1;
    for(int i=2;i<n;i++){
        int x=ans[i-1];
        int y=INT32_MAX;
        int z=INT32_MAX;
        if(i%2==0){
            y=ans[i/2];
        }if(i%3==0){
            z=ans[i/3];
        }
        ans[i]=1+min(x,min(y,z));
    }
    int output = ans[n];
    return output;
}

int minCostPath(int **input , int m ,int n , int i , int j){
    if(i == m-1 && j == n-1){
        return input[i][j];
    }
    if(i>m-1 || j>n-1){
        return INT32_MAX;
    }

    int x = minCostPath(input , m , n , i+1 , j);
    int y = minCostPath(input, m , n, i , j+1);
    int z = minCostPath(input, m , n, i+1 , j+1);

    int ans = min(x,min(y,z)) + input[i][j];
    return ans;
}

int minCostPath_memo(int **input , int m ,int n , int i , int j, int **output){
    if(i == m-1 && j == n-1){
        return input[i][j];
    }
    if(i>m-1 || j>n-1){
        return INT32_MAX;
    }

    if(output[i][j]!=-1){
        return output[i][j];
    }

    int x = minCostPath_memo(input , m , n , i+1 , j,output);
    int y = minCostPath_memo(input, m , n, i , j+1,output);
    int z = minCostPath_memo(input, m , n, i+1 , j+1 ,output);

    int ans = min(x,min(y,z)) + input[i][j];

    output[i][j] = ans;
    return ans;
}

int minCostPath_DP(int **input , int m , int n){
    int **output = new int*[m];
    for(int i=0 ; i<m ;i++){
        output[i] = new int[n];
    }

    //fill last cell
    output[m-1][n-1] = input[m-1][n-1];

    //fill the last row from right to left
    for(int j = n-2 ; j>=0 ;j--){
        output[m-1][j] = output[m-1][j+1]+input[m-1][j];
    }

    //fill last column bottom to top

    for(int i = m-2 ; i>=0 ; i--){
        output[i][n-1]=output[i+1][n-1]+input[i][n-1];
    }

    //fill remaining cells
    for(int i = m-2 ; i>=0 ;i--){
        for(int j = n-2 ; j>=0 ; j--){
            output[i][j] = min(output[i+1][j],min(output[i+1][j+1],output[i][j+1]));
        }
    }
    return output[0][0];
}

int lcs(string s , string t){
    if(s.size()==0 || t.size()==0){
        return 0;
    }
    if(s[0] == t[0]){
        return 1+ lcs(s.substr(1), t.substr(1));
    }else{
        int a = lcs(s.substr(1),t);
        int b = lcs(s,t.substr(1));
        int c = lcs(s.substr(1),t.substr(1));

        return max(a,max(b,c));
    }
}

int minCostPath(int **input , int m , int n){
    return minCostPath(input , m , n , 0 , 0);;
}

int main(){

}