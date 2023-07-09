#include <iostream>
#include <stack>

using namespace std;

int rain(vector<int> n)
{
    stack<int> s;
    int sum = 0;
    for (int i = 1; i < n.size(); i++)
    {
        while (!s.empty() && n[s.top()] < n[i])
        {
            int h1 = n[s.top()];
            s.pop();
            if (!s.empty())
            {
                int before_height = n[s.top()];
                int min = before_height > n[i] ? n[i] : before_height;
                sum += (min - h1) * (i - s.top() - 1);
            }
            else
            {
                break;
            }
        }

        s.push(i);
    }
    return sum;
}

int main()
{
    vector<int> v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(2);
    v.push_back(5);
    cout << rain(v);
    return 0;
}