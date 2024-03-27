resultados.pdf : muñoz_escobar_daniel_arukin_s7casa_plots.pdf

muñoz_escobar_daniel_arukin_s7casa_plots.pdf : muñoz_escobar_daniel_arukin_s7casa_plots.py sol_fijo.dat sol_libre.dat
	python3 muñoz_escobar_daniel_arukin_s7casa_plots.py

sol_fijo.dat : Muñoz_Escobar_Daniel_Arukin_S7CASA_TierraSolFijo.cpp
	g++ Muñoz_Escobar_Daniel_Arukin_S7CASA_TierraSolFijo.cpp
	./a.out>>sol_fijo.dat

sol_libre.dat : Muñoz_Escobar_Daniel_Arukin_S7CASA_TierraSolLibre.cpp
	g++ Muñoz_Escobar_Daniel_Arukin_S7CASA_TierraSolLibre.cpp
	./a.out>>sol_libre.dat
