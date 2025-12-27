class Solution {
public:
    int bestClosingTime(string customers) {
        // N , Y
        // N & shop is open -> penality increases by 1
        // Y & Shop is closed -> penality increases by 1
        // return earliest hour at which shop must be closed to incur a minimum
        // penality Shop is open for hours: 0 to j-1 Shop is closed for hours: j
        // to n-1 keep track of how many Y and N are in the list prefix and
        // suffix arrays of both Y and N
        int n = customers.size();
        vector<int> prey(n);
        vector<int> pren(n);
        vector<int> sufy(n);
        vector<int> sufn(n);
        // prefix calculation
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                prey[i] = prey[i - 1];
                pren[i] = pren[i - 1];
            }
            if (customers[i] == 'Y') {
                prey[i]++;
            } else {
                pren[i]++;
            }
        }
        // suffix calculation
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1) {
                sufy[i] = sufy[i + 1];
                sufn[i] = sufn[i + 1];
            }
            if (customers[i] == 'Y')
                sufy[i]++;
            else
                sufn[i]++;
        }
        int time = 0;
        int pen = 0;
        int minnpen = INT_MAX;
        // calculate hours from 0 to n, at every hour close the shop and find
        // the minimum
        for (int i = 0; i <= n; i++) {
            // close at ith hour, opened upto 0 to j-1 hours
            if (i == 0) {
                // all shops are closed, count Y for n-1th suffix index
                pen = sufy[0];
                if (pen < minnpen) {
                    minnpen = pen;
                    time = i;
                }
            } else if (i == n) {
                // shop is opened for all hours, count N count
                pen = pren[n - 1];
                if (pen < minnpen) {
                    minnpen = pen;
                    time = i;
                }
            } else {
                // open for i-1 hours
                pen = pren[i - 1];
                // close
                pen += sufy[i];
                if (pen < minnpen) {
                    minnpen = pen;
                    time = i;
                }
            }
        }
        return time;
    }
};