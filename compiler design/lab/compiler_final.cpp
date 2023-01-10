#include <bits/stdc++.h>
using namespace std;
set<int> eps_clos(int arr[][4], int state)
{
    set<int> clos;
    queue<int> qu;
    qu.push(state);
    clos.insert(state);
    int t;
    while (!qu.empty())
    {
        t = qu.front();
        if (arr[t][2] != -1)
        {
        qu.push(arr[t][2]);
        clos.insert(arr[t][2]);
        }
        if (arr[t][3] != -1)
        {
        qu.push(arr[t][3]);
        clos.insert(arr[t][3]);
        }
        qu.pop();
    }
return clos;
}
void print_nfa(int n , int arr[][4])
{
    for (int i = 0; i < n; i++)
{
    if (i == 0)
    cout << "initial";
    if (i == n - 1)
    cout << "final";
    cout << "\t" << i;
        for (int j = 0; j < 4; j++)
        {
        cout << "\t" << arr[i][j];
        }
    cout << endl;
    }
}
int main()
{
int n = 11;
int arr[11][4] = {
    {-1, -1, 1, 7},
    {-1, -1, 2, 4},
    {3, -1, -1, -1},
    {-1, -1, 6, -1},
    {-1, 5, -1, -1},
    {-1, -1, 6, -1},
    {-1, -1, 7, 1},
    {8, -1, -1, -1},
    {-1, 9, -1, -1},
    {-1, 10, -1, -1},
    {-1, -1, -1, -1}
    };
cout << "Thompson Construction of (a|b)*abb : " << endl;
cout << "\tState\ta\tb\te1\te2" << endl;

print_nfa(n,arr);

vector<set<int>> epsclos;
for (int i = 0; i < n; i++)
{
    //here we are finding e closure of all the states
    epsclos.push_back(eps_clos(arr, i));
}

set<int> final_states;
queue<set<int>> qu;
//we have pushed null closure of 0 into the queue
qu.push(epsclos[0]);
int count = 1;
map<set<int>, int> mp;
//mapping the key such that ek closure ko as a one key treat krna 
mp[epsclos[0]] = count - 1;
vector<vector<int>> dfa(n);
cout << endl
<< "New States after subset construction are: " << endl;
while (!qu.empty())
{
    //we are begining with the process of subset construction
    
    //finding a and b on null closure of of a particular state
    set<int> a = qu.front();
    int t = mp[a];
    qu.pop();
    set<int> a1;
    set<int> b1;
    set<int>::iterator i;
    cout << t << " ->";
    for (i = a.begin(); i != a.end(); i++)
    {
        if (*i == n - 1)
        final_states.insert(t);
        cout << *i << " ";
        //nfa mei se dekhre a read krke kaha jana and same for b
        if (arr[*i][0] != -1)
        a1.insert(arr[*i][0]);
        if (arr[*i][1] != -1)
        b1.insert(arr[*i][1]);
    }
    cout << endl;
    set<int> a2;
    set<int> b2;
    for (i = a1.begin(); i != a1.end(); i++)
    {
        a.clear();
        a = epsclos[*i];
        a2.insert(a.begin(), a.end());
    }
    //checking already hai toh nhi voh state jo bni hai
    if (mp.find(a2) == mp.end())
    {
        qu.push(a2);
        mp[a2] = count;
        count++; 
    }
    dfa[t].push_back(mp[a2]);
    for (i = b1.begin(); i != b1.end(); i++)
    {
        a.clear();
        a = epsclos[*i];
        b2.insert(a.begin(), a.end());
    }
    if (mp.find(b2) == mp.end())
    {
        qu.push(b2);
        mp[b2] = count;
        count++; 
    }
    dfa[t].push_back(mp[b2]);
}

cout << endl
<< "DFA obtained using subset construction is: " << endl
<< "\tState\ta\tb" << endl;
for (int i = 0; i < count; i++)
{
    if (i == 0)
        cout << "initial";
    if (final_states.find(i) != final_states.end())
        cout << "final";
    cout << "\t" << i << "\t" << dfa[i][0] << "\t" << dfa[i][1] << endl;
}
vector<set<int>> vec;
set<int> non_final;
//storing of non final states 
for (int i = 0; i < count; i++)
{
    if (final_states.find(i) == final_states.end())
        non_final.insert(i);
}
int flag = 0;
vec.push_back(final_states);
vec.push_back(non_final);

set<int> final_states_after_min;
//minimization of dfa 
while (1)
{
    flag = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].size() == 1)
        {
            continue;
        }
        else
        {
        set<int>::iterator it1;
        set<int>::iterator it2;
        for (it1 = vec[i].begin(); it1 != --vec[i].end(); it1++)
        {
            for (it2 = ++it1; it2 != vec[i].end(); it2++)
            {
                it1--;
                //cout<<*it1<<" "<<*it2<<endl;
                int l = dfa[*it1][0];
                int r = dfa[*it2][0];
                for (int j = 0; j < vec.size(); j++)
                {
                    if (vec[j].find(l) != vec[j].end() && vec[j].find(r) == vec[j].end())
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                break;  
                l = dfa[*it1][1];
                r = dfa[*it2][1];
                for (int j = 0; j < vec.size(); j++)
            {
                if (vec[j].find(l) != vec[j].end() && vec[j].find(r) == vec[j].end())
                {
                    flag = 1;
                    break;
                }
            }
                if (flag == 1)
                break;
            }
if (flag == 1)
break;
}
if (flag == 1)
{
//cout<<endl<<*it1<<" "<<*it2<<endl;
vector<set<int>> vec2;
for (int a = 0; a < i; a++)
vec2.push_back(vec[a]);
set<int>::iterator it3;
set<int>::iterator it4;
set<int> s1;
set<int> s2;
for (it4 = vec[i].begin(); it4 != it2; it4++)
    {
    s1.insert(*it4);
    }
s2.insert(*it4);
int f = 0;
for (it3 = ++it2; it3 != vec[i].end(); it3++)
    {
    it2--;
    int l = dfa[*it1][0];
    int r = dfa[*it3][0];
    for (int j = 0; j < vec.size(); j++)
    {
        if (vec[j].find(l) != vec[j].end() && vec[j].find(r) == vec[j].end())
            {
            f = 1;
            break;
            }
    }
if (f == 1)
{
    s2.insert(*it3);
}
else
{
    l = dfa[*it1][1];
    r = dfa[*it3][1];
    for (int j = 0; j < vec.size(); j++)
    {
    if (vec[j].find(l) != vec[j].end() && vec[j].find(r) == vec[j].end())
    {
    f = 1;
    break;
    }
    }
    if (f == 1)
        {
        s2.insert(*it3);
        }
    else
        s1.insert(*it3);
}
}
vec2.push_back(s1);
vec2.push_back(s2);
for (int a = i + 1; a < vec.size(); a++)
vec2.push_back(vec[a]);
vec = vec2;
}
}
        if (flag == 1)
        break;
    }
    if (flag == 0)
    break;
}
set<int>::iterator i;
vector<vector<int>> mindfa(vec.size());
for (int i = 0; i < vec.size(); i++)
{
    int s = *vec[i].begin();
    int a = dfa[s][0];
    for (int j = 0; j < vec.size(); j++)
    {
        if (vec[j].find(a) != vec[j].end())
        {
            mindfa[i].push_back(j);
            break;
        }
    }
    a = dfa[s][1];
    for (int j = 0; j < vec.size(); j++)
    {
        if (vec[j].find(a) != vec[j].end())
        {
            mindfa[i].push_back(j);
            break;
        }
    }
}
cout << endl
<< "New States after minimization are: " << endl;
for (int j = 0; j < vec.size(); j++)
{
    cout << j << " -> ";
    for (i = vec[j].begin(); i != vec[j].end(); i++)
    {
        if (final_states.find(*i) != final_states.end())
        final_states_after_min.insert(j);
        cout << *i << " ";
    }
    cout << endl;
}
int initial;
cout << endl
<< "Minimized DFA is: " << endl
<< "\tState\ta\tb" << endl;
for (int j = 0; j < mindfa.size(); j++)
{
    if (vec[j].find(0) != vec[j].end())
    {
        cout << "initial";
        initial = j;
    }
    if (final_states_after_min.find(j) != final_states_after_min.end())
        cout << "final";
    cout << "\t" << j << "\t" << mindfa[j][0] << "\t" << mindfa[j][1] << endl;
}

//to check whether the string is accepted or not
while (1)
{
    string input;
    int state = initial;
    cout << endl<< "Enter input string(consisting of only 'a' or 'b') (Enter 0 if no further string input): ";
    cin >> input;
    if (input[0] == '0')
        break;
    int n = input.size();
    for (int i = 0; i < n; i++)
    {
        state = mindfa[state][input[i] - 'a'];
    }
    if (final_states_after_min.find(state) != final_states_after_min.end())
        {
            cout << "Input string is Accepted!" << endl;
        }
    else
        cout << "Input string is Rejected!" << endl;
}
return 0;
}

