#pragma once
/*
Given two arrays of length m and n with digits 0-9 representing two numbers.
Create the maximum number of length k <= m + n from digits of the two. 
The relative order of the digits from the same array must be preserved. 
Return an array of the k digits. You should try to optimize your time and space complexity.
Example 1:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
return [9, 8, 6, 5, 3]
Example 2:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
return [6, 7, 6, 0, 4]
Example 3:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
return [9, 8, 9]
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
http://www.cnblogs.com/CarryPotMan/p/5384172.html
http://blog.csdn.net/u012848330/article/details/51233332
*/
class Create_Maximum_Number {
public:
	vector<int> maxNumber(vector<int>&nums1, vector<int>&nums2, int k)
	{
		vector<int> result;
		
		return result;
	}
};