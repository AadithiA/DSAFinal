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
void displayAnimeInfo(const Anime& anime) {
    cout << "Choose the information you want to view:" << endl;
    cout << "1. Rating" << endl;
    cout << "2. Episode Count" << endl;
    cout << "3. Genre" << endl;
    cout << "4. Type" << endl;
    cout << "5. Community Size" << endl;
    cout << "Enter your choice (1-5): ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        cout << "Rating: " << anime.rating << endl;
    }
    else if (choice == 2) {
        cout << "Episodes: " << anime.episodes << endl;
    }
    else if (choice == 3) {
        cout << "Genre: ";
        for (const auto& genre : anime.genres) {
            cout << genre << " ";
        }
        cout << endl;
    }
    else if (choice == 4) {
        cout << "Type: " << anime.type << endl;
    }
    else if (choice == 5) {
        cout << "Community Size: " << anime.members << endl;
    }
    else {
        cout << "Invalid choice!" << endl;
    }
}
int main() {
    string filename = "Anime.csv";
    vector<Anime> animeList = parseAnimeData(filename);
    while (true) {
        string animeName;
        cout << "Enter the anime name (or type 'exit' to quit): ";
        cin.ignore();  // To clear any leftover newline character
        getline(cin, animeName);
        // Exit if user types "exit"
        if (animeName == "exit") {
            break;
        }
        // Search for the anime by name
        Anime* foundAnime = nullptr;
        for (auto& anime : animeList) {
            if (anime.name == animeName) {
                foundAnime = &anime;
                break;
            }
        }
        if (foundAnime) {
            displayAnimeInfo(*foundAnime);
        } else {
            cout << "Anime not found!" << endl;
        }
        // Ask the user if they want to search for another anime
        cout << "Do you want to search for another anime? (yes/no): ";
        string response;
        cin >> response;
        if (response != "yes") {
            break;
        }
    }
    return 0;
}
