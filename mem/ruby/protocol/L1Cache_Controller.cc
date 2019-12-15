/** \file L1Cache_Controller.cc
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/StateMachine.py:465
 * Created by slicc definition of Module "MESI Directory L1 Cache CMP"
 */

#include <sys/types.h>
#include <unistd.h>

#include <cassert>
#include <sstream>
#include <string>
#include <typeinfo>

#include "base/compiler.hh"
#include "base/cprintf.hh"
#include "mem/ruby/common/BoolVec.hh"

#include "debug/RubySlicc.hh"
#include "debug/RubyGenerated.hh"
#include "mem/ruby/network/Network.hh"
#include "mem/ruby/protocol/L1Cache_Controller.hh"
#include "mem/ruby/protocol/L1Cache_Event.hh"
#include "mem/ruby/protocol/L1Cache_State.hh"
#include "mem/ruby/protocol/Types.hh"
#include "mem/ruby/system/RubySystem.hh"

#include "mem/ruby/slicc_interface/RubySlicc_includes.hh"

using namespace std;
#include "mem/ruby/protocol/TBETable.hh"
L1Cache_Controller *
L1Cache_ControllerParams::create()
{
    return new L1Cache_Controller(this);
}

int L1Cache_Controller::m_num_controllers = 0;
std::vector<Stats::Vector *>  L1Cache_Controller::eventVec;
std::vector<std::vector<Stats::Vector *> >  L1Cache_Controller::transVec;

// for adding information to the protocol debug trace
stringstream L1Cache_transitionComment;

#ifndef NDEBUG
#define APPEND_TRANSITION_COMMENT(str) (L1Cache_transitionComment << str)
#else
#define APPEND_TRANSITION_COMMENT(str) do {} while (0)
#endif

/** \brief constructor */
L1Cache_Controller::L1Cache_Controller(const Params *p)
    : AbstractController(p)
{
    m_machineID.type = MachineType_L1Cache;
    m_machineID.num = m_version;
    m_num_controllers++;

    m_in_ports = 3;
    m_cache_ptr = p->cache;
    m_l2_select_num_bits = p->l2_select_num_bits;
    m_l1_request_latency = p->l1_request_latency;
    m_l1_response_latency = p->l1_response_latency;
    m_to_l2_latency = p->to_l2_latency;
    m_bufferToL0_ptr = p->bufferToL0;
    m_bufferFromL0_ptr = p->bufferFromL0;
    m_requestToL2_ptr = p->requestToL2;
    m_responseToL2_ptr = p->responseToL2;
    m_unblockToL2_ptr = p->unblockToL2;
    m_requestFromL2_ptr = p->requestFromL2;
    m_responseFromL2_ptr = p->responseFromL2;

    for (int state = 0; state < L1Cache_State_NUM; state++) {
        for (int event = 0; event < L1Cache_Event_NUM; event++) {
            m_possible[state][event] = false;
            m_counters[state][event] = 0;
        }
    }
    for (int event = 0; event < L1Cache_Event_NUM; event++) {
        m_event_counters[event] = 0;
    }
}

void
L1Cache_Controller::initNetQueues()
{
    MachineType machine_type = string_to_MachineType("L1Cache");
    int base M5_VAR_USED = MachineType_base_number(machine_type);

    assert(m_bufferToL0_ptr != NULL);
    assert(m_bufferFromL0_ptr != NULL);
    assert(m_requestToL2_ptr != NULL);
    m_net_ptr->setToNetQueue(m_version + base, m_requestToL2_ptr->getOrdered(), 0,
                                     "request", m_requestToL2_ptr);
    assert(m_responseToL2_ptr != NULL);
    m_net_ptr->setToNetQueue(m_version + base, m_responseToL2_ptr->getOrdered(), 1,
                                     "response", m_responseToL2_ptr);
    assert(m_unblockToL2_ptr != NULL);
    m_net_ptr->setToNetQueue(m_version + base, m_unblockToL2_ptr->getOrdered(), 2,
                                     "unblock", m_unblockToL2_ptr);
    assert(m_requestFromL2_ptr != NULL);
    m_net_ptr->setFromNetQueue(m_version + base, m_requestFromL2_ptr->getOrdered(), 2,
                                     "request", m_requestFromL2_ptr);
    assert(m_responseFromL2_ptr != NULL);
    m_net_ptr->setFromNetQueue(m_version + base, m_responseFromL2_ptr->getOrdered(), 1,
                                     "response", m_responseFromL2_ptr);
}

