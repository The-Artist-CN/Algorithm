
public class LCS_01 {

    //Using Math
    public int leastMinutes(int n){
        if (n <= 1) return n; // 处理0或1的特殊情况
        
        // 计算log2(n)的整数部分
        int k = (int)(Math.log(n) / Math.log(2));
        
        // 检查2^k是否已经足够
        if ((1 << k) == n) {
            return k + 1;
        } else {
            return k + 2;
        }
    }

    public int leastMinutes_Better(int n){
        if (n==0) return 0;
        return (int) Math.ceil(Math.log(n) / Math.log(2)) + 1;
    }
}
