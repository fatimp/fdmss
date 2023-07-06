FDMSS ?= /home/vasily/test/fdmss/fdmss
SED ?= sed

RAWS = $(wildcard *.raw)
XML_X = $(patsubst %.raw,%-x.out.xml,$(RAWS))
XML_Y = $(patsubst %.raw,%-y.out.xml,$(RAWS))
XML_Z = $(patsubst %.raw,%-z.out.xml,$(RAWS))

all: $(XML_X) $(XML_Y) $(XML_Z)

%-x.out.xml: %.raw config-x.xml
	$(FDMSS) --config config-x.xml --image $< --summary $@

%-y.out.xml: %.raw config-y.xml
	$(FDMSS) --config config-y.xml --image $< --summary $@

%-z.out.xml: %.raw config-z.xml
	$(FDMSS) --config config-z.xml --image $< --summary $@

config-x.xml: config.xml
	$(SED) 's/AXIS/x/' $< > $@

config-y.xml: config.xml
	$(SED) 's/AXIS/y/' $< > $@

config-z.xml: config.xml
	$(SED) 's/AXIS/z/' $< > $@

clean:
	rm -f *.log *.out.xml config-x.xml config-y.xml config-z.xml

.PHONY: clean
