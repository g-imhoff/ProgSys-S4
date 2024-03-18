.PHONY: all 

all:
	$(MAKE) -C ex1
	$(MAKE) -C ex2/ls1
	$(MAKE) -C ex2/ls2
	$(MAKE) -C ex3
	$(MAKE) -C ex4

.phony: clean format sanitizers

clean:
	$(MAKE) -C ex1 clean
	$(MAKE) -C ex2/ls1 clean
	$(MAKE) -C ex2/ls2 clean
	$(MAKE) -C ex3 clean
	$(MAKE) -C ex4 clean
	
format : 
	$(MAKE) -C ex1 format
	$(MAKE) -C ex2/ls1 format 
	$(MAKE) -C ex2/ls2 format
	$(MAKE) -C ex3 format
	$(MAKE) -C ex4 format

sanitizers : 
	$(MAKE) -C ex1 sanitizers
	$(MAKE) -C ex2/ls1 sanitizers
	$(MAKE) -C ex2/ls2 sanitizers
	$(MAKE) -C ex3 sanitizers
	$(MAKE) -C ex4 sanitizers
