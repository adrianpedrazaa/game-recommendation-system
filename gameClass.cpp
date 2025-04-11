#include "gameClass.h"
GameData::GameData()
{
    name = "EMPTY";
    rating = 0.00;
    id = 0;
    sortStart = false;
    
}
GameData::GameData(int ids, string nam, vector<string> tVec, float rat)
{
    id = ids;
    name = nam;
    tags = tVec;
    rating = rat;
}
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
/* to complicated for such a small amount of data
unsigned int GameData::partition(unsigned int top, unsigned int bottom)
{
    string toSwap;
    unsigned int swapps = bottom - 1;
    int pivot = tags[top].length();
    for(unsigned int itter = bottom; itter < top; ++itter)
    {
        if(tags[itter].length() <= pivot)
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
*/
/* Not worth using  
void GameData::vecQuickSort(unsigned int top, unsigned int bottom)
{
    if(bottom < top)
    {
        if(sortStart == false)
        {
            sortStart = true;
            top = sizeof(tags) / sizeof(tags[0]);
            bottom = 0;
        }
        unsigned int  pivot = partition(top, bottom);
        vecQuickSort(bottom, pivot - 1);
        vecQuickSort(pivot + 1, top);
    }
} */
bool GameData::vectorSearch(string genre)
{
    for(unsigned int i = 0; i < tags.size(); ++i)
    {
        if(tags[i] == genre)
        {
            return true;
        }
    }
    return false;
}