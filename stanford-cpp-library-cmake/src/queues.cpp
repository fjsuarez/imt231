
// FIFO = First In First Out

// enqueue(6)
// enqueue(5)
// enqueue(2)
// enqueue(3)
// enqueue(1)

//   Back _______________________ Front
//        1     3     2    5   6
//        _______________________

// dequeue() -> 6

//   Back _______________________ Front
//        1     3     2    5
//        _______________________

// isEmpty()
// peek()
// size()

#include <iostream>
#include <collections/queue.h>

using namespace std;

int main() {
    Queue<int> queue = {12, 7, 5, 8, 9};
    Queue<int> queue2;
    int elemento;
    
    // queue.enqueue(6);
    // queue.enqueue(5);
    // queue.enqueue(2);
    // queue.enqueue(3);
    // queue.enqueue(1);

    // cout << "Tamaño de queue antes: " <<  queue.size() << endl;

    // elemento = queue.dequeue();

    // cout << "Elemento sacado: " << elemento << endl;

    // cout << "Tamaño de queue despues: " << queue.size() << endl;
    // cout << queue.isEmpty() << endl;
    // queue.dequeue();
    // queue.dequeue(); // error! queue vacio

    // for (int i = 0; i < 10; i++) {
    //     cout << "Enqueue " << i << endl;
    //     queue.enqueue(i);
    // }

    // while (!queue.isEmpty()) {
    //     cout << "Dequeue " << queue.dequeue() << endl;
    // }

    // cout << queue.toString() << endl;
    
    // queue.enqueue(1);
    // queue.enqueue(2);
    // queue.enqueue(3);
    
    // cout << queue.toString() << endl;
    // elemento = queue.peek();

    // cout << "Elemento en el frente: " << elemento << endl;

    // while (!queue.isEmpty()) {
    //     cout << "Dequeue " << queue.dequeue() << endl;
    // }

    // implementar una pila con dos colas

    while (!queue.isEmpty()) {
        int tam = queue.size();
        for (int i = 0; i < (tam-1); i++) {
            queue.enqueue(queue.dequeue());
        }
        
        cout << queue.toString() << endl;
        queue2.enqueue(queue.dequeue());
    }

    cout << queue2.toString() << endl;
    return 0;
}