class Solution {
public:
    string decodeString(string s) {
        stack<int> num_stack;
        stack<string> str_stack;
        string current_str;
        int current_num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                current_num = current_num * 10 + (c - '0');
            } else if (c == '[') {
                num_stack.push(current_num);
                str_stack.push(current_str);
                current_num = 0;
                current_str.clear();
            } else if (c == ']') {
                int k = num_stack.top();
                num_stack.pop();
                string prev_str = str_stack.top();
                str_stack.pop();
                string temp;
                for (int i = 0; i < k; ++i) {
                    temp += current_str;
                }
                current_str = prev_str + temp;
            } else {
                current_str += c;
            }
        }

        return current_str;
    }
};
