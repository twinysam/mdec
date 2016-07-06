#==============================================================================
#                            MS-DOS Edit Clone 
#                                  MDEC                                       
#==============================================================================
#
# Depends on libncurses5
#
#==============================================================================

all: debug run

release: ./src/mdec.c
	@gcc -o ./bin/release/mdec ./src/mdec.c -lcdk -lncurses

debug: ./src/mdec.c
	@gcc -o ./bin/debug/mdec ./src/mdec.c -lcdk -lncurses

run: # Debug is default to run
	@./bin/debug/mdec

run-release:
	

clean:
	@rm ./bin/debug/*

