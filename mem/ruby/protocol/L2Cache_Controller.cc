/** \file L2Cache_Controller.cc
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/StateMachine.py:465
 * Created by slicc definition of Module "MESI Directory L2 Cache CMP"
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
#include "mem/ruby/protocol/L2Cache_Controller.hh"
#include "mem/ruby/protocol/L2Cache_Event.hh"
#include "mem/ruby/protocol/L2Cache_State.hh"
#include "mem/ruby/protocol/Types.hh"
#include "mem/ruby/system/RubySystem.hh"

#include "mem/ruby/slicc_interface/RubySlicc_includes.hh"

using namespace std;
#include "mem/ruby/protocol/TBETable.hh"
L2Cache_Controller *
L2Cache_ControllerParams::create()
{
    return new L2Cache_Controller(this);
}

int L2Cache_Controller::m_num_controllers = 0;
std::vector<Stats::Vector *>  L2Cache_Controller::eventVec;
std::vector<std::vector<Stats::Vector *> >  L2Cache_Controller::transVec;

// for adding information to the protocol debug trace
stringstream L2Cache_transitionComment;

#ifndef NDEBUG
#define APPEND_TRANSITION_COMMENT(str) (L2Cache_transitionComment << str)
#else
#define APPEND_TRANSITION_COMMENT(str) do {} while (0)
#endif

/** \brief constructor */
L2Cache_Controller::L2Cache_Controller(const Params *p)
    : AbstractController(p)
{
    m_machineID.type = MachineType_L2Cache;
    m_machineID.num = m_version;
    m_num_controllers++;

    m_in_ports = 3;
    m_L2cache_ptr = p->L2cache;
    m_l2_request_latency = p->l2_request_latency;
    m_l2_response_latency = p->l2_response_latency;
    m_to_l1_latency = p->to_l1_latency;
    m_DirRequestFromL2Cache_ptr = p->DirRequestFromL2Cache;
    m_L1RequestFromL2Cache_ptr = p->L1RequestFromL2Cache;
    m_responseFromL2Cache_ptr = p->responseFromL2Cache;
    m_unblockToL2Cache_ptr = p->unblockToL2Cache;
    m_L1RequestToL2Cache_ptr = p->L1RequestToL2Cache;
    m_responseToL2Cache_ptr = p->responseToL2Cache;

    for (int state = 0; state < L2Cache_State_NUM; state++) {
        for (int event = 0; event < L2Cache_Event_NUM; event++) {
            m_possible[state][event] = false;
            m_counters[state][event] = 0;
        }
    }
    for (int event = 0; event < L2Cache_Event_NUM; event++) {
        m_event_counters[event] = 0;
    }
}

void
L2Cache_Controller::initNetQueues()
{
    MachineType machine_type = string_to_MachineType("L2Cache");
    int base M5_VAR_USED = MachineType_base_number(machine_type);

    assert(m_DirRequestFromL2Cache_ptr != NULL);
    m_net_ptr->setToNetQueue(m_version + base, m_DirRequestFromL2Cache_ptr->getOrdered(), 0,
                                     "request", m_DirRequestFromL2Cache_ptr);
    assert(m_L1RequestFromL2Cache_ptr != NULL);
    m_net_ptr->setToNetQueue(m_version + base, m_L1RequestFromL2Cache_ptr->getOrdered(), 2,
                                     "request", m_L1RequestFromL2Cache_ptr);
    assert(m_responseFromL2Cache_ptr != NULL);
    m_net_ptr->setToNetQueue(m_version + base, m_responseFromL2Cache_ptr->getOrdered(), 1,
                                     "response", m_responseFromL2Cache_ptr);
    assert(m_unblockToL2Cache_ptr != NULL);
    m_net_ptr->setFromNetQueue(m_version + base, m_unblockToL2Cache_ptr->getOrdered(), 2,
                                     "unblock", m_unblockToL2Cache_ptr);
    assert(m_L1RequestToL2Cache_ptr != NULL);
    m_net_ptr->setFromNetQueue(m_version + base, m_L1RequestToL2Cache_ptr->getOrdered(), 0,
                                     "request", m_L1RequestToL2Cache_ptr);
    assert(m_responseToL2Cache_ptr != NULL);
    m_net_ptr->setFromNetQueue(m_version + base, m_responseToL2Cache_ptr->getOrdered(), 1,
                                     "response", m_responseToL2Cache_ptr);
}

