class DynamicArray {
private :
    int*    arr;
    int     size;
    int     capacity;
public:

    DynamicArray(int capacity) {
        if (capacity <= 0)
            throw std::invalid_argument("Invalid argument !");
        this->capacity = capacity;
        this->size = 0;
        this->arr = new int[capacity];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (size == capacity)
            resize();
        arr[size++] = n;
    }

    int popback() {
        return (arr[--size]);
    }

    void resize() {
        capacity *= 2;
        int* bigger = new int[capacity];
        for (int i = 0; i < size; i++)
            bigger[i] = arr[i];
        delete[] arr;
        arr = bigger;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
