/*autor : Clement Christmas
          Arnoult Antoine*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ctype.h>

const char *SaveGame = "SaveGame.txt";
const char *PlayerInfo = "PlayerInfo.txt";
const char *Francais = "Francais.txt";
const char *English = "English.txt";
const char *Carte = "Carte.txt";
const char *Map = "Map.txt";
char *language;
const int des = 21;

char Lfile[200];


char Nom_j[20];

int nbMobs,room,langue;


typedef struct 
{
        int ID_Enemie;
        int PV_Enemie;
        int PVmax_Enemie;
        int ATK_Enemie;
        int Celerite_Enemie;
}Enemie;

typedef struct 
{
        int ID_classe;
        int PV_classe;
        int PVmax_classe;
        int DEF_classe;
        int ATK_classe;
        int Celerite_classe;
        int Mana_classe; 
}classe;

void lecture(int line)
{
        FILE *file = fopen(Lfile, "r");

        if (file != NULL)
        {
                int currentLine = 1;
                int currentChar1;

                while (currentLine < line)
                {
                        currentChar1 = fgetc(file);

                        if (currentChar1 == '\n')
                        {
                                currentLine++;
                        }
                }

                do
                {
                        currentChar1 = fgetc(file);
                        printf("%c", currentChar1);
                } while (currentChar1 != '\n' && currentChar1 != EOF);

                fclose(file);
        }
        else
        {
                printf("\n");
        }
        return; 
}

classe choix_classes(int ID_classe){
switch (ID_classe)
{                        

case 1 :
        classe Barbare  ; 
                Barbare.ID_classe = 1;
                Barbare.Celerite_classe = 3;
                Barbare.DEF_classe = 2;
                Barbare.ATK_classe = 4;
                Barbare.PV_classe = 60;
                Barbare.PVmax_classe = 60;
                Barbare.Mana_classe = 0;
                return(Barbare);
        break;
        
case 2:

        classe Mage ;
                Mage.ID_classe = 2;
                Mage.Celerite_classe = 4;
                Mage.DEF_classe = 1;
                Mage.ATK_classe =2;
                Mage.PV_classe = 40;
                Mage.PVmax_classe = 40;
                Mage.Mana_classe = 100;
                return(Mage);

        break;

case 3 :
        
        classe Paladin ;
                Paladin.ID_classe = 3;
                Paladin.Celerite_classe=2;
                Paladin.DEF_classe=2;
                Paladin.ATK_classe=3;
                Paladin.PV_classe= 50;
                Paladin.PVmax_classe= 50;
                Paladin.Mana_classe = 50;
                return(Paladin);
        break;

case 4 :
        classe Voleur ;
                Voleur.ID_classe = 4;
                Voleur.Celerite_classe=6;
                Voleur.DEF_classe=1;
                Voleur.ATK_classe=2;
                Voleur.PV_classe= 50;
                Voleur.PVmax_classe= 50;
                Voleur.Mana_classe = 30;
                return(Voleur);
        break;
default: 
        printf("erreur ID Classe");
        break;
}
              
}
// Check if the files are available

Enemie setup_Enemie(int ID_Enemie){
switch (ID_Enemie)
{
case 1 :
        Enemie squelette ; 
                squelette.ID_Enemie = 1;
                squelette.Celerite_Enemie = 5;
                squelette.ATK_Enemie = 3;
                squelette.PV_Enemie = 50;
                squelette.PVmax_Enemie = 50;
                return(squelette);
        break;
case 2:
        Enemie araignee ;
                araignee.ID_Enemie = 2;
                araignee.Celerite_Enemie = 7;
                araignee.ATK_Enemie = 4;
                araignee.PV_Enemie = 60;
                araignee.PVmax_Enemie = 60;
                return(araignee);

        break;

case 3 :
        Enemie slime;
                slime.ID_Enemie = 3;
                slime.Celerite_Enemie=2;
                slime.ATK_Enemie=1;
                slime.PV_Enemie= 80;
                slime.PVmax_Enemie= 80;
                return(slime);
        break;
default: 
        lecture(34);
        break;
}
              
}


void verif_fichier()
{
        // open the file
        FILE *in_file = fopen(PlayerInfo, "r");
        FILE *in_save = fopen(SaveGame, "r");
        FILE *in_histoire = fopen(Francais, "r");
        FILE *in_story = fopen(English, "r");
        FILE *in_carte = fopen(Carte, "r");
        FILE *in_map = fopen(Map, "r");

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
        // sauvegarde info joueur
        if (in_file == NULL)
        {
                printf("ERROR: file missing : info_player !\n");
        }
}

/*=========================combats=====================*/
int lancer(int difficulter){
        int resultat = rand() % des ;
        if (resultat >= difficulter)
        {
                printf("%d",resultat);
                lecture(49);
                return 1;
        }
        else{
                printf("%d",resultat);
                lecture(50);
                return 0;
        }
        
}


