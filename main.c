/*autor : Noel Clement
          Arnoult Antoine
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ctype.h>

const char *SaveGame = "SaveGame.txt";
const char *PlayerInfo = "PlayerInfo.txt";
const char *Histoire = "Histoire.txt";
const char *Story = "Story.txt";
char *language;
const int des = 21;

char Lfile[200];

char Nom_j[20];

int nbMobs, room, langue;

//declaration of the inventory stucture
typedef struct
{
    int Gold;
    int HealtPot;
    int HastePot;
    int Resistance;
    int Invisibility;
    int Key;
    int MonsterCostume;
} Inventory;

// declaration of the Enemie structure
typedef struct
{
    int ID_Enemie;
    int PV_Enemie;
    int PVmax_Enemie;
    int ATK_Enemie;
    int Celerite_Enemie;
} Enemie;
// declaration of the classe structure
typedef struct
{
    int ID_classe;
    int PV_classe;
    int PVmax_classe;
    int DEF_classe;
    int ATK_classe;
    int Celerite_classe;
    int Mana_classe;
} classe;
// read a specifique line of the TXT file
char Position(int line)
{
    FILE *file = fopen("SaveGame.txt", "r");
    if (file != NULL)
    {
        int currentLine = 1;
        char currentChar = '\0';

        while (currentLine < line)
        {
            currentChar = fgetc(file);
            if (currentChar == '\n')
            {
                currentLine++;
                currentChar = fgetc(file);
            }
        }
        if (currentLine == line)
        {
            return currentChar;
        }
    }
    else
    {
        printf("Unable to open the file.\n");
        return '\0';
    }
}
void ecriture(int line, char message)
{
    FILE *file = fopen(SaveGame, "r+");
    if (file != NULL)
    {
        int currentLine = 1;
        int currentChar1;
        long offset = 0;

        while (currentLine < line)
        {
            currentChar1 = fgetc(file);

            if (currentChar1 == '\n')
            {
                currentLine++;
                offset = ftell(file);
            }
        }
        fseek(file, offset, SEEK_SET);
        fprintf(file, "%c", message);

        fclose(file);
    }
    else
    {
        printf("\n");
    }
    return;
}
void lecture(int line)
{
    FILE *file = fopen(Lfile, "r");

    if (file != NULL)
    {
        int currentLine = 1;
        int currentChar;

        while (currentLine < line)
        {
            currentChar = fgetc(file);

            if (currentChar == '\n')
            {
                currentLine++;
            }
        }

        do
        {
            currentChar = fgetc(file);
            printf("%c", currentChar);
        } while (currentChar != '\n' && currentChar != EOF);

        fclose(file);
    }
    else
    {
        printf("\n");
    }
    return;
}
// insert statistique of a class into the player variable
classe choix_classes(int ID_classe)
{
    switch (ID_classe)
    {
    case 1:
        classe Barbare;
        Barbare.ID_classe = 1;
        Barbare.Celerite_classe = 3;
        Barbare.DEF_classe = 2;
        Barbare.ATK_classe = 4;
        Barbare.PV_classe = 60;
        Barbare.PVmax_classe = 60;
        Barbare.Mana_classe = 0;
        ecriture(2, 'B');
        return (Barbare);
        break;

    case 2:

        classe Mage;
        Mage.ID_classe = 2;
        Mage.Celerite_classe = 4;
        Mage.DEF_classe = 1;
        Mage.ATK_classe = 3;
        Mage.PV_classe = 40;
        Mage.PVmax_classe = 40;
        Mage.Mana_classe = 100;
        ecriture(2, 'M');
        return (Mage);

        break;

    case 3:

        classe Paladin;
        Paladin.ID_classe = 3;
        Paladin.Celerite_classe = 2;
        Paladin.DEF_classe = 2;
        Paladin.ATK_classe = 4;
        Paladin.PV_classe = 50;
        Paladin.PVmax_classe = 50;
        Paladin.Mana_classe = 50;
        ecriture(2, 'P');
        return (Paladin);
        break;

    case 4:
        classe Voleur;
        Voleur.ID_classe = 4;
        Voleur.Celerite_classe = 6;
        Voleur.DEF_classe = 1;
        Voleur.ATK_classe = 3;
        Voleur.PV_classe = 50;
        Voleur.PVmax_classe = 50;
        Voleur.Mana_classe = 30;
        ecriture(2, 'V');
        return (Voleur);
        break;
    default:
        printf("erreur ID Classe");
        break;
    }
}

// insert statistique of each Enemie into they respective variable
Enemie setup_Enemie(int ID_Enemie)
{
    switch (ID_Enemie)
    {
    case 1:
        Enemie squelette;
        squelette.ID_Enemie = 1;
        squelette.Celerite_Enemie = 3;
        squelette.ATK_Enemie = 4;
        squelette.PV_Enemie = 20;
        squelette.PVmax_Enemie = 20;
        return (squelette);
        break;
    case 2:
        Enemie araignee;
        araignee.ID_Enemie = 2;
        araignee.Celerite_Enemie = 5;
        araignee.ATK_Enemie = 4;
        araignee.PV_Enemie = 25;
        araignee.PVmax_Enemie = 25;
        return (araignee);

        break;

    case 3:
        Enemie slime;
        slime.ID_Enemie = 3;
        slime.Celerite_Enemie = 2;
        slime.ATK_Enemie = 3;
        slime.PV_Enemie = 35;
        slime.PVmax_Enemie = 35;
        return (slime);
        break;
    case 4:
        Enemie dragon;
        dragon.ID_Enemie = 4;
        dragon.Celerite_Enemie = 7;
        dragon.ATK_Enemie = 5;
        dragon.PV_Enemie = 50;
        dragon.PVmax_Enemie = 50;
        return (dragon);
        break;
    default:
        lecture(321);
        break;
    }
}

// Check if the files are available
void verif_fichier()
{
    // open the file
    FILE *in_save = fopen(SaveGame, "r");
    FILE *in_histoire = fopen(Histoire, "r");
    FILE *in_story = fopen(Story, "r");

    // look and create file

    if (in_save == NULL)
    {
        printf("ERROR: file missing : save ! \n");
    }
    if (in_histoire == NULL)
    {
        printf("ERROR: file missing : histoire !\n");
    }
    if (in_story == NULL)
    {
        printf("ERROR: file missing : story !\n");
    }
}

/*=========================combats=====================*/

