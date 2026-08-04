class KthLargest {
public:
    priority_queue<int> pq;
    int num;
    KthLargest(int k, vector<int>& nums) {
        for(int i : nums)
            pq.push(i);
        num = k;
    }

    int add(int val) {
        pq.push(val);

        priority_queue<int> temp = pq;

        for (int i = 1; i < num; i++) {
            temp.pop();
        }

        return temp.top();
    }
};