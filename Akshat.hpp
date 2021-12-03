#include <bits/stdc++.h>
using namespace std;

// forward declarations
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

// basic
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }

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
template <typename A>
string to_string(A v) {
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
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; }

string to_string(char ch) {
    string s(1, ch);
    return '\'' + s + '\'';
}

#define beauty(...) pretty_print(#__VA_ARGS__, __VA_ARGS__)

// base case for template recursion when one argument remains
template <typename Arg1>
void pretty_print(const char* name, Arg1&& arg1) {
    cerr << name << " = ";
    cerr << "\033[33m" << to_string(arg1) << "\033[39m" << '\n';
}
// recursive variadic template for multiple arguments
template <typename Arg1, typename... Args>
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
    beauty(__VA_ARGS__)

#define debug(...)                       \
    cerr << "Line " << __LINE__ << ": "; \
    debug_out(#__VA_ARGS__, __VA_ARGS__)

// base case for template recursion when one argument remains
template <typename Arg1>
void debug_out(const char* name, Arg1&& arg1) {
    cerr << name << " = ";
    cerr << to_string(arg1) << '\n';
}
// recursive variadic template for multiple arguments
template <typename Arg1, typename... Args>
void debug_out(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');

    cerr.write(names, comma - names) << " = ";
    cerr << to_string(arg1);
    debug_out(comma, args...);
}