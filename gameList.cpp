#include "gameList.h"
//Default constructor
GameList::GameList()
{
    size = 0;
    head = NULL;
    tail = NULL;
    alphaSorted = true;
}
//Destructor 
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
//Prints all nodes in the list
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
//Searches for games of a certain tag and displays them
void GameList::genreSearch()
{
    GameData *nodetoCheck = head;
    bool correct = false;
    int choice;
    string genre;
    //Get genre from user
    cout << "\nPlease enter a genre to view: ";
    cin >> genre;
    //Loops until valid choice is entered
    while(correct == false)
    {
        cout << "\nWould you like to see games by"
            << "\n1:Rating"
            << "\n2:Alphabetically"
            << "\n:";
        cin >> choice;
        if(cin.fail())
        {
            while(cin.fail())
            {
                cin.ignore();
            }
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
    //Calls rating sort if needed
    if(choice == 1 && alphaSorted == true)
    {
        quicksortRating();
    }
    //Calls alpha sorting if needed
    else if(choice == 2 && alphaSorted == false)
    {
        quicksortAlph();
    }
    //Checks all but last node for genre type
    while(nodetoCheck->next != head){
        if(nodetoCheck->vectorSearch(genre) == true)
        {
            nodetoCheck->print();
            correct = false;
        }
        nodetoCheck = nodetoCheck->next;
    }
    //Checks last node for genre
    if(nodetoCheck->vectorSearch(genre) == true)
    {
        nodetoCheck->print();
        correct = false;
    }
    //Displays message if no games of genre found
    if(correct == true)
    {
        cout << "\nNo games of genre: " << genre << " found.\n";
    }
}
//Searches for game named by the user
void GameList::nameSearch()
{

    string gameName;
    cout << "\nPlease enter a game you want to view: ";
    cin >> gameName;
    //Binary Search for game by name by alpha
    if(alphaSorted == false)
    {
        quicksortAlph();
    }
    //Search goes here


}
//Pushes new nodes to the front of the list
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