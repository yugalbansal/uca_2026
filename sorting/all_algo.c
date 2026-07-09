#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selection_sort(int arr[], int n)
{
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void quick_sort_recursive(int arr[], int low, int high)
{
    int pivot, i, j, temp;
    if (low < high)
    {
        pivot = arr[high];
        i = low - 1;
        for (j = low; j < high; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        quick_sort_recursive(arr, low, i);
        quick_sort_recursive(arr, i + 2, high);
    }
}

void quick_sort(int arr[], int n)
{
    quick_sort_recursive(arr, 0, n - 1);
}

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void merge_sort_recursive(int arr[], int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = left + (right - left) / 2;
        merge_sort_recursive(arr, left, mid);
        merge_sort_recursive(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge_sort(int arr[], int n)
{
    merge_sort_recursive(arr, 0, n - 1);
}

void heapify(int arr[], int n, int i)
{
    int largest, left, right, temp;
    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{
    int i, temp;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (i = n - 1; i > 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void generate_random(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        arr[i] = rand() % 100000;
}

void generate_ascending(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        arr[i] = i;
}

void generate_descending(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        arr[i] = n - i;
}

double get_time_ms(clock_t start, clock_t end)
{
    return ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC;
}

int main()
{
    int size;

    srand(time(NULL));

    for (size = 8000; size <= 36000; size += 4000)
    {
        int arr[size];

        generate_random(arr, size);
        // generate_ascending(arr, size);
        // generate_descending(arr, size);

        clock_t start = clock();

        // bubble_sort(arr, size);
        // insertion_sort(arr, size);
        // selection_sort(arr, size);
        // quick_sort(arr, size);
        // merge_sort(arr, size);
        heap_sort(arr, size);

        clock_t end = clock();

        printf("%.3f\n", get_time_ms(start, end));
    }

    return 0;
}