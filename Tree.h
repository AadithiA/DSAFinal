//
// Created by Adriel on 12/3/2024.
//

#ifndef DSAFINAL_TREE_H
#define DSAFINAL_TREE_H

#endif //DSAFINAL_TREE_H
//
// Created by Adriel on 12/3/2024.
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <queue>
#include <functional>

using namespace std;
struct Anime {
    int id; //we don't actually need but for reading the file it's there
    string name;
    vector<string> genres;
    string type;
    int episodes;
    double rating;
    int members;
    //compares the rating with the other ratings
    bool operator<(const Anime &other) const {
        return rating < other.rating;
    }
};
// helper function to split a string by a delimiter
vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
// helper function to trim whitespace
string trim(const string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");
    //reference: https://cplusplus.com/reference/string/string/npos/
    return (start == string::npos) ? "" : str.substr(start, end - start + 1);
}
// helper function to check if a string represents an integer
bool isNumber(const string& str) {
    return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
}
// helper function to check if a string represents a floating-point number
bool isFloat(const string& str) {
    std::istringstream iss(str);
    double val;
    return !(str.empty() || !(iss >> val) || !(iss.eof()));
}
// helper function for a line with quoted fields
vector<string> parseLine(const string& line) {
    vector<string> fields;
    stringstream ss(line);
    string field;
    bool inQuotes = false;
    string currentField;
    for (char ch : line) {
        if (ch == '"' && !inQuotes) {
            inQuotes = true;
        } else if (ch == '"' && inQuotes) {
            inQuotes = false;
        } else if (ch == ',' && !inQuotes) {
            fields.push_back(trim(currentField));
            currentField.clear();
        } else {
            currentField += ch;
        }
    }
    if (!currentField.empty()) {
        fields.push_back(trim(currentField));
    }
    return fields;
}
// Function to parse the CSV file into a vector of Anime objects
vector<Anime> parseAnimeData(const string& filename) {
    vector<Anime> animeList;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return animeList;
    }
    string line;
    // Skip the header
    getline(file, line);
    while (getline(file, line)) {
        vector<string> fields = parseLine(line);
        if (fields.size() < 7) continue; // Skip malformed lines
        // Assign fields
        int anime_id = isNumber(fields[0]) ? stoi(fields[0]) : 0;
        string name = fields[1];
        vector<string> genreList = split(fields[2], ','); // splits genres by commas
        string type = fields[3];  //for the ? if it's not true it does the second option, aka 0
        int num_episodes = isNumber(fields[4]) && fields[4] != "Unknown" ? stoi(fields[4]) : 0;
        double avg_rating = isFloat(fields[5]) ? stod(fields[5]) : 0.0;
        int num_members = isNumber(fields[6]) ? stoi(fields[6]) : 0;
        // creates and adds Anime object
        Anime anime = {
                anime_id,
                name,
                genreList,
                type,
                num_episodes,
                avg_rating,
                num_members
        };
        animeList.push_back(anime);
    }
    return animeList;
}
void displayGenreTypes(){
    cout << "Select a Genre " << endl;
    cout << "Genres: " << endl;
    cout << "Action, Adventure, Comedy, Drama, Fantasy, Hentai, Historical, Horror" << endl;
    cout << "Kids, Mystery, Sci-Fi, Shoujo, Shounen, Slice of Life, Supernatural,and Romance" << endl;
}
void displayAnimeInfo(const Anime& anime) {
    cout << "Choose the information you want to view:" << endl;
    cout << "1. Rating" << endl;
    cout << "2. Episode Count" << endl;
    cout << "3. Genre" << endl;
    cout << "4. Type" << endl;
    cout << "5. Community Size" << endl;
    cout << "Enter your choice (1-5): " << endl;
    int choice;
    cin >> choice;
    // Clear the input buffer after numeric input, especially because it led to repeated prints later
    //Resource: https://cplusplus.com/forum/beginner/217812/#google_vignette
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (choice == 1) {
        cout << "Rating: " << anime.rating << endl;
    } else if (choice == 2) {
        cout << "Episodes: " << anime.episodes << endl;
    } else if (choice == 3) {
        cout << "Genres: ";
        for (const auto& genre : anime.genres) {
            cout << genre << " " << endl;
        }
        cout << endl;
    } else if (choice == 4) {
        cout << "Type: " << anime.type << endl;
    } else if (choice == 5) {
        cout << "Community Size: " << anime.members << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }
}
struct TreeNode {
    string animeName;
    TreeNode* left;
    TreeNode* right;
    TreeNode(string name) : animeName(name), left(nullptr), right(nullptr) {}
};

TreeNode* insertNode(TreeNode* root, const string& animeName) {
    string normalizedAnimeName = animeName;
    if (!animeName.empty() && islower(animeName[0])) {
        normalizedAnimeName[0] = toupper(animeName[0]);
    }
    if (!root) return new TreeNode(normalizedAnimeName);
    if (normalizedAnimeName < root->animeName) {
        root->left = insertNode(root->left, normalizedAnimeName);
    } else {
        root->right = insertNode(root->right, normalizedAnimeName);
    }
    return root;
}

void inOrderTraversal(TreeNode* root, vector<string>& result) {
    if (!root) return;
    inOrderTraversal(root->left, result);
    result.push_back(root->animeName);
    inOrderTraversal(root->right, result);
}

void organizeAnimeByGenre(const vector<Anime>& animeList, const string& genre) {
    TreeNode* root = nullptr;
    for (const auto& anime : animeList) {
        if (find(anime.genres.begin(), anime.genres.end(), genre) != anime.genres.end()) {
            root = insertNode(root, anime.name);
        }
    }
    vector<string> sortedAnime;
    inOrderTraversal(root, sortedAnime);
    if (sortedAnime.empty()) {
        cout << "No anime found for genre: " << genre << endl;
    } else {
        cout << "Anime in genre \"" << genre << "\" sorted alphabetically:" << endl;
        for (const auto& name : sortedAnime) {
            cout << name << endl;
        }
    }
    function<void(TreeNode*)> deleteTree = [&](TreeNode* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    };
    deleteTree(root);
}
