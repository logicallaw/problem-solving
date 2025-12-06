#include <iostream>
using namespace std;
void selection_sort(int nums[], const int& size);
void printNums(int nums[], const int& n);

int main(void){
    int size;
    cin >> size;

    int nums[1000];
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i{ 0 }; i < size; i++){
        cin >> nums[i];
    }

    //selection_sort 실행합니다.
    selection_sort(nums, size);

    //출력합니다.
    printNums(nums, size);
}

void selection_sort(int nums[], const int& SIZE){
    int indexMin;
    for (int i{ 0 }; i < SIZE - 1; i++){
        indexMin = i;
        for (int j{ i + 1 }; j < SIZE; j++){
            if (nums[j] < nums[indexMin]){
                indexMin = j;
            }
        }
        int temp = nums[indexMin];
        nums[indexMin] = nums[i];
        nums[i] = temp;
    }
}


void printNums(int nums[], const int& n){
    for (int i{ 0 }; i < n; i++)
        printf("%d\n", nums[i]);
}