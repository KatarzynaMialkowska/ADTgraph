
.SUFFIXES: .cxx .o .x .hxx
NAME1 = ADTgraph
NAME2 = tester
NAME3 = generator
NAME4 = ADTgraphList

CXX1 = $(NAME1).cxx
CXX2 = $(NAME2).cxx
CXX3 = $(NAME3).cxx
CXX4 = $(NAME4).cxx

EXEC1 = $(NAME1).x
EXEC2 = $(NAME2).x
EXEC3 = $(NAME3).x
EXEC4 = $(NAME4).x

CO=g++
FLAGS= -std=c++17 -Wall -O3


.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC3)


$(EXEC1):
	$(CO) -o $@ $(CXX1) $(FLAGS) 

$(EXEC2): 
	$(CO) -o $@ $(CXX2) $(FLAGS)

$(EXEC3):
	$(CO) -o $@ $(CXX3) $(FLAGS) 
	
$(EXEC4):
	$(CO) -o $@ $(CXX4) $(FLAGS) 


##ADT graph##
A: $(EXEC1) 

.PHONY: ADTgraph
ADTgraph: A
	@echo "\n*ADTgraph*\n"
	@./$(EXEC1) 

##ADT graph list##
B: $(EXEC4) 

.PHONY: ADTgraphList
ADTgraphList: B
	@echo "\n*ADTgraphList*\n"
	@./$(EXEC4) 



.PHONY: graph
graph:
	@dot -Tjpg graph.gv -o graphGV.jpg

test: $(EXEC2) $(EXEC3)
tester: test
	@echo "\n*ADTgraph vs ADTgraphList*\n"
	@./$(EXEC3) 20000 20000 | ./$(EXEC2)


.PHONY: clean
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x *.txt *.gv *.jpg *.dat core core* a.out; rm -rf ${LIB_DIR}