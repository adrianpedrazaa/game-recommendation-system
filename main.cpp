#include "headers.h"
void loadData()
{

    ifstream readF;
    bool exists = false;
    string fileName;
    string line;
    string gName;
    string gDesc;
    string gGenre;
    float gRate;

    //Checks if file exists loops until valid file is entered.
    while(exists == false)
    {
        cout << "\nPlease enter the file name: ";
        cin >> fileName;
        readF.open(fileName);
        if(readF)
        {
            exists = true;
        }
        else
        {
            cout << "\nFile not found";
            readF.close();
        }
    }

    while(!readF.eof())
    {
        getline(readF, line);
        for(int i = 0; i < line.size(); ++i)
        {
            
        }
    }
    readF.close();
}
int main()
{
    int selection;
    bool quit = false;
    while(quit == false)
    {   
        cout << "Please enter the number of your selection\n"
            << "1: Load data set\n" 
            << "2: View games by genre\n"
            << "3: Search for by feel\n"
            << "4: Quit\n";
        switch(selection)
        {
            case 1:
                loadData();
        }


    }
    return 0;    
}