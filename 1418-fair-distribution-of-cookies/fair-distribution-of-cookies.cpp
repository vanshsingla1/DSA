class Solution {
public:
    int res = INT_MAX;
    void fun(vector<int>& cookies, int k,int i, vector<int> &bags) {
        // take or skip
        if(i == cookies.size()) {
            int unfairness = *max_element(bags.begin(),bags.end());
            res = min(res,unfairness);
            return;
        }
        for(int j=0; j<k; j++) {
            bags[j] += cookies[i];
            fun(cookies,k,i+1,bags);
            bags[j] -= cookies[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        // k that denotes the number of children to distribute all the bags of cookies to.
        // divide the bags into k parts , such that difference between them is minm
        vector<int> bags(k,0);
        fun(cookies,k,0,bags);
        return res;
    }
};