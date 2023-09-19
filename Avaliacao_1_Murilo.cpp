#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//PRIMEIRA PARTE

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


void Incluir(vector<Cliente>clientes) {
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

void Excluir(vector<Cliente>clientes) {
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

void Alterar(vector<Cliente>clientes) {
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

void Listar(vector<Cliente>clientes) {
    for (const auto& cliente : clientes) {
        cout << "CPF: " << cliente.cpf << endl<<"Nome: " << cliente.nome << endl <<"Data de Nascimento: " << cliente.dtnascimento << endl<<"CNH: " << cliente.cnh <<endl<<endl;
    }
}

void Localizar(vector<Cliente>clientes) {
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

void menuCliente (vector<Cliente>clientes) {
int menu;

do {
cout << "1.Incluir"<<endl<<"2.Excluir"<<endl<<"3.Alterar"<<endl<<"4.Listar"<<endl<<"5.Localizar"<<endl<<"0.Sair"<< endl<< endl;
cout << "Digite a opção desejada: " << endl;
cin >> menu;

switch(menu) {
  case 1:        // Incluir
    Incluir(clientes);
    break;
  case 2:         // Excluir
    Excluir(clientes);
    break;
  case 3:        // Alterar (Apenas por CPF)
    Alterar (clientes);
    break;
  case 4:         // Listar
    Listar (clientes);
    break;
  case 5:        // Localizar (por CPF)
    Localizar (clientes);
    break;
  case 0:        // Sair)
    cout << "Você saiu."<<endl;
    break;
  default:
    cout << "Opção inválida." << endl<<endl;
}
}while (menu != 0);
}

//SEGUNDA PARTE

void IncluirVeiculo(vector<Veiculo> veiculos) {
    Veiculo veiculo;
    cout << "Digite o Renavam: "<<endl;
    cin >> veiculo.renavam;
    cout << "Digite a placa do veículo: "<<endl;
    cin.ignore();
    getline(cin, veiculo.placadoveiculo);
    cout << "Digite a data e hora de retirada (DD/MM/AAAA HH:MM): "<<endl;
    getline(cin, veiculo.data_hora_retirada);
    cout << "Digite a data e hora de entrega (DD/MM/AAAA HH:MM): "<<endl;
    getline(cin, veiculo.data_hora_entrega);
    cout << "Digite a loja de retirada: "<<endl;
    getline(cin, veiculo.loja_retirada);

    veiculos.push_back(veiculo);
    cout << "Veículo incluído com sucesso. " << endl;
}

void ExcluirVeiculo(vector<Veiculo> veiculos) {
    string placa;
    cout << "Digite a placa do veículo que deseja excluir: "<<endl;
    cin >> placa;

    auto it = remove_if(veiculos.begin(), veiculos.end(), [&placa](const Veiculo& v) { return v.placadoveiculo == placa; });

    if (it != veiculos.end()) {
        veiculos.erase(it, veiculos.end());
        cout << "Veículo excluído com sucesso. " << endl;
    } else {
        cout << "Veículo não encontrado. " << endl;
    }
}

void AlterarVeiculo(vector<Veiculo> veiculos) {
    string placa;
    cout << "Digite a placa do veículo que deseja alterar: "<<endl;
    cin >> placa;

    for (auto& veiculo : veiculos) {
        if (veiculo.placadoveiculo == placa) {
            cout << "Veículo encontrado." << endl;
            cout << "Renavam atual: " << veiculo.renavam << endl<<"Deseja alterar? ('s'para sim ou 'n' para não) "<<endl;
            char resposta;
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite o novo Renavam: "<<endl;
                cin >> veiculo.renavam;
            }

            cout << "Placa atual: " << veiculo.placadoveiculo <<endl<< "Deseja alterar? ('s'para sim ou 'n' para não) "<<endl;
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite a nova placa: "<<endl;
                cin.ignore();
                getline(cin, veiculo.placadoveiculo);
            }

            cout << "Data e hora de retirada atual: " << veiculo.data_hora_retirada << endl<< "Deseja alterar? ('s'para sim ou 'n' para não) "<< endl;
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite a nova data e hora de retirada (DD/MM/AAAA HH:MM): "<<endl;
                cin.ignore();
                getline(cin, veiculo.data_hora_retirada);
            }

            cout << "Data e hora de entrega atual: " << veiculo.data_hora_entrega << endl<<"Deseja alterar? ('s'para sim ou 'n' para não) "<<endl;
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite a nova data e hora de entrega (DD/MM/AAAA HH:MM): "<<endl;
                cin.ignore();
                getline(cin, veiculo.data_hora_entrega);
            }

            cout << "Loja de retirada atual: " << veiculo.loja_retirada <<endl<< "Deseja alterar? ('s'para sim ou 'n' para não) "<<endl;
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite a nova loja de retirada: "<<endl;
                cin.ignore();
                getline(cin, veiculo.loja_retirada);
            }

            return;
        }
    }
    cout << "Veículo não encontrado!" << endl;
}

