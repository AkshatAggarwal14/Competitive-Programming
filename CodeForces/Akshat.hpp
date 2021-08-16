#include <bits/stdc++.h>
using namespace std;

// namespace Color {
// enum Code {
//     FG_RED = 31,
//     FG_GREEN = 32,
//     FG_YELLOW = 33,
//     FG_BLUE = 34,
//     FG_DEFAULT = 39
// };
// class ColorDebugger {
//     Code code;

//    public:
//     ColorDebugger(Code pCode) : code(pCode) {}
//     template <class T>
//     ColorDebugger& operator<<(const T& other) {
//         cerr << "\033[" << code << "m" << other << "\033[" << FG_DEFAULT << "m";
//         return *this;
//     }
//     ColorDebugger& operator<<(ostream& (*pManip)(ostream&)) {
//         (*pManip)(cerr);
//         return *this;
//     }
// };
// }  // namespace Color

// using namespace Color;
// ColorDebugger ycerr(FG_YELLOW);
// ColorDebugger rcerr(FG_RED);
// ColorDebugger bcerr(FG_BLUE);
// ColorDebugger gcerr(FG_GREEN);

string to_string(string s) {
    return '"' + s + '"';
}
string to_string(char ch) {
    string s(1, ch);
    return '\'' + s + '\'';
}
string to_string(const char* s) {
    return to_string((string)s);
}
string to_string(bool b) {
    return (b ? "true" : "false");
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
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

#define debug(...) cerr << "Line " << __LINE__ << ": ";\
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