class Solution {
    public long solution(int w, int h){
        long answer = 0;
        long iw = (long) w;
        long ih = (long) h;
        long extent = iw * ih;
        
        long cut = ((iw+ih)-gcd(iw,ih));
        answer = extent - cut;
        return answer;
    }
    public long gcd(long w, long h) {
        if(h==0){
            return w;
        }
        else
            return gcd(h, w%h);
    }
}