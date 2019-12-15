/** \file L0Cache_Controller.cc
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/StateMachine.py:465
 * Created by slicc definition of Module "MESI Directory L0 Cache"
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
#include "mem/ruby/protocol/L0Cache_Controller.hh"
#include "mem/ruby/protocol/L0Cache_Event.hh"
#include "mem/ruby/protocol/L0Cache_State.hh"
#include "mem/ruby/protocol/Types.hh"
#include "mem/ruby/system/RubySystem.hh"

#include "mem/ruby/slicc_interface/RubySlicc_includes.hh"

using namespace std;
#include "mem/ruby/protocol/TBETable.hh"
L0Cache_Controller *
L0Cache_ControllerParams::create()
{
    return new L0Cache_Controller(this);
}

int L0Cache_Controller::m_num_controllers = 0;
std::vector<Stats::Vector *>  L0Cache_Controller::eventVec;
std::vector<std::vector<Stats::Vector *> >  L0Cache_Controller::transVec;

// for adding information to the protocol debug trace
stringstream L0Cache_transitionComment;

#ifndef NDEBUG
#define APPEND_TRANSITION_COMMENT(str) (L0Cache_transitionComment << str)
#else
#define APPEND_TRANSITION_COMMENT(str) do {} while (0)
#endif

/** \brief constructor */
L0Cache_Controller::L0Cache_Controller(const Params *p)
    : AbstractController(p)
{
    m_machineID.type = MachineType_L0Cache;
    m_machineID.num = m_version;
    m_num_controllers++;

    m_in_ports = 2;
    m_sequencer_ptr = p->sequencer;
    if (m_sequencer_ptr != NULL) {
        m_sequencer_ptr->setController(this);
    }
    m_Icache_ptr = p->Icache;
    m_Dcache_ptr = p->Dcache;
    m_request_latency = p->request_latency;
    m_response_latency = p->response_latency;
    m_send_evictions = p->send_evictions;
    m_bufferToL1_ptr = p->bufferToL1;
    m_bufferFromL1_ptr = p->bufferFromL1;
    m_mandatoryQueue_ptr = p->mandatoryQueue;

    for (int state = 0; state < L0Cache_State_NUM; state++) {
        for (int event = 0; event < L0Cache_Event_NUM; event++) {
            m_possible[state][event] = false;
            m_counters[state][event] = 0;
        }
    }
    for (int event = 0; event < L0Cache_Event_NUM; event++) {
        m_event_counters[event] = 0;
    }
}

void
L0Cache_Controller::initNetQueues()
{
    MachineType machine_type = string_to_MachineType("L0Cache");
    int base M5_VAR_USED = MachineType_base_number(machine_type);

    assert(m_bufferToL1_ptr != NULL);
    assert(m_bufferFromL1_ptr != NULL);
}