// roll a dice to see if the action is a success
int lancer(int difficulter)
{
    int resultat = rand() % des;
    if (resultat >= difficulter)
    {
        printf("%d", resultat);
        lecture(76);
        return 1;
    }
    else
    {
        printf("%d", resultat);
        lecture(77);
        return 0;
    }
}

// description of each action depending of the class of the player
int tour_j(classe joueur)
{
    lecture(102);
    int choix = 0,
        i = 0;
    switch (joueur.ID_classe)
    {
    /*=========Barbar turn==============*/
    case 1:
        for (i = 144; i < 148; i++)
        {
            lecture(i);
        }

        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            lecture(149);
            return 1;
            break;
        case 2:
            lecture(151);
            if (lancer(14) == 1)
            {
                lecture(153);
                return 5;
            }
            else
            {
                lecture(155);
                return 0;
            }

            break;
        case 3:
            lecture(157);
            return 2;
            break;
        case 4:
            lecture(159);
            return 3;
            break;
        case 5:
            return 8;
            break;
        default:

            lecture(155);
            break;
        }

        break;

    /*=========Mage turn==============*/
    case 2:
        for (i = 184; i < 188; i++)
        {
            lecture(i);
        }

        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            lecture(189);
            return 1;
            break;
        case 2:
            lecture(191);
            if (lancer(15) == 1)
            {
                lecture(193);
                return 6;
            }
            else
            {
                lecture(195);
                return 0;
            }

            break;
        case 3:
            lecture(197);
            return 2;
            break;
        case 4:
            lecture(199);
            return 3;
            break;
        case 5:
            return 8;
            break;
        default:

            lecture(155); //
            break;
        }

        break;

    /*=========Paladin turn==============*/
    case 3:
        for (i = 230; i < 234; i++)
        {
            lecture(i);
        }
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            lecture(235);
            return 1;
            break;
        case 2:
            lecture(237);
            if (lancer(14) == 1)
            {
                lecture(239);
                return 7;
            }
            else
            {
                lecture(241);
                return 0;
            }

            break;
        case 3:
            lecture(243);
            return 2;
            break;
        case 4:
            lecture(245);
            return 3;
            break;
        case 5:
            return 8;
            break;
        default:

            lecture(155);
            break;
        }

        break;

    /*=========Thief turn==============*/
    case 4:
        for (i = 106; i < 110; i++)
        {
            lecture(i);
        }
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            lecture(111);
            return 1;
            break;
        case 2:
            lecture(113);
            if (lancer(13) == 1)
            {
                lecture(115);
                return 4;
            }
            else
            {
                lecture(117);
                return 0;
            }

            break;
        case 3:
            lecture(119);
            return 2;
            break;
        case 4:
            lecture(121);
            return 3;
            break;
        case 5:
            return 8;
            break;
        default:
            lecture(155);
            break;
        }

        break;

    default:
        lecture(155);
        break;
    }
}

