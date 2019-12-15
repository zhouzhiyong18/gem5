// Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/StateMachine.py:1056
// L1Cache: MESI Directory L1 Cache CMP

#include <sys/types.h>
#include <unistd.h>

#include <cassert>
#include <typeinfo>

#include "base/logging.hh"

#include "debug/RubySlicc.hh"
#include "debug/RubyGenerated.hh"
#include "mem/ruby/protocol/L1Cache_Controller.hh"
#include "mem/ruby/protocol/L1Cache_Event.hh"
#include "mem/ruby/protocol/L1Cache_State.hh"

#include "mem/ruby/protocol/Types.hh"
#include "mem/ruby/system/RubySystem.hh"

#include "mem/ruby/slicc_interface/RubySlicc_includes.hh"

using namespace std;

void
L1Cache_Controller::wakeup()
{
    int counter = 0;
    while (true) {
        unsigned char rejected[3];
        memset(rejected, 0, sizeof(unsigned char)*3);
        // Some cases will put us into an infinite loop without this limit
        assert(counter <= m_transitions_per_cycle);
        if (counter == m_transitions_per_cycle) {
            // Count how often we are fully utilized
            m_fully_busy_cycles++;

            // Wakeup in another cycle and try again
            scheduleEvent(Cycles(1));
            break;
        }
            // L1CacheInPort responseNetwork_in
            m_cur_in_port = 3;
            try {
                            if ((((*m_responseFromL2_ptr)).isReady((clockEdge())))) {
                                {
                                    // Declare message
                                    const ResponseMsg* in_msg_ptr M5_VAR_USED;
                                    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseFromL2_ptr)).peek());
                                    if (in_msg_ptr == NULL) {
                                        // If the cast fails, this is the wrong inport (wrong message type).
                                        // Throw an exception, and the caller will decide to either try a
                                        // different inport or punt.
                                        throw RejectException();
                                    }
                                #ifndef NDEBUG
                                if (!(((((*in_msg_ptr)).m_Destination).isElement(m_machineID)))) {
                                    panic("Runtime Error at MESI_Three_Level-L1cache.sm:274: %s.\n", "assert failure");

                                }
                                #endif
                                ;
                                L1Cache_Entry* cache_entry
                                 = (getCacheEntry(((*in_msg_ptr)).m_addr));
                                L1Cache_TBE* tbe
                                 = (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr));
                                    if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_DATA_EXCLUSIVE)) {
                                        {

                                            TransitionResult result = doTransition(L1Cache_Event_Data_Exclusive, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

                                            if (result == TransitionResult_Valid) {
                                                counter++;
                                                continue; // Check the first port again
                                            }

                                            if (result == TransitionResult_ResourceStall ||
                                                result == TransitionResult_ProtocolStall) {
                                                scheduleEvent(Cycles(1));

                                                // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                            }
                                        }
                                        ;
                                    } else {
                                            if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_DATA)) {
                                                    if (((((getState(tbe, cache_entry, ((*in_msg_ptr)).m_addr)) == L1Cache_State_IS) || ((getState(tbe, cache_entry, ((*in_msg_ptr)).m_addr)) == L1Cache_State_IS_I)) && ((machineIDToMachineType(((*in_msg_ptr)).m_Sender)) == MachineType_L1Cache))) {
                                                        {

                                                            TransitionResult result = doTransition(L1Cache_Event_DataS_fromL1, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

                                                            if (result == TransitionResult_Valid) {
                                                                counter++;
                                                                continue; // Check the first port again
                                                            }

                                                            if (result == TransitionResult_ResourceStall ||
                                                                result == TransitionResult_ProtocolStall) {
                                                                scheduleEvent(Cycles(1));

                                                                // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                            }
                                                        }
                                                        ;
                                                    } else {
                                                            if ((((getPendingAcks(tbe)) - ((*in_msg_ptr)).m_AckCount) == (0))) {
                                                                {

                                                                    TransitionResult result = doTransition(L1Cache_Event_Data_all_Acks, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

                                                                    if (result == TransitionResult_Valid) {
                                                                        counter++;
                                                                        continue; // Check the first port again
                                                                    }

                                                                    if (result == TransitionResult_ResourceStall ||
                                                                        result == TransitionResult_ProtocolStall) {
                                                                        scheduleEvent(Cycles(1));

                                                                        // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                    }
                                                                }
                                                                ;
                                                            } else {
                                                                {

                                                                    TransitionResult result = doTransition(L1Cache_Event_Data, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

                                                                    if (result == TransitionResult_Valid) {
                                                                        counter++;
                                                                        continue; // Check the first port again
                                                                    }

                                                                    if (result == TransitionResult_ResourceStall ||
                                                                        result == TransitionResult_ProtocolStall) {
                                                                        scheduleEvent(Cycles(1));

                                                                        // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                    }
                                                                }
                                                                ;
                                                            }
                                                        }
                                                    } else {
                                                            if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_ACK)) {
                                                                    if ((((getPendingAcks(tbe)) - ((*in_msg_ptr)).m_AckCount) == (0))) {
                                                                        {

                                                                            TransitionResult result = doTransition(L1Cache_Event_Ack_all, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

                                                                            if (result == TransitionResult_Valid) {
                                                                                counter++;
                                                                                continue; // Check the first port again
                                                                            }

                                                                            if (result == TransitionResult_ResourceStall ||
                                                                                result == TransitionResult_ProtocolStall) {
                                                                                scheduleEvent(Cycles(1));

                                                                                // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                            }
                                                                        }
                                                                        ;
                                                                    } else {
                                                                        {

                                                                            TransitionResult result = doTransition(L1Cache_Event_Ack, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

                                                                            if (result == TransitionResult_Valid) {
                                                                                counter++;
                                                                                continue; // Check the first port again
                                                                            }

                                                                            if (result == TransitionResult_ResourceStall ||
                                                                                result == TransitionResult_ProtocolStall) {
                                                                                scheduleEvent(Cycles(1));

                                                                                // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                            }
                                                                        }
                                                                        ;
                                                                    }
                                                                } else {
                                                                        if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_WB_ACK)) {
                                                                            {

                                                                                TransitionResult result = doTransition(L1Cache_Event_WB_Ack, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

                                                                                if (result == TransitionResult_Valid) {
                                                                                    counter++;
                                                                                    continue; // Check the first port again
                                                                                }

                                                                                if (result == TransitionResult_ResourceStall ||
                                                                                    result == TransitionResult_ProtocolStall) {
                                                                                    scheduleEvent(Cycles(1));

                                                                                    // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                                }
                                                                            }
                                                                            ;
                                                                        } else {
                                                                            panic("Runtime Error at MESI_Three_Level-L1cache.sm:302: %s.\n", ("Invalid L1 response type"));
                                                                            ;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                            }
                                                        }
                        } catch (const RejectException & e) {
                            rejected[0]++;
                        }
            // L1CacheInPort requestNetwork_in
            m_cur_in_port = 2;
            try {
                            if ((((*m_requestFromL2_ptr)).isReady((clockEdge())))) {
                                {
                                    // Declare message
                                    const RequestMsg* in_msg_ptr M5_VAR_USED;
                                    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestFromL2_ptr)).peek());
                                    if (in_msg_ptr == NULL) {
                                        // If the cast fails, this is the wrong inport (wrong message type).
                                        // Throw an exception, and the caller will decide to either try a
                                        // different inport or punt.
                                        throw RejectException();
                                    }
                                #ifndef NDEBUG
                                if (!(((((*in_msg_ptr)).m_Destination).isElement(m_machineID)))) {
                                    panic("Runtime Error at MESI_Three_Level-L1cache.sm:312: %s.\n", "assert failure");

                                }
                                #endif
                                ;
                                L1Cache_Entry* cache_entry
                                 = (getCacheEntry(((*in_msg_ptr)).m_addr));
                                L1Cache_TBE* tbe
                                 = (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr));
                                    if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_INV)) {
                                            if (((cache_entry != NULL) && (inL0Cache((*cache_entry).m_CacheState)))) {
                                                {

                                                    TransitionResult result = doTransition(L1Cache_Event_L0_Invalidate_Else, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

                                                    if (result == TransitionResult_Valid) {
                                                        counter++;
                                                        continue; // Check the first port again
                                                    }

                                                    if (result == TransitionResult_ResourceStall ||
                                                        result == TransitionResult_ProtocolStall) {
                                                        scheduleEvent(Cycles(1));

                                                        // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                    }
                                                }
                                                ;
                                            } else {
                                                {

                                                    TransitionResult result = doTransition(L1Cache_Event_Inv, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

                                                    if (result == TransitionResult_Valid) {
                                                        counter++;
                                                        continue; // Check the first port again
                                                    }

                                                    if (result == TransitionResult_ResourceStall ||
                                                        result == TransitionResult_ProtocolStall) {
                                                        scheduleEvent(Cycles(1));

                                                        // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                    }
                                                }
                                                ;
                                            }
                                        } else {
                                                if (((((*in_msg_ptr)).m_Type == CoherenceRequestType_GETX) || (((*in_msg_ptr)).m_Type == CoherenceRequestType_UPGRADE))) {
                                                        if (((cache_entry != NULL) && (inL0Cache((*cache_entry).m_CacheState)))) {
                                                            {

                                                                TransitionResult result = doTransition(L1Cache_Event_L0_Invalidate_Else, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

                                                                if (result == TransitionResult_Valid) {
                                                                    counter++;
                                                                    continue; // Check the first port again
                                                                }

                                                                if (result == TransitionResult_ResourceStall ||
                                                                    result == TransitionResult_ProtocolStall) {
                                                                    scheduleEvent(Cycles(1));

                                                                    // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                }
                                                            }
                                                            ;
                                                        } else {
                                                            {

                                                                TransitionResult result = doTransition(L1Cache_Event_Fwd_GETX, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

                                                                if (result == TransitionResult_Valid) {
                                                                    counter++;
                                                                    continue; // Check the first port again
                                                                }

                                                                if (result == TransitionResult_ResourceStall ||
                                                                    result == TransitionResult_ProtocolStall) {
                                                                    scheduleEvent(Cycles(1));

                                                                    // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                }
                                                            }
                                                            ;
                                                        }
                                                    } else {
                                                            if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_GETS)) {
                                                                    if (((cache_entry != NULL) && (inL0Cache((*cache_entry).m_CacheState)))) {
                                                                        {

                                                                            TransitionResult result = doTransition(L1Cache_Event_L0_Invalidate_Else, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

                                                                            if (result == TransitionResult_Valid) {
                                                                                counter++;
                                                                                continue; // Check the first port again
                                                                            }

                                                                            if (result == TransitionResult_ResourceStall ||
                                                                                result == TransitionResult_ProtocolStall) {
                                                                                scheduleEvent(Cycles(1));

                                                                                // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                            }
                                                                        }
                                                                        ;
                                                                    } else {
                                                                        {

                                                                            TransitionResult result = doTransition(L1Cache_Event_Fwd_GETS, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

                                                                            if (result == TransitionResult_Valid) {
                                                                                counter++;
                                                                                continue; // Check the first port again
                                                                            }

                                                                            if (result == TransitionResult_ResourceStall ||
                                                                                result == TransitionResult_ProtocolStall) {
                                                                                scheduleEvent(Cycles(1));

                                                                                // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                            }
                                                                        }
                                                                        ;
                                                                    }
                                                                } else {
                                                                    panic("Runtime Error at MESI_Three_Level-L1cache.sm:339: %s.\n", ("Invalid forwarded request type"));
                                                                    ;
                                                                }
                                                            }
                                                        }
                                                        }
                                                    }
                        } catch (const RejectException & e) {
                            rejected[1]++;
                        }
            // L1CacheInPort messageBufferFromL0_in
            m_cur_in_port = 0;
            try {
                            if ((((*m_bufferFromL0_ptr)).isReady((clockEdge())))) {
                                {
                                    // Declare message
                                    const CoherenceMsg* in_msg_ptr M5_VAR_USED;
                                    in_msg_ptr = dynamic_cast<const CoherenceMsg *>(((*m_bufferFromL0_ptr)).peek());
                                    if (in_msg_ptr == NULL) {
                                        // If the cast fails, this is the wrong inport (wrong message type).
                                        // Throw an exception, and the caller will decide to either try a
                                        // different inport or punt.
                                        throw RejectException();
                                    }
                                L1Cache_Entry* cache_entry
                                 = (getCacheEntry(((*in_msg_ptr)).m_addr));
                                L1Cache_TBE* tbe
                                 = (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr));
                                    if ((((*in_msg_ptr)).m_Class == CoherenceClass_INV_DATA)) {
                                        {

                                            TransitionResult result = doTransition(L1Cache_Event_L0_DataAck, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

                                            if (result == TransitionResult_Valid) {
                                                counter++;
                                                continue; // Check the first port again
                                            }

                                            if (result == TransitionResult_ResourceStall ||
                                                result == TransitionResult_ProtocolStall) {
                                                scheduleEvent(Cycles(1));

                                                // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                            }
                                        }
                                        ;
                                    } else {
                                            if ((((*in_msg_ptr)).m_Class == CoherenceClass_INV_ACK)) {
                                                {

                                                    TransitionResult result = doTransition(L1Cache_Event_L0_Ack, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

                                                    if (result == TransitionResult_Valid) {
                                                        counter++;
                                                        continue; // Check the first port again
                                                    }

                                                    if (result == TransitionResult_ResourceStall ||
                                                        result == TransitionResult_ProtocolStall) {
                                                        scheduleEvent(Cycles(1));

                                                        // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                    }
                                                }
                                                ;
                                            } else {
                                                    if ((cache_entry != NULL)) {
                                                        {

                                                            TransitionResult result = doTransition((mandatory_request_type_to_event(((*in_msg_ptr)).m_Class)), cache_entry, tbe, ((*in_msg_ptr)).m_addr);

                                                            if (result == TransitionResult_Valid) {
                                                                counter++;
                                                                continue; // Check the first port again
                                                            }

                                                            if (result == TransitionResult_ResourceStall ||
                                                                result == TransitionResult_ProtocolStall) {
                                                                scheduleEvent(Cycles(1));

                                                                // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                            }
                                                        }
                                                        ;
                                                    } else {
                                                            if ((((*m_cache_ptr)).cacheAvail(((*in_msg_ptr)).m_addr))) {
                                                                {

                                                                    TransitionResult result = doTransition((mandatory_request_type_to_event(((*in_msg_ptr)).m_Class)), cache_entry, tbe, ((*in_msg_ptr)).m_addr);

                                                                    if (result == TransitionResult_Valid) {
                                                                        counter++;
                                                                        continue; // Check the first port again
                                                                    }

                                                                    if (result == TransitionResult_ResourceStall ||
                                                                        result == TransitionResult_ProtocolStall) {
                                                                        scheduleEvent(Cycles(1));

                                                                        // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                    }
                                                                }
                                                                ;
                                                            } else {
                                                                Addr victim
                                                                 = (((*m_cache_ptr)).cacheProbe(((*in_msg_ptr)).m_addr));
                                                                L1Cache_Entry* victim_entry
                                                                 = (getCacheEntry(victim));
                                                                L1Cache_TBE* victim_tbe
                                                                 = (((*m_TBEs_ptr)).lookup(victim));
                                                                    if (((victim_entry != NULL) && (inL0Cache((*victim_entry).m_CacheState)))) {
                                                                        {

                                                                            TransitionResult result = doTransition(L1Cache_Event_L0_Invalidate_Own, victim_entry, victim_tbe, victim);

                                                                            if (result == TransitionResult_Valid) {
                                                                                counter++;
                                                                                continue; // Check the first port again
                                                                            }

                                                                            if (result == TransitionResult_ResourceStall ||
                                                                                result == TransitionResult_ProtocolStall) {
                                                                                scheduleEvent(Cycles(1));

                                                                                // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                            }
                                                                        }
                                                                        ;
                                                                    } else {
                                                                        {

                                                                            TransitionResult result = doTransition(L1Cache_Event_L1_Replacement, victim_entry, victim_tbe, victim);

                                                                            if (result == TransitionResult_Valid) {
                                                                                counter++;
                                                                                continue; // Check the first port again
                                                                            }

                                                                            if (result == TransitionResult_ResourceStall ||
                                                                                result == TransitionResult_ProtocolStall) {
                                                                                scheduleEvent(Cycles(1));

                                                                                // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                            }
                                                                        }
                                                                        ;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                    }
                                                }
                        } catch (const RejectException & e) {
                            rejected[2]++;
                        }
        // If we got this far, we have nothing left todo or something went
        // wrong
        break;
    }
}
