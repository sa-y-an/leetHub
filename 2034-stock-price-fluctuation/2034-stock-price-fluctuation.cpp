class StockPrice {
    multiset <int> prices;
    map <int,int> stocks;
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if( stocks.count(timestamp) > 0 ){
            prices.erase(prices.find(stocks[timestamp]));
        }
        prices.insert(price);
        stocks[timestamp] = price;
    }
    
    int current() {
        return (*stocks.rbegin()).second;
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
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