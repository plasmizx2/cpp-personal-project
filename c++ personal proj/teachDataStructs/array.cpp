#include "dsMenu.cpp"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
template <typename typeTemp,int length> // using a template for the class allows us to choose the data type for the array we are gonna implement and also using length allows us 
                                        // to choose the amount of memory we want to allocate for the length so the max length
class Array{  

private:
    typeTemp array[length]; // 
    int currentSize;
public:
    Array(typeTemp* arr,int listSize){// arrays are usually used with pointers learn more ABOUT THIS
    if(listSize > length){
        std::cout<< "The List size was too big for the array\n";
    }
    else{
        std::cout<< "The List size was not too big for the array\n";
        for(int i = 0;i < listSize;i++){
            array[i] = arr[i];
        }
    }
    }



    void displayArray(){
        for(int i = 0;i < currentSize;i++){
            std::cout << arr2display[i] << ",";
        }
        std::cout << "\n";
        std::cout << "The size of your list currently is: " << currentSize;
            
        }    
    

    typeTemp addDel(Array& array){

    }


};







void Array::setElement(){

}


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