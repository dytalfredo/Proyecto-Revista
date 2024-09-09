#include <iostream>
#include <cstring>
#include <string>


using namespace std;

struct Articulo {
	string indice;
    string titulo;
    string autor;
    string tipo;
};

void imprimirMensaje(const char* e){
    std::cout << e <<std::endl;
}

void separacion(){
    std::cout << "/---------------------------------------------------/"<<std::endl;
}

void saltoLinea(){
    std::cout << std::endl;
}

// Función para crear un artículo y agregarlo al arreglo
void crearArticulo(Articulo articulos[], int &numArticulos, const char* titulo, const char* indice, const char* autor, const char* tipo) {
    if (numArticulos < 100) { // Ajusta el límite según tus necesidades
        articulos[numArticulos].titulo = titulo;
        articulos[numArticulos].autor= autor;
        articulos[numArticulos].indice= indice;
        articulos[numArticulos].tipo= tipo;

        numArticulos++;
        std::cout << "Artículo creado exitosamente." << std::endl; // Si deseas mostrar un mensaje
    } else {
        std::cout << "Se ha alcanzado el límite máximo de artículos." << std::endl;
    }
} 

void limpiarPantalla(){
	system("cls");
}

// Función para mostrar todos los artículos     //3
void mostrarArticulos(Articulo articulos[], int numArticulos, bool e) {
	if(e){
		for (int i = 0; i < numArticulos; ++i) {
    
        std::cout << "Option: " << i+1;
        std::cout << "  Title: " << articulos[i].titulo ;
        std::cout << "  Autor: " << articulos[i].autor;
        std::cout << "  Type: " << articulos[i].tipo;
        saltoLinea();

	}
	separacion();
	cout<< "Option:13--->Logarithm Calculator"<<endl;
    cout<< "Opcion:14--->Opinion Video"<<endl;
    cout<< "Opcion:15--->General Help"<<endl;
	} else {
	
    for (int i = 0; i < numArticulos; ++i) {
    
        std::cout << "Opcion:" << i+1;
        std::cout << "-> Titulo:" << articulos[i].titulo ;
        std::cout << " - Autor:" << articulos[i].autor;
        std::cout << " - Tipo:" << articulos[i].tipo;
        saltoLinea();

    }
    
    separacion();
    cout<< "Opcion:13--->Calculadora Logaritmos"<<endl;
    cout<< "Opcion:14--->Video De Opinion"<<endl;
    cout<< "Opcion:15--->Ayuda General"<<endl;
}
}

void abrirArticulo(Articulo articulos[], int numeroArticulo, int numArticulos){



numeroArticulo= numeroArticulo-1;
if (numeroArticulo==12){
	//abre calculador
	string comando ="start calculadoraLogaritmo/CalculadoraLogaritmo.exe";
	system(comando.c_str());
}else if(numeroArticulo==13){
	//Muestro Video
	string comando ="start contenido/video.mp4";
	system(comando.c_str());
	
	
}else if(numeroArticulo<numArticulos && numeroArticulo>=0){
imprimirMensaje("Artículo abierto en pantalla");
string comando = "start contenido/" + articulos[numeroArticulo].indice +".pdf";
//start contenido/1.pdf
system(comando.c_str());
saltoLinea();
}
else{
imprimirMensaje("Artículo no encontrado");
}

}

void eliminarElemento(Articulo articulos[], int &numeroArticulos, int pos) {
    // n representa el tamaño actual del arreglo
    // pos es el índice del elemento a eliminar (comenzando desde 0)
pos--;
    // Validar que la posición sea válida
    if (pos >= 0 && pos < numeroArticulos) {
        // Desplazar todos los elementos a partir de la posición hacia la izquierda
        for (int i = pos; i < numeroArticulos - 1; i++) {
        
            articulos[i] = articulos[i+1];
            
        }
        
        std::cout <<"Articulo "<< articulos[pos++].indice <<" borrado" <<std::endl;
        // Reducir el tamaño del arreglo (lógicamente)
        numeroArticulos--;
    } else {
        cout << "Posición inválida." << endl;
    }
}


