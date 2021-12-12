#include <bits/stdc++.h>
using namespace std;
void show(deque<int> g);

int main() {
    // Double ended queues are sequence containers with the feature of expansion and contraction on both the ends.
    // queue from both ends
    deque<int> dq;  //? declare deque
    // They are similar to vectors, but are more efficient in case of insertion and deletion of elements. Unlike vectors, contiguous storage allocation may not be guaranteed.
    dq.push_back(10);  // 10
    show(dq);
    dq.push_front(20);  // 20 10
    show(dq);
    dq.push_back(30);  // 20 10 30
    show(dq);
    dq.push_front(15);  // 15 20 10 30
    show(dq);
    dq.pop_front();  // 20 10 30
    show(dq);
    dq.pop_back();  // 20 10
    show(dq);
    return 0;
}

void show(deque<int> g) {
    for (auto it = g.begin(); it != g.end(); ++it)
        cout << *it << ' ';
    cout << '\n';
}
