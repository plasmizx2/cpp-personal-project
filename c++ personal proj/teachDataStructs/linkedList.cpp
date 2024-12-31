#include <iostream>
#include "dsMenu.cpp"
#include <string>
#include <vector>

class Node{
public:
    int value;
    Node* nextNode;

    Node(int currentValue){
        value = currentValue;
        nextNode = nullptr;
    }   

};

class LinkedList{
public: 
    Node* head;

    LinkedList(){
        head = nullptr;
        //we do this so automatically everything goes to null and
        //can be changed later whether they want it null or not.
    }

void insertAtBeginning(int value2add){
        // Step 1: Create a new node with the input value
        Node* newNode = new Node(value2add);
        // Now `newNode` points to a new memory block that stores the input value.
        // Step 2: Link the new node to the current head of the list
        newNode->nextNode = head;
        // At this point:
        // - The new node points to the current first node in the list (if any).
        // - If the list is empty, `head` is nullptr, so the new node points to null.

        // Step 3: Update the head pointer to point to the new node
        head = newNode;
        // You are making the head pointer point to the same memory location that newNode points to. In other words, you're saying:
        //"The head of the linked list now refers to this new node."
}

void insertAtEnd(int value2add){
    Node* newNode = new Node(value2add); //Allocate memory for the dynamically made node and then create the node 

    //now we should check if the linked list is empty
    if(head == nullptr){    
        head = newNode; // if its empty basically make the head the new node so it points to null after and return.
        return;        
    }
    Node* tempPtr = head; // make the secondary pointer aka temp pointer point to the head so it can traverse through the list
    while(tempPtr->nextNode != nullptr){
        tempPtr = tempPtr->nextNode; // prior to this has the same meory has head and head has a next pointer 
                                    // as its traversing that secondary pointer is going to continue to equal whatever the next node is.
    }
    tempPtr ->nextNode = newNode; // now that the next node = nullPtr the tempPtr next node should equal whatever the newNode was placing it at the end of the list.
    
}

void reverseList(){
    Node* prev = nullptr; // memory location for prev, pointers are essentially memory locations that hold the addresses of other variables or objects
    Node* current = head; //memory location for current, pointers, and pointers are essentially memory locations that hold the addresses of other variables or objects
    Node* next = nullptr; // memory location for next, pointers, and pointers are essentially memory locations that hold the addresses of other variables or objects

    while(current != nullptr){ // if current = nullPtr that means theres nothing after it.
        next = current->nextNode; // 
        current->nextNode = prev;

        // now we need to traverse through the list.
        prev = current;
        current = next;
    }
    head = prev;  // Update head to the last processed node, the one at the end is not the start but it all points backwards now.

}

void deleteNodeByValue(int value2del){
    if(head == nullptr){ // if its empty theres nothing to delete so do nothing
        return;
    }

    if(head->value == value2del){ // if the head is the value you want to delete
        Node* tempPtr = head; // this is not syntax needed, but is needed for memory leaks, 
                          // we are doing this to keep the memory address for the old head, so doing this we store old heads memory.

        head = head->nextNode = head; // we want the next node of head to be placed inside of the orginal heads memory address.
        // we dont want memory leaks and we dont want the old memory address anymore so we free the memory.
        delete tempPtr;
    }

    //now what if we dont want to delete the first value?
    Node * tempPtr = head; //start the traversal
    while(tempPtr->nextNode != nullptr && tempPtr->nextNode->value != value2del){//making sure the next pointer isnt null and that the value isnt the value to delete
        tempPtr = tempPtr->nextNode;
    }
    //now lets say the value isnt in the list, then you should just return.
    if(tempPtr->nextNode == nullptr){
        std::cout << "The value you want deleted was not found.\n";
        return;
    }

    Node* nodeToDelete = tempPtr->nextNode;// as i didnt realize prior your checking to see if the temporary pointers next nodes value is the value to delete if it is make the 
                                            // node you want to delete the next node of the temp node.
    tempPtr ->nextNode = nodeToDelete->nextNode;// the temp nodes next node  will point to the node you want to deletes next node.
    delete nodeToDelete; // delete this node/value and free up the memory.


}

bool search4Value(int value2Find){
    Node* temp = head; // create the pointer to traverse
    while(temp != nullptr){ 
        if(temp->value != value2Find){ // if the temp pointers value isnt the value to find
            temp = temp->nextNode; // make the temp pointer become the next one and continue to the next 
            continue;
        }
        else{
            return true;    
        }
    }
    return false;
    
}


int getLength(){
    int countNodes = 0;

    Node*temp = head;
    while(temp != nullptr){
        countNodes++;
        temp = temp->nextNode;
    }
    std::cout << "The amount of nodes is " << countNodes << " In the linked list \n";
    return countNodes;
}

int getNthNode(int n){
    int countNode = 0;
    Node* temp = head;

    while(temp != nullptr){
        if(countNode == n){
            return temp->value;
        }
        countNode++;
        temp = temp->nextNode;

    }
    std::cout<< "The input number was larger than the list.";
    return -1;

}

void displayNodes(Node* currentNode){
    while(currentNode != NULL){
        std::cout << currentNode->value << std::endl;
        currentNode = currentNode->nextNode;
    }
    std::cout<< "Null (You are at the end of the list)\n";
}

};

void displayMenu(){
    std::cout << "\n----- Linked List Menu -----\n";
    std::cout << "|============================|\n";
    std::cout << "|1. Insert at Beginning      |\n";
    std::cout << "|2. Insert at End            |\n";
    std::cout << "|3. Display List             |\n";
    std::cout << "|4. Reverse List             |\n";
    std::cout << "|5. Delete Node by Value     |\n";
    std::cout << "|6. Search for a Value       |\n";
    std::cout << "|7. Get List Length          |\n";
    std::cout << "|8. Get N-th Node            |\n";
    std::cout << "|9. Exit                     |\n";
    std::cout << "|============================|\n";
    std::cout << "\n";
    std::cout << "Enter your choice: \n";
}

void startEmptyFilled(LinkedList& list){ // pass the list by refrence at the start so we can use the same list obejct everywhere
    int emptyFullChoice;
    std::cout<< "Would you like to start youre linked list empty or filled? (0 = filled, 1 = empty) \n";
    std::cin >> emptyFullChoice;

    if(emptyFullChoice == 0){
        for(int insert = 1;insert < 6; insert++){
            list.insertAtEnd(insert);
            std::cout<< "Node has been inserted \n";
        }
        std::cout << displayNodes(this->list.head);
        std::cout<< "The linked list has been created with values. You may work on them now! \n";
    }
    else if(emptyFullChoice == 1){
        std::cout << "starting with a empty list\n";
    }
    else{
        std::cout << "The choice you made was invalid, this will default in a empty list\n";

    }
}

int linkedListMenu(){
    LinkedList* list;
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








