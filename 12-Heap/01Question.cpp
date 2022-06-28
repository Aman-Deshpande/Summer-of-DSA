#include <bits/stdc++.h>
using namespace std;

// Max Heap
class Heap
{
public:
    int arr[100];
    int size;

    Heap()
    {
        size = 0;
        arr[0] = -1;
    }

    // insert
    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
            }
            else
            {
                return;
            }
        }
    }

    void deletion()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        // take root to its correct position
        int i = 1;
        while (i < size)
        {
            int left = 2 * i;
            int right = 2 * i + 1;

            if (left < size && arr[i] < arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }
            else if (right < size && arr[i] < arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = (2 * i) + 1;

    if (left < n && arr[i] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[i] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main()
{

    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deletion();
    cout << endl;
    h.print();

    h.deletion();
    cout << endl;
    h.print();

    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = n / 2; i > 0 / 2; i--)
    {
        heapify(arr, n, i);
    }
    cout << "Printing" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Priority Queue - default max heap

    // Max Heap
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    cout << pq.top() << endl;
    cout << "Size " << pq.size() << endl;
    pq.pop();
    cout << pq.top() << endl;
    cout << "Size " << pq.size() << endl;

    // min heap
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);
    cout << minheap.top() << endl;

    return 0;
}