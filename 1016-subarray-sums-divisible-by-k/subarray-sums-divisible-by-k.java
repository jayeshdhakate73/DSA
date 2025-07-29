class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        HashMap<Integer,Integer> map = new HashMap<>();
        map.put(0,1);
        int sum = 0 ,res = 0;
        for(int n : nums){
            sum += n;
            int rem = sum % k;
            if(rem<0) rem += k;
            if(map.containsKey(rem)){
                res += map.get(rem);
            }
            map.put(rem,map.getOrDefault(rem,0)+1);
        }
        return res;
    }
}