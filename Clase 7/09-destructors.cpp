#include <iostream>
using namespace std;

class MiClase {
public:
    MiClase(int x) : x(x) {
        cout << "LLamando a Constructor " << x << endl;
        datos = new int[x];
    }
    ~MiClase() {
        delete[] datos;
        cout << "Llamando a Destructor " << x <<  endl;
    }
    int x;
    private:
    int* datos;
};


int main() {
    MiClase objeto(1);
    MiClase objeto2(2);
    MiClase objeto3(3);
    MiClase* ptr = new MiClase(4);
    cout << "El programa continua..." << endl;
    delete ptr;
    return 0;
}