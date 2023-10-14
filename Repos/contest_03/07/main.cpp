#include "fstream"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int isIn(vector<string> data, string w) {
    auto result = find(begin(data), end(data), w);
    if (result == end(data)) {
        return -1;
    }
    else {
        return (result - begin(data));
    }
}

bool compare(pair<string, int>& a, pair<string, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main() {
    ifstream file("data.txt"); // Открываем файл на чтение
    string word, target;
    vector<string> text;
    map<string, unsigned> words_count;
    vector<pair<string, int>> word_freq;

    cin >> target;

    while (getline(file, word, ' ')) {
        if (word == "stopword") {
            break;
        }
        text.push_back(word);
    }
    
    if (isIn(text, target) == -1) {
        cout << '-';    
    }
       
    else {
        for (int i = (isIn(text, target) + 1); i < text.size(); i++) {
            if (text[i - 1] == target) {
                words_count[(text[i])] += 1;
            }

        }

        for (const auto& pair : words_count) {
            word_freq.push_back(pair);
        }

        sort(word_freq.begin(), word_freq.end(), compare);

        int count = 0;
        for (const auto& pair : word_freq) {
            std::cout << pair.first << " ";
            count++;
            if (count == word_freq.size() || count == 3) {
                break;
            }
        }
    }
    return 0;
}
