#include "headers.h"
#include "gameClass.h"
class GameList
{
    public: 
    GameData *head;
    GameData *tail;
    //Size of list
    int size;
    //Default constructor
    GameList();
    //Deconstructor deletes all nodes
    ~GameList();
    //Sorts games alphabetically
    void swapGames(GameData* i, GameData* j);
    void selectsortAlph();
    //Sorts games by rating
    void selectsortRating();
    //Prints all nodes in list
    void printList();
    //Searches games for genre and prints games of that type
    void genreSearch();
    //Calls alpha sorting function and searches for a game named by the user
    void nameSearch();
    //Pushes new nodes to the front of the list
    void push_front(GameData* p);
    //void vectorSort();
    //Bool to avoid sorting if not needed true = Alpha sorted, false = rating sorted
    bool alphaSorted;
};