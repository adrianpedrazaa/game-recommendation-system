#include "gameClass.h"
//Default Constructor shouldn't ever be used
GameData::GameData()
{
    name = "EMPTY";
    rating = 0.00;
    id = 0;
    sortStart = false;
    next = NULL;
    previous = NULL;
    
}
//Parameterized Constructor
GameData::GameData(int ids, string nam, vector<string> tVec, float rat)
{
    id = ids;
    name = nam;
    tags = tVec;
    rating = rat;
}
//Print nodes data
void GameData::print()
{
    cout << "\nId: " << id
         << "\nName: " << name
         << "\nTags: ";
    for(unsigned int i = 0; i < tags.size(); ++i)
    {
        cout << tags[i];
        if(i != tags.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "\nRating: " << rating;
}

//Returns true if genre is found
//Linear search strings are hard to quick sort and 
//binary search plus its not really worth it with how few genres each game would have
bool GameData::vectorSearch(string genre)
{
    bool found = false;
    for(unsigned int i = 0; i < tags.size(); ++i)
    {
        if(tags[i] == genre)
        {
            found = true;
        }
    }
    return found;
}
/* to complicated for such a small amount of data
unsigned int GameData::partition(unsigned int top, unsigned int bottom)
{
    string toSwap;
    unsigned int swapps = bottom - 1;
    string pivot = tags[top];
    for(unsigned int itter = bottom; itter < top; ++itter)
    {
        if(tags[itter] < pivot)
        {
            ++swapps;
            toSwap = tags[swapps];
            tags[swapps] = tags[itter];
            tags[itter] = toSwap;
        }
    }
    toSwap = tags[swapps + 1];
    tags[swapps + 1] = tags[top];
    tags[top] = toSwap; 
    return (swapps + 1);
}
void GameData::vecQuickSort(unsigned int top, unsigned int bottom)
{
    if(bottom < top)
    {
        if(sortStart == false)
        {
            sortStart = true;
            top = tags.size() - 1;
            bottom = 0;
        }
        unsigned int  pivot = partition(top, bottom);
        vecQuickSort(pivot - 1, bottom);
        vecQuickSort(top, pivot + 1);
    }
} */