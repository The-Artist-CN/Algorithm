class Solution {
public:
	string replaceSpaces(string S, int length) {
		int fillIdx = S.size()-1;
		int i = 0;
		for ( i = length-1; i >= 0; i--) {
			if (S[i] == ' ') {
				S[fillIdx] = '0';
				S[fillIdx - 1] = '2';
				S[fillIdx - 2] = '%';
				fillIdx -= 3;
			}
			else {
				S[fillIdx] = S[i];
				fillIdx--;
			}
		}
		S = S.substr(fillIdx+1);
		return S;
	}
};
