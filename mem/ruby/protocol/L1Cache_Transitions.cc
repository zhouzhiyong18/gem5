// Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/StateMachine.py:1188
// L1Cache: MESI Directory L1 Cache CMP

#include <cassert>

#include "base/logging.hh"
#include "base/trace.hh"
#include "debug/ProtocolTrace.hh"
#include "debug/RubyGenerated.hh"
#include "mem/ruby/protocol/L1Cache_Controller.hh"
#include "mem/ruby/protocol/L1Cache_Event.hh"
#include "mem/ruby/protocol/L1Cache_State.hh"
#include "mem/ruby/protocol/Types.hh"
#include "mem/ruby/system/RubySystem.hh"

#define HASH_FUN(state, event)  ((int(state)*L1Cache_Event_NUM)+int(event))

#define GET_TRANSITION_COMMENT() (L1Cache_transitionComment.str())
#define CLEAR_TRANSITION_COMMENT() (L1Cache_transitionComment.str(""))

TransitionResult
L1Cache_Controller::doTransition(L1Cache_Event event,
                                  L1Cache_Entry* m_cache_entry_ptr,
                                  L1Cache_TBE* m_tbe_ptr,
                                  Addr addr)
{
    L1Cache_State state = getState(m_tbe_ptr, m_cache_entry_ptr, addr);
    L1Cache_State next_state = state;

    DPRINTF(RubyGenerated, "%s, Time: %lld, state: %s, event: %s, addr: %#x\n",
            *this, curCycle(), L1Cache_State_to_string(state),
            L1Cache_Event_to_string(event), addr);

    TransitionResult result =
    doTransitionWorker(event, state, next_state, m_tbe_ptr, m_cache_entry_ptr, addr);

    if (result == TransitionResult_Valid) {
        DPRINTF(RubyGenerated, "next_state: %s\n",
                L1Cache_State_to_string(next_state));
        countTransition(state, event);

        DPRINTFR(ProtocolTrace, "%15d %3s %10s%20s %6s>%-6s %#x %s\n",
                 curTick(), m_version, "L1Cache",
                 L1Cache_Event_to_string(event),
                 L1Cache_State_to_string(state),
                 L1Cache_State_to_string(next_state),
                 printAddress(addr), GET_TRANSITION_COMMENT());

        CLEAR_TRANSITION_COMMENT();
    setState(m_tbe_ptr, m_cache_entry_ptr, addr, next_state);
    setAccessPermission(m_cache_entry_ptr, addr, next_state);
    } else if (result == TransitionResult_ResourceStall) {
        DPRINTFR(ProtocolTrace, "%15s %3s %10s%20s %6s>%-6s %#x %s\n",
                 curTick(), m_version, "L1Cache",
                 L1Cache_Event_to_string(event),
                 L1Cache_State_to_string(state),
                 L1Cache_State_to_string(next_state),
                 printAddress(addr), "Resource Stall");
    } else if (result == TransitionResult_ProtocolStall) {
        DPRINTF(RubyGenerated, "stalling\n");
        DPRINTFR(ProtocolTrace, "%15s %3s %10s%20s %6s>%-6s %#x %s\n",
                 curTick(), m_version, "L1Cache",
                 L1Cache_Event_to_string(event),
                 L1Cache_State_to_string(state),
                 L1Cache_State_to_string(next_state),
                 printAddress(addr), "Protocol Stall");
    }

    return result;
}

