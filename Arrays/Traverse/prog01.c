#include<stdio.h>
#include<time.h>

int foundLocation(int item, int arr[], int n)
{
  int left=0, right=n-1, mid=n/2;
  int nOfIterations = 0;
/*  while(left!=mid && right!=mid)
  {
    printf("\n\n%d",++nOfIterations);
    if(arr[mid]==item)  return mid;
    if(arr[mid]>item) right = mid;
    else left = mid;
    mid=(left+right)/2;
  }
  return -1;
*/
  while(left<=right)
  {
    printf("\n\n%d",++nOfIterations);
    if(arr[mid]==item)  return mid;
    if(arr[mid]>item) right = mid-1;
    else left = mid+1;
    mid=(left+right)/2;
  }
  return -1;
}

void printArray(int arr[], int n)
{
  printf("The Array Is : ");
  for(int i=0; i<n; i++)  printf("%d ",arr[i]);
}

void main(int argc, char const *argv[])
{
  int arr[] = {1,3,5,6,8,9,11,15,35,46,58,79};
  int item = 0;
  printArray(arr, sizeof(arr)/sizeof(int));
  printf("Enter The Item To Be Searched : ");
  scanf("%d",&item);
  long double t = clock();
  int location = foundLocation(item, arr, sizeof(arr)/sizeof(int));
  t = clock()-t;
  t=t/CLOCKS_PER_SEC;
  printf("time taken by function = %llfs\n",t);
  location<0 ? printf("\n%d not found", item) : printf("\nThe %d was found at location %d",item,location+1);
}
