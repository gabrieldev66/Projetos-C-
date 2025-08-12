#include <iostream>
#include <string>
#include <vector>

using namespace std;

void bubbleSort(int numeros[], int n)
{

    bool trocou = false;

    do
    {
        trocou = false;
       
	    for (int i = 0; i < n - 1; i++){
            int primeiroNumero = numeros[i];    // (teste)1!
            int segundoNumero = numeros[i + 1]; // (teste)!2

            if (segundoNumero < primeiroNumero)
            {
                // trocar swap!
                numeros[i] = segundoNumero;
                numeros[i + 1] = primeiroNumero;
                
				trocou = true;
            }
        }

        /* code */
    } while (trocou);
}

int main(){

    int vetor[] = {8, 3, 6, 9, 14, 2, 5};

   bubbleSort( vetor, 7);
    
	for (int i= 0; i < 7; i++){

        cout << vetor[i] << " ";
    }

    cout << endl;

return 0;

}