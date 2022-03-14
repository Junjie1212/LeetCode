/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

示例 1:
输入: "A man, a plan, a canal: Panama"
输出: true
解释："amanaplanacanalpanama" 是回文串

示例 2:
输入: "race a car"
输出: false
解释："raceacar" 不是回文串
*/

/*
验证到length/2就行
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int right = s.length()-1; 
        int left = 0;
        for(int i=0; i<s.length(); i++)
            s[i] = tolower(s[i]);
        while(left < right)
        {
            if( ( isdigit(s[left]) || isalpha(s[left])) && ( isdigit(s[right]) || isalpha(s[right])) )
            {
                if(s[left]!=s[right])
                    return false;
                left++;
                right--;
            }
            else
            {
                if(!isalpha(s[left]) && !isdigit(s[left]))
                    left++;
                if(!isalpha(s[right]) && !isdigit(s[right]))
                    right--;    
            }
        }
        return true;
    }
};
