import java.util.Arrays;

public class Solution {

    public int eraseOverlapIntervals(int[][] intervals) {
        int res = 0, bond = Integer.MIN_VALUE;
        Arrays.sort(intervals, (a, b) -> a[1] - b[1]);
        for (int i = 0; i < intervals.length; i++) {
            if (bond <= intervals[i][0]) {
                bond = intervals[i][1];
            } else {
                res++;
            }
        }
        return res;
    }
}