class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size();
        vector<int>p(n);
        vector<int>s(n);
        p[0]=-1;
        for(int i=1;i<n;i++){
            p[i]=max(p[i-1],v[i-1]);
        }
        s[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            s[i]=max(s[i+1],v[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int h=max(0,min(p[i],s[i]));
            ans+=max(0,h-v[i]);
        }
        return ans;


        
    }
};