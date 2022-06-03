// Best Time to Buy and Sell Stock

// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int leastSofar = INT_MAX; // least price so far
        int totalProfit = 0; // total profit
        int profitOngivenDay = 0; // profit if sold on a given day
        
        for(int i = 0; i<prices.size(); i++){
            if(prices[i] < leastSofar){
                leastSofar = prices[i];
            }
            
            profitOngivenDay = prices[i]-leastSofar;
            if(totalProfit < profitOngivenDay){
                totalProfit = profitOngivenDay;
            }
        }
        
        return totalProfit;
    }
}; 