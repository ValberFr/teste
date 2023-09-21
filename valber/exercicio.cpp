#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

struct Passageiro
{
    string cpf;
    string nome;
    string dataNascimento;
    string numAutorizacao;
};

void criaPassageiro(vector<Passageiro> &passageiros)
{
    Passageiro passageiro;
    regex cpfValido("[0-9]{3}\\.?[0-9]{3}\\.?[0-9]{3}\\-?[0-9]{2}"),
        dataValida("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\\d{4}$");

    cout << "CPF: ";
    cin >> passageiro.cpf;

    while (true)
    {
        if (regex_match(passageiro.cpf, cpfValido))
        {
            break;
        }
        else
        {
            cout << "CPF invalido, digite novamente: ";
            cin >> passageiro.cpf;
        }
    }

    for (Passageiro &it : passageiros)
    {
        if (it.cpf == passageiro.cpf)
        {
            cout << "CPF ja cadastrado!" << endl;
            return;
        }
    }

    cout << "Nome: ";
    cin.ignore();
    getline(cin, passageiro.nome);

    cout << "Data de Nascimento (dia/mes/ano): ";
    cin >> passageiro.dataNascimento;

    while (true)
    {
        if (regex_match(passageiro.dataNascimento, dataValida))
        {
            break;
        }
        else
        {
            cout << "Data invalida, digite novamente: ";
            cin >> passageiro.dataNascimento;
        }
    }

    cout << "Numero de Autorizacao: ";
    cin >> passageiro.numAutorizacao;

    passageiros.push_back(passageiro);

    cout << "Passageiro inserido!" << endl;
}

void excluirPassageiro(vector<Passageiro> &passageiros)
{
    string cpf;
    cout << "Digite o CPF do passageiro para excluir: ";
    cin >> cpf;

    for (auto it = passageiros.begin(); it != passageiros.end(); ++it)
    {
        if (it->cpf == cpf)
        {
            passageiros.erase(it);
            cout << "Passageiro excluido com sucesso!" << endl;
            return;
        }
    }

    cout << "Passageiro nao encontrado." << endl;
}

void alteraPassageiro(vector<Passageiro> &passageiros)
{
    string cpf;
    char decisao;

    cout << "Deseja alterar o CPF? (s/n): ";
    cin >> decisao;

    if (decisao == 's')
    {
        excluirPassageiro(passageiros);
        criaPassageiro(passageiros);
        return;
    }

    cout << "Digite o CPF do passageiro que terá os dados alterados: ";
    cin >> cpf;

    for (Passageiro &it : passageiros)
    {
        if (it.cpf == cpf)
        {
            cout << "Deseja mudar o nome? (s/n): ";
            cin >> decisao;

            if (decisao == 's')
            {
                cout << "Novo Nome: ";
                cin.ignore();
                getline(cin, it.nome);
            }

            cout << "Deseja mudar a data de nascimento? (s/n): ";
            cin >> decisao;

            if (decisao == 's')
            {
                cout << "Nova Data de Nascimento: ";
                cin >> it.dataNascimento;
            }

            cout << "Deseja mudar o numero de autorizacao? (s/n): ";
            cin >> decisao;

            if (decisao == 's')
            {
                cout << "Novo Número de Autorizacao: ";
                cin >> it.numAutorizacao;
            }

            cout << "Passageiro atualizado com sucesso!" << endl;
            return;
        }
    }

    cout << "Passageiro nao encontrado." << endl;
}

void listaPassageiro(vector<Passageiro> &passageiros)
{
    if (passageiros.empty())
    {
        cout << "Nao existem passageiros!" << endl;
        return;
    }
    cout << "Passageiros:" << endl;
    for (Passageiro &it : passageiros)
    {
        cout << "CPF: " << it.cpf << ", Nome: " << it.nome << ", Data de Nascimento: " << it.dataNascimento << ", Número de Autorização: " << it.numAutorizacao << endl;
    }
}

void localizaPassageiro(vector<Passageiro> &passageiros)
{
    string cpf;
    cout << "Digite o CPF do passageiro para localizar: ";
    cin >> cpf;

    if (passageiros.empty())
    {
        cout << "A lista de passageiros está vazia." << endl;
        return;
    }

    for (Passageiro &it : passageiros)
    {
        if (it.cpf == cpf)
        {
            cout << "Passageiro encontrado!" << endl;
            cout << "CPF: " << it.cpf << ", Nome: " << it.nome << ", Data de Nascimento: " << it.dataNascimento << ", Número de Autorização: " << it.numAutorizacao << endl;
            return;
        }
    }

    cout << "Passageiro nao encontrado!" << endl;
}

int main()
{
    vector<Passageiro> listaPassageiros;
    int opt;

    while (true)
    {
        cout << "Escolha uma opcao:" << endl;
        cout << "Criar passageiro - 1" << endl;
        cout << "Excluir passageiro - 2" << endl;
        cout << "Alterar passageiro - 3" << endl;
        cout << "Listar passageiros - 4" << endl;
        cout << "Localizar passageiro - 5" << endl;
        cout << "Sair  - 0" << endl;

        cin >> opt;

        switch (opt)
        {
        case 1:
            criaPassageiro(listaPassageiros);
            break;
        case 2:
            excluirPassageiro(listaPassageiros);
            break;
        case 3:
            alteraPassageiro(listaPassageiros);
            break;
        case 4:
            listaPassageiro(listaPassageiros);
            break;
        case 5:
            localizaPassageiro(listaPassageiros);
            break;
        case 0:
            cout << "Programa finalizado!" << endl;
            return 0;
        default:
            cout << "Digite um valor válido!" << endl;
        }
    }

    return 0;
}