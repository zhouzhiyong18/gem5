/** \file L1Cache_Controller.hh
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/StateMachine.py:281
 * Created by slicc definition of Module "MESI Directory L1 Cache CMP"
 */

#ifndef __L1Cache_CONTROLLER_HH__
#define __L1Cache_CONTROLLER_HH__

#include <iostream>
#include <sstream>
#include <string>

#include "mem/ruby/common/Consumer.hh"
#include "mem/ruby/protocol/TransitionResult.hh"
#include "mem/ruby/protocol/Types.hh"
#include "mem/ruby/slicc_interface/AbstractController.hh"
#include "params/L1Cache_Controller.hh"

#include "mem/ruby/protocol/TBETable.hh"
extern std::stringstream L1Cache_transitionComment;

class L1Cache_Controller : public AbstractController
{
  public:
    typedef L1Cache_ControllerParams Params;
    L1Cache_Controller(const Params *p);
    static int getNumControllers();
    void init();

    MessageBuffer *getMandatoryQueue() const;
    MessageBuffer *getMemoryQueue() const;
    void initNetQueues();

    void print(std::ostream& out) const;
    void wakeup();
    void resetStats();
    void regStats();
    void collateStats();

    void recordCacheTrace(int cntrl, CacheRecorder* tr);
    Sequencer* getCPUSequencer() const;
    GPUCoalescer* getGPUCoalescer() const;

    int functionalWriteBuffers(PacketPtr&);

    void countTransition(L1Cache_State state, L1Cache_Event event);
    void possibleTransition(L1Cache_State state, L1Cache_Event event);
    uint64_t getEventCount(L1Cache_Event event);
    bool isPossible(L1Cache_State state, L1Cache_Event event);
    uint64_t getTransitionCount(L1Cache_State state, L1Cache_Event event);

private:
    CacheMemory* m_cache_ptr;
    int m_l2_select_num_bits;
    Cycles m_l1_request_latency;
    Cycles m_l1_response_latency;
    Cycles m_to_l2_latency;
    MessageBuffer* m_bufferToL0_ptr;
    MessageBuffer* m_bufferFromL0_ptr;
    MessageBuffer* m_requestToL2_ptr;
    MessageBuffer* m_responseToL2_ptr;
    MessageBuffer* m_unblockToL2_ptr;
    MessageBuffer* m_requestFromL2_ptr;
    MessageBuffer* m_responseFromL2_ptr;
    TransitionResult doTransition(L1Cache_Event event,
                                  L1Cache_Entry* m_cache_entry_ptr,
                                  L1Cache_TBE* m_tbe_ptr,
                                  Addr addr);

    TransitionResult doTransitionWorker(L1Cache_Event event,
                                        L1Cache_State state,
                                        L1Cache_State& next_state,
                                        L1Cache_TBE*& m_tbe_ptr,
                                        L1Cache_Entry*& m_cache_entry_ptr,
                                        Addr addr);

    int m_counters[L1Cache_State_NUM][L1Cache_Event_NUM];
    int m_event_counters[L1Cache_Event_NUM];
    bool m_possible[L1Cache_State_NUM][L1Cache_Event_NUM];

    static std::vector<Stats::Vector *> eventVec;
    static std::vector<std::vector<Stats::Vector *> > transVec;
    static int m_num_controllers;

    // Internal functions
    L1Cache_Entry* getCacheEntry(const Addr& param_addr);
    L1Cache_State getState(L1Cache_TBE* param_tbe, L1Cache_Entry* param_cache_entry, const Addr& param_addr);
    void setState(L1Cache_TBE* param_tbe, L1Cache_Entry* param_cache_entry, const Addr& param_addr, const L1Cache_State& param_state);
    AccessPermission getAccessPermission(const Addr& param_addr);
    void functionalRead(const Addr& param_addr, Packet* param_pkt);
    int functionalWrite(const Addr& param_addr, Packet* param_pkt);
    void setAccessPermission(L1Cache_Entry* param_cache_entry, const Addr& param_addr, const L1Cache_State& param_state);
    L1Cache_Event mandatory_request_type_to_event(const CoherenceClass& param_type);
    int getPendingAcks(L1Cache_TBE* param_tbe);
    bool inL0Cache(const L1Cache_State& param_state);

    // Set and Reset for cache_entry variable
    void set_cache_entry(L1Cache_Entry*& m_cache_entry_ptr, AbstractCacheEntry* m_new_cache_entry);
    void unset_cache_entry(L1Cache_Entry*& m_cache_entry_ptr);

    // Set and Reset for tbe variable
    void set_tbe(L1Cache_TBE*& m_tbe_ptr, L1Cache_TBE* m_new_tbe);
    void unset_tbe(L1Cache_TBE*& m_tbe_ptr);

    // Actions
    /** \brief Issue GETS */
    void a_issueGETS(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Issue GETX */
    void b_issueGETX(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Issue GETX */
    void c_issueUPGRADE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief send data to requestor */
    void d_sendDataToRequestor(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief send data to the L2 cache because of M downgrade */
    void d2_sendDataToL2(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief send data to requestor */
    void dt_sendDataToRequestor_fromTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief send data to the L2 cache */
    void d2t_sendDataToL2_fromTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief send invalidate ack to requestor (could be L2 or L1) */
    void e_sendAckToRequestor(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief send data to the L2 cache */
    void f_sendDataToL2(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief send data to the L2 cache */
    void ft_sendDataToL2_fromTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief send data to the L2 cache */
    void fi_sendInvAck(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief sends eviction information to the processor */
    void forward_eviction_to_L0(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief send data to the L2 cache */
    void g_issuePUTX(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief send unblock to the L2 cache */
    void j_sendUnblock(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief send unblock to the L2 cache */
    void jj_sendExclusiveUnblock(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief If not prefetch, send data to the L0 cache. */
    void h_data_to_l0(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief If not prefetch, notify sequencer that store completed. */
    void hh_xdata_to_l0(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief If not prefetch, send data to the L0 cache. */
    void h_stale_data_to_l0(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Allocate TBE (number of invalidates=0) */
    void i_allocateTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Pop mandatory queue. */
    void k_popL0RequestQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Pop incoming request queue and profile the delay within this virtual network */
    void l_popL2RequestQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Pop Incoming Response queue and profile the delay within this virtual network */
    void o_popL2ResponseQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Deallocate TBE */
    void s_deallocateTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Write data to cache */
    void u_writeDataFromL0Request(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Write data to cache */
    void u_writeDataFromL2Response(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Write data to cache */
    void u_writeDataFromL0Response(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Update ack count */
    void q_updateAckCount(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Deallocate L1 cache block. */
    void ff_deallocateCacheBlock(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Set cache tag equal to tag of block B. */
    void oo_allocateCacheBlock(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief recycle L0 request queue */
    void z0_stallAndWaitL0Queue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief recycle L2 request queue */
    void z2_stallAndWaitL2Queue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief wake-up dependents */
    void kd_wakeUpDependents(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Profile the demand miss */
    void uu_profileMiss(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Profile the demand hit */
    void uu_profileHit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);

    // Objects
    TBETable<L1Cache_TBE>* m_TBEs_ptr;
    int* m_l2_select_low_bit_ptr;
};
#endif // __L1Cache_CONTROLLER_H__
