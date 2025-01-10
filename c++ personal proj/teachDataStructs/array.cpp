#include "dsMenu.cpp"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
template <typename T,int length> // using a template for the class allows us to choose the data type for the array we are gonna implement and also using length allows us 
                                        // to choose the amount of memory we want to allocate for the length so the max length
                                        //T stands for temple type essintally.
class Array{  

private:
    T array[length]; // 
    int currentSize;
public:

    Array(T* arr,int listSize){// arrays are usually used with pointers learn more ABOUT THIS
    if(listSize > length){
        std::cout<< "The List size was too big for the array\n";
        currentSize = 0;
    }

    else{
        std::cout<< "The List size fits inside the array\n";
        for(int i = 0;i < listSize;i++){
            array[i] = arr[i];
            
        }
        currentSize = listSize;

    }
    }

    void displayArray() const;

    T addDel();

};

//Must tell the complier the function thats outside the class is a template function not a regular one.
template <typename T,int length>
void Array<T,length>::displayArray(){ //void is the return type then call the Array class with the template parameter of T which is the data type chosen and of length size.
        for(int i = 0;i < currentSize;i++){
            std::cout << array[i];
            std::cout << "Postion - " << i << ",";
        }
        std::cout << "\n";
        std::cout << "The size of your list currently is: " << currentSize;
            
        }    
    


template <typename T,int length> 
T Array<T,length>::addDel(Array& array){
    bool fullResetInitiate = true
    while(fullResetInitiate){
    std::cout << "If you would like to DELETE something from the array please type (-)\n";
    std::cout << "If you would like to ADD something to the array please type (+)";
    std::string add_del_choice;
    std::cin >> add_del_choice;
   

    if(add_del_choice == "-" || add_del_choice == "DELETE"||add_del_choice == "delete" || add_del_choice == "DEL"||add_del_choice == "del"){
        displayArray();
        std::cout<< "Now that you have seen the array please list the postion of the item you want to delete?"
        int positionDel;
        std::cin >> positionDel;

        if(postionDel >= 0 && positionDel < currentSize ){
            //shift elements to the left.
            array[positionDel] = ' '; // changing all deleted characters to a space
            for(int i = positionDel ;i < currentSize - 1;i++){
                array[i] = array[i+1]; 
            }
        }
        
        else{
            std::cout<< "It seems You went out of bounds or typed a character incorectly." << std::endl; // START HERE
            std::cout<< "Please try again\n";
            fullResetInitiate = true;
        }
    }

    else if(add_del_choice == "+" || add_del_choice == "ADD"||add_del_choice == "add"){
        for(int i = currentSize - 1;i <= currentSize;i--){
            if(array[i] == ' '){
                std::cout<< "Theres space for you to add a number!\n";
                break;
            }
            else{
                std::cout<<"Theres is no space for you to add a number, you will be sent back, please delete a value first!\n";
                fullResetInitiate = true;   
            }
        }
        displayArray();
        std::cout<< "Now that you have seen the array please list the postion of the item you want to add?\n";
        int valeueToAdd;
        for(int i = 0;i < currentSize;i++){
            if(array[i] == ' '){
                array[i] = valeueToAdd;
                std::cout<< "We added your value to the end of the list!\n";
                break;
            }
        }
        currentSize++;
    }

    else{
        std::cout << "Would you like to go to menu or continue with modyifying your array? (m - menu)(a - array)\n";
        std::string menuOrArray;
        if(menuOrArray == 'm' || menuOrArray == 'M'){
            main();
        }
        else if(menuOrArray == 'n' || menuOrArray == 'N'){
            fullResetInitiate = true;
        }
        
    }
    }
}


template<typename T ,int length>
T Array<T,length>::changeElements(Array& array){
    std::cout<<"You have chose to change an element(s)\n";
    std::cout<<"Below is all of the elements along with there postion!\n";
    std::cout<<"______________________________________________________\n";
    displayArray();
    while(true)
        std::cout<<"Please list how many items you want to change. If you dont know yet you can still choose later!";
        int amount2Change;
        std::cin>>amount2Change;

        for(int i = 0;i < amount2Change;i++){

            int postionChosen
            std::cout<<"What is the postion of the current value you would like to change?\n";
            std::cin >> postionChosen;
            for(int currentValue = 0; currentValue < currentSize;currentValue++){
                if(postionChosen != currentValue){
                    continue;
                }
                else{
                    T newValue;
                    std::cout<<"Please list what you would like the new values to be!\n";
                    std::cin>> newValue;
                    array[currentValue] = newValue;
                    break;
                }
            }
        }
        if(i == amount2Change - 1){
            continue;
            }

}
//mAKE NEXT FUNCTION





Key Components of the Array Class
Attributes:
Store the data (array or matrix) using std::vector or raw arrays.
Track dimensions for matrices (rows and columns).
Methods:
Basic Operations:
Create/initialize an array or matrix.
Access and modify elements.
Matrix Operations:
Transpose.
Addition, multiplication.
Check if square or identity matrix.
Calculate determinants (optional, for deeper learning).
Utility Functions:
Print the matrix.
Resize the array/matrix.





class vector{

};








void arrayMenu(){

    startEmptyFilled(list);   
    while(true){
        int choice,value,nth;
        
        displayMenu();

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout<< "Please enter the value you would like to add\n";
            std::cin >> value
            insertAtBeginning(value);
            break;
        case 2:
            std::cout<< "Please enter the value you would like to add\n";
            std::cin >> value
            insertAtEnd(value);
            break;
        case 3:
            displayNodes(list.head);
            break;
        case 4:
            reverseList();
            break;
        case 5:
            std::cout<< "Please enter the value you would like to delete\n";
            std::cin >> value
            deleteNodeByValue(value);
            break;
        case 6:
            std::cout<< "Please enter the value you would like to search\n";
            std::cin >> value
            search4Value(value);
            break;
        case 7:
            getLength();
            break;
        case 8:
            std::cout<< "Please enter the value you would like to find from nth Node\n";
            std::cin >> nth
            getNthNode(nth);
            break;
        case 9:
            mainMenu();
            break;
        
        default:
            std::cout<<"The number chosen was not one of the choices please try again! \n";
            break;
        }
    
}
}