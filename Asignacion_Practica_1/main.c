#include <stdio.h>
#include <string.h>
#include <stdlib.h>



//- Permitir registrar una serie de carros públicos
// que trabajan en la ruta. Cada carro tiene: una marca, un año,
//una ficha que lo identifica y el nombre de su propietario.
typedef struct {
    int dia;
    int mes;
    char anyo[5];
    int hora;
    int hora2;
    int minuto;
    int minuto2;
    int segundos;
    int segundos2;
    char duracion;
}Fecha;
typedef struct {
    char marca[20];
    char fichaId[10];
    char proprietario[30];
    Fecha fecha;
}Carro;
typedef struct {
    char nombre[40];
    char ID[10];
    char lugarTrabajo[50];
    char telefono[20];
    char compMovil[10];
}Pasajeros;
typedef struct {
    char idCarro[10];
    char idPasajero[10];
    Fecha fecha;
    int monto;
    float devuelta;
}Transaccion;

int mostrarMenu();
int registrarCarros(int,Carro *, FILE * );
int registrarPasajeros(int ,Pasajeros *,FILE *);
int registrarTransaccion(int ,Transaccion *,FILE *);
int cantidadDuracionMinutos(int,int,int,int,int,int);
//void mostrarPasajeroConcho(Pasajeros *, int,int,Transaccion *,int);
void mostrarConcho(FILE *);

int main() {
    int eleccion;
    int cantidadCarros = 0;
    int cantidadPasajeros= 0;
    int cantidadTransaccion =0;
    int identificacion;
    FILE * archivoCarros = fopen("pasajeros.dat","a+b");
    FILE * archivoPasajeros= fopen("pasajeros.dat","a+b");
    FILE * archivoTransaccion= fopen("transaccion.dat","a+b");
    Carro * listaCarros = (Carro *)malloc(sizeof(Carro)*cantidadCarros);
    Pasajeros * listaPasajeros=(Pasajeros*) malloc(sizeof(Pasajeros)*cantidadPasajeros);
    Transaccion * listaTransaccion=(Transaccion *) malloc(sizeof(Transaccion)*cantidadTransaccion);


    do {
        switch ( eleccion =  mostrarMenu()) {
            case 1:
                cantidadCarros++;
                listaCarros = (Carro*) realloc(listaCarros,sizeof(Carro)*cantidadCarros);
                registrarCarros(cantidadCarros-1,listaCarros,archivoCarros);
                break;
            case 2:
                cantidadPasajeros++;
                listaPasajeros =(Pasajeros*) realloc(listaPasajeros,sizeof(Pasajeros)*cantidadPasajeros);
                registrarPasajeros(cantidadPasajeros-1,listaPasajeros,archivoPasajeros);
                break;
            case 3:
                cantidadTransaccion++;
                listaTransaccion = (Transaccion*) realloc(listaTransaccion,sizeof (Transaccion)*cantidadTransaccion);
                registrarTransaccion(cantidadTransaccion-1,listaTransaccion,archivoTransaccion);
                break;
            case 4:

                mostrarConcho(archivoCarros); //Para poder mostrar el usuario los conchos y que pueda elegir que concho quiere
                printf("\n\t--Ingrese la identificacion del concho para ver cuales fueron sus pasajeros:--");
                scanf("%d" ,&identificacion);
                printf("El concho elegido es el No %d",identificacion);
                //mostrarPasajeroConcho( listaPasajeros ,cantidadTransaccion,identificacion,listaTransaccion,cantidadPasajeros);
                break;
            case 5:

                break;
            case 6:

                break;
            default:
                printf("Eleccion no reconocido");





        }
    } while (eleccion != 0);


    return 0;
}

