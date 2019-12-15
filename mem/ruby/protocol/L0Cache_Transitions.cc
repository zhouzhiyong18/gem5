// Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/StateMachine.py:1188
// L0Cache: MESI Directory L0 Cache

#include <cassert>

#include "base/logging.hh"
#include "base/trace.hh"
#include "debug/ProtocolTrace.hh"
#include "debug/RubyGenerated.hh"
#include "mem/ruby/protocol/L0Cache_Controller.hh"
#include "mem/ruby/protocol/L0Cache_Event.hh"
#include "mem/ruby/protocol/L0Cache_State.hh"
#include "mem/ruby/protocol/Types.hh"
#include "mem/ruby/system/RubySystem.hh"

#define HASH_FUN(state, event)  ((int(state)*L0Cache_Event_NUM)+int(event))

#define GET_TRANSITION_COMMENT() (L0Cache_transitionComment.str())
#define CLEAR_TRANSITION_COMMENT() (L0Cache_transitionComment.str(""))

TransitionResult
L0Cache_Controller::doTransition(L0Cache_Event event,
                                  L0Cache_Entry* m_cache_entry_ptr,
                                  L0Cache_TBE* m_tbe_ptr,
                                  Addr addr)
{
    L0Cache_State state = getState(m_tbe_ptr, m_cache_entry_ptr, addr);
    L0Cache_State next_state = state;

    DPRINTF(RubyGenerated, "%s, Time: %lld, state: %s, event: %s, addr: %#x\n",
            *this, curCycle(), L0Cache_State_to_string(state),
            L0Cache_Event_to_string(event), addr);

    TransitionResult result =
    doTransitionWorker(event, state, next_state, m_tbe_ptr, m_cache_entry_ptr, addr);

    if (result == TransitionResult_Valid) {
        DPRINTF(RubyGenerated, "next_state: %s\n",
                L0Cache_State_to_string(next_state));
        countTransition(state, event);

        DPRINTFR(ProtocolTrace, "%15d %3s %10s%20s %6s>%-6s %#x %s\n",
                 curTick(), m_version, "L0Cache",
                 L0Cache_Event_to_string(event),
                 L0Cache_State_to_string(state),
                 L0Cache_State_to_string(next_state),
                 printAddress(addr), GET_TRANSITION_COMMENT());

        CLEAR_TRANSITION_COMMENT();
    setState(m_tbe_ptr, m_cache_entry_ptr, addr, next_state);
    setAccessPermission(m_cache_entry_ptr, addr, next_state);
    } else if (result == TransitionResult_ResourceStall) {
        DPRINTFR(ProtocolTrace, "%15s %3s %10s%20s %6s>%-6s %#x %s\n",
                 curTick(), m_version, "L0Cache",
                 L0Cache_Event_to_string(event),
                 L0Cache_State_to_string(state),
                 L0Cache_State_to_string(next_state),
                 printAddress(addr), "Resource Stall");
    } else if (result == TransitionResult_ProtocolStall) {
        DPRINTF(RubyGenerated, "stalling\n");
        DPRINTFR(ProtocolTrace, "%15s %3s %10s%20s %6s>%-6s %#x %s\n",
                 curTick(), m_version, "L0Cache",
                 L0Cache_Event_to_string(event),
                 L0Cache_State_to_string(state),
                 L0Cache_State_to_string(next_state),
                 printAddress(addr), "Protocol Stall");
    }

    return result;
}