void
L0Cache_Controller::init()
{
    // initialize objects
    m_TBEs_ptr  = new TBETable<L0Cache_TBE>(m_number_of_TBEs);
    assert(m_TBEs_ptr != NULL);


    (*m_bufferFromL1_ptr).setConsumer(this);
    (*m_mandatoryQueue_ptr).setConsumer(this);

    possibleTransition(L0Cache_State_Inst_IS, L0Cache_Event_Load);
    possibleTransition(L0Cache_State_Inst_IS, L0Cache_Event_Ifetch);
    possibleTransition(L0Cache_State_Inst_IS, L0Cache_Event_Store);
    possibleTransition(L0Cache_State_Inst_IS, L0Cache_Event_L0_Replacement);
    possibleTransition(L0Cache_State_IS, L0Cache_Event_Load);
    possibleTransition(L0Cache_State_IS, L0Cache_Event_Ifetch);
    possibleTransition(L0Cache_State_IS, L0Cache_Event_Store);
    possibleTransition(L0Cache_State_IS, L0Cache_Event_L0_Replacement);
    possibleTransition(L0Cache_State_IM, L0Cache_Event_Load);
    possibleTransition(L0Cache_State_IM, L0Cache_Event_Ifetch);
    possibleTransition(L0Cache_State_IM, L0Cache_Event_Store);
    possibleTransition(L0Cache_State_IM, L0Cache_Event_L0_Replacement);
    possibleTransition(L0Cache_State_SM, L0Cache_Event_Load);
    possibleTransition(L0Cache_State_SM, L0Cache_Event_Ifetch);
    possibleTransition(L0Cache_State_SM, L0Cache_Event_Store);
    possibleTransition(L0Cache_State_SM, L0Cache_Event_L0_Replacement);
    possibleTransition(L0Cache_State_I, L0Cache_Event_Load);
    possibleTransition(L0Cache_State_I, L0Cache_Event_Ifetch);
    possibleTransition(L0Cache_State_I, L0Cache_Event_Store);
    possibleTransition(L0Cache_State_I, L0Cache_Event_Inv);
    possibleTransition(L0Cache_State_IS, L0Cache_Event_Inv);
    possibleTransition(L0Cache_State_IM, L0Cache_Event_Inv);
    possibleTransition(L0Cache_State_Inst_IS, L0Cache_Event_Inv);
    possibleTransition(L0Cache_State_SM, L0Cache_Event_Inv);
    possibleTransition(L0Cache_State_S, L0Cache_Event_Load);
    possibleTransition(L0Cache_State_E, L0Cache_Event_Load);
    possibleTransition(L0Cache_State_M, L0Cache_Event_Load);
    possibleTransition(L0Cache_State_S, L0Cache_Event_Ifetch);
    possibleTransition(L0Cache_State_E, L0Cache_Event_Ifetch);
    possibleTransition(L0Cache_State_M, L0Cache_Event_Ifetch);
    possibleTransition(L0Cache_State_S, L0Cache_Event_Store);
    possibleTransition(L0Cache_State_S, L0Cache_Event_L0_Replacement);
    possibleTransition(L0Cache_State_S, L0Cache_Event_Inv);
    possibleTransition(L0Cache_State_E, L0Cache_Event_Store);
    possibleTransition(L0Cache_State_M, L0Cache_Event_Store);
    possibleTransition(L0Cache_State_E, L0Cache_Event_L0_Replacement);
    possibleTransition(L0Cache_State_E, L0Cache_Event_Inv);
    possibleTransition(L0Cache_State_E, L0Cache_Event_Fwd_GETX);
    possibleTransition(L0Cache_State_E, L0Cache_Event_Fwd_GETS);
    possibleTransition(L0Cache_State_E, L0Cache_Event_Fwd_GET_INSTR);
    possibleTransition(L0Cache_State_M, L0Cache_Event_L0_Replacement);
    possibleTransition(L0Cache_State_M, L0Cache_Event_Inv);
    possibleTransition(L0Cache_State_M, L0Cache_Event_Fwd_GETX);
    possibleTransition(L0Cache_State_M, L0Cache_Event_Fwd_GETS);
    possibleTransition(L0Cache_State_M, L0Cache_Event_Fwd_GET_INSTR);
    possibleTransition(L0Cache_State_IS, L0Cache_Event_Data);
    possibleTransition(L0Cache_State_IS, L0Cache_Event_Data_Exclusive);
    possibleTransition(L0Cache_State_IS, L0Cache_Event_Data_Stale);
    possibleTransition(L0Cache_State_Inst_IS, L0Cache_Event_Data);
    possibleTransition(L0Cache_State_Inst_IS, L0Cache_Event_Data_Exclusive);
    possibleTransition(L0Cache_State_Inst_IS, L0Cache_Event_Data_Stale);
    possibleTransition(L0Cache_State_IM, L0Cache_Event_Data_Exclusive);
    possibleTransition(L0Cache_State_SM, L0Cache_Event_Data_Exclusive);
    AbstractController::init();
    resetStats();
}
Sequencer*
L0Cache_Controller::getCPUSequencer() const
{
    if (NULL != m_sequencer_ptr && m_sequencer_ptr->isCPUSequencer()) {
        return m_sequencer_ptr;
    } else {
        return NULL;
    }
}

GPUCoalescer*
L0Cache_Controller::getGPUCoalescer() const
{
    return NULL;
}