// Enemie choose what he do depending on player stats
int tour_e(Enemie type, classe joueur, int j_attaquable, int j_ralenti, int j_empoisone, int e_invisible, int j_enflammer)
{
    switch (type.ID_Enemie)
    {
    case 1: /*=====================skeleton=========================*/
        if (joueur.PV_classe - type.ATK_Enemie <= 0 && j_attaquable == 0)
        {
            lecture(62);

            return 1; // attaque basic
        }
        else if (type.PV_Enemie <= type.PV_Enemie / 3 && rand() % des >= 18)
        {
            lecture(61);
            return 4; // soin special squelette
        }
        else if (joueur.Celerite_classe / 2 <= type.Celerite_Enemie / 2 && j_ralenti == 0 && rand() % des >= 14)
        {
            lecture(63);
            return 5; // attaque special squelette
        }
        else if (j_attaquable == 0)
        {
            lecture(62);
            return 1;
        }
        else
        {
            lecture(67);
            return 0;
        }

        break;
    case 2: /*============================spider================================*/
        if (joueur.PV_classe - type.ATK_Enemie <= 0 && j_attaquable == 0)
        {
            lecture(64);

            return 1; // attaque basic
        }
        else if (type.PV_Enemie <= type.PV_Enemie / 3 && rand() % des >= 15 && j_attaquable == 0 && j_ralenti == 0 && joueur.Celerite_classe / 2 <= type.Celerite_Enemie / 2)
        {
            lecture(66);

            return 3; // attaque special araignee
        }
        else if (rand() % des >= 17 && j_attaquable == 0 && j_ralenti == 0 && joueur.Celerite_classe / 2 <= type.Celerite_Enemie / 2)
        {
            lecture(66);
            return 3; // attaque special araignee
        }
        else if (j_attaquable == 0)
        {
            lecture(64);

            return 1; // attaque basic
        }
        else
        {
            lecture(68);
            return 0;
        }
        break;
    case 3:                   /*============================slime================================*/
        if (e_invisible == 1) // reapparition slime
        {
            lecture(81);
            if (j_attaquable == 0) // attaque
            {
                lecture(82);
                return 1;
            }
            else // n'attaque pas
            {
                lecture(83);
                return 0;
            }
        }

        if (joueur.PV_classe - type.ATK_Enemie <= 0 && j_attaquable == 0)
        {
            lecture(70);

            return 1; // attaque basic
        }
        else if (type.PV_Enemie <= type.PVmax_Enemie / 2 && rand() % des >= 17 && e_invisible == 0)
        {
            lecture(80);
            return 6; // disparition slime
        }
        else if (rand() % des >= 17 && j_empoisone == 0)
        {
            lecture(79);
            return 7; // plui de slime
        }
        else if (j_attaquable == 0)
        {
            lecture(70);
            return 1; // attaque basic
        }
        break;

    case 4: /*================================Dragon=================================*/

        if (joueur.PV_classe - type.ATK_Enemie <= 0 && j_attaquable == 0)
        {
            lecture(89);

            return 1; // attaque basic
        }
        else if (type.PV_Enemie <= type.PVmax_Enemie / 2)
        {
            if (joueur.PV_classe - type.ATK_Enemie <= 0 && j_attaquable == 0)
            {
                lecture(89);

                return 1; // attaque basic
            }
            else if (rand() % des >= 18)
            {
                return 10; // mur de flamme
            }
            else
            {
                lecture(89);
                return 1; // attaque basic
            }
        }
        else if (rand() % des >= 16 && j_enflammer == 0)
        {
            lecture(91);
            return 8; // souffle de feux
        }
        else if (rand() % des >= 16 && j_empoisone == 0)
        {

            return 7; // souffle acide
        }
        else
        {
            lecture(89);
            return 1;
        }
        break;

    default:
        lecture(321);
        break;
    }
}

// describe the healing action of the classe played by the player then return the value of healing
int soin(classe joueur)
{
    if (joueur.PV_classe < joueur.PVmax_classe)
    {
        switch (joueur.ID_classe)
        {
        case 1:
            lecture(52);
            return 1;
            break;
        case 2:
            lecture(54);
            return 9;
            break;
        case 3:
            lecture(56);
            return 6;
            break;
        case 4:
            lecture(58);
            return 4;
            break;

        default:
            break;
        }
    }
    else if (joueur.PV_classe >= joueur.PVmax_classe)
    {
        lecture(60);
        return (0);
    }
}

