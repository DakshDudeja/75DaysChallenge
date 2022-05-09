class Solution {
public:
    vector<string>keypad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"},ans;
    vector<string> letterCombinations(string digits) {
        if(digits == "") return ans;
        helper(digits,"");
        return ans;
    }
    void helper(string&digits,string comb){
        if(digits.length()==0){
            ans.push_back(comb);
            return;
        }
         char ch = digits[0];
        string code = keypad[ch-'0'];
        string ros = digits.substr(1);
        
        for(int i=0;i<code.length();i++)
            helper(ros,comb+code[i]);
    }
};