#include<iostream>
#include <cmath>
using namespace std;
/* Program: this game is about a pile of coins and there are two players who contribute to choose a non-zero perfect square number
 and this number is taken from the pile and the one who chooses the last perfect square wins
*/
/* Author: mohmammed ahmed khalaf
   ID:20231132
   section :no section
 */
// Version: 2.0
// Date: 1/3/2024


int read_pos() {
// Prompts the user to enter a non-zero and positive integer and excluding the string values.
    int number;
    do
    {
        cout<<"enter a positive integer: ";
        cin >> number;
        //cin fails when the user enters another domain of data types
        while(cin.fail()){
            cin.clear();// clears the user input from the screen
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// clears the input from the buffer
            cout<<"invalid input, enter a positive integer: ";
            cin>>number;
        }

    }
    while (number<=0);

    return number;

}

int read_coins(){
//   prompts the user to enter the number of the coins to play with excluding zeros, negative values and string values
    int coins;
    do
    {
        cout<<"enter the number of coins: ";
        cin >> coins;
        // cin fails when the user enters another domain of data types
        while(cin.fail()){
            cin.clear();// clears the user input from the screen
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// clears the input from the buffer
            cout<<"invalid input, enter the number of coins: ";
            cin >> coins;
        }

    }
    while (coins <= 0);

    return coins;
}
bool check_non_zero_square(int& user_num) {
   // Checks if the given number is a perfect square (excluding 0) because we want a non-perfect square number
    int sqrt_num=pow(user_num ,0.5);
    if(user_num==1||user_num==2)return true;
    if (pow(sqrt_num,2) == user_num){
        return true;
    }
    return false;
}

string determine_the_winner(){
   // Simulates the coin guessing game and returns the winner as a string.

    int user_num;
    int coins= read_coins();
    //the count variable to increment to stimulate the two players
    int count = 0;
    // the game will end when the coins equal to zero
    while (coins > 0)
    {
        user_num =read_pos();
        //when user enters a bigger number that the coins
        while(user_num > coins){
            user_num =read_pos();
        }

        //when true subtract the user input from the whole number of coins and printing the remainder
        if (check_non_zero_square(user_num)) {

            coins -= user_num;
            cout << "the number of coins is :" << coins<<endl;
        }
        // when false exclude the player move by decrementing
        else
        {
            count-=1;
        }

        //  increment the counter to determine which player turn across the game
        count++;
    }

    // to simulate the two players the odd number for the first player and the even ones for the second one
    if (count % 2 == 1)return"player one is the winner";
    return "player two is the winner";
}


int main()
{
    // printing the winner
    string winner = determine_the_winner();
    cout<<winner;
    return 0;
}