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
    Array() {
        currentSize = 0;  // Initialize current size to 0
        for (int i = 0; i < length; i++) {
            array[i] = T();  // Default-initialize each element
        }
    }

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

template<typename T, int length>
int Array<T,length>::getCurrentSize(){
    return currentSize;
}

template <typename T, int length>
void Array<T, length>::makeAnArray() {
    int choice;
    std::cout << "Do you have an array to work with?\n";
    std::cout << "1. Yes, I have an array.\n";
    std::cout << "2. No, I want to create a new array.\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    
    if (choice == 1) {
        // User already has an array
        int size;
        std::cout << "Enter the size of your existing array (max " << length << "): ";
        std::cin >> size;
        if (size <= 0 || size > length) {
            std::cout << "Invalid size! Please enter a size between 1 and " << length << ".\n";
            return;
        }
        currentSize = size;
        std::cout << "Enter " << size << " values for your array:\n";
        for (int i = 0; i < size; i++) {
            std::cin >> array[i];
        }
        std::cout << "Array initialized successfully!\n";
    } 
    
    else if (choice == 2) {
        // User wants to create a new array
        currentSize = 0;
        std::cout << "You can now add elements to your new array using the 'Add or Delete Element' option.\n";
    } 
    
    else {
        std::cout << "Invalid choice! Returning to the menu.\n";
    }
}

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

//dynamically allocate the memory when using this function as its with arrays.
template<typename T, int length>
T** Array<T,length>::matrix2DInitiation(Array& array1,Array& array2){
    std::cout<<"Now that youve given me your row and columns\n";
    // need to allocate new memory for the array that will hold pointers
    T** matrixRow = new T*[array1.currentSize]; // T** (double pointer of said dataType) the row(matrixRow) (T*) the new memory is made to to make an array of T data type of the size of the array1.currentSize
    for(int i = 0;i <array1.currentSize;i++){
        matrixRow[i] = new T[array2.currentSize]; //now access each element/pointer inside of the array of pointers 
        // My def is its an array (double pointer) with each element inside of it pointing to another array thus creating the matrix
    }
        std::cout<< "Matrix has been made here it is!\n";
        return matrixR;
}

template<typename T, int length>
T** Array<T,length>::matrixDisplay(T** matrixRow,int row,int column){ // row and column would be input as array1.currentSize and column would be input as array2.currentSize
    for(int j = 0;j < row;j++){
        for(int k = 0;k < column;k++){
            std::cout<< matrix[j][k];
        }
        std::cout<<"\n";
    }
}
//dont forget  Array<T,length> t and length can be named anything
template<typename T,int length>
T** Array<T,length>::matrixChangeElements(T** matrix,int currentRow,int currentColumn){
    while(true){ 

    T rowToChange;
    T columnToChange;
    T newValue;
    std::cout<<"Heres your current matrix,\n";
    matrixDisplay(matrix,currentRow,currentColumn);
    std::cout<<"Please enter the row from which the element you want to change.\n";
    std::cin >> rowToChange;
    std::cout<<"Please enter the column from which the element you want to change.\n";
    std::cin >> columnToChange;
    std::cout<<"Please enter the value you want to change in row:"<<rowToChange" and column:"<<columnToChange"\n";
    std::cin >> newValue;

    matrix[rowToChange][columnToChange] = newValue;

    std::cout<<"Would you like to change anything else: (Y/N)";
    std::string restartChoice;
    if(restartChoice == 'y'||restartChoice == 'Y'){
        continue;
    }
    else if(restartChoice == 'n'||restartChoice == 'N'){
        return matrix;
    }
    else{
        std::cout<<"You typed neither (Y/N), for safety reasons we will save youre matrix as is and end changing it.\n"
        return matrix;
    }
    }

}


template<typename T, int length>
T** Array<T,length>::transposeCurrentMatrix(T** oldMatrix,int oldRow,int oldColumn){
    int newRow = oldColumn;
    int newColumn = oldRow;

    T** newMatrix = new T*[newRow];
    for(int i = 0;i < newRow;i++){
        newMatrix[i] = new T[newColumn];
    }
    //transpose it by using the old row and column to switch the i and j elemnts.
    for(int i = 0;i<oldRow;i++){
        for(int j = 0;j<oldColumn;j++){
            newMatrix[j][i] = oldMatrix[i][j] // to switch it you need to have the column and row switched of whatever was there for the old matrix!
        }
    }

    return newMatrix;
    }





