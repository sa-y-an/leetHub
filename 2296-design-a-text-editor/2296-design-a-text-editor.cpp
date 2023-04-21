class TextEditor {
  string editor;
  string store;
  int lst;
public:
    TextEditor() {
      lst = -1;
    }
    
    void addText(string text) {
      
      editor += text;
      lst += text.size();

    }
    
    int deleteText(int k) {
      
      int n = min(lst+1,k);
      int ret = n;
      while(n-- && editor.size() > 0 )
        editor.pop_back(), lst--;

      return ret;
    }
    
    string cursorLeft(int k) {
      
      for( int i = 0 ; i < k and editor.size() > 0 ; i++){
        char ch = editor.back();
        editor.pop_back();
        store.push_back(ch);
        lst--;
      }
      
      int n = editor.size();
          
      string ans;
      for( int i = lst ; i > lst-10 and i >= 0 and i < n ; i--)
        ans.push_back(editor[i]);
      
      reverse(ans.begin(),ans.end());
      return ans;
      
    }
    
    string cursorRight(int k) {
      
      while( k-- and store.size() != 0 ){
        editor += store.back();
        store.pop_back();
        lst++;
      }

      int n = editor.size();
      
      string ans;
      for( int i = lst ; i > lst-10 and i >= 0 and i < n ; i--)
        ans.push_back(editor[i]);
      
      reverse(ans.begin(),ans.end());
      return ans;
      
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */