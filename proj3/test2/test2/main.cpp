#include <iostream>

using namespace std;

int main()
{
    string nw="nowa.txt";
    string fileName="/home/jas/\\file.exe";

    int i=fileName.length();
    for ( i--;fileName[i]!=92;i-- );
    for ( int j=0;j<nw.length();i++,fileName[i]=nw[j],j++);fileName[1+i]=0;

    cout << fileName;


    //Dobra, to mam pytanie (bo to jest pewnie powód dla którego zosta³ nadpisany plik wejœciowy) – co siê stanie, jeœli podam tylko nazwê pliku wejœciowego bez œcie¿ki bo w³aœnie plik exe mam w tym samym katalogu co plik z danymi? Czy pêtla zakoñczy siê w jakimœ sensownym momencie?

}
