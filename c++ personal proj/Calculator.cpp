#include <iostream>
#include <vector>


std::vector<int> getNumbers(){
    char choice;
    std::vector<int> numbersV;
    int num;

    int i = 1;
    while( i !=0){
        std::cout << "Enter a number (int)." << std::endl;
        std::cin >> num;
        numbersV.push_back(num);
        std::cout << "Do you want to add another number? Type y or n" << std::endl;
        std::cin >> choice;
        if(choice != 'y'){
            std::cout << "You didnt type y, this means you dont want to add another number!" <<std::endl;
            i = 0;
        }
    }
    return numbersV;
}


char chooseOperation(){
    char opChoice;
    int i = 1;
    std::cout << "Please enter what operation youd like (+, /, -, x): ";
    std::cin >> opChoice;
    while (i != 0){
        if(opChoice != '+' && opChoice != '/' && opChoice != '-' && opChoice != 'x'){
            std::cout << "You didnt choose a usable operation. Please try again" << std::endl;
        }
        else if (opChoice == 'x'){
            opChoice = '*';
            return opChoice;
        }

        else{
            i = 0;
            return opChoice;
        }


    }


}

int mathwork (const std::vector<int> numbers, char operation){
    int answer = numbers[0];
    for(int i = 1;i < numbers.size();i++){
        if(operation == '+' ){
            answer  = answer + numbers[i];
        }
        else if(operation == '*' ){
            answer  = answer * numbers[i];
        }
        else if(operation == '-' ){
            answer  = answer - numbers[i];
        }
        else if(operation == '/' ){
            if (numbers[i] == 0){
                std::cout << "There is not possible way to divide a number by 0 this would lead to an error" << std::endl;
                return 0;
            }
            answer  = answer / numbers[i];
        }
    }
    return answer;
    
}

int main(){
    std::vector<int> numbers = getNumbers();

    char operation = chooseOperation();

    int answer = mathwork (numbers,operation);

    std::cout << "The answer to the problem is: " << answer;
    
    
    
    return 0;
    
}