int tour_j(classe joueur){
        printf("que voulez vous faire ?:\n");
        int choix = 0,
            i=0;
        switch (joueur.ID_classe)
        {
        /*=========Barbar turn==============*/
        case 1:
                for (i = 72; i < 76; i++)
                {
                        lecture(i);
                }
                
                scanf("%d",&choix);
                switch (choix)
                {
                case 1:
                        lecture(77);
                        return 1 ;
                        break;
                case 2:
                        lecture(79);
                        if (lancer(14)==1)
                        {
                                lecture(81);
                                return 5;
                        }
                        else
                        {
                                lecture(83);
                                return 0;
                        }
                        
                        
                        break;
                case 3:
                        lecture(85);
                        return 2;
                        break;
                case 4:
                        lecture(87);
                        return 3;
                        break;
                
                default:

                        lecture(155);
                        break;
                }

                break;


        /*=========Mage turn==============*/
        case 2:
                for (i = 91; i < 95; i++)
                {
                        lecture(i);
                }

                scanf("%d",&choix);
                switch (choix)
                {
                case 1:
                        lecture(96);
                        return 1 ;
                        break;
                case 2:
                        lecture(98);
                        if (lancer(15)==1 )
                        {
                                lecture(100);
                                return 6;
                        }
                        else
                        {
                                lecture(102);
                                return 0;
                        }
                        
                        
                        break;
                case 3:
                        lecture(104);
                        return 2;
                        break;
                case 4:
                        lecture(106);
                        return 3;
                        break;
                
                default:

                        lecture(32);
                        break;
                }

        
                
                break;

        /*=========Paladin turn==============*/
        case 3:
                for (i = 111; i < 115; i++)
                {
                        lecture(i);
                }
                scanf("%d",&choix);
                switch (choix)
                {
                case 1:
                        lecture(116);
                        return 1 ;
                        break;
                case 2:
                        lecture(118);
                        if (lancer(14)==1)
                        {
                                lecture(120);
                                return 7;
                        }
                        else
                        {
                                lecture(122);
                                return 0;
                        }
                        
                        
                        break;
                case 3:
                        lecture(124);
                        return 2;
                        break;
                case 4:
                        lecture(126);
                        return 3;
                        break;
                
                default:

                        lecture(32);
                        break;
                }

                break;

        /*=========Thief turn==============*/
        case 4:   
                for (i = 53; i < 57; i++)
                {
                        lecture(i);
                }
                scanf("%d",&choix);
                switch (choix)
                {
                case 1:
                        lecture(58);
                        return 1 ;
                        break;
                case 2:
                        lecture(60);
                        if (lancer(13)==1)
                        {
                                lecture(62);
                                return 4;
                        }
                        else
                        {
                                lecture(64);
                                return 0;
                        }
                        
                        
                        break;
                case 3:
                        lecture(66);
                        return 2;
                        break;
                case 4:
                        lecture(68);
                        return 3;
                        break;
                
                default:
                        lecture(32);
                        break;
                }



                break;
        
        default:
                lecture(32);
                break;
        }
        
}


