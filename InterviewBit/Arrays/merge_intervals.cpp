/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> answer;
    int n = intervals.size();
    
    if(n == 0)
    {
        answer.push_back(newInterval);
        return answer;
    }
    
    vector<Interval>::iterator it = intervals.begin();
    
    while(((*it).end < newInterval.start)&&(it != intervals.end()))
    {
        answer.push_back(*it);
        it++;
    }
    
    int left;
    if(it != intervals.end())
    {
        left = min((*it).start,newInterval.start);
    }
    else
    {
        left = newInterval.start;
    }
    
    while((*it).start <= newInterval.end&&(it != intervals.end()))
    {
        it++;
    }
    
    int right;
    if(it != intervals.begin())
    {
        right = max(newInterval.end,(*(it-1)).end);    
    }
    else
    {
        right = newInterval.end;
    }
    
    
    answer.push_back(Interval(left,right));
    
    while(it != intervals.end())
    {
        answer.push_back(*it);
        it++;
    }
    
    return answer;
}
