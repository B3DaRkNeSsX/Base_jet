#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void ContinuareONonContinuare()
{
    char continua;
    setColor(2);
    cout << "\nVuoi continuare a usare il programma? (s/n) --> ";
    setColor(4);
    cin >> continua;
    if (continua != 's')
    {
        setColor(6);
        cout << "Chiusura programma in corso..." << "\n";
        Beep(1000, 500);
        exit(0);
    }
}
void assegnaMissioneJet(const string MissioniJet[], const int Missioni)
{
    char s_N = 's';
    int SceltaAssegnazioneMissione;
    setColor(2);
    cout << "\nVuoi assegnare una missione al jet? (s/n) --> ";
    cin >> s_N;
    if (s_N == 's')
    {
        for (int i = 0; i < Missioni; i++)
        {
            cout << "\n"
                 << i + 1 << "." << MissioniJet[i] << "\n\n";
        }
        setColor(2);
        cout << "inserisci il numero della missione che vuoi assegnare al jet--> ";
        setColor(4);
        cin >> SceltaAssegnazioneMissione;
        cout << "\n";
        switch (SceltaAssegnazioneMissione)
        {
            setColor(4);
        case 1:
            cout << "\n✔ Missione Assegnata: Scorta aerea\n";
            break;
        case 2:
            cout << "\n✔ Missione Assegnata: Ricognizione\n";
            break;
        case 3:
            cout << "\n✔ Missione Assegnata: Supporto aereo alle truppe di terra\n";
            break;
        case 4:
            cout << "\n✔ Missione Assegnata: Attacco aereo\n";
            break;
        case 5:
            cout << "\n✔ Missione Assegnata: Evacuazione\n";
            break;
        default:
            cout << "\n[!]-->Selezionare un numero valido.\n";
            break;
        }
    }
}
void AssegnaZonaMissioneJet(const string ZonaMissione[], const int ZoneMissioni)
{
    int SceltaAssegnazioneZonaMissione;
    for (int i = 0; i < ZoneMissioni; i++)
    {
        cout << i + 1 << ". " << ZonaMissione[i] << "\n";
    }
    cout << "|🔧|Assegnare zona missione--> ";
    cin >> SceltaAssegnazioneZonaMissione;
    switch (SceltaAssegnazioneZonaMissione)
    {
    case 1:
        cout << "\n✔ Zona assegnata: Europa [35% risk rate]";
        break;
    case 2:
        cout << "\n✔ Zona assegnata: Russia [90% risk rate]";
        break;
    case 3:
        cout << "\n✔ Zona assegnata: Ucraina [75% risk rate]";
        break;
    case 4:
        cout << "\n✔ Zona assegnata: Cina [65% risk rate]";
        break;
    case 5:
        cout << "\n✔ Zona assegnata: America [15% risk rate]";
        break;
    default:
        cout << "\n[!]-->Selezionare un numero valido.\n";
        break;
    }
}
void assegnaStatoJet(const string statoJet[], const int StatiJet)
{
    int SceltaAssegnazioneStato;
    cout << "Vuoi assegnare uno stato al jet? (s/n) --> ";
    char SceltaStatoJet;
    cin >> SceltaStatoJet;
    if (SceltaStatoJet == 's')
    {
        for (int i = 0; i < StatiJet; i++)
        {
            cout << i + 1 << ". " << statoJet[i] << "\n";
        }
        cout << "Inserisci il numero dello stato da assegnare al jet --> ";
        cin >> SceltaAssegnazioneStato;
        switch (SceltaAssegnazioneStato)
        {
        case 1:
            cout << "✔ Stato assegnato: In manutenzione" << "\n";
            break;
        case 2:
            cout << "✔ Stato assegnato: In missione" << "\n";
            break;
        case 3:
            cout << "✔ Stato assegnato: Pronto al decollo" << "\n";
            break;
        default:
            cout << "❌ Stato inesistente" << "\n";
            Beep(1000, 500);
            break;
        }
    }
}

