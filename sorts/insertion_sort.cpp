#include <iostream>
#include <vector>


std::vector<int> insertionSort(std::vector<int>& nums){
    if (nums.size() < 2){
        return nums;
    }

    int key;
    for (int i = 1; i < nums.size(); ++i){
        key = nums[i];
        int j = i;
        while (j > 0 && key <= nums[j-1]){
            //the value at j is larger, so it moves 1 down
            nums[j] = nums[j-1];
            --j;
        }
        //we stopped, so the current nums[j] is set to the key
        nums[j] = key;
    }
    
    return nums;
}



int main(){
    //test cases here
    std::vector<int> testAlpha = {1,3,4,5,6,2,34,5,4,64,23,12,43,24,54,3,23,546,745,43};

    auto sortedTestAlpha = insertionSort(testAlpha);
    std::cout << "[";
    for (int i = 0; i < sortedTestAlpha.size(); i++){
        if (i > 0){
            std::cout << ", ";
        }
        
        std::cout<< sortedTestAlpha[i];
    }
    std::cout << "]";



    return 0;
}

