/** \file L0Cache_Controller.hh
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/StateMachine.py:281
 * Created by slicc definition of Module "MESI Directory L0 Cache"
 */

#ifndef __L0Cache_CONTROLLER_HH__
#define __L0Cache_CONTROLLER_HH__

#include <iostream>
#include <sstream>
#include <string>

#include "mem/ruby/common/Consumer.hh"
#include "mem/ruby/protocol/TransitionResult.hh"
#include "mem/ruby/protocol/Types.hh"
#include "mem/ruby/slicc_interface/AbstractController.hh"
#include "params/L0Cache_Controller.hh"

#include "mem/ruby/protocol/TBETable.hh"
extern std::stringstream L0Cache_transitionComment;

class L0Cache_Controller : public AbstractController
{
  public:
    typedef L0Cache_ControllerParams Params;
    L0Cache_Controller(const Params *p);
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

    void countTransition(L0Cache_State state, L0Cache_Event event);
    void possibleTransition(L0Cache_State state, L0Cache_Event event);
    uint64_t getEventCount(L0Cache_Event event);
    bool isPossible(L0Cache_State state, L0Cache_Event event);
    uint64_t getTransitionCount(L0Cache_State state, L0Cache_Event event);

private:
    Sequencer* m_sequencer_ptr;
    CacheMemory* m_Icache_ptr;
    CacheMemory* m_Dcache_ptr;
    Cycles m_request_latency;
    Cycles m_response_latency;
    bool m_send_evictions;
    MessageBuffer* m_bufferToL1_ptr;
    MessageBuffer* m_bufferFromL1_ptr;
    MessageBuffer* m_mandatoryQueue_ptr;
    TransitionResult doTransition(L0Cache_Event event,
                                  L0Cache_Entry* m_cache_entry_ptr,
                                  L0Cache_TBE* m_tbe_ptr,
                                  Addr addr);

    TransitionResult doTransitionWorker(L0Cache_Event event,
                                        L0Cache_State state,
                                        L0Cache_State& next_state,
                                        L0Cache_TBE*& m_tbe_ptr,
                                        L0Cache_Entry*& m_cache_entry_ptr,
                                        Addr addr);

    int m_counters[L0Cache_State_NUM][L0Cache_Event_NUM];
    int m_event_counters[L0Cache_Event_NUM];
    bool m_possible[L0Cache_State_NUM][L0Cache_Event_NUM];

    static std::vector<Stats::Vector *> eventVec;
    static std::vector<std::vector<Stats::Vector *> > transVec;
    static int m_num_controllers;

    // Internal functions
    L0Cache_Entry* getCacheEntry(const Addr& param_addr);
    L0Cache_Entry* getDCacheEntry(const Addr& param_addr);
    L0Cache_Entry* getICacheEntry(const Addr& param_addr);
    L0Cache_State getState(L0Cache_TBE* param_tbe, L0Cache_Entry* param_cache_entry, const Addr& param_addr);
    void setState(L0Cache_TBE* param_tbe, L0Cache_Entry* param_cache_entry, const Addr& param_addr, const L0Cache_State& param_state);
    AccessPermission getAccessPermission(const Addr& param_addr);
    void functionalRead(const Addr& param_addr, Packet* param_pkt);
    int functionalWrite(const Addr& param_addr, Packet* param_pkt);
    void setAccessPermission(L0Cache_Entry* param_cache_entry, const Addr& param_addr, const L0Cache_State& param_state);
    L0Cache_Event mandatory_request_type_to_event(const RubyRequestType& param_type);
    int getPendingAcks(L0Cache_TBE* param_tbe);

    // Set and Reset for cache_entry variable
    void set_cache_entry(L0Cache_Entry*& m_cache_entry_ptr, AbstractCacheEntry* m_new_cache_entry);
    void unset_cache_entry(L0Cache_Entry*& m_cache_entry_ptr);

    // Set and Reset for tbe variable
    void set_tbe(L0Cache_TBE*& m_tbe_ptr, L0Cache_TBE* m_new_tbe);
    void unset_tbe(L0Cache_TBE*& m_tbe_ptr);

    // Actions
    /** \brief Issue GETS */
    void a_issueGETS(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Issue GETX */
    void b_issueGETX(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Issue GETX */
    void c_issueUPGRADE(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief send data to the L2 cache */
    void f_sendDataToL1(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief send data to the L2 cache */
    void fi_sendInvAck(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief sends eviction information to the processor */
    void forward_eviction_to_cpu(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief send data to the L2 cache */
    void g_issuePUTX(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief If not prefetch, notify sequencer the load completed. */
    void h_load_hit(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief If not prefetch, notify sequencer the ifetch completed. */
    void h_ifetch_hit(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief notify sequencer the load completed. */
    void hx_load_hit(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief notify sequencer the ifetch completed. */
    void hx_ifetch_hit(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief If not prefetch, notify sequencer that store completed. */
    void hh_store_hit(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief If not prefetch, notify sequencer that store completed. */
    void hhx_store_hit(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Allocate TBE (number of invalidates=0) */
    void i_allocateTBE(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Pop mandatory queue. */
    void k_popMandatoryQueue(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Pop incoming request queue and profile the delay within this virtual network */
    void l_popRequestQueue(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Pop Incoming Response queue and profile the delay within this virtual network */
    void o_popIncomingResponseQueue(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Deallocate TBE */
    void s_deallocateTBE(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Write data to cache */
    void u_writeDataToCache(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Write data to cache */
    void u_writeInstToCache(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Deallocate L1 cache block. */
    void ff_deallocateCacheBlock(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Set L1 D-cache tag equal to tag of block B. */
    void oo_allocateDCacheBlock(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Set L1 I-cache tag equal to tag of block B. */
    void pp_allocateICacheBlock(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief recycle cpu request queue */
    void z_stallAndWaitMandatoryQueue(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief wake-up dependents */
    void kd_wakeUpDependents(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Profile the demand miss */
    void uu_profileInstMiss(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Profile the demand miss */
    void uu_profileInstHit(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Profile the demand miss */
    void uu_profileDataMiss(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Profile the demand miss */
    void uu_profileDataHit(L0Cache_TBE*& m_tbe_ptr, L0Cache_Entry*& m_cache_entry_ptr, Addr addr);

    // Objects
    TBETable<L0Cache_TBE>* m_TBEs_ptr;
};
#endif // __L0Cache_CONTROLLER_H__
