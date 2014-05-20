#include <stdio.h>

int main()
{
        int n, i, inv;

        printf("%s", "Enter number of elements\n");
        scanf("%d", &n);

        int arr[n];

        printf("Enter the elements: \n");

        //Input elements into the array 
        for(i = 0; i < n; i++)
                scanf("%d", &arr[i]);


	inv = merge_sort(arr, 0, n-1); //Calls the merge_sort function

        printf("Total number of inversions: %d\n", inv);
	
	return 0;
}

int merge_sort(int arr[], int low, int high)
{
        int mid, inv_count = 0;

        if(low < high)
        {
                mid = (low + high)/2;

                //recursive calls to continuously divide the array
                inv_count += merge_sort(arr, low, mid);
                inv_count += merge_sort(arr, mid+1, high);

                //merges the divided arrays
                inv_count += merge(arr, low, mid, high);
        }

        return inv_count;
}

int merge(int arr[], int l, int m, int h)
{
        int i, j, k = 0, n1, n2;
	int inv_count = 0;
        
	n1 = m-l+1;
        n2 = h-m;

	i = l;
        j = m+1;
	
	int newArray[100];

	while (1)
	{
		if (arr[i] <= arr[j]) 
		{
			newArray[k] = arr[i];
			i++;
		}
		else
		{
			newArray[k] = arr[j];
			j++;
			inv_count += m-i+1;
		}

		k++;
	
		if (i == l + n1 || j == m + n2 +1)
			break;		
	}

	if (i < l + n1)
	{
		for (; i < l + n1 ; i++) 
		{
			newArray[k] = arr[i];
			k++;
		}
	}
	else if (j < m + n2 + 1)
	{
		for (; j < m + n2 + 1; j++)
		{
			newArray[k] = arr[j]; 
			k++;
		}
	}
	
	for(i = l, k = 0; i <= h; i++, k++)
		arr[i] = newArray[k];

        return inv_count;
}
