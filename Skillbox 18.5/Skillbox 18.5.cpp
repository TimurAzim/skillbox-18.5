#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std;

class Player {
public:
    string name;
    int score;

    Player(string n, int s) : name(n), score(s) {}
};

bool comparePlayers(const Player& a, const Player& b) {
    return a.score > b.score; 
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int numPlayers;
    cout << "Сколько игроков вы хотите добавить? ";
    cin >> numPlayers;

    vector<Player> players;
    for (int i = 0; i < numPlayers; ++i) {
        string name;
        int score;
        cout << "Введите имя игрока: ";
        cin >> name;
        cout << "Введите количество набранных очков: ";
        cin >> score;
        Player player(name, score);
        players.push_back(player);
    }

    sort(players.begin(), players.end(), comparePlayers);

    cout << "\nОтсортированный список игроков:" << endl;
    for (const Player& player : players) {
        cout << "Имя: " << player.name << ", Очки: " << player.score << endl;
    }

    return 0;
}
