// Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/StateMachine.py:1056
// L0Cache: MESI Directory L0 Cache

#include <sys/types.h>
#include <unistd.h>

#include <cassert>
#include <typeinfo>

#include "base/logging.hh"

#include "debug/RubySlicc.hh"
#include "debug/RubyGenerated.hh"
#include "mem/ruby/protocol/L0Cache_Controller.hh"
#include "mem/ruby/protocol/L0Cache_Event.hh"
#include "mem/ruby/protocol/L0Cache_State.hh"

#include "mem/ruby/protocol/Types.hh"
#include "mem/ruby/system/RubySystem.hh"

#include "mem/ruby/slicc_interface/RubySlicc_includes.hh"

using namespace std;

void
L0Cache_Controller::wakeup()
{
    int counter = 0;
    while (true) {
        unsigned char rejected[2];
        memset(rejected, 0, sizeof(unsigned char)*2);
        // Some cases will put us into an infinite loop without this limit
        assert(counter <= m_transitions_per_cycle);
        if (counter == m_transitions_per_cycle) {
            // Count how often we are fully utilized
            m_fully_busy_cycles++;

            // Wakeup in another cycle and try again
            scheduleEvent(Cycles(1));
            break;
        }
            // L0CacheInPort messgeBuffer_in
            m_cur_in_port = 1;
            try {
                            if ((((*m_bufferFromL1_ptr)).isReady((clockEdge())))) {
                                {
                                    // Declare message
                                    const CoherenceMsg* in_msg_ptr M5_VAR_USED;
                                    in_msg_ptr = dynamic_cast<const CoherenceMsg *>(((*m_bufferFromL1_ptr)).peek());
                                    if (in_msg_ptr == NULL) {
                                        // If the cast fails, this is the wrong inport (wrong message type).
                                        // Throw an exception, and the caller will decide to either try a
                                        // different inport or punt.
                                        throw RejectException();
                                    }
                                    if (m_is_blocking &&
                                        (m_block_map.count(in_msg_ptr->m_addr) == 1) &&
                                        (m_block_map[in_msg_ptr->m_addr] != &(*m_bufferFromL1_ptr))) {
                                            (*m_bufferFromL1_ptr).delayHead(clockEdge(), cyclesToTicks(Cycles(1)));
                                            continue;
                                    }
                                            
                                #ifndef NDEBUG
                                if (!((((*in_msg_ptr)).m_Dest == m_machineID))) {
                                    panic("Runtime Error at MESI_Three_Level-L0cache.sm:263: %s.\n", "assert failure");

                                }
                                #endif
                                ;
                                L0Cache_Entry* cache_entry
                                 = (getCacheEntry(((*in_msg_ptr)).m_addr));
                                L0Cache_TBE* tbe
                                 = (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr));
                                    if ((((*in_msg_ptr)).m_Class == CoherenceClass_DATA_EXCLUSIVE)) {
                                        {

                                            TransitionResult result = doTransition(L0Cache_Event_Data_Exclusive, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

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
                                            if ((((*in_msg_ptr)).m_Class == CoherenceClass_DATA)) {
                                                {

                                                    TransitionResult result = doTransition(L0Cache_Event_Data, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

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
                                                    if ((((*in_msg_ptr)).m_Class == CoherenceClass_STALE_DATA)) {
                                                        {

                                                            TransitionResult result = doTransition(L0Cache_Event_Data_Stale, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

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
                                                            if ((((*in_msg_ptr)).m_Class == CoherenceClass_ACK)) {
                                                                {

                                                                    TransitionResult result = doTransition(L0Cache_Event_Ack, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

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
                                                                    if ((((*in_msg_ptr)).m_Class == CoherenceClass_WB_ACK)) {
                                                                        {

                                                                            TransitionResult result = doTransition(L0Cache_Event_WB_Ack, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

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
                                                                            if ((((*in_msg_ptr)).m_Class == CoherenceClass_INV)) {
                                                                                {

                                                                                    TransitionResult result = doTransition(L0Cache_Event_Inv, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

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
                                                                                    if (((((*in_msg_ptr)).m_Class == CoherenceClass_GETX) || (((*in_msg_ptr)).m_Class == CoherenceClass_UPGRADE))) {
                                                                                        {

                                                                                            TransitionResult result = doTransition(L0Cache_Event_Fwd_GETX, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

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
                                                                                            if ((((*in_msg_ptr)).m_Class == CoherenceClass_GETS)) {
                                                                                                {

                                                                                                    TransitionResult result = doTransition(L0Cache_Event_Fwd_GETS, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

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
                                                                                                    if ((((*in_msg_ptr)).m_Class == CoherenceClass_GET_INSTR)) {
                                                                                                        {

                                                                                                            TransitionResult result = doTransition(L0Cache_Event_Fwd_GET_INSTR, cache_entry, tbe, ((*in_msg_ptr)).m_addr);

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
                                                                                                        panic("Runtime Error at MESI_Three_Level-L0cache.sm:289: %s.\n", ("Invalid forwarded request type"));
                                                                                                        ;
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                    }
                                                                }
                        } catch (const RejectException & e) {
                            rejected[0]++;
                        }
            // L0CacheInPort mandatoryQueue_in
            m_cur_in_port = 0;
            try {
                            if ((((*m_mandatoryQueue_ptr)).isReady((clockEdge())))) {
                                {
                                    // Declare message
                                    const RubyRequest* in_msg_ptr M5_VAR_USED;
                                    in_msg_ptr = dynamic_cast<const RubyRequest *>(((*m_mandatoryQueue_ptr)).peek());
                                    if (in_msg_ptr == NULL) {
                                        // If the cast fails, this is the wrong inport (wrong message type).
                                        // Throw an exception, and the caller will decide to either try a
                                        // different inport or punt.
                                        throw RejectException();
                                    }
                                    if (m_is_blocking &&
                                        (m_block_map.count(in_msg_ptr->m_LineAddress) == 1) &&
                                        (m_block_map[in_msg_ptr->m_LineAddress] != &(*m_mandatoryQueue_ptr))) {
                                            (*m_mandatoryQueue_ptr).delayHead(clockEdge(), cyclesToTicks(Cycles(1)));
                                            continue;
                                    }
                                            
                                    if ((((*in_msg_ptr)).m_Type == RubyRequestType_IFETCH)) {
                                        L0Cache_Entry* Icache_entry
                                         = (getICacheEntry(((*in_msg_ptr)).m_LineAddress));
                                            if ((Icache_entry != NULL)) {
                                                {

                                                    TransitionResult result = doTransition((mandatory_request_type_to_event(((*in_msg_ptr)).m_Type)), Icache_entry, (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_LineAddress)), ((*in_msg_ptr)).m_LineAddress);

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
                                                L0Cache_Entry* Dcache_entry
                                                 = (getDCacheEntry(((*in_msg_ptr)).m_LineAddress));
                                                    if ((Dcache_entry != NULL)) {
                                                        {

                                                            TransitionResult result = doTransition(L0Cache_Event_L0_Replacement, Dcache_entry, (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_LineAddress)), ((*in_msg_ptr)).m_LineAddress);

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
                                                        if ((((*m_Icache_ptr)).cacheAvail(((*in_msg_ptr)).m_LineAddress))) {
                                                            {

                                                                TransitionResult result = doTransition((mandatory_request_type_to_event(((*in_msg_ptr)).m_Type)), Icache_entry, (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_LineAddress)), ((*in_msg_ptr)).m_LineAddress);

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
                                                            Addr addr
                                                             = (((*m_Icache_ptr)).cacheProbe(((*in_msg_ptr)).m_LineAddress));
                                                                if (m_is_blocking &&
                                                                    (m_block_map.count(addr) == 1) &&
                                                                    (m_block_map[addr] == &(*m_mandatoryQueue_ptr))) {
                                                                        (*m_mandatoryQueue_ptr).delayHead(clockEdge(), cyclesToTicks(Cycles(1)));
                                                                        continue;
                                                                    }
                                                                    
                                                            {

                                                                TransitionResult result = doTransition(L0Cache_Event_L0_Replacement, (getICacheEntry(addr)), (((*m_TBEs_ptr)).lookup(addr)), addr);

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
                                                    L0Cache_Entry* Dcache_entry
                                                     = (getDCacheEntry(((*in_msg_ptr)).m_LineAddress));
                                                        if ((Dcache_entry != NULL)) {
                                                            {

                                                                TransitionResult result = doTransition((mandatory_request_type_to_event(((*in_msg_ptr)).m_Type)), Dcache_entry, (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_LineAddress)), ((*in_msg_ptr)).m_LineAddress);

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
                                                            L0Cache_Entry* Icache_entry
                                                             = (getICacheEntry(((*in_msg_ptr)).m_LineAddress));
                                                                if ((Icache_entry != NULL)) {
                                                                    {

                                                                        TransitionResult result = doTransition(L0Cache_Event_L0_Replacement, Icache_entry, (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_LineAddress)), ((*in_msg_ptr)).m_LineAddress);

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
                                                                    if ((((*m_Dcache_ptr)).cacheAvail(((*in_msg_ptr)).m_LineAddress))) {
                                                                        {

                                                                            TransitionResult result = doTransition((mandatory_request_type_to_event(((*in_msg_ptr)).m_Type)), Dcache_entry, (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_LineAddress)), ((*in_msg_ptr)).m_LineAddress);

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
                                                                        Addr addr
                                                                         = (((*m_Dcache_ptr)).cacheProbe(((*in_msg_ptr)).m_LineAddress));
                                                                            if (m_is_blocking &&
                                                                                (m_block_map.count(addr) == 1) &&
                                                                                (m_block_map[addr] == &(*m_mandatoryQueue_ptr))) {
                                                                                    (*m_mandatoryQueue_ptr).delayHead(clockEdge(), cyclesToTicks(Cycles(1)));
                                                                                    continue;
                                                                                }
                                                                                
                                                                        {

                                                                            TransitionResult result = doTransition(L0Cache_Event_L0_Replacement, (getDCacheEntry(addr)), (((*m_TBEs_ptr)).lookup(addr)), addr);

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
                        } catch (const RejectException & e) {
                            rejected[1]++;
                        }
        // If we got this far, we have nothing left todo or something went
        // wrong
        break;
    }
}
