// Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/StateMachine.py:1188
// L2Cache: MESI Directory L2 Cache CMP

#include <cassert>

#include "base/logging.hh"
#include "base/trace.hh"
#include "debug/ProtocolTrace.hh"
#include "debug/RubyGenerated.hh"
#include "mem/ruby/protocol/L2Cache_Controller.hh"
#include "mem/ruby/protocol/L2Cache_Event.hh"
#include "mem/ruby/protocol/L2Cache_State.hh"
#include "mem/ruby/protocol/Types.hh"
#include "mem/ruby/system/RubySystem.hh"

#define HASH_FUN(state, event)  ((int(state)*L2Cache_Event_NUM)+int(event))

#define GET_TRANSITION_COMMENT() (L2Cache_transitionComment.str())
#define CLEAR_TRANSITION_COMMENT() (L2Cache_transitionComment.str(""))

TransitionResult
L2Cache_Controller::doTransition(L2Cache_Event event,
                                  L2Cache_Entry* m_cache_entry_ptr,
                                  L2Cache_TBE* m_tbe_ptr,
                                  Addr addr)
{
    L2Cache_State state = getState(m_tbe_ptr, m_cache_entry_ptr, addr);
    L2Cache_State next_state = state;

    DPRINTF(RubyGenerated, "%s, Time: %lld, state: %s, event: %s, addr: %#x\n",
            *this, curCycle(), L2Cache_State_to_string(state),
            L2Cache_Event_to_string(event), addr);

    TransitionResult result =
    doTransitionWorker(event, state, next_state, m_tbe_ptr, m_cache_entry_ptr, addr);

    if (result == TransitionResult_Valid) {
        DPRINTF(RubyGenerated, "next_state: %s\n",
                L2Cache_State_to_string(next_state));
        countTransition(state, event);

        DPRINTFR(ProtocolTrace, "%15d %3s %10s%20s %6s>%-6s %#x %s\n",
                 curTick(), m_version, "L2Cache",
                 L2Cache_Event_to_string(event),
                 L2Cache_State_to_string(state),
                 L2Cache_State_to_string(next_state),
                 printAddress(addr), GET_TRANSITION_COMMENT());

        CLEAR_TRANSITION_COMMENT();
    setState(m_tbe_ptr, m_cache_entry_ptr, addr, next_state);
    setAccessPermission(m_cache_entry_ptr, addr, next_state);
    } else if (result == TransitionResult_ResourceStall) {
        DPRINTFR(ProtocolTrace, "%15s %3s %10s%20s %6s>%-6s %#x %s\n",
                 curTick(), m_version, "L2Cache",
                 L2Cache_Event_to_string(event),
                 L2Cache_State_to_string(state),
                 L2Cache_State_to_string(next_state),
                 printAddress(addr), "Resource Stall");
    } else if (result == TransitionResult_ProtocolStall) {
        DPRINTF(RubyGenerated, "stalling\n");
        DPRINTFR(ProtocolTrace, "%15s %3s %10s%20s %6s>%-6s %#x %s\n",
                 curTick(), m_version, "L2Cache",
                 L2Cache_Event_to_string(event),
                 L2Cache_State_to_string(state),
                 L2Cache_State_to_string(next_state),
                 printAddress(addr), "Protocol Stall");
    }

    return result;
}

