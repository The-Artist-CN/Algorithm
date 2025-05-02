class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>> map = new HashMap<String,List<String>>();
        for (String s : strs){
            char[] ca = s.toCharArray();
            Arrays.sort(ca);
            String key = new String(ca);
            List<String> list = map.getOrDefault(key,new ArrayList<String>());
            list.add(s);
            map.put(key,list);
        }
        return new ArrayList<List<String>>(map.values());
    }
}
