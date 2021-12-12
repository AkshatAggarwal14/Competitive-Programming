#include <bits/stdc++.h>
using namespace std;
void show(queue<int> q);

// used in Graph algorithms like BFS.
int main() {
    // Queues -> operate in FIFO manner.
    // Elements are inserted at the back (end) and are deleted from the front.
    queue<int> q;  //? declare empty queue
    q.push(100);
    show(q);
    q.push(120);
    show(q);

    q.pop();
    show(q);
    cout << q.size() << '\n';
    q.push(200);
    q.push(4);
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
