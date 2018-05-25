CXX = g++
INCLUDING = -I../_libRS232
CXXFLAGS = -std=c++14 -Wall -Wextra -Weffc++ -Os $(INCLUDING) \
           -D_GLIBCXX_USE_NANOSLEEP
LDFLAGS = -pthread

EXECUTABLE = demoRS232tx
SOURCES = ${wildcard *.cpp} \
          ${wildcard ../_libRS232/*.c}
HEADERS = ${wildcard *.h} \
          ${wildcard ../_libRS232/*.h}
OBJECTS = ${SOURCES:.cpp=.o}
OBJECTS := ${OBJECTS:.c=.o}

.PHONY: all
all: ${EXECUTABLE}

$(EXECUTABLE): $(OBJECTS) buildnumber.num
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(LDFLAGS) -o $@
	@echo "-- Build: " $$(cat buildnumber.num)

# Create dependency file using the compiler option -MM
depend: $(SOURCES)
	$(CXX) $(CXXFLAGS) -MM  $^ > $@

-include depend

# Buildnumber in text file
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
