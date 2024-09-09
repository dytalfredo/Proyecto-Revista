#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

void limpiarPantalla(){
	system("cls");
}

void mostrarMensaje(string mensaje) {
    cout << mensaje << endl;
}

double obtenerDato(string mensaje) {
    double dato;
    cout << mensaje;
    cin >> dato;
    return dato;
}

bool negativa(double base , double argumento){
	
	if(base<=0 || argumento<=0  ){
		return true;
	}else{
		return false;
	}
}

bool igualdadDeParametros(double base, double argumento){
	
	if(base==argumento){
		return true;
		
	}else{
		return false;
	}
	
}

bool baseUno(double base, double argumento){
	
	if(base==1 && argumento!=1){
		return true;
	}else{
		return false;
	}
	
}

bool argumentoUno(double argumento){
	
	if(argumento==1){
		return true; 
	}else{
		return false;
	}
	
}

bool sinSolucion(double base, double argumento){
	
	if (negativa(base, argumento)){
		mostrarMensaje("El Calculo de un logaritmo de base o argumento menores o iguales a 0 no esta definido");
		return true;
		
	}else if (baseUno(base, argumento)){
		mostrarMensaje("El Calculo de un logaritmo de base 1 y argumento !=1 no esta definido");
		return true;
	}else if (argumentoUno(argumento)){
		mostrarMensaje("Todo logaritmo de Argumento 1 y base calculable es igual a 0");
		return true;
	}else if(igualdadDeParametros(base,argumento)){
		mostrarMensaje("Por Teorema, si base==argumento -> Log=1");
		return true;
	}
	else {
		mostrarMensaje("Calculo Posible");
		return false;
	}
	
}



double calculoDeLogaritmo(double base, double argumento) {
	stringstream ss;
    string mensaje   ;
    ss<<"Log_" << base << "(" << argumento <<")=";
    mensaje= ss.str();
    mostrarMensaje(mensaje);
    return log(argumento) / log(base);

}
double calculoDeLogaritmoDeBaseEntera(double base, double argumento) {
	stringstream ss;
    string mensaje   ;
    ss<<"Log_" << base << "(" << argumento <<")=";
    mensaje= ss.str();
    mostrarMensaje(mensaje);
    mostrarMensaje("Por teorema del cambio de base, trabajamos con una base mas trabajable ejemplo de base 10");
    ss<<"Log" <<"("<< argumento<<")" << "/" <<"Log" <<"(" << base<<")";
    mensaje= ss.str();
    mostrarMensaje(mensaje);
	
	
    return log(argumento) / log(base);
}
double calculoDeLogaritmoDeBaseEnteraRacional(double base, double argumento1 , double argumento2) {
	stringstream ss;
    string mensaje   ;
    ss<<"Log_" << base << "(" << argumento1 << "/" <<argumento2 <<")=";
    mensaje= ss.str();
    mostrarMensaje(mensaje);
    mostrarMensaje("El logaritmo de una Division es la resta de los Logaritmos del numerador y el logaritmo del denominador");
    ss << "Log_" << base << "(" << argumento1<<")"<< "-"<< "Log_" << base << "(" << argumento2 << ")"<< "=";
    mostrarMensaje("Por teorema del cambio de base, trabajamos con una base mas trabajable ejemplo de base 10 Log");
    ss<<"["<< "Log" <<"("<< argumento1<<")" << "/" <<"Log" <<"(" << base<<")"<<"]"<<"-"<<"["<< "Log" <<"("<< argumento2<<")" << "/" <<"Log" <<"(" << base<<")"<<"]";
    mensaje= ss.str();
    mostrarMensaje(mensaje);
	
	
    return log(argumento1) / log(base) - log(argumento2) / log(base);
}

double calculoDeLogaritmoDeBaseRaizEntero(double base,double raiz, double argumento) {
	double raizN = 1/1/raiz;
   	stringstream ss;
    string mensaje   ;
    ss<<"Log_" << base <<  "^"<< raizN << "(" << argumento<<")=";
    mensaje= ss.str();
    mostrarMensaje(mensaje);
    mostrarMensaje("El logaritmo con una Base raiz enesima es la multiplicacion de la potencia de la raiz por el logaritmo de base sin la raiz");
    ss << raiz << "*"<< "Log_" << base << "(" << argumento<<")=";
    mostrarMensaje("Por teorema del cambio de base, trabajamos con una base mas trabajable ejemplo de base 10 Log");
    ss<< raiz << "*"<<"["<< "Log" <<"("<< argumento<<")" << "/" <<"Log" <<"(" << base<<")"<<"]";
    mensaje= ss.str();
    mostrarMensaje(mensaje);
	
	
    return raiz * log(argumento) / log(base);

}

