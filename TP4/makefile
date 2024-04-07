.PHONY: all clean format

all:
	$(MAKE) -C ex1/pipe_a
	$(MAKE) -C ex1/pipe_b
	$(MAKE) -C ex1/pipe_c
	$(MAKE) -C ex2/pipe_red1a
	$(MAKE) -C ex2/pipe_red1b
	$(MAKE) -C ex2/pipe_red1c
	$(MAKE) -C ex3
	
clean:
	$(MAKE) -C ex1/pipe_a clean
	$(MAKE) -C ex1/pipe_b clean 
	$(MAKE) -C ex1/pipe_c clean
	$(MAKE) -C ex2/pipe_red1a clean 
	$(MAKE) -C ex2/pipe_red1b clean
	$(MAKE) -C ex2/pipe_red1c clean
	$(MAKE) -C ex3 clean

format : 
	$(MAKE) -C ex1/pipe_a format
	$(MAKE) -C ex1/pipe_b format
	$(MAKE) -C ex1/pipe_c format
	$(MAKE) -C ex2/pipe_red1a format
	$(MAKE) -C ex2/pipe_red1b format 
	$(MAKE) -C ex2/pipe_red1c format 
	$(MAKE) -C ex3 format

