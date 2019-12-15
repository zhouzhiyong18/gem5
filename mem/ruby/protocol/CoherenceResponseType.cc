/** \file CoherenceResponseType.hh
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:566
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/ruby/protocol/CoherenceResponseType.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const CoherenceResponseType& obj)
{
    out << CoherenceResponseType_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
CoherenceResponseType_to_string(const CoherenceResponseType& obj)
{
    switch(obj) {
      case CoherenceResponseType_MEMORY_ACK:
        return "MEMORY_ACK";
      case CoherenceResponseType_DATA:
        return "DATA";
      case CoherenceResponseType_DATA_EXCLUSIVE:
        return "DATA_EXCLUSIVE";
      case CoherenceResponseType_MEMORY_DATA:
        return "MEMORY_DATA";
      case CoherenceResponseType_ACK:
        return "ACK";
      case CoherenceResponseType_WB_ACK:
        return "WB_ACK";
      case CoherenceResponseType_UNBLOCK:
        return "UNBLOCK";
      case CoherenceResponseType_EXCLUSIVE_UNBLOCK:
        return "EXCLUSIVE_UNBLOCK";
      case CoherenceResponseType_INV:
        return "INV";
      default:
        panic("Invalid range for type CoherenceResponseType");
    }
}

// Code to convert from a string to the enumeration
CoherenceResponseType
string_to_CoherenceResponseType(const string& str)
{
    if (str == "MEMORY_ACK") {
        return CoherenceResponseType_MEMORY_ACK;
    } else if (str == "DATA") {
        return CoherenceResponseType_DATA;
    } else if (str == "DATA_EXCLUSIVE") {
        return CoherenceResponseType_DATA_EXCLUSIVE;
    } else if (str == "MEMORY_DATA") {
        return CoherenceResponseType_MEMORY_DATA;
    } else if (str == "ACK") {
        return CoherenceResponseType_ACK;
    } else if (str == "WB_ACK") {
        return CoherenceResponseType_WB_ACK;
    } else if (str == "UNBLOCK") {
        return CoherenceResponseType_UNBLOCK;
    } else if (str == "EXCLUSIVE_UNBLOCK") {
        return CoherenceResponseType_EXCLUSIVE_UNBLOCK;
    } else if (str == "INV") {
        return CoherenceResponseType_INV;
    } else {
        panic("Invalid string conversion for %s, type CoherenceResponseType", str);
    }
}

// Code to increment an enumeration type
CoherenceResponseType&
operator++(CoherenceResponseType& e)
{
    assert(e < CoherenceResponseType_NUM);
    return e = CoherenceResponseType(e+1);
}
