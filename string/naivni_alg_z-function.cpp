#include <iostream>
#include <vector>
#include <string>
using namespace std;

void naivni_alg(const string& str, const string& word)
{
    int str_len = str.length();
    int word_len = word.length();
    vector<int> answer;
    for (int i = 0; i < (str_len - word_len); i++)
    {
        for (int j = 0; str[i + j] == word[j]; j++)
        {
            answer.push_back(i);
        }
    }

    auto end = answer.end();
    for (auto it = answer.begin(); it != end; ++it) {
        end = remove(it + 1, end, *it);
    }

    answer.erase(end, answer.end());

    for (vector<int>::size_type i = 0;i != answer.size();i++) {
            cout << answer[i] << " ";
    }

    cout << endl;


}

vector<int> z_function(const string& str)
{
    vector<int> z(str.length(), 0);

    for (int i = 1, left = 0, right = 0; i < str.length(); i++) {
        if (i <= right) {
            z[i] = min(z[i - left], right - i + 1);
        }

        while (i + z[i] < str.length()) {
            if (str[i + z[i]] == str[z[i]]) {
                z[i]++;
            }
            else {
                break;
            }
        }

        if (z[i] > 0 && i + z[i] - 1 > right) {
            left = i;
            right = i + z[i] - 1;
        }
    }

    return z;
}



int main() {
    string str = "abacabacccacc";
    string word = "aba";

    cout << "substring search result with naivni algorithm" << endl;

    cout << "the starting and ending indices of a substring in a string are equal" << endl;



    naivni_alg(str, word);

    cout << endl;

    vector<int> z = z_function(word + '#' + str);

    int word_len = word.length();

    cout << "substring search result with z - function"<<endl;

    for (int i = 0; i < str.length(); i++) {
        if (z[word_len + 1 + i] == word_len) {
            cout << "str[" << i << ".." << i + word_len - 1 << "] = word" << endl;
        }
    }
}
