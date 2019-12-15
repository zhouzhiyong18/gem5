/** \file L0Cache_State.hh
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:566
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/ruby/protocol/L0Cache_State.hh"

using namespace std;

// Code to convert the current state to an access permission
AccessPermission L0Cache_State_to_permission(const L0Cache_State& obj)
{
    switch(obj) {
      case L0Cache_State_I:
        return AccessPermission_Invalid;
      case L0Cache_State_S:
        return AccessPermission_Read_Only;
      case L0Cache_State_E:
        return AccessPermission_Read_Only;
      case L0Cache_State_M:
        return AccessPermission_Read_Write;
      case L0Cache_State_Inst_IS:
        return AccessPermission_Busy;
      case L0Cache_State_IS:
        return AccessPermission_Busy;
      case L0Cache_State_IM:
        return AccessPermission_Busy;
      case L0Cache_State_SM:
        return AccessPermission_Read_Only;
      default:
        panic("Unknown state access permission converstion for L0Cache_State");
    }
}

// Code for output operator
ostream&
operator<<(ostream& out, const L0Cache_State& obj)
{
    out << L0Cache_State_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
L0Cache_State_to_string(const L0Cache_State& obj)
{
    switch(obj) {
      case L0Cache_State_I:
        return "I";
      case L0Cache_State_S:
        return "S";
      case L0Cache_State_E:
        return "E";
      case L0Cache_State_M:
        return "M";
      case L0Cache_State_Inst_IS:
        return "Inst_IS";
      case L0Cache_State_IS:
        return "IS";
      case L0Cache_State_IM:
        return "IM";
      case L0Cache_State_SM:
        return "SM";
      default:
        panic("Invalid range for type L0Cache_State");
    }
}

// Code to convert from a string to the enumeration
L0Cache_State
string_to_L0Cache_State(const string& str)
{
    if (str == "I") {
        return L0Cache_State_I;
    } else if (str == "S") {
        return L0Cache_State_S;
    } else if (str == "E") {
        return L0Cache_State_E;
    } else if (str == "M") {
        return L0Cache_State_M;
    } else if (str == "Inst_IS") {
        return L0Cache_State_Inst_IS;
    } else if (str == "IS") {
        return L0Cache_State_IS;
    } else if (str == "IM") {
        return L0Cache_State_IM;
    } else if (str == "SM") {
        return L0Cache_State_SM;
    } else {
        panic("Invalid string conversion for %s, type L0Cache_State", str);
    }
}

// Code to increment an enumeration type
L0Cache_State&
operator++(L0Cache_State& e)
{
    assert(e < L0Cache_State_NUM);
    return e = L0Cache_State(e+1);
}
