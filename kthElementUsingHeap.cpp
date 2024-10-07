//https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
//page no 93-94
class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq;
        
        int r = arr.size();
        //step : 1
        for(int i = 0; i < k; i++){
            pq.push(arr[i]);
        }
        
        //step : 2
        for(int i = k; i < r; i++ ){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }     
        //step : 3
        return pq.top();
    }
};
