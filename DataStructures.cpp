#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <>

using namespace std;


template <typename T>
class Queue {
   private:
      void **array;
      int head;
      int tail;
      int array_capacity;
      int initial_capacity;
      int size;

   public:
      Queue( int );
      Queue( Queue const & );
      ~Queue();

      bool empty() const;
      int size() const;
      T front() const;

      void push( T const & );
      void pop();
};

template <typename T>
class LinkedList
{
    private:
    struct node
    {
        T value;
        node *pnext;
    };

    node *head;

    public:
    LinkedList();
    void insert_front(T value);
    void push_back(T value);
    int length();
    void reverse();
    T nth(int n);
    void print();
};

template <typename T>
class DynamicArray
{
private:
    int size_;
    int max_;
    int *arrayholder_;

public:
    DynamicArray()
    {
        this->size = 0;
        this->max = 5;
        this->arrayholder = new int[5];
    }

    ~DynamicArray()
    {
        delete[] this->arrayholder_;
    }

    int size()
    {
        return this->size;
    }

    int& operator[](int i) 
    {
        assert(i < this->size);
        return this->arrayholder[i];
    }

    void add(int n)
    {
        if (this->max < this->size + 1)
        {
            this->max *= 2;
            int *tmp = new int[this->max];

            for (sizet i = 0; i < this->size; i++)
            {
                tmp[i] = this->arrayholder[i];              
            }
            delete[] this->arrayholder;
            this->arrayholder = tmp;
            this->arrayholder[this->size] = n;
            this->size += 1;
        }
        else 
        {
            this->arrayholder[this->size] = n;
            this->size += 1;
        }
    }
};


