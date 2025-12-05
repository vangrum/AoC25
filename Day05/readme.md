Prvi del:
V prvem delu loopamo čez vse id-je in čez vse range-e ter preverimo, če se id nahaja znotraj katerega izmed njih.

Drugi del:
V drugem delu uredimo range-e po velikost glede na spodnjo mejo. Nato loopamo čez range-e in preverimo, če je spodnja meja range-a manjša ali enaka kot zgornja meja prejšnjega in če je posodobimo spodnjo mejo trenutnega range-a na spodnjo mejo prejšnjega in zgornjo mejo range-a na večjo izmed zgornjih dveh. 
Če spodnja meja ni manjša ali enaka zgornji meji prejšnjega, vemo, da gre za nov range, zato prejšnjega zaključimo in pričnemo novega.
