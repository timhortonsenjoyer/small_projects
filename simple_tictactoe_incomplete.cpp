#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

vector <vector<char>> board = {{'\0','\0','\0'},
                               {'\0','\0','\0'},
                               {'\0','\0','\0'}}; //Global vector of char vectors for 'board' intialized to null

void set_board(){//used to print the empty spaces in terminal output to make them more visible 
    for (auto &row:board){
        for (auto &element:row){
            element=' ';
        }
        cout<<'\0'<<endl;
    }
    
}
void print_board(){ //Prints out board after each input
    for (const auto &row:board){ // const auto since function shouldn't modify anything here
        for (const auto &element:row){
            cout<<element<<"|";
        }
        cout<<'\0'<<endl;
    }
}

void draw_on_board(const int arr[],bool e_flag){ // takes x,y coordinate and draws input depending on whose turn it is
    for (auto &row:board){
        for (auto &element:row){
                board[arr[0]].erase(board[arr[0]].begin()+arr[1]);
                if (e_flag==0){
                    board[arr[0]].insert(board[arr[0]].begin()+arr[1],'X');
                }
                else if (e_flag==1){
                    board[arr[0]].insert(board[arr[0]].begin()+arr[1],'O');
                }   
            }
        }
        cout<<'\0'<<endl;
    }

bool check_board(const int arr[]){ // function that checks to determine if spot on board was already taken or not
    int temp1=arr[0];
    int temp2=arr[1];
    if (board.at(temp1).at(temp2)=='X'||board.at(temp1).at(temp2)=='O'){
        return 1;
    }
    else{
        return 0;
    }
}
int check_for_win(){ // checks for win condition for both user and comp
    int flag{-1};
    for (int i=0;i<3;i++){ // checks for straight row or straight column win
        if((board[0][i]=='X')&&(board[1][i]=='X')&&(board[2][i]=='X')){
        flag = 1;
        }
        else if((board[0][i]=='O')&&(board[1][i]=='O')&&(board[2][i]=='O')){
        flag = 0;
        }
        else if((board[i][0]=='X')&&(board[i][1]=='X')&&(board[i][2]=='X')){
        flag = 1;
        }
        else if((board[i][0]=='O')&&(board[i][1]=='O')&&(board[i][2]=='O')){
        flag = 0;
        }
    }
    // these check for the diagonal win condition
    if((board[0][0]=='X')&&(board[1][1]=='X')&&(board[2][2]=='X')){
        flag =1;
    }
    else if((board[0][2]=='X')&&(board[1][1]=='X')&&(board[2][0]=='X')){
       flag =1;
    }
    else if((board[0][0]=='O')&&(board[1][1]=='O')&&(board[2][2]=='O')){
        flag =0;
    }
    else if((board[0][2]=='O')&&(board[1][1]=='O')&&(board[2][0]=='O')){
        flag =0;
    }
return flag;
    
}
int main(){
    srand(time(0));
    set_board();
    int inputs[2]={0,0};
    int user_inputs[2]={0,0};
    bool flag = 0;
    bool user_flag = 0;
    int who_win =3;
    int iter{0};
    do{
        bool is_user = 0;
        int random_row = rand()%3;
        int random_column = rand()%3;
        inputs[0]=random_row;
        inputs[1]=random_column;
        flag = check_board(inputs);  
        if(flag==0){
            draw_on_board(inputs,is_user);
            print_board();
            who_win = check_for_win();
            if(who_win==1){
            cout<<"Computer wins!"<<endl;
            break;
        }
            cout<<"Enter row (0,1,2) and column(0,1,2) to mark your location: "<<endl;
            if(cin>>user_inputs[0]>>user_inputs[1]){
                is_user=1;
            }
            user_flag = check_board(user_inputs); 
            if(user_flag==0){
                draw_on_board(user_inputs,is_user);
                print_board();
            }
            else if (user_flag==1){
                continue;
            }
        }
        else if (flag==1){
            continue;
        }
    who_win = check_for_win();
    if(who_win==0){
        cout<<"User wins!"<<endl;
        break;
    }
    iter++;
    }while(iter<3);
    if(who_win==-1){
        cout<<"No one wins!"<<endl;
    }
 system("pause");//to let program pause until termination
 cout<<"Done";
}
//sometimes using the [] way of accessing specific elements in a vector gives plain segmentation error in compiler
//so use the .at() method instead to try to get and check for a specific error
