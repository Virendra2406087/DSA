// class Solution {
// public:
// //    void printPermutation(string &s1, int i, vector<string> &ans) {
// //     if (i == s1.size()) {
// //         ans.push_back(s1);
// //         return;
// //     }

// //     unordered_set<char> used;

// //     for (int j = i; j < s1.size(); j++) {
// //         if (used.count(s1[j])){
// //         continue;
// //         } 

// //         used.insert(s1[j]);
// //         swap(s1[i], s1[j]);
// //         printPermutation(s1, i + 1, ans);
// //         swap(s1[i], s1[j]); 
// //     }
// // }


//     bool checkInclusion(string s1, string s2) {
//         if(s1.length() > s2.length()){
//             return false;
//         }
//         vector<string>ans;
//         printPermutation(s1,0,ans);

//         int k = s1.size();

//         for (auto &perm : ans) {
//             for (int i = 0; i <= s2.size() - k; i++) {
//                if (s2.substr(i, k) == perm) {
//                   return true;
//                 }
//             }
//         }
//         return false;
//     }
// };


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        sort(s1.begin(), s1.end());
        int k = s1.size();

        for (int i = 0; i <= s2.size() - k; i++) {
            string temp = s2.substr(i, k);
            sort(temp.begin(), temp.end());

            if (temp == s1) {
                return true;
            }
        }
        return false;
    }
};
