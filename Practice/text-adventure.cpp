//Inspired from the game witcher 3 - wild hunt
//the user should take as much as Xps (experience points) to have a good ending

#include<iostream>
#include<stdlib.h>
#include<ctime>

typedef struct skills
{
    double Aard = 0;
    double Igni = 0;
    double restoration = 0;
}skill;

typedef struct characters
{
    std::string name;
    double power;
    int health;
    skill abilities; 
}character;

character Geralt;

character Xp(char x){
    Geralt.power += 5;
    Geralt.abilities.restoration += 2; 
    if(x == 'i'){
        Geralt.abilities.Igni += 5;
        std::cout<<"Igni has been developed!!!\n";
    }
    else if(x == 'a'){
        Geralt.abilities.Aard += 5;
        std::cout<<"Aard has been developed!!!\n";
    }
    return Geralt;
}

character monsters(std::string Name){
    character monster;
    monster.name = Name;
    monster.health = 200;
    monster.power = 30;
    return monster;
}

void health_restore(){
    Geralt.health = Geralt.health + Geralt.abilities.restoration;
    if(Geralt.health > 250){
        Geralt.health = 250;
    }
    return;
}

void start(){
    Geralt.name = "Geralt";
    Geralt.health = 100;
    Geralt.abilities.Aard = 1.5;
    Geralt.abilities.Igni = 1.5;
    Geralt.abilities.restoration = 1;
    Geralt.power = 20;
    return;
}
void stats(character x){
    std::cout<<"   "<<x.name<<"\n";
    std::cout<<"=============="<<"\n";
    std::cout<<"Health : "<<x.health<<"\n";
    std::cout<<"Power : "<<x.power<<"\n";
    if(x.abilities.Aard){
        std::cout<<"Aard : "<<x.abilities.Aard<<"\n";
    }
    if(x.abilities.Igni){
        std::cout<<"Igni : "<<x.abilities.Aard<<"\n";
    }
    if(x.abilities.restoration){
        std::cout<<"Restoraton : "<<x.abilities.restoration<<"\n";
    }
    std::cout<<"\n";
    return;
}

character learn_skill(){
    srand(time(NULL));
    int x = rand() % 10 + 1;
    //srand(time(NULL));
    int y = rand() % 10 + 1;
    int ans;
    std::cout<<x<<" x "<<y<<" = ";
    std::cin>>ans;
    if(x*y == ans){
        std::cout<<"Wow... Excellent. Now its time to chose your skill!!!\n";
        int xy;
        std::cout<<"Enter an even number to upgrade Igni or Enter an odd number to upgrade Aard : ";
        std::cin>>xy;
        if(xy % 2){
           Geralt = Xp('a');
        }
        else{
           Geralt = Xp('i');
        }
    }
    return Geralt;
}

character Attack(character x, character y){
    if(x.health<=0){
        return y;
    }
    std::cout<<"\n"<<x.name<<" attacked "<<y.name;
    std::cout<<"\n -"<<x.power<<"\n";
    y.health -= x.power;
    std::cout<<y.name<<" health: "<<y.health<<"\n";
    if(y.health <= 0) std::cout<<y.name<<" is now defeated!!!\n\n";
    return y;
}

character Aard(character y){
    if(Geralt.health<=0){
        return y;
    }
    std::cout<<"\n"<<Geralt.name<<" used Aard on "<<y.name<<"\n";
    std::cout<<"\n -"<<Geralt.power * Geralt.abilities.Aard<<"\n";
    y.health -= Geralt.power * Geralt.abilities.Aard;
    std::cout<<y.name<<" health: "<<y.health<<"\n";
    if(y.health <= 0) std::cout<<y.name<<" is now defeated!!!\n\n";
    return y;
}

character Igni(character y){
    if(Geralt.health<=0){
        return y;
    }
    std::cout<<"\n"<<Geralt.name<<" used Igni on "<<y.name<<"\n";
    std::cout<<"\n -"<<Geralt.power * Geralt.abilities.Igni<<"\n";
    y.health -= Geralt.power * Geralt.abilities.Igni;
    std::cout<<y.name<<" health: "<<y.health<<"\n";
    if(y.health <= 0) std::cout<<y.name<<" is now defeated!!!\n\n";
    return y;
}

int check(){
    //this function checks whether geralt is alive or not
    while(Geralt.health<=0){
        std::cout<<"You died!!!";
        std::cout<<"Press 'x' to exit the game or 's' to restart the game: ";
        char o;
        fflush(stdin);
        std::cin>>o;
        if(o == 'x'){
            std::cout<<"Thank you for playing.\n";
            return 0;
        }
        else if(o == 's'){
            std::cout<<"The game is being restarted...\n";
            return 1;
        }
    }
    return 60;
}