TransitionResult
L0Cache_Controller::doTransitionWorker(L0Cache_Event event,
                                        L0Cache_State state,
                                        L0Cache_State& next_state,
                                        L0Cache_TBE*& m_tbe_ptr,
                                        L0Cache_Entry*& m_cache_entry_ptr,
                                        Addr addr)
{
    switch(HASH_FUN(state, event)) {
  case HASH_FUN(L0Cache_State_Inst_IS, L0Cache_Event_Load):
  case HASH_FUN(L0Cache_State_Inst_IS, L0Cache_Event_Ifetch):
  case HASH_FUN(L0Cache_State_Inst_IS, L0Cache_Event_Store):
  case HASH_FUN(L0Cache_State_Inst_IS, L0Cache_Event_L0_Replacement):
  case HASH_FUN(L0Cache_State_IS, L0Cache_Event_Load):
  case HASH_FUN(L0Cache_State_IS, L0Cache_Event_Ifetch):
  case HASH_FUN(L0Cache_State_IS, L0Cache_Event_Store):
  case HASH_FUN(L0Cache_State_IS, L0Cache_Event_L0_Replacement):
  case HASH_FUN(L0Cache_State_IM, L0Cache_Event_Load):
  case HASH_FUN(L0Cache_State_IM, L0Cache_Event_Ifetch):
  case HASH_FUN(L0Cache_State_IM, L0Cache_Event_Store):
  case HASH_FUN(L0Cache_State_IM, L0Cache_Event_L0_Replacement):
  case HASH_FUN(L0Cache_State_SM, L0Cache_Event_Load):
  case HASH_FUN(L0Cache_State_SM, L0Cache_Event_Ifetch):
  case HASH_FUN(L0Cache_State_SM, L0Cache_Event_Store):
  case HASH_FUN(L0Cache_State_SM, L0Cache_Event_L0_Replacement):
    z_stallAndWaitMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L0Cache_State_I, L0Cache_Event_Load):
    next_state = L0Cache_State_IS;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_bufferToL1_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    oo_allocateDCacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    a_issueGETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileDataMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L0Cache_State_I, L0Cache_Event_Ifetch):
    next_state = L0Cache_State_Inst_IS;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_bufferToL1_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    pp_allocateICacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    a_issueGETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileInstMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L0Cache_State_I, L0Cache_Event_Store):
    next_state = L0Cache_State_IM;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_bufferToL1_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    oo_allocateDCacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    b_issueGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileDataMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L0Cache_State_I, L0Cache_Event_Inv):
  case HASH_FUN(L0Cache_State_IS, L0Cache_Event_Inv):
  case HASH_FUN(L0Cache_State_IM, L0Cache_Event_Inv):
  case HASH_FUN(L0Cache_State_Inst_IS, L0Cache_Event_Inv):
    if (!(*m_bufferToL1_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    fi_sendInvAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L0Cache_State_SM, L0Cache_Event_Inv):
    next_state = L0Cache_State_IM;
    if (!(*m_bufferToL1_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    fi_sendInvAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L0Cache_State_S, L0Cache_Event_Load):
  case HASH_FUN(L0Cache_State_E, L0Cache_Event_Load):
  case HASH_FUN(L0Cache_State_M, L0Cache_Event_Load):
    h_load_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileDataHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L0Cache_State_S, L0Cache_Event_Ifetch):
  case HASH_FUN(L0Cache_State_E, L0Cache_Event_Ifetch):
  case HASH_FUN(L0Cache_State_M, L0Cache_Event_Ifetch):
    h_ifetch_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileInstHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L0Cache_State_S, L0Cache_Event_Store):
    next_state = L0Cache_State_SM;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_bufferToL1_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    c_issueUPGRADE(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileDataMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L0Cache_State_S, L0Cache_Event_L0_Replacement):
    next_state = L0Cache_State_I;
    forward_eviction_to_cpu(m_tbe_ptr, m_cache_entry_ptr, addr);
    ff_deallocateCacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L0Cache_State_S, L0Cache_Event_Inv):
  case HASH_FUN(L0Cache_State_E, L0Cache_Event_Inv):
  case HASH_FUN(L0Cache_State_E, L0Cache_Event_Fwd_GETX):
    next_state = L0Cache_State_I;
    if (!(*m_bufferToL1_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    forward_eviction_to_cpu(m_tbe_ptr, m_cache_entry_ptr, addr);
    fi_sendInvAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    ff_deallocateCacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L0Cache_State_E, L0Cache_Event_Store):
    next_state = L0Cache_State_M;
    hh_store_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileDataHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L0Cache_State_M, L0Cache_Event_Store):
    hh_store_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileDataHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L0Cache_State_E, L0Cache_Event_L0_Replacement):
  case HASH_FUN(L0Cache_State_M, L0Cache_Event_L0_Replacement):
    next_state = L0Cache_State_I;
    if (!(*m_bufferToL1_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    forward_eviction_to_cpu(m_tbe_ptr, m_cache_entry_ptr, addr);
    g_issuePUTX(m_tbe_ptr, m_cache_entry_ptr, addr);
    ff_deallocateCacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L0Cache_State_E, L0Cache_Event_Fwd_GETS):
  case HASH_FUN(L0Cache_State_E, L0Cache_Event_Fwd_GET_INSTR):
  case HASH_FUN(L0Cache_State_M, L0Cache_Event_Fwd_GETS):
  case HASH_FUN(L0Cache_State_M, L0Cache_Event_Fwd_GET_INSTR):
    next_state = L0Cache_State_S;
    if (!(*m_bufferToL1_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    f_sendDataToL1(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L0Cache_State_M, L0Cache_Event_Inv):
  case HASH_FUN(L0Cache_State_M, L0Cache_Event_Fwd_GETX):
    next_state = L0Cache_State_I;
    if (!(*m_bufferToL1_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    forward_eviction_to_cpu(m_tbe_ptr, m_cache_entry_ptr, addr);
    f_sendDataToL1(m_tbe_ptr, m_cache_entry_ptr, addr);
    ff_deallocateCacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L0Cache_State_IS, L0Cache_Event_Data):
    next_state = L0Cache_State_S;
    u_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    hx_load_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popIncomingResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L0Cache_State_IS, L0Cache_Event_Data_Exclusive):
    next_state = L0Cache_State_E;
    u_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    hx_load_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popIncomingResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L0Cache_State_IS, L0Cache_Event_Data_Stale):
    next_state = L0Cache_State_I;
    u_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    hx_load_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    ff_deallocateCacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popIncomingResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L0Cache_State_Inst_IS, L0Cache_Event_Data):
    next_state = L0Cache_State_S;
    u_writeInstToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    hx_ifetch_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popIncomingResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L0Cache_State_Inst_IS, L0Cache_Event_Data_Exclusive):
    next_state = L0Cache_State_E;
    u_writeInstToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    hx_ifetch_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popIncomingResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L0Cache_State_Inst_IS, L0Cache_Event_Data_Stale):
    next_state = L0Cache_State_I;
    u_writeInstToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    hx_ifetch_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    ff_deallocateCacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popIncomingResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L0Cache_State_IM, L0Cache_Event_Data_Exclusive):
  case HASH_FUN(L0Cache_State_SM, L0Cache_Event_Data_Exclusive):
    next_state = L0Cache_State_M;
    u_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    hhx_store_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popIncomingResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

      default:
        panic("Invalid transition\n"
              "%s time: %d addr: %#x event: %s state: %s\n",
              name(), curCycle(), addr, event, state);
    }

    return TransitionResult_Valid;
}
