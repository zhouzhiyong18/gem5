/** \file L2Cache_Event.hh
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:458
 */

#ifndef __L2Cache_Event_HH__
#define __L2Cache_Event_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum L2Cache_Event
 *  \brief L2 Cache events
 */
enum L2Cache_Event {
    L2Cache_Event_FIRST,
    L2Cache_Event_L1_GET_INSTR = L2Cache_Event_FIRST, /**< a L1I GET INSTR request for a block maped to us */
    L2Cache_Event_L1_GETS, /**< a L1D GETS request for a block maped to us */
    L2Cache_Event_L1_GETX, /**< a L1D GETX request for a block maped to us */
    L2Cache_Event_L1_UPGRADE, /**< a L1D GETX request for a block maped to us */
    L2Cache_Event_L1_PUTX, /**< L1 replacing data */
    L2Cache_Event_L1_PUTX_old, /**< L1 replacing data, but no longer sharer */
    L2Cache_Event_L2_Replacement, /**< L2 Replacement */
    L2Cache_Event_L2_Replacement_clean, /**< L2 Replacement, but data is clean */
    L2Cache_Event_Mem_Data, /**< data from memory */
    L2Cache_Event_Mem_Ack, /**< ack from memory */
    L2Cache_Event_WB_Data, /**< data from L1 */
    L2Cache_Event_WB_Data_clean, /**< clean data from L1 */
    L2Cache_Event_Ack, /**< writeback ack */
    L2Cache_Event_Ack_all, /**< writeback ack */
    L2Cache_Event_Unblock, /**< Unblock from L1 requestor */
    L2Cache_Event_Exclusive_Unblock, /**< Unblock from L1 requestor */
    L2Cache_Event_MEM_Inv, /**< Invalidation from directory */
    L2Cache_Event_NUM
};

// Code to convert from a string to the enumeration
L2Cache_Event string_to_L2Cache_Event(const std::string& str);

// Code to convert state to a string
std::string L2Cache_Event_to_string(const L2Cache_Event& obj);

// Code to increment an enumeration type
L2Cache_Event &operator++(L2Cache_Event &e);
std::ostream& operator<<(std::ostream& out, const L2Cache_Event& obj);

#endif // __L2Cache_Event_HH__
