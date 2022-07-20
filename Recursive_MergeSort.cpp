#include<stdio.h>
int pass = 1,n;
int a[50];
int MergeSort(int A[],int p,int r);
void Merge(int a[],int p,int q,int r);
void print(int a[]);
void Merge(int a[],int p,int q,int r) 
{
	int n1 = q-p+1; 
    int n2 = r-q;  
    int L[n1], R[n2];
    for(int i=0;i<n1;i++)
    L[i] = a[p+i];
    for(int j=0;j<n2;j++)
	R[j] = a[q+1+j];                                            
    int i=0,j=0,k=p; 
    while(i<n1 && j<n2)
	{
	    if (L[i] <= R[j])
		{
		    a[k] = L[i];
		    i++;
		} 
        else 
        {
        	a[k] = R[j];
        	j++;
        }
    k++;
	}
	while (i<n1) 
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
    print(a);
}
void print(int a[])
{
	printf("\nMerge step %d: ",pass);
    for(int l=0;l<n;l++)
    printf("%d ",a[l]);
    pass++;
}

int MergeSort(int A[],int p,int r)
{
    if(p<r)
	{
		int q=(p+r)/2;
		printf("\n");
		for(int i=p;i<=q;i++)
		printf("%d\t",A[i]);
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
		printf("\n");
		for(int i=q+1;i<=r;i++)
		printf("%d\t",A[i]);
		Merge(A,p,q,r);
	}	
	
}
main()
{
	printf("Enter the size of the array ");
	scanf("%d",&n);
	printf("Enter the array elements ");
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("\nOriginal : ");
	for(int i=0;i<n;i++)
	printf("%d\t",a[i]);
	printf("\n");
	int ad = MergeSort(a,0,n-1); 
	printf("\n\nFinal : ");
	for(int i=0;i<n;i++)
	printf("%d\t",a[i]);
}