// one big function for the combat, the one who start the combat depend on the celerity,the combat loop until one of them die
int combat(int nbMobs, Enemie type, classe joueur)
{

    type.PV_Enemie = type.PVmax_Enemie;
    int i = 0,
        resultat = 0,
        degats = 0,
        j_invisible = 0,
        defense_j = joueur.DEF_classe,
        celerite_j = joueur.Celerite_classe,
        celerite_e = type.Celerite_Enemie,
        j_renforcer = 0,
        j_ralenti = 0,
        j_empoisone = 0,
        j_enflammer = 0,
        e_ralenti = 0,
        J_danger = 0,
        e_invisible = 0;

    float multiplicateur_e = 1,
          multiplicateur_j = 1;

    lecture(72);
    
    if (Position(12)!= '0')
    {
        lecture(103);
        j_empoisone = 4;
    }
        
    
        do
        {

            if (celerite_e / 2 >= celerite_j)
            {
                /*========================advantage monster========================================*/
                lecture(47);
                resultat = tour_e(type, joueur, j_invisible, j_ralenti, j_empoisone, e_invisible, j_enflammer);
                switch (resultat)
                {
                case 1:
                    degats = type.ATK_Enemie * multiplicateur_e;
                    degats = degats - defense_j;
                    if (degats < 0)
                    {
                        degats = 0;
                    }

                    joueur.PV_classe = joueur.PV_classe - degats;
                    lecture(43);
                    printf("%d", degats);
                    lecture(45);
                    multiplicateur_e = 1;
                    break;
                case 3:
                    j_ralenti = 3;
                    celerite_j = celerite_j / 2;

                    break;
                case 4:
                    type.PV_Enemie = type.PV_Enemie + 7;
                    break;
                case 5:
                    j_ralenti = 2;
                    joueur.PV_classe = joueur.PV_classe - 2;
                    break;
                case 6:
                    e_invisible = 2;
                    celerite_e = celerite_e * 2;
                    break;
                case 7:
                    j_empoisone = 4;
                    break;
                case 8:
                    j_enflammer = 4;
                    break;
                case 10:
                    J_danger = 3;
                    break;
                default:
                    lecture(319);
                    break;
                }
                sleep(4);
            }
            else if (celerite_j / 2 >= celerite_e)
            {

                /*======================advantage player====================================*/
                lecture(49);
                resultat = tour_j(joueur);
                switch (resultat)
                {
                case 1:
                    if (J_danger != 0)
                    {
                        joueur.PV_classe = joueur.PV_classe - J_danger;
                    }
                    if (e_invisible == 1)
                    {
                        lecture(42);
                    }
                    else
                    {
                        degats = joueur.ATK_classe * multiplicateur_j;
                        if (degats < 0)
                        {
                            degats = 0;
                        }
                        type.PV_Enemie = type.PV_Enemie - degats;
                        lecture(41);
                        printf("%d", degats);
                        lecture(45);
                    }
                    multiplicateur_j = 1;

                    break;

                case 2:
                    joueur.PV_classe = joueur.PV_classe + soin(joueur);
                    if (joueur.PV_classe > joueur.PVmax_classe)
                    {
                        joueur.PV_classe = joueur.PVmax_classe;
                    }
                    break;

                case 3:
                    defense_j = defense_j * 2;
                    break;

                case 4:
                    j_invisible = 2;
                    multiplicateur_j = multiplicateur_j * 2;
                    celerite_j = celerite_j * 2;

                    break;
                case 5:
                    defense_j = defense_j * 2;
                    j_renforcer = 2;
                    multiplicateur_j = multiplicateur_j * 2;
                    break;

                case 6:
                    type.PV_Enemie = type.PV_Enemie - 6;
                    break;

                case 7:
                    multiplicateur_e = 0.5;
                    celerite_e = celerite_e / 2;
                    e_ralenti = 2;
                    break;
                case 8:

                    lecture(276);
                    printf("nom joueur\n");
                    lecture(277);
                    printf("%d \n", joueur.PV_classe);
                    lecture(278);
                    printf("%d \n", celerite_j);
                    lecture(279);
                    printf("%d \n", defense_j);
                    lecture(280);
                    printf("%d \n", joueur.ATK_classe);
                    lecture(281);
                    switch (type.ID_Enemie)
                    {
                    case 1:
                        printf("araignée\n");
                        break;
                    case 2:
                        printf("squelette\n");
                        break;
                    case 3:
                        printf("slime\n");
                        break;

                    default:
                        break;
                    }
                    lecture(282);
                    printf("%d \n", type.PV_Enemie);
                    lecture(283);
                    printf("%d \n", celerite_e);
                    lecture(284);
                    printf("%d \n", type.ATK_Enemie);
                    lecture(285);

                    break;

                default:
                    lecture(319);
                    break;
                }
                sleep(4);
            }

            /*========================Monster Turn========================================*/
            resultat = tour_e(type, joueur, j_invisible, j_ralenti, j_empoisone, e_invisible, j_enflammer);
            switch (resultat)
            {
            case 1:
                degats = (type.ATK_Enemie * multiplicateur_e) - defense_j;
                if (degats < 0)
                {
                    degats = 0;
                }
                joueur.PV_classe = joueur.PV_classe - degats;
                lecture(43);
                printf("%d", degats);
                lecture(45);
                break;
            case 3:
                j_ralenti = 3;
                celerite_j = celerite_j / 2;

                break;
            case 4:
                type.PV_Enemie = type.PV_Enemie + 7;
                break;
            case 5:
                j_ralenti = 2;
                joueur.PV_classe = joueur.PV_classe - 2;
                break;
            case 6:
                e_invisible = 2;
                celerite_e = celerite_e * 2;
                break;
            case 7:
                j_empoisone = 4;
                break;
            case 8:
                j_enflammer = 4;
                break;
            case 10:
                J_danger = 3;
                break;

            default:
                lecture(319);
                break;
            }
            sleep(4);

            /*======================TURN OF THE PLAYER====================================*/
            resultat = tour_j(joueur);
            switch (resultat)
            {
            case 1:
                if (J_danger != 0)
                {
                    joueur.PV_classe = joueur.PV_classe - J_danger;
                }
                if (e_invisible == 1)
                {
                    lecture(42);
                }
                else
                {
                    degats = joueur.ATK_classe * multiplicateur_j;
                    if (degats < 0)
                    {
                        degats = 0;
                    }
                    type.PV_Enemie = type.PV_Enemie - degats;
                    lecture(41);
                    printf("%d", degats);
                    lecture(45);
                }
                multiplicateur_j = 1;

                break;

            case 2:
                joueur.PV_classe = joueur.PV_classe + soin(joueur);
                if (joueur.PV_classe > joueur.PVmax_classe)
                {
                    joueur.PV_classe = joueur.PVmax_classe;
                }
                break;

            case 3:
                defense_j = defense_j * 2;
                break;

            case 4:
                j_invisible = 2;
                multiplicateur_j = multiplicateur_j * 2;
                celerite_j = celerite_j * 2;

                break;
            case 5:
                defense_j = defense_j * 2;
                j_renforcer = 2;
                multiplicateur_j = multiplicateur_j * 2;
                break;

            case 6:
                type.PV_Enemie = type.PV_Enemie - 6;
                break;

            case 7:
                multiplicateur_e = 0.5;
                celerite_e = celerite_e / 2;
                e_ralenti = 2;
                break;
            case 8:

                lecture(276);
                printf("nom joueur\n");
                lecture(277);
                printf("%d \n", joueur.PV_classe);
                lecture(278);
                printf("%d \n", celerite_j);
                lecture(279);
                printf("%d \n", defense_j);
                lecture(280);
                printf("%d \n", joueur.ATK_classe);
                lecture(281);
                switch (type.ID_Enemie)
                {
                case 1:
                    printf("araignée\n");
                    break;
                case 2:
                    printf("squelette\n");
                    break;
                case 3:
                    printf("slime\n");
                    break;

                default:
                    break;
                }
                lecture(282);
                printf("%d \n", type.PV_Enemie);
                lecture(283);
                printf("%d \n", celerite_e);
                lecture(284);
                printf("%d \n", type.ATK_Enemie);
                lecture(285);

                break;
            default:
                lecture(319);
                break;
            }
            sleep(4);

            /*========================end turn verification===============================================*/

            if (j_invisible - 1 == 0)
            {
                celerite_j = celerite_j / 2;
            }
            if (j_ralenti - 1 == 0)
            {
                celerite_j = celerite_j * 2;
            }
            if (e_ralenti - 1 == 0)
            {
                celerite_e = celerite_e * 2;
            }
            if (j_renforcer - 1 == 0)
            {
                defense_j = defense_j / 2;
            }
            if (e_invisible - 1 == 0)
            {
                celerite_e = celerite_e / 2;
            }
            if (j_empoisone > 0)
            {
                lecture(78);
                joueur.PV_classe = joueur.PV_classe - 2;
            }
            if (j_enflammer > 0)
            {
                lecture(90);
                joueur.PV_classe = joueur.PV_classe - 3;
            }

            /* compteur de tour */

            if (j_invisible != 0)
            {
                j_invisible = j_invisible - 1;
            }

            if (j_renforcer != 0)
            {
                j_renforcer = j_renforcer - 1;
            }
            if (e_ralenti != 0)
            {
                e_ralenti = e_ralenti - 1;
            }
            
            if (j_ralenti != 0)
            {
                j_ralenti = j_ralenti - 1;
            }
            
            if (j_empoisone != 0)
            {
                j_empoisone = j_empoisone - 1;
            }

            if (j_enflammer != 0)
            {
                j_enflammer = j_enflammer - 1;
            }

            if (e_invisible != 0)
            {
                e_invisible = e_invisible - 1;
            }
            if (J_danger != 0)
            {
                J_danger = J_danger - 1;
            }

            /*affichage PV*/
            for (i = 271; i < 275; i++)
            {
                lecture(i);
                if (i == 272)
                {
                    printf("%d\n", joueur.PV_classe);
                }
                else if (i == 273)
                {
                    printf("%d\n", type.PV_Enemie);
                }
            }
            sleep(4);

            resultat = 0;

        } while (type.PV_Enemie > 0 && joueur.PV_classe > 0);
    

    if (type.PV_Enemie <= 0)
    {
        printf("monstre vaincu\n");
        return (1);
    }
    else
    {
        printf("joueur vaincue\n");
        sleep(10);
        exit(1);
    }
}