int displayDataTypes(){
    std::cout << "\nWelcome to the Array Menu!\n";
    std::cout << "please choose what data type you want!\n"
    std::cout << "|============================|\n";
    std::cout << "|0. Integers                 |\n";
    std::cout << "|1. Doubles                  |\n";
    std::cout << "|2. Floats                   |\n";
    std::cout << "|3. Strings                  |\n";
    std::cout << "|4. Characters               |\n";
    std::cout << "|5. Main Menu                |\n";
    std::cout << "|6. Exit Program             |\n";
    std::cout << "|============================|\n";
    std::cout << "\n";
    std::cout << "Enter your choice: \n";
    int dataTypeChoice;
    std::cin >> dataTypeChoice;
    return dataTypeChoice;
}



void arrayMenu() {
    int dataTypeChoice = displayDataTypes(); // Prompt user to select a data type

    switch (dataTypeChoice) {
        case 0: {
            std::cout << "You chose integers!\n";
            Array<int, 100> intArray; // Create an integer array
            intArray.makeAnArray();  // Initialize the array
            arrayMenuOperations(intArray); // Pass it to operations menu
            break;
        }
        case 1: {
            std::cout << "You chose doubles!\n";
            Array<double, 100> doubleArray; // Create a double array
            doubleArray.makeAnArray();     // Initialize the array
            arrayMenuOperations(doubleArray); // Pass it to operations menu
            break;
        }
        case 2: {
            std::cout << "You chose floats!\n";
            Array<float, 100> floatArray; // Create a float array
            floatArray.makeAnArray();    // Initialize the array
            arrayMenuOperations(floatArray); // Pass it to operations menu
            break;
        }
        case 3: {
            std::cout << "You chose strings!\n";
            Array<std::string, 100> stringArray; // Create a string array
            stringArray.makeAnArray();          // Initialize the array
            arrayMenuOperations(stringArray);   // Pass it to operations menu
            break;
        }
        case 4: {
            std::cout << "You chose characters!\n";
            Array<char, 100> charArray; // Create a char array
            charArray.makeAnArray();   // Initialize the array
            arrayMenuOperations(charArray); // Pass it to operations menu
            break;
        }
        case 5: {
            std::cout << "Returning to main menu...\n";
            return;
        }
        case 6: {
            std::cout << "Exiting the program...\n";
            exit(0);
        }
        default: {
            std::cout << "Invalid choice! Please try again.\n";
            break;
        }
    }
    }




int matrixChoice(){
        std::cout << "\nDo you want to make a matrix?\n";
        std::cout << "|============================|\n";
        std::cout << "|0. Yes                      |\n";
        std::cout << "|1. No                       |\n";
        std::cout << "|2. Maybe Later              |\n";
        std::cout << "|============================|\n";
        std::cout << "\n";
        std::cout << "Enter your choice: \n";
        int matrixChoice;
        std::cin >> matrixChoice;
        return matrixChoice;
    }


    

int displayArrayMenu(){
    std::cout << "\n----- Array Operations Menu -----\n";
    std::cout << "|============================|\n";
    std::cout << "|1. Display Array            |\n";
    std::cout << "|2. Add or Delete Element    |\n";
    std::cout << "|3. Change Elements          |\n";
    std::cout << "|4. Matrix 2D Initiation     |\n";
    std::cout << "|5. Matrix Display           |\n";
    std::cout << "|6. Matrix Change Elements   |\n";
    std::cout << "|7. Transpose Current Matrix |\n";
    std::cout << "|8. Main Menu                |\n";
    std::cout << "|9. Exit                     |\n";
    std::cout << "|============================|\n";
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    if(choice >= 1 && choice <= 9){
       return choice; 
    }
    else{
        return displayArrayMenu();
    }

}

