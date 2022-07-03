int max_ending_here = 0;
int max_so_far = 0;
int _start = 0;
int start = 0;
int end = -1;
for (int i = 0; i < int(a.size()); i++) {
    max_ending_here += a[i];
    if (max_ending_here < 0) {
        max_ending_here = 0;
        _start = i + 1;
    }
    if (max_ending_here > max_so_far) {
        max_so_far = max_ending_here;
        start = _start;
        end = i;
    }
}
