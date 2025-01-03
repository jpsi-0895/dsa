To create a **custom hash table** in C++, you'll need to implement the fundamental operations manually, including:

- **Hash Function**: Define how to map keys to indices in the table.
- **Collision Handling**: Manage cases when two keys map to the same index (using methods like **chaining** or **open addressing**).
- **Resizing**: Dynamically resize the hash table when it gets too full.

Here, we'll implement a **custom hash table** using **separate chaining** to handle collisions. Each bucket in the table will be a linked list to store key-value pairs that hash to the same index.

### Basic Structure of the Custom Hash Table

We'll use the following components:
1. **Hash Function**: A simple hash function will map keys to an index.
2. **Linked List for Chaining**: Each table index will store a linked list of key-value pairs.
3. **Basic Operations**: We'll implement **insert**, **search**, and **delete** operations.

### Custom Hash Table Implementation

```cpp
#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

// Structure to store key-value pairs
template <typename K, typename V>
struct KeyValuePair {
    K key;
    V value;

    KeyValuePair(K k, V v) : key(k), value(v) {}
};

// Custom hash table using separate chaining
template <typename K, typename V>
class CustomHashTable {
private:
    // A vector of lists for separate chaining
    vector<list<KeyValuePair<K, V>>> table;
    int size;  // Current size of the hash table
    int capacity;  // Total number of buckets in the hash table

    // Hash function to convert a key to an index
    int hash(K key) {
        return key % capacity;  // Simple modulus-based hash function
    }

    // Resize the table when the load factor is high
    void resize() {
        int newCapacity = capacity * 2;
        vector<list<KeyValuePair<K, V>>> newTable(newCapacity);

        // Rehash and move elements to the new table
        for (int i = 0; i < capacity; i++) {
            for (auto& kv : table[i]) {
                int index = kv.key % newCapacity;
                newTable[index].push_back(kv);
            }
        }

        table = move(newTable);
        capacity = newCapacity;
    }

public:
    // Constructor to initialize the table with a given capacity
    CustomHashTable(int initialCapacity = 10) {
        capacity = initialCapacity;
        table.resize(capacity);
        size = 0;
    }

    // Insert a key-value pair
    void insert(K key, V value) {
        // Resize if the load factor exceeds 0.7
        if (size >= 0.7 * capacity) {
            resize();
        }

        int index = hash(key);
        for (auto& kv : table[index]) {
            if (kv.key == key) {
                kv.value = value;  // Update value if key already exists
                return;
            }
        }

        table[index].push_back(KeyValuePair<K, V>(key, value));  // Insert new key-value pair
        size++;
    }

    // Search for a key and return its value (if found)
    bool search(K key, V& value) {
        int index = hash(key);
        for (auto& kv : table[index]) {
            if (kv.key == key) {
                value = kv.value;
                return true;
            }
        }
        return false;
    }

    // Delete a key-value pair
    bool deleteKey(K key) {
        int index = hash(key);
        auto& chain = table[index];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->key == key) {
                chain.erase(it);  // Remove the key-value pair
                size--;
                return true;
            }
        }
        return false;  // Key not found
    }

    // Print the contents of the hash table
    void printTable() {
        for (int i = 0; i < capacity; i++) {
            if (!table[i].empty()) {
                cout << "Bucket " << i << ": ";
                for (auto& kv : table[i]) {
                    cout << "(" << kv.key << ", " << kv.value << ") ";
                }
                cout << endl;
            }
        }
    }

    // Get the current size of the hash table
    int getSize() {
        return size;
    }
};

int main() {
    // Create a custom hash table with integer keys and string values
    CustomHashTable<int, string> hashTable;

    // Insert key-value pairs
    hashTable.insert(1, "One");
    hashTable.insert(2, "Two");
    hashTable.insert(3, "Three");
    hashTable.insert(12, "Twelve");

    // Search for a key
    string value;
    if (hashTable.search(3, value)) {
        cout << "Found key 3: " << value << endl;
    } else {
        cout << "Key 3 not found!" << endl;
    }

    // Delete a key-value pair
    if (hashTable.deleteKey(2)) {
        cout << "Key 2 deleted!" << endl;
    } else {
        cout << "Key 2 not found!" << endl;
    }

    // Print the hash table contents
    hashTable.printTable();

    return 0;
}
```

### Key Components of the Code:

1. **KeyValuePair**: This structure holds the key-value pairs.
   
2. **CustomHashTable Class**: 
   - **Vector of Lists**: We use a vector of lists for **separate chaining**. Each list at an index represents a bucket where collisions are handled.
   - **Hash Function**: The simple modulus-based hash function, `key % capacity`, maps keys to indices in the hash table. A more complex hash function can be used depending on the key type.
   - **Resize Function**: The `resize` function doubles the size of the hash table when the load factor (size/capacity) exceeds 0.7. This ensures that the table remains efficient as more elements are added.
   - **Insert, Search, Delete**: Basic hash table operations:
     - **Insert**: Adds a key-value pair. If the key already exists, it updates the value.
     - **Search**: Looks for a key and returns its value if found.
     - **Delete**: Removes a key-value pair if the key exists.
   
3. **Main Function**: Demonstrates how to use the custom hash table with basic operations like insertion, deletion, searching, and printing the contents of the hash table.

### Time and Space Complexity:

- **Insert**: 
  - **Average Case**: O(1), since we directly calculate the index for insertion.
  - **Worst Case**: O(n), when all keys hash to the same bucket (very rare in practice).
  
- **Search**:
  - **Average Case**: O(1), directly compute the index.
  - **Worst Case**: O(n), in case of heavy collisions.
  
- **Delete**:
  - **Average Case**: O(1), direct index lookup.
  - **Worst Case**: O(n), in case of collisions.

- **Space Complexity**: O(n), where `n` is the number of key-value pairs in the table.

### Enhancements:
- **Improved Hash Function**: You can improve the hash function to reduce collisions. A more advanced function like **MurmurHash** or **SHA** might provide better performance for complex keys.
- **Open Addressing**: Instead of using a linked list, you could use open addressing techniques like **linear probing** or **quadratic probing** for collision resolution.
