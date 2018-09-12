#include<iostream>
#include<vector>
using std::vector;

typedef void (*sortingAlgo)(vector<int>&);

#ifdef QUICK_SORT
#include"quickSort.hpp"
sortingAlgo sort = quickSort;
#elif INSERT_SORT
#include"insertSort.hpp"
sortingAlgo sort = insertSort;
#elif BUBBLE_SORT
#include"bubbleSort.hpp"
sortingAlgo sort = bubbleSort;
#elif SIMPLE_SORT
#include"simpleSelectSort.hpp"
sortingAlgo sort = simpleSelectSort;
#elif MERGE_SORT
#include"mergeSort.hpp"
sortingAlgo sort = mergeSort;
#endif

bool is_equal(const vector<int>& source, const vector<int>& target);
void testUnorderedOdd();
void testUnorderedEven();
void testInvOdd();
void testInvEven();
void testRepetition();


int main(){
    testUnorderedOdd();
    testUnorderedEven();
    testInvOdd();
    testInvEven();
    testRepetition();
	return 0;
}

bool is_equal(const vector<int>& source, const vector<int>& target){
    if(source.size() != target.size()){
        return false;
    }
    bool ret = true;
    for(int i=0; ret&&i<source.size(); ++i){
        if(source[i] != target[i])
            ret = false;
    }
    return ret;
}

void print_vec(const vector<int>& arr){
    for(int e:arr) std::cout<< "  " << e;
    std::cout<<std::endl;
}

void testUnorderedOdd(){
	std::cout<< "test unordered and odd array" << std::endl;
    vector<int> source = {-1,0,11,-3,10,3,6,7,9};
	vector<int> target = {-3,-1,0,3,6,7,9,10,11};
	sort(source);
    //partition(source, 0, source.size()-1);
	if(is_equal(source, target)){
		std::cout<< "sorting successfully!" << std::endl;
	}
    else{
        std::cout<< "sorting faild!, arr is " << std::endl;
        print_vec(source);
    }
}

void testUnorderedEven(){
	std::cout<< "test unordered and even array" << std::endl;
    vector<int> source = {-1,0,11,-3,10,3,6,7,9,30};
	vector<int> target = {-3,-1,0,3,6,7,9,10,11,30};
	sort(source);
    //partition(source, 0, source.size()-1);
	if(is_equal(source, target)){
		std::cout<< "sorting successfully!" << std::endl;
	}
    else{
        std::cout<< "sorting faild!, arr is " << std::endl;
        print_vec(source);
    }
}

void testInvOdd(){
	std::cout<< "test inverse odd array" << std::endl;
    vector<int> source = {11,10,9,7,6,3,0,-1,-3};
	vector<int> target = {-3,-1,0,3,6,7,9,10,11};
	sort(source);
    //partition(source, 0, source.size()-1);
	if(is_equal(source, target)){
		std::cout<< "sorting successfully!" << std::endl;
	}
    else{
        std::cout<< "sorting faild!, arr is " << std::endl;
        print_vec(source);
    }
}

void testInvEven(){
	std::cout<< "test inverse even array" << std::endl;
    vector<int> source = {11,10,9,7,6,3,0,-1,-3, -10};
	vector<int> target = {-10, -3,-1,0,3,6,7,9,10,11};
	sort(source);
    //partition(source, 0, source.size()-1);
	if(is_equal(source, target)){
		std::cout<< "sorting successfully!" << std::endl;
	}
    else{
        std::cout<< "sorting faild!, arr is " << std::endl;
        print_vec(source);
    }
}

void testRepetition(){
	std::cout<< "test repetition array" << std::endl;
    vector<int> source = {11,10,7,7,3,0,-1,-3,7};
	vector<int> target = {-3,-1,0,3,7,7,7,10,11};
	sort(source);
    //partition(source, 0, source.size()-1);
	if(is_equal(source, target)){
		std::cout<< "sorting successfully!" << std::endl;
	}
    else{
        std::cout<< "sorting faild!, arr is " << std::endl;
        print_vec(source);
    }
}