void
L1Cache_Controller::init()
{
    // initialize objects
    m_TBEs_ptr  = new TBETable<L1Cache_TBE>(m_number_of_TBEs);
    assert(m_TBEs_ptr != NULL);
    m_l2_select_low_bit_ptr = new int;
    (*m_l2_select_low_bit_ptr) = RubySystem::getBlockSizeBits();


    (*m_responseFromL2_ptr).setConsumer(this);
    (*m_requestFromL2_ptr).setConsumer(this);
    (*m_bufferFromL0_ptr).setConsumer(this);

    possibleTransition(L1Cache_State_IS, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_IS, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_IS, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_IM, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_IM, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_IM, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_IS_I, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_IS_I, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_IS_I, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_M_I, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_M_I, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_M_I, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_SM, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_SM, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_SM, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_SINK_WB_ACK, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_SINK_WB_ACK, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_SINK_WB_ACK, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_S_IL0, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_S_IL0, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_S_IL0, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_M_IL0, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_M_IL0, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_M_IL0, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_E_IL0, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_E_IL0, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_E_IL0, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_MM_IL0, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_MM_IL0, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_MM_IL0, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_I, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_I, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_I, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_S, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_SS, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_EE, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_MM, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_S, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_SS, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_SS, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_S, L1Cache_Event_L0_Invalidate_Own);
    possibleTransition(L1Cache_State_S, L1Cache_Event_L0_Invalidate_Else);
    possibleTransition(L1Cache_State_SS, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_EE, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_MM, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_EE, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_EE, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_EE, L1Cache_Event_Fwd_GETX);
    possibleTransition(L1Cache_State_EE, L1Cache_Event_Fwd_GETS);
    possibleTransition(L1Cache_State_E, L1Cache_Event_L0_Invalidate_Own);
    possibleTransition(L1Cache_State_E, L1Cache_Event_L0_Invalidate_Else);
    possibleTransition(L1Cache_State_MM, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_M, L1Cache_Event_WriteBack);
    possibleTransition(L1Cache_State_E, L1Cache_Event_WriteBack);
    possibleTransition(L1Cache_State_M_I, L1Cache_Event_WB_Ack);
    possibleTransition(L1Cache_State_MM, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_M_I, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_MM, L1Cache_Event_Fwd_GETX);
    possibleTransition(L1Cache_State_MM, L1Cache_Event_Fwd_GETS);
    possibleTransition(L1Cache_State_M, L1Cache_Event_L0_Invalidate_Own);
    possibleTransition(L1Cache_State_M, L1Cache_Event_L0_Invalidate_Else);
    possibleTransition(L1Cache_State_M_I, L1Cache_Event_Fwd_GETX);
    possibleTransition(L1Cache_State_M_I, L1Cache_Event_Fwd_GETS);
    possibleTransition(L1Cache_State_IS, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_IS_I, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_IS, L1Cache_Event_Data_all_Acks);
    possibleTransition(L1Cache_State_IS_I, L1Cache_Event_Data_all_Acks);
    possibleTransition(L1Cache_State_IS, L1Cache_Event_DataS_fromL1);
    possibleTransition(L1Cache_State_IS_I, L1Cache_Event_DataS_fromL1);
    possibleTransition(L1Cache_State_IS, L1Cache_Event_Data_Exclusive);
    possibleTransition(L1Cache_State_IS_I, L1Cache_Event_Data_Exclusive);
    possibleTransition(L1Cache_State_IM, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_SM, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_IM, L1Cache_Event_Data);
    possibleTransition(L1Cache_State_IM, L1Cache_Event_Data_all_Acks);
    possibleTransition(L1Cache_State_SM, L1Cache_Event_Ack);
    possibleTransition(L1Cache_State_IM, L1Cache_Event_Ack);
    possibleTransition(L1Cache_State_SM, L1Cache_Event_Ack_all);
    possibleTransition(L1Cache_State_SM, L1Cache_Event_L0_Invalidate_Else);
    possibleTransition(L1Cache_State_SINK_WB_ACK, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_SINK_WB_ACK, L1Cache_Event_WB_Ack);
    possibleTransition(L1Cache_State_M_IL0, L1Cache_Event_WriteBack);
    possibleTransition(L1Cache_State_E_IL0, L1Cache_Event_WriteBack);
    possibleTransition(L1Cache_State_M_IL0, L1Cache_Event_L0_DataAck);
    possibleTransition(L1Cache_State_E_IL0, L1Cache_Event_L0_DataAck);
    possibleTransition(L1Cache_State_M_IL0, L1Cache_Event_L0_Ack);
    possibleTransition(L1Cache_State_MM_IL0, L1Cache_Event_L0_Ack);
    possibleTransition(L1Cache_State_E_IL0, L1Cache_Event_L0_Ack);
    possibleTransition(L1Cache_State_S_IL0, L1Cache_Event_L0_Ack);
    possibleTransition(L1Cache_State_SM_IL0, L1Cache_Event_L0_Ack);
    possibleTransition(L1Cache_State_S_IL0, L1Cache_Event_L0_Invalidate_Own);
    possibleTransition(L1Cache_State_M_IL0, L1Cache_Event_L0_Invalidate_Own);
    possibleTransition(L1Cache_State_E_IL0, L1Cache_Event_L0_Invalidate_Own);
    possibleTransition(L1Cache_State_SM_IL0, L1Cache_Event_L0_Invalidate_Own);
    possibleTransition(L1Cache_State_SM, L1Cache_Event_L0_Invalidate_Own);
    possibleTransition(L1Cache_State_S_IL0, L1Cache_Event_L0_Invalidate_Else);
    possibleTransition(L1Cache_State_M_IL0, L1Cache_Event_L0_Invalidate_Else);
    possibleTransition(L1Cache_State_E_IL0, L1Cache_Event_L0_Invalidate_Else);
    possibleTransition(L1Cache_State_SM_IL0, L1Cache_Event_L0_Invalidate_Else);
    possibleTransition(L1Cache_State_S_IL0, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_S_IL0, L1Cache_Event_Fwd_GETX);
    possibleTransition(L1Cache_State_S_IL0, L1Cache_Event_Fwd_GETS);
    possibleTransition(L1Cache_State_M_IL0, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_M_IL0, L1Cache_Event_Fwd_GETX);
    possibleTransition(L1Cache_State_M_IL0, L1Cache_Event_Fwd_GETS);
    possibleTransition(L1Cache_State_E_IL0, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_E_IL0, L1Cache_Event_Fwd_GETX);
    possibleTransition(L1Cache_State_E_IL0, L1Cache_Event_Fwd_GETS);
    possibleTransition(L1Cache_State_MM_IL0, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_MM_IL0, L1Cache_Event_Fwd_GETX);
    possibleTransition(L1Cache_State_MM_IL0, L1Cache_Event_Fwd_GETS);
    AbstractController::init();
    resetStats();
}

