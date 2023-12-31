#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

struct Roteiro
{
    string codigo;
    string dataHoraPrevista;
    string duracaoPrevista;
    string origem;
    string destino;
};

void criaRoteiro(vector<Roteiro> &roteiros)
{
    Roteiro roteiro;
    regex cpfValido("[0-9]{3}\\.?[0-9]{3}\\.?[0-9]{3}\\-?[0-9]{2}"),
        dataValida("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\\d{4}$");

    cout << "Codigo: ";
    cin >> roteiro.codigo;

    cout << "Data hora prevista: ";
    cin >> roteiro.dataHoraPrevista;

    cout << "Duracao prevista: ";
    cin >> roteiro.duracaoPrevista;

    cout << "Origem: ";
    cin >> roteiro.origem;

    cout << "Destino: ";
    cin >> roteiro.destino;

    roteiros.push_back(roteiro);

    cout << "Roteiro inserido!" << endl;
}

void excluirRoteiro(vector<Roteiro> &roteiros)
{
    string codigo;
    cout << "Digite o Codigo do roteiro para excluir: ";
    cin >> codigo;

    for (auto it = roteiros.begin(); it != roteiros.end(); ++it)
    {
        if (it->codigo == codigo)
        {
            roteiros.erase(it);
            cout << "Roteiro excluido com sucesso!" << endl;
            return;
        }
    }

    cout << "Roteiro nao encontrado." << endl;
}

void alteraRoteiro(vector<Roteiro> &roteiros)
{
    string codigo;
    char decisao;
    cout << "Digite o codigo do roteiro para alterar: ";
    cin >> codigo;

    for (Roteiro &it : roteiros)
    {
        if (it.codigo == codigo)
        {
            cout << "Deseja mudar a data hora prevista?? (s/n): ";
            cin >> decisao;

            if (decisao == 's')
            {
                cout << "Nova data hora: ";
                cin >> it.dataHoraPrevista;
            }

            cout << "Deseja mudar a duracao prevista? (s/n): ";
            cin >> decisao;

            if (decisao == 's')
            {
                cout << "Nova duracao prevista: ";
                cin >> it.duracaoPrevista;
            }

            cout << "Deseja mudar a origem? (s/n): ";
            cin >> decisao;

            if (decisao == 's')
            {
                cout << "Nova origem: ";
                cin >> it.origem;
            }

            cout << "Deseja mudar o destino? (s/n): ";
            cin >> decisao;

            if (decisao == 's')
            {
                cout << "Novo desino: ";
                cin >> it.destino;
            }

            cout << "Roteiro atualizado com sucesso!" << endl;
            return;
        }
    }

    cout << "Roteiro nao encontrado." << endl;
}

void listaRoteiro(vector<Roteiro> &roteiros)
{
    if (roteiros.empty())
    {
        cout << "Nao existem roteiros!" << endl;
        return;
    }
    cout << "Roteiros:" << endl;
    for (Roteiro &it : roteiros)
    {
        cout << "Codigo: " << it.codigo << ", Data Hora prevista: " << it.dataHoraPrevista << ", Duracao prevista: " << it.duracaoPrevista << ", Origem: " << it.origem << ", Destino: " << it.destino << endl;
    }
}

void localizaRoteiro(vector<Roteiro> &roteiros)
{
    string codigo;
    cout << "Digite o codigo do roteiro para localizar: ";
    cin >> codigo;

    if (roteiros.empty())
    {
        cout << "A lista de Roteiros está vazia." << endl;
        return;
    }
    cout << "Lista de roteiros:" << endl;
    for (Roteiro &it : roteiros)
    {
        if (it.codigo == codigo)
        {
            cout << "Roteiro encontrado!" << endl;
            cout << "Codigo: " << it.codigo << ", Data Hora prevista: " << it.dataHoraPrevista << ", Duracao prevista: " << it.duracaoPrevista << ", Origem: " << it.origem << ", Destino: " << it.destino << endl;
            return;
        }
    }

    cout << "Roteiro nao encontrado!" << endl;
}

int main()
{
    vector<Roteiro> listaRoteiros;
    int opt;

    while (true)
    {
        cout << "Escolha uma opcao:" << endl;
        cout << "Criar roteiro - 1" << endl;
        cout << "Excluir roteiro - 2" << endl;
        cout << "Alterar roteiro - 3" << endl;
        cout << "Listar roteiros - 4" << endl;
        cout << "Localizar roteiro - 5" << endl;
        cout << "Sair  - 0" << endl;

        cin >> opt;

        switch (opt)
        {
        case 1:
            criaRoteiro(listaRoteiros);
            break;
        case 2:
            excluirRoteiro(listaRoteiros);
            break;
        case 3:
            alteraRoteiro(listaRoteiros);
            break;
        case 4:
            listaRoteiro(listaRoteiros);
            break;
        case 5:
            localizaRoteiro(listaRoteiros);
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