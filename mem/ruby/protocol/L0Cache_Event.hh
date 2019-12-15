/** \file L0Cache_Event.hh
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:458
 */

#ifndef __L0Cache_Event_HH__
#define __L0Cache_Event_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum L0Cache_Event
 *  \brief Cache events
 */
enum L0Cache_Event {
    L0Cache_Event_FIRST,
    L0Cache_Event_Load = L0Cache_Event_FIRST, /**< Load request from the home processor */
    L0Cache_Event_Ifetch, /**< I-fetch request from the home processor */
    L0Cache_Event_Store, /**< Store request from the home processor */
    L0Cache_Event_Inv, /**< Invalidate request from L2 bank */
    L0Cache_Event_L0_Replacement, /**< L0 Replacement */
    L0Cache_Event_Fwd_GETX, /**< GETX from other processor */
    L0Cache_Event_Fwd_GETS, /**< GETS from other processor */
    L0Cache_Event_Fwd_GET_INSTR, /**< GET_INSTR from other processor */
    L0Cache_Event_Data, /**< Data for processor */
    L0Cache_Event_Data_Exclusive, /**< Data for processor */
    L0Cache_Event_Data_Stale, /**< Data for processor, but not for storage */
    L0Cache_Event_Ack, /**< Ack for processor */
    L0Cache_Event_Ack_all, /**< Last ack for processor */
    L0Cache_Event_WB_Ack, /**< Ack for replacement */
    L0Cache_Event_NUM
};

// Code to convert from a string to the enumeration
L0Cache_Event string_to_L0Cache_Event(const std::string& str);

// Code to convert state to a string
std::string L0Cache_Event_to_string(const L0Cache_Event& obj);

// Code to increment an enumeration type
L0Cache_Event &operator++(L0Cache_Event &e);
std::ostream& operator<<(std::ostream& out, const L0Cache_Event& obj);

#endif // __L0Cache_Event_HH__
