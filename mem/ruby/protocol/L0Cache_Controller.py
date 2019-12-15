from m5.params import *
from m5.SimObject import SimObject
from m5.objects.Controller import RubyController

class L0Cache_Controller(RubyController):
    type = 'L0Cache_Controller'
    cxx_header = 'mem/ruby/protocol/L0Cache_Controller.hh'
    sequencer = Param.RubySequencer("")
    Icache = Param.RubyCache("")
    Dcache = Param.RubyCache("")
    request_latency = Param.Cycles((2), "")
    response_latency = Param.Cycles((2), "")
    send_evictions = Param.Bool("")
    bufferToL1 = Param.MessageBuffer("")
    bufferFromL1 = Param.MessageBuffer("")
    mandatoryQueue = Param.MessageBuffer("")
