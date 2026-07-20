class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "#";
        string encoded;
        for (int i = 0; i < (int)strs.size() - 1; i++) {
            encoded += to_string(strs[i].size());
            encoded += ",";
        }
        encoded += to_string(strs.back().size());
        encoded += "#";

        for (string s : strs) {
            encoded += s;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        if (s == "#") return {};
        istringstream ss_full{s};
        string size_line;
        getline(ss_full, size_line, '#');
        istringstream ss_sizes{size_line};
        
        vector<int> sizes;
        string curr_size;
        while (getline(ss_sizes, curr_size, ',')) {
            sizes.push_back(stoi(curr_size));
        }
        
        vector<string> decodedStrs;
        string message = s.substr((int)ss_full.tellg());
        int start = 0;
        for (int strsize : sizes) {
            decodedStrs.push_back(message.substr(start, strsize));
            start += strsize;
        }

        return decodedStrs;
    }
};
