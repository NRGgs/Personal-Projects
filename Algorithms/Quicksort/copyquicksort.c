void	swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
	// return (arr);
}

int	choose_pivot(int *arr, int left, int right)
{
	int middle = (right - left) / 2 + left;
	int	a = arr[left];
	int	b = arr[middle];
	int	c = arr[right];

	if ((a <= b) && (b <= c))
		return (middle);
    if ((a <= c) && (c <= b))
		return (right);
    if ((b <= a) && (a <= c))
		return (left);
    if ((b <= c) && (c <= a))
		return (right);
    if ((c <= a) && (a <= b))
		return (left);
    return (middle);
}

//	Sort an integer array according to the quicksort algorithm.
//	(Hoare's Partition)
//
//	int *arr:	Array to be sorted
//	int	left:	Leftmost index
//	int	right:	Rightmost index
void	quicksort(int *arr, int left, int right)
{
	if (left >= right)
		return ;
	int	pivot = choose_pivot(arr, left, right);
	swap(arr, pivot, right);
	int pivotvalue = right;
	int	item_left = left;
	int	item_right = right - 1;

	while (item_left <= item_right)
	{
		while (arr[item_left] <= arr[pivotvalue] && item_left < right)
			item_left++;
		while (arr[item_right] > arr[pivotvalue] && item_right >= left)
			item_right--;
		if (item_left <= item_right)
			swap(arr, item_left, item_right);
	}
	swap(arr, item_left, pivotvalue);

	quicksort(arr, pivot + 1, right);
	quicksort(arr, left, pivot);
}
