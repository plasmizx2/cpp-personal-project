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
    void insertItem(int key, std::string value);
    void removeItem(int key);
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


void HashTable::insertItem(int key, std::string value) {
    int hashValue = hashFunction(key);// Find hash value of whatever ur key is so it can later be found inside the hash table
    std::list<std::pair<int,std::string>>& hashTablecell = table[hashValue]; //now going inside ur hashtable with the hashed key locate the space where the hashed key is.
    std::list<std::pair<int,std::string>> BucketbeginIterator = hashTablecell.begin();// start 
    bool keyExists = false;
}
