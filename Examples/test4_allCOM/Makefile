CXX = g++
INCLUDING = -I./../../_libSenseHAT -I./../../_libMQTT -I./../../_libUtils -I./../../_libDevice -I./../../_libRS232
CXXFLAGS = -std=c++17 -Wall -Wextra -Weffc++ -Os $(INCLUDING) \
           -D_GLIBCXX_USE_NANOSLEEP \
			  -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 \
			  -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 \
			  -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 \
			  -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_8
LDFLAGS = -lboost_system -L/usr/local/lib -lmosquittopp -lm -pthread 

EXECUTABLE = Pi-in-the-sky
SOURCES := ${wildcard *.cpp} \
           ${wildcard ../../_libMQTT/*.cpp} \
	   ${wildcard ../../_libUtils/*.cpp} \
           ${wildcard ../../_libSenseHAT/*.cpp} \
           ${wildcard ../../_libDevice/*.cpp} \
           ${wildcard ../../_libRS232/*.cpp} \
	   ${wildcard ../../_libSenseHAT/*.c}

HEADERS := ${wildcard *.h} \
           ${wildcard ../../_libMQTT/*.h} \
	   ${wildcard ../../_libUtils/*.h} \
	   ${wildcard ../../_libDevice/*.h} \
	   ${wildcard ../../_libRS232/*.h} \
	   ${wildcard ../../_libSenseHAT/*.h}

OBJECTS := ${SOURCES:.cpp=.o}
OBJECTS := ${OBJECTS:.c=.o}

.PHONY: all
all: ${EXECUTABLE}

$(EXECUTABLE): $(OBJECTS) buildnumber.num
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(LDFLAGS) -o $@ -lRTIMULib
	@echo
	@echo "-- Build: " $$(cat buildnumber.num)

# Create dependency file compiler option -MM
depend: $(SOURCES)
	$(CXX) $(CXXFLAGS) -MM  $^ > $@

-include depend

# Buildnumber in text file
buildnumber.num: $(OBJECTS)
	@echo
	@echo "-- Sources: " $(SOURCES)
	@echo
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
