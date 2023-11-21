/*autor : Clement Christmas
          Arnoult Antoine*/
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

int nbMobs,room,langue;

//declaration of the Enemie structure
typedef struct 
{
        int ID_Enemie;
        int PV_Enemie;
        int PVmax_Enemie;
        int ATK_Enemie;
        int Celerite_Enemie;
}Enemie;
//declaration of the classe structure
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
//read a specifique line of the TXT file 
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
//insert statistique of a class into the player variable 
classe choix_classes(int ID_classe){
switch (ID_classe)
{
case 1 : 
        classe Barbare  ; 
                Barbare.ID_classe = 1;
                Barbare.Celerite_classe = 3;
                Barbare.DEF_classe = 2;
                Barbare.ATK_classe = 3;
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

//insert statistique of each Enemie into they respective variable
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
        lecture(321);
        break;
}
              
}

// Check if the files are available
void verif_fichier()
{
        // open the file
        FILE *in_file = fopen(PlayerInfo, "r");
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
        // sauvegarde info joueur
        if (in_file == NULL)
        {
                printf("ERROR: file missing : info_player !\n");
        }
}

/*=========================combats=====================*/

//roll a dice to see if the action is a success
int lancer(int difficulter){
        int resultat = rand() % des ;
        if (resultat >= difficulter)
        {
                printf("%d",resultat);
                lecture(76);
                return 1;
        }
        else{
                printf("%d",resultat);
                lecture(77);
                return 0;
        }
        
}

