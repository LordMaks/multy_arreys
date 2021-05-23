#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> v_int;
typedef vector<double> v_d;
typedef vector<float> v_f;
typedef vector<long> v_l;

typedef vector<vector<int>> v2d_int;
typedef vector<vector<double>> v2d_d;
typedef vector<vector<float>> v2d_f;
typedef vector<vector<long>> v2d_l;

template <typename K>
void print(const vector<K>& v)
{
    string result = "[";
    for (auto i : v)
    {
        result += to_string(i) + ", ";
    }
    result.erase(result.size() - 2, 2);
    result.append("]");

    cout << result << endl;
}

template <typename K>
void print(const vector<vector<K>>& v)
{
    string result = "[";
    for (auto i : v)
    {
        result += "[";
        for (auto j : i)
        {
            result += to_string(j) + ", ";
        }
        result.erase(result.size() - 2, 2);
        result.append("]\n");
    }
    result.erase(result.end());
    result.append("]");

    cout << result << endl;
}

template <typename K>
string to_str(const vector<K>& v)
{
    string result = "[";
    for (auto i : v)
    {
        result += to_string(i) + ", ";
    }
    result.erase(result.size() - 2, 2);
    result.append("]");

    return result;
}

template <typename K>
string to_str(const vector<vector<K>>& v)
{
    string result = "[";
    for (auto i : v)
    {
        result += "[";
        for (auto j : i)
        {
            result += to_string(j) + ", ";
        }
        result.erase(result.size() - 2, 2);
        result.append("]\n");
    }
    result.erase(result.size() - 1);
    result.append("]");

    return result;
}

template <typename K>
K sum(const vector<K>& v)
{
    K result = 0;
    for (auto i : v) result += i;

    return result;
}

template <typename K>
K sum(const vector<vector<K>>& v)
{
    K result = 0;
    for (auto i : v)
    {
        for (auto j : i) result += j;
    }

    return result;
}

int main(int argc, char* argv[])
{

    v_int v1d = {0, 1, 2, 3, 4, 5, 6, 7 };
    cout << "Original: " << to_str(v1d) << endl;
    cout << "Sum: " << sum(v1d) << endl;
    cout << "Average: " << sum(v1d) / v1d.size() << endl;

    v2d_int v2d;
    for (int i = 0; i < 5; i++)
    {
        v2d.push_back(v_int(5));
        for (int j = 0; j < 5; j++) v2d[i][j] = j;
    }

    cout << "Original: " << to_str(v2d) << endl;
    cout << "Sum: " << sum(v2d) << endl;
    int amout = 0;
    for (auto i : v2d) amout += i.size();
    cout << "Average: " << sum(v2d) / amout << endl;
}