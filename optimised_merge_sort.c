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

        printf("%s", "Sorted array: \n");

        //Prints the array      
        for(i = 0; i < n; i++)
                printf("%d\n", arr[i]);

        return 0;
}

int merge_sort(int arr[], int low, int high)
{
        int mid;

	//Optimisation 1: Use insertion sort if no. of test cases <= 17
        if(low < high && (high-low+1) > 17) 
        {
                mid = (low + high)/2;

                //recursive calls to continuously divide the array
                merge_sort(arr, low, mid);
                merge_sort(arr, mid+1, high);

                //merges the divided arrays
                merge(arr, low, mid, high);
        }
	else
		insertion_sort(arr, high-low+1);

        return 0;
}

int insertion_sort(int arr[], int n)
{
	int temp, i, j, k, flag = 0;
	
	for(i = 1; i < n; i++)
	{
		temp = arr[i];
		
		for(j = i-1; arr[j] > temp && j >= 0; j--)
		{
			arr[j+1] = arr[j];
		}
		arr[j+1] = temp;

		//Implementing the optimisation
		for(k = 0; k < n-1; k++)
			if(arr[k] > arr[k+1])
				flag = 1;
		
		if(flag == 0)
			return 0;
    	}
	
	return 0;
}

int merge(int arr[], int l, int m, int h)
{
        int i, j, k, n1, n2;
        n1 = m-l+1;
        n2 = h-m;
        long int arr1[n1+1], arr2[n2+1]; //To accommodate for sentinel element

        //Putting elements in the arrays
        for(i = 0; i < n1; i++)
                arr1[i] = arr[l+i];

        for(j = 0; j < n2; j++)
                arr2[j] = arr[m+j+1];

	//Optimisation 2: Last element of 1st array < 1st element of 2nd array
	if(arr1[n1-1] <= arr2[0])
	{
		for(i = l; i <= h; i++)
		{
			if(i < n1)
				arr[i] = arr1[i];
			else
				arr[i] = arr2[i-n1];
		}
		return 0;	
	}

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
