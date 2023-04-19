#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
 //Password manager v3.0
    /* 
        Nesse programa viso ter um programa que. 
        1- Pessa uma senha que autentifique o usuario unico.
        2- Mostre o menu de interações possíveis,
        colete o input do usuário e abaixo mostre as contas já adicionadas previamente.
        3- Execute a edição das informações se houver alguma atualização com relação as contas.
        4- E por ultimo salve quaisquer mudanças na base de dados e finalize o programa.
    */
//Class that autentify the user**********************|
class Autentification{
    private:
    std::string mainPassword = "21";

    void MainPassword(std::string pssw)
    {
        this->mainPassword=pssw;
    }
    public:

    std::string getMainPassword()
    {
        return this->mainPassword;
    }

    void Autentificator(){
        int count{2};
        
        do{
            std::string password;
            char ch;
            if(count < 2){
                std::cout << "You just have " << count+1 << " lasting!\n";
            }
            std::cout << "\n|Password: ";
            ch = getch();

            while (ch != 13)
            {
                password.push_back(ch);
                std::cout << '*';
                ch = getch();
            }

            if(password == getMainPassword()){
                std::cout << "\nUser aknoledged!";
                Sleep(1000);
                system("cls");
                break;
            }

            else if(count < 1)
            {
                std::cout << "\nTry's excepted! Try again later...";
                Sleep(1000);
                break;
            }

            else{
                std::cout << "\nUser not recognized! try again...";
                count--;
                Sleep(1000);
                system("cls");
            }

        }while(true);
    }
};

class Menu{

    private:
    std::string emails[10];
    std::string passwords[10];
    int size = sizeof(emails)/sizeof(emails[0]);
    void setEmails(std::string email, std::string emails[]){
        this -> emails[10] = email;
    }
    void setPasswords(std::string password, std::string emails[]){
        this -> passwords[10] = password;
    }
    public:
    
    std::string options[5] = {"[1] Add new account.",
                      "[2] Edit account.",
                      "[4] Change main password.",
                      "[5] Quit.",
                      " Press a button..."};

    void ShowMenu(){
        for(int i = 0; i <= 4; i++){
        std::cout << options[i] << "\n";
        }

        std::cout << "\n\n";
        std::cout << "Accounts:\n";
        for(int i = 0; !emails[i].empty(); i++){
            for(int j = 0; !passwords[i].empty(); j++){
                std::cout << emails[i] << '\n';
                std::cout << passwords[i] << "\n\n";
                break;
            }
        }
    }

};

int main(){

    Autentification  attf;
    Menu menu;
    
    attf.Autentificator();
    menu.ShowMenu();
    
    return 0;
}



