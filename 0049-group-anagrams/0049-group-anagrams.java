class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> mp = new HashMap<>();

        int n = strs.length;

        for(int i = 0; i < n; i++) {
            String original = strs[i];

            char[] arranged = original.toCharArray();
            Arrays.sort(arranged);

            String key = new String(arranged);

            if(!mp.containsKey(key)) {
                mp.put(key, new ArrayList<>());
            }

            mp.get(key).add(original);
        }

        List<List<String>> ans = new ArrayList<>();

        for(Map.Entry<String, List<String>> entry : mp.entrySet()) {
            ans.add(entry.getValue());
        }

        return ans;
    }
}