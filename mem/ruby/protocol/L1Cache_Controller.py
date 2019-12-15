from m5.params import *
from m5.SimObject import SimObject
from m5.objects.Controller import RubyController

class L1Cache_Controller(RubyController):
    type = 'L1Cache_Controller'
    cxx_header = 'mem/ruby/protocol/L1Cache_Controller.hh'
    cache = Param.RubyCache("")
    l2_select_num_bits = Param.Int("")
    l1_request_latency = Param.Cycles((2), "")
    l1_response_latency = Param.Cycles((2), "")
    to_l2_latency = Param.Cycles((1), "")
    bufferToL0 = Param.MessageBuffer("")
    bufferFromL0 = Param.MessageBuffer("")
    requestToL2 = Param.MessageBuffer("")
    responseToL2 = Param.MessageBuffer("")
    unblockToL2 = Param.MessageBuffer("")
    requestFromL2 = Param.MessageBuffer("")
    responseFromL2 = Param.MessageBuffer("")
