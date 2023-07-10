#include <bits/stdc++.h>
using namespace std;
string fname;
string line;
vector<string> out;
vector<string> cns;
vector<string> lines;
// was a fun project
// got the idea because intellij "encapsulate fields" doesnt generate the comments that were required for cty
// might actually be useful in apcsa next year lol
int main(int argc, char **argv)
{
    if (argc > 1)
    {
        fname = argv[1];
    }
    else
    {
        cout << "usage: " << argv[0] << " <filename>\n";
        exit(0);
    }
    ifstream fin(fname);
    while (getline(fin, line))
    {
        lines.push_back(line);
        while (!line.empty())
        {
            if (line[0] != ' ')
                break;
            line = line.substr(1, string::npos);
        }
        int i;
        for (i = line.size() - 1; i > 5 && line[i] != ';'; i--)
            ;
        if (i <= 5)
            continue;
        // cout << line << endl;
        if (line.substr(0, 7) != "private")
            continue;
        // cout << line.substr(0, 7) << endl;
        stringstream s(line);
        s.ignore(10, ' ');
        string type, name, cname;
        s >> type >> name;
        name.erase(--name.end());
        cname = name;
        if (cname[0] >= 'a')
            cname[0] -= ('a' - 'A');
        // cout << type << ' ' << name << endl;
        s.clear();
        s << "    public " << type << " get" << cname << "() { // returns " << name << "\n        return this." << name << ";\n    }\n\n"
          << "    public void set" << cname << "(" << type << ' ' << name << ") { // sets " << name << " to " << name << "\n        this." << name << " = " << name << ";\n    }";
        out.push_back(s.str());
        cns.push_back(cname);
    }
    fin.clear();
    fin.seekg(0, std::ios::beg);
    for (int i = fname.size() - 1; i > 0; i--)
    {
        if (fname[i] == '.')
        {
            fname.insert(i, " encapsulated");
        }
    }
    freopen(fname.c_str(), "w", stdout);
    bool print = 1;
    while (getline(fin, line))
    {
        for (int i = 0; i < out.size(); i++)
        {
            // cerr << "set" + cns[i] << endl;
            if (line.find("set" + cns[i]) != string::npos)
            {
                cns.erase(cns.begin() + i);
                out.erase(out.begin() + i);
                i--;
            }
        }
        if (line == "}" && print && out.size() > 0)
        {
            print = 0;
            cout << '\n';
            cerr << out.size() << endl;
            for (int i = 0; i < out.size() - 1; i++)
            {
                cout << out[i] << "\n\n";
            }
            cout << *(--out.end()) << "\n";
        }
        cout << line << endl;
    }
}