int mostrarMenu(){
    char opcion;
    printf("\n\n---Programa de manejo de la ruta RPA---\n\n");
    printf("Seleccione una opcion:\n");
    printf("\t(1) Registrar carro que trabajan en la ruta RPA\n");
    printf("\t(2) Registrar pasajeros asiduos de la ruta RPA\n");
    printf("\t(3) Registrar un servicio de transporte prestado por un carro por su ficha\n");
    printf("\t(4) Mostrar los pasajeros montados por un concho especifico\n");
    printf("\t(5) Mostrar los datos s de los carros publicos en los que se haya montado un pasajero especifico\n");
    printf("\t(6) Mostrar los servicios de transporte registrado en el sistema\n");
    printf("\t(7) Salir del programa\n");
    printf("\t Seleccione:  ");

    fflush(stdin);
    opcion = getchar();

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
        case '6':
            return 6;
        default:
            return 0;
    }
}
int registrarCarros(int indice, Carro * listadoCarros,FILE * archivoCarros){
    printf("---Registracion de carros---\n");
    fflush(stdin);

    printf("Ingrese la marca del carro:");
    gets((listadoCarros+indice)->marca);

    printf("Ingrese el anyo:");
    gets((listadoCarros+indice)->fecha.anyo);

    printf("Ingrese su ficha de identificacion:");
    gets((listadoCarros+indice)->fichaId);

    printf("Nombre del proprietario:");
    gets((listadoCarros+indice)->proprietario);

    fwrite(listadoCarros,sizeof (Carro),1,archivoCarros);

}
int registrarPasajeros(int indice, Pasajeros * listaPasajeros,FILE * archivoPasajeros){
    printf("\n---Registracion de pasajeros---\n");

    printf("Ingrese su nombre:");
    fflush(stdin);
    gets((listaPasajeros+indice)->nombre);

    printf("Ingrese su ID:");
    gets((listaPasajeros+indice)->ID);

    printf("Lugar de trabajo:");
    gets((listaPasajeros+indice)->lugarTrabajo);

    printf("Numero de celular:");
    gets((listaPasajeros+indice)->telefono);

    printf("Compania de movil:");
    gets((listaPasajeros+indice)->compMovil);

    fwrite(listaPasajeros,sizeof (Pasajeros),1,archivoPasajeros);

}
int cantidadDuracionMinutos(int hora1,int minutos1,int segundo1,int hora2,int minutos2,int segundo2){
    int segundos1 = hora1 * 3600 + minutos1 * 60 + segundo1;
    int segundos2 = hora2 * 3600 + minutos2 * 60 + segundo2;
    int diferencias= (segundos2 - segundos1)/60;

    return diferencias;
}
int registrarTransaccion(int indice,Transaccion * listaTransaccion,FILE * archivoTransaccion) {
    printf("---Registro de la transaccion---\n");
    fflush(stdin);
    printf("Ingrese el Id del carro:");
    gets((listaTransaccion + indice)->idCarro);

    printf("Ingrese el Id del pasajero:");
    gets((listaTransaccion + indice)->idPasajero);

    printf("Ingrese el monto pagado:");
    scanf("%d", &(listaTransaccion + indice)->monto);

    printf("Ingrese la devuelta:");
    scanf("%f", &(listaTransaccion + indice)->devuelta);

    printf("\n---Ingrese los datos relativos a la fecha---\n");

    printf("Ingrese el dia:");
    scanf("%d",&(listaTransaccion+indice)->fecha.dia);

    printf("Ingrese el mes:");
    scanf("%d",&(listaTransaccion+indice)->fecha.mes);

    printf("Ingrese el a%co:",164);
    scanf("%s",(listaTransaccion+indice)->fecha.anyo);

    printf("----NB: Ingrese la hora en formato (H24)--\n");
    printf("Ingrese el tiempo de subida(HH:MM:SS):");
    scanf("%d:%d:%d",&(listaTransaccion+indice)->fecha.hora,&(listaTransaccion+indice)->fecha.minuto,&(listaTransaccion+indice)->fecha.segundos);

    printf("Ingrese el tiempo de bajada(HH:MM:SS):");
    scanf("%d:%d:%d",&(listaTransaccion+indice)->fecha.hora2,&(listaTransaccion+indice)->fecha.minuto2,&(listaTransaccion+indice)->fecha.segundos2);

    int h1 = (listaTransaccion+indice)->fecha.hora; //Hora 1
    int m1 = (listaTransaccion+indice)->fecha.minuto; //min 1
    int s1 = (listaTransaccion+indice)->fecha.segundos;//Seg 1
    int h2 = (listaTransaccion+indice)->fecha.hora2; //Hora 2
    int m2 = (listaTransaccion+indice)->fecha.minuto2; //Min 2
    int s2 = (listaTransaccion+indice)->fecha.segundos2; //Seg 2

    char dur =(char)cantidadDuracionMinutos(h1,m1,s1,h2,m2,s2);
    (listaTransaccion+indice)->fecha.duracion = dur;
    //printf("El tiempo es %d",(*(listaTransaccion+indice)).fecha.duracion);
    //strcpy((listaTransaccion+indice)->fecha.duracion,dur);

    fwrite(listaTransaccion,sizeof(Transaccion),1,archivoTransaccion);

}
void mostrarConcho(FILE * archivoConcho){
    Carro  carroActual;

    fseek(archivoConcho,0,SEEK_END);
    int tamano = ftell(archivoConcho);
    fseek(archivoConcho,0,SEEK_SET);

    printf("\tIdentificacion\t \tProprietario\n");
    while (ftell(archivoConcho) < tamano){
        fread(&carroActual,sizeof (Carro),1,archivoConcho);

        printf("      %s\t",carroActual.fichaId);
        printf("    \t\t%s\n\n\n\n\n",carroActual.proprietario);
    }




}

//void imprimirTodosLosPasajeros(FILE * archivoPasajeros) {
//    printf("Automóviles de la marca %s y año %d:\n", marca, anio);
//    for (int i = 0; i < numAutomoviles; i++) {
//        if (strcmp(automoviles[i].marca, marca) == 0 && automoviles[i].anio == anio) {
//            printf("Modelo: %s\n", automoviles[i].modelo);
//            printf("Precio por día: %.2f\n", automoviles[i].precioPorDia);
//            printf("\n");
//        }
//    }
//}
//void mostrarPasajeroConcho(Pasajeros * listaPasajeros,int cantidadTransaccion,int choice,Transaccion * listaTransaccion,int cantidadPasajeros){
  //  for (int i = 0; i < cantidadTransaccion; i++) {
    //    if(choice == (*(listaTransaccion+i)).idCarro)
  //  }




//    for (int i = 0; i < cantidadPasajeros; ++i) {
//        if(choice == (listaPasajeros+i).);
//        printf("%s",(listaPasajeros+i)->ID);
//        printf("%s",(listaPasajeros+i)->lugarTrabajo);
//        printf("%s",(listaPasajeros+i)->telefono);
//
//    }
//
//}
