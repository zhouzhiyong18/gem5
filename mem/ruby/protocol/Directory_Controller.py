from m5.params import *
from m5.SimObject import SimObject
from m5.objects.Controller import RubyController

class Directory_Controller(RubyController):
    type = 'Directory_Controller'
    cxx_header = 'mem/ruby/protocol/Directory_Controller.hh'
    directory = Param.RubyDirectoryMemory("")
    to_mem_ctrl_latency = Param.Cycles((1), "")
    directory_latency = Param.Cycles((6), "")
    requestToDir = Param.MessageBuffer("")
    responseToDir = Param.MessageBuffer("")
    responseFromDir = Param.MessageBuffer("")
    responseFromMemory = Param.MessageBuffer("")
