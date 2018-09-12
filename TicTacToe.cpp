/*
        XO game by Hassan El-shazly
*/
#include <iostream>
#include <vector>
#include <limits>
#include <string>
using namespace std;

class Game 
{
    char game[4][4];
    vector<int> plays ;
    public:
    Game();
    void setGame(int z , char value);
    void printGame();
    void printGameStart();
    int isPlayed(float a);
    char viewWinner();
};
Game::Game()
{
    // initialize the board with '-'
    for(int i = 0 ; i < 4 ; i++)
    {
        for (int j = 0 ; j < 4 ; j++)
        {
            game[i][j] = '-' ;
        }
    }
}
void Game::setGame(int z , char value)
{
    // add the place to the taken places
    plays.push_back(z) ;
    // set the game
    z = z - 1 ;
    int y = z % 4 ;
    int x = (z - y) / 4 ;
    game[x][y] = value ;
}
void Game::printGame()
{
    // print the board with player moves
    for(int i = 0 ; i < 4 ; i++ )
    {
        for (int j = 0 ; j < 4 ; j++ )
        {
            cout << "  " << game[i][j] << "  " ;

        }
        cout << endl ; 
    }   
}
void Game::printGameStart()
{
    // print the board filled with numbers
    int count = 1 ;
    for(int i = 0 ; i < 4 ; i++ )
    {
        for (int j = 0 ; j < 4 ; j++ )
        {
            cout << count << "\t" ;
            count ++ ;

        }
        cout << endl ; 
    }   
}
int Game::isPlayed(float a )
{
    // check if the move was alread played 
    int myints[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    bool flag = true ;
    for (int i = 0 ;  i < 16 ; i++)
    {
        if ( a == myints[i] )
            flag = false ;
    }
    if ( flag )
        return -1 ;  

    for(int i = 0 ; i < plays.size() ; i++)
    {
        if ( a == plays[i] )
        {
            return 1 ;
        }
    }
    return 0 ;
}
char Game::viewWinner()
{
    for (int i = 0 ; i < 4 ; i++)
    {
        // check 4 in row
        int countx=0 , county = 0 ;
        for (int j = 0 ; j < 4 ; j++)
        {
            if ( game[i][j] == 'x')
                countx++ ;
            else if ( game[i][j] == 'o')
                county++ ;
        }
        if (countx == 4)
            return 'X' ;
        else if (county == 4)
            return 'O' ;
        // check 4 in column
        countx=0 ; county = 0 ;
        for (int j = 0 ; j < 4 ; j++)
        {
            if ( game[j][i] == 'x')
                countx++ ;
            else if ( game[j][i] == 'o')
                county++ ;
        }
        if (countx == 4)
            return 'X' ;
        else if (county == 4)
            return 'O' ;    
    }
    // check digonal from left to right
    int countxd = 0 , countyd = 0;
    for (int i = 0 ; i < 4 ; i++)
    {
        if ( game[i][i] == 'x')
            countxd++ ;
        else if ( game[i][i] == 'o')
            countyd++ ;
    }
    if (countxd == 4)
        return 'X' ;
    else if (countyd == 4 )
        return 'O' ;
    // check digonal from right to left
    countxd = 0 ; countyd = 0;
    for (int i = 0 ; i < 4 ; i++)
    {
        if ( game[i][3-i] == 'x')
            countxd++ ;
        else if ( game[i][3-i] == 'o')
            countyd++ ;
    }
    if (countxd == 4)
        return 'X' ;
    else if (countyd == 4 )
        return 'O' ;
    // there is no winner 
    return 'T' ;
}

int main ()
{
    /* starting the game by promt users for Thier names */
    string userX = "", userO = ""; 
    Game game ;
    cout << "Enter player name to be x : "  ;
    cin >> userX ;
    cout << "Enter player name to be o : "  ;
    cin >> userO;
    game.printGameStart();
    for (int i = 0 ; i < 8 ; i++ )
    {
        // (float) to return invalid if the user entered a float number
        float x = 0 ;
        cout << "Enter number from 1 to 16\n" ;
        // confrim that the place is available
        while(game.isPlayed(x))
        {
            cout << userX << " turn to play : " ;
            cin >> x ;
            if(game.isPlayed(x) == 1)
                cout << "This place is already taken\n" ;
            // if the input was string or float
            if (!(cin) or game.isPlayed(x) == -1)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "invalid input\n";
            }
              
        }
        // print the bord with the new place
        game.setGame(x,'x');
        game.printGame();
        // check if there is a winner  
        if (game.viewWinner() == 'X')
        {
            cout << userX << " is the winner\n";
            break;
        }
        else if ( game.viewWinner() == 'O')
        {
            cout << userO << " is the winner\n";
            break;
        }

        // repeat the process again with the secend player
        x = 0 ;
        while(game.isPlayed(x))
        {
            cout << userO << " turn to play : " ;
            cin >> x ;
            if(game.isPlayed(x) == 1)
                cout << "This place is already taken\n" ;
            if (!(cin) or game.isPlayed(x) == -1)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "invalid input\n";
            }
        }
        game.setGame(x,'o');
        game.printGame();

        if (game.viewWinner() == 'X')
        {
            cout << userX << " is the winner\n";
            break;
        }
        else if ( game.viewWinner() == 'O')
        {
            cout << userO << " is the winner\n";
            break;
        }
    }
    // if the available places were out with no winner then the game is tied
    if (game.viewWinner() == 'T')
        {
            cout <<"the game is tied\n" ;
        }  
    cout << " press Enter to exit " ;
    cin.get();
    cin.get();
    return 0 ;
}