TransitionResult
L1Cache_Controller::doTransitionWorker(L1Cache_Event event,
                                        L1Cache_State state,
                                        L1Cache_State& next_state,
                                        L1Cache_TBE*& m_tbe_ptr,
                                        L1Cache_Entry*& m_cache_entry_ptr,
                                        Addr addr)
{
    switch(HASH_FUN(state, event)) {
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_M_I, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_M_I, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_M_I, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_SINK_WB_ACK, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_SINK_WB_ACK, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_SINK_WB_ACK, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_S_IL0, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_S_IL0, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_S_IL0, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_M_IL0, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_M_IL0, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_M_IL0, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_E_IL0, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_E_IL0, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_E_IL0, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_MM_IL0, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_MM_IL0, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_MM_IL0, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_S_IL0, L1Cache_Event_L0_Invalidate_Own):
  case HASH_FUN(L1Cache_State_M_IL0, L1Cache_Event_L0_Invalidate_Own):
  case HASH_FUN(L1Cache_State_E_IL0, L1Cache_Event_L0_Invalidate_Own):
  case HASH_FUN(L1Cache_State_SM_IL0, L1Cache_Event_L0_Invalidate_Own):
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_L0_Invalidate_Own):
    z0_stallAndWaitL0Queue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Load):
    next_state = L1Cache_State_IS;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_requestToL2_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    oo_allocateCacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    a_issueGETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popL0RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Store):
    next_state = L1Cache_State_IM;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_requestToL2_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    oo_allocateCacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    b_issueGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popL0RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_SINK_WB_ACK, L1Cache_Event_Inv):
    if (!(*m_responseToL2_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    fi_sendInvAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popL2RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_S, L1Cache_Event_Load):
    if (!(*m_bufferToL0_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    h_data_to_l0(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popL0RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_SS, L1Cache_Event_Load):
    next_state = L1Cache_State_S;
    if (!(*m_bufferToL0_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    h_data_to_l0(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popL0RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_EE, L1Cache_Event_Load):
    next_state = L1Cache_State_E;
    if (!(*m_bufferToL0_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    hh_xdata_to_l0(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popL0RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_MM, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_EE, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_MM, L1Cache_Event_Store):
    next_state = L1Cache_State_M;
    if (!(*m_bufferToL0_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    hh_xdata_to_l0(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popL0RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_S, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_SS, L1Cache_Event_Store):
    next_state = L1Cache_State_SM;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_requestToL2_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    c_issueUPGRADE(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popL0RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_SS, L1Cache_Event_L1_Replacement):
    next_state = L1Cache_State_I;
    ff_deallocateCacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_S, L1Cache_Event_L0_Invalidate_Own):
  case HASH_FUN(L1Cache_State_S, L1Cache_Event_L0_Invalidate_Else):
    next_state = L1Cache_State_S_IL0;
    if (!(*m_bufferToL0_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    forward_eviction_to_L0(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_SS, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_EE, L1Cache_Event_Inv):
    next_state = L1Cache_State_I;
    if (!(*m_responseToL2_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    fi_sendInvAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    ff_deallocateCacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popL2RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_EE, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_MM, L1Cache_Event_L1_Replacement):
    next_state = L1Cache_State_M_I;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_requestToL2_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    g_issuePUTX(m_tbe_ptr, m_cache_entry_ptr, addr);
    ff_deallocateCacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_EE, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_MM, L1Cache_Event_Fwd_GETX):
    next_state = L1Cache_State_I;
    if (!(*m_responseToL2_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    d_sendDataToRequestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    ff_deallocateCacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popL2RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_EE, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_MM, L1Cache_Event_Fwd_GETS):
    next_state = L1Cache_State_SS;
    if (!(*m_responseToL2_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    d_sendDataToRequestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    d2_sendDataToL2(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popL2RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_E, L1Cache_Event_L0_Invalidate_Own):
  case HASH_FUN(L1Cache_State_E, L1Cache_Event_L0_Invalidate_Else):
    next_state = L1Cache_State_E_IL0;
    if (!(*m_bufferToL0_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    forward_eviction_to_L0(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_M, L1Cache_Event_WriteBack):
  case HASH_FUN(L1Cache_State_E, L1Cache_Event_WriteBack):
    next_state = L1Cache_State_MM;
    u_writeDataFromL0Request(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popL0RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_M_I, L1Cache_Event_WB_Ack):
  case HASH_FUN(L1Cache_State_SINK_WB_ACK, L1Cache_Event_WB_Ack):
    next_state = L1Cache_State_I;
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL2ResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    ff_deallocateCacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_MM, L1Cache_Event_Inv):
    next_state = L1Cache_State_I;
    if (!(*m_responseToL2_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    f_sendDataToL2(m_tbe_ptr, m_cache_entry_ptr, addr);
    ff_deallocateCacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popL2RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_M_I, L1Cache_Event_Inv):
    next_state = L1Cache_State_SINK_WB_ACK;
    if (!(*m_responseToL2_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    ft_sendDataToL2_fromTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popL2RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_M, L1Cache_Event_L0_Invalidate_Own):
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_L0_Invalidate_Else):
    next_state = L1Cache_State_M_IL0;
    if (!(*m_bufferToL0_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    forward_eviction_to_L0(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_M_I, L1Cache_Event_Fwd_GETX):
    next_state = L1Cache_State_SINK_WB_ACK;
    if (!(*m_responseToL2_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    dt_sendDataToRequestor_fromTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popL2RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_M_I, L1Cache_Event_Fwd_GETS):
    next_state = L1Cache_State_SINK_WB_ACK;
    if (!(*m_responseToL2_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    dt_sendDataToRequestor_fromTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    d2t_sendDataToL2_fromTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popL2RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Inv):
    next_state = L1Cache_State_IS_I;
    if (!(*m_responseToL2_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    fi_sendInvAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popL2RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Data_all_Acks):
    next_state = L1Cache_State_S;
    if (!(*m_bufferToL0_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    u_writeDataFromL2Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    h_data_to_l0(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL2ResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_Data_all_Acks):
    next_state = L1Cache_State_I;
    if (!(*m_bufferToL0_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    u_writeDataFromL2Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    h_stale_data_to_l0(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    ff_deallocateCacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL2ResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_DataS_fromL1):
    next_state = L1Cache_State_S;
    if (!(*m_bufferToL0_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_unblockToL2_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    u_writeDataFromL2Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    j_sendUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    h_data_to_l0(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL2ResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_DataS_fromL1):
    next_state = L1Cache_State_I;
    if (!(*m_bufferToL0_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_unblockToL2_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    u_writeDataFromL2Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    j_sendUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    h_stale_data_to_l0(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    ff_deallocateCacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL2ResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Data_Exclusive):
  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_Data_Exclusive):
    next_state = L1Cache_State_E;
    if (!(*m_bufferToL0_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_unblockToL2_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    u_writeDataFromL2Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    hh_xdata_to_l0(m_tbe_ptr, m_cache_entry_ptr, addr);
    jj_sendExclusiveUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL2ResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_Inv):
    next_state = L1Cache_State_IM;
    if (!(*m_responseToL2_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    fi_sendInvAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popL2RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Data):
    next_state = L1Cache_State_SM;
    u_writeDataFromL2Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    q_updateAckCount(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL2ResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Data_all_Acks):
    next_state = L1Cache_State_M;
    if (!(*m_bufferToL0_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_unblockToL2_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    u_writeDataFromL2Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    hh_xdata_to_l0(m_tbe_ptr, m_cache_entry_ptr, addr);
    jj_sendExclusiveUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL2ResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_Ack):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Ack):
    q_updateAckCount(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL2ResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_Ack_all):
    next_state = L1Cache_State_M;
    if (!(*m_bufferToL0_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_unblockToL2_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    jj_sendExclusiveUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    hh_xdata_to_l0(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL2ResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_L0_Invalidate_Else):
    next_state = L1Cache_State_SM_IL0;
    if (!(*m_bufferToL0_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    forward_eviction_to_L0(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_M_IL0, L1Cache_Event_WriteBack):
  case HASH_FUN(L1Cache_State_E_IL0, L1Cache_Event_WriteBack):
    next_state = L1Cache_State_MM_IL0;
    u_writeDataFromL0Request(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popL0RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_M_IL0, L1Cache_Event_L0_DataAck):
  case HASH_FUN(L1Cache_State_E_IL0, L1Cache_Event_L0_DataAck):
    next_state = L1Cache_State_MM;
    u_writeDataFromL0Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popL0RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_M_IL0, L1Cache_Event_L0_Ack):
  case HASH_FUN(L1Cache_State_MM_IL0, L1Cache_Event_L0_Ack):
    next_state = L1Cache_State_MM;
    k_popL0RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_E_IL0, L1Cache_Event_L0_Ack):
    next_state = L1Cache_State_EE;
    k_popL0RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_S_IL0, L1Cache_Event_L0_Ack):
    next_state = L1Cache_State_SS;
    k_popL0RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_SM_IL0, L1Cache_Event_L0_Ack):
    next_state = L1Cache_State_IM;
    k_popL0RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_S_IL0, L1Cache_Event_L0_Invalidate_Else):
  case HASH_FUN(L1Cache_State_M_IL0, L1Cache_Event_L0_Invalidate_Else):
  case HASH_FUN(L1Cache_State_E_IL0, L1Cache_Event_L0_Invalidate_Else):
  case HASH_FUN(L1Cache_State_SM_IL0, L1Cache_Event_L0_Invalidate_Else):
  case HASH_FUN(L1Cache_State_S_IL0, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_S_IL0, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_S_IL0, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_M_IL0, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_M_IL0, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_M_IL0, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_E_IL0, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_E_IL0, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_E_IL0, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_MM_IL0, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_MM_IL0, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_MM_IL0, L1Cache_Event_Fwd_GETS):
    z2_stallAndWaitL2Queue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

      default:
        panic("Invalid transition\n"
              "%s time: %d addr: %#x event: %s state: %s\n",
              name(), curCycle(), addr, event, state);
    }

    return TransitionResult_Valid;
}
