#include<stdio.h>
#include<string.h>

int arr[5000][1010];
int size[5000];
char str[1010];

int main()
{
    int t, count = 0, c, d, i, j, k, tt;
    char x;

    memset(arr, -1, 5050000*4); //Minimum bytes set to -1: int_size * 5000 * 1000

    arr[0][0] = 0;
    arr[1][0] = 1;
    size[0] = size[1] = 1;
    for(i = 2; count <= 1000; i++)
    {
       	j = 0;
        c = 0;

        while(arr[i-2][j] != -1)
        {
            d = arr[i-2][j] + arr[i-1][j] + c;
            arr[i][j] = d%10;
            c = d/10;
            j++;
        }

        while(arr[i-1][j] != -1)
        {
            d = arr[i-1][j] + c;
            arr[i][j] = d%10;
            c = d/10;
            j++;
        }

        if(c != 0)
            arr[i][j++] = c;

	//The above code stores fibnacci nos in array in reverse order

        count = j;   //Gives count of no of digits 
        size[i] = j; //Gives size of the fib no.
    }

    scanf("%d", &t);
    scanf("%c", &x);

    c = i;

    while(t--)
    {
        tt = 0;
        scanf("%s", str); 

        int l = strlen(str);

        for(i=0; i<c; i++)
        {
            if(size[i] == l)
            {
                for(j = l-1, k = 0; j >= 0; j--, k++)
                {
                    if(!(arr[i][k] == (str[j]-'0'))) //comparison starts from l-1 as elements 
						     //are stored in reverse order
                        break;
                }

                if(j < 0)
                {
                    tt = 1;
                    break;
                }
            }

            else if(size[i] > l)
                    break;
        }

        if(tt == 0)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}
