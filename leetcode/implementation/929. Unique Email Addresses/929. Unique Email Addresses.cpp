using pss = pair<string,string>;

class Solution {
public:
    pss getLocalAndDomainName(string &email) {
        string localName, domainName;
        auto idx = email.find('@');
        return {email.substr(0, idx), email.substr(idx)};
    }

    string getFilteredName(string localName) {
        string filtered;
        for(auto c : localName) {
            if(c == '+') return filtered;
            if(c == '.') continue;
            filtered += c;
        }
        return filtered;
    }

    void filterEmails(vector <string> &emails) {
        for(auto &e : emails) {
            pss localAndDomainName = getLocalAndDomainName(e);
            e = getFilteredName(localAndDomainName.first) + localAndDomainName.second;
        }
    }

    int numUniqueEmails(vector<string>& emails) {
        filterEmails(emails);
        map <string,int> m;
        for(auto e: emails) m[e] = 1;
        return m.size();
    }
};