#include <iostream>
#include <vector>
using namespace std;

class Heap
{
public:
  int arr[100];
  int size = 0;
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
        index = parent;
      }
      else
        return;
    }
  }

  int deletion()
  {
    if (size == 0)
    {
      cout << endl
           << "Heap  is empty" << endl;
      return -1;
    }
    int nodeDel = arr[1];
    swap(arr[1], arr[size]);
    size -= 1;
    int index = 1;
    while (index < size)
    {
      int leftIndex = 2 * index;
      int rightIndex = (2 * index) + 1;

      if ((arr[index] < arr[leftIndex] || arr[index] < arr[rightIndex]) && ((rightIndex) <= size) && ((leftIndex) <= size))
      {
        int swapIndex = arr[leftIndex] > arr[rightIndex] ? (leftIndex) : (rightIndex);
        swap(arr[index], arr[swapIndex]);
        index = swapIndex;
      }
      else
        break;
    }
    return nodeDel;
  }
  void heapify(vector<int> &v, int n, int i)
  {
    int largest = i;
    int leftIndex = 2 * i;
    int rightIndex = (2 * i) + 1;
    if (leftIndex < n && v[largest] < v[leftIndex])
    {
      largest = leftIndex;
    }

    if (rightIndex < n && v[largest] < v[rightIndex])
    {
      largest = rightIndex;
    }

    if (largest != i)
    {
      swap(v[largest], v[i]);
      heapify(v, n, largest);
    }
  }
  void print()
  {
    for (int i = 1; i <= size; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
    return;
  }
};

void heapify(vector<int> &v, int n, int i)
{
  int largest = i;
  int leftIndex = ((2 * i) + 1);
  int rightIndex = ((2 * i) + 2);
  if (v[i] < v[leftIndex] && leftIndex < n)
  {
    largest = leftIndex;
  }
  if (v[i] < v[rightIndex] && rightIndex < n)
  {
    largest = rightIndex;
  }
  if (largest != i)
  {
    swap(v[i], v[largest]);
    heapify(v, n, largest);
  }
}

void heapsort(vector<int> &v, int n)
{
  int length = v.size() - 1;
  for (int i = 0; i < n; i++)
  {
    swap(v[0], v[length]);
    length--;
    heapify(v, length, 0);
  }
}

int main()
{
  Heap h;
  h.insert(10);
  h.insert(20);
  h.insert(5);
  h.insert(30);
  h.insert(15);
  h.print();
  cout << endl
       << h.deletion() << endl;
  h.print();
  vector<int> v = {10, 20, 5, 30, 15};
  int n = v.size();
  for (int i = n / 2; i >= 0; i--)
  {
    h.heapify(v, n, i);
  }
  for (auto it : v)
  {
    cout << it << " ";
  }
  cout << endl;

  heapsort(v, n);
  swap(v[0], v[1]);
  for (auto it : v)
  {
    cout << it << " ";
  }
}