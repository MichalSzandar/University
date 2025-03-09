#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <ctime>

using namespace std;

//this is my solver of popular game Mastermind
//it uses minmax algorithm to guess the code in the least number of turns
//it uses a set of 1296 possible codes and removes codes that would not give the same response if they were the code
//it calculates the minmax score for each code in the set and selects the next guess based on the minmax scores

void createSet();

void combinationRecursive(int combinationLength, int position, vector<int> &current, vector<int> &elements);

int getRed(vector<int> guess, vector<int> code);
int getWhite(vector<int> guess, vector<int> code);

void removeCode(vector<vector<int>> &set, vector<int> code);

void pruneCodes(vector<vector<int>> &set, vector<int> code, int red, int white);

vector<vector<int>> minmax();

int getMaxScore(map<string, int> inputMap);

int getMinScore(map<vector<int>, int> inputMap);

vector<int> getNextGuess(vector<vector<int>> nextGuesses);

static const int NUM_COLOURS = 6;
static const int CODE_LENGTH = 4;
static vector<vector<int>> combinations; //Master set of combinations 1111 to 6666
static vector<vector<int>> candidateSolutions;
static vector<vector<int>> nextGuesses;
static vector<int> code;
static vector<int> currentGuess;
static string responsePegs;
static int white;
static int red;
static bool won;
static int turn;

int main() {

    turn = 1;
    won = false;

    currentGuess = {1, 1, 1, 1}; 

    //Create the set of 1296 possible codes
    createSet();
    candidateSolutions.insert(candidateSolutions.end(), combinations.begin(), combinations.end());
    cout << endl;

    while (!won) {

        //Remove currentGuess from possible solutions
        removeCode(combinations, currentGuess);
        removeCode(candidateSolutions, currentGuess);

        cout << "Turn: " << turn << endl;
        cout << "Guess: ";
        for (int i = 0; i < currentGuess.size(); ++i) {
            cout << currentGuess[i] << " ";
        }
        cout<<"red: ";
        cin>>red;
        cout<<"white: ";
        cin>>white;

        //If the response is four colored pegs, the game is won
        if (red == 4) {
            won = true;
            cout << "Game Won!" << endl;
            break;
        }

        //Remove from candidateSolutions,
        //any code that would not give the same response if it were the code
        pruneCodes(candidateSolutions, currentGuess, red, white);

        //Calculate Minmax scores
        nextGuesses = minmax();

        //Select next guess
        currentGuess = getNextGuess(nextGuesses);

        turn++;
    }//End while

    return 0;
}

void createSet() {

    vector<int> current(CODE_LENGTH, 0);
    vector<int> elements;

    for (int i = 1; i <= NUM_COLOURS; ++i) {
        elements.push_back(i);
    }

    combinationRecursive(CODE_LENGTH, 0, current, elements);
}

void combinationRecursive(int combinationLength, int position, vector<int> &current, vector<int> &elements) {

    if (position >= combinationLength) {
        combinations.push_back(current);
        return;
    }

    for (int j = 0; j < elements.size(); ++j) {
        current[position] = elements[j];
        combinationRecursive(combinationLength, position + 1, current, elements);
    }
    return;
}

int getWhite(vector<int> guess, vector<int> code)
{
    int result = 0;
    for (int i = 0; i < CODE_LENGTH; ++i) {

        if (code[i] > 0) {

            vector<int>::iterator it = find(guess.begin(), guess.end(), code[i]);
            int index;
            if (it != guess.end()) {

                index = distance(guess.begin(), it);
                result++;
                guess[index] *= -1;
            }
        }
    }
    return result;
}

int getRed(vector<int> guess, vector<int> code)
{
    int result = 0;
     for (int i = 0; i < CODE_LENGTH; ++i) {

        if (guess[i] == code[i]) {
            result++;
            guess[i] *= -1;
            code[i] *= -1;
        }
    }
    return result;
}

void removeCode(vector<vector<int>> &set, vector<int> currentCode) {

    int index;
    for (auto it = set.begin(); it != set.end(); it++) {
        index = distance(set.begin(), it);

        if (set[index] == currentCode) {
            set.erase(set.begin() + index);
            break;
        }
    }
}

void pruneCodes(vector<vector<int>> &set, vector<int> currentCode, int red, int white) {

    int index;
    vector<vector<int>>::iterator it = set.begin();

    while (it != set.end()) {
        index = distance(set.begin(), it);

        if (red != getRed(currentCode, set[index]) || white!= getWhite(currentCode, set[index])) {
            it = set.erase(set.begin() + index);
        } else {
            it++;
        }
    }
}

vector<vector<int>> minmax() {

    map<int*, int> scoreCount;
    map<vector<int>, int> score;
    vector<vector<int>> nextGuesses;
    int max, min;

    for (int i = 0; i < combinations.size(); ++i) {

        for (int j = 0; j < candidateSolutions.size(); ++j) {
            int pegScore[2];
            int red = getRed(combinations[i], candidateSolutions[j]);
            int white = getWhite(combinations[i], candidateSolutions[j]);
            pegScore[0] = red;
            pegScore[1] = white;
            if (scoreCount.count(pegScore) > 0) {
                scoreCount.at(pegScore)++;
            } else {
                scoreCount.emplace(pegScore, 1);
            }
        }

        max = getMaxScore(scoreCount);
        score.emplace(combinations[i], max);
        scoreCount.clear();
    }

    min = getMinScore(score);

    for (auto elem : score) {
        if (elem.second == min) {
            nextGuesses.push_back(elem.first);
        }
    }

    return nextGuesses;
}

int getMaxScore(map<int*, int> inputMap) {

    int max = 0;
    for (auto elem : inputMap) {
        if (elem.second > max) {
            max = elem.second;
        }
    }

    return max;
}

int getMinScore(map<vector<int>, int> inputMap) {

    int min = 6666;
    for (auto elem : inputMap) {
        if (elem.second < min) {
            min = elem.second;
        }
    }

    return min;
}

vector<int> getNextGuess(vector<vector<int>> nextGuesses) {

    vector<int> nextGuess;

    for (int i = 0; i < nextGuesses.size(); ++i) {
        if (find(candidateSolutions.begin(), candidateSolutions.end(), nextGuesses[i]) != candidateSolutions.end()) {
            return nextGuesses[i];
        }
    }
    for (int j = 0; j < nextGuesses.size(); ++j) {
        if (find(combinations.begin(), combinations.end(), nextGuesses[j]) != combinations.end()) {
            return nextGuesses[j];
        }
    }

    return nextGuess;
}