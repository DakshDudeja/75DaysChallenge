class Solution {
public:
    int longestValidParentheses(string s) {
	int maxi = 0;  
	stack<int> stk;
	stk.push(-1); 
	for(int i = 0; i < size(s); i++)
		if(s[i] == '(') stk.push(i);            
		else{                
			stk.pop();
			if(stk.empty()) stk.push(i);
			else maxi = max(maxi, i - stk.top());
		}        
	return maxi;
}

};