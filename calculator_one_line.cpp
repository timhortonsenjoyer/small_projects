#include <iostream>
#include <vector>
#include <string>
#include <limits> //limits was needed for the cin.ignore() in main

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
void calculator_app(vector <char> inputs){
    do{
        int result{0};
        char num_one=inputs[0];
        char num_two=inputs[2];
        int num_ones = num_one-'0'; //convert to int type from char type
        int num_twos = num_two-'0'; //convert to int type from char type
        if (inputs[1]=='+'){
            result = num_ones+num_twos;
        }
        else if (inputs[1]=='-')
        {
            result = num_ones-num_twos;
        }
        else if (inputs[1]=='*')
        {
            result = num_ones*num_twos;
        }
        else if (inputs[1]=='/')
        {
            result = num_ones/num_twos;
        }
        char temp= result+'0'; //convert from the int type to the char type
        inputs.erase(inputs.begin(),inputs.begin()+3); //removes the first 3 elements from the vector
        inputs.insert(inputs.begin(),temp); //inserts the new result in the vector
    }while(inputs.size()>1); //continues until the final result is obtained.
    cout<<"The final result of the operations is :"<<inputs[0]-'0'<<endl; //the final result was in char format
    //So it had to be converted back into int temporarily
}

int main(){
    bool flag{0}; // flag to signal whether to continue with the program or exit- mainly for .exe
    do{
        string all_inputs;
        cout<<"Enter the complete operation here: "<<endl;
        getline(cin,all_inputs); //uses getline to read entire user data until the newline character
        vector<char> chars;
        for (const auto &element:all_inputs){ //iterates without changing anything
            chars.push_back(element);
        }
        calculator_app(chars);
        chars.clear();
        all_inputs.clear(); //resets both vectors at the end of each loop
        cout<<"Press 0 to continue with the calculator app, or 1 to exit: "<<endl;
        cin>>flag;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //the cin from before ends up populating the cin itself with a newline character, which causes segmentation error
        //Therefore, the above cin.ignore() is called to remove it per loop iteration. the limits library is used here
    }while (flag==0);
}