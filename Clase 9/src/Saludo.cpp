#include "Saludo.hpp"
#include <sstream>

using namespace std;

string generarSaludo(const string &nombre)
{
    stringstream ss;
    ss << "Hola, " << nombre << "!";
    return ss.str();
}