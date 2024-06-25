// page numvber 13

bool isValidParenthesis(string s)
{
   stack<char> sta;
   for(int i = 0; i< s.length(); i++){
       char ch = s[i];

        //if opening bracket then put it in stack
        if(ch == '(' || ch == '{' || ch == '['){
            sta.push(ch);
        }else{
        //if closing bracket then check in the stack top and pop it up
            if (!sta.empty()) {
              char top = sta.top(); 
              if (  (ch == ')' && top == '(') ||
                    (ch == ']' && top == '[') ||
                    (ch == '}' && top == '{') )
                 {
                sta.pop();
              }
              else {
                return false;
              }

            } else {
              return false;
            }
        }
   }

   if(sta.empty()){
       return true;
   }else{
       return false;
   }
}
