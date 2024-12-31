#include <iostream>
#include <string>
#include <vector>


bool quitFlag = true;


int quit(){
    std::cout << "If you would like to quit the whole process please type \"end process\" " << std::endl;
    quitFlag = false;
}




void addNote(std::vector<std::string> &notesList){
    bool pass = true;
    while(pass){
        std::string note;
        std::cout << "Youve chosen to add a note! Please type what you would like.\n";
        std::cin >> note;
        if(note != " "){        
            notesList.push_back(note);
        }
        else{
            char yesNo;
            std::cout << "Did you mean to just submit a space?: (y/n)";
            std::cin >> yesNo;
            if(yesNo == 'y'){
                notesList.push_back(note);

            }
            else if(yesNo == 'n'){
                continue;

            }
            else{
                std::cout << "You typed in the wrong thig its y/n Please restart!";         // make somethign for when they dont put yes or no
                continue;

            }
        }
    }
}


void delNote(std::vector<std::string> &notesList){
    if(notesList.empty()){
        std::cout << "Sorry you cant do this right now as there is not a note to delete\n";
        return;

    }
    int count = 0;
    for(const std::string& note: notesList){ // note is the iteration and you can diredtly call it to print as 
        std::cout << count << ': ' << note << std::endl;         // it doesnt need to be notesList[note] just call note directly
        // have something make it so they can stop it from printing at anytime so they dont have to wait 
        count++;
    }
    int deleteNoteIndex;
    bool deleteFlag = true;
    std::cout << std::endl;
    std::cout << "Now that you have seen the note list, please select which note you would like to delete: ";
    while(deleteFlag){
        std::cin >> deleteNoteIndex;
        if(deleteNoteIndex >= 0 && deleteNoteIndex < notesList.size()){
            notesList.erase(notesList.begin() + deleteNoteIndex);
            std::cout<< "Deletion has been completed, would you like to delete anything else?: (y/n): ";
            char check;
            std::cin >> check;

            if(check == 'y'||check == 'Y'){
                continue;

            }
            else if(check == 'n'||check == 'N'){
                return;
            }
            else{
                std::cout << "You were asked to enter (y or n), becuase you didnt correctly choose for your saftey we will close this task";
                return ;//make sure to make a response when it returns an empty vector it just doesnt take it in or care for it
            }
            
        }

    
        else{
            std::cout << "Please enter a valid number that was shown. Please enter a number: ";
            continue;

        }
    }

    
}




void editNote(std::vector<std::string> &notesList){
    bool editFlag = true;
    if(notesList.empty()){
        std::cout << "Sorry you cant do this right now as there is not a note to edit.\n";
        return;

    }

    while(editFlag){
        int count = 0;
        for(const std::string &noteIndex : notesList){
        //Using a reference (&) instead of copying each element directly avoids unnecessary duplication,
        //allowing note to refer directly to the strings in the notesList, improving performance for large or complex objects like strings.
            std::cout << count << ': ' << noteIndex;
            count++;
        }
        int editChoice;
        std::cout << "Which note would you like to edit (Please enter the number next to the note): ";
        std::cin >> editChoice;
        std::string newnote;
        std::cout <<"\nYou chose to edit note," << notesList[editChoice] << ". Please type what youd like it to be now: " <<std::endl;
        std::cin >> newnote;
        notesList[editChoice] = newnote;
        
        std::cout << "The note has been updated, is there anything else you would like to edit (y/n): "<<std::endl;
        char yesno;
        std::cin >> yesno;
        bool yesnoFlag = true;
        while(yesnoFlag){

            if(yesno == 'y'|| yesno == 'Y' ){
                editFlag == true;
            }
            else if(yesno == 'n' || yesno == 'N'){
                menu(notesList);
            }
            else{
                std::cout << "Please try again";
                yesnoFlag = true;
            }
        }
        // also edit it so it can be swapped places for importance.
    }


}





void menu(std::vector<std::string> &notesList){
    int choice;
    bool pass = true;
    std::cout<< "     Welcome Back To Your Todo List\n";
    std::cout<< "-----------------------------------------\n";
    std::cout<< "|1. Add a task to your todo list        |\n";
    std::cout<< "|2. Delete a task from your todo list   |\n";
    std::cout<< "|3. edit a task from your todo list     |\n";
    std::cout<< "|4. Mark A task as done                 |\n";
    std::cout<< "|5. Save and Quit                       |\n";
    std::cout<< "-----------------------------------------\n";

    std::cout << "Please choose an option (1-5):\n";
    while (pass){
        std::cin >> choice;
        if(choice < 1 || choice > 5){
            std::cout << " Your choice was incorrect. Please choose an option (1-5):\n";
            pass = true;
            
        }
        else if(choice >= 1 && choice <= 5){
            switch (choice)
            {
            case 1:
                addNote(notesList);
                break;
            case 2:
                delNote(notesList);
                break;
            case 3:
                editNote(notesList);
                break;
            case 4:
                
                break;
            case 5:
                quit();
                break;
            default:
                break;
            }

        }
        else{
            std::cout << "Your input was inccorect, please choose a number 1-5.";
            pass = true;
        }

    }
}

int main(){
    std::vector<std::string> notesList;
    menu(notesList);
}


// I understand that you're looking to learn about C++ classes, objects, and dynamic memory allocation. Here are some resources to help you:
// YouTube Video Titles:
// "C++ Classes and Objects Tutorial for Beginners"
// "Understanding Dynamic Memory Allocation in C++"
// "C++ Programming: Classes and Objects Explained"
// "Mastering Dynamic Memory in C++ with 'new' and 'delete'"
// "C++ OOP: Classes, Objects, and Memory Management"
// Educational Websites:
// W3Schools C++ Tutorial: Offers comprehensive tutorials on C++ classes and objects. 
// W3SCHOOLS
// Programiz: Provides detailed explanations and examples on C++ classes and objects. 
// PROGRAMIZ
// GeeksforGeeks: Features articles on C++ classes, objects, and dynamic memory allocation. 
// GEEKSFORGEEKS
// TutorialsPoint: Contains tutorials on C++ classes, objects, and dynamic memory management. 
// TUTORIALSPOINT
// LearnCpp.com: Offers in-depth tutorials on dynamic memory allocation in C++. 