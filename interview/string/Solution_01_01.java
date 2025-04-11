public class Solution_01_01 {

    public static void main(String[] args){
        String str = "abcdefg";
        System.out.println(isUnique(str));
    }

    public static boolean isUnique(String str){
        // 如果字符串长度超过 26，直接返回 false
        if (str.length() > 26) return false;

        // 使用位图记录字符是否出现过
        int bitmap = 0;

        for (char c : str.toCharArray()){
            // 检查字符是否是小写字母
            if (c < 'a' || c > 'z') {
                throw new IllegalArgumentException("字符串必须由小写字母组成");
            }

            int i = c - 'a';
            // 检查字符是否已经出现过
            if (((bitmap >> i) & 1) == 1) return false;
            // 标记字符为已出现
            bitmap |= 1 << i;
        }

        return true;
    }
}

