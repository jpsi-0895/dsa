#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

template <typename K, typename V>
struct KeyValuePair
{
    K key;
    V value;
    KeyValuePair(K k, V v) : key(k), value(v) {}
};

template <typename K, typename V>
class CustomHashTable
{
private:
    vector<list<KeyValuePair<K, V>>> table;
    int size;
    int capacity;
    int hash(K key)
    {
        return key % capacity;
    }
    void resize()
    {
        int newCapacity = capacity * 2;
        vector<list<KeyValuePair<K, V>>> newTable(newCapacity);
        for (int i = 0; i < capacity; i++)
        {
            for (auto &kv : table[i])
            {
                int index = kv.key % newCapacity;
                newTable[index].push_back(kv);
            }
        }

        table = move(newTable);
        capacity = newCapacity;
    }

public:
    CustomHashTable(int intitialCapacity = 10)
    {
        capacity = intitialCapacity;
        table.resize(capacity);
        size = 0;
    }

    void insert(K key, V value)
    {
        if (size >= .7 * capacity)
        {
            resize();
        }

        int index = hash(key);
        for (auto &kv : table[index])
        {
            if (kv.key == key)
            {
                kv.value = value;
                return;
            }
        }

        table[index].push_back(KeyValuePair<K, V>(key, value));
        size++;
    }

    bool search(K key, V &value)
    {
        int index = hash(key);
        for (auto &kv : table[index])
        {
            if (kv.key == key)
            {
                value = key.value;
                return true;
            }
        }
        return false;
    }
    int getSize()
    {
        return size;
    }

    void printTable()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (!table[i].empty())
            {
                cout << "Bucket " << i << ": ";
                for (auto &kv : table[i])
                {
                    cout << "(" << kv.key << ", " << kv.value << ")";
                }
                cout << endl;
            }
        }
    }
};
int main()
{
    CustomHashTable<int, string> hashTable;

    hashTable.insert(1, "One");
    hashTable.insert(2, "Two");
    hashTable.insert(3, "Three");
    hashTable.insert(12, "Twelve");
    hashTable.printTable();
    return 0;
}