Sequencer*
L1Cache_Controller::getCPUSequencer() const
{
    return NULL;
}

GPUCoalescer*
L1Cache_Controller::getGPUCoalescer() const
{
    return NULL;
}

void
L1Cache_Controller::regStats()
{
    AbstractController::regStats();

    if (m_version == 0) {
        for (L1Cache_Event event = L1Cache_Event_FIRST;
             event < L1Cache_Event_NUM; ++event) {
            Stats::Vector *t = new Stats::Vector();
            t->init(m_num_controllers);
            t->name(params()->ruby_system->name() + ".L1Cache_Controller." +
                L1Cache_Event_to_string(event));
            t->flags(Stats::pdf | Stats::total | Stats::oneline |
                     Stats::nozero);

            eventVec.push_back(t);
        }

        for (L1Cache_State state = L1Cache_State_FIRST;
             state < L1Cache_State_NUM; ++state) {

            transVec.push_back(std::vector<Stats::Vector *>());

            for (L1Cache_Event event = L1Cache_Event_FIRST;
                 event < L1Cache_Event_NUM; ++event) {

                Stats::Vector *t = new Stats::Vector();
                t->init(m_num_controllers);
                t->name(params()->ruby_system->name() + ".L1Cache_Controller." +
                        L1Cache_State_to_string(state) +
                        "." + L1Cache_Event_to_string(event));

                t->flags(Stats::pdf | Stats::total | Stats::oneline |
                         Stats::nozero);
                transVec[state].push_back(t);
            }
        }
    }
}

void
L1Cache_Controller::collateStats()
{
    for (L1Cache_Event event = L1Cache_Event_FIRST;
         event < L1Cache_Event_NUM; ++event) {
        for (unsigned int i = 0; i < m_num_controllers; ++i) {
            RubySystem *rs = params()->ruby_system;
            std::map<uint32_t, AbstractController *>::iterator it =
                     rs->m_abstract_controls[MachineType_L1Cache].find(i);
            assert(it != rs->m_abstract_controls[MachineType_L1Cache].end());
            (*eventVec[event])[i] =
                ((L1Cache_Controller *)(*it).second)->getEventCount(event);
        }
    }

    for (L1Cache_State state = L1Cache_State_FIRST;
         state < L1Cache_State_NUM; ++state) {

        for (L1Cache_Event event = L1Cache_Event_FIRST;
             event < L1Cache_Event_NUM; ++event) {

            for (unsigned int i = 0; i < m_num_controllers; ++i) {
                RubySystem *rs = params()->ruby_system;
                std::map<uint32_t, AbstractController *>::iterator it =
                         rs->m_abstract_controls[MachineType_L1Cache].find(i);
                assert(it != rs->m_abstract_controls[MachineType_L1Cache].end());
                (*transVec[state][event])[i] =
                    ((L1Cache_Controller *)(*it).second)->getTransitionCount(state, event);
            }
        }
    }
}

