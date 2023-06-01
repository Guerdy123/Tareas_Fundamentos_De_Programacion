#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

    typedef struct {
        char NoCasa[20];
        char calle[20];
        char sector[25];
        char ciudad[30];
    }Direccion;

    typedef enum {
        persona,
        empresa
    }TipoCliente;

    typedef struct {
     char identificacion[13];
     Direccion Dir;
     char telefono[30];
     char profesion[20];
     char nombre[20];
     TipoCliente tipo;
     int cantidadHijos;
     float altura;
    }Cliente;

    typedef struct {
        int dia;
        int mes;
        int anyo;
    }fecha;

    typedef struct {
        int numero;
        fecha fecha;
        char identificacion[13];
        float inscripcion;
        float pago;
    }Contrato;

    int mostrarMenu(int cantidadCliente,int cantidadContratos); //Prototipo para el menu y la election
    int capturarCliente(int , Cliente*); //Prototipo para capturar nuevo cliente
    int capturarContratos(int ,Contrato*); //Prototipo para capturar Contratos
    long mostrarHijos(int,Cliente*);

int main() {
    int cantidadClientes=0,cantidadContratos=0,eleccion;

    Cliente *listadoClientes = (Cliente*) malloc(sizeof(Cliente)*cantidadClientes); //Reservar dinámicamente espacio para clientes
    Contrato *listadoContratos =(Contrato*) malloc(sizeof(Contrato)*cantidadContratos);//Reservar dinámicamente espacio para contratos


    do {
        eleccion = mostrarMenu(cantidadClientes,cantidadContratos);
        if(eleccion == 1){
            cantidadClientes++;
            listadoClientes = (Cliente*) malloc(sizeof(Cliente)*cantidadClientes);
            capturarCliente(cantidadClientes -1,listadoClientes);

        } else if(eleccion ==2){
            cantidadContratos++;
            listadoContratos = (Contrato *) malloc(sizeof(Contrato)*cantidadContratos);
            capturarContratos(cantidadContratos-1,listadoContratos);
        } else if(eleccion == 3){
           // mostrarClientes(cantidadClientes,listadoClientes);
        } else if(eleccion ==5){
           long hijos = mostrarHijos(cantidadClientes,listadoClientes);
            printf("Hijos: %ld",hijos);
        }
    } while (eleccion !=0);


    return 0;
}

int mostrarMenu(int cantidadCliente,int cantidadContratos){
    char opcion;
    printf("---Registro de contratos y entidades---");
    printf("\n\t Seleccione una opcion del menu:\n");
    printf("\n\t\t 1:Capturar un nuevo cliente");
    printf("\n\t\t 2.Capturar un nuevo contrato:");
    printf("\n\t\t 3.Mostrar todos los clientes(%d)",cantidadCliente);
    printf("\n\t\t 4.Mostrar todos los contratos(%d)",cantidadContratos);
    printf("\n\t\t 5.Mostrar todos los hijos");
    printf("\n\t\t 0.Salir del programa \n\nSeleccione:\t");

    fflush(stdin);
    opcion= getchar();

    switch (opcion) {
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        default:
            return 0;

    }

}

int capturarCliente(int indice,Cliente* listadoClientes){
    char tipo;
    printf("Identificacion:");
    fflush(stdin);
    gets(((listadoClientes+indice))->identificacion);

    printf("No Casa:");
    gets(((listadoClientes+indice))->Dir.NoCasa);

    printf("Calle:");
    gets((listadoClientes+indice)->Dir.calle);

    printf("Sector:");
    gets((listadoClientes+indice)->Dir.sector);

    printf("Ciudad:");
    gets((listadoClientes+indice)->Dir.ciudad);

    printf("Telefono:");
    gets((listadoClientes+indice)->telefono);

    printf("Profession");
    gets( (listadoClientes+indice)->profesion);

    printf("Nombre:");
    gets( (listadoClientes+indice)->nombre);

    printf("Tipo de cliente:");
    tipo= getchar();
    (listadoClientes+indice)->tipo = tolower(tipo) == 'e' ? empresa : persona ;

    printf("Cantidad de hijos:");
    scanf("%d",&(listadoClientes+indice)->cantidadHijos);

    printf("Altura:");
    scanf("%f",&(listadoClientes+indice)->altura);
}

int capturarContratos(int indice ,Contrato* listadoContratos){

    printf("Numero:");
    fflush(stdin);
    scanf("%d",&((listadoContratos+indice)->numero));

    printf("Dia:");
    scanf("%d",&((listadoContratos+indice)->fecha.dia));

    printf("Mes:");
    scanf("%d",&((listadoContratos+indice)->fecha.mes));

    printf("A%co",164);
    scanf("%d",&((listadoContratos+indice)->fecha.anyo));

    printf("ID");
    scanf("%s",((listadoContratos+indice)->identificacion));

    printf("Inscripcion: ");
    scanf("%f",&((listadoContratos+indice)->inscripcion));

    printf("Pago mensual: ");
    scanf("%f",&((listadoContratos+indice)->pago));

}

long mostrarHijos(int indice,Cliente* listadoClientes){

    long hijos =0;
    for (int i = 0; i < indice; i++) {
      hijos += (*(listadoClientes+i)).cantidadHijos;
    }
    return hijos;
}