/*======================================================*/

// Look and provide the player's position




int Trap(classe classe_joueur, Enemie araignee, Enemie squelette, Enemie slime,Enemie dragon){
        if(lancer(15) == 1){
                lecture(362);
                chooseDirection(classe_joueur, araignee, squelette, slime, dragon);
        }
        else{
                lecture(363);
                ecriture(12,'1');
                chooseDirection(classe_joueur, araignee, squelette, slime, dragon);
        }
}


void SaveInv()
{
    Inventory inv;
    inv.HastePot = 1;
    inv.HealtPot = 4;
    inv.Invisibility = 5;
    inv.Key = 1;
    inv.MonsterCostume = 0;
    inv.Resistance = 1;
    char charValue = inv.Gold + '0';
    ecriture(7, charValue);
    charValue = inv.HealtPot + '0';
    ecriture(9, charValue);
    charValue = inv.HastePot + '0';
    ecriture(11, charValue);
    charValue = inv.Resistance + '0';
    ecriture(13, charValue);
    charValue = inv.Invisibility + '0';
    ecriture(15, charValue);
    charValue = inv.Key + '0';
    ecriture(17, charValue);
    charValue = inv.MonsterCostume + '0';
    ecriture(19, charValue);
}

void ExtractInv()
{
    Inventory inv;
    inv.Gold = Position(7) - '0';
    inv.HealtPot = Position(9) - '0';
    inv.HastePot = Position(11) - '0';
    inv.Resistance = Position(13) - '0';
    inv.Invisibility = Position(15) - '0';
    inv.Key = Position(17) - '0';
    inv.MonsterCostume = Position(19) - '0';
}