void ListarVeiculos(vector<Veiculo> veiculos) {
    for (const auto& veiculo : veiculos) {
        cout << "Renavam: " << veiculo.renavam << endl<<"Placa: " << veiculo.placadoveiculo <<endl<< "Data e hora de retirada: " << veiculo.data_hora_retirada <<endl<< "Data e hora de entrega: " << veiculo.data_hora_entrega << endl<<"Loja de retirada: " << veiculo.loja_retirada << "."<<endl<<endl;
    }
}

void LocalizarVeiculo(vector<Veiculo> veiculos) {
    string placa;
    cout << "Digite a placa do veículo que deseja localizar: "<<endl;
    cin >> placa;

    for (const auto& veiculo : veiculos) {
        if (veiculo.placadoveiculo == placa) {
            cout << "Renavam: " << veiculo.renavam << endl<<"Placa: " << veiculo.placadoveiculo << endl<<"Data e hora de retirada: " << veiculo.data_hora_retirada << endl<<"Data e hora de entrega: " << veiculo.data_hora_entrega <<endl<< "Loja de retirada: " << veiculo.loja_retirada << "."<<endl<<endl;
            return;
        }
    }
    cout << "Veículo não encontrado!" << endl;
}

void menuVeiculos(vector<Veiculo> veiculos) {
    int opcao;

    do {
        cout << "Menu de Veículos" << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Alterar" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Localizar" << endl;
        cout << "0. Sair" << endl;
        cout << "Digite uma opção: "<<endl;
        cin >> opcao;

        switch (opcao) {
        case 1:
            IncluirVeiculo(veiculos);
            break;
        case 2:
            ExcluirVeiculo(veiculos);
            break;
        case 3:
            AlterarVeiculo(veiculos);
            break;
        case 4:
            ListarVeiculos(veiculos);
            break;
        case 5:
            LocalizarVeiculo(veiculos);
            break;
        case 0:
            cout << "Encerrando..." << endl;
            break;
        default:
            cout << "Opção inválida." << endl;
            break;
        }

    } while (opcao != 0);
}



int main() {
    int opcao;
    vector<Cliente> clientes;
    vector<Veiculo> veiculos;
    do {
        system("clear");
        cout << "LocaFINA S/A" << endl;
        cout << "1. Gestão de Clientes" << endl;
        cout << "2. Gestão de Veículos" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma das opções :" << endl;;
        cin >> opcao;

        switch (opcao) {
        case 1:
            menuCliente(clientes);
            break;
        case 2:
            menuVeiculos(veiculos);
            break;
        case 0:
            cout << "Encerrando o programa..." << endl;
            break;
        default:
            cout << "Opção inválida!" << endl;
            break;
        }

    } while (opcao != 0);

    return 0;
}
