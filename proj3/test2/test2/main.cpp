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


    //Dobra, to mam pytanie (bo to jest pewnie pow�d dla kt�rego zosta� nadpisany plik wej�ciowy) � co si� stanie, je�li podam tylko nazw� pliku wej�ciowego bez �cie�ki bo w�a�nie plik exe mam w tym samym katalogu co plik z danymi? Czy p�tla zako�czy si� w jakim� sensownym momencie?

}
