#include <stdio.h>
#include <stdlib.h>
int gcd(int a,int b);

void leftRotate(int Array[], int rotation, int count)
{
    int i,j,k,temp;
    for(i = 0;i < gcd(rotation,count);i++)
    {
        temp = Array[i];
        j = i;
        while(1)
        {
            k = j + rotation;
            if(k >= count)
            {
                k = k - count;
            }
            if(k == i)
            {
                break;
            }
            Array[j] = Array[k];
            j = k;
        }
        Array[j] = temp;
    }
}

void printArray(int Array[], int count)
{
    int i;
    for(i = 0;i < count;i++)
    {
        printf("%d ", Array[i]);
    }
}
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    int count,rotation,a[100000],Array[100000];
    int val = 0;
    int i = 0;
    int z = -1;
    scanf("%d %d", &count, &rotation);
    while(scanf("%d", &val) == 1 && i++ < count && (a[i] = val) && z++ < count)
        Array[z] = a[i];
    leftRotate(Array, rotation, count);
    printArray(Array, count);
    getchar();
    return 0;
}
