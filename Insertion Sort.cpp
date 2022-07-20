#include<stdio.h>
int insertion_sort(int arr[],int n);
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
	printf("\n\nIterative : \n");
	ad=insertion_sort(a,n);
	printf("\nDo you want to sort another array? (y/n) ");
	scanf(" %c",&c);
	if(c=='y')
	{
		ad=0;
		goto check;
	}	
}
int insertion_sort(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		int l = arr[i];
		int t = i-1; 
		while (t>=0 && arr[t]>l)
		{
		arr[t+1] = arr[t];
		t--;
		}
		arr[t+1]=l;
	
		
	printf("\nPass %d: ",i+1);
	for(int l=0;l<=i;l++)
	printf("%d\t",arr[l]);	
    }
	printf("\n\nFinal : ");
	for(int l=0;l<n;l++)
	printf("%d\t",arr[l]);
	ad++;
	return ad;
}


