#include<stdio.h>
void rec_insertion_sort(int arr[],int n);
int ad=0;
main()
{
	int n,ch;
	char c;
	check:
	printf("Enter the size of the array :");
	scanf("%d",&n);
	int a[n];
	printf("Enter the array elements :");
    for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	} 	
	printf("\nOriginal : ");
	for(int i=0;i<n;i++)
	printf("%d\t",a[i]);
	printf("\n\nRecursive : \n");
	rec_insertion_sort(a,n);	
	printf("\n\nDo you want to sort another array? (y/n) ");
	scanf(" %c",&c);
	if(c=='y')
	{
		ad=0;
		goto check;
	}
}

void rec_insertion_sort(int arr[],int n)
{
	if(n<=1)
	{
		printf("\nRecursion 1: \t%d",arr[n-1]);
		return ;
	}
		
	rec_insertion_sort(arr,n-1);
	int l = arr[n-1];
	int t = n-2;
	while (t>=0 && arr[t]>l)
	{
		arr[t+1] = arr[t];
		t--;
	}
	arr[t+1]=l;
	for(int i=n-1;i<n;i++)
	{
	printf("\nRecursion %d: ",i+1);
	for(int k=0;k<=i;k++)
	printf("\t%d",arr[k]);
	}	
}