int tour_e(Enemie type,classe joueur,int j_attaquable,int j_ralenti){
       switch (type.ID_Enemie)
       {
       case 1:
                if (joueur.PV_classe - type.ATK_Enemie <= 0 && j_attaquable == 0 )
                {
                        lecture(35);
                        
                        return 1;
                }
        break;
       case 2:
                if (joueur.PV_classe - type.ATK_Enemie <= 0 && j_attaquable == 0 )
                {
                        lecture(37);

                        return 1;
                }
                else if (type.PV_Enemie <= type.PV_Enemie/3 && rand()% des >= 15 && j_attaquable == 0 && j_ralenti == 0&& joueur.Celerite_classe/2 <= type.Celerite_Enemie/2)
                {
                        lecture(39);
                        
                        return 3;       
                }
                else if (rand()% des >= 17 && j_attaquable == 0 && j_ralenti == 0 && joueur.Celerite_classe/2 <= type.Celerite_Enemie/2)
                {
                        lecture(39);
                        return 3;
                }
                else if (j_attaquable == 0)
                {
                        lecture(37);

                        return 1;  
                }
                else{
                        lecture(41);
                        return 0;
                }      
        break;
       case 3:
                if (joueur.PV_classe - type.ATK_Enemie <= 0 && j_attaquable == 0 )
                {
                        lecture(47);
                        
                        return 1;
                }
        break;

       
       default:
                lecture(32);
        break;
       } 
}

int soin(classe joueur){
        if (joueur.PV_classe < joueur.PVmax_classe)
        {
                switch (joueur.ID_classe)
                {
                case 1:
                        lecture(25);
                        return 1;
                        break;
                case 2:
                        lecture(27);
                        return 7;
                        break;
                case 3:
                        lecture(29);
                        return 6;
                        break;
                case 4:
                        lecture(31);
                        return 4;
                        break;
        
                default:
                        break;
                }
        }
        else if (joueur.PV_classe>=joueur.PVmax_classe)
        {
                lecture(33);
                return(0);
        }
        
        
        
}

