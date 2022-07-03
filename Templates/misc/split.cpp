
// splits a std::string into vector<string> at a delimiter
vector<string> split(const string &s, const string &delims = " ") {
    vector<string> res;
    string token = "";
    ll n = s.size();
    for (ll i = 0; i < n; ++i) {
        while (delims.find(s[i]) != string::npos) {
            res.push_back(token);
            token = "";
            ++i;
        }
        token += s[i];
    }
    if (token != "") res.push_back(token);
    return res;
}
