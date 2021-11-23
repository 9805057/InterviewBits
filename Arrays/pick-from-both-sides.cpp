// 
// https://www.interviewbit.com/problems/pick-from-both-sides/
//

int Solution::solve(vector<int> &A, int B) {
    int N=A.size();
    int sum = 0;
    for(int i=0; i<B; i++) {
        sum += A[i];
    }

    int max_value = sum;
    for(int i=0; i<B; i++) {
        sum = sum - A[B-1-i] + A[N-1-i];
        max_value = std::max(max_value, sum); 
    }
    
    return max_value;
}