classe combat(int nbMobs,Enemie type,classe joueur){
        

        lecture(37);
        type.PV_Enemie = type.PVmax_Enemie ;
        int i = 0,
            resultat = 0,
            j_invisible = 0,
            degats = 0,
            defense_j = joueur.DEF_classe,
            celerite_j = joueur.Celerite_classe,
            celerite_e = type.Celerite_Enemie,
            j_renforcer = 0,
            j_ralenti = 0 , 
            e_ralenti = 0;

        float multiplicateur_e = 1,
              multiplicateur_j =1;
            


        if (celerite_e>celerite_j)
        {
                do{
                        if (celerite_e/2 >= celerite_j)
                        {
                        /*========================advantage monster========================================*/
                                lecture(20);
                                resultat = tour_e(type,joueur,j_invisible,j_ralenti);
                                switch (resultat)
                                {
                                case 1:
                                        degats = type.ATK_Enemie * multiplicateur_e;
                                        degats =  degats - defense_j ;
                                        joueur.PV_classe = joueur.PV_classe-degats;
                                        lecture(16);
                                        printf("%d",degats);
                                        lecture(18);
                                        multiplicateur_e = 1;
                                        break;
                                case 3:
                                        j_ralenti = 2 ;
                                        celerite_j = celerite_j / 2 ;

                                        break;
                                default:
                                        lecture(40);
                                        break;
                                }
                                sleep(5);  
                        }
                        else if (celerite_j/2 >= celerite_e)
                        {
                               
                        /*======================advantage player====================================*/ 
                                lecture(22);                       
                                resultat = tour_j(joueur);
                                switch (resultat)
                                {
                                case 1:
                                        degats =joueur.ATK_classe * multiplicateur_j ;
                                        type.PV_Enemie=type.PV_Enemie- degats;
                                        lecture(14);
                                        printf("%d",degats);
                                        lecture(18);
                                        multiplicateur_j = 1;
                                        
                                        break;

                                case 2:
                                        joueur.PV_classe = joueur.PV_classe + soin(joueur);
                                        break;

                                case 3:
                                        defense_j = defense_j * 2;
                                        break;

                                case 4:
                                        j_invisible = 2 ;
                                        multiplicateur_j = 2 ;
                                        celerite_j = celerite_j * 2 ;

                                        break;
                                case 5:
                                        defense_j = defense_j * 2;
                                        j_renforcer = 2;
                                        multiplicateur_j = multiplicateur_j *2;
                                        break;

                                case 6:
                                        type.PV_Enemie=type.PV_Enemie-6;
                                        break;
                                
                                case 7:
                                        multiplicateur_e = 0.5;
                                        celerite_e = celerite_e /2 ;
                                        e_ralenti = 2;
                                        break;
                                
                                
                                default:
                                        lecture(32);
                                        break;
                                }
                                sleep(5);
                                
                                
                                
                        }
                        
                        
                /*========================Monster Turn========================================*/
                        lecture(45);
                        resultat = tour_e(type,joueur,j_invisible,j_ralenti);
                                switch (resultat)
                                {
                                case 1:
                                        degats = (type.ATK_Enemie * multiplicateur_e)-defense_j;
                                        joueur.PV_classe = joueur.PV_classe-degats;
                                        lecture(16);
                                        printf("%d",degats);
                                        lecture(18);
                                        break;
                                case 3:
                                        j_ralenti = 2;
                                        celerite_j = celerite_j / 2 ;

                                        break;
                                default:
                                        printf("erreur");
                                        break;
                                }
                                sleep(5);
                                
                        
                        
                        
                        


                /*======================TURN OF THE PLAYER====================================*/                
                        resultat = tour_j(joueur);
                                switch (resultat)
                                {
                                case 1:
                                        degats =joueur.ATK_classe * multiplicateur_j ;
                                        type.PV_Enemie=type.PV_Enemie- degats;
                                        lecture(14);
                                        printf("%d",degats);
                                        lecture(18);
                                        multiplicateur_j = 1;
                                        
                                        break;

                                case 2:
                                        joueur.PV_classe = joueur.PV_classe + soin(joueur);
                                        break;

                                case 3:
                                        defense_j = defense_j * 2;
                                        break;

                                case 4:
                                        j_invisible = 2 ;
                                        multiplicateur_j = 2 ;
                                        celerite_j = celerite_j * 2 ;

                                        break;
                                case 5:
                                        defense_j = defense_j * 2;
                                        j_renforcer = 2;
                                        multiplicateur_j = multiplicateur_j *2;
                                        break;

                                case 6:
                                        type.PV_Enemie=type.PV_Enemie-6;
                                        break;
                                
                                case 7:
                                        multiplicateur_e = 0.5;
                                        celerite_e = celerite_e /2 ;
                                        e_ralenti = 2;
                                        break;
                                
                                default:
                                        lecture(32);
                                        break;
                                }
                                sleep(5);
                                
                                
                                
                /*========================end turn verification===============================================*/
                        
                                if (j_invisible - 1 == 0)
                                        {
                                                celerite_j = celerite_j /2 ;
                                                
                                        }

                                if (j_ralenti - 1  == 0)
                                        {
                                                celerite_j = celerite_j * 2;
                                        }
                                if (e_ralenti - 1 == 0)
                                {
                                        celerite_e = celerite_e *2;
                                }
                                if (j_renforcer - 1 == 0)
                                {
                                        defense_j = defense_j/2;
                                }
                                
                                if (j_invisible!=0)
                                {
                                        j_invisible = j_invisible - 1;
                                }

                                if (j_renforcer!=0)
                                {
                                        j_renforcer = j_renforcer -1;
                                }
                                if (e_ralenti!=0)
                                {
                                        e_ralenti= e_ralenti-1;
                                }
                        
                                if (celerite_j != 0)
                                {
                                        celerite_j = celerite_j - 1;
                                }

                                for (i = 129; i < 133; i++)
                                {
                                        lecture(i);
                                        if (i == 130 )
                                        {
                                               printf("%d\n",joueur.PV_classe);
                                        }
                                        else if (i == 131 )
                                        {
                                               printf("%d\n",type.PV_Enemie);
                                        }
                                        
                                }
                                sleep(5);
                                
                                

                                resultat=0;

                                
                        
                        
                        

                }while (type.PV_Enemie>0 && joueur.PV_classe>0);
                  
        }
        else if (type.Celerite_Enemie<=joueur.Celerite_classe)
        {
                do{
                        if (celerite_e/2 >= celerite_j)
                        {
                        /*======================advantage player====================================*/ 
                                lecture(22);                       
                                resultat = tour_j(joueur);
                                switch (resultat)
                                {
                                case 1:
                                        degats =joueur.ATK_classe * multiplicateur_j ;
                                        type.PV_Enemie=type.PV_Enemie- degats;
                                        lecture(14);
                                        printf("%d",degats);
                                        lecture(18);
                                        multiplicateur_j = 1;
                                        
                                        break;

                                case 2:
                                        joueur.PV_classe = joueur.PV_classe + soin(joueur);
                                        break;

                                case 3:
                                        defense_j = defense_j * 2;
                                        break;

                                case 4:
                                        j_invisible = 2 ;
                                        multiplicateur_j = 2 ;
                                        celerite_j = celerite_j * 2 ;

                                        break;
                                case 5:
                                        defense_j = defense_j * 2;
                                        j_renforcer = 2;
                                        multiplicateur_j = multiplicateur_j *2;
                                        break;

                                case 6:
                                        type.PV_Enemie=type.PV_Enemie-6;
                                        break;
                                
                                case 7:
                                        multiplicateur_e = 0.5;
                                        celerite_e = celerite_e /2 ;
                                        e_ralenti = 2;
                                        break;
                                
                                
                                default:
                                        lecture(32);
                                        break;
                                }
                                sleep(5);
                                
                                
                                
                        }
                        else if (celerite_j/2 >= celerite_e)
                        {
                                /*========================advantage monster========================================*/
                                lecture(20);
                                resultat = tour_e(type,joueur,j_invisible,j_ralenti);
                                switch (resultat)
                                {
                                case 1:
                                        degats = (type.ATK_Enemie * multiplicateur_e)-defense_j;
                                        joueur.PV_classe = joueur.PV_classe-degats;
                                        lecture(16);
                                        printf("%d",degats);
                                        lecture(18);
                                        multiplicateur_e = 1;
                                        break;
                                case 3:
                                        j_ralenti = 2 ;
                                        celerite_j = celerite_j / 2 ;

                                        break;
                                default:
                                        lecture(40);
                                        break;
                                }
                                sleep(5);
                                
                                
                                
                        }

                               
                        
                        
                        
                
                        
                        
                        
                        


                /*======================TURN OF THE PLAYER====================================*/                
                        resultat = tour_j(joueur);
                                switch (resultat)
                                {
                                case 1:
                                        degats =joueur.ATK_classe * multiplicateur_j ;
                                        type.PV_Enemie=type.PV_Enemie- degats;
                                        lecture(14);
                                        printf("%d",degats);
                                        lecture(18);
                                        multiplicateur_j = 1;
                                        
                                        break;

                                case 2:
                                        joueur.PV_classe = joueur.PV_classe + soin(joueur);
                                        break;

                                case 3:
                                        defense_j = defense_j * 2;
                                        break;

                                case 4:
                                        j_invisible = 2 ;
                                        multiplicateur_j = 2 ;
                                        celerite_j = celerite_j * 2 ;

                                        break;
                                case 5:
                                        defense_j = defense_j * 2;
                                        j_renforcer = 2;
                                        multiplicateur_j = multiplicateur_j *2;
                                        break;

                                case 6:
                                        type.PV_Enemie=type.PV_Enemie-6;
                                        break;
                                
                                case 7:
                                        multiplicateur_e = 0.5;
                                        celerite_e = celerite_e /2 ;
                                        e_ralenti = 2;
                                        break;
                                
                                default:
                                        lecture(32);
                                        break;
                                }
                                sleep(5);
                        

                        /*========================Monster Turn========================================*/
                        lecture(45);
                        resultat = tour_e(type,joueur,j_invisible,j_ralenti);
                                switch (resultat)
                                {
                                case 1:
                                        degats = (type.ATK_Enemie * multiplicateur_e)-defense_j;
                                        joueur.PV_classe = joueur.PV_classe-degats;
                                        lecture(16);
                                        printf("%d",degats);
                                        lecture(18);
                                        break;
                                case 3:
                                        j_ralenti = 2;
                                        celerite_j = celerite_j / 2 ;

                                        break;
                                default:
                                        printf("erreur");
                                        break;
                                }
                                sleep(5);
                        
                                
                                
                /*========================end turn verification===============================================*/
                        
                                if (j_invisible - 1 == 0)
                                        {
                                                celerite_j = celerite_j /2 ;
                                                
                                        }

                                if (j_ralenti - 1  == 0)
                                        {
                                                celerite_j = celerite_j * 2;
                                        }
                                if (e_ralenti - 1 == 0)
                                {
                                        celerite_e = celerite_e *2;
                                }
                                if (j_renforcer - 1 == 0)
                                {
                                        defense_j = defense_j /2;
                                }
                                
                                if (j_invisible!=0)
                                {
                                        j_invisible = j_invisible - 1;
                                }

                                if (j_renforcer!=0)
                                {
                                        j_renforcer = j_renforcer -1;
                                }
                                if (e_ralenti!=0)
                                {
                                        e_ralenti= e_ralenti-1;
                                }
                        
                                if (celerite_j != 0)
                                {
                                        celerite_j = celerite_j - 1;
                                }
                                for (i = 129; i < 133; i++)
                                {
                                        lecture(i);
                                        if (i == 130 )
                                        {
                                               printf("%d\n",joueur.PV_classe);
                                        }
                                        else if (i == 131 )
                                        {
                                               printf("%d\n",type.PV_Enemie);
                                        }
                                        
                                }
                                sleep(5);
                                

                                resultat=0;
                       
                }while (type.PV_Enemie>0 && joueur.PV_classe>0);
                
        }

        if (type.PV_Enemie<=0)
        {
                printf("monstre vaincu\n");
                return (joueur);
        }
        else 
        {
                printf("joueur vaincue\n");
                return (joueur);
        }
        
        

        
}