void
L0Cache_Controller::regStats()
{
    AbstractController::regStats();

    if (m_version == 0) {
        for (L0Cache_Event event = L0Cache_Event_FIRST;
             event < L0Cache_Event_NUM; ++event) {
            Stats::Vector *t = new Stats::Vector();
            t->init(m_num_controllers);
            t->name(params()->ruby_system->name() + ".L0Cache_Controller." +
                L0Cache_Event_to_string(event));
            t->flags(Stats::pdf | Stats::total | Stats::oneline |
                     Stats::nozero);

            eventVec.push_back(t);
        }

        for (L0Cache_State state = L0Cache_State_FIRST;
             state < L0Cache_State_NUM; ++state) {

            transVec.push_back(std::vector<Stats::Vector *>());

            for (L0Cache_Event event = L0Cache_Event_FIRST;
                 event < L0Cache_Event_NUM; ++event) {

                Stats::Vector *t = new Stats::Vector();
                t->init(m_num_controllers);
                t->name(params()->ruby_system->name() + ".L0Cache_Controller." +
                        L0Cache_State_to_string(state) +
                        "." + L0Cache_Event_to_string(event));

                t->flags(Stats::pdf | Stats::total | Stats::oneline |
                         Stats::nozero);
                transVec[state].push_back(t);
            }
        }
    }
}

void
L0Cache_Controller::collateStats()
{
    for (L0Cache_Event event = L0Cache_Event_FIRST;
         event < L0Cache_Event_NUM; ++event) {
        for (unsigned int i = 0; i < m_num_controllers; ++i) {
            RubySystem *rs = params()->ruby_system;
            std::map<uint32_t, AbstractController *>::iterator it =
                     rs->m_abstract_controls[MachineType_L0Cache].find(i);
            assert(it != rs->m_abstract_controls[MachineType_L0Cache].end());
            (*eventVec[event])[i] =
                ((L0Cache_Controller *)(*it).second)->getEventCount(event);
        }
    }

    for (L0Cache_State state = L0Cache_State_FIRST;
         state < L0Cache_State_NUM; ++state) {

        for (L0Cache_Event event = L0Cache_Event_FIRST;
             event < L0Cache_Event_NUM; ++event) {

            for (unsigned int i = 0; i < m_num_controllers; ++i) {
                RubySystem *rs = params()->ruby_system;
                std::map<uint32_t, AbstractController *>::iterator it =
                         rs->m_abstract_controls[MachineType_L0Cache].find(i);
                assert(it != rs->m_abstract_controls[MachineType_L0Cache].end());
                (*transVec[state][event])[i] =
                    ((L0Cache_Controller *)(*it).second)->getTransitionCount(state, event);
            }
        }
    }
}

void
L0Cache_Controller::countTransition(L0Cache_State state, L0Cache_Event event)
{
    assert(m_possible[state][event]);
    m_counters[state][event]++;
    m_event_counters[event]++;
}
void
L0Cache_Controller::possibleTransition(L0Cache_State state,
                             L0Cache_Event event)
{
    m_possible[state][event] = true;
}

uint64_t
L0Cache_Controller::getEventCount(L0Cache_Event event)
{
    return m_event_counters[event];
}

bool
L0Cache_Controller::isPossible(L0Cache_State state, L0Cache_Event event)
{
    return m_possible[state][event];
}

uint64_t
L0Cache_Controller::getTransitionCount(L0Cache_State state,
                             L0Cache_Event event)
{
    return m_counters[state][event];
}

int
L0Cache_Controller::getNumControllers()
{
    return m_num_controllers;
}

MessageBuffer*
L0Cache_Controller::getMandatoryQueue() const
{
    return m_mandatoryQueue_ptr;
}

MessageBuffer*
L0Cache_Controller::getMemoryQueue() const
{
    return NULL;
}

void
L0Cache_Controller::print(ostream& out) const
{
    out << "[L0Cache_Controller " << m_version << "]";
}

void L0Cache_Controller::resetStats()
{
    for (int state = 0; state < L0Cache_State_NUM; state++) {
        for (int event = 0; event < L0Cache_Event_NUM; event++) {
            m_counters[state][event] = 0;
        }
    }

    for (int event = 0; event < L0Cache_Event_NUM; event++) {
        m_event_counters[event] = 0;
    }

    AbstractController::resetStats();
}

// Set and Reset for cache_entry variable
void
L0Cache_Controller::set_cache_entry(L0Cache_Entry*& m_cache_entry_ptr, AbstractCacheEntry* m_new_cache_entry)
{
  m_cache_entry_ptr = (L0Cache_Entry*)m_new_cache_entry;
}