//description of each action depending of the class of the player
int tour_j(classe joueur){
        printf("que voulez vous faire ?:\n");
        int choix = 0,
            i=0;
        switch (joueur.ID_classe)
        {
        /*=========Barbar turn==============*/
        case 1:
                for (i = 144; i < 148; i++)
                {
                        lecture(i);
                }
                
                scanf("%d",&choix);
                switch (choix)
                {
                case 1:
                        lecture(149);
                        return 1 ;
                        break;
                case 2:
                        lecture(151);
                        if (lancer(14)==1)
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

                scanf("%d",&choix);
                switch (choix)
                {
                case 1:
                        lecture(189);
                        return 1 ;
                        break;
                case 2:
                        lecture(191);
                        if (lancer(15)==1 )
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
                scanf("%d",&choix);
                switch (choix)
                {
                case 1:
                        lecture(235);
                        return 1 ;
                        break;
                case 2:
                        lecture(237);
                        if (lancer(14)==1)
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
                scanf("%d",&choix);
                switch (choix)
                {
                case 1:
                        lecture(111);
                        return 1 ;
                        break;
                case 2:
                        lecture(113);
                        if (lancer(13)==1)
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

//Enemie choose what he do depending on player stats
int tour_e(Enemie type,classe joueur,int j_attaquable,int j_ralenti,int j_empoisoné){
       switch (type.ID_Enemie)
       {
        case 1: /*=====================skeleton=========================*/
                if (joueur.PV_classe - type.ATK_Enemie <= 0 && j_attaquable == 0 )
                {
                        lecture(62);
                        
                        return 1; //attaque basic
                }
                else if (type.PV_Enemie <= type.PV_Enemie/3 && rand()% des >= 18 )
                {       lecture(61);
                        return 4; //soin special squelette
                }
                else if (joueur.Celerite_classe/2 <= type.Celerite_Enemie/2 && j_ralenti == 0 && rand()% des >= 14)
                {       lecture(63);                                                          
                        return 5; //attaque special squelette
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
                if (joueur.PV_classe - type.ATK_Enemie <= 0 && j_attaquable == 0 )
                {
                        lecture(64);

                        return 1; //attaque basic
                }
                else if (type.PV_Enemie <= type.PV_Enemie/3 && rand()% des >= 15 && j_attaquable == 0 && j_ralenti == 0&& joueur.Celerite_classe/2 <= type.Celerite_Enemie/2)
                {
                        lecture(66);
                        
                        return 3; //attaque special araignee      
                }
                else if (rand()% des >= 17 && j_attaquable == 0 && j_ralenti == 0 && joueur.Celerite_classe/2 <= type.Celerite_Enemie/2)
                {
                        lecture(66);
                        return 3; //attaque special araignee
                }
                else if (j_attaquable == 0)
                {
                        lecture(64);

                        return 1;  //attaque basic
                } 
                else
                {
                        lecture(68);
                        return 0;
                }   
        break;
       case 3:
                if (joueur.PV_classe - type.ATK_Enemie <= 0 && j_attaquable == 0 )
                {
                        lecture(70);
                        
                        return 1; //attaque basic
                }
                else if (type.PV_Enemie <= type.PV_Enemie/2 && rand()% des >= 16)
                {
                        return 6;       
                }
                else if (/*rand()% des >= 17 &&*/ j_empoisoné == 0)
                {
                        lecture(79);
                        return 7;
                }
                
        break;

       
       default:
                lecture(321);
        break;
       } 
}

//describe the healing action of the classe played by the player then return the value of healing
int soin(classe joueur){
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
        else if (joueur.PV_classe>=joueur.PVmax_classe)
        {
                lecture(60);
                return(0);
        }
        
        
        
}
void end_turn(int j_invisible,int defense_j,int celerite_j,int celerite_e,int j_renforcer,int j_ralenti,int j_empoisoné,int e_ralenti,classe *joueur, Enemie *type){
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

        if (j_empoisoné > 0)
        {
                lecture(78);
                joueur->PV_classe = joueur->PV_classe - 2 ;
        }
        

        /* compteur de tour */
                                
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
        
        if (j_empoisoné !=0)
        {
                j_empoisoné = j_empoisoné -1;
        }
}
//one big function for the combat, the one who start the combat depend on the celerity,the combat loop until one of them die 
classe combat(int nbMobs,Enemie type,classe joueur){
        
        
        type.PV_Enemie = type.PVmax_Enemie ;
        int i = 0,
            resultat = 0,
            degats = 0,
            j_invisible = 0,
            defense_j = joueur.DEF_classe,
            celerite_j = joueur.Celerite_classe,
            celerite_e = type.Celerite_Enemie,
            j_renforcer = 0,
            j_ralenti = 0 , 
            j_empoisoné = 0,
            e_ralenti = 0;

        float multiplicateur_e = 1,
              multiplicateur_j =1;
            

        lecture(72);
        if (celerite_e>celerite_j)
        {
                do{
                       
                        
                        if (celerite_e/2 >= celerite_j)
                        {
                        /*========================advantage monster========================================*/
                                lecture(47);
                                resultat = tour_e(type,joueur,j_invisible,j_ralenti,j_empoisoné);
                                switch (resultat)
                                {
                                case 1:
                                        degats = type.ATK_Enemie * multiplicateur_e;
                                        degats =  degats - defense_j ;
                                        if (degats < 0)
                                        {
                                                degats = 0;
                                        }
                                        
                                        joueur.PV_classe = joueur.PV_classe-degats;
                                        lecture(43);
                                        printf("%d",degats);
                                        lecture(45);
                                        multiplicateur_e = 1;
                                        break;
                                case 3:
                                        j_ralenti = 3 ;
                                        celerite_j = celerite_j / 2 ;

                                        break;
                                case 4:
                                        type.PV_Enemie = type.PV_Enemie + 7;
                                        break;
                                case 5:
                                        j_ralenti = 2;
                                        joueur.PV_classe = joueur.PV_classe - 2;
                                        break;
                                default:
                                        lecture(319);
                                        break;
                                }
                                sleep(4);
                                
                                
                                
                        }
                        else if (celerite_j/2 >= celerite_e)
                        {
                               
                        /*======================advantage player====================================*/ 
                                lecture(49);                       
                                resultat = tour_j(joueur);
                                switch (resultat)
                                {
                                case 1:
                                        degats =joueur.ATK_classe * multiplicateur_j ;
                                        if (degats < 0)
                                        {
                                                degats = 0;
                                        }
                                        type.PV_Enemie=type.PV_Enemie- degats;
                                        lecture(41);
                                        printf("%d",degats);
                                        lecture(45);
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
                                case 8 :
                                                
                                                lecture(276);
                                                printf("nom joueur\n");
                                                lecture(277);
                                                printf("%d \n",joueur.PV_classe);
                                                lecture(278);
                                                printf("%d \n",celerite_j);
                                                lecture(279);
                                                printf("%d \n",defense_j);
                                                lecture(280);
                                                printf("%d \n",joueur.ATK_classe);
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
                                                printf("%d \n",type.PV_Enemie);
                                                lecture(283);
                                                printf("%d \n",celerite_e);
                                                lecture(284);
                                                printf("%d \n",type.ATK_Enemie);
                                                lecture(285);

                                                break;
                                        
                                
                                default:
                                        lecture(319);
                                        break;
                                }
                                sleep(4);
                                
                                
                                
                        }
                        
                        
                /*========================Monster Turn========================================*/
                        resultat = tour_e(type,joueur,j_invisible,j_ralenti,j_empoisoné);
                                switch (resultat)
                                {
                                case 1:
                                        degats = (type.ATK_Enemie * multiplicateur_e)-defense_j;
                                        if (degats < 0)
                                        {
                                                degats = 0;
                                        }
                                        joueur.PV_classe = joueur.PV_classe-degats;
                                        lecture(43);
                                        printf("%d",degats);
                                        lecture(45);
                                        break;
                                case 3:
                                        j_ralenti = 3;
                                        celerite_j = celerite_j / 2 ;

                                        break;
                                case 4:
                                        type.PV_Enemie = type.PV_Enemie + 7;
                                        break;
                                case 5:
                                        j_ralenti = 2;
                                        joueur.PV_classe = joueur.PV_classe - 2;
                                        break;
                                case 6:
                                        j_empoisoné = 5;
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
                                        degats =joueur.ATK_classe * multiplicateur_j ;
                                        if (degats < 0)
                                        {
                                                degats = 0;
                                        }
                                        type.PV_Enemie=type.PV_Enemie- degats;
                                        lecture(41);
                                        printf("%d",degats);
                                        lecture(45);
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
                                case 8 :
                                                
                                                lecture(276);
                                                printf("nom joueur\n");
                                                lecture(277);
                                                printf("%d \n",joueur.PV_classe);
                                                lecture(278);
                                                printf("%d \n",celerite_j);
                                                lecture(279);
                                                printf("%d \n",defense_j);
                                                lecture(280);
                                                printf("%d \n",joueur.ATK_classe);
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
                                                printf("%d \n",type.PV_Enemie);
                                                lecture(283);
                                                printf("%d \n",celerite_e);
                                                lecture(284);
                                                printf("%d \n",type.ATK_Enemie);
                                                lecture(285);

                                                break;
                                default:
                                        lecture(319);
                                        break;
                                }
                                sleep(4);
                                
                                
                                
                /*========================end turn verification===============================================*/
                        
                                end_turn(j_invisible,defense_j,celerite_j,celerite_e,j_renforcer,j_ralenti,j_empoisoné,e_ralenti,&joueur,&type);

                                for (i = 271; i < 275; i++)
                                {
                                        lecture(i);
                                        if (i ==272  )
                                        {
                                               printf("%d\n",joueur.PV_classe);
                                        }
                                        else if (i == 273 )
                                        {
                                               printf("%d\n",type.PV_Enemie);
                                        }
                                        
                                }
                                sleep(4);
                                
                                

                                resultat=0;

                                
                        
                        
                        

                }while (type.PV_Enemie>0 && joueur.PV_classe>0);
                  
        }
        else if (type.Celerite_Enemie<=joueur.Celerite_classe)
        {
                do{
                        if (celerite_e/2 >= celerite_j)
                        {
                        /*======================advantage player====================================*/ 
                                lecture(49);                       
                                resultat = tour_j(joueur);
                                switch (resultat)
                                {
                                case 1:
                                        degats =joueur.ATK_classe * multiplicateur_j ;
                                        if (degats < 0)
                                        {
                                                degats = 0;
                                        }
                                        type.PV_Enemie=type.PV_Enemie- degats;
                                        lecture(41);
                                        printf("%d",degats);
                                        lecture(45);
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
                                case 8 :
                                                
                                                lecture(276);
                                                printf("nom joueur\n");
                                                lecture(277);
                                                printf("%d \n",joueur.PV_classe);
                                                lecture(278);
                                                printf("%d \n",celerite_j);
                                                lecture(279);
                                                printf("%d \n",defense_j);
                                                lecture(280);
                                                printf("%d \n",joueur.ATK_classe);
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
                                                printf("%d \n",type.PV_Enemie);
                                                lecture(283);
                                                printf("%d \n",celerite_e);
                                                lecture(284);
                                                printf("%d \n",type.ATK_Enemie);
                                                lecture(285);

                                                break;
                                
                                default:
                                        lecture(319);
                                        break;
                                }
                                sleep(4);
                                
                                
                                
                        }
                        else if (celerite_j/2 >= celerite_e)
                        {
                                /*========================advantage monster========================================*/
                                lecture(47);
                                resultat = tour_e(type,joueur,j_invisible,j_ralenti,j_empoisoné);
                                switch (resultat)
                                {
                                case 1:
                                        degats = (type.ATK_Enemie * multiplicateur_e)-defense_j;
                                        if (degats < 0)
                                        {
                                                degats = 0;
                                        }
                                        joueur.PV_classe = joueur.PV_classe-degats;
                                        lecture(43);
                                        printf("%d",degats);
                                        lecture(45);
                                        multiplicateur_e = 1;
                                        break;
                                case 3:
                                        j_ralenti = 3 ;
                                        celerite_j = celerite_j / 2 ;

                                        break;
                                case 4:
                                        type.PV_Enemie = type.PV_Enemie + 7;
                                        break;
                                case 5:
                                        j_ralenti = 2;
                                        joueur.PV_classe = joueur.PV_classe - 2;
                                        break;
                                case 6:
                                        j_empoisoné = 5;
                                        break;
                                default:
                                        lecture(319);
                                        break;
                                }
                                sleep(4);
                                
                                
                                
                        }

                               
                        
                        
                        
                
                        
                        
                        
                        


                /*======================TURN OF THE PLAYER====================================*/                
                        resultat = tour_j(joueur);
                                switch (resultat)
                                {
                                case 1:
                                        degats =joueur.ATK_classe * multiplicateur_j ;
                                        if (degats < 0)
                                        {
                                                degats = 0;
                                        }
                                        type.PV_Enemie=type.PV_Enemie- degats;
                                        lecture(41);
                                        printf("%d",degats);
                                        lecture(45);
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
                                case 8 :
                                                
                                                lecture(276);
                                                printf("nom joueur\n");
                                                lecture(277);
                                                printf("%d \n",joueur.PV_classe);
                                                lecture(278);
                                                printf("%d \n",celerite_j);
                                                lecture(279);
                                                printf("%d \n",defense_j);
                                                lecture(280);
                                                printf("%d \n",joueur.ATK_classe);
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
                                                printf("%d \n",type.PV_Enemie);
                                                lecture(283);
                                                printf("%d \n",celerite_e);
                                                lecture(284);
                                                printf("%d \n",type.ATK_Enemie);
                                                lecture(285);

                                                break;
                                default:
                                        lecture(319);
                                        break;
                                }
                                sleep(4);
                        

                        /*========================Monster Turn========================================*/
                        resultat = tour_e(type,joueur,j_invisible,j_ralenti,j_empoisoné);
                                switch (resultat)
                                {
                                case 1:
                                        degats = (type.ATK_Enemie * multiplicateur_e)-defense_j;
                                        if (degats < 0)
                                        {
                                                degats = 0;
                                        }
                                        joueur.PV_classe = joueur.PV_classe-degats;
                                        lecture(43);
                                        printf("%d",degats);
                                        lecture(45);
                                        break;
                                case 3:
                                        j_ralenti = 3;
                                        celerite_j = celerite_j / 2 ;

                                        break;
                                case 4:
                                        type.PV_Enemie = type.PV_Enemie + 7;
                                        break;
                                case 5:
                                        j_ralenti = 2;
                                        joueur.PV_classe = joueur.PV_classe - 2;
                                        break; 
                                case 6:
                                        j_empoisoné = 5;
                                        break;
                                default:
                                        lecture(319);
                                        break;
                                }
                                sleep(4);
                        
                                
                                
                /*========================end turn verification===============================================*/
                        
                                end_turn(j_invisible,defense_j,celerite_j,celerite_e,j_renforcer,j_ralenti,j_empoisoné,e_ralenti,&joueur,&type);

                                for (i = 271; i < 275; i++)
                                {
                                        lecture(i);
                                        if (i == 272  )
                                        {
                                               printf("%d\n",joueur.PV_classe);
                                        }
                                        else if (i == 273 )
                                        {
                                               printf("%d\n",type.PV_Enemie);
                                        }
                                        
                                }
                                sleep(4);
                                

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
        printf("fin de la demo merci d'avoir jouer");
        printf("end of the demo thank for playing ");
        sleep(10);
        exit(1);
        
        

        
}

/*======================================================*/


// Look and provide the player's position
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
        if(currentLine == line){
        return currentChar;
        }
    }
    else
    {
        printf("Unable to open the file.\n");
        return '\0';
    }
}

//provide the player a chose to let him choose were to go next also as a description of the room
void chooseDirection(classe joueur,Enemie araignee,Enemie squelette,Enemie slime)
{
        FILE *file = fopen("SaveGame.txt", "r");
        
        char resultat = Position(3);
        int choixJoueur;
        int action;
while((resultat = fgetc(file)))
{
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

                        ecriture(1,'C');
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
                        ecriture(1,'H');
                        chooseDirection(joueur,araignee,squelette,slime);
                default:
                        break;
                }
        }
}
        
}

// Display the map
void afficheMap(classe joueur,Enemie araignee,Enemie squelette,Enemie slime)
{
        char texte;
        if (strcmp(Lfile, "Histoire.txt") == 0)
        {
                for (int i = 357; i <= 364; i++)
                {
                        lecture(i);
                }
                printf("\n");
                sleep(3);
        }
        chooseDirection(joueur,araignee,squelette,slime);
}

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
                        strcpy(Lfile, "Histoire.txt");
                        FILE *file = fopen(SaveGame, "w");
                        fprintf(file, "F"); // Écrit la chaîne Lfile dans le fichier
                        fclose(file);

                        loop = 0;
                }
                else if (choix == '2')
                {
                        strcpy(Lfile, "Story.txt");
                        FILE *file = fopen(SaveGame, "w");
                        fprintf(file, "E"); // Écrit la chaîne Lfile dans le fichier
                        fclose(file);
                        loop = 1;
                }
        }
        lecture(1);
        fclose(language);
}

void SaveClass(classe *classe_joueur,Enemie araignee ,Enemie squelette,Enemie slime){
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
                case 'P' :
                        choix_classes(3);
                        break;
                case 'V' : 
                        choix_classes(4);
                        break;
                default:
                        break;
                }

}

// start game
void Start(classe classe_joueur,Enemie araignee ,Enemie squelette,Enemie slime)
{
        FILE *file = fopen("SaveGame.txt", "r");
        int c = Position(1);
        int choose;
        int validCharacterFound = 0; //Flag to indicate if a valid character is found in the file

        printf("\033[1;33m"); // Activate yellow and bold text
        printf("*****************************\n");
        printf("*      Dungeon Rescuer      *\n");
        printf("*****************************\n");
        printf("\033[0m"); // Reset color and bold

        SaveClass(&classe_joueur,araignee,squelette,slime);


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

//main
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
