#include "headers.h"
#include "gameClass.h"
class GameList
{
    public: 
    GameData *head;
    GameData *tail;
    int size;
    GameList();
    ~GameList();
    void quicksortAlph();
    void quicksortRating();
    void printList();
    void genreSearch();
    void nameSearch();
    void push_front(GameData* p);
    bool alphaSorted;
};