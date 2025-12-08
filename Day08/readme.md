Prvi del:
Za prvi del uporabimo naivni pristop. Ustvarimo (multi)map razdalj, ki so jim prirejena vozlišča. Nato ustvarimo vektor grafov. Za vsako povezavo v grafu dodamo nov graf. Nato preverimo vsak par grafov in če imata katero izmed vozlišč skupno, grafa združimo. Na koncu ustvarimo še vektor velikosti vseh grafov, od koder nato izračunamo rešitev.

Drugi del:
Naivni pristop iz prvega dela je za drugi del prepočasen. Zato vsakič, ko dodamo novo povezavo, zaženemo DFS. Če smo na koncu obiskali vsa vozlišča, je graf povezan.
