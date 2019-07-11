///Danilo Abella ; Rodolfo Zuñiga
///Licenciatura en Ciencias de la Compuitacion
///USACH
///Compilador:Code-Blocks 13.12
///Profesora: Rosa Barrera
///SO: Windows 8.0

#include <iostream>
#include <string.h>
#define MAX 100

using namespace std;

///Declaracion de Funciones
int elementos_repetidos (char a[MAX],int n);
int esta (char x,char aux[MAX],int n);
int contar (char a[MAX],char b [MAX], int n, int m,int s);

int main ()
{   int n,m,z,s,d,t=0;
    char a[MAX], b[MAX];
    cout<<"Ingrese primer arreglo:"<<endl;
    cin>>a;
    n=strlen(a);        ///largo del string "a".
    cout<<"Ingrese segundo arreglo:"<<endl;
    cin>>b;
    m=strlen(b);        ///largo del string "b".
///-----------------------------------------------///
    elementos_repetidos(a,n);       ///Llamada a la funcion #1
    n=strlen(a);
    elementos_repetidos(b,m);       ///Llamada a la funcion #1
    m=strlen(b);
    s=contar(a,b,n,m,t);            ///Llamada a la funcion #3
    cout<<"cantidad de repeticiones: "<<s<<endl;
    return 0;
}

///--------------------------------------------------------------------///
///Funciones

///Funcion 1
/// Crea un nuevo arreglo sin caracteres repetidos.
int elementos_repetidos (char a[MAX],int n)
{int k=0,i;
 char aux[MAX];
 for (i=0;i<n;i++)
    if (!esta(a[i],aux,k-1))    ///Llamada a la funcion #2 (dentro de intruccion)
    {   aux[k]= a[i];
        k++;
    }
aux[k]='\0';
strcpy(a,aux);
}

///Funcion 2
///Verifica si un caracter en particular es igual a otro en el mismo arreglo/string.
int esta(char x,char a[MAX],int n)
{
/// int i=0;
/// for(i=0;i<n;i++)
/// {  if(a[i]==x)
///     {   return 1;
///     }
///  }
///    return 0;
    if (n==-1)
    { return 0;
    }
    if(a[n]==x)
    { return 1;
    }
    return esta(x,a,n-1);   ///Llamada a la funcion #2 (nuevamente).

}

///Funcion 3
///Cuenta la cantidad de caracteres que tienen en común dos arreglos.
int contar(char a[MAX],char b [MAX], int n, int m,int s)
{   /// int i,s=0;
    /// for (i=0;i<n;i++)
    /// {if(esta(a[i],b,m-1))
    ///  {  s++;
    ///  }
    /// }
    /// return s;
    if (n==-1)
    {  return s;
    }
    if (esta(a[n],b,m-1))               ///Llamada a la funcion #2 (dentro de intruccion)
    {   return contar(a,b,n-1,m,s+1);   ///Llamada a la funcion #3 (nuevamente)
    }
    else
    {   if (!esta(a[n],b,m-1))              ///Llamada a la funcion #2 (dentro de intruccion)
        {   return contar(a,b,n-1,m,s);     ///Llamada a la funcion #3 (nuevamente)
        }
    }
}
