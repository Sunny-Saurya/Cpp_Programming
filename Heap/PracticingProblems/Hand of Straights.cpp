#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    bool checkSuccessor(vector<int>& hand, int groupSize, int currentIndex){
        int n = hand.size();
        int x = hand[currentIndex];
        hand[currentIndex] = -1;
        int count = 1;
        currentIndex++;

        while(count < groupSize && currentIndex < n){
            if(hand[currentIndex] == (x+1)){
                count++;
                x++;
                hand[currentIndex] = -1;
            }
            currentIndex++;
        }
        if(count == groupSize){
            return true;
        }
        else{
            return false;
        }
    }
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        int n = hand.size();

        if(n % groupSize != 0) return false;
        
        for(int i = 0; i < n; i++){
            if(hand[i] != -1){
                if(checkSuccessor(hand, groupSize, i) == false){
                    return false;
                }
            }
        }
        return true;
    }
};