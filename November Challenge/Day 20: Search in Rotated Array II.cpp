class Solution {
public:
bool search1(vector<int> arr, int l, int h, int key)
{
	if (l > h)
		return false;

	int mid = (l + h) / 2;
	if (arr[mid] == key)
		return false;

	if ((arr[l] == arr[mid]) 
		&& (arr[h] == arr[mid])) 
	{
		++l;
		--h;
	}


	if (arr[l] <= arr[mid]) {

		if (key >= arr[l] && key <= arr[mid])
			return search1(arr, l, mid - 1, key);
		return search1(arr, mid + 1, h, key);
	}
	if (key >= arr[mid] && key <= arr[h])
		return search1(arr, mid + 1, h, key);

	return search1(arr, l, mid - 1, key);
}

    bool search(vector<int>& nums, int t) {
        int l=0,h=nums.size()-1;
        if(l == h)
        {
            if(nums[0] == t)
                return true;
            return false;
        }
        bool ans = search1(nums,0,h,t);
        return ans;
    }
};
