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
        if(next != tail)
        {
            next = toDelete->next;
        }
        --size;
    }
    cout << "\nNodes Deleted";
}
void GameList::quicksortRating()
{   
    alphaSorted = false;
    //Quick sort by rating

    GameData* outer_loop_ptr = head;

    int i = 0;
    int j = 0;

    bool outer_cond = true;

    while(outer_cond)
    {
        cout << "outer is " << outer_loop_ptr->name << endl;

        GameData* min_elem_ptr = outer_loop_ptr;
        GameData* inner_loop_ptr = outer_loop_ptr;
        //cout << "min is " << min_elem_ptr->name << endl;

        // loop through unsorted_start -> end, find smallest element
        bool inner_cond = true;
        while (inner_cond)
        {   
            //cout << "inner_loop_ptr->name is " << inner_loop_ptr->name << endl;
            // if current elem's name is alphabetically before the min_elem, min elem = current elem
            if (inner_loop_ptr->rating > (min_elem_ptr->rating)) {
                min_elem_ptr = inner_loop_ptr;
                //cout << "min is " << min_elem_ptr->name << endl;
            }

            if (inner_loop_ptr->next == head) {
                inner_cond = false;
            } else {
                inner_loop_ptr = inner_loop_ptr->next;
            }
            j++;
        }

        // swap smallest element with unsorted_start
        //cout << "swap" << endl;
        swapGames(min_elem_ptr, outer_loop_ptr);
        // unsorted start = smallest->next
        outer_loop_ptr = min_elem_ptr->next;
        

        if (outer_loop_ptr->next == head) {
            outer_cond = false;
        }
        i++;

        // outer_cond = false;
    }
    cout << "sorted with " << i << ", " << j << " iterations" << endl;
}
//Prints all nodes in the list
void GameList::printList()
{
    GameData *nodeToPrint = head;
    while(nodeToPrint->next != head)
    {
        nodeToPrint->print();
        nodeToPrint = nodeToPrint->next;
        if(nodeToPrint->next == nodeToPrint) { cout << "infinite loop :(" << endl; break; }
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
            cin.clear();    
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
    //Test
    //int i = 1;
    //cout << endl << head << endl;
    while(nodetoCheck->next != head)
    {
        if(nodetoCheck->vectorSearch(genre) == true)
        {
            nodetoCheck->print();
            correct = false;
        }
        nodetoCheck = nodetoCheck->next;
        //Test
        //cout << i << " " << nodetoCheck->next << endl;
        //++i;
    }
    //Test
    //cout << "\n1\n";
    //Checks last node for genre
    if(nodetoCheck->vectorSearch(genre) == true)
    {
        nodetoCheck->print();
        correct = false;
    }
    //Test
    //cout << "\n2\n";
    //Displays message if no games of genre found
    if(correct == true)
    {
        cout << "\nNo games of genre: " << genre << " found.\n";
    }
    return;
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
        tail->next = head;
    }
    ++size;
}



void GameList::quicksortAlph()
{   
    GameData* outer_loop_ptr = head;

    int i = 0;
    int j = 0;

    bool outer_cond = true;

    while(outer_cond)
    {
        cout << "outer is " << outer_loop_ptr->name << endl;

        GameData* min_elem_ptr = outer_loop_ptr;
        GameData* inner_loop_ptr = outer_loop_ptr;
        //cout << "min is " << min_elem_ptr->name << endl;

        // loop through unsorted_start -> end, find smallest element
        bool inner_cond = true;
        while (inner_cond)
        {   
            //cout << "inner_loop_ptr->name is " << inner_loop_ptr->name << endl;
            // if current elem's name is alphabetically before the min_elem, min elem = current elem
            int comparison = inner_loop_ptr->name.compare(min_elem_ptr->name);
            if (comparison < 0) {
                min_elem_ptr = inner_loop_ptr;
                //cout << "min is " << min_elem_ptr->name << endl;
            }

            if (inner_loop_ptr->next == head) {
                inner_cond = false;
            } else {
                inner_loop_ptr = inner_loop_ptr->next;
            }
            j++;
        }

        // swap smallest element with unsorted_start
        //cout << "swap" << endl;
        swapGames(min_elem_ptr, outer_loop_ptr);
        // unsorted start = smallest->next
        outer_loop_ptr = min_elem_ptr->next;
        

        if (outer_loop_ptr->next == head) {
            outer_cond = false;
        }
        i++;

        // outer_cond = false;
    }
    alphaSorted = true;
    cout << "sorted with " << i << ", " << j << " iterations" << endl;
}


//swap any 2 lists of the doubly linked list
void GameList::swapGames(GameData* i, GameData* j) {
    if (i == j) { return; }

    //also change head and tail pointers if needed
    if(i == head) { head = j; }
    else if(j == head) { head = i; }
    if(i == tail) { tail = j; }
    else if(j == tail) { tail = i; }

    //makes it so the code for i after j can be the same as j after i
    if (j->next == i) {
        GameData* temp = i;
        i = j;
        j = temp;
    }

    GameData* temp_i_prev = i->previous;
    GameData* temp_j_prev = j->previous;
    GameData* temp_i_next = i->next;
    GameData* temp_j_next = j->next;

    if (i->next == j) {
        //pointers need to be swapped differently if i and j are adjacent
        i->previous = temp_i_next;
        j->previous = temp_i_prev;
        i->next = temp_j_next;
        j->next = temp_j_prev;
    } else {
        i->previous = temp_j_prev;
        j->previous = temp_i_prev;
        i->next = temp_j_next;
        j->next = temp_i_next;
    }

    if (i->previous != NULL) { i->previous->next = i; }
    if (i->next != NULL) { i->next->previous = i; }
    
    if (j->previous != NULL) { j->previous->next = j; }
    if (j->next != NULL) { j->next->previous = j; }
}
