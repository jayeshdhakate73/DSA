class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part)!=string::npos){
            //jab tak string s mai part milega tab tak loop chalega
            s.erase(s.find(part),part.length());
        }
        return s;
    }
};