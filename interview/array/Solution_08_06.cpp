#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class First {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        stack<int> source, auxiliary, target;
        
        // 初始化源柱子
        for (int i = A.size() - 1; i >= 0; --i) {
            source.push(A[i]);
        }
        
        // 执行汉诺塔移动
        moveDisks(A.size(), source, target, auxiliary);
        
        // 将结果放回C
        C.clear();
        while (!target.empty()) {
            C.push_back(target.top());
            target.pop();
        }
        
        // 反转顺序使其与输入顺序一致
        reverse(C.begin(), C.end());
        
        // 清空A和B
        A.clear();
        B.clear();
    }
    
private:
    void moveDisks(int n, stack<int>& s, stack<int>& t, stack<int>& a) {
        if (n == 0) return;
        
        // 将n-1个盘子从源柱子移动到辅助柱子
        moveDisks(n - 1, s, a, t);
        
        // 移动最大的盘子到目标柱子
        t.push(s.top());
        s.pop();
        
        // 将n-1个盘子从辅助柱子移动到目标柱子
        moveDisks(n - 1, a, t, s);
    }
};

//Apr 2 8:00PM

class Second {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n = A.size();
        move(n,A,B,C);
    }

    void move(int n , vector<int>& A, vector<int>& B, vector<int>& C){
        if (n==1){
            C.push_back(A.back());
            A.pop_back();
            return;
        }
        move(n-1,A,C,B);
        C.push_back(A.back());
        A.pop_back();
        move(n-1,B,A,C);


    }
};

int main() {
    First f ;
    vector<int> A = {3, 2, 1, 0};  // 从大到小排列，0是最小的盘子
    vector<int> B, C;

    f.hanota(A, B, C);

    cout << "Result in C: ";
    for (int num : C) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