double calculoDeLogaritmoDeBaseRaizRacional(double base,double raiz, double argumento1, double argumento2) {
	double raizN = 1/1/raiz;
   	stringstream ss;
    string mensaje   ;
    ss<<"Log_" << base <<  "^"<< raizN << "(" << argumento1 << "/" <<argumento2 <<")=";
    mensaje= ss.str();
    mostrarMensaje(mensaje);
    mostrarMensaje("El logaritmo con una Base raiz enesima es la multiplicacion de la potencia de la raiz por el logaritmo de base sin la raiz");
    ss << raiz << "*"<< "Log_" << base << "(" << argumento1 << "/" <<argumento2 <<")=";
    mensaje= ss.str();
    mostrarMensaje(mensaje);
	mostrarMensaje("El logaritmo de una Division es la resta de los Logaritmos del numerador y el logaritmo del denominador");
    ss << raiz << "*" <<"["<< "Log_" << base << "(" << argumento1<<")"<< "-"<< "Log_" << base << "(" << argumento2 << ")"<< "]"<< "=";
    mensaje= ss.str();
    mostrarMensaje(mensaje);
	mostrarMensaje("Por teorema del cambio de base, trabajamos con una base mas trabajable ejemplo de base 10 Log");
    ss<< raiz << "*"<<"["<< "Log" <<"("<< argumento1<<")" << "/" <<"Log" <<"(" << base<<")"<<"]"<<"-"<<"["<< "Log" <<"("<< argumento2<<")" << "/" <<"Log" <<"(" << base<<")"<<"]";
    mensaje= ss.str();
    mostrarMensaje(mensaje);
	
	
    return raiz *( log(argumento1) / log(base)) -( log(argumento2) / log(base));

}

double calculoDeLogaritmoDeBaseRacional(double base1,double base2, double argumento) {
   	stringstream ss;
    string mensaje   ;
    ss<<"Log_" << "("<< base1 <<"/"<<base2 <<")" << "(" << argumento <<")=";
    mostrarMensaje(mensaje);
    mostrarMensaje("Por teorema del cambio de base, trabajamos con una base mas trabajable ejemplo de base 10");
    ss<<"Log" <<"("<< argumento<<")" << "/" <<"Log" <<"(" <<base1 <<"/" << base2<<")" << "=";
    mensaje= ss.str();
    mostrarMensaje(mensaje);
    mostrarMensaje("En la base vemos el logaritmo de una  Division lo cual es la resta de los Logaritmos del numerador y el logaritmo del denominador");
    ss<<"Log" <<"("<< argumento<<")" << "/"<<"[" <<"Log" <<"(" <<base1 <<")" << "-" <<"Log" <<"(" <<base2 <<")" <<"]" << "=";
    mensaje= ss.str();
    mostrarMensaje(mensaje);
    
    return  log(argumento) /( log(base1) -  log(base2));;
}

int preguntarTipoDeLogaritmo() {
    int opcion;
    mostrarMensaje("Seleccione el tipo de logaritmo a calcular:");
    mostrarMensaje("1. Logaritmo con base entera y argumento entero");
    mostrarMensaje("2. Logaritmo de base entera con argumento racional");
    mostrarMensaje("3. Logaritmo de base raiz enesima con argumento entero");
    mostrarMensaje("4. Logaritmo de base raiz enesima con argumento racional");
    mostrarMensaje("5. Logaritmo de base racional con cualquier argumento");
    mostrarMensaje("6. Logaritmo con cualquier base y cualquier argumento SOLO RESULTADO");
    cin >> opcion;
    return opcion;
}

void respuestaLogaritmos(double base, double argumento,double resultado){
	stringstream ss;
        
      ss<< "El resultado es aproximadamente = " << resultado;
        
     string mensajeResultado = ss.str();
        
    mostrarMensaje(mensajeResultado);
}