int main(){
restart:
    start();
    std::cout<<"**You are playing as Geralt. Your mission will be to save the Duchess from the Elder Vampire.**\n";
    stats(Geralt);
    std::cout<<"**You should go through all available quests to defeat the Vampire King with ease. Remember, EVERY SKILL IS IMPORTANT**\n";
    int x;
    std::cout<<"Are you ready to start the game. Enter any number to start the game: ";
    std::cin>>x;
    x = 20;
    std::cout<<"\n\nGeralt was helping Vesemir at Kaer Morhen. Suddenly a raven arrived with a message.";
    std::cout<<"It was from his friend Regis. It was about a threat Geralt's Ally Duchess might face.";
    std::cout<<"Geralt prepared his potions and started riding his hourse towards the Kingdom of Toussaint.\n";
    std::cout<<"\nOn the way, He saw a man being threatened by 2 thugs.";
    std::cout<<"\nGeralt has always stood for the poor and justice. \nPress 'x' to defend the peasant: ";
    std::string opt;
    fflush(stdin);
    std::cin>>opt;
    if(opt == "x" || opt == "X"){
        std::cout<<"Gearalt: Step away or Know the wrath of my blade!!\n";
        std::cout<<"Thug 1 : Let's see what yaa gowt!!!\n";
        character thug1 = monsters("Thug 1");
        thug1.health = 20;
        character thug2 = monsters("Thug 2");
        thug2.health = 20;
        stats(Geralt);
        std::cout<<"\n";
        stats(thug1);
        stats(thug2);
        //fighting starts
        while(Geralt.health>0 && (thug1.health>0 || thug2.health>0)){
            std::cout<<"Geralt has the first oppurtunity to give a swing. press 'x' to attack: ";
            fflush(stdin);
            std::cin>>opt;
            if(opt == "x" || opt == "X"){
                thug1 = Attack(Geralt,thug1);
                thug2 = Attack(Geralt,thug2);
            }
            else{
                std::cout<<"The Thug dodged the sword attack with their blades\n";
            }
            Geralt = Attack(thug1,Geralt);
            Geralt = Attack(thug2,Geralt);
            x = check();
            if(x==0) exit(0);
            else if(x==1) goto restart;
        }
        std::cout<<"The peasant is now releaved. He offered you a fruit to show his gratitude.\n";
        std::cout<<"Enter any key to eat the fruit: ";
        fflush(stdin);
        std::cin>>opt;
        std::cout<<"Geralt all of a sudden feels good and powerful...\n";
        std::cout<<"The peasant disappears and Geralt now understood the man was a wizard.\n";
        Geralt.health += 50;
        stats(Geralt);
        std::cout<<"Press any key to learn  a skill: ";
        fflush(stdin);
        std::cin>>opt;
        std::cout<<"\n**Igni -> fire elementa (heat).**\n"<<"**Strong against = melee and magic**\n"<<"**Weak aaginst = water and earth elementa**\n";
        std::cout<<"\n**Aard -> Air elementa (air).**\n"<<"**Strong against =  Water and magic**\n"<<"**Weak aaginst = melee and plant monsters**\n";
        Geralt = learn_skill();
        Geralt = learn_skill();
    }
    else{
        std::cout<<"Geralt watches, one of the thug knocking the peasant down and stepping on his body, as he rides off the scene.\n";
    }
    std::cout<<"After riding a while Geralt decided to take a rest.\n";
    if(x>30){
        std::cout<<"Eating the fruit might help Geralt to rest more.\n";
    }
    std::cout<<"\nEnter any key for Geralt to start resting: ";
    std::cin>>opt;
    for(int i=0 ; i<=x ; i++){
        health_restore();
        std::cout<<i<<" mins\n";
    }
    std::cout<<"Enter any key for Geralt to wake up: ";
    fflush(stdin);
    std::cin>>opt;
    stats(Geralt);
    std::cout<<"Before Geralt start his journey ahead, he heard a scream of a lady from the river nearby.\n"<<"He ran toward the sound... He saw a water monster ready to devour its meal\n";
    std::cout<<"Enter 'x' to protect the lady from the monster: ";
    fflush(stdin);
    std::cin>>opt;
    if(opt == "x" || opt == "X"){
        character water_monster = monsters("Water Monster");
        std::cout<<"Geralt throws a stick to its head\n"<<"Geralt: step away from her you ugly thing...\n";
        std::cout<<"Monster: RWRAAAAHGHRR...\n";
        std::cout<<"The monster charges towards Gerlat\n";
        std::cout<<"**Remember to use the skills wisely**\n";
        stats(water_monster);
        while(Geralt.health>0 && water_monster.health>0){
            std::cout<<"Enter 'x' to Attack "<<Geralt.power<<"\n";
            if(opt != "a") std::cout<<"Enter 'a' to Aard "<<Geralt.abilities.Aard<<"\n";//if Aard is previous attack (cooldown)
            if(opt != "i")std::cout<<"Enter 'i' to Igni "<<Geralt.abilities.Igni<<"\n";//if Igni is previous attack 
            fflush(stdin);
            std::cin>>opt;
            if(opt == "x" || opt == "X"){
                std::cout<<"Geralt swings his sword at the monster\n";
                water_monster = Attack(Geralt,water_monster);
            }
            else if(opt == "a" || opt == "A"){
                std::cout<<"Geralt shouts Aard and Punches his hand in the direction of the monster\n";
                water_monster = Aard(water_monster);
                std::cout<<"The monsters head shattered. But... it grew back\n."<<"Geralt: *Igni might finish it, if lucky..*\n";
            }
            else if(opt == "i" || opt == "I"){
                std::cout<<"Geralt shouts Igni and swings his hand...\n";
                water_monster.power *= 2;
                std::cout<<"Some how the heat is absorbed by the monster\n";
                stats(water_monster);
                std::cout<<"but, Apart of the monster was vapourised....\n";
                water_monster = Igni(water_monster);
            }
            else{
                std::cout<<"The monster dodged the Attack";
            }
            Geralt = Attack(water_monster,Geralt);
            x = check();
            if(x==0) exit(0);
            else if(x==1) goto restart;
        }
        std::cout<<"The monster was blasted its gut out. It heart was still pumbing\n";
        std::cout<<"The lady is still in shock. She eventually got up and thanked Geralt, and walked away.\n";
        std::cout<<"Geralt took the heart in his hand and was ready to use it to his advantage. Enter any key to upgrade your attacking skills: ";
        fflush(stdin);
        std::cin>>opt;
        Geralt = learn_skill();
        Geralt = learn_skill();
        Geralt.health += 30;
        Geralt = learn_skill();
        for(int i=0;i<20;i++){
            health_restore();
        }
        stats(Geralt);
    }
    else{
        std::cout<<"Geralt: *I shouldn't involve in anything else... my focus should be saving the Duchess...*\n";
        std::cout<<"Geralt heard the disturbing scream of that lady as he drove off the scene.\n";
    }
    std::cout<<"After riding a long time, Gerlat reached the castle. It was already night by then.\n\n";
    std::cout<<"Suddenly Geralt saw something dark flying towards the Queens chamber\n";
    std::cout<<"Geralt Hurried towards the Queen, dodging every guard who obstructed his path\n";
    std::cout<<"Soon the queen was infront of him, he observed the Queen's guards were already motionless.\n\n";
    std::cout<<"The Queen was facing the Vampire Lord and there was nothing in between them except for a few steps\n";
    std::cout<<"Enter any key to react: ";
    std::cin>>opt;
    std::cout<<"Geralt: YOU HAVE TO GO THROUGH ME TO GET HER...\n";
    if(Geralt.abilities.restoration == 1){
        //Vampire lord sensing if Geralt has helped any of the helpless
        std::cout<<"Elder Vamp: You think I care what a Narcissit talk...\n";
        std::cout<<"The vampire charged at the Queen, slitting her throat in a blow of his claws\n";
        std::cout<<"The vampire does the same to Geralt before Geralt could do anything...\n";
        Geralt.health = 0;
        x = check();
            if(x==0) exit(0);
            else if(x==1) goto restart;
    }
    std::cout<<"Elder Vamp: You dare to stand infront of ME?!?!?\n";
    character Elder_vamp = monsters("Elder Vampire");
    Elder_vamp.health = 500;
    Elder_vamp.power = 65;
    stats(Elder_vamp);
    opt = '0';
    while(Geralt.health>0 && Elder_vamp.health>0){
        std::cout<<"Enter 'x' to Attack "<<Geralt.power<<"\n";
        if(opt != "a") std::cout<<"Enter 'a' to Aard "<<Geralt.abilities.Aard<<"\n";//if Aard is previous attack (cooldown)
        if(opt != "i")std::cout<<"Enter 'i' to Igni "<<Geralt.abilities.Igni<<"\n";//if Igni is previous attack 
        fflush(stdin);
        std::cin>>opt;
        if(opt == "x" || opt == "X"){
            std::cout<<"Geralt swings his sword at the Vamp\n";
            std::cout<<"the sword passed though the Vammpires body\n";
            Elder_vamp = Attack(Geralt,Elder_vamp);
        }
        else if(opt == "a" || opt == "A"){
            std::cout<<"Geralt shouts Aard and Punches his hand in the direction of the monster\n";
            std::cout<<"The Vampire is thrown backward by the force.\n.";
            Elder_vamp = Aard(Elder_vamp);
        }
        else if(opt == "i" || opt == "I"){
            std::cout<<"Geralt shouts Igni and swings his hand...\n";
            std::cout<<"Apart of the vampire was burnt....\n";
            Elder_vamp = Igni(Elder_vamp);
        }
        else{
            std::cout<<"The Vampire dodged the Attack";
        }
        Geralt = Attack(Elder_vamp,Geralt);
        x = check();
        if(x==0) exit(0);
        else if(x==1) goto restart;
        else{
            std::cout<<"The Duchess was impressed...\n";
        }
    }
    std::cout<<"There was dark fluid all over Geralts body. Duchess felt joy while watching Geralt putting the sword aside which had her Foe's blood.\n";
    for(int i=0;i<25;i++){
        for(int j=i;j<25;j++){
            std::cout<<" ";
        }
        for(int j=0;j<(2*i)+1;j++){
            std::cout<<"*";
        }
        std::cout<<"\n";
    }
    std::cout<<"The Witcher was honoured to save the ruler of Tuissaint.\n\n"<<"Geralt Adventures will continue...\n";
}