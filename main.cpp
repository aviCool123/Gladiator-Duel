#include <iostream>
#include <bits/stdc++.h>
#include<ctime>
using namespace std;

// structs
struct Moves
{
    string name;
    int power = 0;
    int accuracy;
    int heal = 0 ;
    int defence = 0;
    int attack =0;
    int lower_defense = 0;
    int lower_attack = 0;
};

struct Character
{
    string name;
    int hp;
    int attack;
    int defence;
    int speed;
    Moves move1;
    Moves move2;
    Moves move3;
};

// functions-
int character_chose(int player_no);
Character charcter_maker(int character_no);
void turn_system(Character player_1,Character player_2);
void add_dashes();
Moves ask_move(Character player , int player_no);
int execute_move(Character &attacker, Character &defender, Moves move);

int main(){
    do{
        string input;
        cout<<">>";
        cin>>input;
        if(input == "run"){
            #pragma region Start
                cout<<"----Gladiator Duel----"<<endl;
                cout<<"Choose 1 ,2 or 3"<<endl;
                
                // the choice of the player is the player 1 charcter and vice versa
                Character Player_1 = charcter_maker(character_chose(1));
                Character Player_2 = charcter_maker(character_chose(2));
                cout<<"Player 1 Chose:"<<Player_1.name<<endl;
                cout<<"Player 2 Chose:"<<Player_2.name<<endl<<endl;
                add_dashes();
                cout<<"May the battle commence !"<<endl;
                add_dashes();
                cout<<"Player 1:"<<Player_1.name<<" (HP:"<<Player_1.hp<<")"<< "(DEF:"<< Player_1.defence<<")"<< "(ATCK:"<< Player_1.attack<<")"<<endl;
                cout<<" VS "<<endl;
                cout<<"Player 2:"<<Player_2.name<<" (HP:"<<Player_2.hp<<")"<< "(DEF:"<< Player_2.defence<<")"<< "(ATCK:"<< Player_2.attack<<")"<<endl;
                add_dashes();
                cout<<endl;
                cout<<"The Fastest Moves First"<<endl;
                add_dashes();
            #pragma endregion
            do{
                Moves p1_move = ask_move(Player_1,1);
                Player_2.hp -= execute_move(Player_1,Player_2, p1_move);
                if(Player_2.hp<=0){
                    cout<<"PLAYER 1 HAS WON"<<endl;
                    add_dashes();
                    break;
                }
                cout<<"PLAYER 1 (HP:"<<Player_1.hp<<") "<< "(DEF:"<< Player_1.defence<<")"<< "(ATCK:"<< Player_1.attack<<")"<<endl;
                cout<<"PLAYER 2 (HP:"<<Player_2.hp<<")"<< "(DEF:"<< Player_2.defence<<")"<< "(ATCK:"<< Player_2.attack<<")"<<endl;     
                add_dashes();      
                
                Moves p2_move= ask_move(Player_2,2);
                Player_1.hp -= execute_move(Player_2,Player_1, p2_move);
                
                if(Player_1.hp<=0){
                    cout<<"PLAYER 2 HAS WON"<<endl;
                    add_dashes();
                    break;
                }
                cout<<"PLAYER 1 (HP:"<<Player_1.hp<<") "<< "(DEF:"<< Player_1.defence<<")"<< "(ATCK:"<< Player_1.attack<<")"<<endl;
                cout<<"PLAYER 2 (HP:"<<Player_2.hp<<")"<< "(DEF:"<< Player_2.defence<<")"<< "(ATCK:"<< Player_2.attack<<")"<<endl;     
                add_dashes();
                
            }while(true);

            


            
        }
        else if(input == "end"){
            break;
        }
    }while(true);
    return 0;
}

// functions-
int character_chose(int player_no){
    int player_choice;
    while (true){
            
            cout<<"Player " << player_no << " Pick your character:"<< endl;
            
            cout<<"1. Knight (Balanced)"<< endl;
            cout<<"2. Mage (High attack, low defense)"<< endl;
            cout<<"3. Rogue (Fast, low HP)"<< endl;
            cout<<">";
            
            cin>>player_choice;
            if ((player_choice == 1) || (player_choice == 2) || (player_choice == 3)){
                break;
            }

    }
    add_dashes();
    cout<<endl;
    return player_choice;
}

