#include <iostream>
#include <vector>
using namespace std;

// -----------------------------
// Linked List Section
// -----------------------------
struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void addToLinkedList(int value) {
    Node* newNode = new Node{value, nullptr};

    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

void showLinkedList() {
    Node* temp = head;
    cout << "Linked List: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// -----------------------------
// Merge Sort
// -----------------------------
void merge(vector<int>& array, int left, int mid, int right) {
    vector<int> leftPart(array.begin() + left, array.begin() + mid + 1);
    vector<int> rightPart(array.begin() + mid + 1, array.begin() + right + 1);
    
    int i = 0, j = 0, k = left;

    while (i < leftPart.size() && j < rightPart.size()) {
        if (leftPart[i] <= rightPart[j])
            array[k++] = leftPart[i++];
        else
            array[k++] = rightPart[j++];
    }

    while (i < leftPart.size()) array[k++] = leftPart[i++];
    while (j < rightPart.size()) array[k++] = rightPart[j++];
}

void mergeSort(vector<int>& array, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}

// -----------------------------
// Quick Sort
// -----------------------------
int partition(vector<int>& array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return i + 1;
}

void quickSort(vector<int>& array, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);
        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

// -----------------------------
// Binary Search
// -----------------------------
int binarySearch(vector<int>& array, int target) {
    int low = 0, high = array.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (array[mid] == target)
            return mid;
        else if (array[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// -----------------------------
// Main Function
// -----------------------------
int main() {
    vector<int> numbers;
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Add numbers to Linked List\n";
        cout << "2. Show Linked List\n";
        cout << "3. Enter numbers for Sorting/Search\n";
        cout << "4. Sort using Merge Sort\n";
        cout << "5. Sort using Quick Sort\n";
        cout << "6. Search in Sorted Array (Binary Search)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int count, value;
                cout << "How many values do you want to insert? ";
                cin >> count;

                for (int i = 0; i < count; i++) {
                    cout << "[" << i << "] = ";
                    cin >> value;
                    addToLinkedList(value);
                }
                cout << "Values added to Linked List.\n";
                break;
            }

            case 2:
                showLinkedList();
                break;

            case 3: {
                int n, value;
                cout << "How many numbers? ";
                cin >> n;
                numbers.clear();
                cout << "Enter the numbers:\n";
                for (int i = 0; i < n; i++) {
                    cout << "[" << i << "] = ";
                    cin >> value;
                    numbers.push_back(value);
                }
                break;
            }

            case 4:
                if (numbers.empty()) {
                    cout << "No numbers entered. Please use option 3 first.\n";
                } else {
                    mergeSort(numbers, 0, numbers.size() - 1);
                    cout << "Sorted using Merge Sort: ";
                    for (int num : numbers)
                        cout << num << " ";
                    cout << endl;
                }
                break;

            case 5:
                if (numbers.empty()) {
                    cout << "No numbers entered. Please use option 3 first.\n";
                } else {
                    quickSort(numbers, 0, numbers.size() - 1);
                    cout << "Sorted using Quick Sort: ";
                    for (int num : numbers)
                        cout << num << " ";
                    cout << endl;
                }
                break;

            case 6:
                if (numbers.empty()) {
                    cout << "Please enter and sort numbers first.\n";
                } else {
                    int searchValue;
                    cout << "Enter value to search: ";
                    cin >> searchValue;
                    int index = binarySearch(numbers, searchValue);
                    if (index != -1)
                        cout << "Found at index: " << index << endl;
                    else
                        cout << "Not found!\n";
                }
                break;

            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
