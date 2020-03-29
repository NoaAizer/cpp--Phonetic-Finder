
#include <iostream>
#include <string>
#include<vector>
#include "PhoneticFinder.hpp"

using namespace std;

namespace phonetic {

  std::string toLowerCase(std::string s){
        for (size_t i = 0; i < s.length(); i++)
        {
            s[i] = std::tolower(s[i]);
        }
    return s;
  }

vector<string> split(string str, string token){
  vector<string> result;
    while(str.size()){
        int index = str.find(token);
        
        if(index!=string::npos ){
        
          if(index!=str.size()-1){
            int nextChar= str.find(str.substr(index+1,str.size()));
            if(index!=nextChar){
              result.push_back(str.substr(0,index));
              str = str.substr(index+token.size());
            }
          }
          if(str.size()==0)result.push_back(str);
        }
        else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}

  bool checkWords (std::string wordOrg, std::string wordTextOrg)
  {
  bool flag= true;
  if(wordOrg.size()!=wordTextOrg.size())return false;
  std::string word=toLowerCase(wordOrg);
  std::string wordText=toLowerCase(wordTextOrg);
  for(int i=word.find_first_not_of (' '); i<word.size();++i)
    {
      if(word[i]!=wordText[i]){
        if(word[i] == 'v' || word[i] == 'w'){
          if(wordText[i]!='v' && wordText[i]!='w') flag= false;
        }
        else if(word[i] == 'b' || word[i] == 'f' || word[i] == 'p'){
          if(wordText[i]!='b' && wordText[i]!='f' & wordText[i]!='p') flag= false;
        }
        else if(word[i] == 'c' || word[i] == 'k' || word[i] == 'q'){
          if(wordText[i]!='c' && wordText[i]!='k' & wordText[i]!='q') flag= false;
        }
        else if(word[i] == 'j' || word[i] == 'g'){
          if(wordText[i]!='j' && wordText[i]!='g') flag= false;
        }
        else if(word[i] == 's' || word[i] == 'z'){
          if(wordText[i]!='s' && wordText[i]!='z') flag= false;
        }
        else if(word[i] == 'd' || word[i] == 't'){
          if(wordText[i]!='d' && wordText[i]!='t') flag= false;
        }
        else if(word[i] == 'o' || word[i] == 'u'){
          if(wordText[i]!='o' && wordText[i]!='u') flag= false;
        }
        else if(word[i] == 'i' || word[i] == 'y'){
          if(wordText[i]!='i' && wordText[i]!='y') flag= false;
        }
        else if (word[i]!=wordText[i]) flag=false;
      }
    }
  return flag;
  }

	std::string find(std::string text, std::string word){
    
    std::string *pw=&word;
    std::string *pt=&text;

    if(word.empty()  || (pw == NULL) || (word.find_first_not_of (' ') == std::string::npos))
      throw std::runtime_error {"The "+ text+" is invalid"};
    if(text.empty() || (pt == NULL) || (text.find_first_not_of (' ') == std::string::npos))
      throw std::runtime_error {"The "+ word+" is invalid word"};


    vector<string> wordsFromText = split(text ," ");

    for ( const auto& item : wordsFromText) {
      if(checkWords(word,item))
        return item; 
    }

throw runtime_error("Did not find the word '"+word+"' in the text");

return NULL;
  }

}

