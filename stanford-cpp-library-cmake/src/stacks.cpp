#include <iostream>
#include <collections/stack.h>

using namespace std;

// LIFO = Last In First Out

// push(6)
// push(2)

// |     |    
// |     |
// |  2  | <-- top
// |__6__| <-- bottom

// pop() -> 2

// |     |    
// |     |
// |     | 
// |__6__| <-- top/bottom

int main() {
    Stack<int> stack;
    int elemento;
    
    // stack.push(6);
    // stack.push(2);

    // cout << "Tamaño de stack antes: " <<  stack.size() << endl;

    // elemento = stack.pop();

    // cout << "Elemento sacado: " << elemento << endl;

    // cout << "Tamaño de stack despues: " << stack.size() << endl;
    // cout << stack.isEmpty() << endl;
    // stack.pop();
    // stack.pop(); // error! stack vacio

    // for (int i = 0; i < 10; i++) {
    //     cout << "Push " << i << endl;
    //     stack.push(i);
    // }

    // while (!stack.isEmpty()) {
    //     cout << "Pop " << stack.pop() << endl;
    // }

    stack.push(1);
    stack.push(2);
    stack.push(3);

    elemento = stack.peek();

    cout << "Elemento en la cima: " << elemento << endl;

    // Iniciando con una lista de elementos, invertir el orden de los elementos en indices impares
    return 0;
}