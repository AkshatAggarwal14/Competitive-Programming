#include <bits/stdc++.h>
using namespace std;
void show(queue<int> q);

// used in Graph algorithms like BFS.
int main() {
    // Queues -> operate in FIFO manner.
    // Elements are inserted at the back (end) and are deleted from the front.
    queue<int> q;  //? declare empty queue
    q.push(100);
    show(q);  // 100
    q.push(120);
    show(q);  // 100 120

    q.pop();
    show(q);  // 120
    cout << q.size() << '\n';
    q.push(200);
    q.push(4);  // 120 200 4
    cout << q.front() << ' ' << q.back() << '\n';
    return 0;
}

void show(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << '\n';
}
