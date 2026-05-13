#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

int main() {

    string estudiantes[] = {
        "ACOSTA SOLIS HANNA AIDE",
        "ANDRADE SANCHEZ HUGO ALEXANDER",
        "ATIENCIA CHERRES JOSUE ALEXANDER",
        "BALAREZO PEREZ DIEGO SEBASTIAN",
        "BARRIONUEVO MONTESDEOCA JOB GABRIEL",
        "BEDOYA MAZO JUAN MANUEL",
        "BRAVO LOPEZ JORDAN SAMUEL",
        "CAJIAO VALDIVIESO PAULO ALESSANDRO",
        "CALVOPIÑA HERRERA BRANDON ISRAEL",
        "CASTELO BERRONES KATHERINE NICOL",
        "CHACHA CHANGO VICTOR MANUEL",
        "CHILUIZA QUISHPE DIEGO STEED",
        "DOMINGUEZ LESCANO DANIEL SEBASTIAN",
        "FREIRE AREBALO ALAN ANDERSON",
        "GUALLE AUCANSHALA ABISAG LISENIA",
        "GUAMAN CHANAHUANO HAMILTON ALEXANDER",
        "GUANGA ALTAMIRANO EDWIN SEBASTIAN",
        "GUANOTOA ESCOBAR KARLA LEONELA",
        "LANDETA TAPIA EDISON PAUL",
        "LARA BALSECA KAREN ARACELY",
        "LOOR VELEZ JHON ALEJANDRO",
        "LOPEZ SANCHEZ WASHINGTON STEVEN",
        "MIRANDA GARCES ALAN IMANOL",
        "MONAR PARCO JHAIR ALEXANDER",
        "MUYULEMA MOYOLEMA MATEO ALEXANDER",
        "NARVAEZ GAVILANES ANTONELLA NICOLE",
        "NUÑEZ ESPIN BRYAN SEBASTIAN",
        "PILCO FLORES MARIO DAVID",
        "POMAQUERO CHANGO KATHERINE SOLEDAD",
        "QUEVEDO AJON GINA ANAHI",
        "RIVADENEYRA ULLOA MATIAS SEBASTIAN",
        "ROCHA ROCHA CAROLINA ESTEFANIA",
        "SANCHEZ LEMA ISAAC ADRIAN",
        "SEGOVIA GARCIA JOSEPH ANDRE",
        "SUPE GARCES JOAN SEBASTIAN",
        "TOAPANTA IZA KEVIN MATIAS",
        "VERDESOTO AZOGUE KEVIN ALEXANDER",
        "VILLACRES TOALOMBO JOSUE ALEJANDRO",
        "VITERI CAMINO MAYDELIN SHANTAL"
    };

    int opcion;
    int estudianteSeleccionado;

    double num1, num2, resultado = 0;
    double notas[5];

    double promedio = 0;
    double mayor = 0;
    double menor = 0;

    int aprobados = 0;
    int reprobados = 0;

    bool operacionesHechas = false;
    bool notasRegistradas = false;

    cout << "===== LISTA DE ESTUDIANTES =====" << endl;

    for (int i = 0; i < 39; i++) {
        cout << i + 1 << ". " << estudiantes[i] << endl;
    }

    cout << "\nSeleccione el numero del estudiante: ";
    cin >> estudianteSeleccionado;

    string nombre = estudiantes[estudianteSeleccionado - 1];

    do {

        cout << "\n===== MENU INTERACTIVO =====" << endl;
        cout << "1. Operaciones basicas" << endl;
        cout << "2. Registro de notas" << endl;
        cout << "3. Guardar resultados" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {

            int operacion;

            cout << "\nIngrese el primer numero: ";
            cin >> num1;

            cout << "Ingrese el segundo numero: ";
            cin >> num2;

            cout << "\n1. Suma" << endl;
            cout << "2. Resta" << endl;
            cout << "3. Multiplicacion" << endl;
            cout << "4. Division" << endl;
            cout << "Seleccione la operacion: ";
            cin >> operacion;

            if (operacion == 1) {

                resultado = num1 + num2;
                cout << "Resultado: " << resultado << endl;
                operacionesHechas = true;

            } else if (operacion == 2) {

                resultado = num1 - num2;
                cout << "Resultado: " << resultado << endl;
                operacionesHechas = true;

            } else if (operacion == 3) {

                resultado = num1 * num2;
                cout << "Resultado: " << resultado << endl;
                operacionesHechas = true;

            } else if (operacion == 4) {

                if (num2 != 0) {

                    resultado = num1 / num2;
                    cout << "Resultado: " << resultado << endl;
                    operacionesHechas = true;

                } else {

                    cout << "Error: no se puede dividir para cero." << endl;
                }

            } else {

                cout << "Operacion no valida." << endl;
            }

        } else if (opcion == 2) {

            double suma = 0;

            aprobados = 0;
            reprobados = 0;

            for (int i = 0; i < 5; i++) {

                do {

                    cout << "Ingrese la nota " << i + 1 << ": ";
                    cin >> notas[i];

                } while (notas[i] < 0 || notas[i] > 10);

                suma += notas[i];

                if (i == 0) {

                    mayor = notas[i];
                    menor = notas[i];
                }

                if (notas[i] > mayor) {

                    mayor = notas[i];
                }

                if (notas[i] < menor) {

                    menor = notas[i];
                }

                if (notas[i] >= 7) {

                    aprobados++;

                } else {

                    reprobados++;
                }
            }

            promedio = suma / 5;

            notasRegistradas = true;

            cout << "\nPromedio: " << promedio << endl;
            cout << "Nota mayor: " << mayor << endl;
            cout << "Nota menor: " << menor << endl;
            cout << "Aprobados: " << aprobados << endl;
            cout << "Reprobados: " << reprobados << endl;

        } else if (opcion == 3) {

            ofstream archivo("resultados.txt");

            time_t ahora = time(0);

            archivo << "Nombre del estudiante: " << nombre << endl;
            archivo << "Fecha: " << ctime(&ahora);
            archivo << "Lenguaje utilizado: C++" << endl;

            if (operacionesHechas) {

                archivo << "\nResultado de operacion matematica: " << resultado << endl;

            } else {

                archivo << "\nNo se realizaron operaciones matematicas." << endl;
            }

            if (notasRegistradas) {

                archivo << "\nPromedio: " << promedio << endl;
                archivo << "Nota mayor: " << mayor << endl;
                archivo << "Nota menor: " << menor << endl;
                archivo << "Aprobados: " << aprobados << endl;
                archivo << "Reprobados: " << reprobados << endl;

            } else {

                archivo << "\nNo se registraron notas." << endl;
            }

            archivo.close();

            cout << "Resultados guardados en resultados.txt" << endl;

        } else if (opcion == 4) {

            cout << "Saliendo del programa..." << endl;

        } else {

            cout << "Opcion no valida." << endl;
        }

    } while (opcion != 4);

    return 0;
}
