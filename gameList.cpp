#include "gameList.h"
GameList::GameList()
{
    size = 0;
    head = NULL;
    tail = NULL;
    alphaSorted = true;
}
GameList::~GameList()
{
    GameData *toDelete = head;
    GameData *next = head->next;
    while(size > 0)
    {
        delete toDelete;
        toDelete = next;
        next = toDelete->next;
        --size;
    }
    cout << "\nNodes Deleted";
}
void GameList::quicksortAlph()
{
    alphaSorted = true;
    //Quick sort list by alphabet
}
void GameList::quicksortRating()
{   
    alphaSorted = false;
    //Quick sort by rating
}
void GameList::printList()
{
    GameData *nodeToPrint = head;
    while(nodeToPrint->next != head)
    {
        nodeToPrint->print();
        nodeToPrint = nodeToPrint->next;
    }
    nodeToPrint->print();

}
void GameList::genreSearch()
{
    vector<GameData*> gamestoPrint;
    bool correct = false;
    int choice;
    string genre;
    cout << "\nPlease enter a genre to view: ";
    cin >> genre;
    while(correct == false)
    {
        cout << "\nWould you like to see games by"
            << "\n1:Rating"
            << "\n2:Alphabetically"
            << "\n:";
        cin >> choice;
        if(cin.fail())
        {
            cin.ignore();
            cout << "\nERROR: Invalid Choice\n";
        }
        else if(choice < 1 || choice > 2)
        {
            cout << "\nERROR: Invalid Choice\n";
        }
        else
        {
            correct = true;
        }
        
    }
}
void GameList::nameSearch()
{

    string gameName;
    cout << "\nPlease enter a game you want to view: ";
    cin >> gameName;
    //Quick Search for game by name by alpha
    if(alphaSorted == false)
    {
        quicksortAlph();
    }
    //Search goes here


}
void GameList::push_front(GameData *newnode)
{
    GameData *oldhead;
    //Case for first node added
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    //New node is added to head of list setting its next pointer to the old head and previous to the tail
    //The old heads previous pointer is set to the new node
    else
    {
        oldhead = head;
        head = newnode;
        newnode->next = oldhead;
        newnode->previous = tail;
        oldhead->previous = newnode;
    }
    ++size;
}