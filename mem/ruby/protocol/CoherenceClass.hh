/** \file CoherenceClass.hh
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:458
 */

#ifndef __CoherenceClass_HH__
#define __CoherenceClass_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum CoherenceClass
 *  \brief ...
 */
enum CoherenceClass {
    CoherenceClass_FIRST,
    CoherenceClass_GETX = CoherenceClass_FIRST, /**< Get eXclusive */
    CoherenceClass_UPGRADE, /**< UPGRADE to exclusive */
    CoherenceClass_GETS, /**< Get Shared */
    CoherenceClass_GET_INSTR, /**< Get Instruction */
    CoherenceClass_INV, /**< INValidate */
    CoherenceClass_PUTX, /**< Replacement message */
    CoherenceClass_WB_ACK, /**< Writeback ack */
    CoherenceClass_INV_DATA, /**< No description avaliable */
    CoherenceClass_INV_ACK, /**< No description avaliable */
    CoherenceClass_DATA, /**< Data block for L1 cache in S state */
    CoherenceClass_DATA_EXCLUSIVE, /**< Data block for L1 cache in M/E state */
    CoherenceClass_ACK, /**< Generic invalidate ack */
    CoherenceClass_STALE_DATA, /**< No description avaliable */
    CoherenceClass_NUM
};

// Code to convert from a string to the enumeration
CoherenceClass string_to_CoherenceClass(const std::string& str);

// Code to convert state to a string
std::string CoherenceClass_to_string(const CoherenceClass& obj);

// Code to increment an enumeration type
CoherenceClass &operator++(CoherenceClass &e);
std::ostream& operator<<(std::ostream& out, const CoherenceClass& obj);

#endif // __CoherenceClass_HH__
