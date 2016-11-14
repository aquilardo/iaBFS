#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Grafo.h"

using namespace std;

int main()
{
    Grafo G;
    Grafo W;
    G.Inicializa();
    W.Inicializa();
    int opc;

    G.InsertaVertice("Arad");
    G.InsertaVertice("Zerind");
    G.InsertaVertice("Timisoara");
    G.InsertaVertice("Oradea");
    G.InsertaVertice("Sibiu");
    G.InsertaVertice("Lugoj");
    G.InsertaVertice("Mehadia");
    G.InsertaVertice("Drobeta");
    G.InsertaVertice("Craiova");
    G.InsertaVertice("Rimnicu Vilcea");
    G.InsertaVertice("Fagaras");
    G.InsertaVertice("Pitesti");
    G.InsertaVertice("Bucharest");
    G.InsertaVertice("Giurgiu");
    G.InsertaVertice("Hirsova");
    G.InsertaVertice("Eforie");
    G.InsertaVertice("Vaslui");
    G.InsertaVertice("Iasi");
    G.InsertaVertice("Neamt");
    G.InsertaVertice("Urziceni");

    G.InsertaArista(G.GetVertice("Arad"), G.GetVertice("Zerind"), 75);
    G.InsertaArista(G.GetVertice("Zerind"), G.GetVertice("Arad"), 75);
    G.InsertaArista(G.GetVertice("Zerind"), G.GetVertice("Oradea"), 71);
    G.InsertaArista(G.GetVertice("Oradea"), G.GetVertice("Zerind"), 71);
    G.InsertaArista(G.GetVertice("Oradea"), G.GetVertice("Sibiu"), 151);
    G.InsertaArista(G.GetVertice("Sibiu"), G.GetVertice("Oradea"), 151);
    G.InsertaArista(G.GetVertice("Sibiu"), G.GetVertice("Fagaras"), 99);
    G.InsertaArista(G.GetVertice("Fagaras"), G.GetVertice("Sibiu"), 99);
    G.InsertaArista(G.GetVertice("Fagaras"), G.GetVertice("Bucharest"), 211);
    G.InsertaArista(G.GetVertice("Bucharest"), G.GetVertice("Fagaras"), 211);
    G.InsertaArista(G.GetVertice("Sibiu"), G.GetVertice("Rimnicu Vilcea"), 80);
    G.InsertaArista(G.GetVertice("Rimnicu Vilcea"), G.GetVertice("Sibiu"), 80);
    G.InsertaArista(G.GetVertice("Rimnicu Vilcea"), G.GetVertice("Pitesti"), 97);
    G.InsertaArista(G.GetVertice("Pitesti"), G.GetVertice("Rimnicu Vilcea"), 97);
    G.InsertaArista(G.GetVertice("Pitesti"), G.GetVertice("Bucharest"), 101);
    G.InsertaArista(G.GetVertice("Bucharest"), G.GetVertice("Pitesti"), 101);
    G.InsertaArista(G.GetVertice("Rimnicu Vilcea"), G.GetVertice("Craiova"), 146);
    G.InsertaArista(G.GetVertice("Craiova"), G.GetVertice("Rimnicu Vilcea"), 146);
    G.InsertaArista(G.GetVertice("Craiova"), G.GetVertice("Pitesti"), 138);
    G.InsertaArista(G.GetVertice("Pitesti"), G.GetVertice("Craiova"), 138);

    G.InsertaArista(G.GetVertice("Arad"), G.GetVertice("Sibiu"), 140);
    G.InsertaArista(G.GetVertice("Sibiu"), G.GetVertice("Arad"), 140);

    G.InsertaArista(G.GetVertice("Arad"), G.GetVertice("Timisoara"), 118);
    G.InsertaArista(G.GetVertice("Timisoara"), G.GetVertice("Arad"), 118);
    G.InsertaArista(G.GetVertice("Timisoara"), G.GetVertice("Lugoj"), 111);
    G.InsertaArista(G.GetVertice("Lugoj"), G.GetVertice("Timisoara"), 111);
    G.InsertaArista(G.GetVertice("Lugoj"), G.GetVertice("Mehadia"), 70);
    G.InsertaArista(G.GetVertice("Mehadia"), G.GetVertice("Lugoj"), 70);
    G.InsertaArista(G.GetVertice("Mehadia"), G.GetVertice("Drobeta"), 75);
    G.InsertaArista(G.GetVertice("Drobeta"), G.GetVertice("Mehadia"), 75);

    G.InsertaArista(G.GetVertice("Bucharest"), G.GetVertice("Giurgiu"), 90);
    G.InsertaArista(G.GetVertice("Giurgiu"), G.GetVertice("Bucharest"), 90);

    G.InsertaArista(G.GetVertice("Bucharest"), G.GetVertice("Urziceni"), 85);
    G.InsertaArista(G.GetVertice("Urziceni"), G.GetVertice("Bucharest"), 85);

    G.InsertaArista(G.GetVertice("Urziceni"), G.GetVertice("Hirsova"), 98);
    G.InsertaArista(G.GetVertice("Hirsova"), G.GetVertice("Urziceni"), 98);

    G.InsertaArista(G.GetVertice("Hirsova"), G.GetVertice("Eforie"), 86);
    G.InsertaArista(G.GetVertice("Eforie"), G.GetVertice("Hirsova"), 86);


    G.InsertaArista(G.GetVertice("Urziceni"), G.GetVertice("Vaslui"), 142);
    G.InsertaArista(G.GetVertice("Vaslui"), G.GetVertice("Urziceni"), 142);

    G.InsertaArista(G.GetVertice("Vaslui"), G.GetVertice("Iasi"), 92);
    G.InsertaArista(G.GetVertice("Iasi"), G.GetVertice("Vaslui"), 92);

    G.InsertaArista(G.GetVertice("Iasi"), G.GetVertice("Neamt"), 87);
    G.InsertaArista(G.GetVertice("Neamt"), G.GetVertice("Iasi"), 86);


    W.InsertaVertice("S");
    W.InsertaVertice("Hola");
    W.InsertaVertice("hoy");
    W.InsertaVertice("es");
    W.InsertaVertice("lunes");
    W.InsertaVertice("primer");
    W.InsertaVertice("dia");
    W.InsertaVertice("de");
    W.InsertaVertice("la");
    W.InsertaVertice("semana");
    W.InsertaVertice("noviembre");

    W.InsertaArista(W.GetVertice("S"), W.GetVertice("Hola"), 2);
    W.InsertaArista(W.GetVertice("S"), W.GetVertice("hoy"), 1);
    W.InsertaArista(W.GetVertice("Hola"), W.GetVertice("es"), 5);
    W.InsertaArista(W.GetVertice("Hola"), W.GetVertice("lunes"), 1);
    W.InsertaArista(W.GetVertice("hoy"), W.GetVertice("primer"), 1);
    W.InsertaArista(W.GetVertice("hoy"), W.GetVertice("dia"), 3);
    W.InsertaArista(W.GetVertice("primer"), W.GetVertice("de"), 5);
    W.InsertaArista(W.GetVertice("primer"), W.GetVertice("la"), 2);
    W.InsertaArista(W.GetVertice("dia"), W.GetVertice("semana"), 4);
    W.InsertaArista(W.GetVertice("dia"), W.GetVertice("noviembre"), 1);

    do
    {
        system("cls");
        printf("\n ******************************************************************************\n\n");
        printf(" **********  BIENVENIDO AL PROGRAMA DE BUSQUEDA PRIMERO EL MEJOR  ***********\n");
        printf("\n ******************************************************************************\n");
        cout<<"1. Ingresar Vertice"<<endl;
        cout<<"2. Ingresar arista"<<endl;
        cout<<"3. Lista de adyacencia Turista"<<endl;
        cout<<"4. Lista de adyacencia Palabras"<<endl;
        cout<<"5. Tamaño"<<endl;
        cout<<"6. Eliminar vertice"<<endl;
        cout<<"7. Eliminar arista"<<endl;
        cout<<"8. Anular"<<endl;
        cout<<"9. Viajando por Rumania"<<endl;
        cout<<"10. Buscador Palabras"<<endl;
        cout<<"11. Salir"<<endl;
        cout<<endl<<"Elija una opcion: ";
        cin>>opc;
        switch(opc)
        {
        case 1:
        {
            string nombre;
            system("cls");
            cout<<"Ingrese el nombre del vertice: ";
            cin.ignore();
            getline(cin, nombre, '\n');
            G.InsertaVertice(nombre);
            cin.get();
            cin.get();
            break;
        }
        case 2:
        {
            string origen, destino;
            int peso;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese del nombre del vertice origen: ";
                cin.ignore();
                getline(cin, origen, '\n');
                cout<<"Ingrese el nombre del vertice destino: ";
                getline(cin, destino, '\n');
                cout<<"Ingrese el peso: ";
                cin>>peso;

                if(G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL)
                {
                    cout<<"Uno de los vertices no es valido"<<endl;
                }
                else
                {
                    G.InsertaArista(G.GetVertice(origen), G.GetVertice(destino), peso);
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 3:
        {
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                G.ListaAdyacencia();
            }
            cin.get();
            cin.get();
            break;
        }
        case 4:
        {
            system("cls");
            if(W.Vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                W.ListaAdyacencia();
            }
            cin.get();
            cin.get();
            break;
        }
        case 5:
        {
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Tamano: "<<G.Tamano()<<endl;
            }
            cin.get();
            cin.get();
            break;
        }
        case 6:
        {
            string nombre;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese el nombre del vertice a eliminar: ";
                cin.ignore();
                getline(cin, nombre, '\n');
                if(G.GetVertice(nombre) == NULL)
                {
                    cout<<"Vertice invalido"<<endl;
                }
                else
                {
                   G.EliminarVertice(G.GetVertice(nombre));
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 7:
        {
            string origen, destino;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese del nombre del vertice origen: ";
                cin.ignore();
                getline(cin, origen, '\n');
                cout<<"Ingrese el nombre del vertice destino: ";
                getline(cin, destino, '\n');
                if(G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL)
                {
                    cout<<"Vertices no validos"<<endl;
                }
                else
                {
                    G.EliminarArista(G.GetVertice(origen), G.GetVertice(destino));
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 8:
        {
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
               G.Anular();
            }
            cin.get();
            cin.get();
            break;
        }
        case 9:
        {
            string origen, destino;
            system("cls");
            if(G.Vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese el nombre del vertice origen: ";
                cin.ignore();
                getline(cin, origen, '\n');
                cout<<"Ingrese el nombre del vertice destino: ";
                getline(cin, destino, '\n');
                if(G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL)
                {
                    cout<<"Vertices invalidos"<<endl;
                }
                else
                {
                    G.ViajandoPorRumania(G.GetVertice(origen), G.GetVertice(destino));
                }
            }
            cin.get();
            cin.get();
            break;
        }
         case 10:
        {
            string origen, destino;
            system("cls");
            if(W.Vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Ingrese el origen: ";
                cin.ignore();
                getline(cin, origen, '\n');
                cout<<"Ingrese la palabra a buscar: ";
                getline(cin, destino, '\n');
                if(W.GetVertice(origen) == NULL || W.GetVertice(destino) == NULL)
                {
                    cout<<"No se ha encontrado la palabra"<<endl;
                }
                else
                {
                    W.BuscadorPalabras(W.GetVertice(origen), W.GetVertice(destino));
                }
            }
            cin.get();
            cin.get();
            break;
        }
        case 11:
        {
            break;
        }
        default:
        {
            cout<<"Elija una opcion valida"<<endl;
        }
        }
    }
    while(opc != 11);
    return 0;
}
