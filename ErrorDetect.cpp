#include<iostream>
#include<stack>
#include<set>
using namespace std;

int main() {
    string code;
    stack<char> braces;
    set<string> identifiers;
    
    cout << "Eter the code:\n";

    while(true)
     {
        getline (cin,  code);
        if (code == "END") break;
         
        for (char ch:code) {
            if (ch == '{') {
               braces.push(ch);
               }
                  else if (ch == '}') 
               {
                  if (braces.empty())
               { 
                  cout << "Errors: Unmatched closing brace'}'\n";
               } else {
              braces.pop();
            }
          }
        }

     string word;
     for(int i = 0; i<code.size();i++) {
       if(isalpha (code[i])) {
          word = "";
          while(i<code.size()&& isalnum(code[i])) {
          word += code[i];
            i++;
         }

     if(word != "int"&& word != "float" && word!= "double") {
         if (identifiers .count(word)) {
          cout<< "Errors: Duplicate idetifiers= " << word << endl;
           } else {
             identifiers.insert(word);
           }
         }
        }
      }
    }

    if(!braces.empty())
     {
        cout<<"Errors: unbalamced braces '{ }'\n";
    }

    cout << "check fiished.\n";
    return 0;
}