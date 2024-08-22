#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int findmindistance(int arr[],int n,int x,int y)
{
    int min_dist=INT_MAX;
    int prev_x=-1,prev_y=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            prev_x=i;
        }
        else if(arr[i]==y)
        {
            prev_y=i;
        }
        if(prev_x!=-1 && prev_y!=-1)
        {
            int dist=abs(prev_x-prev_y);
            if(dist<min_dist)
            {
                min_dist=dist;
        }

    }
    return (min_dist==INT_MAX)?-1:min_dist;
}
}
int main()
{
    int arr[]={3,5,4,2,6,5,6,6,5,4,8,3};
    int x=3;
    int y=6;
    int dist=findmindistance(arr,sizeof(arr)/sizeof(arr[0]),x,y);
    if(dist!=-1)
    {
        printf("minimum distance between %dand %d is %d \n",x,y,dist);

    }
    else
    {
        printf("minimum distance between %d and %d is not possible \n",x,y);
    }
    return 0;
}