class StockPrice {
public:

    int time;
    unordered_map<int,int> list;
    priority_queue<pair<int,int>> maxheap;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;
    
	StockPrice()
	{
        time=0;
	}
	
	void update(int t,int p)
	{
		if(time<t)
        {
            time=t;
        }
        list[t]=p;
        maxheap.push({p,t});
        minheap.push({p,t});
	}
	
	int current()
	{
        return list[time];
	}
	
	int maximum()
	{
		while(1)
        {
            auto [p,t]=maxheap.top();
            if(list[t]!=p)
            {
                maxheap.pop();
            }
            else
            {
                break;
            }
        }
        return maxheap.top().first;
	}
	
	int minimum()
	{
        while(1)
        {
            auto [p,t]=minheap.top();
            if(list[t]!=p)
            {
                minheap.pop();
            }
            else
            {
                break;
            }
        }
        return minheap.top().first;
	}
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */