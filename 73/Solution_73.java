
public class Solution_73 {
    public static void main(String[] args){

    }
    public void setZeroes(int[][] matrix) {
    // 检查空矩阵
    if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
        return;
    }

    int m = matrix.length;        // 行数
    int n = matrix[0].length;     // 列数

    // 标记需要置零的行和列
    boolean[] rows = new boolean[m];
    boolean[] cols = new boolean[n];

    // 第一次遍历：标记所有0元素的位置
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                rows[i] = true;   // 标记该行需要置零
                cols[j] = true;   // 标记该列需要置零
            }
        }
    }

    // 第二次遍历：根据标记置零
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rows[i] || cols[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}

}
