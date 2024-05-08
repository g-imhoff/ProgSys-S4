.PHONY: all clean format

all:
	$(MAKE) -C TP1
	$(MAKE) -C TP2
	$(MAKE) -C TP2bis
	$(MAKE) -C TP3
	$(MAKE) -C TP4
	$(MAKE) -C TP7/tpnote
	$(MAKE) -C TP9
	$(MAKE) -C TP10

clean:
	$(MAKE) -C TP1 clean 
	$(MAKE) -C TP2 clean
	$(MAKE) -C TP2bis clean
	$(MAKE) -C TP3 clean 
	$(MAKE) -C TP4 clean
	$(MAKE) -C TP7/tpnote clean 
	$(MAKE) -C TP9 clean
	$(MAKE) -C TP10 clean
	
format : 
	$(MAKE) -C TP1 format
	$(MAKE) -C TP2 format 
	$(MAKE) -C TP3 format 
	$(MAKE) -C TP4 format 
	$(MAKE) -C TP9 format
	$(MAKE) -C TP10 format
