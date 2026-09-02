class Solution {
	public:
	int findSubString(string& str) {
		// code here
		vector<int>freq(26, 0);
		int count = 0;
		for (int i = 0; i<str.size(); i++) {
			if (freq[str[i]-'a'] == 0) {
				count++;
			}
			freq[str[i]-'a']++;
		}
		int timer = 0;
		int ans = INT_MAX;
		int x = 0;
		int first = 0, second = 0;
		vector<int>freq1(26, 0);
		while (first<str.size() && second<str.size()) {
			if (freq1[str[second]-'a'] == 0) {
				freq1[str[second]-'a']++;
				timer++;
				x++;
				second++;
			}
			else {
				freq1[str[second]-'a']++;
				timer++;
				second++;
			}
			while(x==count){
			    freq1[str[first]-'a']--;
			    ans=min(ans,timer);
			    timer--;
			    if(freq1[str[first]-'a']==0){
			        x--;
			    }
			    first++;
			}
		}
		return ans;
	}
};
