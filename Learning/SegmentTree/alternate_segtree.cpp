#include <bits/stdc++.h>
using namespace std;

class SegTree {
   private:
    int leftmost, rightmost;
    SegTree *lChild, *rChild;
    int sum;

   public:
    SegTree() = default;
    SegTree(int left, int right, vector<int> &arr) {
        this->leftmost = left;
        this->rightmost = right;
        if (left == right) {
            this->sum = arr[left];
            return;
        }
        int mid = (left + right) / 2;
        this->lChild = new SegTree(left, mid, arr);
        this->rChild = new SegTree(mid + 1, right, arr);
        recalculate();
    }

    void recalculate() {
        if (this->leftmost == this->rightmost) return;
        this->sum = this->lChild->sum + this->rChild->sum;
    }

    void pointUpdate(int index, int value) {
        if (this->leftmost == this->rightmost) {
            this->sum = value;
            return;
        }
        if (index <= this->lChild->rightmost) {
            this->lChild->pointUpdate(index, value);
        } else {
            this->rChild->pointUpdate(index, value);
        }
        recalculate();
    }

    int rangeQuery(int left, int right) {
        if (right < this->leftmost || left > this->rightmost) return 0;
        if (left <= this->leftmost && right >= this->rightmost) return this->sum;
        return this->lChild->rangeQuery(left, right) + this->rChild->rangeQuery(left, right);
    }
};