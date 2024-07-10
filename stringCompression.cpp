
//https://leetcode.com/problems/string-compression/

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int ansIndex = 0;
        int n = chars.size();

        while(i < n){
            // to track the next character 
            int j = i + 1;

            //traverse the string until the non equal char formed

            while( j < n && chars[i] == chars[j]){
                j++;
            }

            //poora traverse karliya hoga
            //different character aa gaya hoga
            //1. store karlo character ko

            chars[ansIndex++] = chars[i];

            int count = j - i;

            if(count > 1){
                string cnt = to_string(count);

            for(char ch : cnt){
                chars[ansIndex++] = ch;
            }
            
            }

            i = j;


        }

        return ansIndex;
    }
};
