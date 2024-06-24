#include <iostream>
#include <vector>
#include <algorithm>


//Iterative Binary Search
int binarySearch(std::vector<int>& nums, int value){
    int low = 0;
    int high = nums.size()-1;
    while (low <= high){
        int midpoint = (low+high)/2;
        if (nums[midpoint] == value){
            return midpoint;
        }
        if (nums[midpoint] > value){
            high = midpoint -1;
        }
        else {
            low = midpoint +1;
        }
    }
    //if the while loop ends, if means we are looking for an index above low and below high, but low > high at this point, so we guarantee it isn't in the sorted vector.
    return -1;
}


//Recursive Binary Search
int recursiveBinarySearch(std::vector<int>&nums, int value, int low, int high){
    if (low > high){
        return -1;
    }
    int mid = (low + high)/2;
    if (nums[mid] == value){
        return mid;
    }
    if (nums[mid] < value){
        return(recursiveBinarySearch(nums, value, mid+1, high));
    }
    else{
        return(recursiveBinarySearch(nums, value, low, mid-1));
    }
}




int main(){
    //test cases here
    std::vector<int> alphaTest = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> betaTest = {3, 5, 12, 3,4, 35, 13, 53, 64, 23, 4, 1, 9, 4, -1, 3, 8, 17, 25, 72, 36, 40};
    std::vector<int> gammaTest = {1,2,3,4};

    std::sort(alphaTest.begin(), alphaTest.end());
    std::sort(betaTest.begin(), betaTest.end());
    std::sort(gammaTest.begin(), gammaTest.end());

    std::vector<std::vector<int>> testVectors = {alphaTest, betaTest, gammaTest};
    int counter = 0;
    for (auto testVector : testVectors){
        std::cout << "Testing new vector: " <<  counter << std::endl;
        std::cout << "Iterative: " << std::endl;
        std::cout << binarySearch(testVector, 5) << std::endl;
        std::cout << binarySearch(testVector, 100) << std::endl;
        std::cout << binarySearch(testVector, -100) << std:: endl;
        std::cout << binarySearch(testVector, 4) << std:: endl;

        std::cout << "Recursive: " << std::endl;
        std::cout << recursiveBinarySearch(testVector, 5, 0, testVector.size()-1) << std::endl;
        std::cout << recursiveBinarySearch(testVector, 100, 0, testVector.size()-1) << std::endl;
        std::cout << recursiveBinarySearch(testVector, -100, 0, testVector.size()-1) << std:: endl;
        std::cout << recursiveBinarySearch(testVector, 4, 0, testVector.size()-1) << std:: endl;
        ++counter;
    }

    return 0;
}

