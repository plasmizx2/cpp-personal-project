#include <iostream>
#include <list>
#include <string>
#include <unordered_map>


class HashTable {
private:
    static const int hashGroups = 10;
    std::list<std::pair<int, std::string>> table[hashGroups];

public:
    bool isEmpty() const;
    int hashFunction(int key);
    bool insertItem(int key, std::string value);
    bool removeItem(int key,std::string value);
    std::string searchTable(int key);
    void printTable();
};

bool HashTable::isEmpty() const {
    int sum{};
    for (int i{0}; i < hashGroups; i++) {
        sum += table[i].size();
    }

    if (!sum) {
        return true;
    }
    return false;
}


int HashTable::hashFunction(int key) {
    return key % hashGroups; // Key: 905, in return, this function will spit out 5.
}


bool HashTable::insertItem(int key, std::string value) {
    int bucketHashValue = hashFunction(key);// Find hash value of whatever ur key is so it can later be found inside the hash table
    std::list<std::pair<int,std::string>>& bucket = table[bucketHashValue]; //now going inside ur hashtable with the hashed key locate the space where the hashed key is.
    // We'll iterate through the list to find an existing key so we need a flag to let us know if we found it or not.

    //declare the type of iterator is as u can just use a normal for(int i - 0) remeber it says ::iterator
    std::list<std::pair<int, std::string>>::iterator hashTableIterator;
    //the way we iterate it is we check to see if its the end of the hashtable or the null part and if it isnt than iterate 
    for(hashTableIterator = bucket.begin();hashTableIterator != bucket.end();hashTableIterator++){
        if (hashTableIterator->first == key) { //if the iterator first part of the pair equals the key then
            hashTableIterator->second = value;  // Update value
            return false;        // Return false to indicate update (not insertion)
        }
    }
    //Scenario	                                            Will it Update?	Will it Add a New Entry?
    //Insert new key	                                     ❌ No	✅ Yes
    //Insert same key again	                                ✅ Yes	❌ No
    //Two different keys, same hash (collision)	            ❌ No	✅ Yes
    // If we reach this point, the key was not found, so insert a new one
    bucket.push_back(std::make_pair(key, value));
    return true;  // A new key-value pair was added
}

bool HashTable::removeItem(int key,std::string value){
    int bucketHashValue = hashFunction(key);
    std::list<std::pair<int,std::string>>& bucket = table[bucketHashValue];

    //make itterator for forloop
    std::list<std::pair<int, std::string>>::iterator hashTableIterator;
    for(hashTableIterator = bucket.begin();hashTableIterator != bucket.end();hashTableIterator++){
        if(hashTableIterator->first == key && hashTableIterator->second == value){
            bucket.erase(hashTableIterator);
            std::cout<<" deleted succesfully" << "\n";
            return true;
        }
    }
    std::cout << "Key not found!" << "\n";
    return false;  // Return false if the key-value pair was not found

}

std::string searchTable(int key){
    int bucketHashValue = hashFunction(key);
    std::list<std::pair<int,std::string>>& bucket =table[bucketHashValue];
    
    std::list<std::pair<int,std::string>>::iterator hashTableIterator;
    for(hashTableIterator = bucket.begin();hashTableIterator != bucket.end();hashTableIterator++){
        

    }
    
}
void printTable(){

}

