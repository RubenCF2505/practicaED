template <class T>
struct nodo
{
    int operador1, operador2;
    list numeros;
    char operador;
    nodo<T> *padre, *hijoIzq, *hermano;
    nodo()
    {
        padre = hijoIzq = hermano = 0;
    }
    nodo(const T &valor)
    {
        etiqueta = valor;
        padre = hijoIzq = hermano = 0;
    }
};
template <class T>
class ArbolCifras
{
    nodo<T> raiz;
    
};