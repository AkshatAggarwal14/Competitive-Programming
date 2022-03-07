#include <bits/stdc++.h>
using namespace std;

// forward declarations
template <class A, class B>
string to_string(pair<A, B> p);
template <class A, class B, class C>
string to_string(tuple<A, B, C> p);
template <class A, class B, class C, class D>
string to_string(tuple<A, B, C, D> p);

// basic
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "T" : "F"); }
string to_string(char ch) {
    string s(1, ch);
    return '\'' + s + '\'';
}

// others
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <class T>
string to_string(queue<T> q) {
    bool first = true;
    string res = "{";
    while (!q.empty()) {
        if (!first) res += ", ";
        first = false;
        res += to_string(q.front());
        q.pop();
    }
    res += '}';
    return res;
}

template <class T>
string to_string(stack<T> q) {
    bool first = true;
    string res = "{";
    while (!q.empty()) {
        if (!first) res += ", ";
        first = false;
        res += to_string(q.top());
        q.pop();
    }
    res += '}';
    return res;
}

template <class T, class U>
string to_string(priority_queue<T, vector<T>, U> q) {
    bool first = true;
    string res = "{";
    while (!q.empty()) {
        if (!first) res += ", ";
        first = false;
        res += to_string(q.top());
        q.pop();
    }
    res += '}';
    return res;
}

template <class T, class = void>
struct is_iterable : std::false_type {};

// this gets used only when we can call std::begin() and std::end() on that type
template <class T>
struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>())), decltype(std::end(std::declval<T>()))> > : std::true_type {};
// Here is a helper:
template <class T>
constexpr bool is_iterable_v = is_iterable<T>::value;

template <class A>
string to_string(A v) {
    assert(is_iterable_v<A>);
    bool first = true;
    string res = "{";
    for (const auto& x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <class A, class B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <class A, class B, class C>
string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }

template <class A, class B, class C, class D>
string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; }

// base case for template recursion when one argument remains
template <class Arg1>
void pretty_print(const char* name, Arg1&& arg1) {
    cerr << name << " = ";
    cerr << "\033[33m" << to_string(arg1) << "\033[39m" << '\n';
}
// recursive variadic template for multiple arguments
template <class Arg1, class... Args>
void pretty_print(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');

    cerr.write(names, comma - names) << " = ";
    cerr << "\033[33m" << to_string(arg1) << "\033[39m";
    pretty_print(comma, args...);
}
#define dbg(...)                        \
    cerr << "\033[34m"                  \
         << "Line " << __LINE__ << ": " \
         << "\033[39m";                 \
    pretty_print(#__VA_ARGS__, __VA_ARGS__)