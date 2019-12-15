// Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/StateMachine.py:1188
// Directory: MESI Two Level directory protocol

#include <cassert>

#include "base/logging.hh"
#include "base/trace.hh"
#include "debug/ProtocolTrace.hh"
#include "debug/RubyGenerated.hh"
#include "mem/ruby/protocol/Directory_Controller.hh"
#include "mem/ruby/protocol/Directory_Event.hh"
#include "mem/ruby/protocol/Directory_State.hh"
#include "mem/ruby/protocol/Types.hh"
#include "mem/ruby/system/RubySystem.hh"

#define HASH_FUN(state, event)  ((int(state)*Directory_Event_NUM)+int(event))

#define GET_TRANSITION_COMMENT() (Directory_transitionComment.str())
#define CLEAR_TRANSITION_COMMENT() (Directory_transitionComment.str(""))

TransitionResult
Directory_Controller::doTransition(Directory_Event event,
                                  Directory_TBE* m_tbe_ptr,
                                  Addr addr)
{
    Directory_State state = getState(m_tbe_ptr, addr);
    Directory_State next_state = state;

    DPRINTF(RubyGenerated, "%s, Time: %lld, state: %s, event: %s, addr: %#x\n",
            *this, curCycle(), Directory_State_to_string(state),
            Directory_Event_to_string(event), addr);

    TransitionResult result =
    doTransitionWorker(event, state, next_state, m_tbe_ptr, addr);

    if (result == TransitionResult_Valid) {
        DPRINTF(RubyGenerated, "next_state: %s\n",
                Directory_State_to_string(next_state));
        countTransition(state, event);

        DPRINTFR(ProtocolTrace, "%15d %3s %10s%20s %6s>%-6s %#x %s\n",
                 curTick(), m_version, "Directory",
                 Directory_Event_to_string(event),
                 Directory_State_to_string(state),
                 Directory_State_to_string(next_state),
                 printAddress(addr), GET_TRANSITION_COMMENT());

        CLEAR_TRANSITION_COMMENT();
    setState(m_tbe_ptr, addr, next_state);
    setAccessPermission(addr, next_state);
    } else if (result == TransitionResult_ResourceStall) {
        DPRINTFR(ProtocolTrace, "%15s %3s %10s%20s %6s>%-6s %#x %s\n",
                 curTick(), m_version, "Directory",
                 Directory_Event_to_string(event),
                 Directory_State_to_string(state),
                 Directory_State_to_string(next_state),
                 printAddress(addr), "Resource Stall");
    } else if (result == TransitionResult_ProtocolStall) {
        DPRINTF(RubyGenerated, "stalling\n");
        DPRINTFR(ProtocolTrace, "%15s %3s %10s%20s %6s>%-6s %#x %s\n",
                 curTick(), m_version, "Directory",
                 Directory_Event_to_string(event),
                 Directory_State_to_string(state),
                 Directory_State_to_string(next_state),
                 printAddress(addr), "Protocol Stall");
    }

    return result;
}

