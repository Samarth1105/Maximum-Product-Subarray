class Solution{
public:

	long long maxProduct(vector<int> arr, int n) {
	    
    	long long max_prod = LLONG_MIN;
        long long min_prod = 1, max_ending_here = 1;
    
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                
                max_ending_here = 1;
                min_prod = 1;
                max_prod = std::max(max_prod, 0LL);
              //0LL represents 0 as long long int
              //1LL represents 1 as long long int
            } else {
                long long temp = max_ending_here * arr[i];
                max_ending_here = max({arr[i] * max_ending_here, arr[i] * min_prod, (long long)arr[i]});
                min_prod = min({temp, arr[i] * min_prod, (long long)arr[i]});
                max_prod = max(max_prod, max_ending_here);
            }
        }
    
        return max_prod;
	}
};
