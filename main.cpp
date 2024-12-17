#include <iostream>
#include <string.h>

#define MAX_STUDENTI 50
#define MAX_NOME 50

using namespace std;

typedef struct
{
    char nome[MAX_NOME];
    int voti[3];
    float media;
} Studente;

void calcolaMedia(Studente &studente)
{
    int somma = 0;
    for (int i = 0; i < 3; i++)
    {
        somma += studente.voti[i];
    }
    studente.media = somma / 3.0;
}

void inserisciDatiStudente(Studente &studente)
{
    cout << "\nInserisci il nome dello studente: ";
    cin.ignore();
    cin.getline(studente.nome, MAX_NOME);

    cout << "Inserisci i 3 voti per " << studente.nome << ":\n";
    int j=0;
    float possible_voto;
    while (j<3) {
	cout<< "Voto " << j+1 << ": ";
        cin>>possible_voto;
	if (possible_voto >= 1 && possible_voto <= 10) {
		studente.voti[j] = possible_voto;
		j++;
	} else {
		cout<<"Inserisci un voto tra 1 e 10!\n"<<endl;
	}
    }

    calcolaMedia(studente);
}

void stampaRiepilogo(const Studente studenti[], int numeroStudenti)
{
    cout << "\n----------------------------------------------------------\n";
    cout << "\nRiepilogo voti:\n";
    for (int i = 0; i < numeroStudenti; i++)
    {
        cout << "Nome: " << studenti[i].nome << "\n";
        cout << "Voti: " << studenti[i].voti[0] << ", " << studenti[i].voti[1] << ", " << studenti[i].voti[2] << "\n";
        cout << "Media: " << studenti[i].media << "\n\n";
    }
}

int main()
{
    int numeroStudenti;
    Studente studenti[MAX_STUDENTI];

    cout << "Inserisci il numero di studenti (massimo " << MAX_STUDENTI << "): ";
    cin >> numeroStudenti;

    if (numeroStudenti > MAX_STUDENTI)
    {
        cout << "Numero di studenti troppo alto!\n";
        return 1;
    }

    for (int i = 0; i < numeroStudenti; i++)
    {
        inserisciDatiStudente(studenti[i]);
    }

    stampaRiepilogo(studenti, numeroStudenti);

    return 0;
}