TransitionResult
Directory_Controller::doTransitionWorker(Directory_Event event,
                                        Directory_State state,
                                        Directory_State& next_state,
                                        Directory_TBE*& m_tbe_ptr,
                                        Addr addr)
{
    switch(HASH_FUN(state, event)) {
  case HASH_FUN(Directory_State_I, Directory_Event_Fetch):
    next_state = Directory_State_IM;
    qf_queueMemoryFetchRequest(m_tbe_ptr, addr);
    j_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_M, Directory_Event_Fetch):
    if (!(*m_responseFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    inv_sendCacheInvalidate(m_tbe_ptr, addr);
    z_stallAndWaitRequest(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_IM, Directory_Event_Memory_Data):
    next_state = Directory_State_M;
    if (!(*m_responseFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    d_sendData(m_tbe_ptr, addr);
    l_popMemQueue(m_tbe_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_M, Directory_Event_CleanReplacement):
    next_state = Directory_State_I;
    if (!(*m_responseFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    a_sendAck(m_tbe_ptr, addr);
    k_popIncomingResponseQueue(m_tbe_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_M, Directory_Event_Data):
    next_state = Directory_State_MI;
    qw_queueMemoryWBRequest(m_tbe_ptr, addr);
    k_popIncomingResponseQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_MI, Directory_Event_Memory_Ack):
  case HASH_FUN(Directory_State_M_DRDI, Directory_Event_Memory_Ack):
    next_state = Directory_State_I;
    if (!(*m_responseFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    aa_sendAck(m_tbe_ptr, addr);
    l_popMemQueue(m_tbe_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_I, Directory_Event_DMA_READ):
    next_state = Directory_State_ID;
    v_allocateTBE(m_tbe_ptr, addr);
    qf_queueMemoryFetchRequestDMA(m_tbe_ptr, addr);
    j_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_ID, Directory_Event_Memory_Data):
    next_state = Directory_State_I;
    if (!(*m_responseFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    dr_sendDMAData(m_tbe_ptr, addr);
    w_deallocateTBE(m_tbe_ptr, addr);
    l_popMemQueue(m_tbe_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_I, Directory_Event_DMA_WRITE):
    next_state = Directory_State_ID_W;
    v_allocateTBE(m_tbe_ptr, addr);
    qw_queueMemoryWBRequest_partial(m_tbe_ptr, addr);
    j_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_ID_W, Directory_Event_Memory_Ack):
    next_state = Directory_State_I;
    if (!(*m_responseFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    da_sendDMAAck(m_tbe_ptr, addr);
    w_deallocateTBE(m_tbe_ptr, addr);
    l_popMemQueue(m_tbe_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_ID, Directory_Event_Fetch):
  case HASH_FUN(Directory_State_ID, Directory_Event_Data):
  case HASH_FUN(Directory_State_ID_W, Directory_Event_Fetch):
  case HASH_FUN(Directory_State_ID_W, Directory_Event_Data):
  case HASH_FUN(Directory_State_M_DRDI, Directory_Event_Fetch):
  case HASH_FUN(Directory_State_M_DRDI, Directory_Event_Data):
  case HASH_FUN(Directory_State_M_DWRI, Directory_Event_Fetch):
  case HASH_FUN(Directory_State_M_DWRI, Directory_Event_Data):
  case HASH_FUN(Directory_State_IM, Directory_Event_Fetch):
  case HASH_FUN(Directory_State_IM, Directory_Event_Data):
  case HASH_FUN(Directory_State_MI, Directory_Event_Fetch):
  case HASH_FUN(Directory_State_MI, Directory_Event_Data):
    z_stallAndWaitRequest(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_ID, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_ID, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_ID_W, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_ID_W, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_M_DRD, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_M_DRD, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_M_DRDI, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_M_DRDI, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_M_DWR, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_M_DWR, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_M_DWRI, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_M_DWRI, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_IM, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_IM, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_MI, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_MI, Directory_Event_DMA_READ):
    zz_recycleDMAQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_M, Directory_Event_DMA_READ):
    next_state = Directory_State_M_DRD;
    if (!(*m_responseFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    v_allocateTBE(m_tbe_ptr, addr);
    inv_sendCacheInvalidate(m_tbe_ptr, addr);
    j_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_M_DRD, Directory_Event_Data):
    next_state = Directory_State_M_DRDI;
    if (!(*m_responseFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    drp_sendDMAData(m_tbe_ptr, addr);
    w_deallocateTBE(m_tbe_ptr, addr);
    qw_queueMemoryWBRequest(m_tbe_ptr, addr);
    k_popIncomingResponseQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_M, Directory_Event_DMA_WRITE):
    next_state = Directory_State_M_DWR;
    if (!(*m_responseFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    v_allocateTBE(m_tbe_ptr, addr);
    inv_sendCacheInvalidate(m_tbe_ptr, addr);
    j_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_M_DWR, Directory_Event_Data):
    next_state = Directory_State_M_DWRI;
    qw_queueMemoryWBRequest_partialTBE(m_tbe_ptr, addr);
    k_popIncomingResponseQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_M_DWRI, Directory_Event_Memory_Ack):
    next_state = Directory_State_I;
    if (!(*m_responseFromDir_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    aa_sendAck(m_tbe_ptr, addr);
    da_sendDMAAck(m_tbe_ptr, addr);
    w_deallocateTBE(m_tbe_ptr, addr);
    l_popMemQueue(m_tbe_ptr, addr);
    kd_wakeUpDependents(m_tbe_ptr, addr);
    return TransitionResult_Valid;

      default:
        panic("Invalid transition\n"
              "%s time: %d addr: %#x event: %s state: %s\n",
              name(), curCycle(), addr, event, state);
    }

    return TransitionResult_Valid;
}
