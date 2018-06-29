#include<stdio.h>
#include<time.h>

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int l, int r, int a[])
{
  int ir=r,il=l;
  int temp=0;
  int pValue=a[l]; //Pivot Elements Value
  int pIndex=l;
  printf("\nPivot Element is %d and Pivot Index Is %d",pValue,pIndex);
  while(1)
  {
    while(a[l]<=pValue) l++;
    printf("\nl=%d",l);
    while(a[r]>pValue)  r--;
    printf(" r=%d\n",r);
    if(l<r) //swap(&a[l], &a[r]);
    {
      /*a[l]=a[l]+a[r];
      a[r]=a[l]-a[r];
      a[l]=a[l]-a[r];*/
      temp=a[l];
      a[l]=a[r];
      a[r]=temp;
    }
    else  //Swap a[r] and a[pIndex] and return r
    {
      temp=a[pIndex];
      a[pIndex]=a[r];
      a[r]=temp;
      //swap(&a[r], &a[pIndex]);
      return r;
    }
  }
}

/*int partition(int low, int high, int arr[])
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}*/

void quickSort(int l, int r, int a[])
{
  if(l<r)
  {
    int p=partition(l,r,a);
    quickSort(l,p,a);
    quickSort(p+1,r,a);
  }
}

void printArray(int a[], int n)
{
  printf("\nThe Array Is :\n");
  for(int i=0;i<n;i++)  printf(" %d",a[i]);
}

void main()
{
  int arr[]={9,8,7,6,5,4,3,2,1,0};
  int n=sizeof(arr)/sizeof(arr[0]);
  printArray(arr,n);
  quickSort(0,n-1,arr);
  printArray(arr,n);
}
