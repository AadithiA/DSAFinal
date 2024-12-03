#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

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
// Helper function to split a string by a delimiter
vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
// Helper function to trim whitespace
string trim(const string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");
    return (start == string::npos) ? "" : str.substr(start, end - start + 1);
}
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
// Function to parse a line with quoted fields
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
        vector<string> genreList = split(fields[2], ','); // Split genres by commas
        string type = fields[3];
        int num_episodes = isNumber(fields[4]) && fields[4] != "Unknown" ? stoi(fields[4]) : 0;
        double avg_rating = isFloat(fields[5]) ? stod(fields[5]) : 0.0;
        int num_members = isNumber(fields[6]) ? stoi(fields[6]) : 0;
        // Create and add Anime object
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
// Function to display Anime information
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
    // Clear the input buffer after numeric input, especially because it led to repeated prints later
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (choice == 1) {
        cout << "Rating: " << anime.rating << endl;
    } else if (choice == 2) {
        cout << "Episodes: " << anime.episodes << endl;
    } else if (choice == 3) {
        cout << "Genres: ";
        for (const auto& genre : anime.genres) {
            cout << genre << " ";
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
// Main function
int main() {
    string filename = "Anime.csv";
    vector<Anime> animeList = parseAnimeData(filename);
    if (animeList.empty()) {
        cerr << "No data available. Check your file." << endl;
        return 1;
    }
    while (true) {
        string animeName;
        cout << "Enter the anime name (or type 'exit' to quit): " << endl;
        getline(cin, animeName); // Use getline to handle input consistently
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
        string response;
        while (true) { // Keep prompting until a valid response is given
            cout << "Do you want to search for another anime? (yes/no): " << endl;
            getline(cin, response); // Use getline to handle input consistently
            response = trim(response);
            if (response.empty()) {
                // Skip displaying an invalid input message for empty responses
                continue;
            }
            if (response == "yes") {
                break; // Exit the inner loop and continue searching
            } else if (response == "no") {
                cout << "Goodbye!" << endl;
                return 0; // Exit the program
            } else {
                cout << "Invalid input. Please enter 'yes' or 'no'." << endl;
            }
        }
    }
    return 0;
}