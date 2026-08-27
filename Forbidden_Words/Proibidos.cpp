#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){

    int num_plv;
    string Proib[10];
    string MSG;
    int contadores[10] = {0};
    
    
    cin >> num_plv;
    

    for(int i = 0; i < num_plv; i++){
        cin >> Proib[i];
    }

    cin.ignore();

    getline (cin, MSG);

    stringstream mensagem(MSG);
    vector<string> plvrs;
    string temp;

    while(mensagem >> temp){
        plvrs.push_back(temp);
    }
    

    for(int i = 0; i < num_plv; i++){
        for(size_t j = 0; j < plvrs.size(); j++){
            if(Proib[i] == plvrs[j]){
                string asteriscos(plvrs[j].length(), '*');
                plvrs[j] = asteriscos;
                contadores[i]++;
            }
        }
        
    }


    for(size_t i = 0; i < plvrs.size(); i++){
        cout << plvrs[i] << " ";
    }
    cout << endl;


    for(int i = 0; i < num_plv; i++){
        cout << "Palavra " << Proib[i] << " substituida " << contadores[i] << " vez(es)" << ".\n";
    }




    


    return 0;






}