void
L2Cache_Controller::init()
{
    // initialize objects
    m_TBEs_ptr  = new TBETable<L2Cache_TBE>(m_number_of_TBEs);
    assert(m_TBEs_ptr != NULL);


    (*m_unblockToL2Cache_ptr).setConsumer(this);
    (*m_responseToL2Cache_ptr).setConsumer(this);
    (*m_L1RequestToL2Cache_ptr).setConsumer(this);

    possibleTransition(L2Cache_State_NP, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_IS, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_ISS, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_IM, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_M, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_M_I, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_I_I, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_S_I, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_NP, L2Cache_Event_L1_PUTX_old);
    possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_PUTX_old);
    possibleTransition(L2Cache_State_M, L2Cache_Event_L1_PUTX_old);
    possibleTransition(L2Cache_State_MT, L2Cache_Event_L1_PUTX_old);
    possibleTransition(L2Cache_State_M_I, L2Cache_Event_L1_PUTX_old);
    possibleTransition(L2Cache_State_I_I, L2Cache_Event_L1_PUTX_old);
    possibleTransition(L2Cache_State_S_I, L2Cache_Event_L1_PUTX_old);
    possibleTransition(L2Cache_State_IS, L2Cache_Event_L1_PUTX_old);
    possibleTransition(L2Cache_State_ISS, L2Cache_Event_L1_PUTX_old);
    possibleTransition(L2Cache_State_IM, L2Cache_Event_L1_PUTX_old);
    possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L1_PUTX_old);
    possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L1_PUTX_old);
    possibleTransition(L2Cache_State_IM, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_IM, L2Cache_Event_L2_Replacement_clean);
    possibleTransition(L2Cache_State_IS, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_IS, L2Cache_Event_L2_Replacement_clean);
    possibleTransition(L2Cache_State_ISS, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_ISS, L2Cache_Event_L2_Replacement_clean);
    possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L2_Replacement_clean);
    possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L2_Replacement_clean);
    possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L2_Replacement_clean);
    possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L2_Replacement_clean);
    possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L2_Replacement_clean);
    possibleTransition(L2Cache_State_IM, L2Cache_Event_MEM_Inv);
    possibleTransition(L2Cache_State_IS, L2Cache_Event_MEM_Inv);
    possibleTransition(L2Cache_State_ISS, L2Cache_Event_MEM_Inv);
    possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_MEM_Inv);
    possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_MEM_Inv);
    possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_MEM_Inv);
    possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_MEM_Inv);
    possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_MEM_Inv);
    possibleTransition(L2Cache_State_I_I, L2Cache_Event_MEM_Inv);
    possibleTransition(L2Cache_State_S_I, L2Cache_Event_MEM_Inv);
    possibleTransition(L2Cache_State_M_I, L2Cache_Event_MEM_Inv);
    possibleTransition(L2Cache_State_MT_I, L2Cache_Event_MEM_Inv);
    possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_MEM_Inv);
    possibleTransition(L2Cache_State_NP, L2Cache_Event_MEM_Inv);
    possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L1_GET_INSTR);
    possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L1_UPGRADE);
    possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L1_GET_INSTR);
    possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L1_UPGRADE);
    possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L1_GET_INSTR);
    possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L1_UPGRADE);
    possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L1_GET_INSTR);
    possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L1_UPGRADE);
    possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L1_GET_INSTR);
    possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L1_UPGRADE);
    possibleTransition(L2Cache_State_NP, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_NP, L2Cache_Event_L1_GET_INSTR);
    possibleTransition(L2Cache_State_NP, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_ISS, L2Cache_Event_Mem_Data);
    possibleTransition(L2Cache_State_IS, L2Cache_Event_Mem_Data);
    possibleTransition(L2Cache_State_IM, L2Cache_Event_Mem_Data);
    possibleTransition(L2Cache_State_IS, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_IS, L2Cache_Event_L1_GET_INSTR);
    possibleTransition(L2Cache_State_ISS, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_ISS, L2Cache_Event_L1_GET_INSTR);
    possibleTransition(L2Cache_State_IS, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_ISS, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_IM, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_IM, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_IM, L2Cache_Event_L1_GET_INSTR);
    possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_GET_INSTR);
    possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_UPGRADE);
    possibleTransition(L2Cache_State_SS, L2Cache_Event_L2_Replacement_clean);
    possibleTransition(L2Cache_State_SS, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_SS, L2Cache_Event_MEM_Inv);
    possibleTransition(L2Cache_State_M, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_M, L2Cache_Event_L1_GET_INSTR);
    possibleTransition(L2Cache_State_M, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_M, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_M, L2Cache_Event_MEM_Inv);
    possibleTransition(L2Cache_State_M, L2Cache_Event_L2_Replacement_clean);
    possibleTransition(L2Cache_State_MT, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_MT, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_MT, L2Cache_Event_L1_GET_INSTR);
    possibleTransition(L2Cache_State_MT, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_MT, L2Cache_Event_MEM_Inv);
    possibleTransition(L2Cache_State_MT, L2Cache_Event_L2_Replacement_clean);
    possibleTransition(L2Cache_State_MT, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_Exclusive_Unblock);
    possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_Exclusive_Unblock);
    possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L1_PUTX_old);
    possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_WB_Data);
    possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_WB_Data_clean);
    possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_WB_Data);
    possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_WB_Data_clean);
    possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_I_I, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_I_I, L2Cache_Event_L1_UPGRADE);
    possibleTransition(L2Cache_State_I_I, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_I_I, L2Cache_Event_L1_GET_INSTR);
    possibleTransition(L2Cache_State_S_I, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_S_I, L2Cache_Event_L1_UPGRADE);
    possibleTransition(L2Cache_State_S_I, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_S_I, L2Cache_Event_L1_GET_INSTR);
    possibleTransition(L2Cache_State_MT_I, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_MT_I, L2Cache_Event_L1_UPGRADE);
    possibleTransition(L2Cache_State_MT_I, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_MT_I, L2Cache_Event_L1_GET_INSTR);
    possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_L1_UPGRADE);
    possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_L1_GET_INSTR);
    possibleTransition(L2Cache_State_M_I, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_M_I, L2Cache_Event_L1_UPGRADE);
    possibleTransition(L2Cache_State_M_I, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_M_I, L2Cache_Event_L1_GET_INSTR);
    possibleTransition(L2Cache_State_I_I, L2Cache_Event_Ack);
    possibleTransition(L2Cache_State_I_I, L2Cache_Event_Ack_all);
    possibleTransition(L2Cache_State_MT_I, L2Cache_Event_WB_Data);
    possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_WB_Data);
    possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_WB_Data_clean);
    possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_Ack_all);
    possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_L1_PUTX_old);
    possibleTransition(L2Cache_State_MT_I, L2Cache_Event_WB_Data_clean);
    possibleTransition(L2Cache_State_MT_I, L2Cache_Event_Ack_all);
    possibleTransition(L2Cache_State_MT_I, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_MT_I, L2Cache_Event_L1_PUTX_old);
    possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L1_PUTX_old);
    possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L1_PUTX_old);
    possibleTransition(L2Cache_State_S_I, L2Cache_Event_Ack);
    possibleTransition(L2Cache_State_S_I, L2Cache_Event_Ack_all);
    possibleTransition(L2Cache_State_M_I, L2Cache_Event_Mem_Ack);
    AbstractController::init();
    resetStats();
}

