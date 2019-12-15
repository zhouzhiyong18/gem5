/** \file CoherenceResponseType.hh
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:458
 */

#ifndef __CoherenceResponseType_HH__
#define __CoherenceResponseType_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum CoherenceResponseType
 *  \brief ...
 */
enum CoherenceResponseType {
    CoherenceResponseType_FIRST,
    CoherenceResponseType_MEMORY_ACK = CoherenceResponseType_FIRST, /**< Ack from memory controller */
    CoherenceResponseType_DATA, /**< Data block for L1 cache in S state */
    CoherenceResponseType_DATA_EXCLUSIVE, /**< Data block for L1 cache in M/E state */
    CoherenceResponseType_MEMORY_DATA, /**< Data block from / to main memory */
    CoherenceResponseType_ACK, /**< Generic invalidate ack */
    CoherenceResponseType_WB_ACK, /**< writeback ack */
    CoherenceResponseType_UNBLOCK, /**< unblock */
    CoherenceResponseType_EXCLUSIVE_UNBLOCK, /**< exclusive unblock */
    CoherenceResponseType_INV, /**< Invalidate from directory */
    CoherenceResponseType_NUM
};

// Code to convert from a string to the enumeration
CoherenceResponseType string_to_CoherenceResponseType(const std::string& str);

// Code to convert state to a string
std::string CoherenceResponseType_to_string(const CoherenceResponseType& obj);

// Code to increment an enumeration type
CoherenceResponseType &operator++(CoherenceResponseType &e);
std::ostream& operator<<(std::ostream& out, const CoherenceResponseType& obj);

#endif // __CoherenceResponseType_HH__
