Prvi del:
Če je v prejšnji vrstici na i-tem mestu '|', bo tudi v naslednji vrstici, razen, če je na i-tem mestu že '^'. V tem primeru bo '|' na i-1-tem in na i+1-tem mestu. Štejemo število teh dogodkov.

Drugi del:
Podobno kot v prvem delu, vendar štejemo število načinov, kako lahko pridemo do posamezne lokacije. Za to uporabimo vektor. Če je več načinov, kako lahko pridemo do lokacije, jih seštejemo. Rešitev je število načinov, kako pridemo do zadnje vrstice.
