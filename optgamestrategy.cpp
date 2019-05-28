#include <bits/stdc++.h>
using namespace std;


int optimalgamestrat(int* arr, int n)
{
    int table[n][n];
    memset(table, 0, sizeof(table[0][0]) * n * n);

    for(int movement = 0; movement < n; movement++)
    {
        for (int i = 0,j = movement; j < n; i++,j++)
        {
            int x = ((i + 2) <= j) ? table[i + 2][j] : 0; 
            int y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0; 
            int z = (i <= (j - 2)) ? table[i][j - 2] : 0; 

            table[i][j] = max(arr[i] + min(x,y) , arr[j] + min(y,z));
        }
    }

    return table[0][n-1];

}



int main()
{
    int arr1[] = {8,15,3,7};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    printf("%d\n",optimalgamestrat(arr1,n));
}