#include<iostream>
#include<cstdio>
using namespace std;
int max(int a , int b)//return largest of two numbers
{
    return (a>b)?a:b;
}
int knapsack(int value1[],int weight1[],int test1,int limitks1)
{

    int arr[test1+1][limitks1+1];
    int i,w;

    for(i=0;i<=test1;i++)
    {
        for(w=0;w<=limitks1;w++)
        {
            if( w==0 || i==0 )
            {
                arr[i][w]=0;
            }
            else if(weight1[i-1]<=w)
            {
                arr[i][w]= max(value1[i-1] + arr[i-1][w-weight1[i-1]] , arr[i-1][w] );
            }
            else
                arr[i][w]=arr[i-1][w];


        }
    }
    return arr[test1][limitks1];  //returning the last value in array as it will have the largets value in it
}



int main()
{
    int value[501],weight[501],test;
    int limitks;

    scanf("%ld",&limitks);
    scanf("%d",&test);
    for(int i=0;i<test;i++)
    {
        scanf("%d",&value[i]);//value of the unit
        scanf("%d",&weight[i]);//weight of the unit
    }
    printf("%d",knapsack(value,weight,test,limitks));//returning the last value of the array i.e the answer
    return 0;
}