// provide the player a chose to let him choose were to go next also as a description of the room
void chooseDirection(classe joueur, Enemie araignee, Enemie squelette, Enemie slime, Enemie dragon)
{
    char resultat = Position(3);
    int choixJoueur,
        action;

    if (resultat == 'H')
    {

        lecture(344); //------
        lecture(346); // your are in the Hall
        lecture(345); // What do you want
        printf("1-");
        lecture(347); // map
        printf("2-");
        lecture(349); // right
        printf("3-");
        lecture(348); // left
        printf("4-");
        lecture(350); // straight
        lecture(344);

        scanf("%d", &action);

        switch (action)
        {
        case 1:
            afficheMap(joueur, araignee, squelette, slime, dragon);
            break;
        case 2:
            if (Position(6) == '0')
            {
                lecture(354);
            }
            else
            {
                lecture(355);
                sleep(1);
                ecriture(3, 'D');
            }
            chooseDirection(joueur, araignee, squelette, slime, dragon);
            break;

        case 3:

            ecriture(3, 'C');
            chooseDirection(joueur, araignee, squelette, slime, dragon);
            break;
        case 4:
            ecriture(3, 'L');
            chooseDirection(joueur, araignee, squelette, slime, dragon);
            break;
        default:
            break;
        }
    }
    else if (resultat == 'C')
    {
        lecture(344);
        if (Position(8) == '0')
        {
            ecriture(8,combat(1, squelette, joueur));
        }
        if (Position(8) != '0' && Position(9) != '0' && Position(10) != '0')
        {
            lecture(293);//clef trouver
            ecriture(5, '1');
        }
        
        lecture(344);
        lecture(356);
        lecture(345);
        printf("1-");
        lecture(347);
        printf("2-");
        lecture(352);
        lecture(344);
        scanf("%d", &action);

        switch (action)
        {
        case 1:
            afficheMap(joueur, araignee, squelette, slime, dragon);
            break;
        case 2:
            ecriture(3, 'H');
            chooseDirection(joueur, araignee, squelette, slime, dragon);
        default:
            break;
        }
    }
     else if (resultat == 'M')
    {
        lecture(344);
        if (Position(9) == '0')
        {
            ecriture(9,combat(1, araignee, joueur));
        }
        if (Position(8) != '0' && Position(9) != '0' && Position(10) != '0')
        {
            lecture(293); //clef trouver
            ecriture(5, '1');
        }
        lecture(344);
        lecture(357);
        lecture(345);
        printf("1-");
        lecture(347);
        printf("2-");
        lecture(353);
        lecture(344);
        scanf("%d", &action);

        switch (action)
        {
        case 1:
            afficheMap(joueur, araignee, squelette, slime, dragon);
            break;
        case 2:
            ecriture(3, 'L');
            chooseDirection(joueur, araignee, squelette, slime, dragon);
        default:
            break;
        }
    }
     else if (resultat == 'V')
    {
        lecture(344);
        if (Position(10) == '0')
        {
            ecriture(10,combat(1, slime, joueur));
        }
        if (Position(8) != '0' && Position(9) != '0' && Position(10) != '0')
        {
            lecture(293); //clef trouver
            ecriture(5, '1');
        }
        lecture(344);
        lecture(356);
        lecture(345);
        printf("1-");
        lecture(347);
        printf("2-");
        lecture(353);
        lecture(344);
        scanf("%d", &action);

        switch (action)
        {
        case 1:
            afficheMap(joueur, araignee, squelette, slime, dragon);
            break;
        case 2:
            ecriture(3, 'L');
            chooseDirection(joueur, araignee, squelette, slime, dragon);
        default:
            break;
        }
    }
    else if (resultat == 'L')
    {
        lecture(344);
        lecture(356);
        lecture(345);
        printf("1-");
        lecture(347);
        printf("2-");
        lecture(352);
        printf("3-");
        lecture(349);
        printf("4-");
        lecture(348);
        printf("5-");
        lecture(350);
        lecture(344);
        scanf("%d", &action);

        switch (action)
        {
        case 1:
            afficheMap(joueur, araignee, squelette, slime, dragon);
            break;
        case 2:
            ecriture(3, 'H');
            chooseDirection(joueur, araignee, squelette, slime, dragon);
        case 3:
            ecriture(3, 'P');
            Trap(joueur, araignee, squelette, slime, dragon);
            chooseDirection(joueur, araignee, squelette, slime, dragon);
        case 4:
            ecriture(3, 'V');
            chooseDirection(joueur, araignee, squelette, slime, dragon);
        case 5:
            ecriture(3, 'M');
            chooseDirection(joueur, araignee, squelette, slime, dragon);
        default:
            break;
        }
    }
    else if (resultat == 'D')
    {
        combat(1,dragon,joueur);
        printf("fin");
        // spawn boss
    }
    else if (resultat == 'P')
    {
        lecture(344);
        lecture(344);
        lecture(345);
        printf("1-");
        lecture(347);
        printf("2-");
        lecture(353);
        lecture(344);
        scanf("%d", &action);

        switch (action)
        {
        case 1:
            afficheMap(joueur, araignee, squelette, slime, dragon);
            break;
        case 2:
            ecriture(3, 'L');
            chooseDirection(joueur, araignee, squelette, slime, dragon);
        default:
            break;
        }
    }
}

