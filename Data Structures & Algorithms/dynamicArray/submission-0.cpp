class DynamicArray {
    int cap;
    int len;
    int* arr;
public:
    DynamicArray(int capacity) : cap(capacity), len(0) {
        arr = new int[cap];
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
        if (len == cap) {
            resize();
        }
        arr[len++] = n;
    }

    int popback() {
        return arr[--len];
    }

    void resize() {
        cap *= 2;
        int* newArr = new int[cap];
        int* oldArr = arr;
        for (int i = 0; i < len; i++) {
            newArr[i] = arr[i];
        }
        arr = newArr;
        delete[] oldArr;
    }

    int getSize() {
        return len;
    }

    int getCapacity() {
        return cap;
    }
};