int main()
{
    SetConsoleOutputCP(65001); // Imposta la console su UTF-8, accenti e simboli funzionano senza buggarsi

    setColor(2);
    cout << "---------------------------------------------------------------\n";
    cout << "           --|| Benvenuto nel gestore del traffico aereo militare ||--\n";
    cout << "---------------------------------------------------------------\n";
    cout << "\n";
    cout << "🌐 Per accedere al menù degli hangar premi 's', altrimenti premi 'n' per uscire dal programma. --> ";
    char Lettera_log_in;
    cin >> Lettera_log_in;

    if (Lettera_log_in == 's')
    {
        const int MaxJetHangar = 2;
        const int Hangar = 3;
        const int StatiJet = 3;
        const int Missioni = 5;
        const int ZoneMissioni = 5;

        string jetHangar1[MaxJetHangar] = {"SU-27 Flanker", "F-35 Lightning II"};
        string jetHangar2[MaxJetHangar] = {"Eurofighter Typhoon", "F-22 Raptor"};
        string jetHangar3[MaxJetHangar] = {"F-16 Fighting Falcon", "MiG-29 Fulcrum"};
        string hangar[Hangar] = {"Hangar 1", "Hangar 2", "Hangar 3"};
        string statoJet[StatiJet] = {"In manutenzione🔧", "In missione", "Pronto al decollo"};
        string MissioniJet[Missioni] = {"Scorta aerea", "Ricognizione", "Supporto aereo alle truppe di terra", "Attacco aereo", "Evacuazione"};
        string ZonaMissione[ZoneMissioni] = {"Europa", "Russia", "Ucraina", "Cina ", "America"};

        int scelta;
        while (true)
        {
            setColor(2);
            cout << "\n";
            cout << "Menu scelta hangar:" << "\n\n";
            setColor(4);
            cout << "Hangar [1]" << "\n";
            cout << "Hangar [2]" << "\n";
            cout << "Hangar [3]" << "\n";
            setColor(2);
            cout << "\nLa tua scelta --> ";
            setColor(4);
            cin >> scelta;
            setColor(2);

            switch (scelta)
            {
            case 1:
                cout << "\nVisualizzazione contenuto hangar 1..." << "\n";
                for (int i = 0; i < MaxJetHangar; i++)
                {
                    setColor(6);
                    cout << "\n"
                         << jetHangar1[i];
                    cout << "\n";
                }
                break;
            case 2:
            setColor(2);
                cout << "Visualizzazione contenuto hangar 2..." << "\n";
                for (int i = 0; i < MaxJetHangar; i++)
                {
                    setColor(6);
                    cout << "\n"
                         << jetHangar2[i];
                    cout << "\n";
                }
                break;
            case 3:
            setColor(2);
                cout << "Visualizzazione contenuto hangar 3..." << "\n";
                for (int i = 0; i < MaxJetHangar; i++)
                {
                    setColor(6);
                    cout << "\n"
                         << jetHangar3[i];
                    cout << "\n";
                }
                break;
            default:
                setColor(2);
                cout << "Hangar inesistente" << "\n";
                Beep(1000, 500);
                continue;
            }

            int sceltaInfJet;
            setColor(2);
            cout << "\nInserisci il numero del jet di cui vuoi leggere le informazioni ↓";
            cout << "\nla tua scelta-→ ";
            setColor(4);
            cin >> sceltaInfJet;
            setColor(6);
            switch (scelta)
            {
            case 1:
                switch (sceltaInfJet)
                {
                case 1:
                    cout << "\n";
                    cout << "Sukhoi Su-27 'Flanker'\n"
                         << "Ruolo: Caccia da superiorita' aerea\n"
                         << "Origine: Unione Sovietica (URSS)\n"
                         << "Entrata in servizio: 1985\n"
                         << "Velocita' massima: ~2.500 km/h (Mach 2.35)\n"
                         << "Autonomia: ~3.530 km senza rifornimento\n"
                         << "Armamento:\n"
                         << "- 1 cannone GSh-30-1 da 30 mm\n"
                         << " - Missili aria-aria (R-27, R-73, R-77)\n"
                         << "Motori: 2 × Saturn AL-31F\n"
                         << "Punti di forza:\n"
                         << " - Manovrabilita' eccezionale\n"
                         << " - Ottima autonomia\n"
                         << " - Base per varianti piu' avanzate (Su-30, Su-35)\n"
                         << "Curiosita': Creato per contrastare l’F-15 Eagle degli USA.\n";

                    cout << "\n";
                    setColor(2);
                    assegnaStatoJet(statoJet, StatiJet);
                    ContinuareONonContinuare();
                    assegnaMissioneJet(MissioniJet, Missioni);
                    AssegnaZonaMissioneJet(ZonaMissione, ZoneMissioni);
                    ContinuareONonContinuare();
                    break;
                case 2:
                    cout << "\n";
                    cout << "Lockheed Martin F-35 Lightning II\n"
                         << "Ruolo: Caccia multiruolo di quinta generazione\n"
                         << "Origine: Stati Uniti\n"
                         << "Entrata in servizio: 2015\n"
                         << "Velocita' massima: ~1.930 km/h (Mach 1.6)\n"
                         << "Autonomia: ~2.220 km senza rifornimento\n"
                         << "Armamento:\n"
                         << " - 1 cannone GAU-22/A da 25 mm\n"
                         << " - Missili aria-aria (AIM-120 AMRAAM, AIM-9X Sidewinder)\n"
                         << " - Bombe guidate (JDAM, SDB, Paveway)\n"
                         << " - Missili da crociera (JSM)\n"
                         << "Motore: 1 × Pratt & Whitney F135\n"
                         << "Tecnologie avanzate:\n"
                         << " - Stealth (bassa osservabilita' ai radar)\n"
                         << " - Sensori avanzati per guerra elettronica\n"
                         << " - Comunicazione e condivisione dati con altre unita'\n"
                         << "Varianti:\n"
                         << " - F-35A (versione per l’aeronautica, decollo convenzionale)\n"
                         << " - F-35B (versione STOVL, decollo corto e atterraggio verticale)\n"
                         << " - F-35C (versione per portaerei, ali ripiegabili)\n"
                         << "Curiosita': Considerato il caccia piu' avanzato al mondo, usato da diverse nazioni NATO.\n";
                    setColor(2);
                    assegnaStatoJet(statoJet, StatiJet);
                    ContinuareONonContinuare();
                    assegnaMissioneJet(MissioniJet, Missioni);
                    AssegnaZonaMissioneJet(ZonaMissione, ZoneMissioni);
                    ContinuareONonContinuare();
                    break;
                default:
                    setColor(2);
                    cout << "❌" << "\n";
                    Beep(1000, 500);
                    break;
                }
                break;
            case 2:
                switch (sceltaInfJet)
                {
                case 1:
                    cout << "\n";
                    cout << "Eurofighter Typhoon\n"
                         << "Ruolo: Caccia multiruolo\n"
                         << "Origine: Europa (Regno Unito, Germania, Italia, Spagna)\n"
                         << "Entrata in servizio: 2003\n"
                         << "Velocita' massima: ~2.495 km/h (Mach 2.35)\n"
                         << "Autonomia: ~1.390 km senza rifornimento\n"
                         << "Armamento:\n"
                         << " - 1 cannone Mauser BK-27 da 27 mm\n"
                         << " - Missili aria-aria (AIM-120 AMRAAM, AIM-132 ASRAAM)\n";
                    setColor(2);
                    assegnaStatoJet(statoJet, StatiJet);
                    ContinuareONonContinuare();
                    assegnaMissioneJet(MissioniJet, Missioni);
                    AssegnaZonaMissioneJet(ZonaMissione, ZoneMissioni);
                    ContinuareONonContinuare();
                    break;
                case 2:
                    cout << "\n";
                    cout << "Lockheed Martin F-22 Raptor\n"
                         << "Ruolo: Caccia da superiorita' aerea\n"
                         << "Origine: Stati Uniti\n"
                         << "Entrata in servizio: 2005\n"
                         << "Velocita' massima: ~2.410 km/h (Mach 2.25)\n"
                         << "Autonomia: ~3.200 km senza rifornimento\n"
                         << "Armamento:\n"
                         << " - 1 cannone M61A2 Vulcan da 20 mm\n"
                         << " - Missili aria-aria (AIM-120 AMRAAM, AIM-9 Sidewinder)\n";
                    setColor(2);
                    assegnaStatoJet(statoJet, StatiJet);
                    ContinuareONonContinuare();
                    assegnaMissioneJet(MissioniJet, Missioni);
                    AssegnaZonaMissioneJet(ZonaMissione, ZoneMissioni);
                    ContinuareONonContinuare();
                    break;
                default:
                    setColor(2);
                    cout << "❌" << "\n";
                    Beep(1000, 500);
                    break;
                }
                break;
            case 3:
                switch (sceltaInfJet)
                {
                case 1:
                    cout << "\n";
                    cout << "General Dynamics F-16 Fighting Falcon\n"
                         << "Ruolo: Caccia multiruolo\n"
                         << "Origine: Stati Uniti\n"
                         << "Entrata in servizio: 1978\n"
                         << "Velocita' massima: ~2.414 km/h (Mach 2)\n"
                         << "Autonomia: ~4.220 km senza rifornimento\n"
                         << "Armamento:\n"
                         << " - 1 cannone M61A1 Vulcan da 20 mm\n"
                         << " - Missili aria-aria (AIM-9 Sidewinder, AIM-120 AMRAAM)\n";
                    assegnaStatoJet(statoJet, StatiJet);
                    ContinuareONonContinuare();
                    assegnaMissioneJet(MissioniJet, Missioni);
                    AssegnaZonaMissioneJet(ZonaMissione, ZoneMissioni);
                    ContinuareONonContinuare();
                    break;
                case 2:
                    cout << "\n";
                    cout << "Mikoyan-Gurevich MiG-29 Fulcrum\n"
                         << "Ruolo: Caccia multiruolo\n"
                         << "Origine: Unione Sovietica (URSS)\n"
                         << "Entrata in servizio: 1982\n"
                         << "Velocita' massima: ~2.445 km/h (Mach 2.25)\n"
                         << "Autonomia: ~1.430 km senza rifornimento\n"
                         << "Armamento:\n"
                         << " - 1 cannone GSh-30-1 da 30 mm\n"
                         << " - Missili aria-aria (R-60, R-73, R-77)\n";
                    setColor(2);
                    assegnaStatoJet(statoJet, StatiJet);
                    ContinuareONonContinuare();
                    assegnaMissioneJet(MissioniJet, Missioni);
                    AssegnaZonaMissioneJet(ZonaMissione, ZoneMissioni);
                    ContinuareONonContinuare();
                    break;
                default:
                    setColor(2);
                    cout << "❌" << "\n";
                    Beep(1000, 500);
                    break;
                }
                break;
            default:
                setColor(2);
                cout << "Hangar inesistente" << "\n";
                Beep(1000, 500);
                break;
            }
        }
    }
    else
    {
        setColor(6);
        cout << "Chiusura programma in corso..." << "\n";
        Beep(1000, 500);
    }

    return 0;
}