Character charcter_maker(int character_no)
{
    
    if (character_no == 1){
        Character Knight;
            Knight.name = "Knight";
            Knight.hp = 120;
            Knight.attack = 25;
            Knight.defence = 20;
            Knight.speed = 7;
            // move 1
                Knight.move1.name = "Slash :Power 35, High accuracy (90%)";
                Knight.move1.power = 40;
                Knight.move1.accuracy = 90;
            //move 2
                Knight.move2.name ="Shield Bash :80% accuracy,lowers enemy attack by -20";
                
                Knight.move2.accuracy = 80;
                Knight.move2.lower_attack = 20;
            // move 3
                Knight.move3.name = "Rally : Buff move, increases Knights attack by +10";
                Knight.move3.attack = 10;
                Knight.move3.accuracy = 120;
        return Knight;
    }
    else if(character_no == 2){
        Character Mage;
            Mage.name = "Mage";
            Mage.hp = 90;
            Mage.attack =35;
            Mage.defence = 10;
            Mage.speed = 4;
            //move 1
                Mage.move1.name = "Fireball: 65% accuracy,Power:75(high power)";
                Mage.move1.power = 40;
                Mage.move1.accuracy = 65;
            //move 2
                Mage.move2.name = "Lightning Bolt, 90% accuracy,Power:55";
                Mage.move2.accuracy = 90;
                Mage.move2.power = 20;
            //move 3
                Mage.move3.name = "Heal, Heals 25 hp";
                Mage.move3.accuracy = 120;
                Mage.move3.heal = 25;
        return Mage;
    }
    else if(character_no == 3){
        Character Rogue;
            Rogue.name = "Rogue";
            Rogue.hp = 100;
            Rogue.attack = 28;
            Rogue.defence = 12;
            Rogue.speed = 10;
            // move 1
                Rogue.move1.name = "Quick Strike, 33 Power , 80% accurcy";
                Rogue.move1.accuracy = 80;
                Rogue.move1.power = 25;
                
            //move 2
                Rogue.move2.name = "Poison Dagger , 1 Hit kill (108), 40% aacuracy";
                Rogue.move2.accuracy = 40;
                
                Rogue.move2.power = 75;
            //move 3
                Rogue.move3.name = "Smoke Bomb, lowers defenses by 20";
                Rogue.move3.accuracy = 120;
                Rogue.move3.lower_defense = 20;
        return Rogue;

    }

}

void turn_system(Character player_1, Character player_2)
{
    int turns=0;
    do{
        

    }while((player_1.hp >0)&&(player_2.hp>0));
}

void add_dashes(){
    cout<<"--------"<<endl;
}

Moves ask_move(Character player,int player_no)
{
    cout << "Player "<<player_no<<" "<<player.name<<" Choose your move:"<<endl;
    cout << "1." <<player.move1.name << endl;
    cout << "2." <<player.move2.name << endl;
    cout << "3." <<player.move3.name << endl;
    cout << ">";
    int move_choice;
    cin >> move_choice;
    if (move_choice == 1){
        return player.move1;
    }
    else if (move_choice == 2){
        return player.move2;
    }
    else if (move_choice == 3){
        return player.move3;
    }   
}

int execute_move(Character &attacker, Character &defender, Moves move)
{
    srand(time(0));
    
    int hit_chance = rand() % 100 + 1; // rsandom number between 1 and 100
    int move_accu = move.accuracy - defender.speed;
    if (hit_chance <= move_accu) {
        if(move.heal != 0 ){
            attacker.hp += move.heal;
            cout<<"HEALED PLAYER (HP:"<<move.heal<<")"<<endl;
            add_dashes();
            return 0;
        }
        else{
            
            // other buffs / debuffs
                attacker.defence += move.defence;
                if(move.attack > 0){
                    attacker.attack += move.attack;
                    cout<<"ATTACK POWER INCREASED BY "<<move.attack<<endl;
                    add_dashes();
                    return 0;
                }
                if (move.lower_attack>0){
                    defender.attack -= move.lower_attack;
                    cout<<"ENEMY ATTACK POWER DECREASED BY "<<move.lower_attack<<endl;
                    add_dashes();
                }
                
                
                if(defender.defence - move.lower_defense <= 0 ){
                    int temp = move.lower_defense - defender.defence;
                    defender.defence = 0;
                    if (temp > 0) {
                        defender.hp -= temp;
                        cout<<"ENEMY DEFENCES DESTROYED! INFLICTED DAMAGE BY "<<temp << endl;
                    } else {
                        cout<<"ENEMY DEFENCES DESTROYED!" << endl;
                    }
                    add_dashes();
                }else {defender.defence -= move.lower_defense;
                    if(move.lower_defense>0){
                        cout<<"ENEMY DEFENSES LOWERED BY "<<move.lower_defense<<endl;
                        add_dashes();
                    }
                    
                }
               
            
            // returns HP
                if ((move.power + attacker.attack)-defender.defence <0){
                    cout<<"NOT ENOUGH POWER TO INFLICT DAMAGE"<<endl;
                    add_dashes();
                    return 0;

                }else{
                    cout<<"CAUSED "<<(move.power + attacker.attack)-defender.defence<<" DAMAGE"<<endl;
                    add_dashes();
                    return (move.power + attacker.attack)-defender.defence;

                }
        }
    }
    else{
        cout<<attacker.name<<" missed"<<endl;
        add_dashes();
        return 0;
    }
    
    
}
