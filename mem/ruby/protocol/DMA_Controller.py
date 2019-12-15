from m5.params import *
from m5.SimObject import SimObject
from m5.objects.Controller import RubyController

class DMA_Controller(RubyController):
    type = 'DMA_Controller'
    cxx_header = 'mem/ruby/protocol/DMA_Controller.hh'
    dma_sequencer = Param.DMASequencer("")
    request_latency = Param.Cycles((6), "")
    responseFromDir = Param.MessageBuffer("")
    requestToDir = Param.MessageBuffer("")
    mandatoryQueue = Param.MessageBuffer("")