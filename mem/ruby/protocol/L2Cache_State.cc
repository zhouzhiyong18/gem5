/** \file L2Cache_State.hh
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:566
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/ruby/protocol/L2Cache_State.hh"

using namespace std;

// Code to convert the current state to an access permission
AccessPermission L2Cache_State_to_permission(const L2Cache_State& obj)
{
    switch(obj) {
      case L2Cache_State_NP:
        return AccessPermission_Invalid;
      case L2Cache_State_SS:
        return AccessPermission_Read_Only;
      case L2Cache_State_M:
        return AccessPermission_Read_Write;
      case L2Cache_State_MT:
        return AccessPermission_Maybe_Stale;
      case L2Cache_State_M_I:
        return AccessPermission_Busy;
      case L2Cache_State_MT_I:
        return AccessPermission_Busy;
      case L2Cache_State_MCT_I:
        return AccessPermission_Busy;
      case L2Cache_State_I_I:
        return AccessPermission_Busy;
      case L2Cache_State_S_I:
        return AccessPermission_Busy;
      case L2Cache_State_ISS:
        return AccessPermission_Busy;
      case L2Cache_State_IS:
        return AccessPermission_Busy;
      case L2Cache_State_IM:
        return AccessPermission_Busy;
      case L2Cache_State_SS_MB:
        return AccessPermission_Busy;
      case L2Cache_State_MT_MB:
        return AccessPermission_Busy;
      case L2Cache_State_MT_IIB:
        return AccessPermission_Busy;
      case L2Cache_State_MT_IB:
        return AccessPermission_Busy;
      case L2Cache_State_MT_SB:
        return AccessPermission_Busy;
      default:
        panic("Unknown state access permission converstion for L2Cache_State");
    }
}

// Code for output operator
ostream&
operator<<(ostream& out, const L2Cache_State& obj)
{
    out << L2Cache_State_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
L2Cache_State_to_string(const L2Cache_State& obj)
{
    switch(obj) {
      case L2Cache_State_NP:
        return "NP";
      case L2Cache_State_SS:
        return "SS";
      case L2Cache_State_M:
        return "M";
      case L2Cache_State_MT:
        return "MT";
      case L2Cache_State_M_I:
        return "M_I";
      case L2Cache_State_MT_I:
        return "MT_I";
      case L2Cache_State_MCT_I:
        return "MCT_I";
      case L2Cache_State_I_I:
        return "I_I";
      case L2Cache_State_S_I:
        return "S_I";
      case L2Cache_State_ISS:
        return "ISS";
      case L2Cache_State_IS:
        return "IS";
      case L2Cache_State_IM:
        return "IM";
      case L2Cache_State_SS_MB:
        return "SS_MB";
      case L2Cache_State_MT_MB:
        return "MT_MB";
      case L2Cache_State_MT_IIB:
        return "MT_IIB";
      case L2Cache_State_MT_IB:
        return "MT_IB";
      case L2Cache_State_MT_SB:
        return "MT_SB";
      default:
        panic("Invalid range for type L2Cache_State");
    }
}

// Code to convert from a string to the enumeration
L2Cache_State
string_to_L2Cache_State(const string& str)
{
    if (str == "NP") {
        return L2Cache_State_NP;
    } else if (str == "SS") {
        return L2Cache_State_SS;
    } else if (str == "M") {
        return L2Cache_State_M;
    } else if (str == "MT") {
        return L2Cache_State_MT;
    } else if (str == "M_I") {
        return L2Cache_State_M_I;
    } else if (str == "MT_I") {
        return L2Cache_State_MT_I;
    } else if (str == "MCT_I") {
        return L2Cache_State_MCT_I;
    } else if (str == "I_I") {
        return L2Cache_State_I_I;
    } else if (str == "S_I") {
        return L2Cache_State_S_I;
    } else if (str == "ISS") {
        return L2Cache_State_ISS;
    } else if (str == "IS") {
        return L2Cache_State_IS;
    } else if (str == "IM") {
        return L2Cache_State_IM;
    } else if (str == "SS_MB") {
        return L2Cache_State_SS_MB;
    } else if (str == "MT_MB") {
        return L2Cache_State_MT_MB;
    } else if (str == "MT_IIB") {
        return L2Cache_State_MT_IIB;
    } else if (str == "MT_IB") {
        return L2Cache_State_MT_IB;
    } else if (str == "MT_SB") {
        return L2Cache_State_MT_SB;
    } else {
        panic("Invalid string conversion for %s, type L2Cache_State", str);
    }
}

// Code to increment an enumeration type
L2Cache_State&
operator++(L2Cache_State& e)
{
    assert(e < L2Cache_State_NUM);
    return e = L2Cache_State(e+1);
}