// Display the map
void afficheMap(classe joueur, Enemie araignee, Enemie squelette, Enemie slime, Enemie dragon)
{
    for (int i = 366; i <= 392; i++)
    {
        lecture(i);
    }
    printf("\n");
    sleep(3);

    chooseDirection(joueur, araignee, squelette, slime, dragon);
}

// choose langue
void choix_langue()
{
    char choix;
    int loop = 2;
    ecriture(3, 'H');
    while (loop == 2)
    {
        // Affichage de "Francais (1)" en bleu
        printf("\033[1;34m"); // Bleu
        printf("Francais (1)");
        printf("\033[0m \t"); // Réinitialiser la couleur

        // Affichage de "English (2)" en vert
        printf("\033[1;32m"); // Vert
        printf("English (2)");
        printf("\033[0m \n"); // Réinitialiser la couleur
        scanf(" %c", &choix);
        strcpy(Lfile, "");
        if (choix == '1')
        {
            strcpy(Lfile, "Francais.txt");
            ecriture(1, 'F');
            loop = 0;
        }
        else if (choix == '2')
        {
            strcpy(Lfile, "English.txt");
            ecriture(1, 'E');
            loop = 1;
        }
    }
}

void SaveClass(classe *classe_joueur, Enemie araignee, Enemie squelette, Enemie slime)
{
    FILE *file = fopen("SaveGame.txt", "r");
    char class = Position(2);
    switch (class)
    {
    case 'B':
        *classe_joueur = choix_classes(1);
        break;
    case 'M':
        choix_classes(2);
        break;
    case 'P':
        choix_classes(3);
        break;
    case 'V':
        choix_classes(4);
        break;
    default:
        break;
    }
}

