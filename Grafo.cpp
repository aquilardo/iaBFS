#include "Grafo.h"

void Grafo::Inicializa()
{
    h = NULL;
}

bool Grafo::Vacio()
{
    if(h == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Grafo::Tamano()
{
    int cont = 0;
    Vertice *aux;
    aux = h;
    while(aux != NULL)
    {
        cont++;
        aux = aux->sig;
    }
    return cont;
}

Vertice *Grafo::GetVertice(string nombre)
{
    Vertice *aux;
    aux = h;
    while(aux!= NULL)
    {
        if(aux->nombre == nombre)
        {
            return aux;
        }
        aux = aux->sig;
    }
    return NULL;
}

void Grafo::InsertaVertice(string nombre)
{
    Vertice *nuevo = new Vertice;
    nuevo->nombre = nombre;
    nuevo->sig = NULL;
    nuevo->ady = NULL;
    if(Vacio())
    {
        h = nuevo;
    }
    else
    {
        Vertice *aux;
        aux = h;
        while(aux->sig != NULL)
        {
            aux = aux -> sig;
        }
        aux->sig = nuevo;
    }
}

void Grafo::InsertaArista(Vertice *origen, Vertice *destino, int peso)
{
    Arista *nueva = new Arista;
    nueva->peso = peso;
    nueva->sig = NULL;
    nueva->ady = NULL;

    Arista *aux;
    aux = origen->ady;
    if(aux == NULL)
    {
        origen->ady = nueva;
        nueva->ady = destino;
    }
    else
    {
        while(aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nueva;
        nueva->ady = destino;
    }
}


void Grafo::ListaAdyacencia()
{
    Vertice *VertAux;
    Arista *ArisAux;

    VertAux = h;
    while(VertAux != NULL)
    {
        cout<<VertAux->nombre<<"->";
        ArisAux = VertAux->ady;
        while(ArisAux != NULL)
        {
            cout<<ArisAux->ady->nombre<<"->";
            ArisAux = ArisAux->sig;
        }
        VertAux = VertAux->sig;
        cout<<endl;
    }
}

void Grafo::Anular()
{
    Vertice *aux;

    while(h != NULL)
    {
        aux = h;
        h = h->sig;
        delete(aux);
    }
}
void Grafo::EliminarArista(Vertice *origen, Vertice *destino)
{
    int band = 0;
    Arista *actual, *anterior;

    actual = origen -> ady;
    if(actual == NULL)
    {
        cout<<"El vertice origen no tiene aristas"<<endl;
    }
    else if(actual->ady == destino)
    {
        origen->ady = actual->sig;
        delete(actual);
    }
    else
    {
        while(actual != NULL)
        {
            if(actual->ady == destino)
            {
                band = 1;
                anterior->sig = actual->sig;
                delete(actual);
                break;
            }
            anterior = actual;
            actual = actual->sig;
        }
        if(band == 0)
        {
            cout<<"Esos dos vertices no estan conectados"<<endl;
        }
    }

}

void Grafo::EliminarVertice(Vertice *vert)
{
    Vertice *actual, *anterior;
    Arista *aux;
    actual = h;
    while(actual != NULL)
    {
        aux = actual->ady;
        while(aux != NULL)
        {
            if(aux->ady == vert)
            {
                EliminarArista(actual, aux->ady);
                break;
            }
            aux = aux->sig;
        }
        actual = actual->sig;
    }
    actual = h;
    if(h == vert)
    {
        h = h->sig;
        delete(actual);
    }
    else
    {
        while(actual != vert)
        {
            anterior = actual;
            actual = actual->sig;
        }
        anterior->sig = actual->sig;
        delete(actual);
    }
}

bool Comparacion(pair <Vertice*, int> a, pair<Vertice*, int> b)
{
    return a.second < b.second;
}
void Grafo::ViajandoPorRumania(Vertice *origen, Vertice *destino)
{
    int CostoActual = 0, band, band2 = 0;
    Vertice *VerticeActual, *DestinoActual;
    Arista *aux;
    typedef pair<Vertice*, int> VerticeCosto;
    typedef pair<Vertice*, Vertice*> VerticeVertice;
    list<VerticeCosto> ListaCostos;
    list<VerticeCosto> ListaOrdenada;
    stack<VerticeVertice> pila;
    list<VerticeCosto>::iterator i, j;

    ListaCostos.push_back(VerticeCosto(origen,0));
    ListaOrdenada.push_back(VerticeCosto(origen,0));

    while(!ListaOrdenada.empty())
    {
        VerticeActual = ListaOrdenada.front().first;
        CostoActual = ListaOrdenada.front().second;
        ListaOrdenada.pop_front();

        if(VerticeActual == destino)
        {
            cout<<"Costo: "<<CostoActual<<endl;
            band2 = 1;
            DestinoActual = destino;

            while(!pila.empty())
            {
                cout<<DestinoActual->nombre<<"<-";
                while(!pila.empty() && pila.top().second != DestinoActual)
                {
                    pila.pop();
                }

                if(!pila.empty())
                {
                    DestinoActual = pila.top().first;
                }
            }
            break;
        }

        aux = VerticeActual->ady;
        while(aux != NULL)
        {
            band = 0;
            CostoActual = CostoActual + aux->peso;

            for(i=ListaCostos.begin(); i!=ListaCostos.end(); i++)
            {
                if(aux->ady == i->first)
                {
                    band = 1;
                    if(CostoActual < i->second)
                    {
                        (*i).second = CostoActual;

                        for(j=ListaOrdenada.begin(); j!=ListaOrdenada.end(); j++)
                        {
                            if(j->first == aux->ady)
                            {
                                (*j).second = CostoActual;
                            }
                            ListaOrdenada.sort(Comparacion);
                            pila.push(VerticeVertice(VerticeActual, aux->ady));
                            CostoActual = CostoActual - aux->peso;

                        }
                    }
                }
            }
            if(band == 0)
            {
                ListaCostos.push_back(VerticeCosto(aux->ady, CostoActual));
                ListaOrdenada.push_back(VerticeCosto(aux->ady, CostoActual));
                ListaOrdenada.sort(Comparacion);
                pila.push(VerticeVertice(VerticeActual, aux->ady));
                CostoActual = CostoActual - aux->peso;
            }

            aux = aux->sig;

        }
    }

    if(band2 == 0)
    {
        cout<<"No hay una ruta entre esos dos vertices"<<endl;
    }
}
void Grafo::BuscadorPalabras(Vertice *origen, Vertice *destino)
{
    int CostoActual = 0, band, band2 = 0;
    Vertice *VerticeActual, *DestinoActual;
    Arista *aux;
    typedef pair<Vertice*, int> VerticeCosto;
    typedef pair<Vertice*, Vertice*> VerticeVertice;
    list<VerticeCosto> ListaCostos;
    list<VerticeCosto> ListaOrdenada;
    stack<VerticeVertice> pila;
    list<VerticeCosto>::iterator i, j;

    ListaCostos.push_back(VerticeCosto(origen,0));
    ListaOrdenada.push_back(VerticeCosto(origen,0));

    while(!ListaOrdenada.empty())
    {
        VerticeActual = ListaOrdenada.front().first;
        CostoActual = ListaOrdenada.front().second;
        ListaOrdenada.pop_front();

        if(VerticeActual == destino)
        {
            cout<<"Costo: "<<CostoActual<<endl;
            band2 = 1;
            DestinoActual = destino;

            while(!pila.empty())
            {
                while(!pila.empty() && pila.top().second != DestinoActual)
                {
                    pila.pop();
                }

                if(!pila.empty())
                {
                    DestinoActual = pila.top().first;
                }
            }
            cout<<"Se ha encontrado la palabra"<<endl;
            break;
        }

        aux = VerticeActual->ady;
        while(aux != NULL)
        {
            band = 0;
            CostoActual = CostoActual + aux->peso;

            for(i=ListaCostos.begin(); i!=ListaCostos.end(); i++)
            {
                if(aux->ady == i->first)
                {
                    band = 1;
                    if(CostoActual < i->second)
                    {
                        (*i).second = CostoActual;

                        for(j=ListaOrdenada.begin(); j!=ListaOrdenada.end(); j++)
                        {
                            if(j->first == aux->ady)
                            {
                                (*j).second = CostoActual;
                            }
                            ListaOrdenada.sort(Comparacion);
                            pila.push(VerticeVertice(VerticeActual, aux->ady));
                            CostoActual = CostoActual - aux->peso;

                        }
                    }
                }
            }
            if(band == 0)
            {
                ListaCostos.push_back(VerticeCosto(aux->ady, CostoActual));
                ListaOrdenada.push_back(VerticeCosto(aux->ady, CostoActual));
                ListaOrdenada.sort(Comparacion);
                pila.push(VerticeVertice(VerticeActual, aux->ady));
                CostoActual = CostoActual - aux->peso;
            }

            aux = aux->sig;

        }
    }

    if(band2 == 0)
    {
        cout<<"No se ha encontrado"<<endl;
    }
}

