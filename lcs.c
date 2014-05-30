#include<stdio.h>
#include<string.h>

int main()
{
	char s1[100], s2[100];

	printf("Enter 2 strings: \n");
	scanf("%s%s", s1, s2);
	
	printf("Length of the longest common subsequence: %d\n", lcs(s1, s2));
	
	return 0;
}

int lcs(char str1[], char str2[])
{
	int i, j, m, n, lcs_arr[100][100];

	m = strlen(str1);
	n = strlen(str2);

	for(i = 0; i <= m; i++)
	{
		for(j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				lcs_arr[i][j] = 0;

			else if (str1[i-1] == str2[j-1])
				lcs_arr[i][j] = lcs_arr[i-1][j-1]+1;
			else
				lcs_arr[i][j] = max ( lcs_arr[i-1][j], lcs_arr[i][j-1] );	
		}
	}

	return lcs_arr[m][n];
}

int max(int x, int y)
{
	return (x>y?x:y);
}