/*======================================================*/
// Look and provide the player's position
char Position(int line)
{
    FILE *file = fopen("PlayerInfo.txt", "r");
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
            }
        }

        // Lecture du caractère à la ligne spécifiée
        if (currentLine == line)
        {
            while (currentChar != '\n' && currentChar != EOF)
            {
                currentChar = fgetc(file);
                if (!isspace(currentChar))
                {
                    fclose(file);
                    return currentChar;
                }
            }
        }

        fclose(file);

        return '\0'; // Retourne '\0' si la ligne n'est pas trouvée ou s'il y a une erreur de lecture.
    }
    else
    {
        printf("Unable to open the file.\n");
        return '\0';
    }
}

void chooseDirection(classe joueur,Enemie araignee,Enemie squelette,Enemie slime)
{
        char resultat = Position(1);

        int choixJoueur;
        int action;
        if (resultat == 'H')
        {

                if (strcmp(Lfile, "Francais.txt") == 0)
                {
                        printf("\n---------------------------------\n");
                        printf("Vous etes dans le Hall\n");
                        printf("Que voulez-vous faire ?\n");
                        printf("1- Carte\n");
                        printf("2- Aller à Droite\n");
                        printf("3- Aller à Gauche\n");
                        printf("---------------------------------\n");
                }
                else
                {
                        printf("\n---------------------------------\n");
                        printf("You are in the Hall\n");
                        printf("What do you want to do?\n");
                        printf("1- Map\n");
                        printf("2- Go to right\n");
                        printf("3- Go to left\n");
                        printf("---------------------------------\n");
                }
                scanf("%d", &action);

                switch (action)
                {
                case 1:
                        afficheMap(joueur,araignee,squelette,slime);
                        break;
                case 2:

                        if (strcmp(Lfile, "Francais.txt") == 0)
                        {
                                printf("La porte est fermé\n");
                                chooseDirection(joueur,araignee,squelette,slime);
                        }
                        else
                        {
                                printf("The door is closed\n");
                                chooseDirection(joueur,araignee,squelette,slime);
                        }
                        break;

                case 3:
                        FILE *file = fopen(PlayerInfo, "w");
                        for (int i = 1; i < 5; ++i)
                        {
                                fprintf(file, "");
                        }
                        fprintf(file, "C\n");
                        fclose(file);
                        chooseDirection(joueur,araignee,squelette,slime);
                        break;
                default:
                        break;
                }
        }
        else if (resultat == 'C')
        {
                if (strcmp(Lfile, "Francais.txt") == 0)
                {
                        printf("\n---------------------------------\n");
                        printf("Vous etes dans la Piece 1\n");
                        combat(1,araignee,joueur);
                        printf("\n---------------------------------\n");
                        printf("Vous etes dans la Piece 1\n");
                        printf("Que voulez-vous faire ?\n");
                        printf("1- Carte\n");
                        printf("2- Aller dans le Hall\n");
                        printf("---------------------------------\n");
                }
                else
                {
                        printf("\n---------------------------------\n");
                        printf("You are in Room 1\n");
                        combat(1,araignee,joueur);
                        printf("\n---------------------------------\n");
                        printf("You are in Room 1\n");
                        printf("What do you want to do?\n");
                        printf("1- Map\n");
                        printf("2- Go to the Hall\n");
                        printf("---------------------------------\n");
                }
                scanf("%d", &action);

                switch (action)
                {
                case 1:
                        afficheMap(joueur,araignee,squelette,slime);
                        break;
                case 2:
                        FILE *file = fopen(PlayerInfo, "w");
                        for (int i = 1; i < 5; ++i)
                        {
                                fprintf(file, "");
                        }
                        fprintf(file, "H\n");
                        fclose(file);
                        chooseDirection(joueur,araignee,squelette,slime);
                default:
                        break;
                }
        }
        
}

