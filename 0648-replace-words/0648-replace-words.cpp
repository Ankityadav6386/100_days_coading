class Solution {
public:
    vector<string> words;
    struct trie{
     trie* childNode[26];
     bool isEnd = false;
     trie(){
    for(int i=0; i<26; i++){
                childNode[i] = nullptr;
            }
        }
    };
    void insert(trie* root, string word){
        trie* curr = root;
        int i=0;
        while(i<word.size()){
            if(curr->childNode[word[i]-'a'] == nullptr){
                curr->childNode[word[i]-'a'] = new trie();
            }
            curr = curr->childNode[word[i]-'a'];
            i++;
        }
        curr->isEnd = true;
    }

    string search(trie* root, string key){
        trie* curr = root;
        string ret = "";
        for(char c:key){
            if(curr->childNode[c-'a'] != nullptr){
                ret += c;
                if(curr->childNode[c-'a']->isEnd == true){
                    return ret;
                }
            }else break;
            curr = curr->childNode[c-'a'];
        }
        if(curr->isEnd == true)
            return ret;
        else return "";
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        string res;
        trie* root = new trie();
        for(string s:dictionary){
            insert(root,s);
        }
        getWords(sentence);
        for(int i=0; i<words.size(); i++){
            if(i<words.size()-1)
                words[i].pop_back();
            string ret = search(root,words[i]);
            if(ret == ""){
                res += words[i] + " ";
            }else{
                res += ret + " ";
            }
        }
        res.pop_back();
        return res;  
    }

    void getWords(string sentence){
        int start = -1;
        for(int i=0; i<sentence.size(); i++){
            if(sentence[i]==' '){
                words.push_back(sentence.substr(start+1,i-start));
                start = i;
            }else if(i==sentence.size()-1){
                words.push_back(sentence.substr(start+1,i-start));
            }
        }
    }
};