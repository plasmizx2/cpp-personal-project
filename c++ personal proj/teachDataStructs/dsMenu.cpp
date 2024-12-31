#include "linkedList.cpp"
#include "array.cpp"
#include <iostream>
#include <string>


int main(){
    std::cout << "|====================================|\n";
    std::cout << "| Learn Linked List - (0)            |\n";
    std::cout << "| Exit - (-1)                        |\n";
    std::cout << "|====================================|\n";
    std::cout << "Please enter the corresponding option to whatever data structure you would like to learn.\n";
    
    int choice;
    std::cin >> choice;

    while(true){
        switch (choice)
        {
        case -1:
            std::cout<< "You are now being exited out of the program please wait!\n";
            return -1
            break;

        case 0:
            std::cout << "You chose Linked List!\n";
            LinkedListMenu();
        
        case 1;
            std::cout<< "You chose Arrays!"
            arrayMenu();
    
        default:
            break;

        }
    
    }
}