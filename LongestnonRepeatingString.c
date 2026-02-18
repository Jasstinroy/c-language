int lengthOfLongestSubstring(char *s) {
    int lastIndex[256];
    
    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1;
    }

    int maxLength = 0;
    int left = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        
        if (lastIndex[s[right]] >= left) {
            left = lastIndex[s[right]] + 1;
        }

        lastIndex[s[right]] = right;

        int currentLength = right - left + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength;
}

