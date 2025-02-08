class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int i,j=0,a=0,b=0,n=s.size();
        vector<int>v(2);
        for(i=0;i<n;i++){
            if(a+widths[s[i]-'a']<=100){
                a=a+widths[s[i]-'a'];
            }
            else {
                b++;
                a=widths[s[i]-'a'];
            }
            cout<<a<<endl;
        }
        
        v[0]=b+1;
        v[1]=a;
        return v;
    }
};