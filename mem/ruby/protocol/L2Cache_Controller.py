from m5.params import *
from m5.SimObject import SimObject
from m5.objects.Controller import RubyController

class L2Cache_Controller(RubyController):
    type = 'L2Cache_Controller'
    cxx_header = 'mem/ruby/protocol/L2Cache_Controller.hh'
    L2cache = Param.RubyCache("")
    l2_request_latency = Param.Cycles((2), "")
    l2_response_latency = Param.Cycles((2), "")
    to_l1_latency = Param.Cycles((1), "")
    DirRequestFromL2Cache = Param.MessageBuffer("")
    L1RequestFromL2Cache = Param.MessageBuffer("")
    responseFromL2Cache = Param.MessageBuffer("")
    unblockToL2Cache = Param.MessageBuffer("")
    L1RequestToL2Cache = Param.MessageBuffer("")
    responseToL2Cache = Param.MessageBuffer("")