int main() {
    char continuar;
    double argumento;
    double argumento1;
    double argumento2;
    double base;
    double base1;
    double base2;
    double raiz;
    double baseRaiz;
    do {
        mostrarMensaje("Bienvenido al calculador de logaritmos.\n");
        int opcion = preguntarTipoDeLogaritmo();

        
        double resultado;
        
        
        switch (opcion) {
            case 1:
            	mostrarMensaje("CALCULO DE LOGARITMO DE BASE ENTERA Y ARGUMENTO ENTERO");
            	base = obtenerDato("Ingrese la base 'Entera' del logaritmo: ");
        		argumento = obtenerDato("Ingrese el argumento 'Entero' del logaritmo: ");
        		
        		if(sinSolucion(base,argumento)){
        			
        			
        			  
        			break;
				}else{
					
  resultado = calculoDeLogaritmoDeBaseEntera(base,argumento);
					respuestaLogaritmos(base, argumento, resultado);
				}
        	
              
                break;
            case 2:
            	mostrarMensaje("CALCULO DE LOGARITMO DE BASE ENTERA Y ARGUMENTO RACIONAL DEL TIPO a/b");
            	base = obtenerDato("Ingrese la base 'Entera' del logaritmo: ");
        		argumento1 = obtenerDato("Ingrese el Numerador del argumento del logaritmo: ");
        		argumento2 = obtenerDato("Ingrese el Denominador del argumento del logaritmo: ");
        		argumento = argumento1/argumento2;
        		
				if(sinSolucion(base,argumento)){
        			
        			
        			  
        			break;
				}else{
					
  					resultado = calculoDeLogaritmoDeBaseEnteraRacional(base,argumento1, argumento2);
					respuestaLogaritmos(base, argumento, resultado);
				}
        	

            
                break;
            case 3:
            	mostrarMensaje("CALCULO DE LOGARITMO DE BASE RAIZ ENESIMA Y ARGUMENTO ENTERO");
            	base = obtenerDato("Ingrese la base 'Entera' del logaritmo: ");
            	raiz = obtenerDato("Ingrese la raiz 'Entera' de la base del logaritmo: ");
        		argumento = obtenerDato("Ingrese el Numerador del argumento del logaritmo: ");

				baseRaiz = pow(base, 1/raiz);

        		if(sinSolucion(baseRaiz,argumento)){
        			
        			
        			  
        			break;
				}else{
					
  					resultado = calculoDeLogaritmoDeBaseRaizEntero(base,raiz, argumento);
  					respuestaLogaritmos(base, argumento, resultado);
					
				}              
             
                break;
                
            case 4:
            	mostrarMensaje("CALCULO DE LOGARITMO DE BASE RAIZ ENESIMA Y ARGUMENTO RACIONAL DEL TIPO a/b");
            	base = obtenerDato("Ingrese la base 'Entera' del logaritmo: ");
            	raiz = obtenerDato("Ingrese la raiz 'Entera' de la base del logaritmo: ");
        		argumento1 = obtenerDato("Ingrese el Numerador del argumento del logaritmo: ");
        		argumento2 = obtenerDato("Ingrese el Denominador del argumento del logaritmo: ");
        		argumento = argumento1/argumento2;

				baseRaiz = pow(base, 1/raiz);

        		if(sinSolucion(baseRaiz,argumento)){
        			 
        			break;
				}else{
					
  					resultado = calculoDeLogaritmoDeBaseRaizRacional(base,raiz, argumento1, argumento2);
					respuestaLogaritmos(base, argumento, resultado);
				}              
             
                break;
            
            case 5:
            	mostrarMensaje("CALCULO DE LOGARITMO DE BASE RACIONAL Y CUALQUIER ARGUMENTO");
            	base1 = obtenerDato("Ingrese el Numerador de  la base del logaritmo: ");
            	base2 = obtenerDato("Ingrese el Denominador de  la base del logaritmo: ");
            	
        		argumento = obtenerDato("Ingrese el argumento del logaritmo: ");

				baseRaiz = base1/base2;

        		if(sinSolucion(baseRaiz,argumento)){
        			 
        			break;
				}else{
					
  					resultado = calculoDeLogaritmoDeBaseRacional(base1,base2, argumento);
					respuestaLogaritmos(baseRaiz, argumento, resultado);
				}              
             
                break;
                
            case 6:
            	mostrarMensaje("CALCULO DE LOGARITMO SIN PASOS");
            	base = obtenerDato("Ingrese la base del logaritmo: ");
            	argumento = obtenerDato("Ingrese el argumento del logaritmo: ");
            	
        		

        		if(sinSolucion(base,argumento)){
        			 
        			break;
				}else{
					
  					resultado = calculoDeLogaritmo(base,argumento);
					respuestaLogaritmos(baseRaiz, argumento, resultado);
				}              
             
                break;
        }
        
       

        cout << "¿Desea calcular otro logaritmo? (s/n): ";
        cin >> continuar;
        limpiarPantalla();
        
    } while (continuar == 's' || continuar == 'S');

    return 0;
}
