#include <iostream>
#include <string>
#include <vector>


using namespace std;

struct Problem {
    int priorytet;
    string kategoria;

    Problem() : priorytet(0), kategoria("") {}
    Problem(int priorytet, const string& kategoria) : priorytet(priorytet), kategoria(kategoria) {}
};

class Kopiec {
public:
    vector<Problem> heap;
    
    void insert(const Problem& problem) {
        heap.push_back(problem);
        int index = heap.size() - 1;

        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index].priorytet > heap[parentIndex].priorytet) {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            }
            else {
                break;
            }
        }
    }
    
    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void heapify(int i) {
        int i_left = left(i), i_right = right(i);
        int i_max = i;

        if (i_left < heap.size() && heap[i_left].priorytet > heap[i_max].priorytet)
            i_max = i_left;

        if (i_right < heap.size() && heap[i_right].priorytet > heap[i_max].priorytet)
            i_max = i_right;

        if (i != i_max) {
            swap(heap[i], heap[i_max]);
            heapify(i_max);
        }
    }

    void heap_pop() {
        if (heap.empty()) {
            cout << "kopiec jest pusty" << endl;
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
    }

    void merge(const Kopiec& otherHeap) {
        for (const Problem& problem : otherHeap.heap) {
            insert(problem);
        }
        buildHeap();
    }

    void divide() {
       
        vector<string> categories;

        for (size_t i = 0; i < heap.size(); ++i) {
            bool categoryFound = false;
            for (size_t j = 0; j < categories.size(); ++j) {
                if (categories[j] == heap[i].kategoria) {
                    categoryFound = true;
                    break;
                }
            }

            if (!categoryFound) {
                categories.push_back(heap[i].kategoria);
            }
        }

        vector<Kopiec> smallerHeaps(categories.size());

        for (size_t i = 0; i < heap.size(); ++i) {
            int categoryIndex = -1;
            for (size_t j = 0; j < categories.size(); ++j) {
                if (categories[j] == heap[i].kategoria) {
                    categoryIndex = static_cast<int>(j);
                    break;
                }
            }

            if (categoryIndex != -1) {
                smallerHeaps[categoryIndex].insert(heap[i]);
            }
        }

        for (size_t i = 0; i < smallerHeaps.size(); ++i) {
            smallerHeaps[i].display();
        }
    }

    void display() const {
        for (const Problem& problem : heap) {
            cout << "Priority: " << problem.priorytet
                << ", Category: " << problem.kategoria << endl;
        }
        cout << "------------------------" << endl;
    }

private:
    int parent(int i) {
        return (i - 1) / 2;
    }

    void buildHeap() {
        for (int i = heap.size() / 2 - 1; i >= 0; --i) {
            heapify(i);
        }
    }
};


int main() {
    Kopiec namiestnikHeap;

    cout << "insert:" << endl;
    namiestnikHeap.insert(Problem(8, "zagrozenie militarne"));
    namiestnikHeap.insert(Problem(10, "zagrozenie wewnetrzne"));
    namiestnikHeap.insert(Problem(5, "zagrozenie militarne"));
    namiestnikHeap.insert(Problem(2, "finanse"));
    namiestnikHeap.insert(Problem(1, "zagrozenie militarne"));
    namiestnikHeap.insert(Problem(6, "dyplomacja"));
    namiestnikHeap.insert(Problem(3, "zagrozenie militarne"));
    namiestnikHeap.insert(Problem(4, "finanse"));
    namiestnikHeap.insert(Problem(9, "zagrozenie militarne"));
    namiestnikHeap.insert(Problem(7, "dyplomacja"));

    namiestnikHeap.display();

    cout << "pop :" << endl;
    namiestnikHeap.heap_pop();
    namiestnikHeap.display();

    Kopiec pomoc;
    pomoc.insert(Problem(10, "finanse"));
    pomoc.insert(Problem(9, "dyplomacja"));
    pomoc.insert(Problem(1, "dyplomacja"));
    cout << "przychodza nowe raporty:" << endl;
    pomoc.display();

    namiestnikHeap.merge(pomoc);

    cout << "po polaczeniu: " << endl;
    namiestnikHeap.display();



    cout << "podzielenie na kategorie: " << endl;
    namiestnikHeap.divide();
    namiestnikHeap.display();

    return 0;
}