Sequencer*
L2Cache_Controller::getCPUSequencer() const
{
    return NULL;
}

GPUCoalescer*
L2Cache_Controller::getGPUCoalescer() const
{
    return NULL;
}

void
L2Cache_Controller::regStats()
{
    AbstractController::regStats();

    if (m_version == 0) {
        for (L2Cache_Event event = L2Cache_Event_FIRST;
             event < L2Cache_Event_NUM; ++event) {
            Stats::Vector *t = new Stats::Vector();
            t->init(m_num_controllers);
            t->name(params()->ruby_system->name() + ".L2Cache_Controller." +
                L2Cache_Event_to_string(event));
            t->flags(Stats::pdf | Stats::total | Stats::oneline |
                     Stats::nozero);

            eventVec.push_back(t);
        }

        for (L2Cache_State state = L2Cache_State_FIRST;
             state < L2Cache_State_NUM; ++state) {

            transVec.push_back(std::vector<Stats::Vector *>());

            for (L2Cache_Event event = L2Cache_Event_FIRST;
                 event < L2Cache_Event_NUM; ++event) {

                Stats::Vector *t = new Stats::Vector();
                t->init(m_num_controllers);
                t->name(params()->ruby_system->name() + ".L2Cache_Controller." +
                        L2Cache_State_to_string(state) +
                        "." + L2Cache_Event_to_string(event));

                t->flags(Stats::pdf | Stats::total | Stats::oneline |
                         Stats::nozero);
                transVec[state].push_back(t);
            }
        }
    }
}

void
L2Cache_Controller::collateStats()
{
    for (L2Cache_Event event = L2Cache_Event_FIRST;
         event < L2Cache_Event_NUM; ++event) {
        for (unsigned int i = 0; i < m_num_controllers; ++i) {
            RubySystem *rs = params()->ruby_system;
            std::map<uint32_t, AbstractController *>::iterator it =
                     rs->m_abstract_controls[MachineType_L2Cache].find(i);
            assert(it != rs->m_abstract_controls[MachineType_L2Cache].end());
            (*eventVec[event])[i] =
                ((L2Cache_Controller *)(*it).second)->getEventCount(event);
        }
    }

    for (L2Cache_State state = L2Cache_State_FIRST;
         state < L2Cache_State_NUM; ++state) {

        for (L2Cache_Event event = L2Cache_Event_FIRST;
             event < L2Cache_Event_NUM; ++event) {

            for (unsigned int i = 0; i < m_num_controllers; ++i) {
                RubySystem *rs = params()->ruby_system;
                std::map<uint32_t, AbstractController *>::iterator it =
                         rs->m_abstract_controls[MachineType_L2Cache].find(i);
                assert(it != rs->m_abstract_controls[MachineType_L2Cache].end());
                (*transVec[state][event])[i] =
                    ((L2Cache_Controller *)(*it).second)->getTransitionCount(state, event);
            }
        }
    }
}

void
L2Cache_Controller::countTransition(L2Cache_State state, L2Cache_Event event)
{
    assert(m_possible[state][event]);
    m_counters[state][event]++;
    m_event_counters[event]++;
}
void
L2Cache_Controller::possibleTransition(L2Cache_State state,
                             L2Cache_Event event)
{
    m_possible[state][event] = true;
}

uint64_t
L2Cache_Controller::getEventCount(L2Cache_Event event)
{
    return m_event_counters[event];
}

bool
L2Cache_Controller::isPossible(L2Cache_State state, L2Cache_Event event)
{
    return m_possible[state][event];
}

uint64_t
L2Cache_Controller::getTransitionCount(L2Cache_State state,
                             L2Cache_Event event)
{
    return m_counters[state][event];
}

int
L2Cache_Controller::getNumControllers()
{
    return m_num_controllers;
}

MessageBuffer*
L2Cache_Controller::getMandatoryQueue() const
{
    return NULL;
}

MessageBuffer*
L2Cache_Controller::getMemoryQueue() const
{
    return NULL;
}

void
L2Cache_Controller::print(ostream& out) const
{
    out << "[L2Cache_Controller " << m_version << "]";
}

void L2Cache_Controller::resetStats()
{
    for (int state = 0; state < L2Cache_State_NUM; state++) {
        for (int event = 0; event < L2Cache_Event_NUM; event++) {
            m_counters[state][event] = 0;
        }
    }

    for (int event = 0; event < L2Cache_Event_NUM; event++) {
        m_event_counters[event] = 0;
    }

    AbstractController::resetStats();
}

