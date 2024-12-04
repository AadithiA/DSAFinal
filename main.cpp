#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include "Tree.h"
using namespace std;
// Main function
int main() {
    string filename = "Anime.csv";
    vector<Anime> animeList = parseAnimeData(filename);
    if (animeList.empty()) {
        cerr << "No data available. Check your file." << endl;
        return 1;
    }
    while (true) {
        string option;
        cout << "Type '1' to find a specific anime or type '2' to find a specific genre (or type 'exit' to quit):" << endl;
        getline(cin, option);
        if (option == "exit"){ //change this later!
            cout << "Bye bish :)" << endl;
        }
        if (option == "1") {
            //this finds a specific anime
            string animeName;
            cout << "Enter the anime name (or type 'exit' to quit): " << endl;
            getline(cin, animeName); // Use getline to handle input consistently
            if (animeName == "exit") {
                break;
            } // search for the anime by name
            Anime *foundAnime = nullptr;
            for (auto &anime: animeList) {
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
        }
        else if (option == "2"){ //Usage of alogirthms
            cout <<"How do you want the anime to be organized by? Type 'Alphabetical' (Sorted using In Order Traversal) or 'Rating' (Sorted using Max Heap)" << endl;
            string algorithm, genre;
            getline(cin, algorithm);
            if (algorithm == "Alphabetical"){ //organizes Anime list alphabetically, based off an inputted genre:
                displayGenreTypes();
                getline(cin, genre);
                organizeAnimeByGenre(animeList, genre);
            }
            else if (algorithm == "Rating"){ //organizes Anime list by highest rating
                displayGenreTypes();
                getline(cin, genre);
                transform(genre.begin(), genre.end(), genre.begin(), ::tolower); //transform reference: https://www.geeksforgeeks.org/transform-c-stl-perform-operation-elements/
                genre =trim(genre);
                priority_queue<Anime> maxHeap;
                for (auto &anime: animeList) {
                    for(const auto &thegenres: anime.genres) {
                        string name = thegenres;
                        transform(name.begin(), name.end(), name.begin(), ::tolower);
                        if (name == genre) {
                            maxHeap.push(anime);
                            break;
                        }
                    }
                }
                if (!maxHeap.empty()) {
                    //const Anime& topAnime = maxHeap.top();
                    cout<<"Top anime in:" << genre <<"genre:" << endl;
                    while(!maxHeap.empty()) {
                        const Anime& topAnime = maxHeap.top();
                        cout<< topAnime.name << " |Rating:"<< topAnime.rating << endl;
                        maxHeap.pop();
                    }
                }
                else {
                    cout << "Anime not found!" << endl;
                }
            }
            else {
                cout << "Try again motherf*cker curse thy soul on this earth" << endl;
            }
        }
        else {
            cout << "Don't piss me off" << endl;
        }
    }
    return 0;
}