void
L1Cache_Controller::countTransition(L1Cache_State state, L1Cache_Event event)
{
    assert(m_possible[state][event]);
    m_counters[state][event]++;
    m_event_counters[event]++;
}
void
L1Cache_Controller::possibleTransition(L1Cache_State state,
                             L1Cache_Event event)
{
    m_possible[state][event] = true;
}

uint64_t
L1Cache_Controller::getEventCount(L1Cache_Event event)
{
    return m_event_counters[event];
}

bool
L1Cache_Controller::isPossible(L1Cache_State state, L1Cache_Event event)
{
    return m_possible[state][event];
}

uint64_t
L1Cache_Controller::getTransitionCount(L1Cache_State state,
                             L1Cache_Event event)
{
    return m_counters[state][event];
}

int
L1Cache_Controller::getNumControllers()
{
    return m_num_controllers;
}

MessageBuffer*
L1Cache_Controller::getMandatoryQueue() const
{
    return NULL;
}

MessageBuffer*
L1Cache_Controller::getMemoryQueue() const
{
    return NULL;
}

void
L1Cache_Controller::print(ostream& out) const
{
    out << "[L1Cache_Controller " << m_version << "]";
}

void L1Cache_Controller::resetStats()
{
    for (int state = 0; state < L1Cache_State_NUM; state++) {
        for (int event = 0; event < L1Cache_Event_NUM; event++) {
            m_counters[state][event] = 0;
        }
    }

    for (int event = 0; event < L1Cache_Event_NUM; event++) {
        m_event_counters[event] = 0;
    }

    AbstractController::resetStats();
}

// Set and Reset for cache_entry variable
void
L1Cache_Controller::set_cache_entry(L1Cache_Entry*& m_cache_entry_ptr, AbstractCacheEntry* m_new_cache_entry)
{
  m_cache_entry_ptr = (L1Cache_Entry*)m_new_cache_entry;
}

void
L1Cache_Controller::unset_cache_entry(L1Cache_Entry*& m_cache_entry_ptr)
{
  m_cache_entry_ptr = 0;
}

// Set and Reset for tbe variable
void
L1Cache_Controller::set_tbe(L1Cache_TBE*& m_tbe_ptr, L1Cache_TBE* m_new_tbe)
{
  m_tbe_ptr = m_new_tbe;
}

void
L1Cache_Controller::unset_tbe(L1Cache_TBE*& m_tbe_ptr)
{
  m_tbe_ptr = NULL;
}

void
L1Cache_Controller::recordCacheTrace(int cntrl, CacheRecorder* tr)
{
    m_cache_ptr->recordCacheContents(cntrl, tr);
}

