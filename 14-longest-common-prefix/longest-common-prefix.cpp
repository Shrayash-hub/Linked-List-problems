class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int temp =0;
        
        string ans ="";
        if(strs.size()==0  || strs[0].size()==0 ){
            return ans;
        }
        if(strs.size()==1){
            return strs[0];
        }
        if(strs[0].front()!=strs[1].front()){
            return ans;
        }
        for(int i=0;i<strs.size()-1;i++){
            while(temp<min(strs[i].length(),strs[i+1].length())){
                if(strs[i][temp]==strs[i+1][temp]){
                    ans+=strs[i][temp];
                }
                else{
                    break;
                }
                temp++;
            }
            strs[i+1]=ans;
            temp=0;
            if(i!=strs.size()-2){
                ans="";
            }
        }
        return ans;
        
    }
    
};