#include <iostream>
#include <string.h>
#include <ctype.h>
#include <iomanip>
#include <fstream>


using namespace std;

void datos(char [], char[], char[], double& , double&, double&);
bool validacion(char []);
double calculoAT(double,double,double);
void calculoAM(double,double,double, stringstream&);
void calculoAP(double,double,double, stringstream&);
void msj();
void cargarArchivo(double,double,double,stringstream&, stringstream& ap);
void crearArchivo();

int main(){
    system( "Title Calculo AT, AM, AP " );
    
    msj();
    crearArchivo();
    char resp;
    do
    {   cout<<endl;
        cout<<"Nuevo calculo"<<endl;
        char x[100],y[100],z[100];
        double i,d,a;
        stringstream am, ap;
        datos(x,y,z,i,d,a);
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Para los datos: "<<i<<" , "<<d<<" , "<<a<<" :"<<endl;
        cout<<endl;
        cout<<"AT = "<<fixed<<setprecision(4)<<calculoAT(i,d,a)<<endl;
        calculoAM(i,d,a,am);
        calculoAP(i,d,a,ap);
        cout<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cargarArchivo(i,d,a,am,ap);
        cout<<"Queres realizar otro calculo? 's' para si : ";cin>>resp;    
        
    } while ( resp =='s' or resp == 'S');
    
    return (0);
    exit(1);
}

bool validacion(char num[]) {
    for (int i = 0; i < strlen(num); i++)
    {
        if(!isdigit(num[i]) && num[i]!='-' && num[i] != '.') {
            
            return false;
            break;
        }
    }
    return true;
}

void datos(char x[], char y[], char z[], double& i, double& d, double& a){
    cout<<endl;
    cout<<">Ingrese dato I: ";cin>>x;
    while(!validacion(x)){
        cout<<"No es un numero valido..Ingrese otro numero para I : ";cin>>x;    
    }
    if(validacion(x)){
        i = atof(x);

    }
    cout<<">Ingrese dato D: ";cin>>y;
    while(!validacion(y)){
        cout<<"No es un numero valido..Ingrese otro numero para D : ";cin>>y;    
    }
    if(validacion(y)){
        d = atof(y);
    }
    cout<<">Ingrese dato A: ";cin>>z;
    while(!validacion(z)){
        cout<<"No es un numero valido..Ingrese otro numero para A : ";cin>>z;    
    }
    if(validacion(z)){
        a = atof(z);
    }
}

double calculoAT(double i,double d,double a){
    double AT;
    AT = (a*d)-i;
    return AT;
}

void calculoAM(double i,double d,double a, stringstream& am){
    
    if(a==0){
        cout<<"AM = Division por cero no es posible"<<endl;
        am<<"AM = Division por cero no es posible"<<endl;
    }else{
        double AM;
        AM = calculoAT(i,d,a) / a;
        cout<<"AM = "<<fixed<<setprecision(4)<<AM<<endl;
        am<<fixed<<setprecision(4)<<AM;

    }
}

void calculoAP(double i, double d, double a, stringstream& ap){
    double den = a * d;
    if(den==0){
        cout<<"AP = Denominador 0, no es posible la division"<<endl;
        ap<<"AP = Denominador 0, no es posible la division"<<endl;
    }else{
        double num = calculoAT(i,d,a) * 100;
        double AP = num / den;
        cout<<"AP = "<<fixed<<setprecision(4)<<AP<<endl;
        ap<<fixed<<setprecision(4)<<AP;
    }
}
void msj(){
    cout<<"*****************************************************"<<endl;
    cout<<"*                Para mi amigo Fer                  *"<<endl;
    cout<<"*****************************************************"<<endl;
}

void cargarArchivo(double i, double d, double a, stringstream& am, stringstream& ap){
    fstream archivo;
    string texto;
    archivo.open("calculosFer.txt",ios::in);
    if(archivo.fail()==true){
        cout<<"Error al leer archivo\n";
        return;
    }
    while (!archivo.eof()){
        getline(archivo,texto);
    }
    archivo.close();
    fstream archivoB;
    archivoB.open("CalculosFer.txt", ios::app);
    if(archivoB.fail()){
            cout<<"no se puede abrir el archivo";
            return;
    }
    
    archivoB<<"-----------------------------------------------------\n";
    archivoB<<"Para los datos: "<<i<<" , "<<d<<" , "<<a<<" :\n";
    archivoB<<"\n";
    archivoB<<"AT = "<<fixed<<setprecision(4)<<calculoAT(i,d,a)<<endl;
    archivoB<<"AM = "<<am.str()<<endl;
    archivoB<<"AP = "<<ap.str()<<endl;
    archivoB<<endl;
    archivoB<<"-----------------------------------------------------\n";  
    archivoB.close();
}

void crearArchivo(){
    fstream archivoC;
    archivoC.open("calculosFer.txt",ios::out);
    if(archivoC.fail()==true){
        cout<<"Error al crear archivo\n";
        return;
    }
}
//SOFTWARE DESARROLLADO POR PROF. IVÁN ALTAMIRANO