//simple number guesser game
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

// Global vectors to store generated random numbers and user input
vector <int> computer_nums;
vector <int> user_nums;

// Templated function to handle overloaded << operator for vectors
template <typename T>
std::ostream &operator<<(std::ostream &os, const vector<T> &vec){
        for (auto &element:vec){
            os<<element<<" ";
        }
    return os;
    }

int main()
{
  srand(time(0));
  int guess{0},score{0};
  for (int i=0;i<10;i++){
      int rand_num = rand()%11; // Generates a random number
      computer_nums.push_back(rand_num);
      cout<<"Enter a random number between 0 and 10 inclusive: \n";
      cin>>guess;
      user_nums.push_back(guess);
      // Below is a 'scoring' system. Correct answer gives the most points
      //But if the answer is partially right, then the amount of points given depends
      //on how close the answer was. A difference of 1 gives 2 points, while a 
      //difference of 2 gives the least amount of points (1)
      if (guess==rand_num){
        score+=3;
        cout<<"Correct!\n";
      } 
      else if (abs(guess-rand_num)==1){
          cout<<"You were really close!\n";
          score+=2;
      }
      else if (abs(guess-rand_num)==2){
          cout<<"You were close!\n";
          score+=1;
      }
      else
        cout<<"Wrong!\n";
  }
  cout<<"The numbers were: "<<computer_nums<<endl;
  cout<<" Your numbers were: "<<user_nums<<endl;
  cout<<"Game finished. Your final score is :"<<score<<endl;

  system("pause");
 }
