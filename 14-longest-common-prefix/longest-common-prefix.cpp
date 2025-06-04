class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // firstly we are going to sort the vector of string so that we get the element with longest common prefix together 
        sort(strs.begin(),strs.end());

        // now we are going to check for the prefix from the first and last element of the vector because we will get longest common prefix from all the elements of array from it
        int i=0;string ans = "";
        string start = strs[0];
        string last = strs[strs.size()-1];
        while(i<min(start.size(),last.size())){
            if(start[i]!=last[i]){
                break;
            }
            ans+=start[i];
            i++;
        } 
        return ans;
    }
};