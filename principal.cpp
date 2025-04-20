/******************************************************************************
Brenda Griselda Morales Velazquez 

actividad 3

calcular rfc co las reglas del sat 
*******************************************************************************/
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

// Función para obtener la primera vocal interna del apellido paterno
char obtenerPrimeraVocalInterna(const std::string& str) {
    for (size_t i = 1; i < str.length(); ++i) {
        char c = toupper(str[i]);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return c;
    }
    return 'X';
}

//// Verifica si una palabra es malformada (prohibida)
void corregirPalabraProhibida(std::string& rfc, const std::unordered_set<std::string>& palabrasProhibidas) {
    std::string primeras4 = rfc.substr(0, 4);
    if (palabrasProhibidas.count(primeras4)) {
        rfc[3] = 'X';  // Cambia la última letra por 'X'
    }
}

// Función para calcular RFC
std::string calcularRFC(const std::string& nombre, const std::string& apellidoPaterno, const std::string& apellidoMaterno, const std::string& fechaNacimiento) {
    std::string rfc;

    char letraInicial = toupper(apellidoPaterno[0]);
    char primeraVocalInterna = obtenerPrimeraVocalInterna(apellidoPaterno);
    char inicialApellidoMaterno = (!apellidoMaterno.empty()) ? toupper(apellidoMaterno[0]) : 'X';
    char inicialNombre = toupper(nombre[0]);

    std::string anio = fechaNacimiento.substr(2, 2);
    std::string mes = fechaNacimiento.substr(5, 2);
    std::string dia = fechaNacimiento.substr(8, 2);

    rfc = letraInicial;
    rfc += primeraVocalInterna;
    rfc += inicialApellidoMaterno;
    rfc += inicialNombre;
    rfc += anio;
    rfc += mes;
    rfc += dia;

    // Diccionario de palabras mal formadas
    std::unordered_set<std::string> palabrasProhibidas = {
        "PENE", "PUTA", "PUTO", "QULO", "N"
    };

    corregirPalabraProhibida(rfc, palabrasProhibidas);

    return rfc;
}

int main() {
    std::string nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento;

    std::cout << "Ingrese el nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Ingrese el apellido paterno: ";
    std::getline(std::cin, apellidoPaterno);
    std::cout << "Ingrese el apellido materno (si no tiene, presione Enter): ";
    std::getline(std::cin, apellidoMaterno);
    std::cout << "Ingrese la fecha de nacimiento (YYYY-MM-DD): ";
    std::getline(std::cin, fechaNacimiento);

    std::string rfc = calcularRFC(nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento);

    std::cout << "RFC generado: " << rfc << std::endl;

    return 0;
}