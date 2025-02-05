class Solution {
public:
    string decodeMessage(string key, string message) {

        //step1-> create mapping 
        unordered_map<char,char> mapping;
        char space=' ';
        mapping[space]=space;
        char start='a';
        int index=0;
        
        while(start<='z' && index <key.length()){
            char keykaCurrentChar = key[index];
            //start-> mapping abcd...
            //mapping-> keyCurrentChar -> alphabet
            if(mapping.find(keykaCurrentChar) != mapping.end()){
                //agar current ki mapping already present hai 
                index++;
            }
            else{
                mapping[keykaCurrentChar] = start;
                start++;
                index++;
            }
        }

        //step2 -> decode the mapping
        string ans="";
        for(int i=0; i<message.length(); i++){
            char msgChar=message[i];
            char mappedchar = mapping[msgChar];
            ans.push_back(mappedchar);
        }
        return ans;
    }
};