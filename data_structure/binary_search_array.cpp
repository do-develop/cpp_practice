#include<iostream>

template<typename T>
int iterativeBS(T arr[], int arrSize, T target);

template<typename T>
int recursiveBS(T arr[], int arrSize, T target);

//overloaded function for recursive call
template<typename T>
int recursiveBS(T arr[], T target, int bottIdx, int topIdx);

int main()
{
    int arraySize = 5;
    char arr[arraySize] = {'e', 'd', 'c', 'b', 'a'};
    //int numArr[arraySize] = {1, 3, 5, 7, 9};

    //display input
    for(int i=0; i<arraySize; ++i)
        std::cout<< arr[i] << ' ';
    std::cout << '\n';

    //look for value
    char valueToSearch = 'a';
    int foundIdx = recursiveBS(arr, arraySize, valueToSearch);

    //int valueToSearch = 7;
    //int foundIdx = recursiveBS(numArr, arraySize, valueToSearch);

    if(foundIdx >= 0)
        std::cout << valueToSearch << " is at " << foundIdx << '\n';
    else
        std::cout << "Value not found\n";

    return 0;

}

//ascending and descending
template<typename T>
int iterativeBS(T arr[], int arrSize, T target)
{
    int bottIdx = 0, midIdx = 0, topIdx = arrSize-1, targetIdx = -1;
    bool found = false;
    bool desc = false;

    if(arr[bottIdx] > arr[topIdx]) //check for descending order
    {
        desc = true;
    }

    while((topIdx>=bottIdx) && (found==false))
    {
        midIdx = (topIdx + bottIdx)/2;
        if(arr[midIdx] == target)
        {
            targetIdx = midIdx;
            found = true;
        }
        else if(arr[midIdx] < target)
        {
            if(desc)
                topIdx = midIdx - 1;
            else
                bottIdx = midIdx + 1;
        }
        else if(arr[midIdx] > target)
        {
            if(desc)
                bottIdx = midIdx + 1;
            else
                topIdx = midIdx - 1;
        }
    }
    return targetIdx;
}

template<typename T>
int recursiveBS(T arr[], int arrSize, T target)
{
    recursiveBS(arr, target, 0, arrSize-1);
}

//overloaded function for recursive call
template<typename T>
int recursiveBS(T arr[], T target, int bottIdx, int topIdx)
{
    bool desc = false;

    if(arr[bottIdx] > arr[topIdx])
    {
        desc = true;
    }

    int midIdx = (topIdx+bottIdx)/2;
    int targetIdx = -1;

    //base condition 1: found target
    if(arr[midIdx] == target)
    {
        targetIdx = midIdx;
        return targetIdx;
    }
    //base condition 2: no more items left to search
    else if (topIdx <= bottIdx)
    {
        return targetIdx;
    }
    else if(target < arr[midIdx])
    {
        if(desc)
            recursiveBS(arr, target, midIdx+1, topIdx);
        else
            recursiveBS(arr, target, bottIdx, midIdx-1);
    }
    else if(target > arr[midIdx])
    {
        if(desc)
            recursiveBS(arr, target, bottIdx, midIdx-1);
        else
            recursiveBS(arr, target, midIdx+1, topIdx);
    }
}
