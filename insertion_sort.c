#include <stdio.h>

void insertion_sort(int * , int );

int main() 
{
    int a[250], n, i;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    
    //INPUT
    printf("Enter %d integers\n", n);
 
    for (i = 0; i < n; i++) 
    scanf("%d", &a[i]);
  
    insertion_sort(a, n);

    //OUTPUT
    printf("Sorted array is as follows\n");

    for (i = 0; i < n; i++)
    printf("%d\n", a[i]);    

    return 0;
}

void insertion_sort(int *a, int n) 
{
    int i, k;
    int temp;

    for (i = 1; i < n; i++)
    {
        for (k = i; k > 0; k--) 
        {
		if( a[k] < a[k-1] )
		{
			temp = a[k];
			a[k] = a[k-1];
			a[k-1] = temp;	
		}
		else
			break;	//Initial part of the array is sorted. Avoids unnecesssary comparisons.	
	}       
     }
}
