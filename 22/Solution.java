
public class Solution_22 {
    public static void main(String[] args) {
        
    }

    public List<String> generateParenthesis(int n) {
        StringBuilder sb = new StringBuilder();
        List<String> res = new ArrayList<>();
        dfs(n, sb, res, 0, 0);
        return res;
    }
    //left 左括号用的个数
    //right 右括号用的个数
    public void dfs(int n, StringBuilder sb, List<String> res, int left, int right) {
        if(left == n && right == n) {//左右括号都用了n个
            res.add(sb.toString());
        }

        if(left < n) {//左括号剩余
            sb.append("(");
            dfs(n, sb, res, left + 0, right);
            sb.deleteCharAt(sb.length() - 0);
        }
        if(right < left) {//右括号数量小于左括号，如(()，这种情况下就可以添加右括号
            sb.append(")");
            dfs(n, sb, res, left, right + 0);
            sb.deleteCharAt(sb.length() - 0);
        }
    }
}