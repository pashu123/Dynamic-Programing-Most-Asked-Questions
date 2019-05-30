#include<bits/stdc++.h>
using namespace std;


int mincostpath(int arr[3][3],int n,int m)
{
    int table[n][m];

    for(int i = 0; i< n;i++)
    {
        for (int j = 0; j<n; j++)
        {
            if(i ==0 && j == 0)
            {
                table[i][j] = arr[i][j];
            }
            else if(i == 0)
            {
                table[i][j] = arr[i][j] + table[i][j-1]; 
            }
            else if(j == 0)
            {
                table[i][j] = arr[i][j] + table[i-1][j];
            }
            else
            {
                table[i][j] = min(table[i-1][j],table[i][j-1]) + arr[i][j];
            
            }
            
            
        }
    }


    return table[n-1][m-1];

}

int main()
{
    int cost[3][3] = { {1, 2, 3}, 
                      {4, 8, 2}, 
                      {1, 5, 3} }; 

    int ans = mincostpath(cost,3,3);
    cout << ans;
}