#include<stdio.h>

void swap(int *x,int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int participation(int a[],int l,int r)
{
	int p = a[l];
	int i = l;
	int j = r+1;
	while(i<j)
	{
		
		do{
			i++;
		}while(a[i]<=p);
		
		do{
			j--;
		}while (a[j]>p);
		swap(&a[i],&a[j]);
	}
	swap(&a[i],&a[j]);
	swap(&a[l],&a[j]);
	return j;
}

//Î²µÝ¹é
void QuicklySort(int a[],int l,int r)
{
	while(l<r)
	{
		int s = participation(a,l,r);
		QuicklySort(a,l,s-1);
		l = s+1;
	}
}

void main()
{
	int a[10]= {5,3,10,9,8,2,4,7,1,11};
	QuicklySort(a,0,9);
	int i = 0;
	for(i = 0;i<10;i++)
	{
		printf("%d\n",a[i]);
	}
}