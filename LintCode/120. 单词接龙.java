public class Solution {
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: An integer
     */
    public int ladderLength(String start, String end, Set<String> dict) {
        // write your code here
        if (dict == null) {
            return 0;
        }
        if (start.equals(end)) {
            return 1;
        }
        
        //为了能搜出这个结果，end需在字典中
        dict.add(start);
        dict.add(end);
        
        //BFS搜索每层可能的结果，并比较知否找到end
        Queue<String> queue = new LinkedList<>();
        HashSet<String> set = new HashSet<>();
        queue.offer(start);
        set.add(start);
        
        int length = 1;
        while (!queue.isEmpty()) {
            length++;   //遍历每层可能的结果前计数值加一
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String word = queue.poll();
                //遍历下个单词的所有可能，如果已出现过这个可能则直接跳过，将没出现过的记录下来
                for (String nextWord : getNextWords(word, dict)) {
                    if (set.contains(nextWord)) {
                        continue;
                    }
                    if (nextWord.equals(end)) {
                        return length;
                    }
                    set.add(nextWord);
                    queue.offer(nextWord);
                }
            }
        }
        return 0;
    }
    
    //找到所有可能的结果，看看是不是在字典中有出现，如果出现就记录下来
    // get connections with given word.
    // for example, given word = 'hot', dict = {'hot', 'hit', 'hog'}
    // it will return ['hit', 'hog']
    private ArrayList<String> getNextWords(String word, Set<String> dict) {
        ArrayList<String> nextWords = new ArrayList<>();
        for (char c = 'a'; c < 'z'; c++) {
            for (int i = 0; i < word.length(); i++) {
                if (c == word.charAt(i)) {
                    continue;
                }
                String nextWord = replace(word, i, c);
                if (dict.contains(nextWord)) {
                    nextWords.add(nextWord);
                }
            }
        }
        return nextWords;
    }
    
    // replace character of a string at given index to a given character
    // return a new string
    private String replace(String s, int index, char c) {
        char[] chars = s.toCharArray();
        chars[index] = c;
        return new String(chars);
    }
}