#include <stdio.h>

int main()
{
	int n, i;

	printf("%s", "Enter number of elements\n");
	scanf("%d", &n);

	int arr[n];

	printf("Enter the elements: \n");

	//Input elements into the array	
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	merge_sort(arr, 0, n-1); //Calls the merge_sort function

	printf("%s", "Sorted array using merge sort: \n");

	//Prints the array	
	for(i = 0; i < n; i++)
                printf("%d\n", arr[i]);

	return 0;
}

int merge_sort(int arr[], int low, int high)
{
	int mid;

	if(low < high)
	{
		mid = (low + high)/2;

		//recursive calls to continuously divide the array
		merge_sort(arr, low, mid);
		merge_sort(arr, mid+1, high);

		//merges the divided arrays
		merge(arr, low, mid, high);
	}

	return 0;
}

int merge(int arr[], int l, int m, int h)
{
	int i, j, k, n1, n2;
	n1 = m-l+1;
	n2 = h-m;
	long int arr1[n1], arr2[n2];
	
	//Putting elements in the arrays
	for(i = 0; i < n1; i++)
		arr1[i] = arr[l+i];
	
	for(j = 0; j < n2; j++)
                arr2[j] = arr[m+j+1];

	//Using sentinel numbers
	arr1[i] = 999999999;
	arr2[j] = 999999999;

	i = 0;
	j = 0;

	//Comparison
	for(k = l; k <= h; k++)
	{
		if(arr1[i] <= arr2[j])
			arr[k] = arr1[i++];
		else
			arr[k] = arr2[j++];
	}

	return 0;
}