TransitionResult
L2Cache_Controller::doTransitionWorker(L2Cache_Event event,
                                        L2Cache_State state,
                                        L2Cache_State& next_state,
                                        L2Cache_TBE*& m_tbe_ptr,
                                        L2Cache_Entry*& m_cache_entry_ptr,
                                        Addr addr)
{
    switch(HASH_FUN(state, event)) {
  case HASH_FUN(L2Cache_State_NP, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_M_I, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_I_I, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_S_I, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_NP, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_M_I, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_I_I, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_S_I, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L1_PUTX_old):
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    t_sendWBAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    jj_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_I_I, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_I_I, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_I_I, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_I_I, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_S_I, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_S_I, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_S_I, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_S_I, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_M_I, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_M_I, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_M_I, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_M_I, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L1_PUTX_old):
    zz_stallAndWaitL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_MEM_Inv):
  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_MEM_Inv):
  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_MEM_Inv):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_MEM_Inv):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_MEM_Inv):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_MEM_Inv):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_MEM_Inv):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_MEM_Inv):
    zn_recycleResponseNetwork(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_I_I, L2Cache_Event_MEM_Inv):
  case HASH_FUN(L2Cache_State_S_I, L2Cache_Event_MEM_Inv):
  case HASH_FUN(L2Cache_State_M_I, L2Cache_Event_MEM_Inv):
  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_MEM_Inv):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_MEM_Inv):
  case HASH_FUN(L2Cache_State_NP, L2Cache_Event_MEM_Inv):
    o_popIncomingResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_NP, L2Cache_Event_L1_GETS):
    next_state = L2Cache_State_ISS;
    if (!(*m_DirRequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    qq_allocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    ll_clearSharers(m_tbe_ptr, m_cache_entry_ptr, addr);
    nn_addSharer(m_tbe_ptr, m_cache_entry_ptr, addr);
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    ss_recordGetSL1ID(m_tbe_ptr, m_cache_entry_ptr, addr);
    a_issueFetchToMemory(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    jj_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_NP, L2Cache_Event_L1_GET_INSTR):
    next_state = L2Cache_State_IS;
    if (!(*m_DirRequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    qq_allocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    ll_clearSharers(m_tbe_ptr, m_cache_entry_ptr, addr);
    nn_addSharer(m_tbe_ptr, m_cache_entry_ptr, addr);
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    ss_recordGetSL1ID(m_tbe_ptr, m_cache_entry_ptr, addr);
    a_issueFetchToMemory(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    jj_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_NP, L2Cache_Event_L1_GETX):
    next_state = L2Cache_State_IM;
    if (!(*m_DirRequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    qq_allocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    ll_clearSharers(m_tbe_ptr, m_cache_entry_ptr, addr);
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    xx_recordGetXL1ID(m_tbe_ptr, m_cache_entry_ptr, addr);
    a_issueFetchToMemory(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    jj_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_Mem_Data):
    next_state = L2Cache_State_MT_MB;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    m_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    ex_sendExclusiveDataToGetSRequestors(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popIncomingResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_Mem_Data):
    next_state = L2Cache_State_SS;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    m_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    e_sendDataToGetSRequestors(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popIncomingResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_Mem_Data):
    next_state = L2Cache_State_MT_MB;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    m_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    ee_sendDataToGetXRequestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popIncomingResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_L1_GET_INSTR):
    nn_addSharer(m_tbe_ptr, m_cache_entry_ptr, addr);
    ss_recordGetSL1ID(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    jj_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_L1_GET_INSTR):
    next_state = L2Cache_State_IS;
    nn_addSharer(m_tbe_ptr, m_cache_entry_ptr, addr);
    ss_recordGetSL1ID(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    jj_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_GET_INSTR):
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    ds_sendSharedDataToRequestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    nn_addSharer(m_tbe_ptr, m_cache_entry_ptr, addr);
    set_setMRU(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    jj_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_GETX):
    next_state = L2Cache_State_SS_MB;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    d_sendDataToRequestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    fwm_sendFwdInvToSharersMinusRequestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    set_setMRU(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    jj_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_UPGRADE):
    next_state = L2Cache_State_SS_MB;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    fwm_sendFwdInvToSharersMinusRequestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    ts_sendInvAckToUpgrader(m_tbe_ptr, m_cache_entry_ptr, addr);
    set_setMRU(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    jj_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L2_Replacement_clean):
    next_state = L2Cache_State_I_I;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    f_sendInvToSharers(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_MEM_Inv):
    next_state = L2Cache_State_S_I;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    f_sendInvToSharers(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L1_GETX):
    next_state = L2Cache_State_MT_MB;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    d_sendDataToRequestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    set_setMRU(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    jj_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L1_GET_INSTR):
    next_state = L2Cache_State_SS;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    d_sendDataToRequestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    nn_addSharer(m_tbe_ptr, m_cache_entry_ptr, addr);
    set_setMRU(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    jj_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L1_GETS):
    next_state = L2Cache_State_MT_MB;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    dd_sendExclusiveDataToRequestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    set_setMRU(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    jj_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_M, L2Cache_Event_MEM_Inv):
    next_state = L2Cache_State_M_I;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    c_exclusiveReplacement(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L2_Replacement_clean):
    next_state = L2Cache_State_M_I;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    c_exclusiveCleanReplacement(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_L1_GETX):
    next_state = L2Cache_State_MT_MB;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    b_forwardRequestToExclusive(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    set_setMRU(m_tbe_ptr, m_cache_entry_ptr, addr);
    jj_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_L1_GET_INSTR):
    next_state = L2Cache_State_MT_IIB;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    b_forwardRequestToExclusive(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    set_setMRU(m_tbe_ptr, m_cache_entry_ptr, addr);
    jj_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_MEM_Inv):
    next_state = L2Cache_State_MT_I;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    f_sendInvToSharers(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_L2_Replacement_clean):
    next_state = L2Cache_State_MCT_I;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    f_sendInvToSharers(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_L1_PUTX):
    next_state = L2Cache_State_M;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    ll_clearSharers(m_tbe_ptr, m_cache_entry_ptr, addr);
    mr_writeDataToCacheFromRequest(m_tbe_ptr, m_cache_entry_ptr, addr);
    t_sendWBAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    jj_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_Exclusive_Unblock):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_Exclusive_Unblock):
    next_state = L2Cache_State_MT;
    mmu_markExclusiveFromUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popUnblockQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_Unblock):
    next_state = L2Cache_State_MT_IB;
    nnu_addSharerFromUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popUnblockQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_WB_Data):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_WB_Data_clean):
    next_state = L2Cache_State_MT_SB;
    m_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popIncomingResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_WB_Data):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_WB_Data_clean):
    next_state = L2Cache_State_SS;
    m_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popIncomingResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_Unblock):
    next_state = L2Cache_State_SS;
    nnu_addSharerFromUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popUnblockQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_I_I, L2Cache_Event_Ack):
  case HASH_FUN(L2Cache_State_S_I, L2Cache_Event_Ack):
    q_updateAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popIncomingResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_I_I, L2Cache_Event_Ack_all):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_WB_Data_clean):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_Ack_all):
    next_state = L2Cache_State_M_I;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    c_exclusiveCleanReplacement(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popIncomingResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_WB_Data):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_WB_Data):
    next_state = L2Cache_State_M_I;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    qq_writeDataToTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    ct_exclusiveReplacementFromTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popIncomingResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_WB_Data_clean):
  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_Ack_all):
  case HASH_FUN(L2Cache_State_S_I, L2Cache_Event_Ack_all):
    next_state = L2Cache_State_M_I;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    ct_exclusiveReplacementFromTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popIncomingResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_M_I, L2Cache_Event_Mem_Ack):
    next_state = L2Cache_State_NP;
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
