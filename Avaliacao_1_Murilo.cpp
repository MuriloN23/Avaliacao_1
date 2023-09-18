#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Cliente {

    string cpf;
    string nome;
    string dtnascimento;
    string cnh;
};

struct Veiculo{

    string renavam;
    string placadoveiculo;
    string data_hora_retirada;  // prevista
    string data_hora_entrega;   // prevista
    string loja_retirada;

};

//void menu () {
//int menu;

//cout << "1.Incluir"<<endl<<"2.Excluir"<<endl<<"3.Alterar"<<endl<<"4.Listar"<<endl<<"5.Localizar"<<endl<<"0.Sair"<< endl<< endl;
//cout << "Digite a opção desejada: " << endl;
//cin >> menu;

vector<Cliente> clientes;
vector<Veiculo> veiculos;

void Incluir() {
    Cliente cliente;
    cout << "Digite o CPF do cliente: ";
    cin >> cliente.cpf;
    cout << "Digite o nome do cliente: ";
    cin.ignore();
    getline(cin, cliente.nome);
    cout << "Digite a data de nascimento (DD/MM/AAAA): ";
    cin >> cliente.dtnascimento;
    cout << "Digite a CNH: ";
    cin >> cliente.cnh;
    clientes.push_back(cliente);
    cout << "O cliente foi incluído com sucesso!"<< endl<<endl;
}

void Excluir() {
    string cpf;
    cout << "Digite o CPF do cliente a ser excluído: "<< endl;
    cin >> cpf;

    auto it = remove_if(clientes.begin(), clientes.end(), [&cpf](const Cliente& c) { return c.cpf == cpf; });

    if (it != clientes.end()) {
        clientes.erase(it, clientes.end());
        cout << "Cliente excluído com sucesso. " << endl;
    } else {
        cout << "Cliente não encontrado. "<< endl;
    }
}

void Alterar() {
    string cpf;
    cout << "Digite o CPF do cliente que deseja alterar: " << endl;
    cin >> cpf;

    for (auto& cliente : clientes) {
        if (cliente.cpf == cpf) {
            cout << "Cliente encontrado. "<<endl;
            cout << "Nome atual: " << cliente.nome << endl <<"Deseja alterar? ('s'para sim ou 'n' para não) ";
            char resposta;
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite o novo nome: ";
                cin.ignore();
                getline(cin, cliente.nome);
            }

            cout << "Data de nascimento atual: " << cliente.dtnascimento <<endl<< "Deseja alterar? ('s'para sim ou 'n' para não) ";
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite a nova data de nascimento (DD/MM/AAAA): ";
                cin >> cliente.dtnascimento;
            }

            cout << "CNH atual: "<< cliente.cnh <<endl<<"Deseja alterar? ('s'para sim ou 'n' para não) ";
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite a nova CNH: ";
                cin >> cliente.cnh;
            }

            return;
        }
    }
    cout << "Cliente não encontrado. "<< endl;
}

void Listar() {
    for (const auto& cliente : clientes) {
        cout << "CPF: " << cliente.cpf << endl<<"Nome: " << cliente.nome << endl <<"Data de Nascimento: " << cliente.dtnascimento << endl<<"CNH: " << cliente.cnh <<endl<<endl;
    }
}

void Localizar() {
    string cpf;
    cout << "Digite o CPF do cliente que deseja localizar: "<< endl;
    cin >> cpf;

    for (const auto& cliente : clientes) {
        if (cliente.cpf == cpf) {
            cout << "CPF: " << cliente.cpf << endl<<"Nome: " << cliente.nome << endl<<"Data de Nascimento: " << cliente.dtnascimento << endl<<"CNH: " << cliente.cnh << endl<<endl;
            return;
        }
    }
    cout << "Cliente não encontrado. "<<endl;
}

void menucliente () {
int menu;

do {
cout << "1.Incluir"<<endl<<"2.Excluir"<<endl<<"3.Alterar"<<endl<<"4.Listar"<<endl<<"5.Localizar"<<endl<<"0.Sair"<< endl<< endl;
cout << "Digite a opção desejada: " << endl;
cin >> menu;

switch(menu) {
  case 1:        // Incluir
    Incluir();
    break;
  case 2:         // Excluir
    Excluir();
    break;
  case 3:        // Alterar (Apenas por CPF)
    Alterar ();
    break;
  case 4:         // Listar
    Listar ();
    break;
  case 5:        // Localizar (por CPF)
    Localizar ();
    break;
  case 0:        // Sair)
    cout << "Você saiu."<<endl;
    break;
  default:
    cout << "Opção inválida." << endl<<endl;
}
}while (menu != 0);
}
int main() {
    menucliente();
    // Chame o menu de gestão de veículos aqui se necessário

    return 0;
}