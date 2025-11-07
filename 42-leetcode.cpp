class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> leftmax(n);
        vector<int> rightmax(n);

        // Compute left max for each element
        leftmax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftmax[i] = max(leftmax[i - 1], height[i]);
        }

        // Compute right max for each element
        rightmax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightmax[i] = max(rightmax[i + 1], height[i]);
        }

        // Calculate total trapped water
        int volume = 0;
        for (int i = 0; i < n; i++) {
            volume += min(leftmax[i], rightmax[i]) - height[i];
        }

        return volume;
    }
};