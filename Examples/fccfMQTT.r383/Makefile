CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -Weffc++ -Os \
           -D_GLIBCXX_USE_NANOSLEEP \
					 -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 \
					 -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 \
					 -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 \
					 -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_8
LDFLAGS = -pthread -lmosquittopp -lmosquitto -L/usr/local/lib

EXECUTABLE = fccfMQTT
SOURCES = ${wildcard *.cpp}
HEADERS = ${wildcard *.h}
OBJECTS = ${SOURCES:.cpp=.o}

.PHONY: all
all: ${EXECUTABLE}

$(EXECUTABLE): $(OBJECTS) buildnumber.num
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(LDFLAGS) -o $@
	@echo "-- Build: " $$(cat buildnumber.num)

# Create dependency file compiler option -MM
depend: $(SOURCES)
	$(CXX) $(CXXFLAGS) -MM  $^ > $@

-include depend

# Buildnumber in file
buildnumber.num: $(OBJECTS)
	@if ! test -f buildnumber.num; then echo 0 > buildnumber.num; fi
	@echo $$(($$(cat buildnumber.num)+1)) > buildnumber.num

# Create a clean environment
.PHONY: clean
clean:
	$(RM) $(EXECUTABLE) $(OBJECTS)

# Clean up dependency file
.PHONY: clean-depend
clean-depend: clean
	$(RM) depend