// Set and Reset for cache_entry variable
void
L2Cache_Controller::set_cache_entry(L2Cache_Entry*& m_cache_entry_ptr, AbstractCacheEntry* m_new_cache_entry)
{
  m_cache_entry_ptr = (L2Cache_Entry*)m_new_cache_entry;
}

void
L2Cache_Controller::unset_cache_entry(L2Cache_Entry*& m_cache_entry_ptr)
{
  m_cache_entry_ptr = 0;
}

// Set and Reset for tbe variable
void
L2Cache_Controller::set_tbe(L2Cache_TBE*& m_tbe_ptr, L2Cache_TBE* m_new_tbe)
{
  m_tbe_ptr = m_new_tbe;
}

void
L2Cache_Controller::unset_tbe(L2Cache_TBE*& m_tbe_ptr)
{
  m_tbe_ptr = NULL;
}

void
L2Cache_Controller::recordCacheTrace(int cntrl, CacheRecorder* tr)
{
    m_L2cache_ptr->recordCacheContents(cntrl, tr);
}

// Actions
/** \brief fetch data from memory */
void
L2Cache_Controller::a_issueFetchToMemory(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing a_issueFetchToMemory\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
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
    (((*out_msg).m_Destination).add((mapAddressToMachine(addr, MachineType_Directory))));
    (*out_msg).m_MessageSize = MessageSizeType_Control;
    ((*m_DirRequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l2_request_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:a_issueFetchToMemory: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Forward request to the exclusive L1 */
void
L2Cache_Controller::b_forwardRequestToExclusive(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing b_forwardRequestToExclusive\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_cache_entry_ptr != NULL))) {
        panic("Runtime Error at MESI_Two_Level-L2cache.sm:413: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = ((*in_msg_ptr)).m_Type;
    (*out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
    (((*out_msg).m_Destination).add((*m_cache_entry_ptr).m_Exclusive));
    (*out_msg).m_MessageSize = MessageSizeType_Request_Control;
    ((*m_L1RequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_to_l1_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:b_forwardRequestToExclusive: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data to memory */
void
L2Cache_Controller::c_exclusiveReplacement(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing c_exclusiveReplacement\n");
    try {
       {
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_cache_entry_ptr != NULL))) {
        panic("Runtime Error at MESI_Two_Level-L2cache.sm:425: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_MEMORY_DATA;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add((mapAddressToMachine(addr, MachineType_Directory))));
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (*m_cache_entry_ptr).m_Dirty;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l2_response_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:c_exclusiveReplacement: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send ack to memory for clean replacement */
void
L2Cache_Controller::c_exclusiveCleanReplacement(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing c_exclusiveCleanReplacement\n");
    try {
       {
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_ACK;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add((mapAddressToMachine(addr, MachineType_Directory))));
    (*out_msg).m_MessageSize = MessageSizeType_Response_Control;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l2_response_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:c_exclusiveCleanReplacement: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data to memory */
void
L2Cache_Controller::ct_exclusiveReplacementFromTBE(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing ct_exclusiveReplacementFromTBE\n");
    try {
       {
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_tbe_ptr != NULL))) {
        panic("Runtime Error at MESI_Two_Level-L2cache.sm:448: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_MEMORY_DATA;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add((mapAddressToMachine(addr, MachineType_Directory))));
    (*out_msg).m_DataBlk = (*m_tbe_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (*m_tbe_ptr).m_Dirty;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l2_response_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:ct_exclusiveReplacementFromTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data from cache to reqeustor */
void
L2Cache_Controller::d_sendDataToRequestor(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing d_sendDataToRequestor\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
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
        panic("Runtime Error at MESI_Two_Level-L2cache.sm:462: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    (*out_msg).m_AckCount = ((0) - (((*m_cache_entry_ptr).m_Sharers).count()));
        if ((((*m_cache_entry_ptr).m_Sharers).isElement(((*in_msg_ptr)).m_Requestor))) {
            (*out_msg).m_AckCount = ((*out_msg).m_AckCount + (1));
        }
        ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l2_response_latency)));
    }
    }

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:d_sendDataToRequestor: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data from cache to reqeustor */
void
L2Cache_Controller::dd_sendExclusiveDataToRequestor(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing dd_sendExclusiveDataToRequestor\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
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
        panic("Runtime Error at MESI_Two_Level-L2cache.sm:481: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA_EXCLUSIVE;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    (*out_msg).m_AckCount = ((0) - (((*m_cache_entry_ptr).m_Sharers).count()));
        if ((((*m_cache_entry_ptr).m_Sharers).isElement(((*in_msg_ptr)).m_Requestor))) {
            (*out_msg).m_AckCount = ((*out_msg).m_AckCount + (1));
        }
        ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l2_response_latency)));
    }
    }

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:dd_sendExclusiveDataToRequestor: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data from cache to reqeustor */
void
L2Cache_Controller::ds_sendSharedDataToRequestor(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing ds_sendSharedDataToRequestor\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
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
        panic("Runtime Error at MESI_Two_Level-L2cache.sm:500: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    (*out_msg).m_AckCount = (0);
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_l2_response_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:ds_sendSharedDataToRequestor: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data from cache to all GetS IDs */
void
L2Cache_Controller::e_sendDataToGetSRequestors(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing e_sendDataToGetSRequestors\n");
    try {
       #ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MESI_Two_Level-L2cache.sm:513: %s.\n", "assert failure");

}
#endif
;
#ifndef NDEBUG
if (!(((((*m_tbe_ptr).m_L1_GetS_IDs).count()) > (0)))) {
    panic("Runtime Error at MESI_Two_Level-L2cache.sm:514: %s.\n", "assert failure");

}
#endif
;
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_cache_entry_ptr != NULL))) {
        panic("Runtime Error at MESI_Two_Level-L2cache.sm:516: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_Destination = (*m_tbe_ptr).m_L1_GetS_IDs;
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_to_l1_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:e_sendDataToGetSRequestors: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data from cache to all GetS IDs */
void
L2Cache_Controller::ex_sendExclusiveDataToGetSRequestors(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing ex_sendExclusiveDataToGetSRequestors\n");
    try {
       #ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MESI_Two_Level-L2cache.sm:527: %s.\n", "assert failure");

}
#endif
;
#ifndef NDEBUG
if (!(((((*m_tbe_ptr).m_L1_GetS_IDs).count()) == (1)))) {
    panic("Runtime Error at MESI_Two_Level-L2cache.sm:528: %s.\n", "assert failure");

}
#endif
;
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_cache_entry_ptr != NULL))) {
        panic("Runtime Error at MESI_Two_Level-L2cache.sm:530: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA_EXCLUSIVE;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_Destination = (*m_tbe_ptr).m_L1_GetS_IDs;
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_to_l1_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:ex_sendExclusiveDataToGetSRequestors: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data from cache to GetX ID */
void
L2Cache_Controller::ee_sendDataToGetXRequestor(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing ee_sendDataToGetXRequestor\n");
    try {
       {
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_tbe_ptr != NULL))) {
        panic("Runtime Error at MESI_Two_Level-L2cache.sm:542: %s.\n", "assert failure");

    }
    #endif
    ;
    #ifndef NDEBUG
    if (!((m_cache_entry_ptr != NULL))) {
        panic("Runtime Error at MESI_Two_Level-L2cache.sm:543: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add((*m_tbe_ptr).m_L1_GetX_ID));
    DPRINTF(RubySlicc, "MESI_Two_Level-L2cache.sm:548: %s\n", (*out_msg).m_Destination);
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    DPRINTF(RubySlicc, "MESI_Two_Level-L2cache.sm:550: Address: %#x, Destination: %s, DataBlock: %s\n", (*out_msg).m_addr, (*out_msg).m_Destination, (*out_msg).m_DataBlk);
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_to_l1_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:ee_sendDataToGetXRequestor: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief invalidate sharers for L2 replacement */
void
L2Cache_Controller::f_sendInvToSharers(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing f_sendInvToSharers\n");
    try {
       {
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_cache_entry_ptr != NULL))) {
        panic("Runtime Error at MESI_Two_Level-L2cache.sm:558: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_INV;
    (*out_msg).m_Requestor = m_machineID;
    (*out_msg).m_Destination = (*m_cache_entry_ptr).m_Sharers;
    (*out_msg).m_MessageSize = MessageSizeType_Request_Control;
    ((*m_L1RequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_to_l1_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:f_sendInvToSharers: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief invalidate sharers for request */
void
L2Cache_Controller::fw_sendFwdInvToSharers(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing fw_sendFwdInvToSharers\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_cache_entry_ptr != NULL))) {
        panic("Runtime Error at MESI_Two_Level-L2cache.sm:570: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_INV;
    (*out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
    (*out_msg).m_Destination = (*m_cache_entry_ptr).m_Sharers;
    (*out_msg).m_MessageSize = MessageSizeType_Request_Control;
    ((*m_L1RequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_to_l1_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:fw_sendFwdInvToSharers: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief invalidate sharers for request, requestor is sharer */
void
L2Cache_Controller::fwm_sendFwdInvToSharersMinusRequestor(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing fwm_sendFwdInvToSharersMinusRequestor\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_cache_entry_ptr != NULL))) {
        panic("Runtime Error at MESI_Two_Level-L2cache.sm:583: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_INV;
    (*out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
    (*out_msg).m_Destination = (*m_cache_entry_ptr).m_Sharers;
    (((*out_msg).m_Destination).remove(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_MessageSize = MessageSizeType_Request_Control;
    ((*m_L1RequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_to_l1_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:fwm_sendFwdInvToSharersMinusRequestor: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Allocate TBE for request */
void
L2Cache_Controller::i_allocateTBE(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing i_allocateTBE\n");
    try {
       #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MESI_Two_Level-L2cache.sm:597: %s.\n", "assert failure");

}
#endif
;
(((*m_TBEs_ptr)).allocate(addr));
set_tbe(m_tbe_ptr, (((*m_TBEs_ptr)).lookup(addr)));;
(((*m_tbe_ptr).m_L1_GetS_IDs).clear());
(*m_tbe_ptr).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
(*m_tbe_ptr).m_Dirty = (*m_cache_entry_ptr).m_Dirty;
(*m_tbe_ptr).m_pendingAcks = (((*m_cache_entry_ptr).m_Sharers).count());

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:i_allocateTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Deallocate external TBE */
void
L2Cache_Controller::s_deallocateTBE(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing s_deallocateTBE\n");
    try {
       (((*m_TBEs_ptr)).deallocate(addr));
unset_tbe(m_tbe_ptr);;

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:s_deallocateTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Pop incoming L1 request queue */
void
L2Cache_Controller::jj_popL1RequestQueue(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing jj_popL1RequestQueue\n");
    try {
       Tick delay
 = (((*m_L1RequestToL2Cache_ptr)).dequeue((clockEdge())));
(profileMsgDelay((0), (ticksToCycles(delay))));

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:jj_popL1RequestQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Pop incoming unblock queue */
void
L2Cache_Controller::k_popUnblockQueue(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing k_popUnblockQueue\n");
    try {
       Tick delay
 = (((*m_unblockToL2Cache_ptr)).dequeue((clockEdge())));
(profileMsgDelay((0), (ticksToCycles(delay))));

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:k_popUnblockQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Pop Incoming Response queue */
void
L2Cache_Controller::o_popIncomingResponseQueue(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing o_popIncomingResponseQueue\n");
    try {
       Tick delay
 = (((*m_responseToL2Cache_ptr)).dequeue((clockEdge())));
(profileMsgDelay((1), (ticksToCycles(delay))));

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:o_popIncomingResponseQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Write data from response queue to cache */
void
L2Cache_Controller::m_writeDataToCache(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing m_writeDataToCache\n");
    try {
       {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MESI_Two_Level-L2cache.sm:628: %s.\n", "assert failure");

}
#endif
;
(*m_cache_entry_ptr).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
    if (((*in_msg_ptr)).m_Dirty) {
        (*m_cache_entry_ptr).m_Dirty = ((*in_msg_ptr)).m_Dirty;
    }
    }

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:m_writeDataToCache: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Write data from response queue to cache */
void
L2Cache_Controller::mr_writeDataToCacheFromRequest(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing mr_writeDataToCacheFromRequest\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MESI_Two_Level-L2cache.sm:638: %s.\n", "assert failure");

}
#endif
;
    if (((*in_msg_ptr)).m_Dirty) {
        (*m_cache_entry_ptr).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
        (*m_cache_entry_ptr).m_Dirty = ((*in_msg_ptr)).m_Dirty;
    }
    }

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:mr_writeDataToCacheFromRequest: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief update pending ack count */
void
L2Cache_Controller::q_updateAck(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing q_updateAck\n");
    try {
       {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MESI_Two_Level-L2cache.sm:648: %s.\n", "assert failure");

}
#endif
;
(*m_tbe_ptr).m_pendingAcks = ((*m_tbe_ptr).m_pendingAcks - ((*in_msg_ptr)).m_AckCount);
APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_AckCount);
APPEND_TRANSITION_COMMENT((" p: "));
APPEND_TRANSITION_COMMENT((*m_tbe_ptr).m_pendingAcks);
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:q_updateAck: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Write data from response queue to TBE */
void
L2Cache_Controller::qq_writeDataToTBE(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing qq_writeDataToTBE\n");
    try {
       {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MESI_Two_Level-L2cache.sm:658: %s.\n", "assert failure");

}
#endif
;
(*m_tbe_ptr).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
(*m_tbe_ptr).m_Dirty = ((*in_msg_ptr)).m_Dirty;
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:qq_writeDataToTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Record L1 GetS for load response */
void
L2Cache_Controller::ss_recordGetSL1ID(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing ss_recordGetSL1ID\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MESI_Two_Level-L2cache.sm:666: %s.\n", "assert failure");

}
#endif
;
(((*m_tbe_ptr).m_L1_GetS_IDs).add(((*in_msg_ptr)).m_Requestor));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:ss_recordGetSL1ID: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Record L1 GetX for store response */
void
L2Cache_Controller::xx_recordGetXL1ID(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing xx_recordGetXL1ID\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MESI_Two_Level-L2cache.sm:673: %s.\n", "assert failure");

}
#endif
;
(*m_tbe_ptr).m_L1_GetX_ID = ((*in_msg_ptr)).m_Requestor;
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:xx_recordGetXL1ID: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief set the MRU entry */
void
L2Cache_Controller::set_setMRU(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing set_setMRU\n");
    try {
       (((*m_L2cache_ptr)).setMRU(addr));

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:set_setMRU: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Set L2 cache tag equal to tag of block B. */
void
L2Cache_Controller::qq_allocateL2CacheBlock(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing qq_allocateL2CacheBlock\n");
    try {
           if ((m_cache_entry_ptr == NULL)) {
        set_cache_entry(m_cache_entry_ptr, (((*m_L2cache_ptr)).allocate(addr, new L2Cache_Entry)));;
    }

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:qq_allocateL2CacheBlock: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Deallocate L2 cache block.  Sets the cache to not present, allowing a replacement in parallel with a fetch. */
void
L2Cache_Controller::rr_deallocateL2CacheBlock(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing rr_deallocateL2CacheBlock\n");
    try {
       (((*m_L2cache_ptr)).deallocate(addr));
unset_cache_entry(m_cache_entry_ptr);;

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:rr_deallocateL2CacheBlock: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send writeback ACK */
void
L2Cache_Controller::t_sendWBAck(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing t_sendWBAck\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_WB_ACK;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_MessageSize = MessageSizeType_Response_Control;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_to_l1_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:t_sendWBAck: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send ACK to upgrader */
void
L2Cache_Controller::ts_sendInvAckToUpgrader(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing ts_sendInvAckToUpgrader\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
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
        panic("Runtime Error at MESI_Two_Level-L2cache.sm:708: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_ACK;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_MessageSize = MessageSizeType_Response_Control;
    (*out_msg).m_AckCount = (((0) - (((*m_cache_entry_ptr).m_Sharers).count())) + (1));
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_to_l1_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:ts_sendInvAckToUpgrader: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Profile the demand miss */
void
L2Cache_Controller::uu_profileMiss(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing uu_profileMiss\n");
    try {
       (++ ((*m_L2cache_ptr)).m_demand_misses);

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:uu_profileMiss: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Profile the demand hit */
void
L2Cache_Controller::uu_profileHit(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing uu_profileHit\n");
    try {
       (++ ((*m_L2cache_ptr)).m_demand_hits);

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:uu_profileHit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Add L1 sharer to list */
void
L2Cache_Controller::nn_addSharer(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing nn_addSharer\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MESI_Two_Level-L2cache.sm:730: %s.\n", "assert failure");

}
#endif
;
(addSharer(addr, ((*in_msg_ptr)).m_Requestor, m_cache_entry_ptr));
APPEND_TRANSITION_COMMENT((*m_cache_entry_ptr).m_Sharers);
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:nn_addSharer: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Add L1 sharer to list */
void
L2Cache_Controller::nnu_addSharerFromUnblock(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing nnu_addSharerFromUnblock\n");
    try {
       {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_unblockToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MESI_Two_Level-L2cache.sm:738: %s.\n", "assert failure");

}
#endif
;
(addSharer(addr, ((*in_msg_ptr)).m_Sender, m_cache_entry_ptr));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:nnu_addSharerFromUnblock: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Remove L1 Request sharer from list */
void
L2Cache_Controller::kk_removeRequestSharer(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing kk_removeRequestSharer\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MESI_Two_Level-L2cache.sm:745: %s.\n", "assert failure");

}
#endif
;
(((*m_cache_entry_ptr).m_Sharers).remove(((*in_msg_ptr)).m_Requestor));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:kk_removeRequestSharer: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Remove all L1 sharers from list */
void
L2Cache_Controller::ll_clearSharers(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing ll_clearSharers\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MESI_Two_Level-L2cache.sm:752: %s.\n", "assert failure");

}
#endif
;
(((*m_cache_entry_ptr).m_Sharers).clear());
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:ll_clearSharers: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief set the exclusive owner */
void
L2Cache_Controller::mm_markExclusive(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing mm_markExclusive\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MESI_Two_Level-L2cache.sm:759: %s.\n", "assert failure");

}
#endif
;
(((*m_cache_entry_ptr).m_Sharers).clear());
(*m_cache_entry_ptr).m_Exclusive = ((*in_msg_ptr)).m_Requestor;
(addSharer(addr, ((*in_msg_ptr)).m_Requestor, m_cache_entry_ptr));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:mm_markExclusive: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief set the exclusive owner */
void
L2Cache_Controller::mmu_markExclusiveFromUnblock(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing mmu_markExclusiveFromUnblock\n");
    try {
       {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_unblockToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MESI_Two_Level-L2cache.sm:768: %s.\n", "assert failure");

}
#endif
;
(((*m_cache_entry_ptr).m_Sharers).clear());
(*m_cache_entry_ptr).m_Exclusive = ((*in_msg_ptr)).m_Sender;
(addSharer(addr, ((*in_msg_ptr)).m_Sender, m_cache_entry_ptr));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:mmu_markExclusiveFromUnblock: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief recycle L1 request queue */
void
L2Cache_Controller::zz_stallAndWaitL1RequestQueue(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing zz_stallAndWaitL1RequestQueue\n");
    try {
               stallBuffer(&((*m_L1RequestToL2Cache_ptr)), addr);
        (*m_L1RequestToL2Cache_ptr).stallMessage(addr, clockEdge());
        

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:zz_stallAndWaitL1RequestQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief recycle memory request */
void
L2Cache_Controller::zn_recycleResponseNetwork(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing zn_recycleResponseNetwork\n");
    try {
       (((*m_responseToL2Cache_ptr)).recycle((clockEdge()), (cyclesToTicks(m_recycle_latency))));

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:zn_recycleResponseNetwork: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief wake-up dependents */
void
L2Cache_Controller::kd_wakeUpDependents(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing kd_wakeUpDependents\n");
    try {
       (wakeUpBuffers(addr));

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:kd_wakeUpDependents: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

L2Cache_Entry*
L2Cache_Controller::getCacheEntry(const Addr& param_addr)
{
return static_cast<L2Cache_Entry *>((((*m_L2cache_ptr)).lookup(param_addr)));

}
bool
L2Cache_Controller::isSharer(const Addr& param_addr, const MachineID& param_requestor, L2Cache_Entry* param_cache_entry)
{
    if ((param_cache_entry != NULL)) {
        return (((*param_cache_entry).m_Sharers).isElement(param_requestor));
    } else {
        return (false);
    }

}
void
L2Cache_Controller::addSharer(const Addr& param_addr, const MachineID& param_requestor, L2Cache_Entry* param_cache_entry)
{
#ifndef NDEBUG
if (!((param_cache_entry != NULL))) {
    panic("Runtime Error at MESI_Two_Level-L2cache.sm:177: %s.\n", "assert failure");

}
#endif
;
DPRINTF(RubySlicc, "MESI_Two_Level-L2cache.sm:178: machineID: %s, requestor: %s, address: %#x\n", m_machineID, param_requestor, param_addr);
(((*param_cache_entry).m_Sharers).add(param_requestor));

}
L2Cache_State
L2Cache_Controller::getState(L2Cache_TBE* param_tbe, L2Cache_Entry* param_cache_entry, const Addr& param_addr)
{
    if ((param_tbe != NULL)) {
        return (*param_tbe).m_TBEState;
    } else {
            if ((param_cache_entry != NULL)) {
                return (*param_cache_entry).m_CacheState;
            }
        }
        return L2Cache_State_NP;

}
void
L2Cache_Controller::setState(L2Cache_TBE* param_tbe, L2Cache_Entry* param_cache_entry, const Addr& param_addr, const L2Cache_State& param_state)
{
    if ((param_tbe != NULL)) {
        (*param_tbe).m_TBEState = param_state;
    }
        if ((param_cache_entry != NULL)) {
            (*param_cache_entry).m_CacheState = param_state;
        }

}
AccessPermission
L2Cache_Controller::getAccessPermission(const Addr& param_addr)
{
L2Cache_TBE* tbe
 = (((*m_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        DPRINTF(RubySlicc, "MESI_Two_Level-L2cache.sm:206: %s\n", (L2Cache_State_to_permission((*tbe).m_TBEState)));
        return (L2Cache_State_to_permission((*tbe).m_TBEState));
    }
    L2Cache_Entry* cache_entry
     = (getCacheEntry(param_addr));
        if ((cache_entry != NULL)) {
            DPRINTF(RubySlicc, "MESI_Two_Level-L2cache.sm:212: %s\n", (L2Cache_State_to_permission((*cache_entry).m_CacheState)));
            return (L2Cache_State_to_permission((*cache_entry).m_CacheState));
        }
        DPRINTF(RubySlicc, "MESI_Two_Level-L2cache.sm:216: %s\n", AccessPermission_NotPresent);
        return AccessPermission_NotPresent;

}
void
L2Cache_Controller::functionalRead(const Addr& param_addr, Packet* param_pkt)
{
L2Cache_TBE* tbe
 = (((*m_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        (testAndRead(param_addr, (*tbe).m_DataBlk, param_pkt));
    } else {
        (testAndRead(param_addr, (*(getCacheEntry(param_addr))).m_DataBlk, param_pkt));
    }

}
int
L2Cache_Controller::functionalWrite(const Addr& param_addr, Packet* param_pkt)
{
int num_functional_writes
 = (0);
L2Cache_TBE* tbe
 = (((*m_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        num_functional_writes = (num_functional_writes + (testAndWrite(param_addr, (*tbe).m_DataBlk, param_pkt)));
        return num_functional_writes;
    }
    num_functional_writes = (num_functional_writes + (testAndWrite(param_addr, (*(getCacheEntry(param_addr))).m_DataBlk, param_pkt)));
    return num_functional_writes;

}
void
L2Cache_Controller::setAccessPermission(L2Cache_Entry* param_cache_entry, const Addr& param_addr, const L2Cache_State& param_state)
{
    if ((param_cache_entry != NULL)) {
        ((*(param_cache_entry)).changePermission((L2Cache_State_to_permission(param_state))));
    }

}
L2Cache_Event
L2Cache_Controller::L1Cache_request_type_to_event(const CoherenceRequestType& param_type, const Addr& param_addr, const MachineID& param_requestor, L2Cache_Entry* param_cache_entry)
{
    if ((param_type == CoherenceRequestType_GETS)) {
        return L2Cache_Event_L1_GETS;
    } else {
            if ((param_type == CoherenceRequestType_GET_INSTR)) {
                return L2Cache_Event_L1_GET_INSTR;
            } else {
                    if ((param_type == CoherenceRequestType_GETX)) {
                        return L2Cache_Event_L1_GETX;
                    } else {
                            if ((param_type == CoherenceRequestType_UPGRADE)) {
                                    if (((param_cache_entry != NULL) && (((*param_cache_entry).m_Sharers).isElement(param_requestor)))) {
                                        return L2Cache_Event_L1_UPGRADE;
                                    } else {
                                        return L2Cache_Event_L1_GETX;
                                    }
                                } else {
                                        if ((param_type == CoherenceRequestType_PUTX)) {
                                                if ((isSharer(param_addr, param_requestor, param_cache_entry))) {
                                                    return L2Cache_Event_L1_PUTX;
                                                } else {
                                                    return L2Cache_Event_L1_PUTX_old;
                                                }
                                            } else {
                                                DPRINTF(RubySlicc, "MESI_Two_Level-L2cache.sm:271: address: %#x, Request Type: %s\n", param_addr, param_type);
                                                panic("Runtime Error at MESI_Two_Level-L2cache.sm:272: %s.\n", ("Invalid L1 forwarded request type"));
                                                ;
                                            }
                                        }
                                    }
                                }
                            }

}
int
L2Cache_Controller::getPendingAcks(L2Cache_TBE* param_tbe)
{
return (*param_tbe).m_pendingAcks;

}
bool
L2Cache_Controller::isDirty(L2Cache_Entry* param_cache_entry)
{
#ifndef NDEBUG
if (!((param_cache_entry != NULL))) {
    panic("Runtime Error at MESI_Two_Level-L2cache.sm:281: %s.\n", "assert failure");

}
#endif
;
return (*param_cache_entry).m_Dirty;

}
int
L2Cache_Controller::functionalWriteBuffers(PacketPtr& pkt)
{
    int num_functional_writes = 0;
num_functional_writes += m_DirRequestFromL2Cache_ptr->functionalWrite(pkt);
num_functional_writes += m_L1RequestFromL2Cache_ptr->functionalWrite(pkt);
num_functional_writes += m_responseFromL2Cache_ptr->functionalWrite(pkt);
num_functional_writes += m_unblockToL2Cache_ptr->functionalWrite(pkt);
num_functional_writes += m_L1RequestToL2Cache_ptr->functionalWrite(pkt);
num_functional_writes += m_responseToL2Cache_ptr->functionalWrite(pkt);
    return num_functional_writes;
}
