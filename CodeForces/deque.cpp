#include <bits/stdc++.h>
using namespace std;
void show(deque<int> g);

int main() {
    // Double ended queues -> push, pop both ends -> more efficient
    // queue from both ends
    deque<int> dq;     //? declare deque
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
