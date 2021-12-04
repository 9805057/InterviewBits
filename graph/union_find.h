class UnionFind {
    public:
        UnionFind(int N) {
            for ( int i = 0 ; i <= N; ++i ) {
                group_size_.push_back(1);
                parent_.push_back(i);
                roots_.insert(i);
            }

            roots_.erase(0);
        }

        // Unites two sets and returns the unique root count. 
        int Unite(int p, int q) {
            int root_p = GetRoot(p);
            int root_q = GetRoot(q);

            if ( group_size_[root_p] < group_size_[root_q] ) {
                parent_[root_p] = root_q;
                group_size_[root_q] += group_size_[root_p];
                roots_.erase(root_p);                
            } else {
                parent_[root_q] = root_p;
                group_size_[root_p] += group_size_[root_q];
                roots_.erase(root_q);                
            }

            return roots_.size();
        }

        // Path compress while returning the root. 
        int GetRoot(int n) {
            while ( n != parent_[n] ) {
                parent_[n] = parent_[parent_[n]];
                n = parent_[n];
            }

            return n;
        }

        // Checks if connected. 
        bool Find(int p, int q) {
            return GetRoot(p) == GetRoot(q);
        }

    private:
        vector<int> group_size_;
        vector<int> parent_;
        unordered_set<int> roots_;
};
