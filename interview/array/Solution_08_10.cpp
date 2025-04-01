#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class FloodFill {
public:
    vector<vector<int>> floodFillRecursive(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.empty() || image[0].empty()) return image;
        int originalColor = image[sr][sc];
        if (originalColor == newColor) return image;
        dfs(image, sr, sc, originalColor, newColor);
        return image;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.empty() || image[0].empty()) return image;
        int originalColor = image[sr][sc];
        if (originalColor == newColor) return image;

        stack<pair<int, int>> pixels;
        pixels.push({sr, sc});

        while (!pixels.empty()) {
            auto [r, c] = pixels.top();
            pixels.pop();

            if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size()) continue;
            if (image[r][c] != originalColor) continue;

            image[r][c] = newColor;

            pixels.push({r+1, c});
            pixels.push({r-1, c});
            pixels.push({r, c+1});
            pixels.push({r, c-1});
        }
        return image;
    }

private:
    void dfs(vector<vector<int>>& image, int r, int c, int originalColor, int newColor) {
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size()) return;
        if (image[r][c] != originalColor) return;
        image[r][c] = newColor;
        dfs(image, r-1, c, originalColor, newColor);
        dfs(image, r+1, c, originalColor, newColor);
        dfs(image, r, c-1, originalColor, newColor);
        dfs(image, r, c+1, originalColor, newColor);
    }
};

void printSubImage(const vector<vector<int>>& image, int centerRow, int centerCol, int size) {
    int startRow = max(0, centerRow - size/2);
    int endRow = min((int)image.size(), centerRow + size/2 + 1);
    int startCol = max(0, centerCol - size/2);
    int endCol = min((int)image[0].size(), centerCol + size/2 + 1);

    cout << "Showing " << (endRow-startRow) << "x" << (endCol-startCol) 
         << " area around center point (" << centerRow << "," << centerCol << "):\n";
    
    for (int i = startRow; i < endRow; i++) {
        for (int j = startCol; j < endCol; j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    // 创建1000x1000全1图像
    vector<vector<int>> image(1000, vector<int>(1000, 1));
    int sr = 500, sc = 500; // 中心点
    int newColor = 2;

    cout << "Before flood fill:\n";
    printSubImage(image, sr, sc, 10); // 显示中心10x10区域

    FloodFill solver;
    image = solver.floodFill(image, sr, sc, newColor);

    cout << "After flood fill:\n";
    printSubImage(image, sr, sc, 10);

    // 验证整个图像是否都变成了newColor
    bool allFilled = true;
    for (const auto& row : image) {
        for (int pixel : row) {
            if (pixel != newColor) {
                allFilled = false;
                break;
            }
        }
        if (!allFilled) break;
    }
    cout << "Entire image filled: " << (allFilled ? "Yes" : "No") << endl;

    return 0;
}