template <typename T, int length>
void arrayMenuOperations(Array<T, length>& array1,Array<T, length>& array2) {
    T** initializedMatrix = nullptr;  // Pointer to store the 2D matrix
    int matrixRows = 0;               // Store the number of rows
    int matrixCols = 0;
    while (true) {
       displayArrayMenu()
       int matrixChoice = matrixChoice();


       if(matrixChoice == 0){
            switch (choice) {
                case 1: {
                    array1.displayArray();
                    break;
                }
                case 2: {
                    array1.addDel(array1);
                    break;
                }
                case 3: {
                    array1.changeElements(array1);
                    break;
                }
                default: {
                    std::cout << "Invalid choice! Please try again.\n";
                    break;
                }
            }
       }

        if(matrixChoice == 1){
            if(array2.getCurrentSize == 0){
                std::cout<<"You dont have a second array please make it now, the data type must be the same or there will be another error!";
                int dataType = displayDataTypes();
                switch (dataType){

                case 0:
                    std::cout << "You chose integers!\n";
                    Array<int, 100> array2; // Create an integer array2
                    array2.makeAnArray();     
                    break;
                case 1:
                    std::cout << "You chose doubles!\n";
                    Array<double, 100> array2; // Create a double array2
                    array2.makeAnArray(); 
                    break;
                case 2:
                    std::cout << "You chose floats!\n";
                    Array<float, 100> array2; // Create a float array2
                    array2.makeAnArray();
                    break;
                case 3:
                    std::cout << "You chose strings!\n";
                    Array<std::string, 100> array2; // Create a string array2
                    array2.makeAnArray();      
                    break;
                case 4:
                    std::cout << "You chose characters!\n";
                    Array<char, 100> array2;
                    array2.makeAnArray();      
                    break;
                case 5:
                    main();
                    break;
                case 6:

                    break;                
                default:
                    break;
                }

            }
            switch (choice) {
                case 1: {
                    array1.displayArray();
                    if(array2.getCurrentSize != 0){
                        array2.display();
                    }
                    break;
                }
                case 2: {
                    array1.addDel(array1);
                    if(array2.getCurrentSize != 0){
                        array2.addDel(array2);
                    }
                    break;
                }
                case 3: {
                    array1.changeElements(array1);
                    if(array2.getCurrentSize != 0){
                        array2.changeElements(array2);
                    }
                    break;
                }
                case 4: {
                    std::cout << "To do the 2D Matrix Initiation you need 2 arrays make sure you have 2 before doing so.\n";
                    initlizedMatrix = matrix2DInitiation(array1,array2);
                    break;
                }
                case 5: {
                    if(initializedMatrix){

                    matrixRows = array1.getCurrentSize();      // Store the number of rows
                    matrixCols = array2.getCurrentSize();
                    matrixDisplay(initializedMatrix,matrixRows,matrixCols)
                    
                    }
                    else{
                        std::cout << "Matrix not initialized yet!\n";
                    }
                    break;
                }
                case 6:
                    if (initializedMatrix) {
                        std::cout << "Would you like to modify the matrix using:\n";
                        std::cout << "1. Array 1\n";
                        std::cout << "2. Array 2\n";
                        int arrayChoice;
                        std::cin >> arrayChoice;

                        if (arrayChoice == 1) {
                            initializedMatrix = array1.matrixChangeElements(initializedMatrix, matrixRows, matrixCols);
                        } else if (arrayChoice == 2) {
                            initializedMatrix = array2.matrixChangeElements(initializedMatrix, matrixRows, matrixCols);
                        } else {
                            std::cout << "Invalid choice! Returning to menu.\n";
                        }
                    } else {
                        std::cout << "Matrix not initialized yet!\n";
                    }
                    break;

                
                case 7: {
                    if (initializedMatrix) {
                        int oldRows = matrixRows;
                        T** transposedMatrix = transposeCurrentMatrix(initializedMatrix,matrixRows,matrixCols);
                        // doing this you need to free the previous matrix 
                        for (int i = 0; i < matrixRows; i++) {
                            delete[] initializedMatrix[i];
                        }
                        delete[] initializedMatrix;
                        initializedMatrix = transposedMatrix;
                        matrixRows = matrixCols;
                        matrixCols = oldRows; 
                    }
                    else{
                        std::cout << "Matrix not initialized yet!\n";
                    }   

                    break;
                }
                case 8: {
                    std::cout << "Returning to Main Menu...\n";
                    if (initializedMatrix) {
                        // Free dynamically allocated matrix memory
                        for (int i = 0; i < matrixRows; i++) {
                            delete[] initializedMatrix[i];
                        }
                        delete[] initializedMatrix;
                    }   
                    return;
                    }

                case 9: {
                std::cout << "Exiting Program...\n";
                if (initializedMatrix) {
                    // Free dynamically allocated matrix memory
                    for (int i = 0; i < matrixRows; i++) { // go through the list of already allocated memory and deallocate all the pointers 
                        delete[] initializedMatrix[i]; //in the list the pointers where the rows and they pointed to the columsn they auto delete with the rows
                    }
                    delete[] initializedMatrix; //now delete the array that held those pointers 
                }
                std::exit(0);
                default:
                    std::cout << "Invalid choice! Please try again.\n";
                    break;
                    }
                    
            }
        }
    }
}