#include <iostream>
using namespace std;

//array of integers to hold values
int arr[20];
int cmp_count = 0; // number of comparasion
int mov_count = 0; // number of data movements
int n;

void input() {
	while (true) {
		cout << "Masukkan panjang element array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum panjang adalah 20" << endl;
	}
	cout << "\n-------------------" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "---------------------" << endl;

	for (int i = 0;i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> arr[i]; 
	}
}
// swap the element at index x with the element at index y
void swap(int x, int y)
{
	int temp;
	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void q_short(int low, int high) {
	int pivot, i, j;
	if (low > high)
		return;
	//Partition the list into two parts
	//once containing elements less that or equal to pivot
	//Gathercpntaining elements greather than pivot

	pivot = arr[low];
	i = low + 1;
	j = high;

	while (i <= j)
	{
		while ((arr[i] <= pivot) && (i <= high))
		{
			i++;
			cmp_count++;
		}
		cmp_count++;
		while ((arr[j] > pivot) && (j >= low))
		{
			j--;
			cmp_count++;
		}
		cmp_count++;
		if (i < j)
		{
			swap(i, j);
			mov_count++;
		}
	}
	if (low < j) {
		swap(low, j);
		mov_count++;
	}
	q_short(low, j - 1);
}
void display()
{
	cout << "\n------------------" << endl;
	cout << "Sorted Array" << endl;
	cout << "--------------------" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\nNumbaer of comparissions: " << cmp_count << endl;
	cout << "Number of data movements" << mov_count << endl;


}
