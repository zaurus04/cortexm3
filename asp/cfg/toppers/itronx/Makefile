PROJDIR = ../..
WORKDIR = $(PROJDIR)/toppers/itronx

CPPFLAGS := $(CPPFLAGS) -I$(BOOST_DIR) -I$(PROJDIR)
CXXFLAGS := $(CXXFLAGS) -O2 -g

CXXFILES = \
	cfg1_out.cpp \
	checker.cpp \
	factory.cpp \
	preprocess.cpp \
	static_api.cpp

OBJFILES := $(CXXFILES:%.cpp=%.o)

all: libitronx.a

libitronx.a: $(OBJFILES)
	$(AR) rcs libitronx.a $(OBJFILES)

depend:
	$(CXX) $(CPPFLAGS) -M $(CXXFILES) > Makefile.depend

clean:
	-rm *.o *.a

-include Makefile.depend

