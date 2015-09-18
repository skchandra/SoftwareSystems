int main ()
{
	int arr[5] = {2, 3, 6, 7, 4};
	int *array;
	int i;

	array = arr;
	for (i = 0; i < 5; i++) {
		printf("%i\n", *(array + i) );
	}
	
	return 0;
}