// Actions
/** \brief Issue GETS */
void
L1Cache_Controller::a_issueGETS(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing a_issueGETS\n");
    try {
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
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_GETS;
    (*out_msg).m_Requestor = m_machineID;
    (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, m_clusterID))));
    DPRINTF(RubySlicc, "MESI_Three_Level-L1cache.sm:395: address: %#x, destination: %s\n", addr, (*out_msg).m_Destination);
    (*out_msg).m_MessageSize = MessageSizeType_Control;
    (*out_msg).m_AccessMode = ((*in_msg_ptr)).m_AccessMode;
    ((*m_requestToL2_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l1_request_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:a_issueGETS: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Issue GETX */
void
L1Cache_Controller::b_issueGETX(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing b_issueGETX\n");
    try {
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
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_GETX;
    (*out_msg).m_Requestor = m_machineID;
    DPRINTF(RubySlicc, "MESI_Three_Level-L1cache.sm:409: %s\n", m_machineID);
    (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, m_clusterID))));
    DPRINTF(RubySlicc, "MESI_Three_Level-L1cache.sm:412: address: %#x, destination: %s\n", addr, (*out_msg).m_Destination);
    (*out_msg).m_MessageSize = MessageSizeType_Control;
    (*out_msg).m_AccessMode = ((*in_msg_ptr)).m_AccessMode;
    ((*m_requestToL2_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l1_request_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:b_issueGETX: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Issue GETX */
void
L1Cache_Controller::c_issueUPGRADE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing c_issueUPGRADE\n");
    try {
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
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_UPGRADE;
    (*out_msg).m_Requestor = m_machineID;
    (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, m_clusterID))));
    DPRINTF(RubySlicc, "MESI_Three_Level-L1cache.sm:428: address: %#x, destination: %s\n", addr, (*out_msg).m_Destination);
    (*out_msg).m_MessageSize = MessageSizeType_Control;
    (*out_msg).m_AccessMode = ((*in_msg_ptr)).m_AccessMode;
    ((*m_requestToL2_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l1_request_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:c_issueUPGRADE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief send data to requestor */
void
L1Cache_Controller::d_sendDataToRequestor(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing d_sendDataToRequestor\n");
    try {
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
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_cache_entry_ptr != NULL))) {
        panic("Runtime Error at MESI_Three_Level-L1cache.sm:439: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA;
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (*m_cache_entry_ptr).m_Dirty;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseToL2_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l1_response_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:d_sendDataToRequestor: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief send data to the L2 cache because of M downgrade */
void
L1Cache_Controller::d2_sendDataToL2(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing d2_sendDataToL2\n");
    try {
       {
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_cache_entry_ptr != NULL))) {
        panic("Runtime Error at MESI_Three_Level-L1cache.sm:453: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA;
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (*m_cache_entry_ptr).m_Dirty;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, m_clusterID))));
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseToL2_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l1_response_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:d2_sendDataToL2: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief send data to requestor */
void
L1Cache_Controller::dt_sendDataToRequestor_fromTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing dt_sendDataToRequestor_fromTBE\n");
    try {
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
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_tbe_ptr != NULL))) {
        panic("Runtime Error at MESI_Three_Level-L1cache.sm:468: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA;
    (*out_msg).m_DataBlk = (*m_tbe_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (*m_tbe_ptr).m_Dirty;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseToL2_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l1_response_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:dt_sendDataToRequestor_fromTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief send data to the L2 cache */
void
L1Cache_Controller::d2t_sendDataToL2_fromTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing d2t_sendDataToL2_fromTBE\n");
    try {
       {
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_tbe_ptr != NULL))) {
        panic("Runtime Error at MESI_Three_Level-L1cache.sm:482: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA;
    (*out_msg).m_DataBlk = (*m_tbe_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (*m_tbe_ptr).m_Dirty;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, m_clusterID))));
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseToL2_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l1_response_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:d2t_sendDataToL2_fromTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief send invalidate ack to requestor (could be L2 or L1) */
void
L1Cache_Controller::e_sendAckToRequestor(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing e_sendAckToRequestor\n");
    try {
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
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_ACK;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_MessageSize = MessageSizeType_Response_Control;
    ((*m_responseToL2_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l1_response_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:e_sendAckToRequestor: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief send data to the L2 cache */
void
L1Cache_Controller::f_sendDataToL2(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing f_sendDataToL2\n");
    try {
       {
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_cache_entry_ptr != NULL))) {
        panic("Runtime Error at MESI_Three_Level-L1cache.sm:508: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA;
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (*m_cache_entry_ptr).m_Dirty;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, m_clusterID))));
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Data;
    ((*m_responseToL2_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l1_response_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:f_sendDataToL2: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief send data to the L2 cache */
void
L1Cache_Controller::ft_sendDataToL2_fromTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing ft_sendDataToL2_fromTBE\n");
    try {
       {
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_tbe_ptr != NULL))) {
        panic("Runtime Error at MESI_Three_Level-L1cache.sm:522: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA;
    (*out_msg).m_DataBlk = (*m_tbe_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (*m_tbe_ptr).m_Dirty;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, m_clusterID))));
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Data;
    ((*m_responseToL2_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l1_response_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:ft_sendDataToL2_fromTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief send data to the L2 cache */
void
L1Cache_Controller::fi_sendInvAck(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing fi_sendInvAck\n");
    try {
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
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_ACK;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_MessageSize = MessageSizeType_Response_Control;
    (*out_msg).m_AckCount = (1);
    ((*m_responseToL2_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l1_response_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:fi_sendInvAck: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief sends eviction information to the processor */
void
L1Cache_Controller::forward_eviction_to_L0(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing forward_eviction_to_L0\n");
    try {
       {
    std::shared_ptr<CoherenceMsg> out_msg = std::make_shared<CoherenceMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Class = CoherenceClass_INV;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_Dest = (createMachineID(MachineType_L0Cache, m_version));
    (*out_msg).m_MessageSize = MessageSizeType_Control;
    ((*m_bufferToL0_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l1_request_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:forward_eviction_to_L0: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief send data to the L2 cache */
void
L1Cache_Controller::g_issuePUTX(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing g_issuePUTX\n");
    try {
       {
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_cache_entry_ptr != NULL))) {
        panic("Runtime Error at MESI_Three_Level-L1cache.sm:559: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_PUTX;
    (*out_msg).m_Dirty = (*m_cache_entry_ptr).m_Dirty;
    (*out_msg).m_Requestor = m_machineID;
    (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, m_clusterID))));
        if ((*m_cache_entry_ptr).m_Dirty) {
            (*out_msg).m_MessageSize = MessageSizeType_Writeback_Data;
            (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
        } else {
            (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
        }
        ((*m_requestToL2_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l1_response_latency)));
    }

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:g_issuePUTX: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief send unblock to the L2 cache */
void
L1Cache_Controller::j_sendUnblock(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing j_sendUnblock\n");
    try {
       {
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_UNBLOCK;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, m_clusterID))));
    (*out_msg).m_MessageSize = MessageSizeType_Response_Control;
    DPRINTF(RubySlicc, "MESI_Three_Level-L1cache.sm:583: %#x\n", addr);
    ((*m_unblockToL2_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_to_l2_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:j_sendUnblock: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief send unblock to the L2 cache */
void
L1Cache_Controller::jj_sendExclusiveUnblock(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing jj_sendExclusiveUnblock\n");
    try {
       {
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_EXCLUSIVE_UNBLOCK;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, m_clusterID))));
    (*out_msg).m_MessageSize = MessageSizeType_Response_Control;
    DPRINTF(RubySlicc, "MESI_Three_Level-L1cache.sm:595: %#x\n", addr);
    ((*m_unblockToL2_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_to_l2_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:jj_sendExclusiveUnblock: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief If not prefetch, send data to the L0 cache. */
void
L1Cache_Controller::h_data_to_l0(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing h_data_to_l0\n");
    try {
       {
    std::shared_ptr<CoherenceMsg> out_msg = std::make_shared<CoherenceMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_cache_entry_ptr != NULL))) {
        panic("Runtime Error at MESI_Three_Level-L1cache.sm:602: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Class = CoherenceClass_DATA;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_Dest = (createMachineID(MachineType_L0Cache, m_version));
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_bufferToL0_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l1_response_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:h_data_to_l0: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief If not prefetch, notify sequencer that store completed. */
void
L1Cache_Controller::hh_xdata_to_l0(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing hh_xdata_to_l0\n");
    try {
       {
    std::shared_ptr<CoherenceMsg> out_msg = std::make_shared<CoherenceMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_cache_entry_ptr != NULL))) {
        panic("Runtime Error at MESI_Three_Level-L1cache.sm:615: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Class = CoherenceClass_DATA_EXCLUSIVE;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_Dest = (createMachineID(MachineType_L0Cache, m_version));
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (*m_cache_entry_ptr).m_Dirty;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_bufferToL0_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l1_response_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:hh_xdata_to_l0: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief If not prefetch, send data to the L0 cache. */
void
L1Cache_Controller::h_stale_data_to_l0(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing h_stale_data_to_l0\n");
    try {
       {
    std::shared_ptr<CoherenceMsg> out_msg = std::make_shared<CoherenceMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_cache_entry_ptr != NULL))) {
        panic("Runtime Error at MESI_Three_Level-L1cache.sm:631: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Class = CoherenceClass_STALE_DATA;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_Dest = (createMachineID(MachineType_L0Cache, m_version));
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (*m_cache_entry_ptr).m_Dirty;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_bufferToL0_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l1_response_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:h_stale_data_to_l0: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Allocate TBE (number of invalidates=0) */
void
L1Cache_Controller::i_allocateTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing i_allocateTBE\n");
    try {
       #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MESI_Three_Level-L1cache.sm:645: %s.\n", "assert failure");

}
#endif
;
(((*m_TBEs_ptr)).allocate(addr));
set_tbe(m_tbe_ptr, (((*m_TBEs_ptr)).lookup(addr)));;
(*m_tbe_ptr).m_Dirty = (*m_cache_entry_ptr).m_Dirty;
(*m_tbe_ptr).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:i_allocateTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Pop mandatory queue. */
void
L1Cache_Controller::k_popL0RequestQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing k_popL0RequestQueue\n");
    try {
       (((*m_bufferFromL0_ptr)).dequeue((clockEdge())));

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:k_popL0RequestQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Pop incoming request queue and profile the delay within this virtual network */
void
L1Cache_Controller::l_popL2RequestQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing l_popL2RequestQueue\n");
    try {
       Tick delay
 = (((*m_requestFromL2_ptr)).dequeue((clockEdge())));
(profileMsgDelay((2), (ticksToCycles(delay))));

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:l_popL2RequestQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Pop Incoming Response queue and profile the delay within this virtual network */
void
L1Cache_Controller::o_popL2ResponseQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing o_popL2ResponseQueue\n");
    try {
       Tick delay
 = (((*m_responseFromL2_ptr)).dequeue((clockEdge())));
(profileMsgDelay((1), (ticksToCycles(delay))));

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:o_popL2ResponseQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Deallocate TBE */
void
L1Cache_Controller::s_deallocateTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing s_deallocateTBE\n");
    try {
       (((*m_TBEs_ptr)).deallocate(addr));
unset_tbe(m_tbe_ptr);;

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:s_deallocateTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Write data to cache */
void
L1Cache_Controller::u_writeDataFromL0Request(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing u_writeDataFromL0Request\n");
    try {
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
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MESI_Three_Level-L1cache.sm:675: %s.\n", "assert failure");

}
#endif
;
    if (((*in_msg_ptr)).m_Dirty) {
        (*m_cache_entry_ptr).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
        (*m_cache_entry_ptr).m_Dirty = ((*in_msg_ptr)).m_Dirty;
    }
    }

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:u_writeDataFromL0Request: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Write data to cache */
void
L1Cache_Controller::u_writeDataFromL2Response(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing u_writeDataFromL2Response\n");
    try {
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
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MESI_Three_Level-L1cache.sm:685: %s.\n", "assert failure");

}
#endif
;
(*m_cache_entry_ptr).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:u_writeDataFromL2Response: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Write data to cache */
void
L1Cache_Controller::u_writeDataFromL0Response(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing u_writeDataFromL0Response\n");
    try {
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
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MESI_Three_Level-L1cache.sm:692: %s.\n", "assert failure");

}
#endif
;
    if (((*in_msg_ptr)).m_Dirty) {
        (*m_cache_entry_ptr).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
        (*m_cache_entry_ptr).m_Dirty = ((*in_msg_ptr)).m_Dirty;
    }
    }

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:u_writeDataFromL0Response: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Update ack count */
void
L1Cache_Controller::q_updateAckCount(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing q_updateAckCount\n");
    try {
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
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MESI_Three_Level-L1cache.sm:702: %s.\n", "assert failure");

}
#endif
;
(*m_tbe_ptr).m_pendingAcks = ((*m_tbe_ptr).m_pendingAcks - ((*in_msg_ptr)).m_AckCount);
APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_AckCount);
APPEND_TRANSITION_COMMENT((" p: "));
APPEND_TRANSITION_COMMENT((*m_tbe_ptr).m_pendingAcks);
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:q_updateAckCount: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Deallocate L1 cache block. */
void
L1Cache_Controller::ff_deallocateCacheBlock(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing ff_deallocateCacheBlock\n");
    try {
           if ((((*m_cache_ptr)).isTagPresent(addr))) {
        (((*m_cache_ptr)).deallocate(addr));
    }
    unset_cache_entry(m_cache_entry_ptr);;

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:ff_deallocateCacheBlock: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Set cache tag equal to tag of block B. */
void
L1Cache_Controller::oo_allocateCacheBlock(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing oo_allocateCacheBlock\n");
    try {
           if ((m_cache_entry_ptr == NULL)) {
        set_cache_entry(m_cache_entry_ptr, (((*m_cache_ptr)).allocate(addr, new L1Cache_Entry)));;
    }

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:oo_allocateCacheBlock: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief recycle L0 request queue */
void
L1Cache_Controller::z0_stallAndWaitL0Queue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing z0_stallAndWaitL0Queue\n");
    try {
               stallBuffer(&((*m_bufferFromL0_ptr)), addr);
        (*m_bufferFromL0_ptr).stallMessage(addr, clockEdge());
        

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:z0_stallAndWaitL0Queue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief recycle L2 request queue */
void
L1Cache_Controller::z2_stallAndWaitL2Queue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing z2_stallAndWaitL2Queue\n");
    try {
               stallBuffer(&((*m_requestFromL2_ptr)), addr);
        (*m_requestFromL2_ptr).stallMessage(addr, clockEdge());
        

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:z2_stallAndWaitL2Queue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief wake-up dependents */
void
L1Cache_Controller::kd_wakeUpDependents(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing kd_wakeUpDependents\n");
    try {
       (wakeUpAllBuffers(addr));

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:kd_wakeUpDependents: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Profile the demand miss */
void
L1Cache_Controller::uu_profileMiss(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing uu_profileMiss\n");
    try {
       (++ ((*m_cache_ptr)).m_demand_misses);

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:uu_profileMiss: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Profile the demand hit */
void
L1Cache_Controller::uu_profileHit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing uu_profileHit\n");
    try {
       (++ ((*m_cache_ptr)).m_demand_hits);

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:uu_profileHit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

L1Cache_Entry*
L1Cache_Controller::getCacheEntry(const Addr& param_addr)
{
L1Cache_Entry* cache_entry
 = static_cast<L1Cache_Entry *>((((*m_cache_ptr)).lookup(param_addr)))
;
return cache_entry;

}
L1Cache_State
L1Cache_Controller::getState(L1Cache_TBE* param_tbe, L1Cache_Entry* param_cache_entry, const Addr& param_addr)
{
    if ((param_tbe != NULL)) {
        return (*param_tbe).m_TBEState;
    } else {
            if ((param_cache_entry != NULL)) {
                return (*param_cache_entry).m_CacheState;
            }
        }
        return L1Cache_State_I;

}
void
L1Cache_Controller::setState(L1Cache_TBE* param_tbe, L1Cache_Entry* param_cache_entry, const Addr& param_addr, const L1Cache_State& param_state)
{
    if ((param_tbe != NULL)) {
        (*param_tbe).m_TBEState = param_state;
    }
        if ((param_cache_entry != NULL)) {
            (*param_cache_entry).m_CacheState = param_state;
        }

}
AccessPermission
L1Cache_Controller::getAccessPermission(const Addr& param_addr)
{
L1Cache_TBE* tbe
 = (((*m_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        DPRINTF(RubySlicc, "MESI_Three_Level-L1cache.sm:194: %s\n", (L1Cache_State_to_permission((*tbe).m_TBEState)));
        return (L1Cache_State_to_permission((*tbe).m_TBEState));
    }
    L1Cache_Entry* cache_entry
     = (getCacheEntry(param_addr));
        if ((cache_entry != NULL)) {
            DPRINTF(RubySlicc, "MESI_Three_Level-L1cache.sm:200: %s\n", (L1Cache_State_to_permission((*cache_entry).m_CacheState)));
            return (L1Cache_State_to_permission((*cache_entry).m_CacheState));
        }
        DPRINTF(RubySlicc, "MESI_Three_Level-L1cache.sm:204: %s\n", AccessPermission_NotPresent);
        return AccessPermission_NotPresent;

}
void
L1Cache_Controller::functionalRead(const Addr& param_addr, Packet* param_pkt)
{
L1Cache_TBE* tbe
 = (((*m_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        (testAndRead(param_addr, (*tbe).m_DataBlk, param_pkt));
    } else {
        (testAndRead(param_addr, (*(getCacheEntry(param_addr))).m_DataBlk, param_pkt));
    }

}
int
L1Cache_Controller::functionalWrite(const Addr& param_addr, Packet* param_pkt)
{
int num_functional_writes
 = (0);
L1Cache_TBE* tbe
 = (((*m_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        num_functional_writes = (num_functional_writes + (testAndWrite(param_addr, (*tbe).m_DataBlk, param_pkt)));
        return num_functional_writes;
    }
    num_functional_writes = (num_functional_writes + (testAndWrite(param_addr, (*(getCacheEntry(param_addr))).m_DataBlk, param_pkt)));
    return num_functional_writes;

}
void
L1Cache_Controller::setAccessPermission(L1Cache_Entry* param_cache_entry, const Addr& param_addr, const L1Cache_State& param_state)
{
    if ((param_cache_entry != NULL)) {
        ((*(param_cache_entry)).changePermission((L1Cache_State_to_permission(param_state))));
    }

}
L1Cache_Event
L1Cache_Controller::mandatory_request_type_to_event(const CoherenceClass& param_type)
{
    if ((param_type == CoherenceClass_GETS)) {
        return L1Cache_Event_Load;
    } else {
            if (((param_type == CoherenceClass_GETX) || (param_type == CoherenceClass_UPGRADE))) {
                return L1Cache_Event_Store;
            } else {
                    if ((param_type == CoherenceClass_PUTX)) {
                        return L1Cache_Event_WriteBack;
                    } else {
                        panic("Runtime Error at MESI_Three_Level-L1cache.sm:247: %s.\n", ("Invalid RequestType"));
                        ;
                    }
                }
            }

}
int
L1Cache_Controller::getPendingAcks(L1Cache_TBE* param_tbe)
{
return (*param_tbe).m_pendingAcks;

}
bool
L1Cache_Controller::inL0Cache(const L1Cache_State& param_state)
{
    if ((((((((param_state == L1Cache_State_S) || (param_state == L1Cache_State_E)) || (param_state == L1Cache_State_M)) || (param_state == L1Cache_State_S_IL0)) || (param_state == L1Cache_State_E_IL0)) || (param_state == L1Cache_State_M_IL0)) || (param_state == L1Cache_State_SM_IL0))) {
        return (true);
    }
    return (false);

}
int
L1Cache_Controller::functionalWriteBuffers(PacketPtr& pkt)
{
    int num_functional_writes = 0;
num_functional_writes += m_bufferToL0_ptr->functionalWrite(pkt);
num_functional_writes += m_bufferFromL0_ptr->functionalWrite(pkt);
num_functional_writes += m_requestToL2_ptr->functionalWrite(pkt);
num_functional_writes += m_responseToL2_ptr->functionalWrite(pkt);
num_functional_writes += m_unblockToL2_ptr->functionalWrite(pkt);
num_functional_writes += m_requestFromL2_ptr->functionalWrite(pkt);
num_functional_writes += m_responseFromL2_ptr->functionalWrite(pkt);
    return num_functional_writes;
}
