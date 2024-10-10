#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <bitset>

using namespace std;

int T;
vector<string> ans;

map<string, string> opcode;

void init()
{
    opcode["ADD"] = "0000";
    opcode["ADDC"] = "0000";
    opcode["SUB"] = "0001";
    opcode["SUBC"] = "0001";
    opcode["MOV"] = "0010";
    opcode["MOVC"] = "0010";
    opcode["AND"] = "0011";
    opcode["ANDC"] = "0011";
    opcode["OR"] = "0100";
    opcode["ORC"] = "0100";
    opcode["NOT"] = "0101";
    opcode["MULT"] = "0110";
    opcode["MULTC"] = "0110";
    opcode["LSFTL"] = "0111";
    opcode["LSFTLC"] = "0111";
    opcode["LSFTR"] = "1000";
    opcode["LSFTRC"] = "1000";
    opcode["ASFTR"] = "1001";
    opcode["ASFTRC"] = "1001";
    opcode["RL"] = "1010";
    opcode["RLC"] = "1010";
    opcode["RR"] = "1011";
    opcode["RRC"] = "1011";
}

void Test()
{
    string _opcode; int rD, rA, rB;
    string machine_code = "";
    bool IsUseConst = false;
    cin >> _opcode;

    // 0 ~ 4
    machine_code.append(opcode[_opcode]);

    // 상수를 사용하는 경우
    if (_opcode[_opcode.size() - 1] == 'C')
    {
        IsUseConst = true;
        machine_code.push_back('1');
    }
    else
    {
        machine_code.push_back('0');
    }

    // 5
    machine_code.push_back('0');

    cin >> rD;

    // 6 ~ 8

    
    machine_code.append(bitset<3>(rD).to_string());

    cin >> rA;

    // 9 ~ 11
    if (_opcode == "MOV" || _opcode == "MOVC" || _opcode == "NOT")
    {
        machine_code.append("000");
    }
    else
    {
        machine_code.append(bitset<3>(rA).to_string());
    }

    cin >> rB;

    // 12 ~ 15
    if (IsUseConst)
    {
        // 상수 쓰면 #C 그대로 2진수화
        machine_code.append(bitset<4>(rB).to_string());
    }
    else
    {
        // 레지스터 쓰면 마지막 자리만 0 처리
        machine_code.append(bitset<3>(rB).to_string());
        machine_code.push_back('0');
    }

    ans.push_back(machine_code);

    

}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        Test();
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << '\n';
    }
    

    return 0;
}