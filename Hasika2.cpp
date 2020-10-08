#include<iostream>

using namespace std;

int main()
{
	int i,j,t,n;

	cout<<"Enter the number of elements"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the values of the elements"<<endl;

	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n-(i+1);j++)
		{
			if(arr[j]>arr[j+1])
			{
				t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}

	for(i=0;i<n;i++)//delete duplicate
	{
		for(j=0;j<n-(i+1);j++)
		{
			if(arr[j]==arr[j+1])
			{
				arr[j]=0;
			}
		}
	}
            
	for(i=0;i<n;i++)
	{
		if(arr[i]!=0 || i==0)
		cout<<arr[i]<<endl;
	}

	return 0;
}