// Display the map
void afficheMap(classe joueur,Enemie araignee,Enemie squelette,Enemie slime)
{
        char texte;
                for (int i = 153; i <= 160; i++)
                {
                        lecture(i);
                }
                printf("\n");
                sleep(3);
        
        chooseDirection(joueur,araignee,squelette,slime);
}
// Choose where the player should go

// Read the file

// choose langue
void choix_langue()
{
        char choix;
        int loop = 2;
        FILE *Room = fopen(PlayerInfo, "w");
        fprintf(Room,"H");
        fclose(Room);


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
                if (choix == '1')
                {
                        strcpy(Lfile, "Francais.txt");
                        FILE *file = fopen(SaveGame, "w");
                        fprintf(file, "F"); // Écrit la chaîne Lfile dans le fichier
                        fclose(file);

                        loop = 0;
                }
                else if (choix == '2')
                {
                        strcpy(Lfile, "English.txt");
                        FILE *file = fopen(SaveGame, "w");
                        fprintf(file, "E"); // Écrit la chaîne Lfile dans le fichier
                        fclose(file);
                        loop = 1;
                }
        }
        lecture(1);
        fclose(language);
}

// start game
void Start(classe classe_joueur,Enemie araignee ,Enemie squelette,Enemie slime)
{
        FILE *file = fopen("SaveGame.txt", "r");
        int c;
        int choose;
        int validCharacterFound = 0; // Flag to indicate if a valid character is found in the file

        printf("\033[1;33m"); // Activate yellow and bold text
        printf("*****************************\n");
        printf("*      Dungeon Rescuer      *\n");
        printf("*****************************\n");
        printf("\033[0m"); // Reset color and bold

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
                                for (int i = 147; i <= 149; i++)
                                {
                                        lecture(i);
                                        printf("\n");
                                }
                        }
                        else if (strcmp(Lfile, "English.txt") == 0)
                        {
                                for (int i = 147; i <= 149; i++)
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
                        chooseDirection(classe_joueur,araignee,squelette,slime);
                        break;
                case 2:
                        choix_langue();
                        
                        
                        lecture(3);
                        scanf("%s",&Nom_j);


                        lecture(5);
                        scanf("%d",&choose);


                        classe_joueur = choix_classes(choose);
                        chooseDirection(classe_joueur,araignee,squelette,slime);
                        break;
                default:
                        break;
                }
        }

        fclose(file);
}
int main(int argc, char *argv[])
{
        Enemie araignee,squelette,slime ;
        classe classe_joueur ;
        squelette = setup_Enemie(1);
        araignee = setup_Enemie(2);
        slime = setup_Enemie(3);
        verif_fichier();
        Start(classe_joueur ,araignee,squelette,slime);
}