void
L0Cache_Controller::unset_cache_entry(L0Cache_Entry*& m_cache_entry_ptr)
{
  m_cache_entry_ptr = 0;
}

// Set and Reset for tbe variable
void
L0Cache_Controller::set_tbe(L0Cache_TBE*& m_tbe_ptr, L0Cache_TBE* m_new_tbe)
{
  m_tbe_ptr = m_new_tbe;
}

void
L0Cache_Controller::unset_tbe(L0Cache_TBE*& m_tbe_ptr)
{
  m_tbe_ptr = NULL;
}

void
L0Cache_Controller::recordCacheTrace(int cntrl, CacheRecorder* tr)
{
    m_Icache_ptr->recordCacheContents(cntrl, tr);
    m_Dcache_ptr->recordCacheContents(cntrl, tr);
}

// Actions
/** \brief Issue GETS */
void
L0Cache_Controller::a_issueGETS(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing a_issueGETS\n");
    try {
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
{
    std::shared_ptr<CoherenceMsg> out_msg = std::make_shared<CoherenceMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Class = CoherenceClass_GETS;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_Dest = (createMachineID(MachineType_L1Cache, m_version));
    DPRINTF(RubySlicc, "MESI_Three_Level-L0cache.sm:381: address: %#x, destination: %s\n", addr, (*out_msg).m_Dest);
    (*out_msg).m_MessageSize = MessageSizeType_Control;
    (*out_msg).m_AccessMode = ((*in_msg_ptr)).m_AccessMode;
    ((*m_bufferToL1_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:a_issueGETS: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Issue GETX */
void
L0Cache_Controller::b_issueGETX(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing b_issueGETX\n");
    try {
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
{
    std::shared_ptr<CoherenceMsg> out_msg = std::make_shared<CoherenceMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Class = CoherenceClass_GETX;
    (*out_msg).m_Sender = m_machineID;
    DPRINTF(RubySlicc, "MESI_Three_Level-L0cache.sm:395: %s\n", m_machineID);
    (*out_msg).m_Dest = (createMachineID(MachineType_L1Cache, m_version));
    DPRINTF(RubySlicc, "MESI_Three_Level-L0cache.sm:398: address: %#x, destination: %s\n", addr, (*out_msg).m_Dest);
    (*out_msg).m_MessageSize = MessageSizeType_Control;
    (*out_msg).m_AccessMode = ((*in_msg_ptr)).m_AccessMode;
    ((*m_bufferToL1_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:b_issueGETX: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Issue GETX */
void
L0Cache_Controller::c_issueUPGRADE(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing c_issueUPGRADE\n");
    try {
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
{
    std::shared_ptr<CoherenceMsg> out_msg = std::make_shared<CoherenceMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Class = CoherenceClass_UPGRADE;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_Dest = (createMachineID(MachineType_L1Cache, m_version));
    DPRINTF(RubySlicc, "MESI_Three_Level-L0cache.sm:414: address: %#x, destination: %s\n", addr, (*out_msg).m_Dest);
    (*out_msg).m_MessageSize = MessageSizeType_Control;
    (*out_msg).m_AccessMode = ((*in_msg_ptr)).m_AccessMode;
    ((*m_bufferToL1_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:c_issueUPGRADE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief send data to the L2 cache */
void
L0Cache_Controller::f_sendDataToL1(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing f_sendDataToL1\n");
    try {
       {
    std::shared_ptr<CoherenceMsg> out_msg = std::make_shared<CoherenceMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_cache_entry_ptr != NULL))) {
        panic("Runtime Error at MESI_Three_Level-L0cache.sm:424: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Class = CoherenceClass_INV_DATA;
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (*m_cache_entry_ptr).m_Dirty;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_Dest = (createMachineID(MachineType_L1Cache, m_version));
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Data;
    ((*m_bufferToL1_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}
(*m_cache_entry_ptr).m_Dirty = (false);

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:f_sendDataToL1: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief send data to the L2 cache */
void
L0Cache_Controller::fi_sendInvAck(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing fi_sendInvAck\n");
    try {
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
{
    std::shared_ptr<CoherenceMsg> out_msg = std::make_shared<CoherenceMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Class = CoherenceClass_INV_ACK;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_Dest = (createMachineID(MachineType_L1Cache, m_version));
    (*out_msg).m_MessageSize = MessageSizeType_Response_Control;
    ((*m_bufferToL1_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:fi_sendInvAck: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief sends eviction information to the processor */
void
L0Cache_Controller::forward_eviction_to_cpu(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing forward_eviction_to_cpu\n");
    try {
           if (m_send_evictions) {
        DPRINTF(RubySlicc, "MESI_Three_Level-L0cache.sm:450: Sending invalidation for %#x to the CPU\n", addr);
        (((*m_sequencer_ptr)).evictionCallback(addr));
    }

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:forward_eviction_to_cpu: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief send data to the L2 cache */
void
L0Cache_Controller::g_issuePUTX(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing g_issuePUTX\n");
    try {
       {
    std::shared_ptr<CoherenceMsg> out_msg = std::make_shared<CoherenceMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_cache_entry_ptr != NULL))) {
        panic("Runtime Error at MESI_Three_Level-L0cache.sm:457: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Class = CoherenceClass_PUTX;
    (*out_msg).m_Dirty = (*m_cache_entry_ptr).m_Dirty;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_Dest = (createMachineID(MachineType_L1Cache, m_version));
        if ((*m_cache_entry_ptr).m_Dirty) {
            (*out_msg).m_MessageSize = MessageSizeType_Writeback_Data;
            (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
        } else {
            (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
        }
        ((*m_bufferToL1_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
    }

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:g_issuePUTX: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief If not prefetch, notify sequencer the load completed. */
void
L0Cache_Controller::h_load_hit(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing h_load_hit\n");
    try {
       #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MESI_Three_Level-L0cache.sm:474: %s.\n", "assert failure");

}
#endif
;
DPRINTF(RubySlicc, "MESI_Three_Level-L0cache.sm:475: %s\n", (*m_cache_entry_ptr).m_DataBlk);
(((*m_Dcache_ptr)).setMRU(m_cache_entry_ptr));
(((*m_sequencer_ptr)).readCallback(addr, (*m_cache_entry_ptr).m_DataBlk));

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:h_load_hit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief If not prefetch, notify sequencer the ifetch completed. */
void
L0Cache_Controller::h_ifetch_hit(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing h_ifetch_hit\n");
    try {
       #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MESI_Three_Level-L0cache.sm:481: %s.\n", "assert failure");

}
#endif
;
DPRINTF(RubySlicc, "MESI_Three_Level-L0cache.sm:482: %s\n", (*m_cache_entry_ptr).m_DataBlk);
(((*m_Icache_ptr)).setMRU(m_cache_entry_ptr));
(((*m_sequencer_ptr)).readCallback(addr, (*m_cache_entry_ptr).m_DataBlk));

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:h_ifetch_hit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief notify sequencer the load completed. */
void
L0Cache_Controller::hx_load_hit(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing hx_load_hit\n");
    try {
       #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MESI_Three_Level-L0cache.sm:488: %s.\n", "assert failure");

}
#endif
;
DPRINTF(RubySlicc, "MESI_Three_Level-L0cache.sm:489: %s\n", (*m_cache_entry_ptr).m_DataBlk);
(((*m_Dcache_ptr)).setMRU(m_cache_entry_ptr));
(((*m_sequencer_ptr)).readCallback(addr, (*m_cache_entry_ptr).m_DataBlk, (true)));

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:hx_load_hit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief notify sequencer the ifetch completed. */
void
L0Cache_Controller::hx_ifetch_hit(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing hx_ifetch_hit\n");
    try {
       #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MESI_Three_Level-L0cache.sm:495: %s.\n", "assert failure");

}
#endif
;
DPRINTF(RubySlicc, "MESI_Three_Level-L0cache.sm:496: %s\n", (*m_cache_entry_ptr).m_DataBlk);
(((*m_Icache_ptr)).setMRU(m_cache_entry_ptr));
(((*m_sequencer_ptr)).readCallback(addr, (*m_cache_entry_ptr).m_DataBlk, (true)));

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:hx_ifetch_hit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief If not prefetch, notify sequencer that store completed. */
void
L0Cache_Controller::hh_store_hit(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing hh_store_hit\n");
    try {
       #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MESI_Three_Level-L0cache.sm:502: %s.\n", "assert failure");

}
#endif
;
DPRINTF(RubySlicc, "MESI_Three_Level-L0cache.sm:503: %s\n", (*m_cache_entry_ptr).m_DataBlk);
(((*m_Dcache_ptr)).setMRU(m_cache_entry_ptr));
(((*m_sequencer_ptr)).writeCallback(addr, (*m_cache_entry_ptr).m_DataBlk));
(*m_cache_entry_ptr).m_Dirty = (true);

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:hh_store_hit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief If not prefetch, notify sequencer that store completed. */
void
L0Cache_Controller::hhx_store_hit(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing hhx_store_hit\n");
    try {
       #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MESI_Three_Level-L0cache.sm:510: %s.\n", "assert failure");

}
#endif
;
DPRINTF(RubySlicc, "MESI_Three_Level-L0cache.sm:511: %s\n", (*m_cache_entry_ptr).m_DataBlk);
(((*m_Dcache_ptr)).setMRU(m_cache_entry_ptr));
(((*m_sequencer_ptr)).writeCallback(addr, (*m_cache_entry_ptr).m_DataBlk, (true)));
(*m_cache_entry_ptr).m_Dirty = (true);

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:hhx_store_hit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Allocate TBE (number of invalidates=0) */
void
L0Cache_Controller::i_allocateTBE(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing i_allocateTBE\n");
    try {
       #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MESI_Three_Level-L0cache.sm:519: %s.\n", "assert failure");

}
#endif
;
(((*m_TBEs_ptr)).allocate(addr));
set_tbe(m_tbe_ptr, (((*m_TBEs_ptr)).lookup(addr)));;
(*m_tbe_ptr).m_Dirty = (*m_cache_entry_ptr).m_Dirty;
(*m_tbe_ptr).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:i_allocateTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Pop mandatory queue. */
void
L0Cache_Controller::k_popMandatoryQueue(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing k_popMandatoryQueue\n");
    try {
       (((*m_mandatoryQueue_ptr)).dequeue((clockEdge())));

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:k_popMandatoryQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Pop incoming request queue and profile the delay within this virtual network */
void
L0Cache_Controller::l_popRequestQueue(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing l_popRequestQueue\n");
    try {
       Tick delay
 = (((*m_bufferFromL1_ptr)).dequeue((clockEdge())));
(profileMsgDelay((2), (ticksToCycles(delay))));

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:l_popRequestQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Pop Incoming Response queue and profile the delay within this virtual network */
void
L0Cache_Controller::o_popIncomingResponseQueue(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing o_popIncomingResponseQueue\n");
    try {
       Tick delay
 = (((*m_bufferFromL1_ptr)).dequeue((clockEdge())));
(profileMsgDelay((1), (ticksToCycles(delay))));

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:o_popIncomingResponseQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Deallocate TBE */
void
L0Cache_Controller::s_deallocateTBE(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing s_deallocateTBE\n");
    try {
       (((*m_TBEs_ptr)).deallocate(addr));
unset_tbe(m_tbe_ptr);;

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:s_deallocateTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Write data to cache */
void
L0Cache_Controller::u_writeDataToCache(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing u_writeDataToCache\n");
    try {
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
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MESI_Three_Level-L0cache.sm:549: %s.\n", "assert failure");

}
#endif
;
(*m_cache_entry_ptr).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
}

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:u_writeDataToCache: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Write data to cache */
void
L0Cache_Controller::u_writeInstToCache(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing u_writeInstToCache\n");
    try {
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
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MESI_Three_Level-L0cache.sm:556: %s.\n", "assert failure");

}
#endif
;
(*m_cache_entry_ptr).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
}

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:u_writeInstToCache: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Deallocate L1 cache block. */
void
L0Cache_Controller::ff_deallocateCacheBlock(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing ff_deallocateCacheBlock\n");
    try {
           if ((((*m_Dcache_ptr)).isTagPresent(addr))) {
        (((*m_Dcache_ptr)).deallocate(addr));
    } else {
        (((*m_Icache_ptr)).deallocate(addr));
    }
    unset_cache_entry(m_cache_entry_ptr);;

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:ff_deallocateCacheBlock: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Set L1 D-cache tag equal to tag of block B. */
void
L0Cache_Controller::oo_allocateDCacheBlock(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing oo_allocateDCacheBlock\n");
    try {
           if ((m_cache_entry_ptr == NULL)) {
        set_cache_entry(m_cache_entry_ptr, (((*m_Dcache_ptr)).allocate(addr, new L0Cache_Entry)));;
    }

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:oo_allocateDCacheBlock: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Set L1 I-cache tag equal to tag of block B. */
void
L0Cache_Controller::pp_allocateICacheBlock(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing pp_allocateICacheBlock\n");
    try {
           if ((m_cache_entry_ptr == NULL)) {
        set_cache_entry(m_cache_entry_ptr, (((*m_Icache_ptr)).allocate(addr, new L0Cache_Entry)));;
    }

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:pp_allocateICacheBlock: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief recycle cpu request queue */
void
L0Cache_Controller::z_stallAndWaitMandatoryQueue(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing z_stallAndWaitMandatoryQueue\n");
    try {
               stallBuffer(&((*m_mandatoryQueue_ptr)), addr);
        (*m_mandatoryQueue_ptr).stallMessage(addr, clockEdge());
        

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:z_stallAndWaitMandatoryQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief wake-up dependents */
void
L0Cache_Controller::kd_wakeUpDependents(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing kd_wakeUpDependents\n");
    try {
       (wakeUpAllBuffers(addr));

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:kd_wakeUpDependents: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Profile the demand miss */
void
L0Cache_Controller::uu_profileInstMiss(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing uu_profileInstMiss\n");
    try {
       (++ ((*m_Icache_ptr)).m_demand_misses);

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:uu_profileInstMiss: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Profile the demand miss */
void
L0Cache_Controller::uu_profileInstHit(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing uu_profileInstHit\n");
    try {
       (++ ((*m_Icache_ptr)).m_demand_hits);

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:uu_profileInstHit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Profile the demand miss */
void
L0Cache_Controller::uu_profileDataMiss(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing uu_profileDataMiss\n");
    try {
       (++ ((*m_Dcache_ptr)).m_demand_misses);

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:uu_profileDataMiss: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Profile the demand miss */
void
L0Cache_Controller::uu_profileDataHit(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing uu_profileDataHit\n");
    try {
       (++ ((*m_Dcache_ptr)).m_demand_hits);

    } catch (const RejectException & e) {
       fatal("Error in action L0Cache:uu_profileDataHit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

L0Cache_Entry*
L0Cache_Controller::getCacheEntry(const Addr& param_addr)
{
L0Cache_Entry* Dcache_entry
 = static_cast<L0Cache_Entry *>((((*m_Dcache_ptr)).lookup(param_addr)))
;
    if ((Dcache_entry != NULL)) {
        return Dcache_entry;
    }
    L0Cache_Entry* Icache_entry
     = static_cast<L0Cache_Entry *>((((*m_Icache_ptr)).lookup(param_addr)))
    ;
    return Icache_entry;

}
L0Cache_Entry*
L0Cache_Controller::getDCacheEntry(const Addr& param_addr)
{
L0Cache_Entry* Dcache_entry
 = static_cast<L0Cache_Entry *>((((*m_Dcache_ptr)).lookup(param_addr)))
;
return Dcache_entry;

}
L0Cache_Entry*
L0Cache_Controller::getICacheEntry(const Addr& param_addr)
{
L0Cache_Entry* Icache_entry
 = static_cast<L0Cache_Entry *>((((*m_Icache_ptr)).lookup(param_addr)))
;
return Icache_entry;

}
L0Cache_State
L0Cache_Controller::getState(L0Cache_TBE* param_tbe, L0Cache_Entry* param_cache_entry, const Addr& param_addr)
{
#ifndef NDEBUG
if (!((((((*m_Dcache_ptr)).isTagPresent(param_addr)) && (((*m_Icache_ptr)).isTagPresent(param_addr))) == (false)))) {
    panic("Runtime Error at MESI_Three_Level-L0cache.sm:171: %s.\n", "assert failure");

}
#endif
;
    if ((param_tbe != NULL)) {
        return (*param_tbe).m_TBEState;
    } else {
            if ((param_cache_entry != NULL)) {
                return (*param_cache_entry).m_CacheState;
            }
        }
        return L0Cache_State_I;

}
void
L0Cache_Controller::setState(L0Cache_TBE* param_tbe, L0Cache_Entry* param_cache_entry, const Addr& param_addr, const L0Cache_State& param_state)
{
#ifndef NDEBUG
if (!((((((*m_Dcache_ptr)).isTagPresent(param_addr)) && (((*m_Icache_ptr)).isTagPresent(param_addr))) == (false)))) {
    panic("Runtime Error at MESI_Three_Level-L0cache.sm:182: %s.\n", "assert failure");

}
#endif
;
    if ((param_tbe != NULL)) {
        (*param_tbe).m_TBEState = param_state;
    }
        if ((param_cache_entry != NULL)) {
            (*param_cache_entry).m_CacheState = param_state;
        }

}
AccessPermission
L0Cache_Controller::getAccessPermission(const Addr& param_addr)
{
L0Cache_TBE* tbe
 = (((*m_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        DPRINTF(RubySlicc, "MESI_Three_Level-L0cache.sm:197: %s\n", (L0Cache_State_to_permission((*tbe).m_TBEState)));
        return (L0Cache_State_to_permission((*tbe).m_TBEState));
    }
    L0Cache_Entry* cache_entry
     = (getCacheEntry(param_addr));
        if ((cache_entry != NULL)) {
            DPRINTF(RubySlicc, "MESI_Three_Level-L0cache.sm:203: %s\n", (L0Cache_State_to_permission((*cache_entry).m_CacheState)));
            return (L0Cache_State_to_permission((*cache_entry).m_CacheState));
        }
        DPRINTF(RubySlicc, "MESI_Three_Level-L0cache.sm:207: %s\n", AccessPermission_NotPresent);
        return AccessPermission_NotPresent;

}
void
L0Cache_Controller::functionalRead(const Addr& param_addr, Packet* param_pkt)
{
L0Cache_TBE* tbe
 = (((*m_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        (testAndRead(param_addr, (*tbe).m_DataBlk, param_pkt));
    } else {
        (testAndRead(param_addr, (*(getCacheEntry(param_addr))).m_DataBlk, param_pkt));
    }

}
int
L0Cache_Controller::functionalWrite(const Addr& param_addr, Packet* param_pkt)
{
int num_functional_writes
 = (0);
L0Cache_TBE* tbe
 = (((*m_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        num_functional_writes = (num_functional_writes + (testAndWrite(param_addr, (*tbe).m_DataBlk, param_pkt)));
        return num_functional_writes;
    }
    num_functional_writes = (num_functional_writes + (testAndWrite(param_addr, (*(getCacheEntry(param_addr))).m_DataBlk, param_pkt)));
    return num_functional_writes;

}
void
L0Cache_Controller::setAccessPermission(L0Cache_Entry* param_cache_entry, const Addr& param_addr, const L0Cache_State& param_state)
{
    if ((param_cache_entry != NULL)) {
        ((*(param_cache_entry)).changePermission((L0Cache_State_to_permission(param_state))));
    }

}
L0Cache_Event
L0Cache_Controller::mandatory_request_type_to_event(const RubyRequestType& param_type)
{
    if ((param_type == RubyRequestType_LD)) {
        return L0Cache_Event_Load;
    } else {
            if ((param_type == RubyRequestType_IFETCH)) {
                return L0Cache_Event_Ifetch;
            } else {
                    if (((param_type == RubyRequestType_ST) || (param_type == RubyRequestType_ATOMIC))) {
                        return L0Cache_Event_Store;
                    } else {
                        panic("Runtime Error at MESI_Three_Level-L0cache.sm:249: %s.\n", ("Invalid RubyRequestType"));
                        ;
                    }
                }
            }

}
int
L0Cache_Controller::getPendingAcks(L0Cache_TBE* param_tbe)
{
return (*param_tbe).m_pendingAcks;

}
int
L0Cache_Controller::functionalWriteBuffers(PacketPtr& pkt)
{
    int num_functional_writes = 0;
num_functional_writes += m_bufferToL1_ptr->functionalWrite(pkt);
num_functional_writes += m_bufferFromL1_ptr->functionalWrite(pkt);
num_functional_writes += m_mandatoryQueue_ptr->functionalWrite(pkt);
    return num_functional_writes;
}
