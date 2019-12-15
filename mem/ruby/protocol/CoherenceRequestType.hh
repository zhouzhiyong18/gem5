/** \file CoherenceRequestType.hh
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:458
 */

#ifndef __CoherenceRequestType_HH__
#define __CoherenceRequestType_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum CoherenceRequestType
 *  \brief ...
 */
enum CoherenceRequestType {
    CoherenceRequestType_FIRST,
    CoherenceRequestType_GETX = CoherenceRequestType_FIRST, /**< Get eXclusive */
    CoherenceRequestType_UPGRADE, /**< UPGRADE to exclusive */
    CoherenceRequestType_GETS, /**< Get Shared */
    CoherenceRequestType_GET_INSTR, /**< Get Instruction */
    CoherenceRequestType_INV, /**< INValidate */
    CoherenceRequestType_PUTX, /**< Replacement message */
    CoherenceRequestType_WB_ACK, /**< Writeback ack */
    CoherenceRequestType_DMA_READ, /**< DMA Read */
    CoherenceRequestType_DMA_WRITE, /**< DMA Write */
    CoherenceRequestType_NUM
};

// Code to convert from a string to the enumeration
CoherenceRequestType string_to_CoherenceRequestType(const std::string& str);

// Code to convert state to a string
std::string CoherenceRequestType_to_string(const CoherenceRequestType& obj);

// Code to increment an enumeration type
CoherenceRequestType &operator++(CoherenceRequestType &e);
std::ostream& operator<<(std::ostream& out, const CoherenceRequestType& obj);

#endif // __CoherenceRequestType_HH__
