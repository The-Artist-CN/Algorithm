


public class Solution_42 {
    public static void main(String[] args){

        int[] height = {0,1,0,2,1,0,1,3,2,1,2,1};

        System.out.println(new Solution_42().trap(height)); // Should output 6
    }

    public int trap(int[] height){
        int n = height.length;

        int m = getMax(height);

        int sum = 0;

        for (int i = 1 ; i <= m ; i++){
            boolean isStart = false;
            int temp_sum = 0;
            for (int j = 0 ; j < n ; j++){
                if (isStart && i > height[j]){
                    temp_sum++;
                }
                if (height[j] >= i){
                    sum += temp_sum;
                    temp_sum = 0;
                    isStart = true;
                }
            }
        }

        return sum;
    }
    
    public int getMax(int[] nums){
        int res = 0;
        for (int i = 0 ; i < nums.length ; i++){
            res = Math.max(res,nums[i]);
        }
        return res;
    }
    public int trap_Optimize(int[] height) {
        if (height == null || height.length == 0) return 0;

        int left = 0, right = height.length - 1;
        int leftMax = height[left], rightMax = height[right];
        int water = 0;

        while (left < right) {
            if (leftMax < rightMax) {
                left++;
                leftMax = Math.max(leftMax, height[left]);
                water += leftMax - height[left];
            } else {
                right--;
                rightMax = Math.max(rightMax, height[right]);
                water += rightMax - height[right];
            }
        }
        return water;
    }

    public int trap_Stack(int[] height) {
        int sum = 0;
        Stack<Integer> stack = new Stack<>();
        int current = 0;
        while (current < height.length) {
            //如果栈不空并且当前指向的高度大于栈顶高度就一直循环
            while (!stack.empty() && height[current] > height[stack.peek()]) {
                int h = height[stack.peek()]; //取出要出栈的元素
                stack.pop(); //出栈
                if (stack.empty()) { // 栈空就出去
                    break; 
                }
                int distance = current - stack.peek() - 1; //两堵墙之前的距离。
                int min = Math.min(height[stack.peek()], height[current]);
                sum = sum + distance * (min - h);
            }
            stack.push(current); //当前指向的墙入栈
            current++; //指针后移
        }
        return sum;
    }

}