int main() {
    Articulo articulosSpa[100];
	Articulo articulosEng[100]; // Ajusta el tamaño máximo del arreglo
    int numArticulos = 0;
    int numArticulosEng = 0;
    int lenguajeOption;

	char respuesta;
    int numArticulo;
    bool e= false;
    //Generacion Automatica de Articulos En español e ingles
    crearArticulo(articulosSpa, numArticulos, "Portada","1", "Equipo", "Grafico");
    crearArticulo(articulosSpa, numArticulos, "Contenido","2", "Equipo", "Grafico");
    crearArticulo(articulosSpa, numArticulos, "Editorial","3", "Alfredo Mendoza", "Editorial");
    crearArticulo(articulosSpa, numArticulos, "La Voceria","4", "Alfredo Mendoza", "Art. Cientifico");
    crearArticulo(articulosSpa, numArticulos, "Humano-Maquina","5", "Zuzej Crespo", "Art. Investigación");
    crearArticulo(articulosSpa, numArticulos, "Los Logaritmos","6", "Dario Montero", "Art. Matematico");
    crearArticulo(articulosSpa, numArticulos, "Como Nace Un Vocero","7", "Alfredo Mendoza", "Cronica");
    crearArticulo(articulosSpa, numArticulos, "Bots de Internet","8", "Jesus Castillo", "Art. Investigación + Manual");
    crearArticulo(articulosSpa, numArticulos, "Adios, caos. Hola, organización","9", "Melary Morales", "Art. Opinion");
    crearArticulo(articulosSpa, numArticulos, "Ruido Blanco","10", "Dario Montero", "Art. Opinion");
    crearArticulo(articulosSpa, numArticulos, "Contra Portada","11", "Equipo", "Grafico");
    crearArticulo(articulosSpa, numArticulos, "Revista Completa","12", "Equipo", "Maravilloso");
    
    
    
    
    crearArticulo(articulosEng, numArticulosEng, "Cover","1", "Team", "Desing");
    crearArticulo(articulosEng, numArticulosEng, "Content","2", "Team", "Desing");
    crearArticulo(articulosEng, numArticulosEng, "The Spokesperson","3", "Alfredo Mendoza", "Art. Scientific");
    crearArticulo(articulosEng, numArticulosEng, "Human-Machine","4", "Zuzej Crespo", "Art. Research");
    crearArticulo(articulosEng, numArticulosEng, "The logarithms","5", "Dario Montero", "Art. Mathematical");
    crearArticulo(articulosEng, numArticulosEng, "How a Spokesperson Is Born","6", "Alfredo Mendoza", "Chronicle");
   
    
    

    
  
	
	
    imprimirMensaje("/--------------------INICIO-------------------------/");
    separacion();


    
	
	do{
        imprimirMensaje("Antes de comenzar selecciona un idioma. Escribe solo el numero segun el idioma que deseas?");
		imprimirMensaje("1. Espanol");
		imprimirMensaje("2. Ingles");
		imprimirMensaje("3. Salir");
		std::cin >> lenguajeOption;
		 limpiarPantalla();
	
		
		switch (lenguajeOption){
			case 1:           //Porgrama en español
			e=false;
				
				
				

	           

                do{
                imprimirMensaje("Bienvenido a la Revista");
                imprimirMensaje("Criollo Digital");
                imprimirMensaje("Edicion: Ni Una Palabra Perdida");
                saltoLinea();
                imprimirMensaje("Instrucciones:");
                imprimirMensaje("Cada artículo posee un digito referencial, ingresa el numero del artículo que deseas ver.");
                separacion();
                imprimirMensaje( "/--------------------INDICE-------------------------/");
                separacion();
                imprimirMensaje("Ingresa el número del artículo que deseas leer");
                saltoLinea();
                mostrarArticulos(articulosSpa,numArticulos,e);
                imprimirMensaje("Si desea eliminar un articulo escriba 99");
                
               
                std::cin >> numArticulo;
                if(numArticulo==99){
                	imprimirMensaje("Eliga el numero del articulo que desea eliminar");
                	cin >> numArticulo;
                	
                
                	eliminarElemento(articulosSpa,numArticulos, numArticulo );
				} else {
					cout << "Numero obtenido" << numArticulo;
				
					abrirArticulo(articulosSpa, numArticulo, numArticulos);
              
				}
                	 limpiarPantalla();
                
                
                imprimirMensaje("¿Desea abrir otro articulo? (s/n)");
                std::cin >> respuesta;
              //  limpiarPantalla();
                
                }while(respuesta == 's' || respuesta == 'S');
                
	   
	            
				break;
				
			case 2:        //Programa en Ingles
                imprimirMensaje("Welcome to the Journal");
                imprimirMensaje("Criollo Digital");
                imprimirMensaje("Editing: Not a Lost Word");
                saltoLinea();
                imprimirMensaje("Instructions:");
                imprimirMensaje("Each article has a reference digit, enter the number of the article you want to see.");
                separacion();
				
				

	           

                do{
                	e=true;
                imprimirMensaje( "/--------------------INDEX-------------------------/");
                separacion();
                imprimirMensaje("Enter the number of the article you want to read");
                saltoLinea();
                mostrarArticulos(articulosEng,numArticulosEng,e);
               
                std::cin >> numArticulo;
                
                
                abrirArticulo(articulosEng, numArticulo, numArticulosEng);
                limpiarPantalla();
                imprimirMensaje("Want to open another article? (y/n)");
                std::cin >> respuesta;
                
                }while(respuesta == 'y' || respuesta == 'Y');
                
	   
	            
				break;
				
			case 3:
				std::cout <<"Gracias por Ingresar a nuestro proyecto <3"<<std::endl;
				break;
				
			default:
				std::cout <<"ERROR! Opcion no valida x_x"<<std::endl;
				
				return 2;
		
		}		
		
		
		
    	
    	imprimirMensaje("Desea volver a ejecutar el proyecto? (s/n): ");
    	std::cin >> respuesta;
	}while (respuesta == 's' || respuesta == 'S');
	
	
	imprimirMensaje( "Gracias por ingresar a nuestro proyecto");
	imprimirMensaje( "Integrantes: Jesus Castillo, Melary Morales, Zuzej Crespo, Heracles Sanchez, Dario Montero, Adriana Mendoza, Alfredo Mendoza");
	
	
    
    return 0;
}
