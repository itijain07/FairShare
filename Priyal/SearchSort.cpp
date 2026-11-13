
#include <iostream>
using namespace std;

class SearchSort {
private:
    void merge(int arr[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int* L = new int[n1];
        int* R = new int[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];

        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j])
                arr[k++] = L[i++];
            else
                arr[k++] = R[j++];
        }

        while (i < n1)
            arr[k++] = L[i++];

        while (j < n2)
            arr[k++] = R[j++];

        delete[] L;
        delete[] R;
    }

    void mergeSortHelper(int arr[], int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;

        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        return i + 1;
    }

    void quickSortHelper(int arr[], int low, int high) {
        if (low >= high) return;

        int p = partition(arr, low, high);
        quickSortHelper(arr, low, p - 1);
        quickSortHelper(arr, p + 1, high);
    }

public:
    int linearSearch(int arr[], int n, int key) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == key)
                return i;
        }
        return -1;
    }

    int binarySearch(int arr[], int n, int key) {
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == key)
                return mid;

            if (arr[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    void mergeSort(int arr[], int n) {
        if (n > 0)
            mergeSortHelper(arr, 0, n - 1);
    }

    void quickSort(int arr[], int n) {
        if (n > 0)
            quickSortHelper(arr, 0, n - 1);
    }

    void display(int arr[], int n) {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    SearchSort s;

    int expenses[] = {500, 200, 800, 100, 400};
    int n = 5;

    cout << "Original Expense Amounts: ";
    s.display(expenses, n);

    cout << "Linear Search for 800: ";
    cout << s.linearSearch(expenses, n, 800) << endl;

    s.mergeSort(expenses, n);

    cout << "After Merge Sort: ";
    s.display(expenses, n);

    cout << "Binary Search for 400: ";
    cout << s.binarySearch(expenses, n, 400) << endl;

    int expenses2[] = {900, 300, 700, 100, 500};

    s.quickSort(expenses2, n);

    cout << "After Quick Sort: ";
    s.display(expenses2, n);

    return 0;
}
