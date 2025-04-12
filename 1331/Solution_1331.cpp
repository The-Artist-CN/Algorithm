class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return arr; // 处理空数组的情况

        vector<int> backup = arr;
        sort(backup.begin(), backup.end());

        unordered_map<int, int> map;
        int rank = 1;
        for (int i = 0; i < backup.size(); i++) {
            if (map.find(backup[i]) == map.end()) { // 如果当前元素未被映射过
                map[backup[i]] = rank++;
            }
        }

        vector<int> result(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            result[i] = map[arr[i]]; // 使用映射后的序号
        }

        return result;
    }
};
