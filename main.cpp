#include "headers.h"
#include "gameList.h"
using namespace std;
void loadData(GameList &games)
{

    ifstream ofile;
    string theFile;
    bool exists = false;
    string line;
    string gName;
    vector<string> gTags;
    string capt;
    int id = 1;
    int comCount = 0;
    float gRate;
    
    //Test
    //vector<GameData*> testvec;
    
    while(exists == false)
    {
        cout << "\nPlease enter the file name: ";
        cin >> theFile;
        ofile.open(theFile);
        if(ofile)
        {
            exists = true;
            cout << "\nFile Loaded";
        }
        else
        {
            cout << "\nFile Not Found";
        }
    }

    while(!ofile.eof())
    {
        comCount = 0;
        getline(ofile, line);
        for(int i = 0; i < line.length(); ++i)
        {
            if(line[i] != ',')
            {
                capt += line[i];
                if(i == line.length() - 1)
                {
                    gTags.push_back(capt);
                    capt = "";
                }
            }
            else
            {
                ++comCount;
                if(comCount == 1)
                {
                    gName = capt;
                }
                else if(comCount == 2)
                {
                    gRate = stof(capt);
                }
                else if(comCount >= 3)
                {
                    gTags.push_back(capt);
                }
                capt = "";
            }
        }
        //Create gameClass object and store in hash table
        //Add code
        games.push_front(new GameData(id, gName, gTags, gRate));
        //temp to test
        //testvec.push_back(new GameData(id, gName, gTags, gRate));

        //Reset temp Variables increment id
        //gTags.clear();
        ++id;
    }
    ofile.close();

    //Temp to test
    /*for(unsigned int i = 0; i < testvec.size(); ++i)
    {
        testvec[i]->print();
    }
    cout << endl;
    for(unsigned int i = 0; i < testvec.size(); ++i)
    {
        cout << testvec[i] << endl;
        delete testvec[i];
        
    }
    testvec.clear();
    */
}
void vgamesMenu(GameList &games)
{
    int selection; 
    bool correct = false;
    while(correct == false)
    {
        cout << "\nPlease enter the number of your selection"
            << "\n1:View games by rating"
            << "\n2:View games alphabetically"
            << "\n3:View games by a genre"
            << "\n4:Search for game"
            << "\n: ";
        cin >> selection;
        if(cin.fail())
        {
            cin.ignore();
            cout << "\nERROR: Invalid choice\n";
        }
        else
        {
            correct = true;
        }
    }
    switch(selection)
    {
        case 1:
            if(games.alphaSorted == true)
            {
                games.quicksortRating();
            }
            games.printList();
        break;
        case 2:
            if(games.alphaSorted == false)
            {
                games.quicksortAlph();
            }
            games.printList();
        case 3:
        
            
            
    }

}
int main()
{
    GameList games;
    string aFile;
    int selection;
    bool quit = false;
    bool exists = false;
    while(quit == false)
    {   
        cout << "\nPlease enter the number of your selection\n"
             << "1: Load data set\n" 
             << "2: View games\n"            
             << "3: Quit\n"
             << ": ";
        cin >> selection;
        switch(selection)
        {
            case 1:
                loadData(games);
            break;
            case 2:
                vgamesMenu(games);
            break;
            case 4:
                quit = true;
            break;
        }


    }
    return 0;    
}