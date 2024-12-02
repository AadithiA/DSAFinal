#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm> // Required for all_of
using namespace std;
struct Anime {
    int id;
    string name;
    vector<string> genres;
    string type;
    int episodes;
    double rating;
    int members;
};
// Helper function to check if a string represents an integer
bool isNumber(const string& str) {
    return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
}
// Helper function to check if a string represents a floating-point number
bool isFloat(const string& str) {
    std::istringstream iss(str);
    double val;
    return !(str.empty() || !(iss >> val) || !(iss.eof()));
}
vector<Anime> parseAnimeData(const string& filename) {
    vector<Anime> animeList;
    ifstream file(filename);
    string line;
    // Skip the header
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, genre, type, episodes, rating, members;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, genre, ',');
        getline(ss, type, ',');
        getline(ss, episodes, ',');
        getline(ss, rating, ',');
        getline(ss, members, ',');
        // Validate and parse fields
        int anime_id = isNumber(id) ? stoi(id) : 0;
        int num_episodes = isNumber(episodes) ? stoi(episodes) : 0;
        double avg_rating = isFloat(rating) ? stod(rating) : 0.0;
        int num_members = isNumber(members) ? stoi(members) : 0;
        // Create the Anime object
        Anime anime = {
                anime_id,
                name,
                {genre},  // Simplified for single genre; split further if needed
                type,
                num_episodes,
                avg_rating,
                num_members
        };
        animeList.push_back(anime);
    }
    return animeList;
}
int main() {
    string filename = "Anime.csv";
    vector<Anime> animeList = parseAnimeData(filename);
    for (const auto& anime : animeList) {
        cout << "Anime: " << anime.name
             << ", Rating: " << anime.rating << endl;
    }
    return 0;
}
