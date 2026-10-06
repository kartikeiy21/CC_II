class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        int n = s.size();

        for (int targetUnique = 1; targetUnique <= 26; targetUnique++) {
            vector<int> freq(26, 0);

            int left = 0, right = 0;
            int unique = 0;      // chars in window
            int atleastK = 0;    // chars whose freq >= k

            while (right < n) {
                if (unique <= targetUnique) {
                    int idx = s[right] - 'a';

                    if (freq[idx] == 0) unique++;
                    freq[idx]++;

                    if (freq[idx] == k) atleastK++;

                    right++;
                } else {
                    int idx = s[left] - 'a';

                    if (freq[idx] == k) atleastK--;

                    freq[idx]--;

                    if (freq[idx] == 0) unique--;

                    left++;
                }

                if (unique == targetUnique &&
                    unique == atleastK) {
                    ans = max(ans, right - left);
                }
            }
        }

        return ans;
    }
};