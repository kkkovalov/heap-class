//                  Implement max-heap:
// -------------------------------------------------------------------------------------------------------------------
// - [x]  insert
// - [x]  siftUp - needed for insert
// - [x]  getMax - returns the max item, without removing it
// - [x]  getSize() - return number of elements stored
// - [x]  isEmpty() - returns true if heap contains no elements
// - [x]  extractMax - returns the max item, removing it
// - [x]  siftDown - needed for extract_max
// - [x]  remove(x) - removes item at index x
// - [x]  heapify - create a heap from an array of elements, needed for heap_sort
// - [x]  heapSort() - take an unsorted array and turn it into a sorted array in-place using a max heap or min heap

#include <iostream>

class Heap{
    public:
        void insert(int new_value){
            if(*(heap_array + _size + 1) <= __capacity) {
                _size++;
                *(heap_array + _size) = new_value;
                siftUp(_size);
            } else {
                std::cout<<"The heap is full, remove old elements before inserting new ones."<<std::endl;
                std::cout<<"Also, resize() function is available to increase the capacity of the heap"<<std::endl;
            }
        };


        int getMax(){
            return *(heap_array + 1);
        };
        
        int getSize(){
            return _size;
        };

        bool isEmpty(){
            return !getSize();
        };

        int extractMax(){
            if(!isEmpty()) {
                int result = getMax();
                *(heap_array + 1) = *(heap_array + _size);
                *(heap_array + _size) = 0;
                _size--;
                siftDown(1);
                return result;
            } else {
                std::cout<<"The heap is empty."<<std::endl;
                return 0;
            };
        };

        void remove(int index){
            if(*(heap_array + index)){
                *(heap_array + index) = *(heap_array + _size);
                *(heap_array + _size) = 0;
                _size--;
                siftDown(index);
            } else {
                std::cout<<"Item at this location does not exist. Please try different index. Indexes start with 1 and end with "<<__capacity<<std::endl;
                return ;
            }
        };

        void heapSort(int *array){
            heapify(array, 7);
            display();
        };

        void display(){
            for(int i = 1; i <= _size; i++){
                std::cout<<*(heap_array + i)<<" ";
            };
            std::cout<<std::endl;
        };

    private:
        int _size = 0;
        int __capacity = 10;
        int *heap_array = new int[__capacity + 1]();

        void siftDown(int current_index){
            int *left_child = (heap_array + (current_index * 2)), *right_child = (heap_array + (current_index * 2 + 1));
            if(*left_child > *(heap_array + current_index) && *left_child > *right_child){
                int temp = *(heap_array + current_index);
                *(heap_array + current_index) = *left_child;
                *left_child = temp;
                siftDown(current_index * 2);
            } else if(*right_child > *(heap_array + current_index)) {
                int temp = *(heap_array + current_index);
                *(heap_array + current_index) = *right_child;
                *right_child = temp;
                siftDown(current_index * 2 + 1);
            } else return ;
        };

        void siftUp(int current_index){
            if(*(heap_array + int(current_index / 2)) < *(heap_array + current_index) && int(current_index / 2) > 0) {
                int temp = *(heap_array + int(current_index / 2));
                *(heap_array + int(current_index / 2)) = *(heap_array + current_index);
                *(heap_array + current_index) = temp;
                siftUp(int(current_index / 2));
            } else return ;
        };

        void heapify(int *array, int size){
            __capacity = size;
            _size = 0;
            delete[](heap_array);
            heap_array = new int[__capacity + 1]();
            for(int i = 0; i < size; i++){
                insert(*(array + i));
            }
        };
};

int main(){
    Heap mock;
    std::cout<<"Empty: "<<mock.isEmpty()<<std::endl;
    mock.insert(6);
    mock.insert(8);
    mock.insert(3);
    mock.insert(7);
    mock.insert(9);
    mock.insert(2);
    std::cout<<"Max: "<<mock.getMax()<<std::endl;
    std::cout<<"Size: "<<mock.getSize()<<std::endl;
    std::cout<<"Empty: "<<mock.isEmpty()<<std::endl;
    mock.display();
    std::cout<<"Max removed: "<<mock.extractMax()<<std::endl;
    mock.display();
    mock.remove(2);
    mock.display();
    int array[7] = {5, 7, 9, 1, 5, 3, 2};
    mock.heapSort(array);
};