// start game
void Start(classe classe_joueur, Enemie araignee, Enemie squelette, Enemie slime, Enemie dragon, Inventory inv)
{

    char charValue = inv.Gold + '0';
    FILE *file = fopen("SaveGame.txt", "r");
    int c = Position(1);
    int choose;
    int validCharacterFound = 0; // Flag to indicate if a valid character is found in the file

    printf("\033[1;33m"); // Activate yellow and bold text
    printf("*****************************\n");
    printf("*      Dungeon Rescuer      *\n");
    printf("*****************************\n");
    printf("\033[0m"); // Reset color and bold

    SaveClass(&classe_joueur, araignee, squelette, slime);

    while ((c = fgetc(file)))
    {
        switch (c)
        {
        case 'F':
            strcpy(Lfile, "Francais.txt");
            validCharacterFound = 1;
            break;
        case 'E':
            strcpy(Lfile, "English.txt");
            validCharacterFound = 1;
            break;
        default:
            choix_langue();
            break;
        }
        if (validCharacterFound == 1)
        {
            if (strcmp(Lfile, "Francais.txt") == 0)
            {
                for (int i = 338; i <= 340; i++)
                {
                    lecture(i);
                    printf("\n");
                }
            }
            else if (strcmp(Lfile, "English.txt") == 0)
            {
                for (int i = 338; i <= 340; i++)
                {
                    lecture(i);
                    printf("\n");
                }
            }
            break;
        }
    }
    if (!validCharacterFound)
    {
        choix_langue();
    }
    else
    {
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            chooseDirection(classe_joueur, araignee, squelette, slime, dragon);
            break;
        case 2:
            choix_langue();

            lecture(3);
            FILE *file = fopen("SaveGame.txt", "r+");
            if (file == NULL)
            {
                printf("Erreur lors de l'ouverture du fichier.\n");
            }

            // Lire le contenu du fichier ligne par ligne
            char Nom_j[100];
            long int position = 0; // Pour stocker la position du curseur de fichier

            for (int i = 1; i <= 4; ++i)
            {
                position = ftell(file); // Enregistrer la position actuelle du curseur

                if (fgets(Nom_j, sizeof(Nom_j), file) == NULL)
                {
                    printf("Erreur lors de la lecture du fichier.\n");
                    fclose(file);
                }

                if (i == 4)
                {
                    scanf("%s", Nom_j); // Lire la nouvelle valeur
                    fseek(file, position, SEEK_SET);
                    fprintf(file, "");
                    fprintf(file, "%s\n", Nom_j);

                    fseek(file, 0, SEEK_END);
                }
            }

            fclose(file);

            lecture(5);
            scanf("%d", &choose);
            classe_joueur = choix_classes(choose);
            reset_sav();
            chooseDirection(classe_joueur, araignee, squelette, slime, dragon);
            break;
        default:
            break;
        }
    }
}

int reset_sav(){
    ecriture(6,'0');
    ecriture(8,'0');
    ecriture(9,'0');
    ecriture(10,'0');
    ecriture(12, '0');
}

// main
int main(int argc, char *argv[])
{
    Enemie araignee, squelette, slime, dragon;
    classe classe_joueur;
    Inventory inv;
    squelette = setup_Enemie(1);
    araignee = setup_Enemie(2);
    slime = setup_Enemie(3);
    dragon = setup_Enemie(4);
    verif_fichier();
    Start(classe_joueur, araignee, squelette, slime, dragon, inv);
}
